#include "Radnik.h"
#include <iostream>
#include<fstream>
#include <ctime>
#include <iomanip>
#include <vector>
using std::cout;
using std::cin;

void Radnik::setIme()
{
	cout << "\n\tUnesite ime: ";
	std::cin >> ime;
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->ime.length(); i++)//provjera da li je ime bez brojeva
		{
			if (isdigit(this->ime.at(i)))
			{
				std::cout << "\n\tIme ne moze imati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->ime);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->ime.length(); i++)//postavljanje da je uvijek pocetno slovo veliko
	{
		if (i == 0)
		{
			if (this->ime.at(i) >= 97 && this->ime.at(i) <= 122)
			{
				this->ime.at(i) = this->ime.at(i) - 32;
			}
		}
		else
		{
			if (this->ime.at(i) >= 65 && this->ime.at(i) <= 90)
			{
				this->ime.at(i) = this->ime.at(i) + 32;
			}
		}

	}
	cin.ignore();
}

void Radnik::setPrezime()
{
	cout << "\n\tUnesite prezime: ";
	std::cin >> prezime;
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->prezime.length(); i++)
		{
			if (isdigit(this->prezime.at(i)))
			{
				std::cout << "\n\tPrezime ne moze imati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->prezime);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->prezime.length(); i++)
	{
		if (i == 0)
		{
			if (this->prezime.at(i) >= 97 && this->prezime.at(i) <= 122)
			{
				this->prezime.at(i) = this->prezime.at(i) - 32;
			}
		}
		else
		{
			if (this->prezime.at(i) >= 65 && this->prezime.at(i) <= 90)
			{
				this->prezime.at(i) = this->prezime.at(i) + 32;
			}
		}

	}
	cin.ignore();
}

std::string Radnik::getIme()
{
	return this->ime;
}

std::string Radnik::getPrezime()
{
	return this->prezime;
}

void Radnik::prijava()
{
	system("cls");
	std::ofstream radnik("radnici.txt", std::ios_base::app);

	cout << "\n\t\tPODACI O RADNIKU\n";
	this->setIme();
	this->setPrezime();
	cout << "\nPodaci su uspjesno uneseni!";
	cout << "\nPricekajte malo!";

	time_t now=time(0);			//funkcije za racunanje vemena
    tm *ltm=localtime(&now);

	radnik << "Ime radnika: " << getIme() << "\nPrezime radnika: " << getPrezime();
	radnik << "\nDatum prijave:	" << ltm->tm_mday << "." << 1+ltm->tm_mon << "." << 1900+ltm->tm_year<< ".\t\t";
	radnik << "\nVrijeme prijave: " << 1+ltm->tm_hour << ":" << 1+ltm->tm_min << ":" << 1+ltm->tm_sec << "\n\n";

	radnik.close();
	Sleep(2000);

}