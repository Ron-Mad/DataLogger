#define ERROR_PIN D02
int counter=0;
bool errorFlag = 0;
bool setTimestatus = 0;
String timeStr;
uint16_t hour, minute, second, day, month, year;

void setup() {
  pinMode(D01,OUTPUT);digitalWrite(D01,LOW);
  pinMode(ERROR_PIN,OUTPUT);digitalWrite(ERROR_PIN,LOW);

  Serial.begin(9600);
  hour =    21;
  minute =  15;
  second =  0;
  day =     9;
  month =   5;
  year =    2018;

  setTimestatus = Clock.setDateTime(year,month,day,hour,minute,second);
  if (!setTimestatus){
    errorFlag = 1;
  }

}

void loop() {
  if (!errorFlag){
    counter +=1;
    digitalWrite(D01,HIGH);
    delay(500);
    digitalWrite(D01,LOW);
    if (counter%(60*10)==0){//each ~10 minutes
      Serial.println("Counter value is: ");
      Serial.println(counter);
  
      Serial.println("current time is:");
      timeStr = Clock.currentDateTime();
      Serial.println(timeStr);
    }
    digitalWrite(ERROR_PIN,LOW);
  }
  else{ //error 
    digitalToggle(ERROR_PIN);
    digitalWrite(D01,LOW);
  }
  delay(500);
}

