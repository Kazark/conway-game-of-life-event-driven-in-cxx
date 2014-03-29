#include "Bus.hpp"
#include "LazyInitContainer.hpp"
#include "Inject.hpp"
#include "DeliverEventsUntilNoneLeft.hpp"
using namespace ::EventArchitecture;

#include "CountLivingNeighbors.hpp"
using namespace ::ConwayGameOfLife;

int main(int /*argCount*/, char* /*argArray*/[])
{
    LazyInitContainer container;
    container.registerInjector<Router>(Inject<>::Into<Router>);
    container.registerInjector<Channel>(Inject<Router>::Into<Channel>);
    container.registerInjector<Bus>(Inject<Router, Channel>::Into<Bus>);
    container.registerInjector<DeliverEventsUntilNoneLeft>(Inject<Channel>::Into<DeliverEventsUntilNoneLeft>);
    container.registerInjector<CountLivingNeighbors>(Inject<Bus>::Into<CountLivingNeighbors>);

    auto bus = container.getInstanceOf<Bus>();
    bus.registerHandler(container.getInstanceOf<CountLivingNeighbors>());

    auto mainLoop = container.getInstanceOf<DeliverEventsUntilNoneLeft>();
    mainLoop.run();

    return 0;
}
