#include<iostream>
#include<vector>
using namespace std;

class stack{
    int s[1000000];
    int top=-1;

    public:         
        int empty(){
            return top==-1;
        }

        int full(){
            return top==1000000;
        }

        void push(int v){
            if(!full()){
                top++;
                s[top]=v;
            }
        }
        
        int pop(){
            if(!empty()){
                int x=s[top];
                top--;
                return x;
            }
        }

        int back(){
            return s[top];
        }
};

int main(){
    int street;
    cin>>street;
    for(;street;street--){
        int buildings;
        cin>>buildings;
        long height[buildings], span=1;
        for(int i=0;i<buildings;i++)cin>>height[i];
        stack s;
        s.push(0);
        for(int j=1;j<buildings;j++){
            cout<<span<<"\n";
            while(!s.empty() && height[j]>=height[s.back()]){
                s.pop();
            }
            if(s.empty()){
                s.push(j);
                span=j+1;
            }else{
                span=j-s.back();
                s.push(j);
            }
        }
        cout<<span<<"\n";
    }
    return 0;
}