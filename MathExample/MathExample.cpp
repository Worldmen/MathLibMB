// MathExample.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctgmath>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include "MathFunctionsStatic.h"
//#include "MathFunctionsDynamic.h"

using namespace std;

int main()
{
	double complex[3][3][2];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 2; k++)
			{
				complex[i][j][k] = rand() % 5;
			}
	//cout << MathFunctionsDynamic::add(6, 3) << endl;
	double R, angles;
	cout << "Enter circumradius of regular polygon, and how many angles it has: ";
	cin >> R >> angles;
	cout << "Area of " << angles << " polygon is: " << areaOfRegularPolygon(R, angles) << endl;

	cout << "Enter each row of 3x3 real matrix determinant: ";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> complex[i][j][0];

	cout << "Enter each row of 3x3 imagine matrix determinant: ";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> complex[i][j][0];

	pair<double, double> complexResult = matrixDeterminantThreeOfComplex(complex);
	cout << "complex number equal to: " << complexResult.first << " + " << complexResult.second << "i" << endl;

	double realPart, imaginePart, index;
	cout << "Enter complex number to make root of it, real part:";
	cin >> realPart;
	cout << "Enter imagine part:";
	cin >> imaginePart;
	cout << "Enter root index:";
	cin >> index;

	vector<pair<double, double>>  v = rootComplex(realPart, imaginePart, index);
	for (int i = 0; i < v.size(); i++)
		cout << i << "." << " real possibility: " << v[i].first << " " << i << "." << " imagine possibility: " << v[i].second << endl;

	char* num1 = new char[100];
	char* num2 = new char[100];
	cout << "Enter numbers to add: ";
	cin >> num1 >> num2;
	int lenghs = 0;
	char* resultc = add100Digit(num1, num2);
	cout << "Result is: ";
	showResoultOfAdding(resultc);

	cout << "Enter 3 equations'coefficients with 3 unknowns: ";
	double unknows[3][4];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cin >> unknows[i][j];
	vector<double> resultMatrix = matrixDeterminantThreeUnknowns(unknows);
	return 0;
}

