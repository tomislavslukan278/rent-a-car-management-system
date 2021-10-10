#include"Header.h"

AUTOMOBIL** procitajSveAute(FILE* carFile, int carCounter) {

	AUTOMOBIL* helpCar = (AUTOMOBIL*)malloc(sizeof(AUTOMOBIL));

	AUTOMOBIL** carList = (AUTOMOBIL**)malloc(carCounter * sizeof(AUTOMOBIL*));
	for (int i = 0; i < carCounter; i++) {
		carList[i] = (AUTOMOBIL*)malloc(sizeof(AUTOMOBIL));
	}
	int i = 0;
	while (fread(helpCar, sizeof(AUTOMOBIL), 1, carFile) != NULL) {
		strcpy(carList[i]->boja, helpCar->boja);
		carList[i]->cijena = helpCar->cijena;
		carList[i]->godinaProizvodnje = helpCar->godinaProizvodnje;
		carList[i]->id = helpCar->id;
		carList[i]->jacina = helpCar->jacina;
		strcpy(carList[i]->naziv, helpCar->naziv);
		strcpy(carList[i]->marka, helpCar->marka);
		strcpy(carList[i]->registracija, helpCar->registracija);
		strcpy(carList[i]->tipMjenjaca, helpCar->tipMjenjaca);
		i++;
	}
	free(helpCar);
	return carList;
}

KORISNIK** procitajSveKorisnike(FILE* userFile, int userCounter) {

	KORISNIK* helpUser = (KORISNIK*)malloc(sizeof(KORISNIK));

	KORISNIK** userList = (KORISNIK**)malloc(userCounter * sizeof(KORISNIK*));
	for (int i = 0; i < userCounter; i++) {
		userList[i] = (KORISNIK*)malloc(sizeof(KORISNIK));
	}
	int i = 0;
	while (fread(helpUser, sizeof(KORISNIK), 1, userFile) != NULL) {
		strcpy(userList[i]->adresa, helpUser->adresa);
		strcpy(userList[i]->brojTel, helpUser->brojTel);
		userList[i]->daniPosudbe = helpUser->daniPosudbe;
		userList[i]->datumRodjenja = helpUser->datumRodjenja;
		userList[i]->id = helpUser->id;
		strcpy(userList[i]->ime, helpUser->ime);
		strcpy(userList[i]->nacinPlacanja, helpUser->nacinPlacanja);
		userList[i]->odabirAutomobila = helpUser->odabirAutomobila;
		strcpy(userList[i]->oib, helpUser->oib);
		strcpy(userList[i]->osiguranje, helpUser->osiguranje);
		strcpy(userList[i]->pocetniDatum, helpUser->pocetniDatum);
		strcpy(userList[i]->prezime, helpUser->prezime);
		strcpy(userList[i]->vrsta, helpUser->vrsta);
		i++;
	}
	free(helpUser);
	return userList;
}