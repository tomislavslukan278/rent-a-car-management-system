#include "Header.h"

void racun() {

	char trash[128];
	printf("\nID korisnika: ");
	int id;
	scanf("%d", &id); gets(trash);

	FILE* korisnici = fopen("popisKorisnika.bin", "rb");
	if (korisnici == NULL) {

		perror("\nError");
		return;
	}
	FILE* userAmount = fopen("ukupanBrKorisnika.txt", "r");
	if (userAmount == NULL) {
		perror("\nError");
		return;
	}
	int userCount;
	fscanf(userAmount, "%d", &userCount);
	fclose(userAmount);
	KORISNIK** userList = procitajSveKorisnike(korisnici, userCount);
	fclose(korisnici);
	

	FILE* carFile = fopen("popisAutomobila.bin", "rb");
	FILE* carAmount = fopen("ukupanBrAutomobila.txt", "r");
	if (carFile == NULL) {
		perror("\nError");
		return;
	}
	if (carAmount == NULL) {
		perror("\nError");
		return;
	}
	int carCount;
	fscanf(carAmount, "%d", &carCount);
	fclose(carAmount);
	AUTOMOBIL** carList = procitajSveAute(carFile, carCount);
	fclose(carFile); 

	for (int i = 0; i < userCount; i++) {
		if (id == userList[i]->id) {
			for (int j = 0; j < carCount; j++) {
				if (userList[i]->odabirAutomobila == carList[j]->id) {
					float cijena = userList[i]->daniPosudbe * carList[j]->cijena;
					printf("\nKorisnik je duzan platiti: HRK %.2f.\n", cijena);
				}
			}
		}
	}
	oslobodiSveAute(carList, carCount);
}