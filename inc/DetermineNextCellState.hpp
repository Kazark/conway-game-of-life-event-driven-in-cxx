#ifndef _CONWAYGAMEOFLIFE_DETERMINENEXTCELLSTATE_HPP_
#define _CONWAYGAMEOFLIFE_DETERMINENEXTCELLSTATE_HPP_

#include "IHandle.hpp"
#include "IPublish.hpp"
#include "LivingNeighborsOfCellCounted.hpp"

namespace ConwayGameOfLife {
	class DetermineNextCellState : ::EventArchitecture::IHandle<LivingNeighborsOfCellCounted> {
	public:
        DetermineNextCellState(::EventArchitecture::IPublish&);
        void handle(LivingNeighborsOfCellCounted);
	private:
        ::EventArchitecture::IPublish& _bus;
	};
}
#endif
