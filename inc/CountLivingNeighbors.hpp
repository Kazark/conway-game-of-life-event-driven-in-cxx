#ifndef _CONWAYGAMEOFLIFE_COUNTLIVINGNEIGHBORS_HPP_
#define _CONWAYGAMEOFLIFE_COUNTLIVINGNEIGHBORS_HPP_

#include "IHandle.hpp"
#include "GenerationCompleted.hpp"
#include "LivingNeighborsOfDeadCellCounted.hpp"
#include "LivingNeighborsOfLiveCellCounted.hpp"

namespace ConwayGameOfLife {
	class CountLivingNeighbors : public ::EventArchitecture::IHandle<GenerationCompleted> {
	public:
        CountLivingNeighbors(::EventArchitecture::IHandle<LivingNeighborsOfLiveCellCounted>&,
                             ::EventArchitecture::IHandle<LivingNeighborsOfDeadCellCounted>&);

        void handle(GenerationCompleted);
	private:
        ::EventArchitecture::IHandle<LivingNeighborsOfLiveCellCounted>& _liveCellEventHandler;
        ::EventArchitecture::IHandle<LivingNeighborsOfDeadCellCounted>& _deadCellEventHandler;
	};
}
#endif
