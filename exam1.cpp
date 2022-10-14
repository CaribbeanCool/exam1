#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructors
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    Fraction(int num, int den)
    {
        numerator = num;
        denominator = den;
    }
    Fraction(const Fraction &f2)
    {
        numerator = f2.getNumerator();
        denominator = f2.getDenominator();
    }
    // Getters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Setters
    void setNumerator(int num) { this->numerator = num; }
    void setDenominator(int den) { this->denominator = den; }

    double getNumericalValue() const { return 1.0 * numerator / denominator; }

    Fraction add(const Fraction &f2) const
    {
        return Fraction(numerator * f2.getDenominator() + f2.getNumerator() * denominator, denominator * f2.getDenominator());
    }
};

class MixedFraction
{
private:
    int integer;
    Fraction fraction;

public:
    // Constructors
    MixedFraction(int integer, int num, int den);

    MixedFraction(const MixedFraction &mxfr)
    {
        this->integer = mxfr.getInteger();
        this->fraction = Fraction(mxfr.getFraction().getNumerator(), mxfr.getFraction().getDenominator());
    }
    // Getters
    int getInteger() const { return integer; }
    Fraction getFraction() const { return fraction; }

    // Setter
    void setMixedFraction(int integer, int num, int den);

    Fraction getImproperFraction() const
    {
        return Fraction(this->fraction.getDenominator() * this->integer + this->fraction.getNumerator(), this->fraction.getDenominator());
    }
    MixedFraction add(const MixedFraction &mf2) const;
    double getNumericalValue() const;
    bool isEquivalentWith(const Fraction &f) const;
    bool isBetweenClosedInterval(double min, double max) const;
    static bool isValidMixedFraction(const MixedFraction &mxfr);
    void reduceFraction();
};

/**
 *
 * EXERCISE #1
 *
 * @brief Implement parameterized constructor of MixedFraction.
 *
 * @param integer
 * @param numerator
 * @param denominator
 */
MixedFraction::MixedFraction(int integer, int num, int den)
{
    // YOUR CODE HERE
    this->integer = integer;
    this->fraction = Fraction(num, den);
}

/**
 * EXERCISE #2
 *
 * @brief Implement the following setter for target MixedFraction integer,
 * fraction numerator and fraction denominator.
 *
 * @param integer
 * @param numerator
 * @param denominator
 */
void MixedFraction::setMixedFraction(int integer, int num, int den)
{
    // YOUR CODE HERE
    this->integer = integer;
    this->fraction = Fraction(num,den);
}

/**
 * EXERCISE #3
 *
 * @brief Sum the target MixedFraction and the 2nd MixedFraction
 *
 * HINT: Sum both target and parameter MixedFractions as Improper Fractions,
 *       then convert resulting Fraction into MixedFraction.
 * @param mf2    cout << num / gcd1 << endl;
    cout << den / gcd1 << endl;
 */
MixedFraction MixedFraction::add(const MixedFraction &mf2) const
{
    // YOUR CODE HERE
    Fraction f1 = this->getImproperFraction();  //* GET FRACTION
    Fraction f2 = mf2.getImproperFraction();    //* GET FRACTION
    Fraction f3 = f1.add(f2);   //? ADD FUNCTION ALREADY IN CLASS
    int integer = f3.getNumerator() / f3.getDenominator();  //* CONSIGO ENTERO
    int num = f3.getNumerator() % f3.getDenominator();  //* CONSIGO NUMERADOR
    int den = f3.getDenominator();  //* CONSIGO DENOMINADOR
    cout << "==================================================\n";
    return MixedFraction(integer, num, den);
}

/**
 * EXERCISE #4
 *
 * @brief Compute the Numerical Value the target object MixedFraction represents.
 *
 * @return Numerical value as a double.
 */
double MixedFraction::getNumericalValue() const
{
    // YOUR CODE HERE
    Fraction f1 = this->getImproperFraction();
    return f1.getNumericalValue();  //* METHOD ALREADY IN CLASS
}

/**
 * EXERCISE #5
 *
 * @brief Determine if the target MixedFraction represents the same numeric value as the parameter Fraction
 *
 * @param Fraction f (constant reference)
 * @return true or false
 */
bool MixedFraction::isEquivalentWith(const Fraction &f) const
{
    // YOUR CODE HERE
    Fraction f1 = this->getImproperFraction();
    if (f1.getNumericalValue() == f.getNumericalValue()){
        return true;
    }
    return false;
}

/**
 * EXERCISE #6
 *
 * @brief Determine if the numerical value of the target MixedFraction is in between the interval [min, max]
 *
 * @param min (minimum value)
 * @param max (maximum value)
 * @return true or false
 */
bool MixedFraction::isBetweenClosedInterval(double min, double max) const
{
    // YOUR CODE HERE
    Fraction f1 = this->getImproperFraction();
    if (f1.getNumericalValue() >= min && f1.getNumericalValue() <= max){    //* IF NUMERICAL_VALUE IS BETWEEN MINIMUM AND MAXIMUM
        return true;
    }
    else{
        return false;
    }
}

/**
 * EXERCISE #7
 *
 * @brief Determine if the parameter is a valid MixedFraction.
 *        A valid MixedFraction has an integer other than 0 and a Proper Fraction a/b where a<b.
 *
 * @param mxfr
 * @return true or false
 */

bool MixedFraction::isValidMixedFraction(const MixedFraction &mxfr)
{
    // YOUR CODE HERE
    if (mxfr.getInteger() != 0 && mxfr.getFraction().getNumerator() < mxfr.getFraction().getNumerator()){   //? IF THE "ENTERO" IS NOT ZERO and THE NUMERATOR IS LESS THAN THE DENOMINATOR
        return true;
    }
    return false;
}

int gcd(int a, int b)
{
    int gcd = 1;
    for (int i = 1; i <= min(a, b); i++)
        if (a % i == 0 && b % i == 0)
            gcd = i;
    return gcd;
}

/**
 * EXERCISE #8
 *
 * @brief Simplify the Fraction property of target MixedFraction.
 *
 * Hint: Use gcd(a, b) given function to modify target object fraction attributes
 * by dividing both numerator and denominator by the greatest common divisor of both numbers.
 *
 **/
void MixedFraction::reduceFraction()
{
    // YOUR CODE HERE
    int num = this->fraction.getNumerator();
    int den = this->fraction.getDenominator();
    int gcd1 = gcd(num, den);
    this->fraction.setNumerator(num / gcd1);
    this->fraction.setDenominator(den / gcd1);
}
