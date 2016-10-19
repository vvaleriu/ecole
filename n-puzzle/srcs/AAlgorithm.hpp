//
// Created by vincent on 29/09/16.
//

#ifndef N_PUZZLE_AALGORITHM_HPP
#define N_PUZZLE_AALGORITHM_HPP


# include "State.hpp"

class AAlgorithm {
public:
	AAlgorithm(PQ &open, PQ &close, State &final);
	virtual ~AAlgorithm(void);

	virtual int	compute() = 0;

protected:
	PQ &open;
	PQ &close;
	State &final;
};


#endif //N_PUZZLE_AALGORITHM_HPP
