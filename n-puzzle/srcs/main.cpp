#include "../headers/n_puzzle.h"
#include "./State.hpp"
#include "Manager.hpp"

using namespace std;

int main(int ac, char **av) {
	Manager		manager = Manager();
	State*		left = NULL;

	manager.init(ac, av);
	manager.compute();
    return 0;
}