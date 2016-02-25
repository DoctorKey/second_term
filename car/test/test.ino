#define LED_PIN 13
int speed_base,deriction;
void setup() {
 Serial.begin(38400);
pinMode(LED_PIN,OUTPUT);
}

void loop() {
  while (Serial.available() >= 0) {   // 串口收到字符数大于零。
    speed_base = Serial.parseInt();           // 在串口数据流中查找一个有效整数。
    deriction=Serial.parseInt(); 
    if (Serial.read() == 'x') {      // 收到结束符后开始处理数据。
      Serial.print("speed:");
      Serial.print(speed_base);
      Serial.print("\t");
      Serial.println(deriction);
    }
  }
}
