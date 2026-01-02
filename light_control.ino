const int orangePin = 3;
const int whitePin = 11;
// values below were chosen through experimentation to fit project needs
const int minVal = 1;
const int maxVal = 59;


void setup() {


  pinMode(orangePin, OUTPUT);
  pinMode(whitePin, OUTPUT);
 
  analogWrite(orangePin, 0);
  analogWrite(whitePin, 255);


}


void loop() {


  delay(1000);


  // orange fades up / white fades down
  for (int i = minVal; i <= maxVal; i++) {
    float x_orange = (float)(i - minVal) / (maxVal - minVal);
    float x_white = 1.0 - x_orange;


    // gamma correction
    int pwmOrange = 255 * pow(x_orange, 2.2);
    int pwmWhite = 255 * pow(x_white, 2.2);


    analogWrite(orangePin, pwmOrange);
    analogWrite(whitePin, pwmWhite);
   
    delay(800); 
  }


    delay(2000); 




  // orange fades down / white fades up
  for (int i = maxVal; i >= minVal; i--) {
    float x_orange = (float)(i - minVal) / (maxVal - minVal);
    float x_white = 1.0 - x_orange;


    int pwmOrange = 255 * pow(x_orange, 2.2);
    int pwmWhite = 255 * pow(x_white, 2.2);


    analogWrite(orangePin, pwmOrange);
    analogWrite(whitePin, pwmWhite);
   
    delay(25);
  }


}

