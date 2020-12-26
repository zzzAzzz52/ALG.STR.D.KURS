#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
#include <math.h>

using namespace std;

void expression::setExp(string rt)
{
	exp.resize(rt.size());
	exp = rt;
}

string expression::retExp()
{
	return exp;
}

void expression::add_exp()
{
	char stack[100];
	int i = -1, j = 0;
	int k = 0;
	string tmp;
	tmp.empty();

	do
	{
		j++;
		if ((exp.size() - j == -1) && (i != -1))
		{
			break;
		}
		if (exp[exp.size() - j] == ' ')
		{

		}
		//
		else if (exp[exp.size() - j] == 's')
		{
			if (exp[exp.size() - j - 1] == 'o')
			{
				if (exp[exp.size() - j - 2] == 'c')
				{
					for (int q = 0; q < 3; q++)
					{
						tmp.push_back(exp[exp.size() - j]);
						j++;
					}
				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else
			{
				throw out_of_range("wrong input");
			}
		}
		//
		else if (exp[exp.size() - j] == 'n')
		{
			if (exp[exp.size() - j - 1] == 'i')
			{
				if (exp[exp.size() - j - 2] == 's')
				{
					for (int q = 0; q < 3; q++)
					{
						tmp.push_back(exp[exp.size() - j]);
						j++;
					}
				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else if (exp[exp.size() - j - 1] == 'l')
			{
				for (int q = 0; q < 2; q++)
				{
					tmp.push_back(exp[exp.size() - j]);
					j++;
				}

			}
			else
			{
				throw out_of_range("wrong input");
			}
		}
		//
		else if (exp[exp.size() - j] == 'g')
		{
			if (exp[exp.size() - j - 1] == 't')
			{
				if (exp[exp.size() - j - 2] == 'c')
				{
					for (int q = 0; q < 3; q++)
					{
						tmp.push_back(exp[exp.size() - j]);
						j++;
					}
				}
				else
				{
					for (int q = 0; q < 2; q++)
					{
						tmp.push_back(exp[exp.size() - j]);
						j++;
					}
				}
			}
			else if (exp[exp.size() - j - 1] == 'o')
			{
				if (exp[exp.size() - j - 2] == 'l')
				{
					for (int q = 0; q < 3; q++)
					{
						tmp.push_back(exp[exp.size() - j]);
						j++;
					}
				}
			}
			else
			{
				throw out_of_range("wrong input");
			}
		}
		//
		else if (exp[exp.size() - j] == 't')
		{
			if (exp[exp.size() - j - 1] == 'r')
			{
				if (exp[exp.size() - j - 2] == 'q')
				{
					if (exp[exp.size() - j - 3] == 's')
					{
						for (int q = 0; q < 4; q++)
						{
							tmp.push_back(exp[exp.size() - j]);
							j++;
						}
					}
					else
					{
						throw out_of_range("wrong input");
					}
				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else
			{
				throw out_of_range("wrong input");
			}
		}
		//
		else if (isdigit(exp[exp.size() - j]) || exp[exp.size() - j] == '.')
		{
			while ((!isOperator(exp[exp.size() - j])) && (isdigit(exp[exp.size() - j]) || exp[exp.size() - j] == '.'))
			{
				tmp.push_back(exp[exp.size() - j]);
				j++;
				if (j > exp.size()) break;
			}
			if (j > exp.size()) j++;
			tmp.push_back(' ');
			j--;
		}
		else if (isOperator(exp[exp.size() - j]))
		{
			if (exp[exp.size() - j] == ')')
			{
				i++;
				stack[i] = exp[exp.size() - j];
			}
			else if (exp[exp.size() - j] == '(')
			{
				char s = stack[i];
				i--;

				do
				{
					tmp.push_back(s);
					s = stack[i];
					i--;
				} while (s != ')');
			}
			else
			{
				if (i > -1)
				{
					if (prior(exp[exp.size() - j]) <= prior(stack[i]))
					{
						tmp.push_back(stack[i]);
						i--;
					}
				}
				i++;
				stack[i] = exp[exp.size() - j];
			}

		}
		else if (exp[exp.size() - j] == 'i')
		{
			if (exp[exp.size() - j - 1] == 'p')
			{
				for (int i = 0; i < 2; i++)
				{
					tmp.push_back(exp[exp.size() - j]);
					j++;
				}
				tmp.push_back(' ');
			}
			else
			{
				throw out_of_range("wrong input");
			}
		}
		else if (exp[exp.size() - j] == 'e')
		{
			tmp.push_back(exp[exp.size() - j]);
			tmp.push_back(' ');
		}
		else
		{
			throw domain_error("wrong input");
		}
	} while (exp.size() - j != -1);

	while (i != -1)
	{
		if (stack[i] == '(' || stack[i] == ')')
		{
			i--;
		}
		else
		{
			tmp.push_back(stack[i]);
			i--;
		}
	}
	
	exp.resize(tmp.size());
	int n = tmp.size();

	for (int l = 0; l < tmp.size(); l++)
	{
		exp[l] = tmp[n - 1];
		n--;
	}

}

double expression::Counting()
{
	double result = 0;
	double stack[100];
	int i = -1;
	int j = 1;

	while (exp.size() - j != -1)
	{
		if (exp[exp.size() - j] == ' ')
		{

		}
		else if ((isDigit(exp[exp.size() - j]) == true) || (exp[exp.size() - j] == '.'))
		{
			string a; a.empty();
			string a2; a2.empty();
			int m, c = 1;

			while ((!isOperator(exp[exp.size() - j])) && (isdigit(exp[exp.size() - j]) || exp[exp.size() - j] == '.'))
			{
				a += exp[exp.size() - j];
				j++;
				if (j == exp.length()) break;
			}
			m = a.size();
			for (m; m > 0; m--)
			{
				a2.push_back(a[a.size() - c]);
				c++;
			}

			i++;
			stack[i] = stod(a2);
			j--;
		}
		else if (isOperator(exp[exp.size() - j]))
		{
			double k = stack[i];
			i--;
			double k2 = stack[i];
			i--;

			switch (exp[exp.size() - j])
			{
			case '+': result = k + k2; break;
			case '-': result = k - k2; break;
			case '*': result = k * k2; break;
			case '/': result = k / k2; break;
			case '^': result = pow(k, k2); break;
			}
			i++;
			stack[i] = result;
		}
		else if (exp[exp.size() - j] == 'i')
		{
			string val;
			val.empty();
			for (int i = 0; i < 2; i++)
			{
				val.push_back(exp[exp.size() - j]);
				j++;
			}
			i++;
			stack[i] = 3.14;
			j--;
		}
		else if (exp[exp.size() - j] == 'e')
		{
			string val;
			val.empty();
			val.push_back(exp[exp.size() - j]);
			i++;
			stack[i] = 2.7182818284;
		}
		else if (exp[exp.size() - j] == 's')
		{
			if (exp[exp.size() - j - 1] == 'o')
			{	
				double k = stack[i];
				i--;

				result = cos(k);

				i++;
				stack[i] = result;
				j++; j++;
			}
		}
		else if (exp[exp.size() - j] == 'n')
		{
			if (exp[exp.size() - j - 1] == 'i')
			{
				double k = stack[i];
				i--;

				result = sin(k);

				i++;
				stack[i] = result;
				j++; j++;
			}
			else if (exp[exp.size() - j - 1] == 'l')
			{
				double k = stack[i];
				i--;

				result = log(k);

				i++;
				stack[i] = result;
				j++;
			}
		}
		else if (exp[exp.size() - j] == 'g')
		{
			if (exp[exp.size() - j - 1] == 't')
			{
				if (exp[exp.size() - j - 2] == 'c')
				{
					double k = stack[i];
					i--;
					
					result = cos(k)/sin(k);

					i++;
					stack[i] = result;
					j++; j++;
				}
				else
				{
					double k = stack[i];
					i--;

					result = tan(k);

					i++;
					stack[i] = result;
					j++;
				}
			}
			else if (exp[exp.size() - j - 1] == 'o')
			{
				if (exp[exp.size() - j - 2] == 'l')
				{
					double k = stack[i];
					i--;

					result = log10(k);

					i++;
					stack[i] = result;
					j++; j++;
				}
			}
		}
		else if (exp[exp.size() - j] == 't')
		{
			if (exp[exp.size() - j - 1] == 'r')
			{
				if (exp[exp.size() - j - 2] == 'q')
				{
					if (exp[exp.size() - j - 3] == 's')
					{
						double k = stack[i];
						i--;

						result = sqrt(k);

						i++;
						stack[i] = result;
						j++; j++; j++;

					}
				}
			}
		}
		j++;
	}
	exp.empty();
	return stack[i];
}

void expression::print()
{
	cout << exp;
}

bool expression::isDigit(char o)
{
	switch (o)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}

bool expression::isOperator(char o)
{
		switch (o)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case ')':
		case '(':
			return 1;
			break;
		default:
			return 0;
		}
}

bool expression::isOperator2(char o, char o2, char o3, char o4)
{
	if (o == 's')
	{
		if (o2 == 'o')
		{
			if (o3 == 'c')
			{
				return 1;
			}
		}
	}

}

int expression::prior(char o)
{
	switch (o)
	{
	case'+':
	case'-':
		return 1;
		break;
	case'*':
	case'/':
		return 2;
		break;
	case'^':
		return 3;
		break;
	case')':
	case'(':
		return 0;
		break;

	}
}