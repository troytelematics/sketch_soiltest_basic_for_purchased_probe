/*
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps

  int total = 0;
  float avg = 0.0;

  for (int i = 0; i < 2000; i++) {
    int val;
    val = analogRead(36); //connect sensor to Analog 0
    total += val;
    avg = total / (i+1);
  delay(100);
  Serial.println(val);
  Serial.print(avg); //print the value to serial port
  Serial.println();


  }

}
void loop() {
}
*/
/***************************************************
 This example reads Capacitive Soil Moisture Sensor.
 
 Created 2015-10-21
 By berinie Chen <bernie.chen@dfrobot.com>
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here: https://www.dfrobot.com/wiki/index.php?title=Capacitive_Soil_Moisture_Sensor_SKU:SEN0193
 2.This code is tested on Arduino Uno.
 3.Sensor is connect to Analog 0 port.
 ****************************************************/

const int AirValue = 384;//520;   //you need to replace this value with Value_1
const int WaterValue =2200;//260;  //you need to replace this value with Value_2
int intervals = (WaterValue-AirValue)/3;   
int soilMoistureValue = 0;
void setup() {
  Serial.begin(115200); // open serial port, set the baud rate to 9600 bps
}
void loop() {
soilMoistureValue = analogRead(36);  //put Sensor insert into soil
Serial.println(soilMoistureValue);
if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
{
  Serial.println("Very Wet");
}
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
  Serial.println("Wet");
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
  Serial.println("Dry");
}
delay(2000);
}
