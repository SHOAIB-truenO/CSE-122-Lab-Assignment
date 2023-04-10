
/*Queation Number 3:Demonstrate a C++ code that creates a class called Fraction. The class
Fraction has two attributes: numerator and denominator.
• In your constructor (inyour__init__ method), verify(assert?) that the
numerator and denominator passed in during initiation are both of type int.
If you want to be thorough, also check to make sure that the denominator is
not zero.
• Write a .reduce() method that will reduce a fraction to lowest terms.
• Override the Object class’s __str__ and __repl__ methods so that your
objects will print out nicely. Remember that__str__ is more for humans;
__repl__ is more for programmers. Ideally ,the__repl__ method will
produce a string that you can run through the eval() function to clone the
original fraction object.
• Override the + operator. In your code, this means that you will implement
the special method __add__. The signature of the __add__ function will be
def __add__(self, other): , and you’ll return a new Fraction with the result
of the addition. Run your new Fraction through the reduce() function before
returning.*/


#include <iostream>
#include <cassert>
                    using namespace std;
                    class Fraction {
private:
    int numerator;
    int denominator;
public:
                Fraction(int n,int d)
     {
                assert(d != 0);
                assert(is_int(n) && is_int(d));
                numerator=n;
                denominator=d;
   }
    int gcd(int a, int b) {
        return b==0 ? a : gcd(b, a % b);
  }
     void reduce() {
        int gcd_val=gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
  }
                        friend ostream& operator<<(ostream& os, const Fraction& f) {
                          os<<f.numerator<<"/"<< f.denominator;
        return os;
    }
                        friend Fraction operator+(const Fraction& f1,const Fraction& f2) {
                        int n=f1.numerator*f2.denominator+f2.numerator*f1.denominator;
                        int d=f1.denominator*f2.denominator;
          Fraction result(n,d);
        result.reduce();
      return result;
     }
   bool is_int(int n) {
                           return static_cast<double>(n)==static_cast<int>(n);
    }};
   int main() {
            Fraction f1(7,4);
            Fraction f2(5,8);
            Fraction f3 =f1+f2;
            cout <<f1<<"+"<<f2<<"="<<f3<<endl;
    return 0;
} 
