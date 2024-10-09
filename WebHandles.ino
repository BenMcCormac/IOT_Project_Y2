void handleRoot() {
  String message1 = homePagePart1 + getTemp() + homePagePart2 + getHumid() + homePagePart3 + getLight() + homePagePart4;
  server.send(200, "text/html", message1);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/html", message);
}

void handleKeyPress() 
{
  String receivedData = "You pressed: " + server.arg("button");
  Serial.print(receivedData);
  server.send(200);
}

void lockPressed()
{
  String receivedData;

  if(lock == 0)
  {
    lock = 1;
    receivedData = "Locked\n";
  }
  else if(lock == 1)
  {
    lock = 0;
    receivedData = "Unlocked\n";
  }

  
  Serial.print(receivedData);
  server.send(200);
}