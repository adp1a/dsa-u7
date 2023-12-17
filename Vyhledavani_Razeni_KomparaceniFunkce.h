#pragma once
#include "Sort.h"
#include "Student.h"
#include <iostream>
using namespace std;

/*
 * Find_interpolation : interpolacni vyhledavani
 * Params:
 *	p - pole hodnot
 *	l - dolni mez intervalu hledani
 *	r - horni mez intervalu hledani
 *	x0 - dolni mez hledane hodnoty
 *	x1 - horni mez hledane hodnoty
 *	value - hledana hodnota
 */
int Find_interpolation(char p[], int l, int r, char x0, char x1, char value);

/* realiazace interpolacniho hledani */
void Find_Char();

/* realizace razeni pole uk int */
void Sort_ukInt();

/* realizace razeni pole uk student */
void Sort_ukStudent();

// ------------------------------------------------------------------------------------

int Find_interpolation(char p[], int l, int r, char x0, char x1, char value)
{
	if (l > r)
		return -1;

	int kde = l + (value - x0) * (r - l) / (x1 - x0);

	if (p[kde] == value) {
		return kde;
	}
	else {
		for (int i = kde + 1; i <= r; ++i) {
			if (p[i] == value)
				return i;
		}
		return -1;
	}
}

void Find_Char()
{
	const int N = 14;
	char pismena[] = { 'A', 'C', 'D', 'E', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'P', 'Y' };
	
	const char z1 = 'P', z2 = 'D';
	int kde1, kde2;

	kde1 = Find_interpolation(pismena, 0, N - 1, 'A', 'Z', z1);
	cout << z1 << " is " << "[" << kde1 << "]" << endl;

	kde2 = Find_interpolation(pismena, 0, N - 1, 'A', 'Z', z2);
	cout << z2 << " is " << "[" << kde2 << "]" << endl;
}

bool vetsi_int(int* a, int* b)
{
	return *a > *b;
}

void Sort_ukInt()
{
	const int N = 10;
	int *cisla[10] = { new int(10), new int(25), new int(5), new int(14), new int(8), new int(1), new int(-5), new int(3), new int(15), new int(10) };

	Sort<int, vetsi_int>::SelectionSort(cisla, N);

	cout << "sort int: ";
	for (int i = 0; i < N; i++)
		cout << *cisla[i] << "; ";
	cout << endl;
}

bool horsi(Student* st1, Student* st2)
{
	return st1->getPrumer() > st2->getPrumer();
}

void Sort_ukStudent()
{
	const int numOfStud = 5;
	Student* trida[numOfStud] = { new Student(5.0), new Student(3.5), new Student(1.25), new Student(4.5), new Student(1.0) };
	Sort<Student, horsi>::SelectionSort(trida, numOfStud);

	cout << "Serazeni studenti: ";
	for (int i = 0; i < numOfStud; i++)
		cout << trida[i]->getPrumer() << "; ";
	cout << endl;

	for (int i = 0; i < numOfStud; i++)
		delete trida[i];
}