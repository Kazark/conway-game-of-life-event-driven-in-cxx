#include "Router.hpp"
using namespace ::EventArchitecture;

void Router::invokeHandler(Event* event) const
{
    auto unpackager = registry.at(std::type_index(typeid(*event)));
    unpackager->invokeHandler(event);
}
