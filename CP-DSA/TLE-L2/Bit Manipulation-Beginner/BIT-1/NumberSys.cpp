// The system we use runs through a decimal system with base 10.
// However, computers are not programmed through base 10 systems.
// Early computers were programmed with base 2 (binary), base 8
// (octal), and base 16 (hexadecimal) systems.

// The OR operator (“|”) takes every corresponding bit of the numbers
// and checks whether at least one of them is set.

// The AND operator (“&”) takes every corresponding bit of the numbers
// and checks whether all of them are set.

// The XOR operator (“^”) takes every corresponding bit of the numbers
// and checks the parity of number of set bits.

// A << B shifts the A to the left by B bits, adding B zeroes at the end.
// The result is same as A * 2B.

// A >> B shifts the A to the right by B bits, deleting B bits from the end.
// The result is same as A / 2B.

// Properties of Bitwise Operators

// ● OR , AND , XOR are associative and commutative.
// ● A^0 = A
// ● A^A = 0
// ● If A^B = C , then A^C = B and B^C = A
// ● A&B <= MIN(A,B)
// ● A|B >= MAX(A,B)
// ● (A&1) is 1 if A→odd , else 0
// ● A & (A-1) is 0 if A is power of 2
