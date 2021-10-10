#include "Header.h"

void azuriranjeIndeksa() {

	FILE* carFile = fopen("popisAutomobila.bin", "rb");
	FILE* carAmount = fopen("ukupanBrAutomobila.txt", "r");
	if (carFile == NULL) {
		perror("\nError: ");
		return;
	}
	if (carAmount == NULL) {
		perror("\nError: ");
		return;
	}
	int carCounter = 0;
	fscanf(carAmount, "%d", &carCounter);
	AUTOMOBIL** carList = procitajSveAute(carFile, carCounter);
	fclose(carFile); fclose(carAmount);
	
	carFile = fopen("popisAutomobila.bin", "wb+");
	for (int i = 0; i < carCounter; i++) {
		carList[i]->id = i + 1;
		fwrite(carList[i], sizeof(AUTOMOBIL), 1, carFile);
	}
	fclose(carFile);

	oslobodiSveAute(carList, carCounter);
}

void azuriranjeIndeksaKorisnika() {
	int userCounter = 0;
	FILE* userFile = fopen("popisKorisnika.bin", "rb");
	FILE* userAmount = fopen("ukupanBrKorisnika.txt", "r");

	KORISNIK* helpUser = (KORISNIK*)malloc(sizeof(KORISNIK));
	fscanf(userAmount, "%d", &userCounter);


	KORISNIK** userList = procitajSveKorisnike(userFile, userCounter);
	fclose(userAmount);
	fclose(userFile);

	userFile = fopen("popisKorisnika.bin", "wb+");
	for (int i = 0; i < userCounter; i++) {
		userList[i]->id = i + 1;
		fwrite(userList[i], sizeof(KORISNIK), 1, userFile);
	}
	fclose(userFile);
}

void azuriranjeKorisnika(int carID) {

	int userAmount;
	FILE* korisnici = fopen("popisKorisnika.bin", "rb");
	if (korisnici == NULL) {
		perror("\nError: ");
		return;
	}
	FILE* userAmountFile = fopen("ukupanBrKorisnika.txt", "r");
	if (userAmountFile == NULL) {
		perror("\nError: ");
		return;
	}
	fscanf(userAmountFile, "%d", &userAmount);
	fclose(userAmountFile);
	KORISNIK** users = procitajSveKorisnike(korisnici, userAmount);
	fclose(korisnici);

	for (int i = 0; i < userAmount; i++) {
		if (users[i]->odabirAutomobila == carID) {
			users[i]->odabirAutomobila = 0;
		}
	}
	korisnici = fopen("popisKorisnika.bin", "wb");
	if (korisnici == NULL) {
		perror("\nError: ");
		return;
	}
	for (int i = 0; i < userAmount; i++) {
		fwrite(users[i], sizeof(KORISNIK), 1, korisnici);
	}
	fclose(korisnici);


	oslobodiSveKorisnike(users, userAmount);
}