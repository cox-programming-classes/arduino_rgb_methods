#define RED_PIN 2
#define GREEN_PIN 3
#define BLUE_PIN 4

#define BUTTON_PIN 5
#define BUTTON2_PIN 7

void setup() 
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
}

#define LED_COUNT 3

int ledPins[] = { RED_PIN, GREEN_PIN, BLUE_PIN };
bool ledStates[] = { false, false, false };

// Set each of the LED States to what ever
// is given here for Red, Green, and Blue
void setLEDState(bool r, bool g, bool b)
{
  ledStates[0] = r;
  ledStates[1] = g;
  ledStates[2] = b;
}

// Update all of the LEDs to be On or Off
// based on the ledStates array.
void updateLEDs()
{
  // repeat for each LED number
  for(int i = 0; i < LED_COUNT; i++)
  {
    if(ledStates[i])
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
}

// Turn on each LED in sequence one at a time.
void cycleLEDs()
{
  setLEDState(true, false, false);
  updateLEDs();
  delay(1000);

  if(turnOffLEDsOn2Pressed()) return; // end the method here.

  setLEDState(false, true, false);
  updateLEDs();
  delay(1000);

  if(turnOffLEDsOn2Pressed()) return;

  setLEDState(false, false, true);
  updateLEDs();
  delay(1000);

  if(turnOffLEDsOn2Pressed()) return;


  setLEDState(false, false, false);
  updateLEDs();
}

bool turnOffLEDsOn2Pressed()
{
  bool is2Pressed =
    digitalRead(BUTTON2_PIN) == LOW;

  if(is2Pressed)
  {
    setLEDState(false, false, false);
    updateLEDs();
    return true;
  }

  return false;
}

void loop() 
{
  bool isPressed =
    digitalRead(BUTTON_PIN) == LOW;
  
  if(isPressed)
    cycleLEDs();

  delay(50);
}
