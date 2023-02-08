# Prepare
## with platformIo(recommand)
1. install [vscode](https://code.visualstudio.com/) 
2. install [platformIO](https://platformio.org/install/ide?install=vscode)
3. import project
1. connect esp
4. Click the right arrow(Platform:Upload) on the blue bar at the bottom of vscode to flash


# Materials
+ 1x esp32
+ 1x 100K ohm NTC 3950 Thermistors
+ 2x 100K resistor
+ 1x PMOS 18p06p
+ heating wire (30 ohm)
# Cable Connect
3V(esp32) - 100K - 15(esp32) -thermmistors - GND

GND - common! ground

24v - D(Pmos)

S(Pmos) - heating wire - GND

4(ESP32) -G(Pmos)

D(Pmos) - 100K - S(Pmos)


<!-- # ROS Server
##  Install
1. Install ROS (recommand [Melodic](http://wiki.ros.org/melodic/Installation))

2. Install rosserial_python 

```apt-get install ros-melodic-rosserial-python```


## start rosserial_server
```source /opt/ros/melodic/setup.bash```

```rosrun rosserial_python serial_node.py tcp``` (default)
```rosrun rosserial_python node.py tcp```   (on Roboy) -->
