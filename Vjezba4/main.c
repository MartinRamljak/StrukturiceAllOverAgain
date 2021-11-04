#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"


int main(int argc, char** argv)
{
	Element head1 = { .coefficient = 0, .exponent = 0, .next = NULL };
	Element head2 = { .coefficient = 0, .exponent = 0, .next = NULL };
	Element resultAdd = { .coefficient = 0, .exponent = 0, .next = NULL };
	Element resultMult = { .coefficient = 0, .exponent = 0, .next = NULL };
	char fileName[MAX_SIZE] = { 0 };

	FillOutFileName(fileName);

	if (ReadFile(&head1, &head2, fileName) == EXIT_SUCCESS)
	{
		PrintPoly("p1", head1.next);
		PrintPoly("p2", head2.next);

		AddPoly1(&resultAdd, &head1, &head2);
		MultiplyPoly(&resultMult, &head1, &head2);

		PrintPoly("pAdd", resultAdd.next);
		PrintPoly("pMult", resultMult.next);

		FreeMemory(&head1);
		FreeMemory(&head2);
		FreeMemory(&resultAdd);
		FreeMemory(&resultMult);
	}

	return EXIT_SUCCESS;
}

