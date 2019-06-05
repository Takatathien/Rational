// Thien Trinh
// CSE 374
// Homework 7
// 06/06/2019

/* 
  Implementation of Rational.h
  If no number is entered, constructs a Rational object with 0/1
  If only one number is entered, constructs a Rational object with n/1
  If two number is entered, constructs a Rational object with n/d
*/

# include "Rational.h"
# include <cstdlib>
# include <stdio.h>

namespace rational374 {

static int gcd(int n, int d);

  // Constructors
  Rational::Rational() {
    numer_ = 0;
    denom_ = 1;
  }

  Rational::Rational(int n) {
    numer_ = n;
    denom_ = 1;
  }

  Rational::Rational(int n, int d) {
    numer_ = n;
    denom_ = d;

    int div_ = gcd(numer_, denom_);
    numer_ = numer_ / div_;
    denom_ = denom_ / div_;
  }

  // Accessors
  int Rational::n() const {
    return numer_;
  }

  int Rational::d() const {
    return denom_;
  }

  // Arithmetic
  Rational Rational::plus(Rational other) const {
    int n1 = n();
    int d1 = d();

    int n2 = other.n();
    int d2 = other.d();

    return Rational(((n1 * d2) + (n2 * d1)), d1 * d2); 
  }

  Rational Rational::minus(Rational other) const {
    int n1 = n();
    int d1 = d();

    int n2 = other.n();
    int d2 = other.d();

    return Rational(((n1 * d2) - (n2 * d1)), d1 * d2);
  }

  Rational Rational::times(Rational other) const {
    int n1 = n();
    int d1 = d();

    int n2 = other.n();
    int d2 = other.d();

    return Rational(n1 * n2, d1 * d2);
  }

  Rational Rational::div(Rational other) const {
    int n1 = n();
    int d1 = d();

    int n2 = other.n();
    int d2 = other.d();

    return Rational(n1 * d2, d1 * n2);
  }

  // Helper method that finds the greatest common divisor of 
  // two numbers in the arguments and returns it.
  static int gcd(int n, int d) {
    n = abs(n);
    d = abs(d);
    if (d == 0) {
      return n;
    } else {
      return gcd(d, n % d);
    }
  }
}
