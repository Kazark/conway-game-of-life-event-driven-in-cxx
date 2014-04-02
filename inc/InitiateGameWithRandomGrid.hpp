#ifndef _CONWAYGAMEOFLIFE_INITIATEGAMEWITHRANDOMGRID_HPP_
#define _CONWAYGAMEOFLIFE_INITIATEGAMEWITHRANDOMGRID_HPP_

#include "IPublish.hpp"
#include "ReferenceType.hpp"

namespace ConwayGameOfLife {
	class InitiateGameWithRandomGrid: public ::EventArchitecture::ReferenceType {
	public:
        InitiateGameWithRandomGrid(::EventArchitecture::IPublish&);
        void initiate();
	private:
        ::EventArchitecture::IPublish& _bus;
	};
}
#endif
