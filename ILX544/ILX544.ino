
char Str; // Receive instructions from USB

// constante para configuração do prescaler
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);

  ADCSRA &= ~PS_128;

  ADCSRA |= PS_16;
  
  DDRB = DDRB | B111111;  //Sets up the pins for output

}

void loop() {
   Str = Serial.read();
      //--------------------------------------------
  if (Str == 'A') // Download data
    {
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
            delayMicroseconds(1);
            PORTB = B000010; // sets digital pins
            int sensorValue = analogRead(A0);
            //Serial.print("[");
            Serial.println(sensorValue);
            //Serial.println("]");
            delayMicroseconds(1);
         }// for
         Serial.println("end");
       //-------------------------------------------
    }// if
}// loop

