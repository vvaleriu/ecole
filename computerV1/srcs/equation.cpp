#include <equation.hpp>
#include <cstddef>

using namespace std;

Equation::Equation() {
	return;
}

Equation::~Equation() {
	if (_equation != NULL)
		delete _equation;
	return;
}

Equation::Equation(const char *line) {
	_equation = new std::string(line);
	_degre[0] = 0;
	_degre[1] = 0;
	_degre[2] = 0;
	_hasSolution = false;
	_delta = 0.0f;
	_solution = 0.0f;
	return;
}

Equation::Equation(char *line) {
	_equation = new std::string(line);
	_degre[0] = 0;
	_degre[1] = 0;
	_degre[2] = 0;
	_hasSolution = false;
	_delta = 0.0f;
	_solution = 0.0f;
	return;
}

Equation::Equation(Equation const & eq) {
		*this = eq;
}

Equation &	Equation::operator=(Equation const & rhs) {
	(void) rhs;
	return (*this);
}

//================================= LOGIC

void			Equation::reduce() {
	string::iterator	it = _equation->begin();
	string::iterator	end = _equation->end();

	while (it != end && *it != '=') {
		it++;
	}
	if (it + 3 == end) {
		string	tmp = _equation->substr(0, _equation->size() - 4);
		delete _equation;
		_equation = new string(tmp);
	}
	else {
		*it = '-';
		it++;
		while (it != end) {
			if (*it == '-')
				*it = '+';
			if (*it == '+')
				*it = '-';
			it++;
		}
	}
}

/*list<string>	Equation::split() {
	//char		clist[] = {'+', '-'};
	list<string> ret = new list<string>();

}*/


//================================= ACCESSORS

std::string* Equation::getEquation() {
	return _equation;
}

float*		Equation::getDegre() {
	return this->_degre;
}

float		Equation::getDelta() {
	return this->_delta;
}

float		Equation::getSolution() {
	return this->_solution;
}

bool		Equation::getHasSolution() {
	return this->_hasSolution;
}

void		Equation::setDegre(float zero, float one, float two) {
	_degre[0] = zero;
	_degre[1] = one;
	_degre[2] = two;
}

void		Equation::setDelta(float delta) {
	this->_delta = delta;
}

void		Equation::setSolution(float solution) {
	_solution = solution;
}

void		Equation::setHasSolution(bool bo) {
	_hasSolution = bo;
}