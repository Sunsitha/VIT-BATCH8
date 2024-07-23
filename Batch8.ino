int sensorState = 0;  // Defining the Eyeblink sensor state to low
# define eyeBlink A0  // Defining the pin connected to the eyeblink sensor
const int buzzer = 6; // Defining the pin connected to the buzzer

void setup()
{
  pinMode(eyeBlink, INPUT); // Defining the eyeblink sensor pin as input
  pinMode(buzzer, OUTPUT); // Defining the buzzer pin as output
  Serial.begin(9600); // Initiating serial communication with the serial monitor 
 }

void loop()
{
  sensorState = analogRead(eyeBlink); // Checks the eyeblink sensor output 
  noTone(buzzer); // Buzzer does not rings
  delay(1000); // Delay a little bit to improve simulation performance
  Serial.println(sensorState); // print the value
  if (sensorState<400){
    delay(1000); // wait 1 second to see if the person is drowsy 
    tone(buzzer, 500); // Buzzer rings to wake the person
    delay(3000); // Buzzerrings for 3 seconds
  }
}
