#include<iostream>
using namespace std;

int t=0;

class Node{
    public:
        int x;
        Node* next;
};

class list{
    public:
        Node* head;
        bool incycle;
        void addedge(int v){
            Node* newNode = new Node();
            newNode->x=v;
            newNode->next = head;
            head = newNode;
            incycle = false;
        }
        list(){
            head = NULL;
            incycle=false;
        }
        int length(){
            int count=0;
            for(Node* i=head;i!=NULL;i=i->next){
                count++;
            }
            return count;
        }
        void sortlist(){
            int n = length();
            for(int i=0;i<n;i++){
                for(auto j=head;j->next!=NULL;j=j->next){
                    if(j->x>j->next->x){
                        int temp = j->x;
                        j->x=j->next->x;
                        j->next->x=temp;
                    }
                }
            }
        }
};

class Graph{
    public:
        int v,e;
        list *adj;
        Graph(int x){
            v=x;
            adj = new list[v];
        }
        void DFS(int v, bool* visited, int* d, int* low, int* parent){
            visited[v]=true;
            d[v]=t;
            low[v]=t++;
            for(auto i=adj[v].head;i!=NULL;i = i->next){
                if(!visited[i->x]){
                    parent[i->x]=v;
                    DFS(i->x, visited, d, low, parent);
                    low[v]=min(low[v],low[i->x]);
                    if(low[i->x]>d[v]){
                        cout<<min(v,i->x)<<" "<<max(v,i->x)<<"\n";
                    }
                }else if( i->x!=parent[v]){
                    low[v] = min(low[v],d[i->x]);
                }
            }
        }
};

int main(){
    int v,e;
    cin>>v>>e;
    Graph g(v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g.adj[x].addedge(y);
        g.adj[y].addedge(x);
    }
    bool visited[v];
    int d[v], low[v], parent[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        d[i]=999999, low[i]=99999, parent[i]=-1;
        g.adj[i].sortlist();
    }
    for(int i=v-1;i>=0;i--){
        if(!visited[i]){
            g.DFS(i, visited, d, low, parent);
        }
    }    
}   