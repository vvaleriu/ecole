#include <stdio.h>
#include <equation.hpp>

using namespace std;

int		main(int ac, char **av) {

	Equation *equation;
	if (ac == 2) {
		equation = new Equation(av[1]);
		equation->reduce();
		cout << *equation->getEquation() << endl;
		delete equation;
	}
	else {
		std::cout << "Usage : computor \"equation\"" << std::endl;
	}

	return 0;
}