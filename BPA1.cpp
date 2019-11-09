#include<iostream>
#include<climits>
using namespace std;

long steps(int* matrices, int k){
    int s[k][k];
    for(auto i=0;i<k;i++)s[i][i]=0;
    for(auto l=2;l<k;l++){
        for(auto i=1;i<k-l+1;i++){
            auto j=i+l-1;
            s[i][j]=INT_MAX;
            for(auto p=i; p <= j-1; p++){
                auto q = s[i][p] + s[p+1][j]+ matrices[i-1]*matrices[p]*matrices[j];
                if(q<s[i][j])s[i][j]=q;
            }
        }
    }
    return s[1][k-1];
}

int main(){
    int t;
    cin>>t;
    for(;t;t--){
        int k;
        cin>>k;
        int matrices[k+1];
        for(auto i=0;i<k+1;i++)cin>>matrices[i];
        cout<<steps(matrices, k+1)<<"\n";
    }
    return 0;
}