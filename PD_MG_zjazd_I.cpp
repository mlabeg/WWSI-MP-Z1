#include<iostream>
#include<string>
//#include<stddef.h>
#define NULL 0
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
			
			//cin.sync();
			cin>>id;	//ID powinno byæ nadawane automatycznie
			cout<<"Tytul: ";
			cin>>ws;
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
			cout<<"\nCena: "<<cena<<" zl";
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
		
		void usun1(string q){
			if(q=="tytul"){
				tytul.clear();
			}else if(q==autor){
				autor.clear();
			}else if(q=="rok_wydania"){
				rok_wydania = NULL;
			}else if(q=="liczba stron"){
				liczba_stron=NULL;
			}else if(q=="cena"){
					cena=NULL;
			}else if(q=="stan"){
					stan=NULL;
			}
		}
		
		
//		void usun(string q){
//			switch(str2int(q)){
//				case str2int("tutul"):
//					tytul=NULL;
//					break;
//				case str2int("autor"):
//					autor=NULL;
//					break;
//				case str2int("rok_wydania"):
//					rok_wydania=NULL;
//					break
//				case str2int("liczba stron"):
//					liczba_stron=NULL;
//					break;	
//				case str2int("cena"):
//					cena=NULL;
//					break;
//				case str2int("stan"):
//					stan=NULL;
//					break;	
//			}
//		}
		
		float daj_cene(){
			return cena;	//metoda udostepnia watosc prywatnego pola
		}
		
		string daj_autora(){
			return autor;
		}
		
		string daj_tytul(){
			return tytul;
		}
		int daj_rok(){
			return rok_wydania;
		}
		int daj_id() {
			return id;
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
		cout << endl;
	}
}
void pokaz_tanie_ksiazki(int n, Ksiazka ksiazki[]){
	float cena_max;
	cout<<"\nPodaj cene maksymalna: ";
	cin>> cena_max;
	for(int i=0; i<n; i++){
		if(ksiazki[i].daj_cene()<=cena_max){
			ksiazki[i].pokaz();
			
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

void ksiazki_wg_roku(int n, Ksiazka ksiazki[]){
	int rok;
	int l=0;
	cout<<"\nPodaj rok do wyswietlenia wydanych w nim ksiazek: ";
	cin>> rok;
	cout<<"Tytuly: "<<endl;
	for(int i=0; i<n; i++){
		if(ksiazki[i].daj_rok()==rok){
			cout<<ksiazki[i].daj_autora()<<" - "<<ksiazki[i].daj_tytul() << "\n";
			l++;	
		}
	}
	if(l==0){
		cout<<"Brak pozycji do wyswietlenia.";
	}
}

void usuwanie_informacji(int n, Ksiazka ksiazki[]){
	int r;
	string t;
	bool l,k = true;

	do {
		cout << "\nPodaj ID ksiazki do usuniecia informacji: ";
		cin >> r;
		for (int i = 0; i < n; i++) {
			if (ksiazki[i].daj_id() == r) {
				ksiazki[i].pokaz();
				cout << endl;
				l = false;
			}
		}
		if (l) {
			cout << "Brak pozycji o podanym ID.";
		}
	} while (cin.fail() || l);
	
	//mozna dodaæ jeszcze automatyczne numerowanie ID
	
	do{

	cout<<"Ktora informacje usunac? ";
	cin>>t;

	for (int i = 0; i < n; i++) {
		if (ksiazki[i].daj_id() == r) {
			ksiazki[i].usun1(t);
			ksiazki[i].pokaz();
			k = false;
		}
	}
	if (l) {
		cout << "Brak informacji do usuniecia";
	}
} while (cin.fail() || k);
//ksiazki[r].pokaz();
cout << endl;

	//ksiazki[r].usun1(t);
//	switch(t)
//	{
//		case "tytul":
//			ksiazki[r].usun(t);
//			break;
//		case "autor":
//			ksiazki[r].usun(t);
//			break;
//		case "rok wydania"
//			ksiazki[r].usun(t);
//			break;
//		case "liczba stron"
//			ksiazki[r].usun(t);
//		case "cena":
//			ksiazki[r].usun(t);
//			break;
//		case "stan":
//			ksiazki[r].usun(t);
//			break;	
//	}
}

void sortowanie(int n, Ksiazka ksiazki[]){
	//sortowanie nie jest "odporne" na tytu³y i autorów wprowadzonych raz z ma³ych raz z wielkich liter (kod ASCII)
	char d;
	int pmin, pmax, i, p;
	bool j;

	cout<<"Posortowac wg autora czy tytulu? [a/t]: ";
	cin>>d;
	do {
		j = false;
		if (d == 'a'||d=='A') {

			pmin = 0;
			pmax = n - 1;
			do {
				p = -1;
				for (i = pmin; i < pmax; i++)
					if (ksiazki[i].daj_autora() > ksiazki[i + 1].daj_autora()) {
						swap(ksiazki[i], ksiazki[i + 1]);
						if (p < 0) pmin = i;
						p = i;
					}
				if (pmin) pmin--;
				pmax = p;
			} while (p >= 0);
		}
		else if (d == 't'||d=='T'){

			pmin = 0;
			pmax = n - 1;
			do {
				p = -1;
				for (i = pmin; i < pmax; i++)
					if (ksiazki[i].daj_tytul() > ksiazki[i + 1].daj_tytul()) {
						swap(ksiazki[i], ksiazki[i + 1]);
						if (p < 0) pmin = i;
						p = i;
					}
				if (pmin) pmin--;
				pmax = p;
			} while (p >= 0);
		}
		else {
			cout << "Nie znam takiego typu sortowania, spróbuj jeszcze raz.";
			j = true;
		}
	} while (cin.fail() || j); 
}


int main(){
	
	Ksiazka ksiazki[100]; //utworzenie tablicy, której elementy s¹ obiektami klasy ksia¿ka;
	int lp_ksiazek=0;
	int w;
	bool k=true;
	
	cout<<"\n1. Dodaj nowa ksiazke\n2. Pokaz wszystkie ksiazki\n3. Ksiazki wg autora\n4. Ksiazki wg roku wydania\n5. Usuniecie informacji\n6. Sortowanie wg autora/tytulu\n9. Wyjscie\n\n99. Wyswietl menu" <<endl;
	do{
		cin.clear();
		cin.sync();
		cout<<"\nWybierz: ";
		cin>>w;
	
		switch (w){
			case 1:
				lp_ksiazek= dodaj_ksiazki(lp_ksiazek, ksiazki);
				break;
			case 2:
				pokaz_wszystkie_ksiazki(lp_ksiazek, ksiazki);
				break;
			case 3:
				ksiazki_wg_autora(lp_ksiazek, ksiazki);
				break;
			case 4:
				ksiazki_wg_roku(lp_ksiazek, ksiazki);
				break;
			case 5:
				usuwanie_informacji(lp_ksiazek,ksiazki);
				break;
			case 6:
				sortowanie(lp_ksiazek, ksiazki);
				pokaz_wszystkie_ksiazki(lp_ksiazek, ksiazki);
				break;
			case 9:
				k=false;
				break;
			case 99:
				cout << "\n1. Dodaj nowa ksiazke\n2. Pokaz wszystkie ksiazki\n3. Ksiazki wg autora\n4. Ksiazki wg roku wydania\n5. Usuniecie informacji\n6. Sortowanie wg autora/tytulu\n9. Wyjscie\n\n99. Wyswietl menu" << endl;
				break;
			default:
				cout<<"Nie znam takiego polecenia.";
				break;
		}
	
	}while(cin.fail()||k);
	
//	
//	pokaz_tanie_ksiazki(lp_ksiazek, ksiazki);
//	ksiazki_wg_autora(lp_ksiazek, ksiazki);
	
}
