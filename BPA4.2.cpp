#include<iostream>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(;t;t--){
        int m, n;
        scanf("%d %d\n", &m,&n);
        char str1[m], str2[n];
        for(int i=0;i<m;i++)str1[i] = getchar();
        getchar();
        for(int i=0;i<n;i++)str2[i]=getchar();
        int r1[n+1], r2[n+1];
        for(auto i=0;i<n+1;i++){
            r1[i]=0;
            r2[i]=0;
        }
        for(auto i=1;i<=m;i++){
            for(auto k=0;k<n+1;k++)r1[k]=r2[k];
            for(auto j=0;j<=n;j++){
                if(i==0||j==0)r2[j]=0;
                else if(str1[i-1]==str2[j-1]){
                    r2[j]=r1[j-1]+1;
                }else{
                    r2[j]= r1[j]>r2[j-1]?r1[j]:r2[j-1];
                }
            }
        }
        cout<<r2[n]<<"\n";
    }
    return 0;
}