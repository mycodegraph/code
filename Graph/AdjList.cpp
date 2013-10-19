#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int num;
    vector<Node *> links;
};

int main()
{
    int n;
    cin >>n;

    vector<Node *> graph;
    graph.resize(2*n+1);

/**
@Def: Taking input per edge(a<=>b) and creating graph.
@Type: Can hold both directed and undirected graphs.
@Structure:
    |_1_|=>|_|_|_| (<=list of pointers to all verices node 1 is connected to and similar lists exists for other nodes as well)
    |_2_|=>|_|_|
    |_3_|=>|_|
    |_4_|=>|_|_|_|_|

@Size: Graph size is one more than double of n.

**/
    for(int i=0;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        if(graph[a] ==  NULL){graph[a]=new Node(); graph[a]->num = a;}
        if(graph[b] ==  NULL){graph[b]=new Node(); graph[b]->num = b;}
        graph[a]->links.resize(graph[a]->links.size()+1);
        graph[b]->links.resize(graph[b]->links.size()+1);

        graph[a]->links[graph[a]->links.size()-1]=graph[b];
        graph[b]->links[graph[b]->links.size()-1]=graph[a];
    }

    /**Printing the Graph**/
    for(int i=1;i<2*n+1;++i) if(graph[i] != NULL)
    {
        cout<<graph[i]->num<<": ";
        vector<Node *> vec = graph[i]->links;
        for(int j=0;j<vec.size();++j) cout<<vec[j]->num<<" ";
        cout<<endl;
    }
    else
        cout<<i<<": NULL\n";
}
