#include <stdio.h>

int		main(int ac, char **av) {
	if (ac == 2) {
		printf("salut les loulous : %s", av[1]);
	}
	else {
		printf("salut le loulou");
	}
	return 0;
}
