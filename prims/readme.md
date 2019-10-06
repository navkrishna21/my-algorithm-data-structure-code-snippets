# Prim's Algorithm
Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. 


## Pseudocode:
```
Select an arbitrary vertex s to start the tree from.

While (there are still nontree vertices)
  
    Select the edge of minimum weight between a tree and nontree vertex
  
    Add the selected edge and vertex to the MST tree T.

```

## Time Complexity:
Time complexity of Prim's Algorithm depends on the implementation. Following is for my implementation:

Each edge is visited exactly twice, thus in the worst case there are almost O(E) inserts.(Since priority queue doesn't support updates).

Also, there are atmost O(E) items in the priority_queue.

priority_queue supports all these operations in logarithmic time. Hence one insert takes O(logE) time.

There are V deletes too. but they are neglected since for this algorithm to work V-1 <= E

Total time complexity is O(ElogE + VlogE) = O(ElogE)

## Problem Link for the code:
[MST - Minimum Spanning Tree](https://www.spoj.com/problems/MST/)
