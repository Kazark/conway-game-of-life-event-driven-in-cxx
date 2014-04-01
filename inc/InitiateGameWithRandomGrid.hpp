#ifndef _CONWAYGAMEOFLIFE_INITIATEGAMEWITHRANDOMGRID_HPP_
#define _CONWAYGAMEOFLIFE_INITIATEGAMEWITHRANDOMGRID_HPP_

#include "IPublish.hpp"

namespace ConwayGameOfLife {
	class InitiateGameWithRandomGrid {
	public:
        InitiateGameWithRandomGrid(::EventArchitecture::IPublish&);
        void initiate();
	private:
        ::EventArchitecture::IPublish& _bus;
	};
}
#endif
