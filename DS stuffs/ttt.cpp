/*Program for traversing a directed graph through BFS*/
#include<bits/stdc++.h>
#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

using namespace std;
queue<int>q;

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/

void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front=-1,rear=-1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

main()
{
	create_graph();
	BF_Traversal();
}/*End of main()*/

void BF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
		state[v]=initial;

	cout<<"\nEnter starting vertex for Breadth First Search : \t";
	cin>>v;

	BFS(v);
	for(v=0; v<n; v++)
		if(state[v] == initial)
			BFS(v);
}/*End of BF_Traversal()*/

void BFS(int v)
{
	int i;

	insert_queue(v);
	state[v]=waiting;

	while(! q.empty() )
	{
		v=q.front();
		v = delete_queue( );
		cout<<"  "<<v;
		state[v] = visited;
		for(i=0; i<n; i++)
		{
			/* Check for adjacent unvisited vertices */
			if( adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}

	cout<<endl;
}/*End of BFS()*/

void insert_queue(int vertex)
{
	q.push(vertex);
}/*End of insert_queue()*/


int delete_queue()
{
	int del_item;

	del_item=q.front();

	q.pop();
	return del_item;

}/*End of delete_queue() */

void create_graph()
{
	int i,max_edges,origin,destin;

	cout<<"\nEnter number of vertices : ";
	cin>>n;
	max_edges = n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		cout<<"Enter edge %d( -1 -1 to quit ) : "<<i;
		cin>>origin>>destin ;

		if((origin == -1) && (destin == -1))
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			cout<<"Invalid edge!\n";
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	}/*End of for*/
}/*End of create_graph()*/

