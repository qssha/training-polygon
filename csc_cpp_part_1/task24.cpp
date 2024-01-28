#include <iostream>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational const& number) {
        this->add(number);
        return *this;
    }

    Rational& operator-=(Rational const& number) {
        this->sub(number);
        return *this;
    }

    Rational& operator*=(Rational const& number) {
        this->mul(number);
        return *this;
    }

    Rational& operator/=(Rational const& number) {
        this->div(number);
        return *this;
    }

    Rational operator-() const {
       Rational copyNumber(*this); 
       copyNumber.neg();
       return copyNumber;
    }

    Rational operator+() const {
        Rational copyNumber(*this);
        return copyNumber;
    }

private:
    int numerator_;
    int denominator_;
};
