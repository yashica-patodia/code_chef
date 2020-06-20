#include<cstdio>
#include<vector>
 
using namespace std;
 
vector<vector<int> > graph(200001, vector<int>(0));
vector<int> color(200001, -1);
int max_distance = -1;
int farthest_node = 0;
 
void dfs(int src, int par, int dist)
{
	if(dist > max_distance)
	{
		max_distance = dist;
		farthest_node = src;
	}
 
	for(int i=0;i<graph[src].size();i++)
	{
		if(graph[src][i]!=par)
		{
			dfs(graph[src][i], src, dist + int(color[graph[src][i]]!=color[src]));
		}
	}
}
 
int main()
{
	int N, node1, node2;
 
	scanf("%d", &N);
 
	for(int i=1;i<=N;i++)
	{
		scanf("%d", &color[i]);
	}
 
	for(int i=1;i<N;i++)
	{
		scanf("%d%d", &node1, &node2);
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
 
	dfs(1, 1, 0);
	max_distance = -1;
	dfs(farthest_node, farthest_node, 0);
	printf("%d\n", (max_distance+1)/2);
 
	return 0;