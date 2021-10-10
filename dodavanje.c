#include "Header.h"

void dodavanjeAutomobila() {

	int brAuto, brojac = 0;
	char trash[128];
	AUTOMOBIL* car = NULL;
	FILE* fp = NULL;


	FILE* fpbr1 = NULL;
	fpbr1 = fopen("ukupanBrAutomobila.txt", "r");
	if (fpbr1 == NULL) {
		printf("\nDatoteka za pohranjivanje ukupnog broja unesenih automobila je stvorena.\n");
		FILE* fpbr = fopen("ukupanBrAutomobila.txt", "w+");
		int s = 0;
		fprintf(fpbr, "%d", s);
		fclose(fpbr);
	}
	else {
		fscanf(fpbr1, "%d", &brojac);
		fclose(fpbr1);
	}

	printf("\n---DODAVANJE AUTOMOBILA U SUSTAV---\n");
	fp = fopen("popisAutomobila.bin", "ab+");
	if (fp == NULL) {
		perror("Otvaranje: ");
		return;
	}
	else {
		do {
			printf("\nKoliko automobila zelite dodati na popis ? ");
			scanf("%d", &brAuto);
			gets(trash);
			if (brAuto < 1 || brAuto>10);
		} while (brAuto < 1 || brAuto>10);

		car = (AUTOMOBIL*)malloc(brAuto * sizeof(AUTOMOBIL));

		for (int i = 0; i < brAuto; i++) {

			car->id = brojac + 1;

			printf("\nUnesite marku %d. automobila: ", i + 1);
			scanf("%20[^\n]s", car->marka); gets(trash);

			printf("\nUnesite naziv %d. automobila: ", i + 1);
			scanf("%20[^\n]s", car->naziv); gets(trash);

			printf("\nUnesite godinu proizvodnje %d. automobila: ", i + 1);
			scanf("%hd", &car->godinaProizvodnje); gets(trash);

			printf("\nUnesite tip mjenjaca %d. automobila (rucni/automatski): ", i + 1);
			scanf("%15[^\n]s", car->tipMjenjaca); gets(trash);

			printf("\nUnesite jacinu u KS/HP %d. automobila: ", i + 1);
			scanf("%d", &car->jacina); gets(trash);

			printf("\nUnesite boju %d. automobila: ", i + 1);
			scanf("%20[^\n]s", car->boja); gets(trash);

			printf("\nUnesite registraciju %d. automobila (npr: BM-167-BA): ", i + 1);
			scanf("%15[^\n]s", car->registracija); gets(trash);

			printf("\nUnesite cijenu/dan %d. automobila: ", i + 1);
			scanf("%f", &car->cijena); gets(trash);

			fwrite(car, sizeof(AUTOMOBIL), 1, fp);

			brojac++;
		}


	}

	fclose(fp);
	free(car);

	fpbr1 = fopen("ukupanBrAutomobila.txt", "w");
	fprintf(fpbr1, "%d", brojac);
	fclose(fpbr1);

}

void dodavanjeKorisnika() {

	int brKor, brojac = 0; char trash[128];
	KORISNIK* korisnik = NULL;
	FILE* fp = NULL;


	FILE* fpbr1 = NULL;
	fpbr1 = fopen("ukupanBrKorisnika.txt", "r");
	if (fpbr1 == NULL) {
		printf("\nDatoteka za pohranjivanje ukupnog broja unesenih korisnika je stvorena.\n");
		FILE* fpbr = fopen("ukupanBrKorisnika.txt", "w+");
		int s = 0;
		fprintf(fpbr, "%d", s);
		fclose(fpbr);
	}
	else {
		fscanf(fpbr1, "%d", &brojac);
		fclose(fpbr1);
	}

	printf("\n---NOVI ZAHTJEV ZA RENTU---\n");
	fp = fopen("popisKorisnika.bin", "ab+");
	if (fp == NULL) {
		perror("Otvaranje: ");
		return (1);
	}
	else {
		do {
			printf("\nKoliko korisnickih naloga zelite dodati na popis ? ");
			scanf("%d", &brKor); gets(trash);
			if (brKor < 1 || brKor>10);
		} while (brKor < 1 || brKor>10);

		korisnik = (KORISNIK*)malloc(brKor * sizeof(KORISNIK));

		FILE* kolicinaAuta = fopen("ukupanBrAutomobila.txt", "r");
		int maksimalniID;
		fscanf(kolicinaAuta, "%d", &maksimalniID);
		fclose(kolicinaAuta);

		int flag = 0;

		for (int i = 0; i < brKor; i++) {

			korisnik->id = brojac + 1;

			do {
				if (flag == 1) {
					printf("\nNe postoji auto koji posjeduje uneseni ID.\n");
					printf("Raspon dostupnih ID brojeva za aute je: 1 - %d\n", maksimalniID);
				}
				//potrebno zato da se ne može odabrati nepostojeci ID auta
				printf("\nUnesite ID automobila kojeg %d. korisnik zeli iznajmiti: ", i + 1);
				scanf("%d", &korisnik->odabirAutomobila); gets(trash);
				flag = 1;
			} while (maksimalniID < korisnik->odabirAutomobila || korisnik->odabirAutomobila < 1);

			printf("\nUnesite vrstu naloga %d. korisnika (pravna/fizicka) osoba: ", i + 1);
			scanf("%20[^\n]s", korisnik->vrsta); gets(trash);

			printf("\nUnesite ime %d. korisnika: ", i + 1);
			scanf("%20[^\n]s", korisnik->ime); gets(trash);

			printf("\nUnesite prezime %d. korisnika: ", i + 1);
			scanf("%20[^\n]s", korisnik->prezime); gets(trash);

			printf("\nUnesite datum rodjenja %d. korisnika: ", i + 1);
			scanf("%hd%hd%hd", &korisnik->datumRodjenja.dan, &korisnik->datumRodjenja.mjesec, &korisnik->datumRodjenja.godina); gets(trash);

			printf("\nUnesite OIB %d. korisnika: ", i + 1);
			scanf("%20[^\n]s", korisnik->oib); gets(trash);

			printf("\nUnesite adresu %d. korisnika: ", i + 1);
			scanf("%30[^\n]s", korisnik->adresa); gets(trash);

			printf("\nUnesite broj telefona %d. korisnika: ", i + 1);
			scanf("%20[^\n]s", korisnik->brojTel); gets(trash);

			printf("\nUnesite koliko dana %d. korisnik zeli unajmiti vozilo: ", i + 1);
			scanf("%d", &korisnik->daniPosudbe); gets(trash);

			printf("\nUnesite datum podnosenja zahtjeva za rentu automobila %d. korisnika: ", i + 1);
			scanf("%15[^\n]s", korisnik->pocetniDatum); gets(trash);

			printf("\nUnesite vrstu osiguranja %d. korisnika (osnovno/WUG/supercover): ", i + 1);
			scanf("%20[^\n]s", korisnik->osiguranje); gets(trash);

			printf("\nUnesite nacin placanja %d. korisnika (gotovina/kartica): ", i + 1);
			scanf("%15[^\n]s", korisnik->nacinPlacanja); gets(trash);


			fwrite(korisnik, sizeof(KORISNIK), 1, fp);

			brojac++;
		}
	}

	fclose(fp);
	free(korisnik);

	fpbr1 = fopen("ukupanBrKorisnika.txt", "w");
	fprintf(fpbr1, "%d", brojac);
	fclose(fpbr1);
}