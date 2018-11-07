#include<iostream>
#include<algorithm>
using namespace std;

struct Edge {

    int src,des,weight;

};

struct Graph   //构建图
{
    int V;   //储存vertice的个数
    int E;   //储存edge的个数
    Edge *edge;
};
//disjoint_set 的find函数
int Find_Root(int array[],int i)
{
    while(array[i]!=i)
    {
        array[i]=array[array[i]];
        i=array[i];
    }
    return i;
}

//disjoint_set 的union函数

void Union(int array[],int size[],int a,int b)
{
    int aroot=Find_Root(array,a);
    int broot=Find_Root(array,b);
    if(size[aroot]>size[broot])
    {
        array[broot]=aroot;
        size[aroot]+=size[broot];
    }
    else
    {
        array[aroot]=broot;
        size[broot]+=size[aroot];
    }
}

bool less_cmp(Edge a,Edge b)
{
    return a.weight<b.weight;
}

void MST(Graph graph,int array[],int size[],Edge *&edge)
{
    sort(graph.edge,graph.edge+graph.E,less_cmp);
    int e=0; //用于保存已经处理的edge数
    int v=0; //用于保存已经放入MST的树
    edge=new Edge[graph.E];
    while(v<graph.V-1)
    {
        Edge temp = graph.edge[e++];
        int aRoot = Find_Root(array, temp.src);
        int bRoot = Find_Root(array, temp.des);
        if (aRoot != bRoot) {
            Union(array, size, aRoot, bRoot);
            edge[v++] = temp;
        }
    }
}

int main()
{
    Graph graph;
    graph.V=4;
    graph.E=5;
    // add edge 0-1
    graph.edge=new Edge[5];
    graph.edge[0].src = 0;
    graph.edge[0].des = 1;
    graph.edge[0].weight = 10;

    // add edge 0-2
    graph.edge[1].src = 0;
    graph.edge[1].des = 2;
    graph.edge[1].weight = 6;

    // add edge 0-3
    graph.edge[2].src = 0;
    graph.edge[2].des = 3;
    graph.edge[2].weight = 5;

    // add edge 1-3
    graph.edge[3].src = 1;
    graph.edge[3].des = 3;
    graph.edge[3].weight = 15;

    // add edge 2-3
    graph.edge[4].src = 2;
    graph.edge[4].des = 3;
    graph.edge[4].weight = 4;
    Edge* edge;
    int array[4];
    for(int i=0;i<4;i++)
        array[i]=i;
    int size[4];
    for(int i=0;i<4;i++)
        size[i]=1;
    MST(graph,array,size,edge);
    for(int i=0;i<graph.V-1;i++)
    {
        cout<<edge[i].src<<" "<<edge[i].des<<" "<<edge[i].weight<<endl;
    }

}
