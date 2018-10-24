void Stop()
{
  //PORTA = 0B00000000;
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

}

void Forward()
{
 //PORTA = 0B00000110;
 digitalWrite(LM1, HIGH);
 digitalWrite(LM2, LOW);
 digitalWrite(RM1, HIGH);
 digitalWrite(RM2, LOW);
}
void Backward()
{
  //PORTA = 0B00001001;
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);

}

void Left()
{
  //PORTA = 0B00000101;

 digitalWrite(LM1, HIGH);
 digitalWrite(LM2, LOW);
 digitalWrite(RM1, LOW);
 digitalWrite(RM2, LOW);

}

void Right()
{
  //PORTA = 0B00001010;
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

}

