//
// Created by nvuletic on 11.9.19..
//

#include <iostream>
#include "../Machine.h"
#include "../Components/Conveyor.h"
#include "../Components/Feeder.h"

using namespace std;

void printMachineState(std::shared_ptr<Machine> machine) {
    cout << "[MS] " << machine->getName() << " | " << machine->getComponents().size() << endl;
}

void printActionResults(ActionStatusMessage &message) {
    cout << "[ACM] " << message.getType() << " | " << message.getContent() << endl;
}



int main() {
    try {
        std::shared_ptr<Machine> machine = std::make_shared<Machine>("Test Machine 1");
        printMachineState(machine);
        std::shared_ptr<Conveyor> conveyor = std::make_shared<Conveyor>("Conveyor Test 1", *machine.get(), 15000, 15000);
        machine->addComponent(conveyor);
        std::shared_ptr<Feeder> feeder = std::make_shared<Feeder>("Feeder Test 1", *machine.get(), 17000, 100);
        machine->addComponent(feeder);
        printMachineState(machine);
        machine->checkForErrors(false);
    } catch (std::exception& e) {
        cout << "Exception was thrown : " << e.what();
    }
    return 0;
}
