#include "Bus.hpp"
#include "LazyInitContainer.hpp"
#include "Inject.hpp"
using namespace ::EventArchitecture;
#include "CountLivingNeighbors.hpp"
using namespace ::ConwayGameOfLife;

int main(int /*argCount*/, char* /*argArray*/[])
{
    LazyInitContainer container;
    container.registerInjector<Bus>(Inject<>::Into<Bus>);
    container.registerInjector<CountLivingNeighbors>(Inject<Bus>::Into<CountLivingNeighbors>);

    auto bus = container.getInstanceOf<Bus>();
    bus.registerHandler(container.getInstanceOf<CountLivingNeighbors>());

    return 0;
}
