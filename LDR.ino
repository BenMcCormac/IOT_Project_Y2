int Light()
{
  float voltage = (analogRead(LDR)) * (5/1023);
  return voltage;
}
String getLight()
{
  float voltage = (analogRead(LDR)) * (5/1023);
  if(voltage<3)
  {
    String x = "Enough";
    return x;
  }
  else
  {
    String y = "Too much";
    return y;
  }
}