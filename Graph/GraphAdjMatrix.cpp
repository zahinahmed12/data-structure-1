#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3


class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************


//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	int ** matrix ; //adjacency matrix to store the graph
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation
	int *color;
	int *parent;
	int *dist;
	int *discoveryTime;
	int *finishTime;
	int time;

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph
	void dfs();
	void dfs_visit(int u);
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ; //set direction of the graph
	//define other variables to be initialized
	color = 0;
	parent = 0;
	dist = 0;
	discoveryTime = 0;
	finishTime = 0;
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;

	//allocate space for the matrix
    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0; //initialize the matrix cells to 0
    }
    if(parent!=0) delete[] parent ;
	parent = new int[nVertices];

	if(dist!=0) delete[] dist ;
	dist = new int[nVertices];

	if(discoveryTime!=0) delete[] discoveryTime ;
	discoveryTime = new int[nVertices];

	if(finishTime!=0) delete[] finishTime ;
	finishTime = new int[nVertices];

	if(color!=0) delete[] color ;
	color = new int[nVertices];

}

void Graph::addEdge(int u, int v)
{
    //write your code here
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    if(directed)
    {
        matrix[u][v] = 1;
        nEdges++;
    }

    if(!directed) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
        nEdges=nEdges+2;
    }
}

void Graph::removeEdge(int u, int v)
{
    //write this function
    if(!isEdge(u,v)) return;
    else
    {
        if(!directed) {

        matrix[u][v]=0;
        matrix[v][u]=0;
        nEdges=nEdges-2;
        return;
        }
        if(directed){

        matrix[u][v] = 0;
        nEdges--;
        return;
    }
    }
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false

    if(matrix[u][v]==1) {
            printf("Edge found\n");
            return true;
    }
    else {
            printf(" No Edge found\n");
    return false;
    }
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    int c=0,j;

       for(int j=0;j<nVertices;j++)
            if( matrix[u][j] == 1)
        {
            c++;
        }
        if(!directed) return 2*c;
        else if(directed) return c;
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    int j;
    for(int j=0;j<nVertices;j++){
            if( matrix[u][j] == 1 && matrix[v][j] == 1)
        {
            printf("HAS ADJACENT VERTICES\n");
            return true;
        }
    }
            printf("No adjacent vertices\n");
            return false;
}

void Graph::bfs(int source)
{
    //complete this function
    //initialize BFS variables
    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
        dist[i] = INFINITY ;
    }
    Queue q ;
    color[source] = GREY;
    dist[source] = 0 ;
    q.enqueue(source) ;
    while( !q.empty() )
    {
        //complete this part
        int u=q.dequeue();
        for(int j=0;j<nVertices; j++)
        {
            if(matrix[u][j]==1){

            if(color[j]==WHITE)
            {
                color[j]=GREY;
                dist[j]=dist[u]+1;
                parent[j]=u;
                q.enqueue(j);
            }
            }
        }
        color[u]=BLACK;
        printf("%d->",u);

    }
    printf("\n");

}

void Graph::dfs()
{
    //write this function
    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE;
        parent[i] = -1;
        dist[i] = 0;
    }
    time = 0;
    for(int i=0; i<nVertices; i++)
    {
        if(color[i] == WHITE)
        {
            dfs_visit(i);
        }
    }

}

void Graph::dfs_visit(int u)
{
    time++;
    discoveryTime[u] = time;
    color[u] = GREY;
    for(int i=0; i<nVertices; i++)
    {
        if(matrix[u][i]==1){
        if(color[i] == WHITE)
        {
            parent[i] = u;
            dfs_visit(i);
        }
        }
    }
    color[u] = BLACK;
    time++;
    finishTime[u] = time;
}

int Graph::getDist(int u, int v)
{
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    bfs(u);
    return dist[v];

}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
    for(int i=0;i<nVertices;i++)
    {
            delete[] matrix[i];
    }
    delete[] matrix;

	if(color!=0) delete[] color ;
	if(parent!=0) delete[] parent ;
	if(dist!=0) delete[] dist ;
	if(discoveryTime!=0) delete[] discoveryTime ;
	if(finishTime!=0) delete[] finishTime ;

	color = 0;
	parent = 0;
	dist = 0;
	discoveryTime = 0;
	finishTime = 0;
}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. 2. Remove edge. 3. Degree\n");
        printf("4. isEdge. 5. Print Graph  6. Exit. 7. Common Adjacent vertices.\n");
        printf("8. BFS. 9. Get Shortest Distance. 10. DFS\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.removeEdge(u, v);

        }
        else if(ch==3)
        {
            int u;
            scanf("%d", &u);
            printf("%d\n",g.getDegree(u));

        }
        else if(ch==4)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.isEdge(u, v);
        }
        else if(ch==5)
        {
            g.printGraph();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.hasCommonAdjacent(u, v);

        }
        else if(ch==8)
        {
            int u;
            scanf("%d", &u);
            g.bfs(u);
        }
        else if(ch==9)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n",g.getDist(u, v));

        }
        else if(ch==10)
        {
            g.dfs();
        }
    }

}
