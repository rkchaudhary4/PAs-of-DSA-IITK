#include<iostream>
using namespace std;

int binarySearch(long long arr[], int l, int r, long long target){
    if(l>r)return -1;
    int m=(l+r)/2;
    if(arr[m]==target)return m;
    if(arr[m]>target)return binarySearch(arr,l,m-1,target);
    else return binarySearch(arr,m+1,r,target);
}

int pivot(long long arr[],int l, int r,int n){
    if(l==r)return l;
    int m=(l+r)/2;
    if(arr[(m-1+n)%n]>arr[m])return m;
    if(arr[m]>arr[m+1])return m+1;
    if(arr[l]>=arr[m])return pivot(arr, l, m-1,n);
    return pivot(arr,m+1,r,n);
}

int main(){
    int t;
    cin>>t;
    for(;t;t--){
        int n;
        cin>>n;
        long long arr[n], target;
        for(int i=0;i<n;i++)cin>>arr[i];
        cin>>target;
        int p;
        if(arr[0]<arr[n-1])p=0;
        else p=pivot(arr,0,n-1,n);
        int index;
        if(arr[n-1]<target)index=binarySearch(arr,0,p-1,target);
        else index=binarySearch(arr,p,n-1,target);
        cout<<index;
    }
    return 0;
}