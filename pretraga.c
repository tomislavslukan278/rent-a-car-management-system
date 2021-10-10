#include "Header.h"

void pretragaAutomobila(){
	
	char trash[128];
	int br;
	FILE* fpbr1 = NULL;
	fpbr1 = fopen("ukupanBrAutomobila.txt", "r");
	if (fpbr1 == NULL) {
		perror("\nError");
		return;
	}
	fscanf(fpbr1, "%d", &br);
	fclose(fpbr1);

	int id;
	printf("\nUnesite ID automobila: ");
	scanf("%d", &id); gets(trash);

	AUTOMOBIL* car = NULL;
	car = (AUTOMOBIL*)malloc(sizeof(AUTOMOBIL));
	FILE* fp = NULL;
	fp = fopen("popisAutomobila.bin", "rb");
	if (fp == NULL) {
		printf("\nPopis automobila je prazan.");
	}
	else {
		int provjera = 0;
		for (int i = 0; i < br; i++) {
			fread(car, sizeof(AUTOMOBIL), 1, fp);
			if (car->id == id) {
				printf("\nID: %d\nMarka: %s\nNaziv: %s\nGodina proizvodnje: %4hd\nTip Mjenjaca: %s\nJacina (KS/HP): %d\nBoja: %s\nRegistracija: %s\nCijena/dan: %.2f\n\n", car->id, car->marka, car->naziv, car->godinaProizvodnje, car->tipMjenjaca, car->jacina, car->boja, car->registracija, car->cijena);
				provjera = 1;
			}
		}

		if (provjera != 1) {
			printf("\nAutomobil s tim ID-em ne nalazi se na popisu. Pokusajte ponovno.\n");

			fclose(fp);
			free(car);
		}
	}

}

void pretragaKorisnika() {

	char trash[128];
	int br;
	FILE* fpbr1 = NULL;
	fpbr1 = fopen("ukupanBrKorisnika.txt", "r");
	if (fpbr1 == NULL) {
		perror("\nError");
		return;
	}
	fscanf(fpbr1, "%d", &br);
	fclose(fpbr1);

	char oib[20];
	printf("\nUnesite OIB korisnika: ");
	scanf("%s", oib); gets(trash);

	KORISNIK* user = NULL;
	user = (KORISNIK*)malloc(sizeof(KORISNIK));
	FILE* fp = NULL;
	fp = fopen("popisKorisnika.bin", "rb");
	if (fp == NULL) {
		printf("\nPopis korisnika je prazan.");
	}
	else {
		int provjera = 0;
		for (int i = 0; i < br; i++) {
			fread(user, sizeof(KORISNIK), 1, fp);
			if (strcmp(user->oib, oib) == 0) {
				printf("\nID korisnika: %d\nID automobila za rentu: %d\nPravna/fizicka osoba: %s\nime: %s\nPrezime: %s\nDatum rodjenja: %2hd.%2hd.%4hd.\nOIB: %s\nAdresa: %s\nBroj telefona: %s\nPosudba: %d dan(a)\nDatum izdavanja rente: %s\nOsiguranje: %s\nNacin placanja: %s\n\n", user->id, user->odabirAutomobila, user->vrsta, user->ime, user->prezime, user->datumRodjenja.dan, user->datumRodjenja.mjesec, user->datumRodjenja.godina, user->oib, user->adresa, user->brojTel, user->daniPosudbe, user->pocetniDatum, user->osiguranje, user->nacinPlacanja);
				provjera = 1;
			}
		}

		if (provjera != 1) {
			printf("\nKorisnik s tim OIB-om ne nalazi se na popisu. Pokusajte ponovno.\n");

			fclose(fp);
			free(user);
		}
	}
}