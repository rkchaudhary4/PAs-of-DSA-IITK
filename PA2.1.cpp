#include<iostream>
#include<vector>
#include<map>
using namespace std;

class stack{
    char s[1000];
    int top=-1;

    public:         
        int empty(){
            return top==-1;
        }

        int full(){
            return top==1000;
        }

        void push(char v){
            if(!full()){
                top++;
                s[top]=v;
            }
        }
        
        int pop(){
            if(!empty()){
                char x=s[top];
                top--;
                return x;
            }else return -1;
        }

        int back(){
            return s[top];
        }
};

int main(){
    map<char, int> precedence;
    precedence['(']=6;
    precedence['^']=5;
    precedence['/']=4;
    precedence['*']=3;
    precedence['+']=2;
    precedence['-']=1;
    vector<char> infix;
    vector<char> postfix;
    char temp;
    while(cin>>temp){
        infix.push_back(temp);
    }
    stack s;
    for(auto i=0;i<infix.size();i++){
        if((infix[i]>='A' && infix[i]<='Z')||(infix[i]>='a' && infix[i]<='z')||(infix[i]>='0' && infix[i]<='9'))postfix.push_back(infix[i]);
        else if(infix[i]=='(')s.push(infix[i]);
        else if(infix[i]==')'){
            while(!s.empty() && s.back()!='('){
                postfix.push_back(s.pop());
            }
            s.pop();
        }else{
            while(!s.empty() && precedence[s.back()]>=precedence[infix[i]] && s.back()!='('){
                postfix.push_back(s.pop());
            }
            s.push(infix[i]);
        }
    }
    while(!s.empty()){
        postfix.push_back(s.pop());
    }
    for(auto p=postfix.begin(); p!=postfix.end();p++)cout<<*p;
    return 0;
}