//
// Created by vincent on 29/09/16.
//

#ifndef N_PUZZLE_ALGASTAT_HPP
#define N_PUZZLE_ALGASTAT_HPP

# include "AAlgorithm.hpp"

class AlgoAStar : public AAlgorithm {
public:
	AlgoAStar(PQ &open, PQ &close, State &final);
	virtual ~AlgoAStar(void);

	virtual int compute() override;

private:
	bool			isInQueue(PQ &queue, State &el);
	bool			processNewState(State *moved);
};


#endif //N_PUZZLE_ALGASTAT_HPP
