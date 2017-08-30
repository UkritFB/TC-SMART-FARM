// DS1302:  RESET pin    -> Arduino Digital 2
//          IDATA pin    -> Arduino Digital 3
//          CLK   pin    -> Arduino Digital 4
// DHT11 :  DATA  pin    -> Arduino Digital 5
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
#include <dht11.h>
dht11 DHT11;                      //เรียกใช้ dth11 ในชื่ออะไร
DS1302 rtc(2, 3, 4);              //Pin ที่ใช้ในการต่อ RTC
#define DHT11PIN 5
LiquidCrystal_I2C lcd(0x27, 16, 2);
String date_start , time_start;
float temp_start, hum_start;

int i = 0;

void setup()
{
  lcd.begin();
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time_Now,Temp,Hum");

  //  Serial.println("################################## QUBE START #############################");
  //  Serial.println(DHT11LIB_VERSION);
  //---------------------------------------------SET TIME----------------------------------------
  //  rtc.setDOW(WEDNESDAY);      // Set Day-of-Week to FRIDAY
  //  rtc.setTime(13, 53, 0);     // Set the time to 12:00:00 (24hr format)
  //  rtc.setDate(17, 8, 2017);   // Set the date to August 6th, 2010
  //---------------------------------------------------------------------------------------------

}
void loop()
{

  int chk = DHT11.read(DHT11PIN);
  //
  //  if(i==0)
  //  {
  //    time_start = rtc.getTimeStr();
  //    date_start = rtc.getDateStr();
  //    temp_start = (float)DHT11.temperature,2;
  //    hum_start  = (float)DHT11.humidity,2;
  //    i=i+1;
  //  }
  String time_read = rtc.getTimeStr();

  Serial.print("DATA,");
  Serial.print(time_read);
  Serial.print(",");
  Serial.print((float)DHT11.temperature, 2);
  Serial.print(",");
  Serial.println((float)DHT11.humidity, 2);
  lcd.setCursor(0,0);
  lcd.print("TIME : ");
  lcd.print(time_read);
  
  lcd.setCursor(0,1);
  lcd.print("TEMP : " );
  lcd.print((float)DHT11.temperature, 2);
  lcd.print(" C");
  
  lcd.setCursor(0,2);
  lcd.print("HUM  : " );
  lcd.print((float)DHT11.humidity, 2);
  lcd.print(" %");
  
  //  Serial.print("Start: ");
  //  Serial.print(date_start);
  //  Serial.print("/");
  //  Serial.print(time_start);
  //  Serial.print("/");
  //  Serial.print(temp_start);
  //  Serial.print(" C /");
  //   Serial.print(hum_start);
  //  Serial.print(" % /");
  //
  //  // Send Day-of-Week
  //  Serial.print(rtc.getDOWStr());
  //  Serial.print(" ");
  //  // Send date
  //  Serial.print(rtc.getDateStr());
  //  Serial.print(" -- ");
  //  // Send time
  //  Serial.print(rtc.getTimeStr());
  //  // Wait one second before repeating :)
  //  Serial.print("  ");
  //  Serial.print("Humidity (%): ");
  //  Serial.print((float)DHT11.humidity,2);
  //  Serial.print("  ");
  //  Serial.print("Temperature (oC): ");
  //  Serial.println((float)DHT11.temperature,2);

  delay (1000);
 
}
