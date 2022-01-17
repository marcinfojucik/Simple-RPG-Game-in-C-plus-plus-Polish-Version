#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

bool player_smierc = false;
bool walka;
int command;
string ruch;
int hp, dmg, fhp, fdmg; // FUNKCJE ODPOWIADAJ¥CE ZA ZDROWIE I OBRA¯ENIA ZADAWANE PRZEZ GRACZA
float xp, nexp=100; // FUNKCJE ZDABYWANIA I PODNOSZENIA POZIOMU DOŒWIADCZENIA PRZEZ GRACZA
int ehp, edmg, fedmg; // FUNKCJE ODPOWIADAJ¥CE ZA ZDROWIE I ZADAWANE OBRA¯ENIA PRZEZ PRZECIWNIKA
int lvl=1;
int x = 2,y = 2;
void menu();
void gra();
void mapa();
void statystyki();
void sterowanie();
void logika();
void klasa();
void bitwa();
void wilk();

// MECHANIKA MENU G£ÓWNEGO
void menu()
{
	system("cls");
	cout << "Witaj w grze RPG" << endl << endl;
	cout << "1. Start Gry" << endl;
	cout << "2. Wyjscie z Gry" << endl;
	cin >> command;
	
	switch(command)
	{
		case 1:
			{
			klasa();
			}break;
		case 2: 
		{
			cout << "Gra zostanie wylaczona" ; Sleep(1500);
			exit(0);
		}break;
		default:
			{
				cout << "Nie ma takiej opcji" << endl; Sleep(1500);
				menu();
			}break;
	}
}

// MECHANIKA WYBORU POSTACI
void klasa()
{
	system("cls");
	cout << "Wybierz klase postaci" << endl << endl;
	cout << "1. Wojownik" << endl;
	cout << "2. Lowca" << endl;
	cout << "3. Mag" << endl;
	cout << "4. Barbarzynca" << endl;
	cout << "5. Amazonka" << endl;
	cout << "6. Zlodziej" << endl;
	cin >> command;

	switch(command)
	{
		case 1:
			{
				hp = 30;
				dmg = 5;
				gra();
			}break;
		case 2:
			{
				hp = 25;
				dmg = 8;
				gra();
			}break;
		case 3:
			{
				hp = 10;
				dmg = 10;
				gra();
			}break;
		case 4:
			{
				hp = 100;
				dmg = 100;
				gra();
			}break;
		case 5: 
			{
				hp = 20;
				dmg = 6;
				gra();
			}break;
		case 6:
			{
				hp = 10;
				dmg = 8;
				gra();	
			}break;
		default:
			{
				cout << "Nie ma takiej klasy" << endl; Sleep(1500);
				klasa();
			}break;
	}
	
}

// MECHANIKA GRY
void gra()
{
	system("cls");
	mapa();
	statystyki();
	sterowanie();
	logika();
}

// MECHANIKA MAPY ŒWIATA GRY
void mapa()
{
	if(x==2 && y==2)
	{
		cout << "Wojslawice" << endl;
	}
		if(x==1 && y==1)
	{
		cout << "Stary Majdan" << endl;
	}
		if(x==2 && y==1)
	{
		cout << "Krasny Staw" << endl;
	}
		if(x==1 && y==2)
	{
		cout << "Chelm" << endl;
	}
}

// MECHANIKA INTERFEJSU GRY
void statystyki()
{
	cout << "Pozycja gracza na mapie: X:" << x << "Y:" << y << endl;
	cout << "HP: " << hp << "DMG: " << dmg << "LVL: " << lvl << "XP: " << xp << "/" << nexp << endl;
}

// MECHANIKA STEROWANIA POSTACI¥ 
void sterowanie()
{
	cin >> ruch;
	
	if(ruch=="w")
	{
		y=y+1;
	}
	else if(ruch=="s")
	{
		y=y-1;
	}
	else if(ruch=="d")
	{
		x=x+1;
	}
	else if(ruch=="a")
	{
		x=x-1;
	}
	else if(ruch=="walka")
	{
		wilk();
		bitwa();
	}
	else
	{
		cout << "Nie ma takiego polecenia" << endl; Sleep(1500);
		gra();
	}
}

// MECHANIKA ZDOBYWANIA DOŒWIADCZENIA I PODNOSZENIA POZIOMU POSTACI BOHATERA GRY
void logika()
{
if(xp>=nexp)
{
	xp=0;
	lvl=lvl+1;
	hp+=3;
	dmg+=2;
	nexp=nexp*1.15;
	}	
}

// MECHANIKA WALKI 
void bitwa()
{
	cout << "Rozpoczyna sie walka" << endl; Sleep(1500);
	fhp=hp;
	system("cls");
	while(ehp>=1 && fhp>=1)
	{
		system("cls");
		cout << "GRACZ" <<"HP: " << fhp << "DMG: " << dmg << "LVL: " << lvl << "XP: " << xp << "/" << nexp << endl;
		cout << "PRZECIWNIK" << "HP: " << ehp << "DMG: " << edmg << endl << endl;
		
		fdmg = rand() % dmg; 
		cout << "Gracz zadaje: " << fdmg << endl;
		ehp=ehp-fdmg;
		Sleep(500);
		
		fedmg = rand() % edmg; 
		cout << "Przeciwnik zadaje: " << fedmg << endl;
		hp=hp-fedmg;
		Sleep(500);
	}
	gra();
}

// MECHANIKA PRZECIWNIKA
void wilk()
{
	ehp = 15;
	edmg = 2;
}
