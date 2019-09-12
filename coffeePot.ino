

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;
unsigned int pitch;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(A1, INPUT);
  digitalWrite(ledPin, HIGH);
  Serial.println("Calculating max and min value ");


 while(millis() < 5000){
    sensorValue = analogRead(A1);
    if (sensorValue > sensorHigh) {
        sensorHigh = sensorValue;
      }
    if (sensorValue < sensorLow){
        sensorLow= sensorValue;
      } 

  }

  
  Serial.print("The high Value is: ");
  Serial.println(sensorHigh);

  Serial.print("The low Value is: ");
  Serial.println(sensorLow);
 
   digitalWrite(ledPin, LOW);
}


void loop() {
  sensorValue = analogRead(A1);
  unsigned int pitch = map(sensorValue, sensorLow, sensorHigh, 50 ,1000);
  //Serial.print("The tone is: ");
  //Serial.println(pitch);
    
    
    if(sensorValue <= sensorLow+100){
      //Serial.println("I am not playing a tone");
      Serial.print("NOT ALLOWED sensor value: "); 
      Serial.println(sensorValue);
      tone(8, 5, 50);
      } else {
        tone(8, pitch, 50);
        Serial.print("sensor value: "); 
        Serial.println(sensorValue);
        }

      delay(10);

     
}
