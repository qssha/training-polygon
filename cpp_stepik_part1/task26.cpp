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

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;
    
    int getNumerator() const {
        return numerator_;
    }

    int getDenominator() const {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

bool operator==(Rational const& first, Rational const& second) {
    return first.getNumerator() * second.getDenominator() == second.getNumerator() * first.getDenominator();
}

bool operator!=(Rational const& first, Rational const& second) {
    return !(first == second);
}

bool operator<(Rational const& first, Rational const& second) {
    return first.getNumerator() * second.getDenominator() < second.getNumerator() * first.getDenominator();
}

bool operator>(Rational const& first, Rational const& second) {
    return second < first;
}

bool operator<=(Rational const& first, Rational const& second) {
    return !(second < first);
}

bool operator>=(Rational const& first, Rational const& second) {
    return !(first < second);
}
