#ifndef _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFLIVECELLCOUNTEDHANDLER_HPP_
#define _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFLIVECELLCOUNTEDHANDLER_HPP_

#include "IHandle.hpp"
#include "LivingNeighborsOfLiveCellCounted.hpp"
#include "CellLived.hpp"
#include "CellDied.hpp"

namespace ConwayGameOfLife {
	class DetermineNextStateOfLiveCell: public EventArchitecture::IHandle<LivingNeighborsOfLiveCellCounted> {
	public:
        DetermineNextStateOfLiveCell(IHandle<CellLived>&, IHandle<CellDied>&);
        void handle(LivingNeighborsOfLiveCellCounted);
	private:
        void cellDiesAt(CartesianPosition) const;
        void cellStaysAliveAt(CartesianPosition) const;

        IHandle<CellLived>& _cellLivedHandler;
        IHandle<CellDied>& _cellDiedHandler;
	};
}
#endif
