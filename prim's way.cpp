#include<iostream>
#define V 5
using namespace std;


bool mstset[V];//用于记录是否已经在已经构造的mst树里面
int Parent[V];//用于记录构造的mst
int minkey[V];//用于确定需要选择的最小的不包含在已经构造的mst的值

//获得最小值
int GetMin()
{
    int k=-1;
    int min=INT32_MAX;
    for(int i=0;i<V;i++)
        if(!mstset[i]&&minkey[i]<min)
          k=i,min=minkey[i];
     return k;
}

void MST(int graph[V][V])
{
    for(int i=0;i<V;i++)
        mstset[i]=false,minkey[i]=INT32_MAX;
    Parent[0]=-1;//可以确定任意的起点作为root
    minkey[0]=0;//设置为零，必定会在第一次选择被挑出来
    for(int i=0;i<V;i++)
    {
        int u=GetMin();
        mstset[u]=true;//设置选出来的最小值的节点为一构造
        for(int j=0;j<V;j++)
            if(!mstset[j]&&graph[u][j]<minkey[j])
                Parent[j]=u,minkey[j]=graph[u][j];
    }
    for(int i=0;i<V;i++)
        cout<<Parent[i]<<" "<<i<<endl;
}

int main()
{
    int graph[V][V] = {{INT32_MAX, 2, INT32_MAX, 6, INT32_MAX},
                       {2, INT32_MAX, 3, 8, 5},
                       {INT32_MAX, 3, INT32_MAX, INT32_MAX, 7},
                       {6, 8, INT32_MAX, INT32_MAX, 9},
                       {INT32_MAX, 5, 7, 9, INT32_MAX}};
    //不能到达设置为int32_max
    MST(graph);
}
