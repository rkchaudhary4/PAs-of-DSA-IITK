#include<iostream>
using namespace std;

class Node{
    public:
        int x;
        Node *next;
};

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
            return -1;
        }

        int back(){
            return s[top];
        }
};

class list{
    public:
        Node* head;
        void addedge(int v){
            Node* new_node = new Node();
            new_node->x = v;
            new_node->next = head;
            head=new_node;
        }
        list(){
            head=NULL;
        }
};

void DFS1(int v, bool *visited, stack &arr, list *edge){
    visited[v]=true;
    for(auto i =edge[v].head; i!=NULL; i= i-> next){
        if(!visited[i->x]){
            DFS1(i->x, visited, arr, edge);
        }
    }
    arr.push(v);
}

void DFS2(int v, bool *visited, list *tedge, int &path){
    path++;
    visited[v]=true;
    for(auto i = tedge[v].head; i !=NULL; i = i-> next){
        if(!visited[i->x]){
            DFS2(i->x, visited,tedge, path);
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(;t;t--){
        long v,e;
        cin>>v>>e;
        int max=0;
        list edge[v];
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            edge[x].addedge(y);
        }
        stack arr;
        bool visited[v];
        for(int j=0;j<v;j++)visited[j]=false;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                DFS1(i,visited,arr,edge);
            }
        }
        list tedge[v];
        for(int i=0;i<v;i++){
            for(auto j = edge[i].head; j!= NULL; j = j -> next){
                tedge[j->x].addedge(i);
            }
        }
        for(int j=0;j<v;j++)visited[j]=false;
        while(!arr.empty()){
            int k = arr.pop();
            int path = 0;
            if(!visited[k]){
                DFS2(k, visited, tedge, path);
            }
            if(max<path)max=path;
        }
        cout<<max<<"\n";
    }
}