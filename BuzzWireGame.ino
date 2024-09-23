int relayPin = 7;   // Relay control pin
int buttonPin = 2;  // Button input pin
int buttonState = 0;
bool relayState = LOW; // Current state of the relay

void setup() {
  pinMode(relayPin, OUTPUT);      // Set relay pin as output
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  digitalWrite(relayPin, relayState);  // Initially set relay to NC (Normally Closed)
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the state of the button

  if (buttonState == LOW) {  // Button is pressed (active LOW with internal pull-up)
    delay(50);  // Debounce delay to prevent multiple activations
    relayState = !relayState;  // Toggle relay state
    digitalWrite(relayPin, relayState);  // Set relay to new state

    // Wait until button is released
    while (digitalRead(buttonPin) == LOW) {
      // Do nothing, wait for release
    }
    
    delay(200);  // Small delay to avoid bouncing after button release
  }
}
