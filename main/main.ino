/*
Note of the impolementation of common HTTP errors:
1xx - Informative response
2xx - success
3xx - redirection
4xx - client error
5xx - server errors

https://en.wikipedia.org/wiki/List_of_HTTP_status_codes

Created with @bestcode123 and @adeer67 on GitHub

https://github.com/bestcode123/Self-Driving-Room-Clearer # For github webpage/releases

https://github.com/bestcode123/Self-Driving-Room-Clearer.git # For git clones etc


*** MORE INFORMATION IS FOUND IN README.md FILE ***
*/

#define trigPin1 1 // Chancge Later
#define echoPin1 2 // Chancge Later
#define trigPin2 3 // Chancge Later
#define echoPin2 4 // Chancge Later

float duration1, distance1, duration2, distance2;

float getDistanceData2(int distanceData) {
  if(distanceData < 2 || distanceData > 1) {
    if(distanceData == 1) {
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);

      duration1 = pulseIn(echoPin1, HIGH);
      distance1 = duration1 * 0.037 / 2;

      return distance1;
    } else {
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);

      duration2 = pulseIn(echoPin2, HIGH);
      distance2 = duration2 * 0.037 / 2;

      return distance2;
    }
  } else {
    return 400;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Getting the HC-SR04 distance data

  float distances[2] = { getDistanceData2(1), getDistanceData2(2) };

}
