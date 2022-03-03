#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class Ksiazka{	//definicja klasy
	private: //sk³adowe s¹ prywatne - dostêpne tylko z operacji klasy
		int id;
		int rok_wydania;
		int liczba_stron;
		int stan;
		string tytul;	//zmienna sk³adowa klasy (dana); string - ³añcuch znaków
		string autor;
		float cena;
	public:	 //sk³adowe publiczne - mo¿na ich u¿ywaæ spoza klasy(np funkcji main)
		void wpisz(){	//funkcja sk³adowa klasy (operacja)
			
			cout<<"\nPodaj informacje o ksiazce: \n";
			cout<<"Id: ";
		//	cin>>ws;
			cin>>id;
			cout<<"Tytul: ";
			cin.sync();
			getline(cin, tytul);
			cout<<"Autor: ";
			getline(cin, autor);
			do{
				cin.clear(); // czyœci flagê b³êdu
				cin.sync(); // opró¿nia bufor strumienia
				cout<<"Rok wydania: ";
				cin>>rok_wydania;	
			}while(cin.fail());
			do{
				cin.clear();
				cin.sync();
				cout<<"Liczba stron: ";
				cin>>liczba_stron;
			}while(cin.fail());
			do{
				cin.clear();
				cin.sync(); 
				cout<<"Cena: ";
				cin>> cena;	
			}while(cin.fail());
			
			bool p;
			do{
				p=0;
				cout<<"Stan (1-5) \n(1- bardzo dobry, 5- zniszczony): ";
				cin>>stan;
				if(stan<1||stan>5){
					cout<<"Wprowadzono nieprawid³owy stan ksiazki. Sprobuj jeszcze raz.\n";
					p=1;
				}
			}while(cin.fail()||p);
		}
		void pokaz(){
			cout<<"\nId: "<<id;
			cout<<"\nTytul: "<<tytul;
			cout<<"\nAutor "<<autor;
			cout<<"\nRok wydania: "<<rok_wydania;
			cout<<"\nLiczba stron: "<<liczba_stron;
			cout<<"\nCena: "<<cena<" zl";
			cout<<"\nStan egzemplarza: ";
			switch(stan){
				case 1:
					cout<<"bardzo dobry";
					break;
				case 2:
					cout<<"dobry";
					break;	
				case 3:
					cout<<"dostateczny";
					break;
				case 4:
					cout<<"z³y";
					break;
				case 5:
					cout<<"zniszczony";
					break;
			}
		}
		
		float daj_cene(){
			return cena;	//metoda udostepnia watosc prywatnego pola
		}
		
		string daj_autora(){
			return autor;
		}
		
		string daj_tytul(){
			return tytul;
		}
};

int dodaj_ksiazki(int n, Ksiazka ksiazki[]){
	// n - ile mamy do tej pory ksiazek w tablicy
	char decyzja = 't';
	do{
		ksiazki[n].wpisz(); //wywo³anie metody wpisz dla obiektu n-tego w tablicy
		n++;
		cout<<"\nCzy chcesz dodac nowa ksiazke? [t/n]: ";
		cin >>decyzja;
	}while (decyzja=='t');
	return n;
}

void pokaz_wszystkie_ksiazki(int n, Ksiazka ksiazki[]){
	for(int i=0; i<n; i++){
		ksiazki[i].pokaz();
	}
}
void pokaz_tanie_ksiazki(int n, Ksiazka ksiazki[]){
	float cena_max;
	cout<<"\nPodaj cene maksymalna: ";
	cin>> cena_max;
	for(int i=0; i<n; i++){
		if(ksiazki[i].daj_cene()<=cena_max){
			ksiazki[i].pokaz(); //zaznaczone bo funkcja pokaz ma gdzies blad
			
		}
	}
}

void ksiazki_wg_autora(int n, Ksiazka ksiazki[]){
	string pautor;
	int l=0;
	cout<<"\nPodaj autora do wyswietlenia jego bibliografii: ";
	cin>> pautor;
	cout<<"Tytuly: "<<endl;
	for(int i=0; i<n; i++){
		if(ksiazki[i].daj_autora()==pautor){
			cout<<ksiazki[i].daj_tytul()<<"\n";
			l++;	
		}
	}
	if(l==0){
		cout<<"Brak pozycji do wyswietlenia.";
	}
}


int main(){
	
	Ksiazka ksiazki[100]; //utworzenie tablicy, której elementy s¹ obiektami klasy ksia¿ka;
	int lp_ksiazek=0;
	lp_ksiazek= dodaj_ksiazki(lp_ksiazek, ksiazki);
//	pokaz_wszystkie_ksiazki(lp_ksiazek, ksiazki);
//	pokaz_tanie_ksiazki(lp_ksiazek, ksiazki);
	ksiazki_wg_autora(lp_ksiazek, ksiazki);
	
}
