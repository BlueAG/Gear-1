#define BUTTON_DOWN 13
#define BUTTON_UP 4
#define BUTTON_N 11

int ledPinA = 7;
int ledPinB = 12;
int ledPinC = 10;
int ledPinD = 9;
int ledPinE = 8;
int ledPinF = 6;
int ledPinG = 5;

int val_up = 0;
int val_down = 0;
int val_n = 0;
int old_val_n = 0;
int old_val_down = 0;
int old_val_up = 0;
int gear = 0;
// The setup() method runs once, when the sketch starts

void setup()
{
  pinMode(BUTTON_N, INPUT);
  pinMode(BUTTON_UP, INPUT);
  pinMode(BUTTON_DOWN, INPUT);
  
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);
  pinMode(ledPinF, OUTPUT);
  pinMode(ledPinG, OUTPUT);
}

void led0()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, LOW);
  digitalWrite(ledPinF, LOW);
  digitalWrite(ledPinG, HIGH);
}
void led1()
{
  digitalWrite(ledPinA, HIGH);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, HIGH);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, HIGH);
  digitalWrite(ledPinG, HIGH);
}
void led2()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, HIGH);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, LOW);
  digitalWrite(ledPinF, HIGH);
  digitalWrite(ledPinG, LOW);
}
void led3()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, HIGH);
  digitalWrite(ledPinG, LOW);
}
void led4()
{
  digitalWrite(ledPinA, HIGH);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, HIGH);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, LOW);
  digitalWrite(ledPinG, LOW);
}
void led5()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, HIGH);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, LOW);
  digitalWrite(ledPinG, LOW);
}
void led6()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, HIGH);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, LOW);
  digitalWrite(ledPinF, LOW);
  digitalWrite(ledPinG, LOW);
}
void led7()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, HIGH);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, HIGH);
  digitalWrite(ledPinG, HIGH);
}
void led8()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, LOW);
  digitalWrite(ledPinF, LOW);
  digitalWrite(ledPinG, LOW);
}
void led9()
{
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, LOW);
  digitalWrite(ledPinG, LOW);
}

void setLed(int number)
{
  switch (number)
  {
    case 0:  
      led0();
      break;
    case 1:  
      led1();
      break;
    case 2:  
      led2();
      break;
    case 3:  
      led3();
      break;
    case 4:  
      led4();
      break;
    case 5:  
      led5();
      break;
    case 6:  
      led6();
      break;
    case 7:  
      led7();
      break;
    case 8:  
      led8();
      break;
    case 9:  
      led9();
      break;
  }
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void oldloop()
{
  led0();
  led1();
  led2();
  led3();
  led4();
  led5();
  led6();
  led7();
  led8();
  led9();
}

void loop()
{
//neutral

    val_n =  digitalRead(BUTTON_N);
    if ((val_n == HIGH) &&gear<=2)
    {
     gear = HIGH;
      delay(100);
    }

// Gear Up

    val_up = digitalRead(BUTTON_UP);
    if ((val_up == HIGH) && (old_val_up == LOW) &&(gear<6) && (gear>0))
    {
      gear += 1;
      delay(100);
    }
    
    else if ((val_up == HIGH) && (old_val_up == LOW) &&(gear==0))
    {
      gear += 2;
      delay(100);
    }
    old_val_up = val_up;

// Gear Down

    val_down = digitalRead(BUTTON_DOWN);
    if ((val_down == HIGH) && (old_val_down == LOW)&& (gear>1))
    {
      gear -= 1;
      delay(100);
    }
    
    else   if ((val_down == HIGH) && (old_val_down == LOW) && (gear==0))
    {
      gear += 1;
      delay(100);
    }
    old_val_down = val_down;

// Max Limit

    if (gear >= 5)
    {
      gear = 5;
    }
    
    setLed(gear);
}
