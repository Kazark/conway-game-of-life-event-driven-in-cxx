#ifndef _CONWAYGAMEOFLIFE_EQUILIBRIUMREACHED_HPP_
#define _CONWAYGAMEOFLIFE_EQUILIBRIUMREACHED_HPP_

#include "Event.hpp"

namespace ConwayGameOfLife {
	struct EquilibriumReached : public ::EventArchitecture::Event {
        unsigned GenerationNumber;
	};
}
#endif
