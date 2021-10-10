#include "Header.h"

void oslobodiSveAute(AUTOMOBIL** cars, int carAmount) {
	for (int i = 0; i < carAmount; i++) {
		free(cars[i]);
	}
	free(cars);
}

void oslobodiSveKorisnike(KORISNIK** users, int userAmount) {
	for (int i = 0; i < userAmount; i++) {
		free(users[i]);
	}
	free(users);
}