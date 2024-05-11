## Connect RC controllers to your computer
Requires an Arduino Mega and any RC receivers

### Recommended RC simulators
This code makes Arudino+RC controller emulates a USB joystick for any computer and software.

For Windows: Phoenix RC [Download](https://www.rc-thoughts.com/phoenix-sim/)
do not forget to install an emulator to avoid needing their proprietary dongle.

For Linux: Check this website [here](https://www.linuxquestions.org/questions/linux-games-33/linux-rc-simulators-4175668078/). Koji and Serzed have tried [crrcsim](https://sourceforge.net/projects/crrcsim/). Not as realistic as Phoenix RC, but it works. You can install it via apt and ARU (yay).


### Wiring
Connect the RC receiver's ground to Arduino's GND
power (middle pin) to 5V on Arduino
Connect signal pins to Arduino pins according to the table below
| RC Channel | Arduino Pin |
| - | -- |
| 1 | 21 |
| 2 | 20 |
| 3 | 19 |
| 4 | 18 |

### How to install
1. Use Arduino IDE to upload this code to Arduino Mega
2. Download [UnoJoy](https://github.com/AlanChatham/UnoJoy)
3. Put Arduino into DFU MODE ([guide](https://support.arduino.cc/hc/en-us/articles/4410804625682-Set-a-board-to-DFU-mode))
4. Run Unojoy/TurnIntoAJoystick (.bat in Windows, .command in Mac?, .sh in Linux) to turn Arduino into a USB joystick

When you want to turn the Arduino back into a normal Arduino, run MegaJoy/TurnIntoAnArduino
