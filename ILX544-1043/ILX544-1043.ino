
char Str; // Receive instructions from USB
byte arraySensor[1043]; // data

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
for (int m=0; m <= 20; m++)
{
//--------------------------------------------------
        PORTB = B000111; // sets digital pins 
        delayMicroseconds(200);
        PORTB = B000101; // sets digital pins 
        delayMicroseconds(200);
        PORTB = B000111; // sets digital pins
        delayMicroseconds(100);
      //--------------------------------------------
         for (int i=0; i < 1043; i++)
         {
            PORTB = B000011; // sets digital pins
            delayMicroseconds(10);
            PORTB = B000010; // sets digital pins
            //-------------------------------------
            PORTB = B000011; // sets digital pins
            delayMicroseconds(10);
            PORTB = B000010; // sets digital pins
            byte sensorValue = analogRead(A0);
            arraySensor[i] = sensorValue;
            delayMicroseconds(10);
         }// for
         delay (1); // Integration time
//--------------------------------------------------
} // for loop       
       //-------------------------------------------
        for (int i=0; i < 1043; i++)
         {
            Serial.println(arraySensor[i]);
         }// for
         Serial.println("end");
    }// if
}// loop

