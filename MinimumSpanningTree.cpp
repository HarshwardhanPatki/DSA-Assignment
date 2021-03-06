#include <iostream>
using namespace std;
class spanningTree
{
    public:
    int a[10][10];
    int sp[10][10];
    int V,E,infinity,min_cost;
    spanningTree()
    {
        infinity =99;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                a[i][j]=0;
                sp[i][j]=0;
            }
        }
    }
    void createGraph();
    void displayGraph();
    void Prims();
    void display_spanningTree();
};
void spanningTree::createGraph()
{
    int i,j;
    char ch;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    do
    {
        cout<<"Enter the Edges: ";
        cin>>i>>j;
        cout<<"Enter the weight of the edge "<<i<<" to "<<j<<" : ";
        cin>>a[i][j];
        a[j][i]=a[i][j];
        cout<<"Want to insert another edge(y/n): ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}
void spanningTree :: displayGraph()
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void spanningTree :: Prims()
{
    int cost[10][10],distance[10],source[10];
    int visited[10];
    int u,mindist,v;
    //creating cost matrix
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(a[i][j]==0)
            {
                cost[i][j]=infinity;
            }
            else
            {
                cost[i][j]=a[i][j];
            }
        }
    }
    //starting from vertex 0
    distance[0]=0;
    visited[0]=1;
    //calculating distance from vertex 0
    for(int i=1;i<V;i++)
    {
        distance[i]=cost[0][i];
        source[i]=0;
        visited[i]=0;
    }
    min_cost =0;
    E=V-1;
    while(E--)
    {
        mindist =infinity;
        for(int i=1;i<V;i++)
        {
            if(visited[i]==0 && distance[i]<mindist)
            {
                mindist =distance[i];
                v=i;
            }
        }
     u=source[v];
     sp[u][v]=distance[v];
     sp[v][u]=distance[v];
     visited[v]=1;
     for(int i=1;i<V;i++)
     {
         if(visited[i]==0 && cost[i][v]<distance[i])
         {
             distance[i]=cost[i][v];
             source[i]=v;
         }
     }
     min_cost = min_cost + cost[u][v];
    }
    cout<<"Minimum weight of the spanning tree is: "<<min_cost<<endl;
}
void spanningTree :: display_spanningTree()
{
    cout<<"Displaying the spanning tree"<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<sp[i][j]<<"\t";
        }
        cout<<endl;
    }
   
}

int main()
 {
    spanningTree t1;
    t1.createGraph();
    t1.displayGraph();
    t1.Prims();
    t1.display_spanningTree();
    return 0;
}