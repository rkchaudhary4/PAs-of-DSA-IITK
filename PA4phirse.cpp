#include<iostream>
using namespace std;

class Edge{
    public:
        int x,y,w;
};

class Graph{
    public:
        int v,e;
        Edge* edge;
        int last=0;
        Graph(int v1, int e1){
            v=v1, e=e1;
            edge = new Edge[e1];
        }
        void inline addedge(int s, int d, int we){
            edge[last].x=s;
            edge[last].y=d;
            edge[last++].w=we;
        }

        void inline swap(Edge &a, Edge& b){
            Edge c=a;
            a=b;
            b=c;
        }

        int inline partition(int p, int r){
            int i=p-1, key = edge[r].w;
            for(int j=p;j<r;j++){
                if(edge[j].w<=key){
                    swap(edge[i+1], edge[j]);
                    i++;
                }
            }
            swap(edge[r], edge[i+1]);
            return i+1;
        }

        int inline randomizedPartition(int p, int r){
            int k=p+(rand()%(r-p+1));
            swap(edge[k],edge[r]);
            return partition(p,r);
        }

        void inline sort(int p, int r){
            if(p<r){
                int q =  partition(p,r);
                sort(p,q-1);
                sort(q+1,r);
            }
        }
};

class Node{
    public:
        int rank=0, parent;
};

int inline find(Node* sets, int x){
    int y=x;
    while(y!=sets[y].parent)y=sets[y].parent;
    int r=y;
    y=sets[x].parent;
    while(y!=sets[y].parent){
        sets[x].parent = r;
        x=y;
        y=sets[y].parent;
    }
    return y;
}

void inline uni(Node* sets, int x, int y){
    int rx= find(sets, x), ry = find(sets,y);
    if(rx==ry)return;
    if(sets[rx].rank > sets[ry].rank){
        sets[ry].parent = rx;
    }else if(sets[rx].rank<sets[ry].rank){
        sets[rx].parent=ry;
    }else{
        sets[ry].parent = rx;
        sets[rx].rank++;
    }
}

int main(){
    int v,e,q;
    long long mst=0;
    scanf("%d %d %d", &v, &e, &q);
    Graph g(v,e);
    Graph g1(v,v);
    for(int i=0;i<e;i++){
        int x,y,we;
        scanf("%d %d %d", &x, &y, &we);
        g.addedge(x,y,we);
    }
    g.sort(0,e-1);
    Node sets[v];
    for(auto i=0;i<v;i++)sets[i].parent=i;
    for(auto i=0;i<e;i++){
        int x = g.edge[i].x, y = g.edge[i].y, w = g.edge[i].w;
        if(find(sets, x) != find(sets, y)){
            g1.addedge(x, y, w);
            mst+=w;
            uni(sets,x, y);
        }
        if(g1.last==v-1)break;
    }
    g=g1;
    printf("%llu\n", mst);
    for(;q;q--){
        mst=0;
        int x,y,we;
        scanf("%d %d %d", &x, &y, &we);
        g.addedge(x,y,we);
        g.sort(0,v-1);
        Node sets[v];
        for(auto i=0;i<v;i++)sets[i].parent=i;
        Graph g1(v, v);
        for(auto i=0;i<v;i++){
            int x = g.edge[i].x, y = g.edge[i].y, w = g.edge[i].w;
            if(find(sets, x) != find(sets, y)){
                g1.addedge(x, y, w);
                mst+=w;
                uni(sets,x, y);
            }
        }
        g=g1;
        printf("%llu\n", mst);
    }
    return 0;
}