/***********************************************
Name: Ankit Amrit Raj
CodeChef Handle : ankitamritraj 
Date: 05/09/2016
***********************************************/

/***********************************************
Prerequisites :
1. Queues
2. Adjacency List 
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
#include <queue>

using namespace std;

#define lli long long int
#define mod 1e9+7
#define f(i,x,n) for(i=x;i<n;i++)
#define vlli vector<lli>
#define pb push_back

lli visited[100];
vlli adjacency_list[100];

void BFS(lli start)
{
	queue<lli> travel;
	lli temp,i;
	travel.push(start);
	visited[start]=1;
	while(!travel.empty())
	{
		temp=travel.front();
		cout<<temp<<" ";				// Printing the traversed node order
		travel.pop();
		f(i,0,adjacency_list[temp].size())
		{
			if(visited[adjacency_list[temp][i]]!=1)
			{
				travel.push(adjacency_list[temp][i]);
				visited[adjacency_list[temp][i]]=1;		
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	lli nodes,a,b,i;
	cin>>nodes;
	
	f(i,0,nodes-1)
	{	
		cin>>a>>b;
		adjacency_list[a].pb(b);
		adjacency_list[b].pb(a);
	}
	BFS(1);       // Start BFS from Node 1.
	
	return 0;
}