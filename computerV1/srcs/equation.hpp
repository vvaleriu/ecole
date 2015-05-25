#ifndef EQUATION_HPP
#define EQUATION_HPP

# include <iostream>
# include <cstddef>
# include <list>

class Equation {

public:

	// Constructors and Destructors
	Equation(char *line);
	Equation(const char *line);
	Equation(Equation const & c);
	~Equation();
	Equation & operator=(Equation const & rhs);

	// Logic
	void					reduce();
	//std::list<std::string>	split();

	// Accessors
	std::string				*getEquation();
	float					*getDegre();
	float					getDelta();
	float					getSolution();
	bool					getHasSolution();

	void					setDegre(float, float, float);
	void					setDelta(float);
	void					setSolution(float);
	void					setHasSolution(bool);

private:

	std::string*			_equation;
	float					_degre[3];
	float					_delta;
	float					_solution;
	bool					_hasSolution;

	std::list<std::string>*	elem;

	Equation();

	// Logic


};

#endif