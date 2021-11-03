#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define MAX_LINE (1024)
#define MAX_SIZE (50)

struct _Element;
typedef struct _Element* Position;
typedef struct _Element
{
	int coefficient;
	int exponent;
	Position next;
} Element;

int FillOutFileName(char* fileName);
int ReadFile(Position head1, Position head2, char* fileName);
int ParseStringIntoList(Position head, char* buffer);
int DeleteAfter(Position previous);
int InsertAfter(Position position, Position newElement);
int InsertSorted(Position head, Position newElement);
int MergeAfter(Position position, Position newElement);
Position CreateElement(int coefficient, int exponent);
int PrintPoly(char* name, Position first);
int CreateAndInsertAfter(int coefficient, int exponent, Position position);
int AddPoly1(Position resultHead, Position head1, Position head2);
int AddPoly2(Position resultHead, Position head1, Position head2);
int MultiplyPoly(Position resultHead, Position head1, Position head2);

#endif // !POLYNOMIAL_H
