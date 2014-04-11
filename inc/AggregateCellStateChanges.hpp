#ifndef _CONWAYGAMEOFLIFE_AGGREGATECELLSTATECHANGES_HPP_
#define _CONWAYGAMEOFLIFE_AGGREGATECELLSTATECHANGES_HPP_

#include "IPublish.hpp"
#include "IHandle.hpp"

#include "CellStateChanged.hpp"
#include "GameInitiated.hpp"

namespace ConwayGameOfLife {
	class AggregateCellStateChanges :
        ::EventArchitecture::IHandle<CellStateChanged>,
        ::EventArchitecture::IHandle<GameInitiated>
    {
	public:
        AggregateCellStateChanges(::EventArchitecture::IPublish&);
        void handle(CellStateChanged);
        void handle(GameInitiated);
	private:
        ::EventArchitecture::IPublish& _bus;
	};
}
#endif