# Aim of the program:
_Define a struct __`person`__ as follows:_
```c
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
```
### Write a menu driven program to read the data of `n` students from a csv file and store them in a dynamically allocated array of struct person. Implement the min-heap or max-heap and its operations based on the menu options.


## Sample Input :
```console
MAIN MENU (HEAP)
1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit
```
## Sample Output :
```console
Enter your choice : 1
Total No of persons: 7
Id      Name                    Age     Height  Weight(pound)
0       Adarsh Hota             39      77      231
1       Levi Maier              56      77      129
2       Priya Kumari            63      78      240
3       Dorothy Helton          47      72      229
4       Florence Smith          24      75      171
5       Erica Anyan             38      73      102
6       Norma Webster           23      75      145
```

```console
Enter your choice : 2
            Priya Kumari (63 years old)
      Erica Anyan (38 years old)
            Adarsh Hota (39 years old)
Norma Webster (23 years old)
            Levi Maier (56 years old)
      Florence Smith (24 years old)
            Dorothy Helton (47 years old)
```
```console
Enter your choice : 3
            Norma Webster (145 pounds)
      Adarsh Hota (231 pounds)
            Erica Anyan (102 pounds)
Priya Kumari (240 pounds)
            Florence Smith (171 pounds)
      Dorothy Helton (229 pounds)
            Levi Maier (129 pounds)
```
```console
Enter your choice : 4
Weight of the youngest person
Name     Norma Webster
Age      23
Weight   145
```
```console
Enter your choice : 5
Insert new person :
ID:     741
Name:   Samriddha Sil
Age:    20
Height: 67
Weight: 154
            Norma Webster (23 years old)
      Priya Kumari (63 years old)
            Erica Anyan (38 years old)
Samriddha Sil (20 years old)
            Florence Smith (24 years old)
      Adarsh Hota (39 years old)
            Levi Maier (56 years old)
                  Dorothy Helton (47 years old)
```
```console
MAIN MENU (HEAP)
1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit

Enter your choice : 6
Deleted person
Name     Adarsh Hota
Age      39
Height   77
Weight   231
```

```console
Enter your choice : 7
Program closed
```