# Valve control

Control a solenoid valve via a MOSFET with ROS and an arduino

## Hardware setup
* Power the Valve (via the DC-DC converter) with `25V` max!
* Connect the signal cable to the arduino
```
Y -> Pin 3
BLK -> Ground
```
## SW setup
* Copy the Udev rule to `/etc/udev/rules.d/`
```
cp auxiliary/98-usb-serial.rules /etc/udev/rules.d/
```
* Install deps:
```
sudo apt install ros-$ROS_DISTRO-rosserial ros-$ROS_DISTRO-rosserial-arduino
```

* build

## Run:
```
roslaunch valve_control valve.launch