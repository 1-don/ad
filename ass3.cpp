#include<iostream>
using namespace std;

class graph
{
	int G[10][10],v[10];
	int v1,v2;
	public:
		int n;
		int count;
		graph()			//Constructor
		{
			for(v1=0;v1<10;v1++)
				v[v1] = false;
			for(v1=0;v1<10;v1++)
				for(v2=0;v2<10;v2++)	
					G[v1][v2] = false;
		}	
		void create();
		void display();
		void DFS(int);
		~graph()
		{
			for(v1=0;v1<10;v1++)
				for(v2=0;v2<10;v2++)	
					G[v1][v2] = false;
			for(v1=0;v1<10;v1++)
				v[v1] = false;
		}
};

void graph::create()
{
	int v1,v2;
	n=0;
	do
	{
		cout<<"\n\t Enter the end vertices of the edge:\n";
		cout<<"\n\t (and type -99 terminate)\n";
		cin>>v1>>v2;
		if(v1==-99)
			break;
		if( v1>=10 || v2>=10)
			cout<<"\n Invalid Vertex \n";
		else
		{
			G[v1][v2] = true;
			G[v2][v1] = true;
		}
		n++;
	}while(1);
}

void graph::display()
{
	for(v1=1;v1<n;v1++)
	{
		for(v2=1;v2<n;v2++)	
			cout<<" "<<G[v1][v2];
	cout<<endl;
	}
}

void graph::DFS(int v1)
{
	int v2;
	cout<<endl<<v1;
	count++;
	v[v1]=true;
	for(v2=0;v2<10;v2++)
		if(G[v1][v2] == true & v[v2] == false)
			DFS(v2);
}


int main()
{
	graph g;
	int v1;
	g.create();
	cout<<"\n\t The Adjacency Matrix for the Graph is: \n";
	g.display();
	cout<<"\n\t Enter the vertex from which you want to traverse:\t";
	cin>>v1;
	if( v1>=10)
			cout<<"\n Invalid Vertex \n";
	cout<<"\n\t The DFS for the Graph is: \n";
	g.DFS(v1);
	cout<<"\n\t Total no of nodes in graph is:\t"<<g.count<<endl;
}