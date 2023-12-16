# AlgebraicFieldExtension
Algebraic Field Extension GF(p)^k in C++.

This program is able to construct a field GF(p)^k with the generation of an irreducible polynomial. Manual input of the polynomial is also available.

The forming element is X!
But why X? According to my research, for any field GF(p)^k there is an irreducible polynomial for which X is the generator.


The correctness of the polynomial goes through 3 checks:
1) Substitution of values that are included in the module (p - 1 values): if any substitution is 0, then the polynomial is generated anew;
2) If the number of terms of the generated polynomial is integerally divisible by p, then the polynomial is generated anew;
3) If the field is not closed by p^k -1 element (not only the last value of the field = 1), then the polynomial is also generated anew.

The principle of operation:
1) Generating a polynomial;
2) Creating an array that consists of p^k+1 arrays filled with zeros;
3) Performing operations:
  3.1) Multiplication by X (shifting elements to the left);
  3.2) Adding a polynomial module (if necessary);
  3.3) Taking modulo (if necessary);
4) Checking the field elements (only the last element should be 1).

If the polynomial entered manually is incorrect, then the polynomial will be automatically generated and then the field will be constructed.

Addition, multiplication and finding the inverse element by addition and multiplication are also implemented.


