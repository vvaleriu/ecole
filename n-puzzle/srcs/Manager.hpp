//
// Created by vincent on 02/08/16.
//

#ifndef N_PUZZLE_MANAGER_HPP
# define N_PUZZLE_MANAGER_HPP

# include "../headers/n_puzzle.h"
# include "State.hpp"
# include "AHeuristic.hpp"
# include "AAlgorithm.hpp"
# include "AlgoAStar.hpp"
# include <boost/heap/priority_queue.hpp>

struct StateCompare
{
	bool operator()(const State &e1, const State &e2) const
	{
		std::cout  << std::endl << "A: " << std::endl;
		e1.printAllInfo();
		std::cout << "B: " << std::endl;
		e2.printAllInfo();
		std::cout << "A: " << e1.getF() << " B: " << e2.getF() << std::endl;
		std::cout << "true or false : " << (e1.getF() > e2.getF() ? "true" : "false") << std::endl;
		return e1.getF() > e2.getF();
	}
};

using namespace		boost::heap;

class Manager {

public:
	State				initial;
	State				final;
	static AHeuristic*	heuristic;
	PQ					open;
	PQ					close;

	Manager(void);
	virtual 		~Manager(void);
	int 			init(int ac, char** av);
	int 			compute();
	void 			printSolution(State &solution) const;

	const State&	getInitial() const;
	void 			setInitial(const State &initial);
	const State&	getFinal() const;
	const PQ&		getOpen() const;
	void 			setOpen(const PQ &open);
	const PQ&		getClose() const;
	void			setClose(const PQ &close);

private:
	long 			turn = 0;
};

#endif //N_PUZZLE_MANAGER_HPP
