
// #define til at give et navn til en konstant værdi 
#define RoterendeSensor A0 //Tilkoblet pin A0
#define FuldRotation 300
#define LED 3 //LED er tilsluttet pin 3 
#define ADC 5 //Så den kan aflæse sensoren lettere og mere præcis
#define VCC 5 //Normalt 5v

 
void setup()
{
    Serial.begin(9600); //Hvor hurtig den kommunikerer
    pinMode(RoterendeSensor, INPUT);
    pinMode(LED,OUTPUT); //Klargør til pin 3 til output
}
 
void loop()
{   
    float vol;
    int sensorValue = analogRead(RoterendeSensor);
    vol = (float)sensorValue*ADC/1023;
    float degrees = (vol*FuldRotation)/VCC; //Beregn degree
    Serial.println("Vinklen mellem ståpunkt og start punkt"); //Printer sætningen i serial monitor 
    Serial.println(degrees);
 
    int brightness;
    brightness = map(degrees, 0, FuldRotation, 0, 300);
    analogWrite(LED,brightness);
    //Millisekunder 
    delay(0.05); //Vent i 0.05 ms
   
}
