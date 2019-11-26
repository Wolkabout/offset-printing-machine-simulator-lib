# Offset Printing Machine Simulator
This project provides a C++ library, which contains everything necessary to simulate workings
of an offset printing machine (on a simplified level)

This project is meant to be included in a bigger application, wrapping it and providing a GUI,
and exposing data to Modbus registers.

## Building & Installation

Project requires a few dependencies, for *apt* running Linux distributions you can run:

```
sudo snap install cmake --classic
sudo apt-get install g++ libpthread-stubs0-dev
```

From there, you can run the shell script setup to build the entire project:
```
. build.sh
```

Which generates the library, and an example executable:
```
./modbus_simulator_testing
```

### How it works

This application uses a Machine/Component structure, where the Machine actually hosts the
components, serves to be host for start and stop inputs. It can provide instruction messages to all components,
and also receive messages from them, and based on them stopping if necessary.

Components are the ones doing all the logic, such as counting the amount of paper/color, causing issues that stop the machine, etc...

Conveyor component is the heart of the operation. It hosts the new thread that the simulator opens,
and in that thread, it keeps interacting with other components, to modify their count in the necessary way.

Other components just serve to keep track of counts, and also notify the machine if they are bottomed out.
