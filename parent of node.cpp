#include<iostream>

using namespace std;

struct node {
	int child;
	int parent;
	int weight;
};

int find(int vertex, node nodes[],int e) 
{
	for(int i=0; i<e; i++) 
	{
		if (nodes[i].child==vertex) 
		{
			return nodes[i].parent;
		}
	}
} 


int assign_parent(int vertex1, node nodes[], int i)
{
	for (int j=0; j<=i; j++) 
	{
		if (nodes[j].child==vertex1) 
		{
			return (nodes[j].parent);
		}
	}
	
	return 0;
}

int main()
{
	node nodes[20];
	int i, j, k, e, vertex1, vertex;
	cout << "Enter the no of edges in your tree\n";
	cin >> e;
	for (i=0; i<e; i++) {
		cout << "Enter the weight of the edge\n";
		cin >> nodes[i].weight;
		cout << "Enter the vertice 1\n";
		cin >> vertex1;
		nodes[i].parent = assign_parent(vertex1, nodes, i);
		if (nodes[i].parent==0) {
			nodes[i].parent=vertex1;
		}
		cout << "Enter the vertice 2\n";
		cin >> nodes[i].child;
	}
	
	cout << "Enter the vertex whose parent is to be found\n";
	cin >> vertex;
	cout << find(vertex, nodes, e);
}
