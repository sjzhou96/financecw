#include <iostream>
using namespace std;

class fraction {
	friend ostream &operator<< (ostream &os, const fraction &f) {
		if (i != 1) {
			os << f.numerator << "/" << f.denominator;
		}
		if (i == 1) {
			os << f.numerator ;
		}
		return os;
	};
private:
	int numerator, denominator;
	int gcd(int i, int j) {
		while (j != 0) {
			int temp = i;
			i = j;
			j = temp%j;		
		}
		return i;
		//return j == 0 ? j : gcd(j, i % j);
	}
	void reduce(int &i, int &j) {
		if (abs(i) > abs(j)){
			int h = gcd(abs(i), abs(j));
			i /= h;
			j /= h;
		}
		else {
			int h = gcd(abs(j), abs(i));
			i /= h;
			j /= h;
		}
		if (j < 0) {
			i *= -1;
			j *= -1;
		}
	};

public:
	fraction(int n = 0, int d = 1) : numerator(n), denominator(d) { reduce(numerator, denominator); }
	fraction operator+ (const fraction &f) const {
		int nn = f.numerator*denominator+f.denominator*numerator;
		int dd = f.denominator*denominator;
		fraction res(nn, dd);
		return res;
	};
	fraction operator- () const { fraction res(-numerator, denominator); return res; }
	bool operator< (const fraction &f) const {
		int n = numerator*f.denominator;
		int m = f. numerator*denominator;
		return bool(n < m);
	};
	fraction operator* (const fraction &f) const {
		fraction res(numerator*f.numerator, denominator*f.denominator);
		return res;
	};
	fraction operator- (const fraction &f) const {
		fraction res(numerator*f.denominator-f.numerator*denominator, denominator*f.denominator); return res;}
	fraction operator/ (const fraction &f) const {
		fraction res(numerator*f.denominator, denominator*f.numerator); return res;}
	
	fraction &operator+= (const fraction &f) {  
	numerator = f.numerator*denominator + f.denominator*numerator; 
	denominator = f.denominator*denominator;
	reduce(numerator, denominator);
	return *this;
	}

	fraction &operator-= (const fraction &f) {
		numerator = numerator*f.denominator - f.numerator*denominator;
		denominator = f.denominator*denominator;
		reduce(numerator, denominator);
		return *this;
	}


	fraction operator+ (int i,const fraction &f) const {
		fraction res(numerator*f.denominator - f.numerator*denominator, denominator*f.denominator); return res;
	}

};

int main() {
	fraction a(1, 12), b(1, 25), c(1, 300), e(3, 4), f(2, 5), g(7, 2), h;
	cout << a << " + " << b << " + " << c << " = " << a + b + c << endl;

	if (-a < b) cout << -a << " < " << b << endl;
	else cout << -a << " >= " << b << endl;

	h = e*f - g;
	cout << e << " * " << f << " - " << g << " = " << h << endl;

	fraction i(-1, 6), j(5, 17), k(3, 5);
	cout << i << " + " << j << " / " << k << " = " << i + j / k << endl;

	int m = 2, q = 1;
	fraction n(1, 3), p(4, 5), s(a), t(b), u(c), w(e), x(f), y(g), v, z;
	//cout << m << " + " << n << " = " << m + n << endl;
	//cout << p << " - " << q << " = " << p - q << endl;

	v = (a += b -= u);
	cout << s << " += " << t << " -= " << u << " = " << v << endl;
	//z = (e *= f /= g);
	//cout << w << " *= " << x << " /= " << y << " = " << z << endl;

	cin.get();
	return 0;
}