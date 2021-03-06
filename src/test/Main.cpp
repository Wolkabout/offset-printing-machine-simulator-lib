//
// Created by nvuletic on 11.9.19..
//

#include "components/Conveyor.h"
#include "components/Delivery.h"
#include "components/Feeder.h"
#include "components/PaintStation.h"
#include "Machine.h"

#include <iostream>

using namespace simulator;

void printMachineState(Logger& logger, std::shared_ptr<Machine> machine)
{
    logger.Log("[MS] " + machine->getName() + " | " + std::to_string(machine->getComponents().size()));
}

void printActionResults(Logger& logger, ActionStatusMessage& message)
{
    logger.Log("[ACM] " +
    std::to_string(static_cast<double>(message.getType())) + " | " + message.getContent());
}

class CountListener : public CountMessageReceiver
{
private:
    Logger m_logger;
    TempoComponent& m_component;
public:
    CountListener(const Logger& logger, TempoComponent& component) : m_logger(logger), m_component(component) {}

    void ReceiveMessage(std::shared_ptr<CountMessage> ptr) override
    {
        m_logger.Log("[CL] Component " +
                     m_component.getName() + " says : " + std::to_string(ptr->getCount()));
    }
};

int main()
{
    try
    {
        Logger logger("Main()");
        std::shared_ptr<Machine> machine =
                std::make_shared<Machine>("Test Machine 1");
        printMachineState(logger, machine);

        std::shared_ptr<Feeder> feeder =
                std::make_shared<Feeder>("Feeder Test 1", *machine,
                                                                  17000, 100);
        machine->addComponent(feeder);
        std::shared_ptr<CountMessageReceiver> listener =
                std::make_shared<CountListener>(logger, *feeder);
        feeder->getCountMessageReceiver().push_back(listener);

        std::shared_ptr<PaintStation> cyan =
                std::make_shared<PaintStation>("PaintStation Cyan Test 1",
                        *machine, 10000, 10000);
        machine->addComponent(cyan);

        std::shared_ptr<PaintStation> magenta =
                std::make_shared<PaintStation>("PaintStation Magenta Test 1",
                        *machine, 10000, 10000);
        machine->addComponent(magenta);

        std::shared_ptr<PaintStation> yellow =
                std::make_shared<PaintStation>("PaintStation Yellow Test 1",
                        *machine, 10000, 10000);
        machine->addComponent(yellow);

        std::shared_ptr<PaintStation> black =
                std::make_shared<PaintStation>("PaintStation Black Test 1",
                        *machine, 10000, 10000);
        machine->addComponent(black);

        std::shared_ptr<Delivery> delivery =
                std::make_shared<Delivery>("Delivery Test 1",
                        *machine, 17000, 16950);
        machine->addComponent(delivery);

        std::shared_ptr<Conveyor> conveyor =
                std::make_shared<Conveyor>("Conveyor Test 1",
                        *machine, 15000, 15000);
        machine->addComponent(conveyor);

        printMachineState(logger, machine);
        machine->start();

        std::cin.get();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception was thrown : " << e.what();
    }
    return 0;
}
