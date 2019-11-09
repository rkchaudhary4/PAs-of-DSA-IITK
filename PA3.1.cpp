#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(;n;n--){
        int v, flag=0,x,y;
        long long e;
        cin>>v>>e;
        int part[v+1];
        for(int i=0;i<=v;i++)part[i]=0;
        for(;e;e--){
            cin>>x>>y;
            if(part[x]==part[y] && part[x]){
                cout<<"No"<<"\n";
                flag=1;
                break;
            }else if(part[x]==1 && !part[y]){
                part[y]=2;
            }else if(part[x]==2 && !part[y]){
                part[y]=1;
            }else if(part[y]==1 && !part[x]){
                part[x]=2;
            }else if(part[y]==2 && !part[x]){
                part[x]=1;
            }else{
                part[x]=1;
                part[y]=2;
            }    
        }
        if(e)for(e--;e;e--)cin>>x>>y;
        if(!flag)cout<<"Yes"<<"\n";
    }
    return 0;
}