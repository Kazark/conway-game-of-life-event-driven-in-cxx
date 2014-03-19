#ifndef _CONWAYGAMEOFLIFE_COUNTLIVINGNEIGHBORS_HPP_
#define _CONWAYGAMEOFLIFE_COUNTLIVINGNEIGHBORS_HPP_

#include "IHandle.hpp"
#include "IPublish.hpp"
#include "GenerationCompleted.hpp"

namespace ConwayGameOfLife {
	class CountLivingNeighbors : public ::EventArchitecture::IHandle<GenerationCompleted> {
	public:
        CountLivingNeighbors(::EventArchitecture::IPublish& bus);

        void handle(GenerationCompleted);
	private:
        ::EventArchitecture::IPublish& _bus;
	};
}
#endif
