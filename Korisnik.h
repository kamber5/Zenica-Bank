#pragma once
#include "osoba.h"

class Korisnik : public osoba
{
private:
	std::string  zaposlenost;
	int radniStaz;
	long jmbg;
	int zeljeniKredit;
	int brojRata;
	int ukupnoZaVratiti;
	int ukupno;
	int mjesecnaRata;
	int kamatnaStopa;
	
public:
	void postaviKarta();
	void setIme();
	void setPrezime();
	void setZaposlenost();
	void setRadniStaz();
	void setJMBG();
	void setZeljeniKredit();
	void setBrojRata();
	std::string getIme();
	std::string getPrezime();
	int getJMBG();
	std::string getZaposlenost();
	int getRadniStaz();
	void pokreniProceduru();
	void prikazInformacija();
	void kalkulatorprovjera();

};

