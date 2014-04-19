#include "OutputPlaintextCells.hpp"
using namespace ConwayGameOfLife;

OutputPlaintextCells::OutputPlaintextCells(std::ostream& outputStream) :
    _outputStream(outputStream)
{}

void OutputPlaintextCells::writeLivingCell() {
    _outputStream << "O";
}

void OutputPlaintextCells::writeDeadCell() {
    _outputStream << ".";
}

void OutputPlaintextCells::startNextRow() {
    _outputStream << "\n"; //std::endl;
}
