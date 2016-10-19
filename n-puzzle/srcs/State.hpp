//
// Created by vincent on 30/07/16.
//

#ifndef N_PUZZLE_STATE_H
#define N_PUZZLE_STATE_H

#include <ostream>
#include <array>

# include "../headers/n_puzzle.h"

/**
 * Represente un etat du jeu a un moment donne. Contient le nombre de coups
 * precedents, un etat de la table, les differentes valeurs et couts (mouvement,
 * heuristique, etc).
 * */
class State {
public:
	static int32_t	edge_size; // Taille d'un cote du carre de jeu.

	State();
	State(uint32_t size);
	State(std::string& filename);
	virtual ~State();
	int*	getFinal(State& initial);
	void 	incrementG(void);

	// Mouvement
	State* 	moveLeft(int32_t& i) const;
	State* 	moveLeft(void) const;
	State* 	moveRight(int32_t& i) const;
	State* 	moveRight(void) const;
	State* 	moveUp(int32_t& i) const;
	State* 	moveUp(void) const;
	State* 	moveDown(int32_t& i) const;
	State* 	moveDown(void) const;
	void 	printTable(void) const;
	void 	printTable(const char* title) const;
	void 	printAllInfo(void) const;

	// OPERATORS
	State&	operator=(State const &rhs);
	bool	operator>=(State const &rhs) const;
	bool	operator>(State const &rhs) const;
	bool	operator==(State const &rhs) const;
	bool	operator<=(State const &rhs) const;
	bool	operator<(State const &rhs) const;
	friend std::ostream&	operator<<(std::ostream &os, const State &state);

	// ACCESSORS
	int32_t					getSize() const;
	const State*			getParent() const;
	int32_t*				getTable() const;
	int32_t					getH() const;
	int32_t					getG() const;
	int32_t					getF() const;
	void					setSize(int32_t size);
	void					setParent(const State *parent);
	void					setTable(int32_t *table);
	void					setH(int32_t h);
	void					setG(int32_t g);
	void					setF(int32_t f);
	void					setF();

protected:
	class StateException : public std::exception {
		StateException();
		~StateException();
	};

private:
	int32_t 		size = 0;
	const State		*parent = NULL;
	int32_t			turn_nb = 0;
	int32_t 		*table = NULL;
	int32_t 		h = 0; // Heuristic value
	int32_t 		g = 0; // Mouvement cost
	int32_t 		f = 0; // h + g

	void	parseFile(State& state, std::string& line);
	void 	setMovedValues();
};

#endif //N_PUZZLE_STATE_H
