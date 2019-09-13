//
// Created by nvuletic on 11.9.19..
//

#include <iostream>
#include "../Machine.h"
#include "../Components/Conveyor.h"
#include "../Components/Feeder.h"
#include "../Components/PaintStation.h"
#include "../Components/Delivery.h"

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

        std::shared_ptr<Feeder> feeder = std::make_shared<Feeder>("Feeder Test 1", *machine.get(), 17000, 100);
        machine->addComponent(feeder);

        std::shared_ptr<PaintStation> cyan = std::make_shared<PaintStation>("PaintStation Cyan Test 1", *machine.get(), 10000, 10000);
        machine->addComponent(cyan);

        std::shared_ptr<PaintStation> magenta = std::make_shared<PaintStation>("PaintStation Magenta Test 1", *machine.get(), 10000, 10000);
        machine->addComponent(magenta);

        std::shared_ptr<PaintStation> yellow = std::make_shared<PaintStation>("PaintStation Yellow Test 1", *machine.get(), 10000, 10000);
        machine->addComponent(yellow);

        std::shared_ptr<PaintStation> black = std::make_shared<PaintStation>("PaintStation Black Test 1", *machine.get(), 10000, 10000);
        machine->addComponent(black);

        std::shared_ptr<Delivery> delivery = std::make_shared<Delivery>("Delivery Test 1", *machine.get(), 17000, 16950);
        machine->addComponent(delivery);

        std::shared_ptr<Conveyor> conveyor = std::make_shared<Conveyor>("Conveyor Test 1", *machine.get(), 15000,
                                                                        15000);
        machine->addComponent(conveyor);

        printMachineState(logger, machine);
        machine->start();

        cin.get();
    } catch (std::exception &e) {
        cout << "Exception was thrown : " << e.what();
    }
    return 0;
}
