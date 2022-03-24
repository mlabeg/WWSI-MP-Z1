//E. Figielska, Metody programowania, 2022
#include<iostream>
#include<string>
using namespace std;

class Macierz {
	float ** t;		//deklaracja wskaŸnika do zmiennej typu float* (czyli do wskaŸnika)
	int n;
	int m;
public:
	Macierz(int n, int m) {
		this->n = n;
		this->m = m;
		t = new float*[n];		//utworzenie n-elementowej tablicy zawieraj¹cej wskaŸniki (adresy)
		for (int i = 0; i < n; i++) {
			t[i] = new float[m];		//utworzenie m-elementowej tablicy (elementy s¹ wartoœciami), wpisanie adresu tej tablicy do elementu t[i]
		}
	}
	~Macierz() { //definicja destruktora
		delete[] t;
	}
	void wpisz() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cout << "t[" << i << "][" << j << "] = ";
				cin >> t[i][j];
			}
	}
	void drukuj() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << t[i][j] << " ";
			}
			cout << "\n";
		}
	}
	//bool dodaj(Macierz& w) {
	//	//dodaje wspólrzedne wektora w do wspólrzednych wektora, dla którego wykonuje sie metoda dodaj()
	//	if (n != w.n) { //dodawanie nie odbedzie sie dla wektorow o róznych rozmiarach
	//		return false;
	//	}
	//	for (int i = 0; i < n; i++) {
	//		wspolrzedne[i] += w.wspolrzedne[i];
	//	}
	//	return true;
	//}
};

int main() {
	int n, m;
	cout << "liczba wierszy = "; cin >> n;
	//cout << "liczba kolumn = "; cin >> m;
	//float** tab = utworz(n, m);
	//Macierz * w1=new Macierz (100);
	//w1.wpisz();
	//w1.drukuj();
	//usun(tab, n);

}
//int main() {
//	int n = 0;
//	cout << "Podaj rozmiar wektora: "; cin >> n;
//	Macierz w1(n), w2(n);
//	w1.wpisz();
//	w2.wpisz();
//	bool zrobione = w1.dodaj(w2);
//	if (zrobione) {
//		w1.drukuj();
//	}
//wywolanie destruktorów dla obiektów w1 i w2