
char Str; // Receive instructions from USB

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  DDRB = DDRB | B111111;  //Sets up the pins for output

}

void loop() {
//   Str = Serial.read();
      //--------------------------------------------
//  if (Str == 'A') // Download data
//    {
        PORTB = B000111; // sets digital pins 
        delayMicroseconds(200);
        PORTB = B000101; // sets digital pins 
        delayMicroseconds(200);
        PORTB = B000111; // sets digital pins
        delayMicroseconds(100);
      //--------------------------------------------
         for (int i=0; i < 2086; i++)
         {
            PORTB = B000011; // sets digital pins
            delayMicroseconds(10);
            PORTB = B000010; // sets digital pins
            //int sensorValue = analogRead(A0);
//            Serial.print("[");
//            Serial.print(sensorValue);
//            Serial.println("]");
             delayMicroseconds(10);
         }// for
         //Serial.println("end");
       //-------------------------------------------
//    }// if
delay(30);
}// loop

