//
// Created by vincent on 31/07/16.
//

#ifndef N_PUZZLE_N_PUZZLE_H
#define N_PUZZLE_N_PUZZLE_H

# include <stdint.h>
# include <cstddef>
# include <cstdlib>
# include <iostream>
# include "../srcs/State.hpp"
# include <boost/heap/priority_queue.hpp>

class State;

//typedef boost::heap::priority_queue<State, boost::heap::compare<StateCompare>> PQ
typedef boost::heap::priority_queue<State, boost::heap::compare<std::greater<State>>>	PQ;
//typedef boost::heap::priority_queue<State>	PQ;


#endif //N_PUZZLE_N_PUZZLE_H
