#include "AS726X.h"
// TODO: make the code look like less of a travesty
AS726X sensor;
void setup() {
 Wire.begin();
  Serial.begin(115200);
  sensor.begin();

}

int x = 0;
void loop() {
  sensor.takeMeasurements();
  //Prints all measurements
  // need to find way to store into a list

// store measurements
float sensor_values[6] = {(sensor.getCalibratedViolet()),(sensor.getCalibratedBlue()), (sensor.getCalibratedGreen()), (sensor.getCalibratedYellow()), (sensor.getCalibratedOrange()), (sensor.getCalibratedRed())};
// {violet, blue, green, yellow, orange, red}
float red = 0;
float total = 0;
red = sensor.getCalibratedRed();
for (int i = 0; i <= 5; i++)
{
  //Serial.println(i);
Serial.println(sensor_values[i]);
total += sensor_values[i];
}
float ratio = red/total;
float original_red;
float original_total;
float original_ratio;

  if (x == 0)
  {
    original_red = sensor.getCalibratedRed();
    for (int i = 0; i <= 5; i++)
    {
    original_total += sensor_values[i];
    }
    original_ratio = original_red/original_total;
  }
Serial.println(original_ratio);
Serial.println(ratio);
Serial.println();
x++;
delay(1000);  // only prints every 5000 milliseconds
if (original_ratio + 0.1 < ratio)
{
  Serial.println("Red filter is on");
  }
}
