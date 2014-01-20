int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int pingPin = 11;               // ping sensor
int groundpin = 18;             // analog input pin 4 -- ground
int powerpin = 19;              // analog input pin 5 -- voltage
int xpin = A1;                  // x-axis of the accelerometer
int ypin = A2;                  // y-axis
int zpin = A3;                  // z-axis
int xpin0, ypin0, zpin0;        // define placeholder variable
int pingOld = 30;               // for bug checking 
int distBool = false;           // if (distBool || pir ) => video on


void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600);
  //establishContact();  // send a byte to establish contact until receiver responds 

}

void loop(){
  
  long duration, cm;
  
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
    // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW); 
  digitalWrite(powerpin, HIGH);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
    
  val = digitalRead(inputPin);  // read input value
 
if (cm > 200){ 
  distBool = true;
}


// print the sensor values:
      if ( (val == 1) || (distBool == true) ){     // 1 = close
        Serial.print(1);  
      }
      else Serial.print(0);                        // 0 = not close
      Serial.print(", ");
      Serial.print(" Distance: ");
      Serial.print(cm);    // distance
      Serial.print(", ");
      Serial.print(" Accelerometer: ");
      int xX = analogRead(xpin);
      Serial.print(abs(xX - xpin0));
      Serial.print(", ");
      int yY = analogRead(ypin); 
      Serial.print(abs(yY- ypin0));
      Serial.print(", ");
      int zZ = analogRead(zpin);
      Serial.print(abs(zZ - zpin0));
      Serial.println();



  xpin0 = analogRead(xpin);     // resets x-axis index
  ypin0 = analogRead(ypin);     // resets y-axis index
  zpin0 = analogRead(zpin);     // resets z-axis index
  
  delay(10);
  
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}






