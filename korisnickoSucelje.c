#include "Header.h"

void izbornik() {

	printf("\n\t\tRENT-A-CAR MANAGEMENT SYSTEM");
	printf("\n\n***************************************************************");

	printf("\n\nUredite popis automobila\t\tUredite popis korisnika");
	printf("\n\n1. Dodavanje\t\t\t\t5. Dodavanje");
	printf("\n2. Prikaz\t\t\t\t6. Prikaz");
	printf("\n3. Pretraga\t\t\t\t7. Pretraga");
	printf("\n4. Brisanje\t\t\t\t8. Brisanje");
	printf("\n\n\n\t\t\t9. Racun");
	printf("\n\n\n\t\t\t10. Izlaz");
	printf("\n\n***************************************************************");

}

void izlaz() {

    int opcija;
    do {
        printf("********************************************");
        printf("\n1. Povratak u glavni izbornik\n2. Izlaz iz programa\n");
        printf("\nOdaberite broj ispred opcije: ");
        scanf("%d", &opcija);
        if (opcija < 1 || opcija>2);
    } while (opcija < 1 || opcija>2);


    switch (opcija) {

    case 1:
        return;
        break;

    case 2:
        exit(0);

    default:
        printf("\nUnos nije valjan.");
    }

}

int unos(int broj) {
	char trash[128];
	do {
		printf("\n\nUpisite broj ispred opcije koju zelite odabrati: ");
		scanf("%d", &broj);
		gets(trash);
		if (broj < 1 || broj>10);
	} while (broj < 1 || broj>10);

	return broj;
}