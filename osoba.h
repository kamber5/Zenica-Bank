#pragma once
#include<iostream>
#include <string>

class osoba {
public:
	std::string ime, prezime;

public:
	//definisanje virtualnih funkcija
	virtual void setIme() = 0;
	virtual void setPrezime() = 0;
	virtual std::string getIme() {return ime;}
	virtual std::string getPrezime() { return prezime; }
};
