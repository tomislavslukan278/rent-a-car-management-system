#include "Header.h"


void prikazAutomobila() {

	int n;
	FILE* fp = NULL;
	FILE* fpbr1 = NULL;
	AUTOMOBIL* car = NULL;

	fpbr1 = fopen("ukupanBrAutomobila.txt", "r");
	if (fpbr1 == NULL) {
		perror("\nError");
		return;
	}
	fscanf(fpbr1, "%d", &n);
	fclose(fpbr1);

	fp = fopen("popisAutomobila.bin", "rb");
	if (fp == NULL) {
		fprintf(stderr, "Vrijednost pogreske je: %d.\n", errno);
		fprintf(stderr, "Pogreska: %s.\n", strerror(errno));
		return 0;
	}
	else {
		fprintf(stdout, "\nDatoteka postoji na disku.\n");

		printf("\n---POPIS AUTOMOBILA U SUSTAVU---\n");

		printf("\nUkupan broj automobila u sustavu: %d\n", n);

		car = (AUTOMOBIL*)malloc(sizeof(AUTOMOBIL));

		for (int i = 0; i <n; i++) {
			fread(car, sizeof(AUTOMOBIL), 1, fp);
			printf("\nID: %d\nMarka: %s\nNaziv: %s\nGodina proizvodnje: %2hd\nTip Mjenjaca: %s\nJacina (KS/HP): %d\nBoja: %s\nRegistracija: %s\nCijena/dan: %.2f\n\n", car->id, car->marka, car->naziv, car->godinaProizvodnje, car->tipMjenjaca, car->jacina, car->boja, car->registracija, car->cijena);
		}

		fclose(fp);
		free(car);
	}

}

void prikazKorisnika() {

	int n;
	FILE* fp = NULL;
	FILE* fpbr1 = NULL;
	KORISNIK* user = NULL;

	fpbr1 = fopen("ukupanBrKorisnika.txt", "r");
	if (fpbr1 == NULL) {
		perror("\nError");
		return;
	}
	fscanf(fpbr1, "%d", &n);
	fclose(fpbr1);


	fp = fopen("popisKorisnika.bin", "rb");
	if (fp == NULL) {
		fprintf(stderr, "Vrijednost pogreske je: %d.\n", errno);
		fprintf(stderr, "Pogreska: %s.\n", strerror(errno));
		return;
	}
	else {
		fprintf(stdout, "\nDatoteka postoji na disku.\n");

		printf("\n---POPIS ZAHTJEVA ZA RENTU---\n");
		printf("\nUkupan broj korisnika u sustavu: %d\n", n);

		user = (KORISNIK*)malloc(sizeof(KORISNIK));

		for (int i = 0; i < n; i++) {
			fread(user, sizeof(KORISNIK), 1, fp);
			printf("\nID korisnika: %d\nID automobila za rentu: %d\nPravna/fizicka osoba: %s\nime: %s\nPrezime: %s\nDatum rodjenja: %2hd.%2hd.%4hd.\nOIB: %s\nAdresa: %s\nBroj telefona: %s\nPosudba: %d dan(a)\nDatum izdavanja rente: %s\nOsiguranje: %s\nNacin placanja: %s\n\n", user->id, user->odabirAutomobila, user->vrsta, user->ime, user->prezime, user->datumRodjenja.dan, user->datumRodjenja.mjesec, user->datumRodjenja.godina, user->oib, user->adresa, user->brojTel, user->daniPosudbe, user->pocetniDatum, user->osiguranje, user->nacinPlacanja);
		}
		fclose(fp);
		free(user);
	}
}