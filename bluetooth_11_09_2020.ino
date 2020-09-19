#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial BTSerial(RxD, TxD); // RX, TX for Bluetooth

void setup() {
  Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor
  BTSerial.begin(9600); // For Bluetooth
  while (!Serial) {
    Serial.println("AT commands: okay");
  }
}
int counter = 0;
 const byte buflen = 10;
    char buf[ buflen ];
    int i = 0;
    bool res = false;
    
void loop() {
 
  if (BTSerial.available()) {
    Serial.println("Primo");
    //Serial.write(BTSerial.read());  
    buf[counter] = BTSerial.read();
    counter++;
    
  } else if (counter != i){
    Serial.println("Secondo");
    for (; i < counter; i++) {
      //Serial.print(buf[i]); 
    }
  } else if (counter == i && counter != 0) {
    Serial.println("Entro pure qua");
    res = true;
    counter = 0;
    i = 0;
  }

  if (res) {
    BTSerial.write("messaggio privato");
  }
  
    if (Serial.available()) {
    BTSerial.write(Serial.read());
    
  }
 
  /*
// put your main code here, to run repeatedly:
boolean isValidInput; 
do { 
 
  byte c; // get the next character from the bluetooth serial port

  while (!BTSerial.available()); 
    c = BTSerial.read(); // Execute the option based on the character recieved
    Serial.print(c); // Print the character received to the IDE serial monitor

    switch ( c ) {

    Serial.write("a");
      case 'a': // You've entered a
        // Do the code you need when 'a' is received.....
        BTSerial.println( "You've entered an 'a'" );
        isValidInput = true;
      break;

      case 'b': // You've entered b
        // Do the code you need when 'a' is received.....
        BTSerial.println( "You've entered an 'b'" );
        isValidInput = true;
      break;

      default:
        // Do the code you need when any other character is received.....
        BTSerial.println( "Please enter 'a' or 'b'" );
        isValidInput = false;
      break;
    }

  }while ( isValidInput == true ); // Repeat the loop
  */
}
