# Aim of the program:
### Given an undirected weighted connected graph G(V, E) and starring vertex 'S'. Maintain a Min-Priority Queue 'Q' from the vertex set V and apply `Prim’s algorithm` to

- Find the minimum spanning tree T(V, E`). Display the cost adjacency matrix of ‘T’.

- Display total cost of the minimum spanning tree T.

> _Note#_ Nodes will be numbered consecutively from 1 to n (user input), and edges will have varying weight. The graph G can be read from an input file `“inUnAdjMat.dat”` that contains cost adjacency matrix. The expected output could be displayed as the cost adjacency matrix of the minimum spanning tree and total cost of the tree.


### FILE INPUT
**inUnAdjMat.dat**
```console
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
```

### TERMINAL EXECUTION
```bash
$ gcc solution.c
$ ./a.out
```

### CONSOLE OUTPUT
```console
Enter the number of vertices : 9
Enter the starting vertex : 1

MST Tree adjacent:
0  4  0  0  0  0  0  0  0
4  0  8  0  0  0  0  0  0
0  8  0  7  0  4  0  0  2
0  0  7  0  9  0  0  0  0
0  0  0  9  0  0  0  0  0
0  0  4  0  0  0  2  0  0
0  0  0  0  0  2  0  1  0
0  0  0  0  0  0  1  0  0
0  0  2  0  0  0  0  0  0

Total Weight of spanning tree : 37
```