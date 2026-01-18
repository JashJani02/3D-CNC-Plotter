// C++ code
//
const int redPin = 50;
const int bluePin = 51;
const int greenPin = 52;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{
  setColor(255, 0, 0);   //Red color
  delay(1004);
  setColor(0, 255, 0); //Green color
  delay(1004);
  setColor(0, 0, 255); // Blue color
  delay(1004);
  setColor(255,255,255); // White color
  delay(1004);
  setColor(255,255,0);  // Yellow color
  delay(1004);
  setColor(0,255,255); // Cyan color
  delay(1004);
  setColor(255,0,255); // Purple color
  delay(1004);
  setColor(220,100,310); // skin color 
  delay(1004);
  setColor(120,240,360); // light-green color
  delay(1004);
}
// Function to set RGB color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
