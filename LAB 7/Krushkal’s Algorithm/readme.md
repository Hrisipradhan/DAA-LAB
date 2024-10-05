# Aim of the program: 
### Given an undirected weighted connected graph G(V, E). Apply Krushkal’s algorithm to
- Find the minimum spanning tree T(V, E’) and Display the selected edges of G.
- Display total cost of the minimum spanning tree T.

> Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have varying weight. The weight matrix of the graph can be represented from the user’s input in the given format. The expected output could be the selected edge and the corresponding cost of the edge as per the sample output.

### CONSOLE OUTPUT

```console
Enter the number of vertices : 9
Enter the number of edges : 14
Enter
V1 V2 Distance
1  2  4
1  8  8
2  3  8
2  8  11
3  4  7
3  6  4
3  9  2
4  5  9
4  6  14
5  6  10
6  7  2
7  8  1
7  9  6
8  9  7

Edge Cost
7--8  1
3--9  2
6--7  2
1--2  4
3--6  4
3--4  7
1--8  8
4--5  9
Total Weight of the Spanning Tree: 37
```