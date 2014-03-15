#ifndef _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFDEADCELLCOUNTEDHANDLER_HPP_
#define _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFDEADCELLCOUNTEDHANDLER_HPP_

#include "IHandle.hpp"
#include "LivingNeighborsOfDeadCellCounted.hpp"
#include "CellLived.hpp"
#include "CellDied.hpp"

namespace ConwayGameOfLife {
	class DetermineNextStateOfDeadCell: public EventArchitecture::IHandle<LivingNeighborsOfDeadCellCounted> {
	public:
        DetermineNextStateOfDeadCell(IHandle<CellLived>&, IHandle<CellDied>&);
        void handle(LivingNeighborsOfDeadCellCounted);
	private:
        void cellComesToLifeAt(CartesianPosition) const;
        void cellRemainsDeadAt(CartesianPosition) const;

        IHandle<CellLived>& _cellLivedHandler;
        IHandle<CellDied>& _cellDiedHandler;
	};
}
#endif
