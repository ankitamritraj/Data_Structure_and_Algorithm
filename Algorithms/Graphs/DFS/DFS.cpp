/***********************************************
Prerequisites :
1. Stacks
2. Adjacency List 
3. Stacks
4. C++ STL 
***********************************************/

/***********************************************
Complexity :
Time  : O(V+E) 
Space : O(V+E)
***********************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define lli long long int
#define mod 1e9+7
#define f(i,x,n) for(i=x;i<n;i++)
#define vlli vector<lli>
#define pb push_back

lli visited[100]={0};
lli visited_recursive[100]={0};
vlli adjacency_list[100];

void DFS_Stack(lli start_node)   					// DFS implementation using Stacks
{
	stack<lli> travel;
	lli i;
	travel.push(start_node);
	lli temp;
	while(!travel.empty())
	{
		temp=travel.top();
		visited[temp]=1;
		travel.pop();
		cout<<temp<<" ";
		f(i,0,adjacency_list[temp].size())
		{
			if(visited[adjacency_list[temp][i]]!=1)
			{
				travel.push(adjacency_list[temp][i]);
			}	
		}
	}
}

void DFS_Recurcive(lli start_node)					// Recursive method to implement DFS
{
	lli i;
	f(i,0,adjacency_list[start_node].size())
	{
		if(visited_recursive[adjacency_list[start_node][i]]!=1)
		{
			visited_recursive[adjacency_list[start_node][i]]=1;
			cout<<adjacency_list[start_node][i]<<" ";
			DFS_Recurcive(adjacency_list[start_node][i]);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	lli nodes,a,b,i;
	cin>>nodes;
	
	f(i,0,nodes-1)									// Change number of edges input accordingly
	{	
		cin>>a>>b;
		adjacency_list[a].pb(b);
		adjacency_list[b].pb(a);
	}

	DFS_Stack(1);									// Taking node 1 as the Start Node
	cout<<endl;
	visited_recursive[1]=1;
	DFS_Recurcive(1);								// Taking node 1 as the start Node
	return 0;
}