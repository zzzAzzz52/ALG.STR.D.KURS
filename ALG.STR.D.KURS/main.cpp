#include "Header.h"
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <math.h>

using namespace std;

void main()
{
	while (1)
	{
		expression exp;
		string exp2;
		cout << "Enter expression = ";
		getline(cin, exp2);
		exp.setExp(exp2);
		exp.add_exp();
		cout << endl;
		exp.print();
		cout << " = ";
		cout << exp.Counting();
		cout << endl;
		cout << endl;
	}
}