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
			else if (*it == '-')
				positive = false;
		}
		it++;
	}
}

void			Equation::parseElem(string & elem, bool positive) {
	float tmp = std::stof(elem);
	_degre[static_cast<int> (*(elem.rbegin())) - 48] += (positive ? tmp : -tmp);
}

void			Equation::solve() {
	int 	deg = returnDegre();

	printReduced();
	printDegre();
	if (deg == 2)
		solveDeg2();
	else if (deg == 1)
		solveDeg1();
	else
		solveDeg0();
}

void			Equation::printReduced() const {
	if (A != 0.0f)
		cout << A << " * X^2";
	if (B != 0.0f) {
		if (A != 0.0f)
			cout << " ";
		if (B < 0.0f)
			cout << "- " << -B << " * X^1";
		 if (B > 0.0f)
			cout << "+ " << B << " * X^1";
	}
	if (C != 0.0f) {
		if (A != 0.0f || B != 0.0f)
			cout << " ";
		if (C < 0.0f)
			cout << "- " << -C << " * X^0";
		 if (C > 0.0f)
			cout << "+ " << C << " * X^0";
	}
	cout << " = 0" << endl;
}

void			Equation::printDegre() const {
	if (A != 0.0f)
		cout << "Polynome de degre 2." << endl;
	else if (B != 0.0f)
		cout << "Polynome de degre 1." << endl;
	else if (C != 0.0f)
		cout << "Polynome sans degre." << endl;
}

void			Equation::solveDeg2() {
	_delta = computeDelta();
	displayABC();
	if (_delta < 0.0f)
		cout << "Cette equation n'a pas de solution reelle.";
	else if (_delta == 0.0f)
		cout << "La solution est : " << B << "/" <<  2 * A << endl;
	else {
		cout << "Les solutions sont :" << endl << "(" << -B << " - " << this->sqrt(_delta) << ") / " <<  2 * A << endl \
		<< "(" << -B << " + " << this->sqrt(_delta) << ") / " <<  2 * A << endl;
	}
}

void			Equation::solveDeg1() const {
	displayABC1();
	if (C != 0.0f)
		cout << "La solution est : " << -C << "/" << B << "." << endl;
	if (C == 0.0f)
		cout << "La solution est : " << 0 << "." << endl;
}

void			Equation::solveDeg0() const {
	displayABC();
	if (C == 0.0f)
		cout << "Tous les nombres reels sont solutions de cette equation." << endl;
	else
		cout << "Celle equation n'a pas de solution." << endl;
}

int			Equation::returnDegre() const {
	if (A != 0.0f)
		return 2;
	else if (B != 0.0f)
		return 1;
	else
		return 0;
}

float		Equation::sqrt(float num) const {
	float fa;
	float fb;
	float fm;
	float fn;

	if(num == 0.0) {
    	return 0.0;
	}
	else {
		fm = 1.0;
		fn = num;
		while(fn >= 2.0) {
			fn = 0.25 * fn;
			fm = 2.0 * fm;
    	}
     	while(fn<0.5) {
			fn = 4.0 * fn;
			fm = 0.5 * fm;
    	}
    	fa = fn;
    	fb = 1.0 - fn;
    	do {
			fa = fa * (1.0 + 0.5 * fb);
			fb = 0.25 * (3.0 + fb) * fb * fb;
		}
		while(fb >= 1.0E-15);
		return fa * fm;
	}
}

float			Equation::computeDelta() const {
	return square(B) - (4 * A * C);
}

float			Equation::square(float value) const {
	return value * value;
}

void			Equation::displayABC() const {
	cout << "A = " << A << ", B = " << B << ", C = " << C << " | delta = " << _delta << endl;
}

void			Equation::displayABC1() const {
	cout << "A = " << A << ", B = " << B << ", C = " << C << "." << endl;
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