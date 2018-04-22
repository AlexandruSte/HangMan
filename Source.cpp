#include <iostream>
#include <string>
#include <vector>
#include "Cuvant.h"
#include <graphics.h>
#include <windows.h>

using namespace std;

///function to draw to hanging
void desen() {
	line(80,450,240,450);
	line(160,450,160,80);
	line(160,80,400,80);
	line(400,80,400,120);
}

int main() {
    int gm,gd;
    gd=DETECT;
    initgraph(&gd, &gm,"");
    string cuvant1;
    cout << "Scrieti cuvantul pentru spanzuratoare : ";
    cin >> cuvant1;
    Cuvant cuvant = ( cuvant1 );
	cuvant.construireCuvantDeAfisat();
	system("cls");
	if (cuvant.cuvant_de_afisat == cuvant.cuvant || cuvant.cuvant.size() < 3)
		cout << "Trebuie sa introduceti un cuvant din mai mult de 2 caractere si cu cel putin 3 caractere distincte";
	else
	{
		while (true) {
        system("cls");
        if(cuvant.incercari==6)
            desen();
        if(cuvant.incercari==5){
            circle(400, 155, 35);
        }
        if(cuvant.incercari==4){
            line(400, 190, 400, 325);
        }
        if(cuvant.incercari==3){
            line(400,220,350,270);
        }
        if(cuvant.incercari==2){
            line(400,220,450,270);
        }
        if(cuvant.incercari==1){
            line(400,325,450,375);
        }
			cuvant.afisare();
			char litera;
			cout << "Scrieti litera pe care doriti sa o cautati : ";
			cin >> litera;
			cout << endl;
			cuvant.verificareSiInlocuireLitera(litera);
			if (cuvant.nuMaiSuntIncercari()) {
			    line(400,325,350,375);
				cout << "Ati pierdut!";
				break;
			}
			if (cuvant.verificareTerminat()) {
				cout << "Felicitari! Ati castigat!";
				break;
			}
		}
	}
	Sleep(7000);
	return 0;
}
