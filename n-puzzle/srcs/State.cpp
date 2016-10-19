//
// Created by vincent on 30/07/16.
//

#include "State.hpp"
#include "Manager.hpp"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <boost/tokenizer.hpp>

int32_t		State::edge_size = 0;

/*
 * =========================================================
 * 					PUBLIC LOGIC
 * =========================================================
 * */

/*
 * -----------------------------------
 * 			CONSTRUCTORS
 * -----------------------------------
 * */
State::State() {}
State::~State() {}

/**
 * Genera aleatoirement une table dont le cote est egal a la taille rentree en
 * parametre
 * @param size: Taille d'un cote de la table
 * */
State::State(uint32_t size) {
	int32_t		i = -1;
	int32_t 	random;

	if (size < 3)
		std::cout << "La taille minimale d'une table est de 3" << std::endl;
	try {
		table = new int[size * size];
		while (++i < size * size)
			table[i] = -1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	State::edge_size = size;
	this->size = size * size;
	srand(time(NULL));
	i = -1;
	while (++i < this->size) {
		random = std::rand() % (this->size);
		if (std::find(table, table + (this->size), random) != table + (this->size))
			--i;
		else
			table[i] = random;
	}/*
	table[0] = 1;
	table[1] = 2;
	table[2] = 3;
	table[3] = 4;
	table[4] = 0;
	table[5] = 5;
	table[6] = 7;
	table[7] = 8;
	table[8] = 6;*/
}

/**
 * Creer un etat initial a partir d'un fichier contentant la table de jeu
 * @param filename: nom du fichier contenant la table
 * */
State::State(std::string& filename) {
	std::ifstream 	ifs(filename);
	std::string		line;

	if (ifs.is_open()) {
		while (std::getline(ifs, line)) {
			//std::cout << line << std::endl;
			this->parseFile(*this, line);
		}
		ifs.close();
	}
}

/*
 * -----------------------------------
 * 				LOGIC
 * -----------------------------------
 * */

bool mySort(int i, int j) {
	if (i == 0)
		return false;
	else if (j == 0)
		return true;
	return i <= j;
}

/**
 * Retourne le resultat tel qu'il doit etre au final
 * */
int*	State::getFinal(State& initial) {
	int*	sorted = new int[initial.getSize()];

	std::copy(initial.getTable(),
			  initial.getTable() + initial.getSize(), sorted);
	std::sort(sorted, sorted + initial.getSize(), mySort);
	return sorted;
}

void 	State::incrementG() {
	++g;
}

State* 	State::moveLeft(void) const {
	int32_t		rk;

	rk = std::distance(table, std::find(table, table + size, 0));
	return this->moveLeft(rk);
}

/**
 * Retourne un pointeur vers une copie de l'instance a la difference pres que la
 * table a ete bougee
 * */
State*	State::moveLeft(int32_t& i) const {
	State*	ret = NULL;
	int32_t tmp;

	if (!table)
		return 0;
	if (i % State::edge_size != State::edge_size - 1) {
		ret = new State();
		*ret = *this;
		if (this->getParent() == ret) {
			delete ret;
			return NULL;
		}
		tmp = table[i + 1];
		ret->table[i + 1] = 0;
		ret->table[i] = tmp;
		ret->setParent(this);
		ret->setMovedValues();
	}
	return ret;
}

State* 	State::moveRight(void) const {
	int32_t		rk;

	rk = std::distance(table, std::find(table, table + size, 0));
	return this->moveRight(rk);
}

State*	State::moveRight(int32_t& i) const {
	State*	ret = NULL;
	int32_t tmp;

	if (!table)
		return 0;
	if (i % State::edge_size != 0) {
		ret = new State();
		*ret = *this;
		tmp = table[i - 1];
		ret->table[i - 1] = 0;
		ret->table[i] = tmp;
		ret->setParent(this);
		ret->setMovedValues();
	}
	return ret;
}

State* 	State::moveDown(void) const {
	int32_t		rk;

	rk = std::distance(table, std::find(table, table + size, 0));
	return this->moveDown(rk);
}

State*	State::moveDown(int32_t& i) const {
	State*	ret = NULL;
	int32_t tmp;

	if (!table)
		return 0;
	if (i >= State::edge_size) {
		ret = new State();
		*ret = *this;
		tmp = table[i - State::edge_size];
		ret->table[i - State::edge_size] = 0;
		ret->table[i] = tmp;
		ret->setParent(this);
		ret->setMovedValues();
	}
	return ret;
}

State* 	State::moveUp(void) const {
	int32_t		rk;

	rk = std::distance(table, std::find(table, table + size, 0));
	return this->moveUp(rk);
}

State*	State::moveUp(int32_t& i) const {
	State*	ret = NULL;
	int32_t tmp;

	if (!table)
		return 0;
	if (i < size - State::edge_size) {
		ret = new State();
		*ret = *this;
		tmp = table[i + State::edge_size];
		ret->table[i + State::edge_size] = 0;
		ret->table[i] = tmp;
		ret->setParent(this);
		ret->setMovedValues();
	}
	return ret;
}

/*
 * Incremente la valeur de deplacement G, Calcule la valeur heuristique,
 * assigne le total comme il faut.
 * */
void	State::setMovedValues() {
	Manager::heuristic->setValues(*this);
	this->incrementG();
	this->setF();
}

/**
 * imprime la table
 * */
void	State::printTable(void) const {
	int 	i = -1;

	while (++i < size) {
		if (i && !(i % State::edge_size))
			std::cout << std::endl;
		std::cout << table[i] << (i % State::edge_size == State::edge_size - 1 ? "" : " ");
	}
	std::cout << std::endl;
}

void	State::printTable(const char* title) const {
	int 	i = -1;

	std::cout << title << ":" << std::endl;
	while (++i < size) {
		if (i && !(i % State::edge_size))
			std::cout << std::endl;
		std::cout << table[i] << (i % State::edge_size == State::edge_size - 1 ? "" : " ");
	}
	std::cout << std::endl;
}

void 	State::printAllInfo(void) const {
	this->printTable("------state");
	std::cout << "heur : " << this->getH() << " | mouv : " << this->getG() << \
	" | total: " << this->getF() <<	std::endl;
}

/*
 * OPERATORS
 * */
State&	State::operator=(State const &rhs) {
	size = rhs.getSize();
	parent = rhs.getParent();
	h = rhs.getH();
	g = rhs.getG();
	f = rhs.getF();
	table = new int[size];
	std::copy(rhs.getTable(),
			  rhs.getTable() + size, table);
}

bool 	State::operator>=(State const &rhs) const {
	return this->getF() >= rhs.getF();
}

bool 	State::operator>(State const &rhs) const {
	return this->getF() > rhs.getF();
}

bool 	State::operator==(State const &rhs) const {
	int32_t* table1 = rhs.getTable();
	for (int i = 0; i < size; ++i) {
		if (table[i] != table1[i])
			return false;
	}
	return true;
}

bool 	State::operator<=(State const &rhs) const {
	return this->getF() <= rhs.getF();
}

bool 	State::operator<(State const &rhs) const {
	return this->getF() < rhs.getF();
}

std::ostream &operator<<(std::ostream& os, const State &state) {
	os << "parent: " << (state.parent != nullptr ? true : false)
	   << " table: " << state.table << " h: " << state.h << " g: " << state.g
	   << " f: " << state.f;
	return os;
}

/*
 * =========================================================
 * 					PRIVATE LOGIC
 * =========================================================
 * */

void	State::parseFile(State& state, std::string& line) {
	using namespace std;
	using namespace boost;

	size_t 		pos;
	static int 	line_nb = -1;
	int 		i = -1;
	int			max_line = 0;

	if ((pos = line.find('#', 0)) != std::string::npos) {
		line = line.substr(0, pos);
		std::cout << "Nouvelle ligne sans commentaire : " << line << std::endl;
	}
	if (line.empty())
		return;
	if (line.find(' ', 0) == std::string::npos) {
		try {
			State::edge_size = std::stoi(line);
			state.size = State::edge_size * State::edge_size;
			state.table = new int[state.size];
		} catch (std::invalid_argument& ) {
			std::cout << "Invalid number" << std::endl;
		}
		return;
	}
	else {
		max_line = State::edge_size;
		if (++line_nb < max_line) {
			tokenizer<> tok(line);
			for(tokenizer<>::iterator beg = tok.begin(); beg != tok.end(); ++beg) {
				if (++i < max_line)
					state.table[i + (line_nb * 3)] = stoi(*beg);
			}
		}
	}
}

/*
 * ACCESSORS
 * */
int32_t State::getSize() const {
	return size;
}

void State::setSize(int32_t size) {
	State::size = size;
}

const State *State::getParent() const {
	return parent;
}

void State::setParent(const State *parent) {
	this->parent = parent;
}


int32_t *State::getTable() const {
	return table;
}

void State::setTable(int32_t *table) {
	State::table = table;
}

int32_t State::getH() const {
	return h;
}

void State::setH(int32_t h) {
	State::h = h;
}

int32_t State::getG() const {
	return g;
}

void State::setG(int32_t g) {
	State::g = g;
}

int32_t State::getF() const {
	return f;
}

void State::setF(int32_t f) {
	State::f = f;
}

void State::setF() {
	State::f = h + g;
}

/*
 * EXCEPTIONS
 * */


