const int TrigPin1 = 2;
const int EchoPin1 = 3;
const int TrigPin2 = 4;
const int EchoPin2 = 5;
const int TrigPin3 = 6;
const int EchoPin3 = 7;
const int lightPin = 8;
float cm;

void setup()
{
  Serial.begin(9600);
  pinMode(TrigPin1, OUTPUT );
  pinMode(EchoPin1, INPUT);
  pinMode(TrigPin2, OUTPUT );
  pinMode(EchoPin2, INPUT);
  pinMode(TrigPin3, OUTPUT );
  pinMode(EchoPin3, INPUT);
  pinMode(lightPin, OUTPUT);
}
void loop()
{
  digitalWrite(lightPin, LOW);
  if (Serial.read() == 's') {
    while(Serial.read() != 'o'){
      digitalWrite(lightPin, HIGH);
      getDistance(TrigPin1, EchoPin1);
      //getDistance(TrigPin2, EchoPin2);
      //getDistance(TrigPin3, EchoPin3);
    }
    digitalWrite(lightPin, LOW);
  }
}
void getDistance(int trig, int echo){
  digitalWrite(trig, LOW); //低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  cm = pulseIn(echo, HIGH) / 58.0; //将回波时间换算成cm
  int mm = int(cm * 10); //保留两位小数
  Serial.print(mm);
  Serial.print("mm");
  Serial.println();
  delay(1000);	//时间不能低于500ms
}
  
