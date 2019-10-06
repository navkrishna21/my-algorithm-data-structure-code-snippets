#include<iostream>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
 
typedef struct comp{
    bool operator()(const pair<int,int>&a, pair<int,int>&b )
    {
        return a.second>b.second;
    }
}comp;

int main(){
    int n,m;
 
    cin>>n>>m; //input number of nodes n and edges m
 
    vector< vector< pair<int,int> > > adj(n+1);
    
    int x,y,wt; //x and y has an edge of weight w
 
    //input graph
    for(int i=1;i<=m;i++){ 
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }
 
    int dist[n+1];
    bool vis[n+1];
    for(int i=1;i<=n;i++){
        dist[i]=1000001; //initialize distance array to an infinite number
        vis[i]=false; //initialize visited array to false
    }
 
    priority_queue<pair<int,int>, vector<pair<int,int> >,comp >pq; //min-heap
 
    //add node 1 to start the MST and its distance will be 0
    pq.push({1,0}); 
    dist[1]=0;
 
    int unvisited=n; //keep count of univisted nodes
    long long ans=0;
    while(unvisited>0){
        
        if(pq.empty()==true) //condition for MST does not exist 
            ans=0; 
 
        int node =  pq.top().first;
        int w= pq.top().second;
        pq.pop();
     
        if(vis[node]) //Node already in MST
            continue;
        vis[node]=true;
        
        unvisited--;
        ans+=w; //add edge weight to answer
 
        for(auto neighb : adj[node] ){ 
            if( neighb.second< dist[neighb.first] ){ //update distances
                dist[neighb.first]=neighb.second;
                pq.push({neighb.first,neighb.second}); //add the adjacent node and the edge weight connecting it
            }
        }
    }
    cout<<ans<<endl;
}
