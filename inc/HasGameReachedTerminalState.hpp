#ifndef _CONWAYGAMEOFLIFE_HASGAMEREACHEDTERMINALSTATE_HPP_
#define _CONWAYGAMEOFLIFE_HASGAMEREACHEDTERMINALSTATE_HPP_

#include "IHandle.hpp"
#include "IPublish.hpp"

#include "GameInitiated.hpp"
#include "CellStateChangesAggregated.hpp"

namespace ConwayGameOfLife {
	class HasGameReachedTerminalState:
        public ::EventArchitecture::IHandle<GameInitiated>,
        public ::EventArchitecture::IHandle<CellStateChangesAggregated>
    {
	public:
        HasGameReachedTerminalState(::EventArchitecture::IPublish&);

        void handle(GameInitiated);
        void handle(CellStateChangesAggregated);

	private:
        ::EventArchitecture::IPublish& _bus;
	};
}
#endif
