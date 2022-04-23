# define motor_pump_pin 3
# define water_level_pin 5
const int AirValue = 620;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent = 0;
void setup() {
  pinMode(motor_pump_pin,OUTPUT);
  digitalWrite(motor_pump_pin,LOW);
    pinMode(water_level_pin,INPUT);
  digitalWrite(water_level_pin,LOW);
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop() {
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if (soilmoisturepercent >= 100)
  {
    soilmoisturepercent = 100;
    Serial.println("100 %");
  }
  else if (soilmoisturepercent <= 0)
  {
    soilmoisturepercent = 0;
    Serial.println("0 %");
  }
  else if (soilmoisturepercent > 0 && soilmoisturepercent < 100)
  {
    Serial.print(soilmoisturepercent);
    Serial.println("%");
  }

  if(soilmoisturepercent <= 85)
  {
    digitalWrite(motor_pump_pin,LOW);
    }
  else
  {
    digitalWrite(motor_pump_pin,HIGH);
    }

  
  delay(250);
}
