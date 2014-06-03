#include "PrintGeneration.hpp"
using namespace ::ConwayGameOfLife;

PrintGeneration::PrintGeneration(IOutputCells& outputter) :
    _outputter(outputter)
{}

void PrintGeneration::handle(GenerationCompleted event) {
    for (auto cell : event.grid.iterator()) {
        if (cell.isLiving) {
            _outputter.writeLivingCell();
        } else {
            _outputter.writeDeadCell();
        }
        if (cell.position.x() + 1 == event.grid.size()) {
            _outputter.startNextRow();
        }
    }
    _outputter.startNextRow();
}
