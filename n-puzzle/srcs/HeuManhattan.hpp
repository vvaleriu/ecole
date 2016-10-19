//
// Created by vincent on 04/08/16.
//

#ifndef N_PUZZLE_HEUMANHATTAN_HPP
#define N_PUZZLE_HEUMANHATTAN_HPP

# include "AHeuristic.hpp"
# include "State.hpp"

class HeuManhattan : public AHeuristic {
public:
	HeuManhattan(State& final);
	~HeuManhattan(void);
	virtual void setValues(State &state) const override;

private:
};


#endif //N_PUZZLE_HEUMANHATTAN_HPP
