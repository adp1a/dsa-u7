#pragma once

class Student
{
private:
	double studijniPrumer;

public:
	Student(double studijniPrumer);

	/* Metoda vrati hodnotu prumeru studenta. */
	double getPrumer() const;
};

// ---------------------------------------------------

Student::Student(double studijniPrumer)
{
	this->studijniPrumer = studijniPrumer;
}

double Student::getPrumer() const
{
	return studijniPrumer;
}