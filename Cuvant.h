#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <graphics.h>
#include <windows.h>

using namespace std;

class Cuvant {
public:
	string cuvant;
	string cuvant_de_afisat;
	vector<char> litereBune;
	vector<char> litereRele;
	int incercari = 6;
public:
	Cuvant(string value1) : cuvant{ value1 }, cuvant_de_afisat{ value1 } {};

	//functie pentru construirea cuvantului de afisat
	void  construireCuvantDeAfisat() {
		char plitera, ulitera;
		for (int i = 0; i < cuvant.size(); i++) {
			if (cuvant[i] > 90) {
				cuvant[i] -= 32;
				cuvant_de_afisat[i] -= 32;
			}
		}
		cuvant_de_afisat[0] = cuvant[0];
		cuvant_de_afisat[cuvant.size() - 1] = cuvant[cuvant.size() - 1];
		for (int i = 1; i < (cuvant.size() - 1); i++) {
			if (cuvant[i] != cuvant[0] && cuvant[i] != cuvant[cuvant.size() - 1]) {
				cuvant_de_afisat[i] = '_';
			}
		}
	}

	//functie pentru verificare literei si inlocuirea ei in cuvant
	void verificareSiInlocuireLitera(char litera) {
		int ok = 0;
		for (int i = 0; i < (cuvant.size()); i++)
		{
			if (litera == cuvant[i] || (litera + 32) == cuvant[i] || (litera - 32) == cuvant[i]) {
				ok = 1;
				cuvant_de_afisat[i] = litera;
				cuvant_de_afisat[i] -= 32;
			}
		}
		for (int i = 0; i < litereBune.size(); i++)
			if (litera == litereBune[i])
				ok = 2;
		for (int i = 0; i < litereRele.size(); i++)
			if (litera == litereRele[i])
				ok = 2;
		//ok=2 inseamna ca litera a mai fost introdusa
		//ok=1 inseamna ca litera s-a gasit in cuvant pentru prima data
		if(ok == 2)
            cout<<" Caracterul a mai fost introdus. Incercati altul!"<<endl;
		if (ok == 1) {
			litereBune.push_back(litera);
			cout << "Litera introdusa se gaseste in cuvant!" << endl;;
		}
		//ok=0 inseamna ca litera nu se gaseste in cuvant
		if (ok == 0){
			litereRele.push_back(litera);
			cout << "Litera introdusa nu se gaseste in cuvant!" << endl;
			incercari--;
		}
	}

	//verificare daca cuvantul este completat
	int verificareTerminat() {
		if (cuvant == cuvant_de_afisat)
			return 1;
		return 0;
	}

	//verificare numarul de incercari ramase
	int nuMaiSuntIncercari() {
		if (incercari == 0)
			return 1;
		return 0;
	}

	//functie care afiseaza cuvantul pe ecran NEINCEPUTA!!!!!!!!!!!!!!!!!
	void afisareCuvantPeEcran() {
		//afisare cuvant_de_afisat
		//afisare vectori litereBune si litereRele
	}

	void afisare() {
		cout << " Cuvantul cautat : " << cuvant_de_afisat << endl;
		cout << "Mai aveti " << incercari << " incercari.";
		cout << endl << "Litere corecte : ";
		for (int i = 0; i < litereBune.size(); i++)
			cout << litereBune[i] << " ";
		cout << endl << "Litere gresite : ";
		for (int i = 0; i < litereRele.size(); i++)
			cout << litereRele[i] << " ";
		cout << endl;
	};
};
