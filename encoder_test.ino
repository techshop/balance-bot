const byte interruptL = 2; // interrupt for left encoder
unsigned long timeL = 0; // time since last pulse received on left encoder
unsigned long pulseL = 0; // pulse width of left wheel encoder
unsigned long rpmL = 0; // speed (RPM) of left wheel

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptL), encodeL, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(rpmL);
}


// ===============================
// Interrupt service routine (ISR)
// ===============================


// encoder left
void encodeL() {
  pulseL= millis() - timeL; // time between last state change and this state change
  timeL = millis();  // update timeL with time of most recent state change
  rpmL = pulseToRPM(pulseL)
}



// ===============================
// Functions
// ===============================


/* 
function for calculating RPM of wheel hooked up to 8-pole
magnetic wheel encoder. an interrupt should be attached
to the hall-effect sensor, and this function should be called
on each interrupt

each call to the function represents 1/8 revolution of the wheel
in the time given by pulse (in miliseconds).  therfore, 
conversion to RPM is:
1000 * 60 * 1/8 * 1/pulse or 7500 / pulse


 */
unsigned long pulseToRPM(unsigned long pulse) {
  return 7500 / pulse; 
}

