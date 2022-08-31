#pragma once
#include <iostream>
#include "Korisnik.cpp" 
#include "Radnik.cpp"
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

Korisnik p;
Radnik r;

void IzaberiMode();
void menuP();
void menuR();
void load();
void gotoxy();

void menuR() {//menu za radnika na aerodromu
	system("cls");
	string MeniRadnik[2] = { "\n\t1. Prijava na posao", "\n\t0. Izlaz" };
	int pointer = 0;
	bool MeniProvjera = true;

	while (MeniProvjera)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t\t       ::::::::: :::::::::: ::::    ::: ::::::::::: ::::::::      :::  \n";
		cout << "\t\t           :+:  :+:        :+:+:   :+:     :+:    :+:    :+:   :+: :+: \n";
		cout << "\t\t         +:+   +:+        :+:+:+  +:+     +:+    +:+         +:+   +:+ \n";
		cout << "\t\t       +#+    +#++:++#   +#+ +:+ +#+     +#+    +#+        +#++:++#++: \n";
		cout << "\t\t     +#+     +#+        +#+  +#+#+#     +#+    +#+        +#+     +#+  \n";
		cout << "\t\t   #+#      #+#        #+#   #+#+#     #+#    #+#    #+# #+#     #+#   \n";
		cout << "\t\t ######### ########## ###    #### ########### ########  ###     ###    \n";
		cout << "\t\t                :::::::::      :::     ::::    ::: :::    ::: \n";
		cout << "\t\t               :+:    :+:   :+: :+:   :+:+:   :+: :+:   :+:   \n";
		cout << "\t\t              +:+    +:+  +:+   +:+  :+:+:+  +:+ +:+  +:+     \n";
		cout << "\t\t             +#++:++#+  +#++:++#++: +#+ +:+ +#+ +#++:++       \n";
		cout << "\t\t            +#+    +#+ +#+     +#+ +#+  +#+#+# +#+  +#+       \n";
		cout << "\t\t           #+#    #+# #+#     #+# #+#   #+#+# #+#   #+#       \n";
		cout << "\t\t          #########  ###     ### ###    #### ###    ###    \n\n";
		cout << "\n\n\t\t\tMENU RADNIK\n\n";
		for (int i = 0; i < 2; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << MeniRadnik[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << MeniRadnik[i] << endl;
			}
		}

		while (MeniProvjera)
		{
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				pointer = pointer - 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				pointer += 1;
				if (pointer == 2)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) & 1)
			{
				switch (pointer)
				{
				case 0:
					system("cls");
					r.prijava();
					MeniProvjera = false;
					menuR();
					break;
				case 1:
					system("cls");
					std::cout << "\n\n\n\t\tHvala Vam za koristenje nase aplikacije.\n\n";
					system("pause");
					MeniProvjera = false;
					Sleep(3000);
					std::exit(0);
				default:
					std::cout << "Greska!";
				}
			}
		}
		Sleep(1000);
	}
	cin.ignore();
}

void menuP() {//menu za korisnika
	system("cls");
	string Meni[4] = { "\n\t1. Informacije","\n\t2. Podizanje kredita" ,
						"\n\t3. Kalkulator","\n\t0. Izlaz"};
	int pointer = 0;
	bool MeniProvjera = true;

	while (MeniProvjera)
	{
		load();
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t\t       ::::::::: :::::::::: ::::    ::: ::::::::::: ::::::::      :::  \n";
		cout << "\t\t           :+:  :+:        :+:+:   :+:     :+:    :+:    :+:   :+: :+: \n";
		cout << "\t\t         +:+   +:+        :+:+:+  +:+     +:+    +:+         +:+   +:+ \n";
		cout << "\t\t       +#+    +#++:++#   +#+ +:+ +#+     +#+    +#+        +#++:++#++: \n";
		cout << "\t\t     +#+     +#+        +#+  +#+#+#     +#+    +#+        +#+     +#+  \n";
		cout << "\t\t   #+#      #+#        #+#   #+#+#     #+#    #+#    #+# #+#     #+#   \n";
		cout << "\t\t ######### ########## ###    #### ########### ########  ###     ###    \n";
		cout << "\t\t                :::::::::      :::     ::::    ::: :::    ::: \n";
		cout << "\t\t               :+:    :+:   :+: :+:   :+:+:   :+: :+:   :+:   \n";
		cout << "\t\t              +:+    +:+  +:+   +:+  :+:+:+  +:+ +:+  +:+     \n";
		cout << "\t\t             +#++:++#+  +#++:++#++: +#+ +:+ +#+ +#++:++       \n";
		cout << "\t\t            +#+    +#+ +#+     +#+ +#+  +#+#+# +#+  +#+       \n";
		cout << "\t\t           #+#    #+# #+#     #+# #+#   #+#+# #+#   #+#       \n";
		cout << "\t\t          #########  ###     ### ###    #### ###    ###    \n\n";
		cout << "\n\n\t\t\tMENU KORISNIK\n\n";
		for (int i = 0; i < 4; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Meni[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Meni[i] << endl;
			}
		}
	
	while (MeniProvjera)
	{
		if (GetAsyncKeyState(VK_UP) & 1)
		{
			pointer = pointer - 1;
			if (pointer == -1)
			{
				pointer = 2;
			}
			break;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 1)
		{
			pointer += 1;
			if (pointer == 5)
			{
				pointer = 0;
			}
			break;
		}
		else if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			try{
				switch (pointer)
				{
					case 0:
						system("cls");
						MeniProvjera = false;
						p.prikazInformacija();
						Sleep(1000);
						menuP();
						Sleep(1000);
						break;
			
					case 1:
						system("cls");
						MeniProvjera = false;
						p.pokreniProceduru();
						menuP();
						Sleep(1000);
						break;
					case 2:
						system("cls");
						MeniProvjera = false;
						p.kalkulatorprovjera();
						Sleep(1000);
						break;
					case 3:
						system("cls");
						std::cout << "\n\n\n\t\tHvala Vam za koristenje nase aplikacije.\n\n";
						system("pause");
						Sleep(1000);
						MeniProvjera = false;
						Sleep(3000);
						std::exit(0);
					default:
						std::cout << "Greska!";
					}
				if(pointer<0 || pointer>3){
					throw(pointer);
				}
			}
			catch(int pointer)
			{
				std::cout<<pointer<<" nije u rasponu, trebate unijeti broj izmedju 1 i 3\n";
			}
		  }
		}
		Sleep(1000);
	}
}

void IzaberiMode()
{
	system("cls");
	string MeniOdabir[3] = { "\n\n\t\t\t1. Korisnik","\n\t\t\t2. Radnik", "\n\t\t\t3. IZLAZ" };
	int pointer = 0;
	bool MeniProvjera = true;
	int sifra;
	int brojac=0;
	while (MeniProvjera)
	{
		system("cls");
		cout << "\t\t       ::::::::: :::::::::: ::::    ::: ::::::::::: ::::::::      :::  \n";
		cout << "\t\t           :+:  :+:        :+:+:   :+:     :+:    :+:    :+:   :+: :+: \n";
		cout << "\t\t         +:+   +:+        :+:+:+  +:+     +:+    +:+         +:+   +:+ \n";
		cout << "\t\t       +#+    +#++:++#   +#+ +:+ +#+     +#+    +#+        +#++:++#++: \n";
		cout << "\t\t     +#+     +#+        +#+  +#+#+#     +#+    +#+        +#+     +#+  \n";
		cout << "\t\t   #+#      #+#        #+#   #+#+#     #+#    #+#    #+# #+#     #+#   \n";
		cout << "\t\t ######### ########## ###    #### ########### ########  ###     ###    \n";
		cout << "\t\t                :::::::::      :::     ::::    ::: :::    ::: \n";
		cout << "\t\t               :+:    :+:   :+: :+:   :+:+:   :+: :+:   :+:   \n";
		cout << "\t\t              +:+    +:+  +:+   +:+  :+:+:+  +:+ +:+  +:+     \n";
		cout << "\t\t             +#++:++#+  +#++:++#++: +#+ +:+ +#+ +#++:++       \n";
		cout << "\t\t            +#+    +#+ +#+     +#+ +#+  +#+#+# +#+  +#+       \n";
		cout << "\t\t           #+#    #+# #+#     #+# #+#   #+#+# #+#   #+#       \n";
		cout << "\t\t          #########  ###     ### ###    #### ###    ###    \n\n";
		cout << "\n\t\t Za zeljeni izbor mode koristite strelice (gore-dolje) i space\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 3; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << MeniOdabir[i] << endl;
		 	}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << MeniOdabir[i] << endl;
			}
		}

		while (MeniProvjera)
		{
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				pointer = pointer - 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				pointer += 1;
				if (pointer == 3)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) & 1)
			{
				switch (pointer)
				{
				case 0:
				{
					system("cls");
					do {
						cout << "\t\t       ::::::::: :::::::::: ::::    ::: ::::::::::: ::::::::      :::  \n";
						cout << "\t\t           :+:  :+:        :+:+:   :+:     :+:    :+:    :+:   :+: :+: \n";
						cout << "\t\t         +:+   +:+        :+:+:+  +:+     +:+    +:+         +:+   +:+ \n";
						cout << "\t\t       +#+    +#++:++#   +#+ +:+ +#+     +#+    +#+        +#++:++#++: \n";
						cout << "\t\t     +#+     +#+        +#+  +#+#+#     +#+    +#+        +#+     +#+  \n";
						cout << "\t\t   #+#      #+#        #+#   #+#+#     #+#    #+#    #+# #+#     #+#   \n";
						cout << "\t\t ######### ########## ###    #### ########### ########  ###     ###    \n";
						cout << "\t\t                :::::::::      :::     ::::    ::: :::    ::: \n";
						cout << "\t\t               :+:    :+:   :+: :+:   :+:+:   :+: :+:   :+:   \n";
						cout << "\t\t              +:+    +:+  +:+   +:+  :+:+:+  +:+ +:+  +:+     \n";
						cout << "\t\t             +#++:++#+  +#++:++#++: +#+ +:+ +#+ +#++:++       \n";
						cout << "\t\t            +#+    +#+ +#+     +#+ +#+  +#+#+# +#+  +#+       \n";
						cout << "\t\t           #+#    #+# #+#     #+# #+#   #+#+# #+#   #+#       \n";
						cout << "\t\t          #########  ###     ### ###    #### ###    ###    \n\n";
						std::cout << "\n\n\n\t\t\tpassword: ";
						std::cin >> sifra;
						if (sifra != 1234) {
							system("cls");
							std::cout << "Neispravna sifra\t\t\t\tBroj pokusaja: " << 2 - brojac;
							brojac++;
						}
						else if (sifra == 1234) {
							menuP();
						}
						if (brojac == 3) {
							IzaberiMode();
						}
					} while (sifra!=1234);
					menuP();
					MeniProvjera = false;
					break;
				}
				case 1:
				{
					system("cls");
					do {
						cout << "\t\t       ::::::::: :::::::::: ::::    ::: ::::::::::: ::::::::      :::  \n";
						cout << "\t\t           :+:  :+:        :+:+:   :+:     :+:    :+:    :+:   :+: :+: \n";
						cout << "\t\t         +:+   +:+        :+:+:+  +:+     +:+    +:+         +:+   +:+ \n";
						cout << "\t\t       +#+    +#++:++#   +#+ +:+ +#+     +#+    +#+        +#++:++#++: \n";
						cout << "\t\t     +#+     +#+        +#+  +#+#+#     +#+    +#+        +#+     +#+  \n";
						cout << "\t\t   #+#      #+#        #+#   #+#+#     #+#    #+#    #+# #+#     #+#   \n";
						cout << "\t\t ######### ########## ###    #### ########### ########  ###     ###    \n";
						cout << "\t\t                :::::::::      :::     ::::    ::: :::    ::: \n";
						cout << "\t\t               :+:    :+:   :+: :+:   :+:+:   :+: :+:   :+:   \n";
						cout << "\t\t              +:+    +:+  +:+   +:+  :+:+:+  +:+ +:+  +:+     \n";
						cout << "\t\t             +#++:++#+  +#++:++#++: +#+ +:+ +#+ +#++:++       \n";
						cout << "\t\t            +#+    +#+ +#+     +#+ +#+  +#+#+# +#+  +#+       \n";
						cout << "\t\t           #+#    #+# #+#     #+# #+#   #+#+# #+#   #+#       \n";
						cout << "\t\t          #########  ###     ### ###    #### ###    ###    \n\n";
						std::cout << "\n\n\n\t\t\tpassword: ";
						std::cin >> sifra;
						if (sifra != 5678) {
							system("cls");
							std::cout << "Neispravna sifra\t\t\t\tBroj pokusaja: " << 2 - brojac;
							brojac++;
						}
						else if (sifra == 5678) {
							menuR();
						}
						if (brojac == 3) {
							IzaberiMode();
						}
					} while (sifra != 5678);
					brojac = 0;
					MeniProvjera = false;
					break;
				}
				case 2:
				{
					system("cls");
					std::cout << "\n\n\n\t\tHvala Vam za koristenje nase aplikacije.\n\n";
					system("pause");
					Sleep(3000);
					std::exit(0);
				}
				default:
				{
					std::cout << "Greska!";
				}
				}
			}
		}
		Sleep(150);
	}
	cin.ignore();
}
void gotoxy(int x, int y)
{
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

void load()
{
	char a = 219;
	gotoxy(36, 14);
	cout << "Loading..."<< endl;
	gotoxy(30,16);
	for(int r =1; r<=20; r++)
	{
		for(int q=0; q<=10000000; q++);
		cout << a;
	}
}

