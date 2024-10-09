/*---Code by Ben McCormack---*/
/*-15/Nov/2023-05/05/2024----*/
/*--------IOT Apiary---------*/


//Declare Libraries
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "homepage.h"
#include <DFRobot_DHT11.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include <Servo.h>
#include "rgb_lcd.h"
#include "secrets.h"
#include "ThingSpeak.h"

//DHT11 Setup
DFRobot_DHT11 DHT;
#define DHT11_PIN 14

//PN532 (RFID Scanner) Setup
#define PN532_IRQ   (18)
#define PN532_RESET (23)
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

//Servo Setup
Servo servo1;
static const int servoPin = 4;

//LCD Setup
rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

//LDR setup
const int LDR = 32;

uint8_t success;
uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };	// Buffer to store the returned UID
uint8_t uidLength = 0;				// Length of the UID (4 or 7 bytes depending on ISO14443A card type)

char* ssid = SECRET_SSID;   // My network SSID (name) 
char* password = SECRET_PASS;   // My network password
int keyIndex = 0;            
WiFiClient  client;

int mPos1 = 0;
int mPos2 = 0;
int lock = 0;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

int C1[] = {0x7b, 0x32, 0x32, 0x21};
int C2[] = {0,0,0,0,0,0,0,0};

WebServer server(80);

void setup(void) {
  lcd.clear();

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.setRGB(colorR, colorG, colorB);

  while (!Serial) delay(10); // for Leonardo/Micro/Zero

  nfc.begin();

  //LDR
  pinMode(LDR, INPUT);

  //Error catching
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print(versiondata);
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

  servo1.attach(servoPin);

  

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/sentKeyPressToWebServer", lockPressed);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

  //nfc.setPassiveActivationRetries(0xFF);

  dMotor();
}

void loop(void) {
  server.handleClient();
  delay(20);//allow the cpu to switch to other tasks
  
  int temp = GetTemp();
  int humid = GetHumid();
  int light = Light();

  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humid);
  ThingSpeak.setField(4, light);

  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  Serial.println("Waiting for Card");
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 5000);
  //Serial.println("Through");
  //nfc.PrintHexChar(uid, uidLength);
  //Serial.println("Hex");
  Serial.print(lock);
  Serial.print("\n");

  if(success)
  {
    if(uidLength == 4)
    {
      // We probably have a Mifare Classic card ...
      Serial.println("Seems to be a Mifare Classic card (4 byte UID)");

      // Now we need to try to authenticate it for read/write access
      Serial.println("Authenticating block 4 with KEYA value");
      uint8_t keya[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

      if(nfcDetector(uid, uidLength) == 1)
      {
        mPos2 = motor(mPos1);
        mPos1 = mPos2;
        Serial.print(mPos2);
        Serial.print(mPos1);
        Serial.print("");
      }
      else
      {
        Serial.println("Wrong Card");
      }
    }
  }

  if(Serial.find('c'))
  {
    mPos2 = motor(mPos1);
    mPos1 = mPos2;
    Serial.print(mPos2);
    Serial.print(mPos1);
    Serial.print("");
  }
  else if(Serial.find('i'))
  {
    Serial.println("Wrong Card");
  }
}