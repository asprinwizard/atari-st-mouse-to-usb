#include <Mouse.h>

/*
#define inputX2 1;
#define inputX1 2;
#define inputY1 3;
#define inputY2 4;
*/

int inputX2 = 2;
int inputX1 = 3;
int inputY1 = 4;
int inputY2 = 5;
int buttonL = 6;
int buttonR = 7;

int xCounter = 0;
int xState = 0;
int xLastState = 0;
int xPosition = 0;

int yCounter = 0;
int yState = 0;
int yLastState = 0;
int yPosition = 0;

int leftButtonState = HIGH;
int leftButtonLastState = HIGH;

int rightButtonState = HIGH;
int rightButtonLastState = LOW;

float mouseSpeed = 10.0;
float xDistance = 0;
float yDistance = 0;

void setup() {
  //Serial.begin(1200);

  // X-axis
  pinMode(inputX1, INPUT);
  pinMode(inputX2, INPUT);

  // Y-axis
  pinMode(inputY1, INPUT);
  pinMode(inputY2, INPUT);

  //Buttons
  pinMode(buttonL, INPUT_PULLUP);
  pinMode(buttonR, INPUT_PULLUP);

  Serial.begin (115200);

  //initiate the Mouse library
  Mouse.begin();

  xLastState = digitalRead(inputX2);
  yLastState = digitalRead(inputY1);
}

void loop() {
  //Serial.print("debug");
  xDistance = 0;
  yDistance = 0;
  
  // Handle X Position
  xState = digitalRead(inputX2);
  if (xState != xLastState) {   
    if (digitalRead(inputX1) != xState) { 
      xCounter ++;
    } else {
      xCounter --;
    }
    //Serial.print("X Position: ");
    //Serial.println(xCounter);

    xDistance = (xPosition - xCounter) * mouseSpeed;
    xPosition = xCounter;
  } 
  xLastState = xState;

  // Handle Y position
  yState = digitalRead(inputY1);
  if (yState != yLastState) {     
    if (digitalRead(inputY2) != yState) { 
      yCounter ++;
    } else {
      yCounter --;
    }
    //Serial.print("Y Position: ");
    //Serial.println(yCounter);

    yDistance = (yPosition - yCounter) * mouseSpeed;
    yPosition = yCounter;
  } 
  yLastState = yState;

  // Move mouse
  Mouse.move(xDistance, yDistance, 0);

  // Handle buttons
  leftButtonState = digitalRead(buttonL);
  if (leftButtonState != leftButtonLastState) {
    //Serial.print("Left button:");
    if (leftButtonState == LOW) {
      //Serial.println("down");
      Mouse.press(MOUSE_LEFT);
    } else {
      //Serial.println("up");
      Mouse.release(MOUSE_LEFT);
    }
     
    leftButtonLastState = leftButtonState;
    delay(20);
  }
  
  rightButtonState = digitalRead(buttonR);
  if (rightButtonState != rightButtonLastState) {
    //Serial.print("Right button:");
    if (rightButtonState == LOW) {
      //Serial.println("down");
      Mouse.press(MOUSE_RIGHT);
    } else {
      //Serial.println("up");
      Mouse.release(MOUSE_RIGHT);
    }
     
    rightButtonLastState = rightButtonState;
    delay(20);
  }
}
