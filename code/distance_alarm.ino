//Here we assign each pin on UNO wrt to the circuit in code
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;
const int buzzerPin = 8;

const float warningDistance = 50.0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}
// 9600 is the baud rate
// since these pins are gpio, we need to assign if they re i/o or o/o


void loop() {
  // Send a short ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure how long the echo pin stays HIGH
  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) {
    Serial.println("No echo detected");
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100);
    return;
  }

  // Sound travels to the object and back
  float distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= warningDistance && distance >= 2.0) {
    digitalWrite(ledPin, HIGH);

    // Closer object = shorter gap between beeps
    int beepGap = (int)(distance * 8.0);
    beepGap = constrain(beepGap, 40, 160);

    digitalWrite(buzzerPin, HIGH);
    delay(40);
    digitalWrite(buzzerPin, LOW);
    delay(beepGap);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
}
