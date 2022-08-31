#include "Korisnik.h"
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <fstream>
#include <ctime>
#include <memory>
#include <time.h> 
#include <iomanip>
#include "Funkcije.h"
void Korisnik::setIme()
{
	std::cout << "\nUnesite ime: ";
	std::cin >> ime;
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->ime.length(); i++)//provjera da li je ime bez brojeva
		{
			if (isdigit(this->ime.at(i)))
			{
				std::cout << "\nIme ne moze sadrzavati brojeve u sebi!\n";
				std::cout << "\nPonovite unos: ";
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
}

void Korisnik::setPrezime()
{
	std::cout << "Unesite prezime: ";
	std::cin >> prezime;
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->prezime.length(); i++)
		{
			if (isdigit(this->prezime.at(i)))
			{
				std::cout << "\nPrezime ne moze sadrzavati brojeve u sebi!\n";
				std::cout << "\nPonovite unos: ";
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
}

void Korisnik::setZaposlenost()
{
	std::cout << "Da li ste zaposleni? (Da/Ne) ";
	std::cin >> zaposlenost;

	if (zaposlenost == "Ne") {
	std::cout << "\n\nIzvinjavamo se ali niste kreditno sposobni\n";
	std::cout << "Neka pristupi sljedeci klijent\n";
	std::cout << "Vasa aplikacija ce se ugasiti uskoro!\n\n";
	Sleep(2000);
	std::exit(0);
	}
}

void Korisnik::setRadniStaz()
{
	std::cout << "Koliko godina radnog staza imate ? ";
	std::cin >> radniStaz;
	if (radniStaz < 2) {
		std::cout << "\n\nIzvinjavamo se ali niste kreditno sposobni da podignete kredit.\n";
		std::cout << "Hvala na razumijevanju\n";
		std::cout << "Molimo neka pristupi sljedeci klijent\n";
		std::cout << "Vasa aplikacija ce se ugasiti uskoro!\n\n";
		Sleep(2000);
		std::exit(0);
	}
}

void Korisnik::setJMBG()
{
	std::cout << "Unesite vas maticni broj: ";
	std::cin >> jmbg;
}

void Korisnik::setZeljeniKredit()
{
	std::cout << "Kreditno ste sposobni, sada unesite iznos kredita koji zelite podici: ";
	std::cin >> zeljeniKredit;
}

void Korisnik::setBrojRata()
{
	std::cout << "Unesite broj godina na koliko zelite vracati kredit: ";
	std::cin >> brojRata;
}

std::string Korisnik::getIme()
{
	return this->ime;
}

std::string Korisnik::getPrezime()
{
	return this->prezime;
}

int Korisnik::getJMBG()
{
	return this->jmbg;
}

std::string Korisnik::getZaposlenost()
{
	return this->zaposlenost;
}

int Korisnik::getRadniStaz()
{
	return this->radniStaz;
}

void Korisnik::pokreniProceduru()
{
	system("cls");
	std::ofstream blagajnik("klijenti.txt", std::ios_base::app);

	std::cout << "Sada cemo Vam postaviti par pitanja da provjerimo da li ste kreditno sposobni...\n";
	this->setIme();
	this->setPrezime();
	this->setZaposlenost();
	this->setRadniStaz();
	this->setJMBG();
	std::cout << "\n\nMolimo pricekajte par trenutaka dok provjerimo Vase podatke...\n\n";
	Sleep(1000);
	this->setZeljeniKredit();
	this->setBrojRata();

	std::cout << "\n\nMolimo pricekajte par trenutaka dok obavimo neke proracune...\n\n\n";
	Sleep(1000);

	if (zeljeniKredit <= 10000) {
		kamatnaStopa = 0.07;
	}
	else if (zeljeniKredit > 10000 && zeljeniKredit <= 30000) {
		kamatnaStopa = 0.06;
	}
	else if (zeljeniKredit > 30000 && zeljeniKredit <= 60000) {
		kamatnaStopa = 0.05;
	}
	else if (zeljeniKredit > 60000) {
		kamatnaStopa = 0.04;
	}
	ukupno = zeljeniKredit + (zeljeniKredit * 0.05 * brojRata);
	mjesecnaRata = ukupno / (brojRata * 12);

	std::cout << "Ukupno ce te vratiti: " << ukupno << "\n";
	std::cout << "Mjesecna rata je: " << mjesecnaRata << "\n\n\n ";

	std::cout << "Cestitamo, uspjesno ste podigli kredit i postali ste klijent nase banke.\n ";
	std::cout << "Hvala Vam na ukazanom povjerenju!\n";
	std::cout << "Molimo pricekajte par trenutaka da Vas vratimo na pocetnu stranicu...\n";

	time_t now=time(0);			//funkcije za racunanje vemena
    tm *ltm=localtime(&now);

	blagajnik << "Ime klijenta: " << getIme() << "\nPrezime klijenta: " << getPrezime() << "\nJMBG klijenta: " << getJMBG();
	blagajnik << "\nDa li je klijent zaposlen: " << getZaposlenost() << "\nKlijent ima " << getRadniStaz() << " godina radnog staza \n";
	blagajnik << "Datum sklopljenog ugovora:	" << ltm->tm_mday << "." << 1+ltm->tm_mon << "." << 1900+ltm->tm_year<< ".\t\t";
	blagajnik << "\nVrijeme sklopljenog ugovora: " << 1+ltm->tm_hour << ":" << 1+ltm->tm_min << ":" << 1+ltm->tm_sec << "\n";
	blagajnik << "Iznos kredita: " << zeljeniKredit << "\nKlijent ce vratiti ukupno: " << ukupno << " KM" << " na: " << brojRata << " rata";
	blagajnik << "\n";

	blagajnik.close();

	Sleep(5000);

	void IzaberiMode();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Korisnik::prikazInformacija()
{
	std::cout << "*********************************************************************************************************************\n" ;
	std::cout << "\tNasa banka Vam pruza :\n" ;
	std::cout << "\t- Potrosacki kredit.\n" ;
	std::cout << "\t- Stambeni kredit.\n" ;
	std::cout << "\tZa veci rok otplate, kamatna stopa (EKS) se povecava.\n" ;
	std::cout << "\tZa nove klijente bez naknade za obradu kredita.\n" ;
	std::cout << "\tUkoliko na vrijeme ne vratite odredjene rate kredita, taj iznos ce biti naplacen od Vasih jemaca/ziranata.\n" ;
	std::cout << "\tKamatna stopa se mijenja u zavisnosti visine iznosa, npr :\n" ;
	std::cout << "\tZa iznos manji od 10.000, kamatna stopa iznosi 0,07.\n" ;
	std::cout << "\tZa iznos veci od 10.000, a manji od 30.000 kamatna stopa iznosi 0,06. \n" ;
	std::cout << "\tZa iznos veci od 30.000 , a manji od 60.000 kamatna stopa iznosi 0,05. \n" ;
	std::cout << "\tZa iznose vece od 60.000, kamatna stopa iznosi 0,04. \n" ;
	std::cout << "\tMoguca je isplata u valutama : konvertibilna marka, euro, kuna.\n" ;
	std::cout << "\tPri podizanju potrosackog kredita ne zaboravite da ste prije potpisivanja ugovora zasticeni pravilima \n\tEU-a i da vam se njima u slucaju potrebe jamci mogucnost povlacenja iz ugovornog odnosa.\n" ;
	std::cout << "\tPo dolasku u poslovnicu, bankar ce:\n" ;
	std::cout << "\t- Ocijeniti Vasu preliminarnu mogucnosti za odobrenje kredita(procjena kreditne sposobnosti)\n" ;
	std::cout << "\t- Uruciti Informaciju o uvjetima kredita sa pratecim Otplatnim planom \n" ;
	std::cout << "\t- Uruciti popis dokumentacije koju je potrebno prikupiti za nastavak obrade kredita\n" ;
	std::cout << "\tUkoliko su Vam uvjeti kredita prihvatljivi, mozete podnijeti zahtjev za kredit.\n" ;
	std::cout << "\tPritisnite ENTER za vracanje u MENI\n" ;
	std::cout << "*********************************************************************************************************************\n" ;
	(void)getchar();
}

//Kalkulator za provjeru preko koje klijent moze provjeriti svoj zeljeni kredit
void Korisnik::kalkulatorprovjera() {
	system("cls");
	std::cout << "\t\t\t\t\t-- KALKULATOR ZA PROVJERU --\n";
	std::cout << "\nPostovani...\n";
	std::cout << "Ovdje mozete provjeriti iznos kredita sa uracunatom kamatom, prije nego ga podignete.\n";

	double ukupan, kamatnaStopa = 0, mjesecnaRata;
	double iznos;

	int godine = 0;
	char odgovor1;

	do {
		std::cout << "Unesite iznos koji zelite provjeriti : ";
		std::cin >> iznos;
		if (iznos < 0){
			kalkulatorprovjera();
			break;
		}
		std::cout << "Unesite na koliko godina zelite provjeriti iznos koji bi morali vratiti : ";
		std::cin >> godine;
		if (iznos < 10000) {
			kamatnaStopa = 0.07;
		}
		else if (iznos >= 10000 && iznos < 30000) {
			kamatnaStopa = 0.06;
		}
		else if (iznos >= 30000 && iznos < 60000) {
			kamatnaStopa = 0.05;
		}
		else if (iznos >= 60000) {
			kamatnaStopa = 0.04;
		}

		ukupan = iznos + (iznos * kamatnaStopa * godine);
		mjesecnaRata = ukupan / ((__int64)godine * 12);

		std::cout << "\nUkupan iznos koji bi morali vratiti: " << ukupan << "\n";
		std::cout << "Vasa mjeseca rata bi iznosila: " << mjesecnaRata << "\n";
		std::cout << "Da li zelite provjeriti drugi iznos ?" << "\n";
		std::cout << "[Y] za da, [N] za ne: ";
		std::cin >> odgovor1;
		system("cls");
	} while (odgovor1 == 'y' || odgovor1 == 'Y');

	void IzaberiMode();
}
