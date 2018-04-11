/*Assignment No: 4
Problem Statement:
There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph. Justify the storage representation used. 
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class vertex;

class edge
{
	private:
		vertex *source;
		vertex *destination;
		int distance;
	public:
		edge(vertex *s,vertex *d,int dist)
		{
			source = s;
			destination = d;
			distance = dist;
		}
		vertex *getsource()
		{
			return source;
		}
		vertex *getdesti()
		{
			return destination;
		}
		int getdist()
		{
			return distance;
		}
};
class vertex
{
	private:
		string city;
		vector<edge> edges;	//vector created for edges
	public:
		vertex(string name)			//Constructor
		{
			city=name;
		}	
		void addedge(vertex *v,int dist)
		{
			edge new_e(this,v,dist);
			edges.push_back(new_e);
		}
		void showedge()
		{
			cout<<"\n\tFrom "<<city<<" to ";
			for(int i=0;i<(int)edges.size();i++)
			{
				edge e=edges[i];
				cout<<e.getdesti()->getcity()<<" requires "<<e.getdist()<<" hrs "<<endl;
			}		
			cout<<endl;
		}
		string getcity()
		{
			return city;
		}
		vector<edge> getedges()
		{
			return edges;
		}
};

class graph
{
	private:
		vector<vertex*>v;
	public:
		graph()
		{
		}
		void insert(vertex *val)
		{
			v.push_back(val);
		}
		void display()
		{
			for(int i=0; i<(int)v.size();i++)
				v[i]->showedge();		
		}
};

int main()
{
	graph g;
	vertex v1 = vertex("Mumbai");
	vertex v2 = vertex("Pune");
	vertex v3 = vertex("Kolkata");
	vertex v4 = vertex("Delhi");

	vertex *vptr1 = &v1;
	vertex *vptr2 = &v2;
	vertex *vptr3 = &v3;
	vertex *vptr4 = &v4;

	v1.addedge(vptr4,2);
	v2.addedge(vptr1,1);
	v3.addedge(vptr1,3);
	v4.addedge(vptr2,2);
	v4.addedge(vptr3,3);

	g.insert(vptr1);
	g.insert(vptr2);
	g.insert(vptr3);
	g.insert(vptr4);

	cout<<"\n\t Displaying city transport map using Adjacency list"<<endl;
	g.display();
	
	return 1;
}

/*---------------------OUTPUT------------------------
sh-4.2$ g++ -o main *.cpp                                                                                                                    
sh-4.2$ main                                                                                                                                 
                                                                                                                                             
         Displaying city transport map using Adjacency list    

 	From Mumbai to Delhi requires 2 hrs                                                                                                                                     From Pune to Mumbai requires 1 hrs
 	
	From Kolkata to Mumbai requires 3 hrs 

	From Delhi to Pune requires 2 hrs                                                                                                    
	Kolkata requires 3 hrs  
*/