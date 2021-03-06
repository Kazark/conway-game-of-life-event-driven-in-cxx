#ifndef _CONWAYGAMEOFLIFE_AGGREGATECELLSTATECHANGES_HPP_
#define _CONWAYGAMEOFLIFE_AGGREGATECELLSTATECHANGES_HPP_

#include "IPublish.hpp"
#include "IHandle.hpp"

#include "BuildGrid.hpp"

#include "CellStateChanged.hpp"
#include "GameInitiated.hpp"

namespace ConwayGameOfLife {
	class AggregateCellStateChanges:
        public ::EventArchitecture::IHandle<CellStateChanged>,
        public ::EventArchitecture::IHandle<GameInitiated>
    {
	public:
        AggregateCellStateChanges(::EventArchitecture::IPublish&);
        void handle(GameInitiated);
        void handle(CellStateChanged);

	private:
        ::EventArchitecture::IPublish& _bus;
        BuildGrid _buildGrid;
	};
}
#endif
