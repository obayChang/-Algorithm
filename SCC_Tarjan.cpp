#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
#define N 100001
 
vector<int> edge[N];
int dfn[N];
int low[N];
int T; // tag
 
stack<int> Stack;
bool instack[N];
 
int component[N]; the component belong to whtat point
int C; // # of SCC 
 
int n;
 
void DFS(int u)
{
 
    dfn[u] = low[u] = ++ T;
    Stack.push(u);
    instack[u] = true;
 
    for(int i = 0; i < edge[u].size(); i ++)
    {
        int v = edge[u][i];
 
        if(!dfn[v])
        {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u], dfn[v]); 
 
    }
 
    if(dfn[u] == low[u])
    {
        int t;
 
        C ++;
 
        do
        {
            t = Stack.top(); Stack.pop();
            instack[t] = false;
            component[t] = C;
 
        }while(t != u);
 
    }
}
 
void Tarjan()
{
	/*initial the diagram*/
	edge[1][0] = 2;
	edge[1][1] = 6;
	edge[2][0] = 3;
	edge[3][0] = 4;
	edge[3][1] = 6;
	edge[4][0] = 5;
	edge[5][0] = 1;
	edge[6][0] = 7;		
	edge[7][0] = 3;		
	
    for(int i = 1; i <= n; i ++)
    {
        dfn[i] = 0;
        instack[i] = false;
    }
    while(Stack.size()) Stack.pop();
 
    T = 0;
    C = 0;
 
    for(int u = 1; u <= n; u ++)
    {
        if(!dfn[u])
            DFS(u);
    }
}
