#ifndef _CONWAYGAMEOFLIFE_OUTPUTPLAINTEXTCELLS_HPP_
#define _CONWAYGAMEOFLIFE_OUTPUTPLAINTEXTCELLS_HPP_

#include "IOutputCells.hpp"

#include <ostream>

namespace ConwayGameOfLife {
	class OutputPlaintextCells: public IOutputCells {
	public:
        OutputPlaintextCells(std::ostream&);

        void writeLivingCell();
        void writeDeadCell();
        void startNextRow();

    private:
        std::ostream& _outputStream;
	};
}
#endif
