int pin6 = 6;
int tempOn = 30; //tepltoa zapnutí
int tempOff = 28; //tepltoa vypnutí
float temp = 0;

#include <OneWire.h>
#include <DallasTemperature.h>

// pin termomether
#define pin 5

OneWire oneWire(pin);                       
DallasTemperature sensors(&oneWire);           
 


void setup() {
   Serial.begin(9600);
   pinMode(pin6, OUTPUT);
   // zapnutí senzoru                          
   sensors.begin();
   digitalWrite(6, LOW);   
}

void loop() {

  sensors.requestTemperatures();               
  temp = (sensors.getTempCByIndex(0));   
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();
   
   if (temp > tempOn)  {   //  If the temperature higher than ...
   Serial.print("TEMP is higher than = ");
   Serial.print(tempOn);
   Serial.print(" I turn on the FAN");
   Serial.println();
  
     while (temp > tempOn) {  //  As long as the temperature remains over ...
      sensors.requestTemperatures();7
      temp = (sensors.getTempCByIndex(0));
      digitalWrite(6, HIGH); // turns fan relay on
      Serial.print("TEMP is higher than = ");
      Serial.print(temp);
      Serial.print("*C");
      Serial.print("the FAN is still running. TEMP:");
      Serial.print(temp);
      Serial.print("*C");
      Serial.println();
      delay(6000); // update sensor reading each one 6 sec
      }
   }
    else if (temp < tempOff){  // If temperature is less than ...
    digitalWrite(6, LOW);  // turn or leave fan off.
    Serial.print("TEMP is lower than = ");
    Serial.print(tempOff);
    Serial.print("*C");
    Serial.print(" FAN: off | TEMP: ");
    Serial.print(temp);
    Serial.print("*C");
    Serial.println();
  }
  
  
   delay(6000); // update sensor reading each one minute
}
