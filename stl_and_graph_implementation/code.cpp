# include<iostream>
# include<vector>
# include<algorithm>
# include<utility>
using namespace std; 
 
int NMAX = 5000; // constraints on N 
int MMAX = 100000; // constraints on M 
 
vector <int> vv; // vector
vv.resize(n); // resizing since you get to know n during run-time 
for (i = 0; i < n; i++) { 
   cin >> vv[i];
}
sort(vv.begin(), vv.end()); // sort vv from begin to end
 
vector < pair <int, int> > pairs(n); // vector of pairs
int a, b; 
for (i = 0; i < n; i++) { 
   cin >> pairs[i].first >> pairs[i].second;
}
sort(pairs.begin(), pairs.end()); // sort still works
 
vector <int> nodes(NMAX); // vector with NMAX elements
vector <int> nodes(NMAX, 0); // vector with NMAX elements initialized to 0
 
int adjacency_matrix[NMAX][NMAX]; // 2D matrix NMAX x NMAX 
for (int i = 0; i < m; i++) { 
   cin >> a >> b; 
   adjacency_matrix[a][b] = 1; 
   adjacency_matrix[b][a] = 1; // only if graph is undirected
}
// neighbors of node using adjacency matrix 
// ( good if dense graph, for sparse graph use adjacency list )
for (int i = 0; i < n; i++) {
   if (adjacency_matrix[node][i] == 1) {
      // do stuff 
   }
}
// is x neighbor of y ? ( good )
if ( adjacency_matrix[x][y] == 1 ) { 
   // do stuff 
} 
 
vector <int> adjacency_list [NMAX]; // NMAX vectors 
for (int i = 0; i < m; m++) { 
   cin >> a >> b; 
   adjacency_list[a].push_back(b); 
   adjacency_list[b].push_back(a); // only if graph is undirected
}
// is x neighbor of y ? ( bad, adjacency matrix is faster )
for (int i = 0; i < adjacency_list[node].size() ; i++) {
   if (adjacency_list[x][i] == j) {
      // do stuff 
   }
}
// neighbors of node using adjacency list ( good )
for (int i = 0; i < adjacency_list[node].size() ; i++) {
int neighbor = adjacency_list[node][i]; 
   // do stuff 
}
 
// adjacency matrix using vectors. 
// overkill. not recommended. use 2D arrays 
vector< vector<int> > adjacency_matrix (N, vector<int>(N, 0)) ; 
