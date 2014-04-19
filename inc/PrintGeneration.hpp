#ifndef _CONWAYGAMEOFLIFE_PRINTGENERATION_HPP_
#define _CONWAYGAMEOFLIFE_PRINTGENERATION_HPP_

#include "IHandle.hpp"
#include "IOutputCells.hpp"
#include "GenerationCompleted.hpp"

namespace ConwayGameOfLife {
	class PrintGeneration: public ::EventArchitecture::IHandle<GenerationCompleted> {
	public:
        PrintGeneration(IOutputCells&);

        void handle(GenerationCompleted);

	private:
        IOutputCells& _outputter;
	};
}
#endif
