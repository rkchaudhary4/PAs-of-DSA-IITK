#include<iostream>
#include<limits.h>
using namespace std;

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*(i+1);
}

int parent(int i){
    return (i-1)/2;
}

class AdjNode{
    public:
        int x, w;
        AdjNode* next;
};

class HeapNode{
    public:
        int x, p=INT_MAX;
};

class list{
    public:
        AdjNode* head;
        void addedge(int v, int w){
            AdjNode* new_node = new AdjNode();
            new_node->x = v;
            new_node->w=w;
            new_node->next=head;
            head=new_node;
        }
        list(){
            head = NULL;
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
};

class Heap{
    public:
        HeapNode a[2500];
        int size=-1;
        int pos[2500];
        void addnode(int v){
            HeapNode temp;
            temp.x=v;
            a[++size] = temp;
            pos[temp.x]=size;
        }

        void swap(int x, int y){
            HeapNode temp = a[x];
            a[x]=a[y];
            a[y]=temp;
            pos[a[x].x]=x;
            pos[a[y].x]=y;
        }

        void heapify(int i){
            int min_index;
            if(left(i)>size)return;
            if(a[i].p>a[left(i)].p)min_index=left(i);
            else min_index = i;
            if(right(i) <= size){
                if(a[right(i)].p < a[min_index].p )min_index=right(i);
            }
            if(min_index != i){
                swap(i,min_index);
                heapify(min_index);
            }
        }
        void minheap(){
            int n=size;
            for(int i=n/2;i>=0;i--){
                heapify(i);
            }
        }

        HeapNode extract_min(){
            int n=size;
            HeapNode min = a[0];     
            swap(0,n);
            size--;
            heapify(0);
            return min;
        }

        void Decrease_Key(int i){
            int j=i;
            while(j>0 && a[parent(j)].p > a[j].p){
                swap(parent(j),j);
                j=parent(j);
            }
        }
};

int main(){
    int v,e;
    scanf("%d %d", &v, &e);
    Graph g(v);
    for(auto i=0;i<e;i++){
        int x,y,w;
        scanf("%d %d %d\n", &x,&y, &w);
        g.adj[x].addedge(y,w);
    }
    int s,t;
    scanf("%d %d", &s, &t);
    Heap h;
    for(auto i=0;i<v;i++){
        h.addnode(i);
        if(i==s)h.a[h.size].p=0;
    }
    h.minheap();
    while(h.size != -1){
        HeapNode u = h.extract_min();
        if(u.x==t){
            cout<<u.p;
            return 0;
        }
        AdjNode* head = g.adj[u.x].head;
        while(head !=NULL){
            int pos = h.pos[head->x];
            if(h.a[pos].p > u.p + head->w){
                h.a[pos].p = u.p + head->w;
                h.Decrease_Key(pos);
            }
            head=head->next;
        }
    }
    return 0;
}