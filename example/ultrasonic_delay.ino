#define echoPin 11
#define trigPin 12

long distance_in_cm;

void setup() {
  Serial.begin (9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  measure_distance();
  Serial.print(distance_in_cm);
  Serial.println("");
  delay(1000);
}

void measure_distance() {
  long duration;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance_in_cm = (duration/2.0) / 29.1;
}
