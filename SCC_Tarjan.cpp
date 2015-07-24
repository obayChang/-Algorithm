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
int T; //時間戳記 
 
stack<int> Stack;
bool instack[N];
 
int component[N]; //每個點對應到的 強連通元件收縮成的點
int C; //強連通元件個數 
 
int n = 8;
 
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

int main (){
    /*initial the diagram*/
	edge[1].push_back(2);
	edge[1].push_back(8);
	edge[2].push_back(3);
	edge[3].push_back(4);
	edge[3].push_back(6);
	edge[4].push_back(5);
	edge[5].push_back(1);
	edge[6].push_back(7);		
	edge[7].push_back(3);
	Tarjan();
	cout << C << endl;
    return 0;   
}
