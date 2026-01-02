const int pinA = 8;
const int pinB = 9;


// possible states of rotary encoder
const int states[4][2] = {
  {LOW, LOW},   // no contact
  {HIGH, LOW},  // pinA contact
  {HIGH, HIGH}, // pinA & pinB contact
  {LOW, HIGH}   // pinB contact
};


int encoderPosition = 0;




void updatePins() {
  int currentStateA = states[encoderPosition][0];
  int currentStateB = states[encoderPosition][1];


  // set pins to the current state values
  digitalWrite(pinA, currentStateA);
  digitalWrite(pinB, currentStateB);


  // for visualization, prints to the serial plotter
  Serial.print(currentStateA);
  Serial.print(",");
  Serial.println(currentStateB);
}


// one CW rotation
void rotateCW() {
  encoderPosition = (encoderPosition + 1) % 4;
  updatePins();
}


// One CCW rotation
void rotateCCW() {
  encoderPosition = (encoderPosition - 1 + 4) % 4;
  updatePins();
}






void setup() {
  Serial.begin(9600);
  Serial.println("Send 1 for full CW cycle, 0 for full CCW cycle");


  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);


  // startup opacity (temporary solution to set starting opacity value); values were chosen for the purposes of this project but can be adjusted easily
  updatePins();
  for (int i = 0; i < 300; i++) {
    rotateCCW();
    delay(5);
      }
  for (int i = 0; i < 200; i++) {
    rotateCW();
    delay(5);
      }


}


void loop() {


    for (int i = 0; i < 59; i++) {
      rotateCW();
      delay(800);
    }
    delay(15000);
    Serial.println("BACK DOWN");
    for (int i = 0; i < 59; i++) {
      rotateCCW();
      delay(10);
      }
    delay(1000);
}



