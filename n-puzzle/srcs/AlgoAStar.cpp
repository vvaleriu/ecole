//
// Created by vincent on 29/09/16.
//

#include "AlgoAStar.hpp"

/*
 * ============================
 * 		PUBLIC METHODS
 * ============================
 * */

/*
* ---- CONSTRUCTORS ----
* */
AlgoAStar::AlgoAStar(PQ &open, PQ &close, State &final) : AAlgorithm(open, close, final) {}

AlgoAStar::~AlgoAStar(void) {}

int 	AlgoAStar::compute() {
	State*	moved = NULL;
	bool 	solved = false;
	State	top;

	while (open.size() > 0 && !solved) {
		top = open.top();
		if (top == final) {
			solved = true;
			break;
		}
		open.pop();
		close.push(top);
		if ((moved = top.moveLeft())) {
			if ((solved = processNewState(moved)))
				break;
		}
		moved = NULL;
		if ((moved = top.moveRight())) {
			if ((solved = processNewState(moved)))
				break;
		}
		moved = NULL;
		if ((moved = top.moveUp())) {
			if ((solved = processNewState(moved)))
				break;
		}
		moved = NULL;
		if ((moved = top.moveDown())) {
			if ((solved = processNewState(moved)))
				break;
		}
	}
	if (solved) {
		std::cout << "probleme resolu (tours : )" << std::endl;
		moved->printAllInfo();
		//printSolution(*moved);
	}
	std::cout << "FIN" << std::endl;
	return 1;
}
/*
* ============================
* 		PRIVATE METHODS
* ============================
* */
bool		AlgoAStar::processNewState(State *moved) {
	if (*moved == final)
		return true;
	if (isInQueue(open, *moved))
		return false;
	if (isInQueue(close, *moved))
		return false;
	open.push(*moved);
	return false;
}

bool 		AlgoAStar::isInQueue(PQ &queue, State &el) {
	size_t	queueSize = queue.size();
	PQ		tmpQ;
	State 	tmpEl;

//	std::cout << "(avant) longeur : " << queue.size() << std::endl;
	for (long i = 0; i < queueSize; ++i) {
		tmpEl = queue.top();
		queue.pop();
		if (tmpEl == el) {
			if (el.getG() < tmpEl.getG()) {
				queue.push(el);
				boost::heap::heap_merge(queue, tmpQ);
			}
			else {
				queue.push(tmpEl);
				boost::heap::heap_merge(queue, tmpQ);
			}
//			std::cout << "(apres) longeur : " << queue.size() << std::endl;
			return true;
		}
		tmpQ.push(tmpEl);
	}
	boost::heap::heap_merge(queue, tmpQ);
	return false;
}
