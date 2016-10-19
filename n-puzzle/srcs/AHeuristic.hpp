//
// Created by vincent on 02/08/16.
//

#ifndef N_PUZZLE_IHEURISTIC_HPP
# define N_PUZZLE_IHEURISTIC_HPP

# include "State.hpp"

class AHeuristic {
public:
	AHeuristic(State &final);
	virtual			~AHeuristic(void);
	virtual void	setValues(State& state) const = 0;

	State&	getFinal() const;

protected:
	State& final;

private:
};


#endif //N_PUZZLE_IHEURISTIC_HPP
