// Suma.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstring>
#define LIMIT 30

using namespace std;

void intToTab(char* tab, int liczba) {
	memset(tab, -1, LIMIT);
	int cyfra = 0;
	int i = 0;
	while (liczba > 0) {
		tab[i++] = liczba % 10;
		liczba = liczba / 10;
	}
}

void intPlus(char* result, char* m1, char* m2) {
	memset(result, -1, LIMIT);
	char l1, l2, reszta=0;
	int cnt = 0;
	for (int i = 0; i < LIMIT; i++) {
		if (m1[i] == -1 && m2[i] == -1) break;
		l1 = (m1[i] == -1) ? 0 : m1[i];
		l2 = (m2[i] == -1) ? 0 : m2[i];
		result[i] = (l1 + l2 + reszta) % 10;
		reszta = (l1 + l2 + reszta) / 10;
		cnt++;
	}
	if (reszta) result[cnt] = reszta;
}

void intCopy(char* result, char* m) {
	memset(result, -1, LIMIT);
	for (int i = 0; i < LIMIT; i++) {
		if (m[i] == -1) break;
		result[i] = m[i];
	}
}

void intMul(char result[], char m1[],long long unsigned int m2) {
	memset(result, -1, LIMIT);
	int cyfra = 0, i, r, reszta = 0, licznik_cyfr=0, j;
	while (m2 > 0) {
		cyfra = m2 % 10;
		m2 /= 10;
		i = licznik_cyfr++;
		j = 0;
		while (m1[j] != -1 && i <= LIMIT && j < LIMIT) {
			r = m1[j] * cyfra + reszta;
			result[i] = ((result[i] == -1) ? 0 : result[i]) + (r % 10);
			reszta = r / 10;
			i++;
			j++;
		}
		if (reszta) result[i] = reszta;
		reszta = 0;
	}
}
void printLiczba(char* tab) {
	for (int i = LIMIT - 1; i >= 0; i--) {
		if (tab[i] != -1) cout << (int)(tab[i]);
	}
}

int main()
{
	bool suma1 = true;
	char sumaa[LIMIT], sumab[LIMIT], mn1[LIMIT], mn2[LIMIT], liczba1[LIMIT], liczba2[LIMIT],para[LIMIT];
	int ileLiczb, wpis/*, l1, l2*/;
	memset(sumab, -1, LIMIT);
	/*intToTab(liczba1, 2);
	intMul(sumaa, liczba1, 18);
	printLiczba(sumaa);*/
	//int suma = 0;
	cin >> ileLiczb;
	/*int *wpis = new int[ileLiczb];*/
	long long unsigned int pom = ileLiczb, mnoz = ileLiczb;
	//cin >> l1 >> l2;
	//long long unsigned int mnoz = ileLiczb, pom = ileLiczb;
	//long long unsigned int *liczby = new long long unsigned int[ileLiczb];

	/*for (int i = 0; i < ileLiczb; i++)
	{
		cin >> wpis[i];
	}*/
	if (ileLiczb == 1) {
		cin >> wpis;
		cout << wpis;
	}
	else if (ileLiczb % 2 == 0) {
		for (int i = 0; i < ileLiczb; i++)
		{
			wpis = 0;
			cin >> wpis;
			intToTab(liczba1, wpis);
			//printLiczba(liczba1);
			//cout << endl;

			intMul(mn1, liczba1, mnoz);
			//printLiczba(mn1);
			//cout << endl;
			if (i < ileLiczb / 2) {
				pom -= 2;
				mnoz += pom;
			}
			//else if (i == ileLiczb / 2) { ; }
			else {
				pom += 2;
				mnoz -= pom;
				}
			
			//intToTab(liczba2, wpis2);
			////printLiczba(liczba2);
			////cout << endl;
			//intMul(mn2, liczba2, mnoz);
			////printLiczba(mn2);
			////cout << endl;
			//if (i <= ileLiczb / 2) {
			//	pom -= 2;
			//	mnoz += pom;
			//}
			//else {
			//	pom += 2;
			//	mnoz -= pom;
			//}
			//pom -= 2;
			//mnoz += pom;
			//intPlus(para, mn1, mn2);
			////printLiczba(para);
			////cout << endl;
			if (suma1)
			{
				suma1 = false;
				intPlus(sumaa, sumab, mn1);
				//printLiczba(sumaa);
				//cout << endl;
			}
			else
			{
				suma1 = true;
				intPlus(sumab, sumaa, mn1);
				//printLiczba(sumab);
				//cout << endl;

			}
		}
		//if (ileLiczb % 2)
		//{
		//	intToTab(liczba1, wpis[ileLiczb / 2]);
		//	intMul(mn1, liczba1, mnoz);
		//	if (suma1) {
		//		intPlus(sumaa, sumab, mn1);
		//		suma1 = false;
		//	}
		//	else {
		//		intPlus(sumab, sumaa, mn1);
		//		suma1 = true;
		//	}
		//}
		if (suma1) printLiczba(sumab);
		else printLiczba(sumaa);
	}
	else if (ileLiczb % 2 == 1)
	{
		for (int i = 0; i < ileLiczb; i++)
		{

			wpis = 0;
			cin >> wpis;
			intToTab(liczba1, wpis);
			//printLiczba(liczba1);
			//cout << endl;

			intMul(mn1, liczba1, mnoz);
			//printLiczba(mn1);
			//cout << endl;
			if (i < ileLiczb / 2) {
				pom -= 2;
				mnoz += pom;
			}
			else if (i == ileLiczb / 2)
			{
				mnoz -= pom;
			}
			else {
				pom += 2;
				mnoz -= pom;
			}

			//intToTab(liczba2, wpis2);
			////printLiczba(liczba2);
			////cout << endl;
			//intMul(mn2, liczba2, mnoz);
			////printLiczba(mn2);
			////cout << endl;
			//if (i <= ileLiczb / 2) {
			//	pom -= 2;
			//	mnoz += pom;
			//}
			//else {
			//	pom += 2;
			//	mnoz -= pom;
			//}
			//pom -= 2;
			//mnoz += pom;
			//intPlus(para, mn1, mn2);
			////printLiczba(para);
			////cout << endl;
			if (suma1)
			{
				suma1 = false;
				intPlus(sumaa, sumab, mn1);
				//printLiczba(sumaa);
				//cout << endl;
				
			}
			else
			{
				suma1 = true;
				intPlus(sumab, sumaa, mn1);
				//printLiczba(sumab);
				//cout << endl;
			}
			
		}
		if (suma1) printLiczba(sumab);
		else printLiczba(sumaa);
	}
	return 0;
}
//char liczba1[LIMIT];
	//intToTab(liczba1, l1);
	//char liczba2[LIMIT];
	//intToTab(liczba2, l2);
	////printLiczba(liczba1);
	//char res[LIMIT];
	//intPlus(res, liczba1, liczba2);
	//printLiczba(res);
	//cout << endl;
	//char resM[LIMIT];
	//intMul(resM, res, 100000);
	//printLiczba(resM);

	//for (int i = 0; i < ileLiczb; i++) {
	//	cin >> liczby[i];
	//}
	//if (ileLiczb % 2)
	//{
	//	for (int i = 0; i < ileLiczb / 2; i++)
	//	{
	//		suma += mnoz * liczby[i] + mnoz * liczby[ileLiczb - i - 1];
	//		pom -= 2;
	//		mnoz += pom;
	//	}
	//	suma += mnoz * liczby[ileLiczb / 2];
	//}
	//else
	//{
	//	for (int i = 0; i < ileLiczb / 2; i++)
	//	{
	//		suma += mnoz * liczby[i] + mnoz * liczby[ileLiczb - i - 1];
	//		pom -= 2;
	//		mnoz += pom;
	//	}

	//}
	//cout << suma;
	//delete[] liczby;

