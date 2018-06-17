#include <Servo.h>      // Thư viện điều khiển servo
Servo Ser1;
Servo Ser2;  

int servoPin = 9;
int servoPin1 = 10;

int dem=90;
int dem1=90;
int bugiat = 1;

void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  
  Ser1.attach(servoPin); 
  Ser2.attach(servoPin1);
  
  Ser1.write(90);
  Ser2.write(90);
  
  delay(5000);
  Serial.begin(9600);
}

void loop() 
{
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
  int d = analogRead(A3);
 // delay(100);
  Ser1.write(dem);
  Ser2.write(dem1);
  
  Serial.print("\nA0= ");
  Serial.print(a);
  Serial.print("\tA1= ");
  Serial.print(b);
  Serial.print("\tA2= ");
  Serial.print(c);
  Serial.print("\tA3= ");
  Serial.println(d);

// servo 2
    int sa2 = a + d;
    int sb2 = b + c;
    Serial.print("sa2: ");  Serial.println(sa2);
    Serial.print("sb2: ");  Serial.println(sb2);
    Serial.println("");
    if(sa2-sb2 > bugiat || sb2-sa2 > bugiat )
    {
      if(sa2 > sb2)
      {
        Serial.println("aaaaaa");
        dem1 = dem1-1;
        if(dem1 <= 0)
        {
          dem1 = 0;
        }
      }
      if(sa2 < sb2)
      {
        Serial.println("bbbbbb");
        
        dem1 = dem1 + 1;
        if(dem1 >= 179)
        {
          dem1 = 179;
        }
      }
    }
    

  //servo 1
  int sa = a + b;
  int sb = c + d;
  Serial.print("sa: ");  Serial.println(sa);
  Serial.print("sb: ");  Serial.println(sb);
  Serial.println("");
  if(sa-sb > bugiat || sb-sa > bugiat)
  {
    if(sa > sb)
    {
      dem = dem + 1;
      if(dem >= 179)
      {
         dem = 179;  
      }
    }
    if(sa < sb)
    {
      dem = dem - 1;
      if(dem <= 0)
      {
         dem = 0;
      }
    }
  }

  Serial.print("\tdem= ");
  Serial.print(dem);
  Serial.print("\tdem1= ");
  Serial.print(dem1); 
  
  Ser1.write(dem);
  Ser2.write(dem1);
  delay(50);
}
