#ifndef _CONWAYGAMEOFLIFE_IOUTPUTCELLS_HPP_
#define _CONWAYGAMEOFLIFE_IOUTPUTCELLS_HPP_

#include "ReferenceType.hpp"

namespace ConwayGameOfLife {
	struct IOutputCells: public ::EventArchitecture::ReferenceType {
        virtual ~IOutputCells() {}
        virtual void writeLivingCell() = 0;
        virtual void writeDeadCell() = 0;
        virtual void startNextRow() = 0;
	};
}
#endif
