#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int nok(int a, int b) {
	return a * b / gcd(a,b);
}

class Rational {
public:
    Rational() {
        // Конструктор по умолчанию
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(int numerator, int denominator) {
        // Конструктор с параметрами

        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }

        int gcd_value = gcd(abs(numerator), abs(denominator));

        // Сохраняем знак
        int sign = (numerator >= 0 && denominator >= 0) || (numerator <= 0 && denominator <= 0) ? 1 : -1;

        numerator_ = sign * abs(numerator) / gcd_value;
        denominator_ = abs(denominator) / gcd_value;
    }

    int Numerator() const {
        // Возвращает числитель
        return numerator_;
    }

    int Denominator() const {
        // Возвращает знаменатель
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator + (const Rational& lhr, const Rational& rhr) {
	int _nok = nok(lhr.Denominator(), rhr.Denominator());
	return { lhr.Numerator() * _nok / lhr.Denominator() + rhr.Numerator() * _nok / rhr.Denominator(), _nok };
}

Rational operator - (const Rational& lhr, const Rational& rhr) {
	int _nok = nok(lhr.Denominator(), rhr.Denominator());
	return { lhr.Numerator() * _nok / lhr.Denominator() - rhr.Numerator() * _nok / rhr.Denominator(), _nok };
}

bool operator==(const Rational& lhr, const Rational& rhr) {
	if (lhr.Numerator() == rhr.Numerator() && lhr.Denominator() == rhr.Denominator()) return true;
	else return false;
}

Rational operator*(const Rational& lhr, const Rational& rhr) {
	return { lhr.Numerator() * rhr.Numerator(), lhr.Denominator() * rhr.Denominator() };
}

Rational operator/(const Rational& lhr, const Rational& rhr) {
	return { lhr.Numerator() * rhr.Denominator(), lhr.Denominator() * rhr.Numerator() };
}

ostream& operator << (ostream& stream, const Rational& rational) {
	stream << rational.Numerator() << '/' << rational.Denominator();
	return stream;
}

istream& operator >> (istream& stream, Rational& rational) {
	int denominator, numerator;
	char separator;

	if (stream >> numerator >> separator >> denominator && separator == '/') {
		rational = Rational(numerator, denominator);
	}

	return stream;

}

bool operator < (const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

bool operator > (const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator();
}

int main() {
	
	return 0;
}
