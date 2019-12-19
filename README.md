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
components, and takes inputs like start/stop. It can provide instruction messages to all components,
and also receive messages back from them, and stop based on a received message if necessary.

Components are the ones doing all the logic, such as counting the amount of paper/color,
causing issues that stop the machine, etc...

Conveyor component is the heart of the operation. It hosts the new thread that the simulator opens,
and in that thread, it keeps interacting with other components, to modify their count in their respective ways.

Other components just serve to keep track of counts, and also notify the machine if they are bottomed out.

### Usage

There is an example compiled together with the library, you can start by:
```
./out/test_example
```

The code for it is located in [here](src/Test/main.cpp).
I will go over it step by step:

You have to create a machine (you can name it anyway you want):
```
std::shared_ptr<Machine> machine = std::make_shared<Machine>("<MACHINE_NAME>");
```

And then you can add the components. The order you add components is important, because that's the order
in which the conveyor will iterate their counts. So, if you want the regular offset print machine layout, you'll create
and add components in such way:

```
// Create all the components
std::shared_ptr<Feeder> feeder = std::make_shared<Feeder>("<COMPONENT_NAME>", *machine.get(), 17000, 100);
std::shared_ptr<PaintStation> cyan = std::make_shared<PaintStation>("PaintStation <COMPONENT_NAME>", *machine.get(), 10000, 10000);
std::shared_ptr<PaintStation> magenta = std::make_shared<PaintStation>("PaintStation <COMPONENT_NAME>", *machine.get(), 10000, 10000);
std::shared_ptr<PaintStation> yellow = std::make_shared<PaintStation>("PaintStation <COMPONENT_NAME>", *machine.get(), 10000, 10000);
std::shared_ptr<PaintStation> black = std::make_shared<PaintStation>("PaintStation <COMPONENT_NAME>", *machine.get(), 10000, 10000);
std::shared_ptr<Delivery> delivery = std::make_shared<Delivery>("<COMPONENT_NAME>", *machine.get(), 17000, 16950);
std::shared_ptr<Conveyor> conveyor = std::make_shared<Conveyor>("<COMPONENT_NAME>", *machine.get(), 15000, 15000);
// Add all the components
machine->addComponent(feeder);
machine->addComponent(delivery);
machine->addComponent(cyan);
machine->addComponent(magenta);
machine->addComponent(yellow);
machine->addComponent(black);
machine->addComponent(conveyor);
```

All components take as arguments a name, maximum value, and default value for their count, where the count for feeder
is amount of paper it can dispense, delivery is amount of papers it collected, and conveyor the speed it will print by.
There is an internal split, to *TempoComponents* (they inherit this abstract class), and to the Conveyor. Conveyor interacts
only with TempoComponents, and iterates their count, and their count is modify-able (in the implemented way).
<b>All components except the Conveyor are TempoComponents.</b>

Now, you can always provide inputs to the machine, such as:
```
machine->start();
machine->stop();

// There exists a checkForErrors, which checks if the machine is ready to start working.
// It is not necessary to run, as start will check for errors anyways.

machine->checkForErrors();
```

For the machine and components you can create listeners. You create a class that inherits the abstract class,
which there exists 4:
- ExternalMachineStateReceiver, which needs to override *void ReceiveMachineState(bool)*. This one receives 
the machines state when it gets changed. You get a *true* if it is on, and *false* if it is off. You can at any 
point check the state, by:
```
machine->isRunning();
```
- ExternalMachineMessageReceiver, which needs to override *void ReceiveMessage(std::shared_ptr<ComponentMessage>)*.
This on receives any messages the machine emits, worthy for the user. Such as empty components, failing components, 
running low, etc... All the messages also can be accessed by:
```
machine->getMessages();
```
- CountMessageReceiver, which needs to override *void ReceiveMessage(std::shared_ptr<CountMessage>)*. This one provides
the specific count, and the percentage that is to the full capacity, of the TempoComponent you attached the listener to.
For TempoComponents, you can also get these at any time by:
```
tempoComponent->getCount();
tempoComponent->getPercentage();
tempoComponent->getCapacity();
```
- ConveyorRateMessageReceiver, which needs to override *void ReceiveMessage(std::shared_ptr<ConveyorRateMessage>)*. This one
is just like the CountMessageReceiver, but for the only non-TempoComponent, the Conveyor. You create it and attach it, and it will
receive the tempo value whenever it is changed. You can get it at any point by:
```
conveyor->getRatePerHour();
```

After you create a class, and override the receivers you need, create an instance, and attach it to the machine/component.

```
machine->getExternalMachineStateReceivers().push_back(stateReceiver);
machine->getExternalMessageReceivers().push_back(messageReceiver)
tempoComponent->getCountMessageReceiver().push_back(countReceiver);
conveyor->getRateMessageReceivers().push_back(rateReceiver);
```

Now from the second thread, the receivers will execute methods when count is changed/rate has been changed, machine state 
has changed, etc...
