#include "Header.h"

int main(void) {

	int n, rez;

	while (1) {

		izbornik();
		rez = unos(&n);
		switch (rez) {


		case 1:
			dodavanjeAutomobila();
			break;

		case 2:
			prikazAutomobila();
			break;

		case 3:
			pretragaAutomobila();
			break;

		case 4:
			brisanjeAutomobila();
			break;

		case 5:
			dodavanjeKorisnika();
			break;

		case 6:
			prikazKorisnika();
			break;

		case 7:
			pretragaKorisnika();
			break;

		case 8:
			brisanjeKorisnika();
			break;

		case 9:
			racun();
			break;

		case 10:
			izlaz();
			break;

		default:
			printf("Unos nije valjan, pokusajte ponovno.");
		}
	}

	return 0;
}