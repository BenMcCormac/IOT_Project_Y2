int nfcDetector(uint8_t uid[], uint8_t uidLegnth)
{
  int card1 = 0, card2 = 0;
  int C1[] = {0x7b, 0x32, 0x32, 0x21};
  int C2[] = {0,0,0,0,0,0,0,0};

  for (int i = 0; i < uidLegnth; i++)
  {
    if(uid[i] == C1[i])
    {
      card1++;
    }
    else if(uid[i] == C2[i])
    {
      card2++;
    }
  }

  if(card1 == uidLegnth)
  {
    Serial.println("Card 1 detected");
    delay(100);
    return 1;
  }
  else if(card2 == uidLegnth)
  {
    Serial.println("Card 2 Detected");
    delay(100);
    return 1;
  }
  else
  {
    for(int i = 0; i < uidLegnth; i++)
    {
      C2[i] = uid[i];
    }
    delay(100);
    return 0;
  }
}