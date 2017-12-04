#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <time.h>
# define INF 0x3f3f3f3f
using namespace std;

struct node
	    {
			int id;
			int n;
			int degree;
			node* parent;
			node* child;
			node* left;
			node* right;
			char mark;
			char C;
	    };

int nH;
node* MAKE_FIB_HEAP();
int FIB_HEAP_LINK(node*,node*,node*);
node* CREATE_NODE(int,int);
node* FIB_HEAP_INSERT(node*,node*);
node* FIB_HEAP_UNION(node*,node*);
node* FIB_HEAP_EXTRACT_MIN(node*);
int CONSOLIDATE(node*);
int DISPLAY(node*);
int DISPLAY_1(node*);
node* H=MAKE_FIB_HEAP();
node* FIND_NODE(node*,int);
int FIB_HEAP_DECREASE_KEY(node*,int,int);
int FIB_HEAP_DELETE_KEY(node*,int);
int CUT(node*,node*,node*);
int CASCADE_CUT(node*,node*);
int PRESENT_NODE(node*);


/////////////////////////////////////PRIMS////////////////////////////////////////////


typedef pair<int, int> iPair;

class Graph
{
    int V;
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
    
    void printlist();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 void Graph::printlist(){
	 
	     list< pair<int, int> >::iterator i;
        {
            int v = (*i).first;
            int weight = (*i).second;
            printf("%d %d :: ",v,weight);
		}
 }
 
void Graph::primMST()
{
 
    int src = 0;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    node* p;
    /// ADDED
	p=CREATE_NODE(0,src);
	H=FIB_HEAP_INSERT(H,p);
    /// END
    
    key[src] = 0;
    
    /// ADDED
    
    node *q1=H;
    while(q1!=NULL)
    /// END
    {
        
        ///ADDED
        
        q1=FIB_HEAP_EXTRACT_MIN(H);
        if(q1==NULL)break;
        int u=q1->id;
        ///END
 
        inMST[u] = true;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight)
            {

                key[v] = weight;
                ///ADDED
                p=CREATE_NODE(key[v],v);
				H=FIB_HEAP_INSERT(H,p);
                ///END
                
                
                parent[v] = u;
            }
        }
    }
 
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

void selftest1()
{
	int V = 9;
    Graph g(V);
	printf("/////////////// TEST 1 : 10 Edges ////////////////////////\n");
    g.addEdge(0,1,-1);
    ///////////////////////////////////INPUTS FROM FILE/////////////////////////////
	std::fstream myfile("test1.txt", std::ios_base::in);
    
    int a,b,c;
    while (myfile >> a)
    {
		myfile >> b;
		myfile >> c;
		//printf("%d %d %d\n",a,b,c);
		g.addEdge(a,b,c);
        
    } 
    ///////////////////////////////////////////////////////////////////////////////
     clock_t t;
    t = clock();
    
    g.primMST();
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("TIME : %f\n",time_taken);
	}
	
	
	void selftest2()
{
	int V = 100;
    Graph g(V);
	printf("/////////////// TEST 2 : 100 Edges ////////////////////////\n");
    g.addEdge(0,1,-1);
    ///////////////////////////////////INPUTS FROM FILE/////////////////////////////
	std::fstream myfile("test2.txt", std::ios_base::in);
    
    int a,b,c;
    while (myfile >> a)
    {
		myfile >> b;
		myfile >> c;
		//printf("%d %d %d\n",a,b,c);
		g.addEdge(a,b,c);
        
    } 
    ///////////////////////////////////////////////////////////////////////////////
     clock_t t;
    t = clock();
    
    g.primMST();
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("TIME : %f\n",time_taken);
	}
	
	void selftest3()
{
	int V = 100;
    Graph g(V);
	printf("/////////////// TEST 3 : 500 Edges ////////////////////////\n");
    g.addEdge(0,1,-1);
    ///////////////////////////////////INPUTS FROM FILE/////////////////////////////
	std::fstream myfile("test3.txt", std::ios_base::in);
    
    int a,b,c;
    while (myfile >> a)
    {
		myfile >> b;
		myfile >> c;
		//printf("%d %d %d\n",a,b,c);
		g.addEdge(a,b,c);
        
    } 
    ///////////////////////////////////////////////////////////////////////////////
     clock_t t;
    t = clock();
    
    g.primMST();
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("TIME : %f\n",time_taken);
	}
	
	void selftest4()
{
	int V = 100;
    Graph g(V);
	printf("/////////////// TEST 4 : 1000 Edges ////////////////////////\n");
    g.addEdge(0,1,-1);
    ///////////////////////////////////INPUTS FROM FILE/////////////////////////////
	std::fstream myfile("test4.txt", std::ios_base::in);
    
    int a,b,c;
    while (myfile >> a)
    {
		myfile >> b;
		myfile >> c;
		//printf("%d %d %d\n",a,b,c);
		g.addEdge(a,b,c);
        
    } 
    ///////////////////////////////////////////////////////////////////////////////
     clock_t t;
    t = clock();
    
    g.primMST();
    
    t = clock() ;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("TIME : %f\n",time_taken);
	}
int main()
{
    selftest1();
    selftest2();
    selftest3();
    selftest4();
 
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
  
node* MAKE_FIB_HEAP()
  {
    node* np;
    np=NULL;
    return np;
  }
  
node* CREATE_NODE(int k, int ide)
  {
    node* x=new node;
    x->n=k;
    x->id=ide;
    return x;
  }
  
node* FIB_HEAP_INSERT(node* H,node* x)
  {
    x->degree=0;
    x->parent=NULL;
    x->child=NULL;
    x->left=x;
    x->right=x;
    x->mark='F';
    x->C='N';
    if(H!=NULL)
      {
	(H->left)->right=x;
	x->right=H;
	x->left=H->left;
	H->left=x;
	if(x->n<H->n)
	  H=x;
      }
    else
      {
	H=x;
      }
    nH=nH+1; 
    
    return H;
  }
  
int FIB_HEAP_LINK(node* H1,node* y,node* z)
  { 
    (y->left)->right=y->right;
    (y->right)->left=y->left;
    if(z->right==z)
      H1=z;
     y->left=y;
     y->right=y;
    y->parent=z;
    if(z->child==NULL)
      z->child=y;
    y->right=z->child;
    y->left=(z->child)->left;
    ((z->child)->left)->right=y;
    (z->child)->left=y;
    if(y->n<(z->child)->n)
      z->child=y;
    z->degree++;
    
  }

node* FIB_HEAP_UNION(node* H1,node* H2)
  {
    node* np;
    node* H=MAKE_FIB_HEAP();
    H=H1;
    (H->left)->right=H2;
    (H2->left)->right=H;
    np=H->left;
    H->left=H2->left;
    H2->left=np;
    return H;
  }

node* FIB_HEAP_EXTRACT_MIN(node* H1)
  {
    node* p;node* ptr;
    node* z=H1;
    p=z;
    ptr=z;
    if(z==NULL)
    {
		
     return z;
	}
    node* x;
    node* np;
    x=NULL;
    if(z->child!=NULL)
	x=z->child;
    if(x!=NULL)
      {
	ptr=x;
	do
	  {
	    np=x->right;
	  (H1->left)->right=x;
	  x->right=H1;
	  x->left=H1->left;
	  H1->left=x;
	  if(x->n<H1->n)
	    H1=x;
	  x->parent=NULL;
	  x=np;
	  }while(np!=ptr);
      }  
    (z->left)->right=z->right;
    (z->right)->left=z->left;
     H1=z->right;
    if(z==z->right&&z->child==NULL)
    {
      H=NULL;
    }
    
    else
      {
	H1=z->right;
	CONSOLIDATE(H1);
      }
    nH=nH-1;
    return p;
  }
  
int CONSOLIDATE(node* H1)
  {
    int d;
    float f=(log(nH))/(log(2));
    int D=f;
    node* A[D];
    for(int i=0;i<=D;i++)
	A[i]=NULL;
    node* x=H1;
    node* y;
    node* np;
    node* pt=x;
    do
      {
	pt=pt->right;
	d=x->degree;
	while(A[d]!=NULL)
	  {
	    y=A[d];
	    if(x->n>y->n)
	      {
		np=x;
		x=y;
		y=np;
		
	      }
	    if(y==H1)
	      H1=x;
	    FIB_HEAP_LINK(H1,y,x);  
	    if(x->right==x)
	      H1=x;
	    A[d]=NULL;
	    d=d+1;
	      
	  }
	
	A[d]=x;
	x=x->right;
      }while(x!=H1);
   H=NULL;
   for(int j=0;j<=D;j++)
    {
      if(A[j]!=NULL)
	{
	  A[j]->left=A[j];
	  A[j]->right=A[j];
	  if(H!=NULL)
	{
	(H->left)->right=A[j];
	A[j]->right=H;
	A[j]->left=H->left;
	H->left=A[j];
	if(A[j]->n<H->n)
	  H=A[j];
	}
    else
	{
	H=A[j];
	}
	  if(H==NULL)
	    H=A[j];
	  else if(A[j]->n<H->n)
	    H=A[j];
	}
    }
  }
  
  
int FIB_HEAP_DECREASE_KEY(node*H1,int x,int k)
  {
    node* y;
    if(H1==NULL)
      {
	cout<<"\nNO NODE IN THE HEAP!!! ABORTING!!!!";
	return 0;
      }
    node* ptr=FIND_NODE(H1,x);
    if(ptr==NULL)
      {
	cout<<"\nTHE TARGET NODE NOT FOUND!!!!!";
	return 1;
      }
    if(ptr->n<k)
      {
	cout<<"\nTHE ENTERED KEY IS GREATER THAN THE CURRENT VALUE!!!";
	return 0;
      }
    ptr->n=k;
    y=ptr->parent;
    if(y!=NULL&&ptr->n<y->n)
      {
	CUT(H1,ptr,y);
	CASCADE_CUT(H1,y);
      }
   if(ptr->n<H->n)
    H=ptr;
   return 0;
  }
  
int CUT(node* H1,node* x,node* y)
  {
    if(x==x->right)
      y->child=NULL;
    (x->left)->right=x->right;
    (x->right)->left=x->left;
    if(x==y->child)
      y->child=x->right;
    y->degree=y->degree-1;
    x->right=x;
    x->left=x;
    (H1->left)->right=x;
    x->right=H1;
    x->left=H1->left;
    H1->left=x;
    x->parent=NULL;
    x->mark='F';
  }
  
  
int CASCADE_CUT(node* H1,node* y)
  {
    node* z=y->parent;
    if(z!=NULL)
      {
	if(y->mark=='F')
	    {
	      y->mark='T';
	    }
	else
	  {
	    CUT(H1,y,z);
	    CASCADE_CUT(H1,z);
	  }
	      
      }
  }
  
  
node* FIND_NODE(node* H,int k)
  {
    node* x=H;
    x->C='Y';
    node* p=NULL;
    if(x->n==k)
      {
	p=x;
	x->C='N';
	return p;
      }
    if(x->child!=NULL&&p==NULL)
      {
      p=FIND_NODE(x->child,k);
      }
    if((x->right)->C!='Y'&&p==NULL)
      {
      p=FIND_NODE(x->right,k);
      }
    x->C='N';  
    return p; 
  }
