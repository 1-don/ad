//Ass 3-B: Graph representation using Adjacency List


#include<iostream>
using namespace std;

class gnode
{
    public:
	    int vertex;
	    gnode *next;
};

class graph
{
	private:
		gnode *head[10];
		int visited[10];
	public:
		static int cnt;
		graph()
		{
			int v1;
			for(v1=0;v1<10;v1++)
				visited[v1] = false;
			for(v1=0;v1<10;v1++)
				head[v1]=NULL;
		}
		void create();
		//void display();
		void DFS(int);

}; 	

void graph::create()
{
	int v1,v2;	
	char ans='y';
	gnode *temp,*first;
	cout<<"\n\t Enter the vertices beginning with 0";
	do
	{	
		cout<<"\n\t Enter the end vertices of the edge:\n";
		cin>>v1>>v2;
		if( v1>=10 || v2>=10)
			cout<<"\n Invalid Vertex \n";
		else
		{
			temp = new gnode;
			if(temp == NULL)
				cout<<"\n\t Insufficient Memory";
			temp->vertex = v2;
			temp->next = NULL;
			first = head[v1];
			if(first == NULL)
				head[v1] = temp;
			else
			{
				while(first->next!= NULL)
					first = first->next;
				first->next = temp;
			}
			temp = new gnode;
			if(temp == NULL)
				cout<<"\n\t Insufficient Memory";
			else
			{
				temp->vertex = v1;
				temp->next = NULL;
				first = head[v2];
			}
			if(first == NULL)
				head[v2] = temp;
			else
			{
				while(first->next!= NULL)
					first = first->next;
				first->next = temp;
			}
		}
		cout<<"\n\t Do you want to add more edges?(y/n)";
		cin>>ans;
	}while(ans == 'y'||ans == 'Y');
}

void graph::DFS(int v1)
{
	gnode *first;
	cout<<"\t"<<v1<<endl;
	cnt++;
	visited[v1] = true;
	first = head[v1];
	while(first!= NULL)
		if(visited[first->vertex] == false)
			DFS(first->vertex);
		else
			first = first->next;
}

int graph::cnt=0;
int main()
{
	int v1; 
	graph g;
	g.create();
	cout<<endl<<"\t Enter the vertex from which you want to traverse:";
	cin>>v1;
	if(v1>=10)
		cout<<"\n\t Invalid Vertex";
	else
	{
		cout<<"\n\t The Depth first search of graph is:\t";
		g.DFS(v1);
	}
	cout<<"\n\t The total number of nodes in graph is:\t"<<g.cnt;
}
