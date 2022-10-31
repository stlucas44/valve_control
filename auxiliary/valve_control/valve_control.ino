#include <ros.h>
#include <std_msgs/Bool.h>

// NOTE: make sure rosserial is installed via Sketch -> Include Library -> Manage Libraries -> Rosserial Arduino Library

const int VALVE_PIN = 3;

ros::NodeHandle  nh;

void valveCallback( const std_msgs::Bool& msg){
  digitalWrite(VALVE_PIN, msg.data ? HIGH : LOW);   // set open / close valve
  digitalWrite(LED_BUILTIN, msg.data ? HIGH : LOW);   // blink the led

}

ros::Subscriber<std_msgs::Bool> sub("nozzle", &valveCallback);

void setup()
{ 
  pinMode(VALVE_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(VALVE_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
