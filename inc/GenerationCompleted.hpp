#ifndef _CONWAYGAMEOFLIFE_GENERATIONCOMPLETED_HPP_
#define _CONWAYGAMEOFLIFE_GENERATIONCOMPLETED_HPP_

#include "Event.hpp"
#include "Grid.hpp"
#include "Cell.hpp"

namespace ConwayGameOfLife {
	class GenerationCompleted : public ::EventArchitecture::Event {
	public:
        GenerationCompleted(std::initializer_list<bool> data) :
            grid(data)
        {}

        Grid grid;
	};
}
#endif
