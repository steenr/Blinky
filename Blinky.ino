/*
  Blinky

  Turns an LED on and off while wrapping serial input back to the monitor.
  
  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  modified 17 May 2018
  by Eric Cartman


  This example code is in the public domain.
*/

bool ledState = 0;

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize serial connection
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if( ledState == 0 )
    digitalWrite( LED_BUILTIN, LOW );
  else
    digitalWrite( LED_BUILTIN, HIGH );

  while(Serial.available()) {
    char incoming = Serial.read();
    Serial.print(incoming);
    ledState = ~ledState;
  }
}
