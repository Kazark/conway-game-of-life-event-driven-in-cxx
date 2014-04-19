#ifndef _CONWAYGAMEOFLIFE_IOUTPUTCELLS_HPP_
#define _CONWAYGAMEOFLIFE_IOUTPUTCELLS_HPP_
namespace ConwayGameOfLife {
	struct IOutputCells {
        virtual ~IOutputCells() {}
        virtual void writeLivingCell() = 0;
        virtual void writeDeadCell() = 0;
        virtual void startNextRow() = 0;
	};
}
#endif
