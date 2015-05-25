#include <equation.hpp>

# define A		_degre[2]
# define B		_degre[1]
# define C		_degre[0]

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

void			Equation::split() {

	bool				positive = true;
	string				tmp;
	string::iterator	it = _equation->begin();
	string::iterator	previous = it;
	string::iterator	end = _equation->end();

	while (it <= end) {
		if (*it == '+' || *it == '-' || *it == '\0') {
			tmp = _equation->substr(std::distance(_equation->begin(), previous), std::distance(previous, it - (*it == '\0' ? 0 : 1)));
			parseElem(tmp, positive);
			previous = it + 2;
			if (*it == '+')
				positive = true;
			else if (*it == '+')
				positive = false;
		}
		it++;
	}
}

void			Equation::parseElem(string & elem, bool positive) {
	if (positive)
		cout << "positif : ";
	else
		cout << "negatif : ";
	cout << elem << endl;

	//float tmp = atof(elem.c_str());
	float tmp = std::stof(elem);
	cout << tmp << endl;
	_degre[static_cast<int> (*(elem.rbegin())) - 48] += (positive ? tmp : -tmp);
	cout << _degre[static_cast<int> (*(elem.rbegin())) - 48] << endl;
}

void			Equation::showResult() {
	_delta = computeDelta();
	cout << _delta << endl;
	if (_delta < 0)
		cout << "Pas de solution." << endl;
	else if (_delta == 0.0f) {
		cout << "Une solution." << endl;
	}
	else{
		cout << "Deux solutions." << endl;
	}
}

float			Equation::computeDelta() {
	return square(B) - (4 * A * C);
}

float			Equation::square(float value) {
	return value * value;
}

//================================= ACCESSORS

std::string*	Equation::getEquation() {
	return _equation;
}

float*			Equation::getDegre() {
	return this->_degre;
}

float			Equation::getDelta() {
	return this->_delta;
}

float			Equation::getSolution() {
	return this->_solution;
}

bool			Equation::getHasSolution() {
	return this->_hasSolution;
}

void			Equation::setDegre(float zero, float one, float two) {
	_degre[0] = zero;
	_degre[1] = one;
	_degre[2] = two;
}

void			Equation::setDelta(float delta) {
	this->_delta = delta;
}

void			Equation::setSolution(float solution) {
	_solution = solution;
}

void			Equation::setHasSolution(bool bo) {
	_hasSolution = bo;
}