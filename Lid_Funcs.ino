int motor(int mPos)
{
  uint8_t rep = 0;

  if(lock == "0")
  {
    if(mPos == 0 && rep == 0)
    {
      Serial.print(mPos);
      lcd.clear();
      lcd.print("OPENING!");
      for(int posDegrees = 90; posDegrees >= 0; posDegrees -= 2)      //opens the lid
      {
        servo1.write(posDegrees);
        delay(20);
      }
      
      lcd.clear();
      lcd.print("The lid is open!");

      delay(1000);
      rep = 1;
      Serial.print(rep);
      Serial.println("open");

      mPos = 1;
    }
    else if(mPos == 1 && rep == 0)
    {
      Serial.print(mPos);
      lcd.clear();
      lcd.print("CLOSING!");
      for(int posDegrees = 0; posDegrees <= 90; posDegrees += 2)        //reset to closed
      {
        servo1.write(posDegrees);
        delay(20);
      }

      lcd.clear();
      lcd.print("The lid is closed!");

      delay(1000);
      rep = 1;
      Serial.print(rep);
      Serial.println("close");

      mPos = 0;
    }
  }
  else
  {
    lcd.clear();
    lcd.print("The lid is LOCKED!");
  }

  Serial.print(mPos);
  Serial.println("rep");

  return mPos;
}
void dMotor()
{
  for(int posDegrees = 0; posDegrees <= 90; posDegrees += 2)        //reset to closed
  {
    servo1.write(posDegrees);
    delay(20);
  }
}