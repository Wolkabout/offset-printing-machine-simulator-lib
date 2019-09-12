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
    std::shared_ptr<Machine> machine = std::make_shared<Machine>("Test Machine 1");
    printMachineState(machine);
    std::shared_ptr<Conveyor> conveyor = std::make_shared<Conveyor>("Conveyor Test 1", machine, 15000, 15000);
    std::shared_ptr<Feeder> feeder = std::make_shared<Feeder>("Feeder Test 1", machine, 17000, 17000);
    printMachineState(machine);
    return 0;
}
