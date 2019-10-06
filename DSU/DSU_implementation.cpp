int fn(long long x,int*par){
    
	if(par[x]==x)
        return x;

    par[x]=fn(par[x],par);
    
	return par[x];
}
 
void un(int x,int y,int*par,int*sz){
 
    x = fn(x,par);
    y = fn(y,par);
   
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

    int par[nodes+1];
    int sz[nodes+1];

    for(int i=1;i<=nodes;i++){
        par[i]=i;
        sz[i]=1;
    }
