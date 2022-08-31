#pragma once
#include <string>
#include "Korisnik.h"
#include "osoba.h"
enum Prijava { radnik = 1, admin, vlasnik };
class Radnik : public osoba
{
private:
	Korisnik korisnik;
public:
	void setIme();
	void setPrezime();
	std::string getIme();
	std::string getPrezime();
	void prijava();
	Radnik(){};
	~Radnik(){};
};
