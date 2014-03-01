#ifndef _CONWAYGAMEOFLIFE_GENERATIONINITIATED_HPP_
#define _CONWAYGAMEOFLIFE_GENERATIONINITIATED_HPP_

#include "Event.hpp"

namespace ConwayGameOfLife {
	struct GenerationInitiated : public ::EventArchitecture::Event {
        unsigned GenerationNumber;
	};
}
#endif
