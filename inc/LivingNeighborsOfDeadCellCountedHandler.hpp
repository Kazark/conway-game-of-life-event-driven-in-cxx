#ifndef _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFDEADCELLCOUNTEDHANDLER_HPP_
#define _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFDEADCELLCOUNTEDHANDLER_HPP_

#include "IHandle.hpp"
#include "LivingNeighborsOfDeadCellCounted.hpp"
#include "CellLived.hpp"
#include "CellDied.hpp"

namespace ConwayGameOfLife {
	class LivingNeighborsOfDeadCellCountedHandler: public EventArchitecture::IHandle<LivingNeighborsOfDeadCellCounted> {
	public:
        LivingNeighborsOfDeadCellCountedHandler(IHandle<CellLived>&, IHandle<CellDied>&);
        void handle(LivingNeighborsOfDeadCellCounted);
	private:
        IHandle<CellLived>& _cellLivedHandler;
        IHandle<CellDied>& _cellDiedHandler;
	};
}
#endif
