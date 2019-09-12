//
// Created by nvuletic on 11.9.19..
//

#include <iostream>
#include "../Machine.h"
#include "../Components/Conveyor.h"
#include "../Components/Feeder.h"

using namespace std;

void printMachineState(Logger &logger, std::shared_ptr<Machine> machine) {
    logger.Log("[MS] " + machine->getName() + " | " + std::to_string(machine->getComponents().size()));
}

void printActionResults(Logger &logger, ActionStatusMessage &message) {
    logger.Log("[ACM] " + std::to_string(message.getType()) + " | " + message.getContent());
}


int main() {
    try {
        Logger logger("Main()");
        std::shared_ptr<Machine> machine = std::make_shared<Machine>("Test Machine 1");
        printMachineState(logger, machine);
        std::shared_ptr<Conveyor> conveyor = std::make_shared<Conveyor>("Conveyor Test 1", *machine.get(), 15000,
                                                                        15000);
        machine->addComponent(conveyor);
        std::shared_ptr<Feeder> feeder = std::make_shared<Feeder>("Feeder Test 1", *machine.get(), 17000, 100);
        machine->addComponent(feeder);
        printMachineState(logger, machine);
        machine->checkForErrors(false);
        machine->start();
    } catch (std::exception &e) {
        cout << "Exception was thrown : " << e.what();
    }
    return 0;
}
