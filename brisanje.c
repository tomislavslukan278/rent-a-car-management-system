#include "Header.h"


void brisanjeAutomobila() {

	AUTOMOBIL* car = (AUTOMOBIL*)malloc(sizeof(AUTOMOBIL));
	FILE* fp = NULL;
	FILE* fpTemp = NULL;
	int found = 0, carID = 0;
	char trash[128];

	fp = fopen("popisAutomobila.bin", "rb");
	if (fp == NULL) {
		perror("\nError");
		return;
	}

	fpTemp = fopen("tempAutomobili.bin", "wb");
	if (fpTemp == NULL) {
		perror("Greska: ");
		return;
	}

	char searchname[16];
	printf("\nUnesite registraciju automobila kojeg zelite obrisati: ");
	scanf("%15[^\n]s", searchname); gets(trash);

	while (fread(car, sizeof(AUTOMOBIL), 1, fp) != NULL) {
		if (strcmp(searchname, car->registracija) == 0) {
			found = 1;
			printf("\nAutomobil s registracijom %s je uspjesno pronadjen i obrisan!\n", searchname);
			carID = car->id;
			FILE* fpbr1 = fopen("ukupanBrAutomobila.txt", "r");
			if (fpbr1 == NULL) {
				perror("\nError");
				return;
			}
			int brojautomobila;
			fscanf(fpbr1, "%d", &brojautomobila);
			fclose(fpbr1);

			//kada se jedan auto obrise potrebno je azurirati ukupan broj automobila
			fpbr1 = fopen("ukupanBrAutomobila.txt", "w+");
			if (fpbr1 == NULL) {
				perror("\nError");
				return;
			}
			brojautomobila--;
			fprintf(fpbr1, "%d", brojautomobila);
			fclose(fpbr1);
		}
		else {
			fwrite(car, sizeof(AUTOMOBIL), 1, fpTemp);
		}
	}
	if (found == 0) {
		printf("\nAutomobil s registracijskim oznakama %s ne postoji u popisu automobila. Pokusajte ponovno.", searchname);
	}

	fclose(fp);
	fclose(fpTemp);
	free(car);

	remove("popisAutomobila.bin");
	rename("tempAutomobili.bin", "popisAutomobila.bin");


	//Popravlja situaciju ukoliko se obrisu svi auti
	fp = fopen("popisAutomobila.bin", "rb");
	if (NULL != fp) {
		fseek(fp, 0, SEEK_END);
		int size = ftell(fp);
		if (0 == size) {
			FILE* fpbr1 = fopen("ukupanBrAutomobila.txt", "w");
			fprintf(fpbr1, "%d", 0);
			fclose(fpbr1);
		}
	}
	fclose(fp);


	azuriranjeIndeksa();
	azuriranjeKorisnika(carID);
}

void brisanjeKorisnika() {

	KORISNIK* user = (KORISNIK*)malloc(sizeof(KORISNIK));
	FILE* fp = NULL;
	FILE* fpTemp = NULL;
	int found = 0;
	char trash[128];

	fp = fopen("popisKorisnika.bin", "rb");
	if (fp == NULL) {
		perror("\nError");
		return;
	}

	fpTemp = fopen("tempKorisnici.bin", "wb");
	if (fpTemp == NULL) {
		perror("Greska: ");
		return;
	}

	char searchname[16];
	printf("\nUnesite OIB korisnika kojeg zelite obrisati: ");
	scanf("%15[^\n]s", &searchname); gets(trash);

	while (fread(user, sizeof(KORISNIK), 1, fp) != NULL) {
		if (strcmp(searchname, user->oib) == 0) {
			found = 1;
			printf("\nKorisnik s ID-em %s je uspjesno pronadjen i obrisan!\n", searchname);
			FILE* fpbr1 = fopen("ukupanBrKorisnika.txt", "r");
			if (fpbr1 == NULL) {
				perror("\nError");
				return;
			}
			int brojKorisnika;
			fscanf(fpbr1, "%d", &brojKorisnika);
			fclose(fpbr1);

			//kada se jedan korisnik obrise potrebno je azurirati ukupan broj korisnika
			fpbr1 = fopen("ukupanBrKorisnika.txt", "w+");
			if (fpbr1 == NULL) {
				perror("\nError");
				return;
			}
			brojKorisnika--;
			fprintf(fpbr1, "%d", brojKorisnika);
			fclose(fpbr1);
		}
		else {
			fwrite(user, sizeof(KORISNIK), 1, fpTemp);
		}
	}
	if (found == 0) {
		printf("\nKorisnik s id-em %s ne postoji. Pokusajte ponovno.\n", searchname);
	}

	fclose(fp);
	fclose(fpTemp);
	free(user);

	remove("popisKorisnika.bin");
	rename("tempKorisnici.bin", "popisKorisnika.bin");


	//Popravlja situaciju ukoliko se obrisu svi korisnici
	fp = fopen("popisKorisnika.bin", "rb");
	if (NULL != fp) {
		fseek(fp, 0, SEEK_END);
		int size = ftell(fp);
		if (0 == size) {
			FILE* fpbr1 = fopen("ukupanBrKorisnika.txt", "w");
			fprintf(fpbr1, "%d", 0);
			fclose(fpbr1);
		}
	}
	fclose(fp);

	azuriranjeIndeksaKorisnika();

}