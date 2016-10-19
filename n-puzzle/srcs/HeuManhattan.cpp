//
// Created by vincent on 04/08/16.
//

#include "HeuManhattan.hpp"
#include <algorithm>
#include <iterator>

/*
 * ============================
 * 		PUBLIC METHODS
 * ============================
 * */

/*
* ---- CONSTRUCTORS ----
* */
HeuManhattan::HeuManhattan(State& finalState) : AHeuristic(finalState) {}
HeuManhattan::~HeuManhattan(void) {}

void HeuManhattan::setValues(State &state) const {
	int32_t 	total = 0;
	int32_t 	finalPos = 0;
	int32_t 	absDistance = 0;

	for (int32_t i = 0; i < state.getSize(); ++i) {
		if (state.getTable()[i] != 0) {
			finalPos = std::distance(final.getTable(), std::find(final.getTable(), final.getTable() + final.getSize(), state.getTable()[i]));
			absDistance = abs((finalPos % State::edge_size) - (i % State::edge_size));
			absDistance += abs((finalPos / State::edge_size) - (i / State::edge_size));
			total += absDistance;
		}
	}
	state.setH(total);
}
/*
* ============================
* 		PRIVATE METHODS
* ============================
* */
