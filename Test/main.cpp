//
// Created by nvuletic on 11.9.19..
//

#include "../Logger/Logger.h"
#include "../Machine.h"
#include "../Component.h"
#include "../TestingComponents/SimpleComponent.h"

using namespace std;

void loggerTest() {
    Logger logger("Main");
    logger.Log("Hello World!");
}

void machineTestReceiveMessage() {
    Machine machine("Test Machine 1");
    SimpleComponent simpleComponent("Test Component 1", machine);
    simpleComponent.Emit(std::make_shared<ComponentMessage>(Neutral, "Test Neutral Message!"));
}

int main() {
    machineTestReceiveMessage();
    return 0;
}
