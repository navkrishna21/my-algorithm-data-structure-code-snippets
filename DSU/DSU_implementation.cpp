// implementation of disjoint-set data structure (very efficient!)
 
// each "set" is a tree, and the "set representative" is the tree root
// hence, two nodes are in the same set if root(u) == root(v)
// initially, everything is in its own set. hence parent(node) = node


// to find the root, start from the node and keep going to parent[node]. stop when parent[node] = node.
// in addition, we set "parent[node] = root(node)" so that next time we look for root(node), we'll get there in 1 step!

#include<iostream>
using namespace std;

int par[100005];
int sz[100005];

int root(long long x){	//root finding function
    
    if(par[x]==x)
        return x;

    par[x]=root(par[x]);
    
	return par[x];
}


// to merge the sets, we can simply do parent[root(u)] = root(v)
// to ensure that tree heights are O(log n), we make the root of the smaller tree a child of the root of the larger tree
// (since a node's root can't change > log n times)
 
void un(int x,int y){ //union function
 
    x = root(x);
    y = root(y);
   
    if(sz[x]>sz[y]){
        sz[x]+=sz[y];
        par[y]=par[x];
    }
    else{
        sz[y]+=sz[x];
        par[x]=y;
    }
 
}

int main(){
    
    int nodes;
    cin>>nodes;

    for(int i=1;i<=nodes;i++){	
        par[i]=i;	//initially, everything is in its own set.
        sz[i]=1;	
    }

}
