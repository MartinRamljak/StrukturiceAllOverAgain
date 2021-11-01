#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct _Element;
typedef struct _Element* Position;
typedef struct _Element
{
	int coefficient;
	int exponent;
	Position next;
} Element;

#endif // !POLYNOMIAL_H
