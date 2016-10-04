/*input
1
3 3
1 2 1
1 3 4
2 3 2
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
using namespace std;

#define lli long long int
#define mod 1e9+7
#define f(i,x,n) for(i=x;i<n;i++)
#define vlli vector<lli>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

typedef pair<lli, lli> Plli;

bool visited[1000];
lli dist[1000];
lli parent[1000];
lli edges;
vector<Plli> graph[1000];

void initialize()
{
	lli i;
	f(i,0,1000)
	{
		dist[i]=10000000000;
	}
}

void Dijkstra(lli x)
{
	priority_queue< Plli, vector<Plli>, greater<Plli> > Q;
	Plli temp;
	lli i,y;
	// cout<<"flakj";
	Q.push(mp(0,x));
	while(!Q.empty())
	{
		temp=Q.top();
		x=temp.second;
		Q.pop();
		if(visited[x]==true)
			continue;
		visited[x]=true;
		// cout<<"dist(x)["<<x<<"] "<<dist[x]<<endl;
		f(i,0,graph[x].size()) 
		{
			y=graph[x][i].second;
			if(visited[y]==false)
			{
				// cout<<"x="<<x<<"  y="<<y<<" dist["<<x<<"] "<<dist[x]<<"  dist["<<y<<"] "<<dist[y]<<" ";
				// cout<<"distance "<<x<<" to "<<y<<" :"<<graph[x][i].first<<endl;
				if(dist[y] > dist[x] + graph[x][i].first)
				{
					// cout<<"hello____"<<endl;
					dist[y] = dist[x] + graph[x][i].first;	
					// cout<<"dist["<<y<<"] "<<dist[y]<<endl;
					Q.push(mp(dist[y],y));
				}
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	lli test;
	cin>>test;
	while(test--)
	{
		lli n,i,a,b,weight;
		cin>>n>>edges;
		initialize();
		// cout<<dist[3];
		f(i,0,edges)
		{
			cin>>a>>b>>weight;
			graph[a].pb(mp(weight,b));
			graph[b].pb(mp(weight,a));
		}
		int start,end;
		cin>>start>>end;
		dist[start]=0;
		Dijkstra(1);
		// cout<<"hllo";
		// cout<<n<<" "<<edges;
		f(i,1,n+1)
		{
			cout<<dist[i]<<" ";
		}
	}
	return 0;
}