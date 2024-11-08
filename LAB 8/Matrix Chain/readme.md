# Aim of the program
### Write a program to implement the matrix chain multiplication problem using M-table & S-table to find optimal parenthesization of a matrix-chain product. Print the number of scalar multiplications required for the given input.

> _Note#_ Dimensions of the matrices can be inputted as row and column values. Validate the dimension compatibility.

## INPUT
```console
Enter number of matrices : 4
Enter row and col size of A1 : 30 35
Enter row and col size of A2 : 35 15
Enter row and col size of A3 : 15 5
Enter row and col size of A4 : 5 10
```

## OUTPUT
```console
M Table representation:
0       15750   7875    9375
0       0       2625    4375
0       0       0       750
0       0       0       0

S table representation:
0       1       1       3
0       0       2       3
0       0       0       3
0       0       0       0

Optimal Parenthesization: ((A1(A2A3))A4)
The optimal ordering of the given matrices requires 9375 scalar multiplications.
```