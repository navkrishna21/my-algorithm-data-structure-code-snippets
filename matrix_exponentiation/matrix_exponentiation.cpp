#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef vector<vector<long long>> matrix; //matrix is defined as vector of vector
 
//function declarations for matrix multiplication, addition, subtraction and, identity matrix
matrix mul(const matrix &,const matrix &);
matrix add(const matrix &,const matrix &);
matrix sub(const matrix &,const matrix &);
matrix identity_matrix(long long);

int main(){
    int t;
    cin>>t;
    while(t--){
        long long m,n;
        cin>>m>>n;
 
        matrix mat(m,vector<long long>(m)); //initialize a matrix of m X m
     
        //input matrix
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                cin>>mat[i][j];
 
        matrix ans = identity_matrix(m); //initialize answer with unit matrix of size m X m
 
        //logarithmic expontiation
        while(n!=0){
            if(n%2==1)
                    ans=mul(ans,mat);
 
            mat = mul(mat,mat);
            n=n/2;
        }
        
        //output
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
 
    }
}
 
 

matrix mul(const matrix &a,const matrix &b){ //matrix multiplication function
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
 
matrix add(const matrix &a,const matrix &b){ //matrix addition function
    int n=a.size();
    matrix ans(n,vector<long long>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans[i][j]=a[i][j]+b[i][j];
    return ans;
}
 
 
matrix sub(const matrix &a,const matrix &b){ //matrix subtraction function
    int n=a.size();
    matrix ans(n,vector<long long>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans[i][j]=a[i][j] - b[i][j];
 
    return ans;
}
 
matrix identity_matrix(long long size){
 
    matrix ans(size,vector<long long>(size));
 
    for(int i=0;i<size;i++){
         ans[i][i]=1;
    } 
    return ans;
}
