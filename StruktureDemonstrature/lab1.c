//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE (128)
//#define MAX_LINE (1024)
//#define MAX_BODOVI (15)
//
//typedef struct _student 
//{
//	char ime[MAX_SIZE];
//	char prezime[MAX_SIZE];
//	double bodovi;
//} student;
//
//int ProcitajBrojRedakaUDatoteci(char* nazivDatoteke);
//student* AlocirajMemorijuIProcitajStudente(char* nazivDatoteke, int brojStudenata);
//double IzracunajRelativniBrojBodova(double bodovi);
//int IspisStudenata(int brojStudenata, student* studenti);
//
//int main()
//{
//	char nazivDatoteke[MAX_SIZE] = { 0 };
//	int brojRedaka = 0;
//	student* studenti = NULL;
//
//	printf("Unesi naziv datoteke iz koje ucitavas studente: \n");
//	scanf(" %s", nazivDatoteke);
//
//	brojRedaka = ProcitajBrojRedakaUDatoteci(nazivDatoteke);
//	if (brojRedaka > 0)
//	{
//		studenti = AlocirajMemorijuIProcitajStudente(nazivDatoteke, brojRedaka);
//		IspisStudenata(brojRedaka, studenti);
//
//		free(studenti);
//	}
//
//	return 0;
//}
//
//int ProcitajBrojRedakaUDatoteci(char* nazivDatoteke)
//{
//	int brojac = 0;
//	FILE* datoteka = NULL;
//	char buffer[MAX_SIZE] = { 0 };
//
//	datoteka = fopen(nazivDatoteke, "r");
//	if (!datoteka)
//	{
//		printf("Neuspjesno otvaranje datoteke!\n");
//		return -1;
//	}
//	while (!feof(datoteka))
//	{
//		fgets(buffer, MAX_SIZE, datoteka);
//		brojac++;
//	}
//
//	fclose(datoteka);
//	
//	return brojac;
//}
//
//student* AlocirajMemorijuIProcitajStudente(char* nazivDatoteke, int brojStudenata)
//{
//	int brojac = 0;
//	FILE* datoteka = NULL;
//	student* studenti = NULL;
//
//	studenti = (student*)malloc(brojStudenata * sizeof(student));
//	if (!studenti)
//	{
//		printf("Neuspjesna alokacija memorije!\n");
//		return NULL;
//	}
//
//	datoteka = fopen(nazivDatoteke, "r");
//	if (!datoteka)
//	{
//		printf("Neuspjesno otvaranje datoteke!\n");
//		return NULL;
//	}
//	while (!feof(datoteka))
//	{
//		fscanf(datoteka, " %s %s %lf", studenti[brojac].ime, studenti[brojac].prezime, &studenti[brojac].bodovi);
//		brojac++;
//	}
//
//	fclose(datoteka);
//
//	return studenti;
//}
//
//double IzracunajRelativniBrojBodova(double bodovi)
//{
//	return ((bodovi / MAX_BODOVI) * 100);
//}
//
//int IspisStudenata(int brojStudenata, student* studenti)
//{
//	int brojac = 0;
//
//	for (brojac; brojac < brojStudenata; brojac++)
//	{
//		printf("Ime: %s\t Prezime: %s\t Apsolutni bodovi: %lf\t Relativni bodovi: %lf\t\n", studenti[brojac].ime, 
//			studenti[brojac].prezime, studenti[brojac].bodovi, IzracunajRelativniBrojBodova(studenti[brojac].bodovi));
//	}
//
//	return 0;
//}