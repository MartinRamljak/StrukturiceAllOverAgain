#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (50)
#define MAX_LINE (1024)

struct _Person;
typedef struct _Person* Position;
typedef struct _Person {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthYear;
	Position next;
} Person;

int PrependList(Position head, char* name, char* surname,
	int birthYear);
int PrintList(Position first);
Position CreatePerson(char* name, char* surname, int birthYear);
int InsertAfter(Position position, Position newPerson);
Position FindLast(Position head);
int AppendList(Position head, char* name, char* surname,
	int birthYear);
Position FindPerson(char* surname, Position first);
Position FindPrevious(Position head, char* surname);
int DeleteAfter(Position previous);
int DeletePerson(char* surname, Position head);

int InsertAfterPerson(char* surname, Position head, 
	char* newName, char* newSurname, int birthYear);
int InsertBeforePerson(char* surname, Position head,
	char* newName, char* newSurname, int birthYear);

int Menu(Position head);
Position InputPersonalData();

int PrintInFile(char* fileName, Position first);
int ReadFromFile(char* fileName, Position head);
int main(int argc, char** argv)
{
	Person head = { .next = NULL, .name = {0},
	.surname = {0}, .birthYear = 0 };
	Position p = &head;

	return EXIT_SUCCESS;
}

int PrependList(Position head, char* name, char* surname,
	int birthYear)
{
	Position newPerson = NULL;

	newPerson = CreatePerson(name, surname, birthYear);
	if (!newPerson)
	{
		return -1;
	}

	InsertAfter(head, newPerson);

	return EXIT_SUCCESS;
}

int PrintList(Position first)
{
	Position temp = first;

	while (temp)
	{
		printf("Name: %s, surname: %s, "
			"birth year: %d\n", temp->name, temp->surname,
			temp->birthYear);
		temp = temp->next;
	}

	return EXIT_SUCCESS;
}

Position CreatePerson(char* name, char* surname, int birthYear)
{
	Position newPerson = NULL;

	newPerson = (Position)malloc(sizeof(Person));
	if (!newPerson)
	{
		perror("Can't allocate memory!\n");
		return NULL;
	}

	strcpy(newPerson->name, name);
	strcpy(newPerson->surname, surname);
	newPerson->birthYear = birthYear;
	newPerson->next = NULL;

	return newPerson;
}

int InsertAfter(Position position, Position newPerson)
{
	newPerson->next = position->next;
	position->next = newPerson;

	return EXIT_SUCCESS;
}

Position FindLast(Position head)
{
	Position last = head;

	while (last->next)
	{
		last = last->next;
	}

	return last;
}

int AppendList(Position head, char* name, char* surname,
	int birthYear)
{
	Position newPerson = NULL;
	Position last = NULL;

	newPerson = CreatePerson(name, surname, birthYear);
	if (!newPerson)
	{
		return -1;
	}

	last = FindLast(head);
	InsertAfter(last, newPerson);

	return EXIT_SUCCESS;
}

Position FindPerson(char* surname, Position first)
{
	Position temp = first;

	while (temp)
	{
		if (strcmp(temp->surname, surname) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}

	return temp;
}

Position FindPrevious(Position head, char* surname)
{
	Position temp = head;

	while (temp->next)
	{
		if (strcmp(temp->next->surname, surname) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	
	return NULL;
}

int DeleteAfter(Position previous)
{
	Position toDelete = NULL;

	toDelete = previous->next;
	previous->next = toDelete->next;
	free(toDelete);

	return EXIT_SUCCESS;
}

int DeletePerson(char* surname, Position head)
{
	Position previous = NULL;

	previous = FindPrevious(head, surname);
	if (!previous)
	{
		return -1;
	}

	DeleteAfter(previous);

	return EXIT_SUCCESS;
}

int InsertAfterPerson(char* surname, Position head, char* newName, char* newSurname, int birthYear)
{
	Position newPerson = NULL;
	Position insertAfterMe = NULL;

	newPerson = CreatePerson(newName, newSurname, birthYear);
	if (!newPerson)
	{
		return -1;
	}

	insertAfterMe = FindPerson(surname, head->next);
	if (!insertAfterMe)
	{
		return -1;
	}

	InsertAfter(insertAfterMe, newPerson);

	return EXIT_SUCCESS;
}

int InsertBeforePerson(char* surname, Position head,
	char* newName, char* newSurname, int birthYear)
{
	Position newPerson = NULL;
	Position previous = NULL;

	newPerson = CreatePerson(newName, newSurname, birthYear);
	if (!newPerson)
	{
		return -1;
	}

	previous = FindPrevious(head, surname);
	if (!previous)
	{
		return -1;
	}

	InsertAfter(previous, newPerson);

	return EXIT_SUCCESS;
}

int Menu(Position head)
{
	char choice = '\0';
	while (1) {
		printf("Enter A(prepend list), B(append list), C(insert after person), D(insert before person),"
			"P(print list), S(search), D(delete by surname), X(exit)\n");
		scanf(" %c", &choice);
		if (choice == 'A')
			Prependlist(head);
		else if (choice == 'e')
			addtoendoflist(head);
		else if (choice == 'p')
			printlist(head->next);
		else if (choice == 's')
		{
			while (findperson(head) == -1)
			{
				FindPerson(head);
			}
		}
		else if (choice == 'd')
		{
			while (deleteperson(head) == -1)
			{
				DeletePerson(head);
			}
		}
		else if (choice == 'x')
			break;
		else
			perror("Wrong letter!\n");
	}
	return EXIT_SUCCESS;
}

Position InputPersonalData()
{

}

int PrintInFile(char* fileName, Position first)
{
	FILE* file = NULL;
	Position temp = first;

	file = fopen(fileName, "w");
	if (!file)
	{
		perror("Can't open file!\n");
			return -1;
	}

	while (temp)
	{
		fprintf(file, "Name: %s, surname: %s, "
			"birth year: %d\n", temp->name, temp->surname,
			temp->birthYear);
		temp = temp->next;
	}

	fclose(file);

	return EXIT_SUCCESS;
}

int ReadFromFile(char* fileName, Position head)
{
	FILE* file = NULL;
	char buffer[MAX_LINE] = { 0 };
	char name[MAX_SIZE] = { 0 };
	char surname[MAX_SIZE] = { 0 };
	int birthYear = 0;

	file = fopen(fileName, "r");
	if (!file)
	{
		perror("Can't open file!\n");
		return -1;
	}
	while (!feof(file))
	{
		fgets(buffer, MAX_LINE, file);
		if (sscanf(buffer, " %s %s %d\n", name, surname, &birthYear) == 3)
		{
			PrependList(head, name, surname, birthYear);
		}
	}

	fclose(file);
}