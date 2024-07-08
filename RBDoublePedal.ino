/*
  RBDoublePedal.ino
  v1.0 08/07/2024
  This lets you combine 2 on/off switch pedals into one for RB style drumkit controllers.

  Alix1723
*/

//Configuration
int leftPedalInputPin = 4; //Left pedal switch input
int rightPedalInputPin = 5; //Right pedal switch input
int controllerOutputPin = 12; //Combined output, plug this into the controller's pedal port

int holdTime = 15; //time to keep the input pressed in ms, pressing pedals together shorter than this will only count 1 press

//Tracking states
bool outputPedal = false;
bool inLeft = false;
bool inRight = false;
unsigned long leftHoldStart = 0;
unsigned long rightHoldStart = 0;
bool outLeft = false;
bool outRight = false;

void setup() {
  //Set pin modes appropriately
  pinMode(rightPedalInputPin, INPUT_PULLUP);
  pinMode(leftPedalInputPin, INPUT_PULLUP);
  pinMode(controllerOutputPin, OUTPUT);
}

void loop() {
  //Read the current pin states (may be inverted depending on pull-up etc)
  inRight = !digitalRead(rightPedalInputPin);
  inLeft = !digitalRead(leftPedalInputPin);

  //Right
  if(inRight == true)
  {
    if(rightHoldStart==0) //Start press
    {
        outRight = true;
        rightHoldStart = millis();
    }
    else //already pressed...
    {
      if(millis() - rightHoldStart > holdTime) //holdTime has elapsed, release
      {
          outRight = false;
      }
      //otherwise keep holding
    }
  }
  else
  {
    rightHoldStart = 0; //reset press
    outRight = false; //reset this just in case it's been held shorter than holdTime
  }
  
  //Left
  if(inLeft == true)
  {
    if(leftHoldStart==0) //Start press
    {
        outLeft = true;
        leftHoldStart = millis();
    }
    else //already pressed...
    {
      if(millis() - leftHoldStart > holdTime) //holdTime has elapsed, release
      {
          outLeft = false;
      }
      //otherwise keep holding
    }
  }
  else
  {
    leftHoldStart = 0; //reset press
    outLeft = false; //reset this just in case it's been held shorter than holdTime
  }

  //Output to the controller's pedal port
  outputPedal = (outRight == true) || (outLeft == true);
  digitalWrite(controllerOutputPin, !outputPedal);
}
