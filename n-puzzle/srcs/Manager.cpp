//
// Created by vincent on 02/08/16.
//

#include "Manager.hpp"
#include "HeuManhattan.hpp"

AHeuristic* Manager::heuristic = NULL;

/*
 * ============================
 * 		PUBLIC METHODS
 * ============================
 * */

/*
* ---- CONSTRUCTORS ----
* */
Manager::Manager(void) {}
Manager::~Manager(void) {}

int		Manager::init(int ac, char **av) {
	std::string		opt;

	// Create de l'etat initial
	if (ac == 1)
		this->initial = State(3);
	else if (ac == 2) {
		if (opt.assign(av[1]).find("--size=", 0) != std::string::npos) {
			this->initial = State(std::stoi(opt.substr(7, std::string::npos)));
		}
		else {
			this->initial = State(opt);
		}
	}
	this->final = State();
	this->final.setSize(this->initial.getSize());
	this->final.setTable(this->initial.getFinal(this->initial));

	// Debug
	std::cout << "============================" << std::endl;
	initial.printTable("initial");
	std::cout << "============================" << std::endl;

	// Choix de l'heuristique
	Manager::heuristic = new HeuManhattan(final);

	return 1;
}

int 	Manager::compute() {
	Manager::heuristic->setValues(initial);
	initial.setF();
	initial.setParent(NULL);
	open.push(initial);

	AAlgorithm *alg = new AlgoAStar(open, close, final);
	return alg->compute();
}

/*
* ============================
* 		PRIVATE METHODS
* ============================
* */

void 		Manager::printSolution(State &solution) const {
	const State	*tmp;

	tmp = solution.getParent();
	solution.printAllInfo();
	while (tmp) {
		tmp->printAllInfo();
		tmp = tmp->getParent();
	}
}

/*
 * ACCESSORS
 * */
const State &Manager::getInitial() const {return initial;}

void Manager::setInitial(const State &initial) {Manager::initial = initial;}

const State &Manager::getFinal() const {return final;}

void Manager::setFinal(const State &final){Manager::final = final;}

const PQ &Manager::getOpen() const {return open;}

void Manager::setOpen(const PQ &open) {Manager::open = open;}

const PQ &Manager::getClose() const {return close;}

void Manager::setClose(const PQ &close) {Manager::close = close;}
