#include "InitiateGameWithRandomGrid.hpp"
#include "GameInitiated.hpp"
using namespace ::ConwayGameOfLife;

InitiateGameWithRandomGrid::InitiateGameWithRandomGrid(::EventArchitecture::IPublish& bus) :
    _bus(bus)
{
}

void InitiateGameWithRandomGrid::initiate() {
    GameInitiated event = {true, false, true, false,
                           true, false, true, false,
                           false, true, true, false,
                           false, true, true, true};
    _bus.publish(event);
}
