#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

class zespolone {
	double real;
	double uroj;
public:
	zespolone(double r, double i) {
		real = r;
		uroj = i;
	}

	zespolone() {
		srand(time(NULL));
		real = rand() % 100;;
		uroj = rand() % 100;;	
		
	}

	~zespolone()
	{

	};

	zespolone operator +(zespolone & z) {
		zespolone wyn;
		wyn.real = real + z.real;
		wyn.uroj = uroj + z.uroj;
		return wyn;

	}

	zespolone operator -(zespolone & z) {
		zespolone wyn;
		wyn.real = real - z.real;
		wyn.uroj = uroj - z.uroj;
		return wyn;

	}

	zespolone operator *(zespolone & z) {
		zespolone wyn;
		wyn.real = real * z.real - uroj * z.uroj;
		wyn.uroj = real * z.uroj + uroj * z.real;
		return wyn;

	}

	void modul()
	{
		double i;
		i = sqrt(real*uroj + uroj * uroj);
		cout << "|z|=" << i << endl;
		//return sqrt(Rm*Rm + Im * Im);
	};

	void sprzezenie()
	{
		//zespolone wyn;
		if (uroj >= 0)
			uroj = -uroj;
		else
			uroj = uroj * (-1);
		//wyswietlanie();
		//return wyn;
	};

	void wyswietlanie()
	{
		cout << "z=" << real;
		if (uroj >= 0)
			cout << "+" << uroj << "i";
		else
			cout << uroj << "i" << endl;
	};

	friend ostream & operator <<(ostream & s, zespolone & z);

};
ostream & operator <<(ostream & s, zespolone & z) {
	return s << z.real << "+" << z.uroj;
}

int main()
{
	cout << "wpisz liczbe zespolona czesc Rm i Im " << endl;
	double a ;
	double b ;
	cin >> a;
	cin >> b;
	zespolone z1(a, b);
	zespolone z2;
	cout << "z1:";
	z1.wyswietlanie();
	cout << endl;
	cout << "z2:";
	z2.wyswietlanie();
	cout << endl;
	zespolone z3 = z1 + z2;
	zespolone wyn;
	cout << z3<<"i" << endl;
	z3 = z1 - z2;
	cout << z3 << "i" << endl;
	z3 = z1 * z2;
	cout << z3 << "i" << endl;
	z3.sprzezenie();
	z3.wyswietlanie();
	z3.modul();

	/*int ile;
	cin >> ile;
	double *tablica;
	tablica = new double[ile];
	srand(time(NULL));
	for (int x = 0; x <= ile - 1; x++)
	{
		
		zespolone z;
		for (int j = 0; j <= ile - 1; j++)
		{
			z.wyswietlanie();
			cout << endl;
		}
	}
	
	delete tablica;*/

	//int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
	//cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10;
	//zespolone z(a1, a2), z1(a3, a4), z2(a5, a6), z3(a7, a8), z4(a9, a10), wyn;

	system("pause");
	return 0;
}