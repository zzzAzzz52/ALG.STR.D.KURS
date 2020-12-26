#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class expression
{
	string exp;

public:
	void add_exp();
	void print();
	bool isOperator(char o);
	int prior(char o);
	double Counting();
	bool isDigit(char o);
	bool isOperator2(char o, char o2, char o3, char o4);
	void setExp(string rt);
	string retExp();
};
