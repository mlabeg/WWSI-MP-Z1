#include<iostream>
#include<string>
using namespace std;

class Macierz {
	float ** t;		//deklaracja wskaźnika do wskaźnika
	int n;
	int m;
public:
	Macierz(int n, int m) {
		this->n = n;
		this->m = m;
		t = new float*[n];		//utworzenie n-elementowej tablicy zawierającej wskaźniki
		for (int i = 0; i < n; i++) {
			t[i] = new float[m];		//utworzenie m-elementowej tablicy (elementy są wartościami), wpisanie adresu tej tablicy do elementu t[i]
		}
	}
	~Macierz() { //definicja destruktora
		delete[] t[n];
	}
	void wpisz() {
		cout << "Podaj wartosci: " << endl;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cout << "t[" << i << "][" << j << "] = ";
				cin >> t[i][j];
			}
		delete[] t;
	}
	void drukuj() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << t[i][j] << " ";
			}
			cout << "\n\n";
		}
	}
	void transpozycja(Macierz& m_t) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				m_t.t[j][i] = t[i][j];
			}
		}
		t = m_t.t;
	}

	bool dodaj(Macierz mac) {
		//dodaje wspólrzedne wektora w do wspólrzednych wektora, dla którego wykonuje sie dodaj()
		if (n != mac.n || m !=mac.m) { //porownianie dlugosci wektorow
			cout << "Nie pasujace rozmiary tablic." << endl;
			return false;
		}
		else {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					t[i][j] += mac.t[i][j];
				}
			return true;
		}
	}

	void psklr(float sklr) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				t[i][j] *= sklr;
			}
	}
};

int main() {
	int n, m;
	float sklr;
	cout << "liczba wierszy = "; cin >> n;
	cout << "liczba kolumn = "; cin >> m;

	Macierz * m1=new Macierz(n,m);
	m1->wpisz();
	m1->drukuj();

	cout << "\nMnozenie przez skalar, podaj wartosc skalarna: ";
	cin >> sklr;
	m1->psklr(sklr);
	m1->drukuj();

	cout << "Macierz transponowana: " << endl;
	Macierz* m_t = new Macierz(n, m);
	m1->transpozycja(*m_t);
	m1->drukuj();
	delete m_t;
	
	Macierz * m2=new Macierz(2,2);
	m2->wpisz();
	m2->drukuj();

	bool zrobione = m1->dodaj(*m2);
	if (zrobione) {
		m1->drukuj();
	}

	delete m1;
	delete m2;


	return 0;
}
