# Kruskal's Algorithm

## Pseudocode


* create a forest F (a set of trees), where each vertex in the graph is a separate tree
* create a set S containing all the edges in the graph
* while S is nonempty and F is not yet spanning
	
	* remove an edge with minimum weight from S
	
	* if the removed edge connects two different trees then add it to the forest F, combining two trees into a single tree

At the termination of the algorithm, the forest forms a minimum spanning forest of the graph. If the graph is connected, the forest has a single component and forms a minimum spanning tree



