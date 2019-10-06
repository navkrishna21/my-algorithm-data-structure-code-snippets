#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef vector<vector<long long>> matrix;
 
matrix mul(matrix a,matrix b){
    int r=a.size();
    int c=b[0].size();
    int k=b.size();
 
    matrix ans(r,vector<long long>(c));
 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans[i][j]=0;
            for(int l=0;l<k;l++)
                ans[i][j] =(ans[i][j]+(a[i][l]*b[l][j])%MOD)%MOD;
        }
    }
 
    return ans;
}
 
matrix add(matrix a,matrix b){
    int n=a.size();
    matrix ans(n,vector<long long>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans[i][j]=a[i][j]+b[i][j];
    return ans;
}
 
 
matrix sub(matrix a,matrix b){
    int n=a.size();
    matrix ans(n,vector<long long>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans[i][j]=a[i][j] - b[i][j];
 
    return ans;
}
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long long m,n;
        cin>>m>>n;
 
        matrix mat(m,vector<long long>(m));
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                cin>>mat[i][j];
 
        matrix ans;
        bool flag=false;
 
        while(n!=0){
            if(n%2==1)
                if(flag==false){
                    ans=mat;
                    flag=true;
                }
                else
                    ans=mul(ans,mat);
 
            mat=mul(mat,mat);
            n=n/2;
        }
 
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
 
    }
}
 
 
 
