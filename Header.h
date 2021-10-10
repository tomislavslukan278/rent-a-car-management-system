#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct automobil {
	int id;
	char marka[21];
	char naziv[21];
	unsigned short int godinaProizvodnje;
	char tipMjenjaca[16];
	int jacina;
	char boja[21];
	char registracija[16];
	float cijena;
}AUTOMOBIL;

typedef struct datum {
	unsigned short int dan;
	unsigned short int mjesec;
	unsigned short int godina;
}DATUM;

typedef struct korisnik {
	int id;
	int odabirAutomobila;
	char vrsta[21];
	char ime[21];
	char prezime[21];
	DATUM datumRodjenja;
	char oib[20];
	char adresa[31];
	char brojTel[21];
	int daniPosudbe;
	char pocetniDatum[16];
	char osiguranje[21];
	char nacinPlacanja[16];
}KORISNIK;


void izbornik();
int unos(int);

void dodavanjeAutomobila();
void prikazAutomobila();
void pretragaAutomobila();
void brisanjeAutomobila();

void dodavanjeKorisnika();
void prikazKorisnika();
void pretragaKorisnika();
void azuriranjeIndeksa();
void brisanjeKorisnika();

void racun();

KORISNIK** procitajSveKorisnike(FILE* userFile, int userCounter);
void oslobodiSveKorisnike(KORISNIK** users, int userAmount);

AUTOMOBIL** procitajSveAute(FILE* carFile, int carAmount);
void oslobodiSveAute(AUTOMOBIL** cars, int carAmount);

void azuriranjeKorisnika(int carID);
void azuriranjeIndeksaKorisnika();

void izlaz();


#endif //HEADER_H