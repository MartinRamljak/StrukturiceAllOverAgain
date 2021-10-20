#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _osoba* pozicija;
typedef struct _osoba 
{
	char ime[20];
	char prezime[20];
	int godinaRodenja;
	pozicija next;
} osoba;

int DodajNaPocetak(pozicija head);
int DodajNaKraj(pozicija head);
int Ispis(pozicija prvi);
int PronadiOsobu(pozicija head);
int IzbrisiOsobu(pozicija head);
int main()
{
	osoba Head;
	Head.next = NULL;
	int broj = 0;
	int uspjesnostFunkcije = 0;

	for (broj; broj < 1; broj++)
	{
		DodajNaKraj(&Head);
		DodajNaPocetak(&Head);
	}
	Ispis(Head.next);
	IzbrisiOsobu(&Head);
	Ispis(Head.next);
	while (PronadiOsobu(&Head) == -1)
		PronadiOsobu(&Head);

	return 0;
}

int DodajNaPocetak(pozicija head)
{
	pozicija novi = NULL;

	novi = (pozicija)malloc(sizeof(osoba));
	if (!novi)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return -1;
	}

	printf("Unesi ime nove osobe: \n");
	scanf(" %s", novi->ime);
	printf("Unesi prezime nove osobe: \n");
	scanf(" %s", novi->prezime);
	printf("Unesi godinu rodenja nove osobe: \n");
	scanf("%d", &novi->godinaRodenja);

	novi->next = head->next;
	head->next = novi;

	return 0;
}

int DodajNaKraj(pozicija head)
{
	while (head->next != NULL)
		head = head->next;

	pozicija novi = NULL;

	novi = (pozicija)malloc(sizeof(osoba));
	if (!novi)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return -1;
	}

	printf("Unesi ime nove osobe: \n");
	scanf(" %s", novi->ime);
	printf("Unesi prezime nove osobe: \n");
	scanf(" %s", novi->prezime);
	printf("Unesi godinu rodenja nove osobe: \n");
	scanf("%d", &novi->godinaRodenja);

	

	novi->next = head->next;
	head->next = novi;

	return 0;
}

int Ispis(pozicija prvi)
{
		while (prvi)
		{
			printf("Ime osobe: %s\t Prezime osobe: %s\t Godina rodenja: %d\t\n", prvi->ime, prvi->prezime, prvi->godinaRodenja);
			prvi = prvi->next;
		}

	return 0;
}

int PronadiOsobu(pozicija head)
{
	char prezime[20] = { 0 };

	printf("Unesi prezime osobe koju zelis pronaci:\n");
	scanf(" %s", prezime);

	while (head->next && strcmp(head->next->prezime, prezime) != 0)
		head = head->next;
	if (head->next)
		printf("Osoba je: %s, a njezina adresa je: %p\n", head->next->ime, head->next);
	else
	{
		printf("Ne postoji osoba pod tim prezimenom!\n");
		return -1;
	}

		return 0;
}
int IzbrisiOsobu(pozicija head)
{
	char prezime[20] = { 0 };
	pozicija prethodni = NULL;

	printf("Unesi prezime osobe koju zelis izbrisati:\n");
	scanf(" %s", prezime);

	while (head->next && strcmp(head->prezime, prezime) != 0)
	{
		prethodni = head;
		head = head->next;
	}
	if (prethodni->next && strcmp(head->prezime, prezime) == 0)
	{
		printf("Osoba je: %s, a njezina adresa je: %p i sad je brisemo!\n", head->ime, head);
		prethodni->next = head->next;
		free(head);
	}
	else
	{
		printf("Ne postoji osoba pod tim prezimenom!\n");
		return -1;
	}

	return 0;
}