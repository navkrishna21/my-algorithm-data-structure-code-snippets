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
 
    cin>>n>>m;
 
    vector< vector< pair<int,int> > > adj(n+1);
    int x,y,wt;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }
 
    int dist[n+1];
    bool vis[n+1];
    for(int i=1;i<=n;i++){
        dist[i]=1000001;
        vis[i]=false;
    }
 
    priority_queue<pair<int,int>, vector<pair<int,int> >,comp >pq;
 
    pq.push({1,0});
    dist[1]=0;
 
    int unvisited=n;
    long long ans=0;
    while(unvisited>0){
        if(pq.empty()==true)
            ans=0;
 
        int node =  pq.top().first;
        int w= pq.top().second;
        pq.pop();
        if(vis[node])
            continue;
        vis[node]=true;
        unvisited--;
        ans+=w;
 
        for(auto neighb : adj[node] ){
            if( neighb.second< dist[neighb.first] ){
                dist[neighb.first]=neighb.second;
                pq.push({neighb.first,neighb.second});
            }
        }
    }
    cout<<ans<<endl;
}
