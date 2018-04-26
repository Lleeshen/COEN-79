 /* 
	Lyman Shen, October 21 2017
	FILE: poly.cpp
	CLASS implemented: polynomial (see poly.h for documentation)
	INVARIANT for the sequence class:
		1. The degree of the polynomial is in the member variable current_degree;
		2. All coeficients of degrees larger than the current_degree are 0.
		3. The coeficient for the n-th degree of a polynomial is stored in coef[n].
 */

#include <iostream>
#include <climits>
#include <cassert>
#include "poly.h"

namespace coen79_lab4
{
	void polynomial::update_current_degree()
	{
		unsigned int i;
		for(i = MAXIMUM_DEGREE; i != 0; i--)
		{
			if(coef[i] != 0)
			{
				current_degree = i;
				return;
			}
		}
		current_degree = 0;
	}

	polynomial::polynomial(double c, unsigned int exponent)
	{
		assert(exponent <= MAXIMUM_DEGREE);
		size_t i;
		for(i = 0; i <= MAXIMUM_DEGREE; i++)
		{
			coef[i] = 0;
		}
		coef[exponent] = c;
		current_degree = exponent;
	}

	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	{
		assert(exponent <= MAXIMUM_DEGREE);
		coef[exponent] = coefficient;
		update_current_degree();
	}

	void polynomial::add_to_coef(double amount, unsigned int exponent)
	{
		assert(exponent <= MAXIMUM_DEGREE);
		coef[exponent] += amount;
		update_current_degree();
	}

	void polynomial::clear( )
	{
		unsigned int i;
		for(i = 0; i <= current_degree; i++)
		{
			coef[i] = 0;
		}
		current_degree = 0;
	}

	polynomial polynomial::antiderivative( ) const
	{
		assert(degree() <= MAXIMUM_DEGREE);
		polynomial antideriv;
		double value;
		int i;
		for(i = 0; i <= current_degree; i++)
		{
			value = coef[i] / (i + 1);
			antideriv.assign_coef(value,i+1);
		}
		antideriv.current_degree = current_degree + 1;
		return antideriv;
	}

	double polynomial::coefficient(unsigned int exponent) const
	{
		return (exponent <= MAXIMUM_DEGREE) ? coef[exponent] : 0;
	}

	double polynomial::definite_integral(double x0, double x1) const
	{
		polynomial antideriv = antiderivative();
		double defInt = antideriv.eval(x1) - antideriv.eval(x0);
		return defInt;
	}

	polynomial polynomial::derivative( ) const
	{
		polynomial deriv;
		int i;
		for (i = 1; i <= current_degree; i++)
		{
			deriv.assign_coef((double) i * coef[i],i - 1);
		}
		deriv.current_degree = current_degree - 1;
		return deriv;
	}

	double polynomial::eval(double x) const
	{
		double sum = 0, term;
		unsigned int i,j;
		for (i = 0; i <= current_degree; i++)
		{
			term = coef[i];
			for(j = 0; j < i; j++)
			{
				term *= x;
			}
			sum += term;
		}
		return sum;
	}

	bool polynomial::is_zero( ) const
	{
		return (current_degree == 0 && coef[0] == 0);
	}

	unsigned int polynomial::next_term(unsigned int e) const
	{
		unsigned int i;
		for(i = e + 1; i <= current_degree; i++)
		{
			if(coef[i] != 0)
			{
				return i;
			}
		}
		return 0;
	}

	unsigned int polynomial::previous_term(unsigned int e) const
	{
		unsigned int i;
		if(e == 0)
		{
			return UINT_MAX;
		}
		for(i = e - 1; i != 0; i++)
		{
			if(coef[i] != 0)
			{
				return i;
			}
		}
		return (coef[0] != 0) ? 0 : UINT_MAX;
	}

	polynomial operator +(const polynomial& p1, const polynomial& p2)
	{
		polynomial polynomial3;
		unsigned int exp, maxExp;
		double value;
		maxExp  = (p1.degree() > p2.degree()) ? p1.degree() : p2.degree();
		for(exp = 0; exp <= maxExp; exp++)
		{
			value = p1.coefficient(exp) + p2.coefficient(exp);
			polynomial3.assign_coef(value, exp);
		}
		return polynomial3;
	}

	polynomial operator -(const polynomial& p1, const polynomial& p2)
	{
		polynomial polynomial3;
		unsigned int exp, maxExp;
		double value;
		maxExp  = (p1.degree() > p2.degree()) ? p1.degree() : p2.degree();
		for(exp = 0; exp <= maxExp; exp++)
		{
			value = p1.coefficient(exp) - p2.coefficient(exp);
			polynomial3.assign_coef(value, exp);
		}
		return polynomial3;
	}

	polynomial operator *(const polynomial& p1, const polynomial& p2)
	{
		assert(p1.degree( ) + p2.degree( ) <= polynomial::MAXIMUM_DEGREE);
		polynomial polynomial3;
		unsigned int exp1, exp2;
		double value;
		for(exp1 = 0; exp1 <= p1.degree(); exp1++)
		{
			for(exp2 = 0; exp2 <= p2.degree(); exp2++)
			{
				value = p1.coefficient(exp1) * p2.coefficient(exp2);
				polynomial3.add_to_coef(value, exp1 + exp2);
			}
		}
		return polynomial3;
	}

	std::ostream& operator << (std::ostream& out, const polynomial& p)
	{
		unsigned int i = p.degree();
		if(i > 1)
		{
			out << p.coefficient(i) << "x^" << i;
			i--;
			while(i != 1)
			{
				if(p.coefficient(i) > 0)
				{
					out << " + " << p.coefficient(i) << "x^" << i;
				}
				else if (p.coefficient(i) < 0)
				{
					out << " - " << -p.coefficient(i) << "x^" << i;
				}
				i--;
			}
			if(p.coefficient(i) > 0)
			{
				out << " + " << p.coefficient(i) << "x";
			}
			else if (p.coefficient(i) < 0)
			{
				out << " - " << -p.coefficient(i) << "x";
			}
			i--;
			if(p.coefficient(i) > 0)
			{
				out << " + " << p.coefficient(i);
			}
			else if (p.coefficient(i) < 0)
			{
				out << " - " << -p.coefficient(i);
			}
		}
		else if (i == 1)
		{
			out << p.coefficient(1) << "x";
			if(p.coefficient(0) > 0)
			{
				out << " + " << p.coefficient(0);
			}
			else if (p.coefficient(0) < 0)
			{
				out << " - " << -p.coefficient(0);
			}
		}
		else
		{
			out << p.coefficient(0);	
		}
		return out;
	}
}