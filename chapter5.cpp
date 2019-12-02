#define  MaxVertexNum 100
#define  Maxsize 100
#include "iostream"
#include <string>
using namespace std;

bool visited[MaxVertexNum];

typedef struct MGraph{


    int Edge[MaxVertexNum][MaxVertexNum];

    int vexnumber;
};

typedef  struct Stack {

    int data[MaxVertexNum];

    int top=-1;



};
typedef struct ArcNode{


    int data;



    ArcNode*next= nullptr;
    ArcNode(int data){

        this->data=data;
    }

};



typedef struct VNode{


    int data;


    ArcNode* next= nullptr;



};

typedef struct Graph{

    VNode vertices [MaxVertexNum];

    int vexnumber;



};


typedef struct Queue{

    int data[Maxsize];

    int rear=0;

    int front=0;

    int tag=0;
};

Queue Q;
bool isEmpty(Queue Q){

    if(Q.tag==0&&Q.front==Q.rear)

        return 1;

    else
        return 0;

}
bool EnQueue(Queue &Q,int x) {


    if (Q.tag == 1 && Q.front == Q.rear)

        return 0;

    else {

        Q.data[Q.rear] = x;

        Q.rear = (Q.rear + 1) % Maxsize;

        Q.tag = 1;

        return 1;

    }
}


bool DeQueue(Queue &Q,int &x){


    if(isEmpty(Q))

        return 0;

    else{

        x=Q.data[Q.front];

        Q.front=(Q.front+1)%Maxsize;

        Q.tag=0;

        return 1;
    }


}

bool isEmpty(Stack &stack){

    if(stack.top!=-1)
        return 0;
    else
        return 1;


}


bool Push(Stack &stack,int x){

    if(stack.top==Maxsize-1)
        return 0;

    stack.data[++stack.top]=x;
    return 1;

}
bool Pop(Stack &stack,int &x){

    if(isEmpty(stack))
        return 0;

    x=stack.data[stack.top--];

    return 1;


}
bool GetTop(Stack &stack,int &x){

    if(isEmpty(stack))
        return 0;

    x=stack.data[stack.top];


    return 1;


}

int FirstNeighbour(Graph G, int vex ){


    return G.vertices[vex].next? G.vertices[vex].next->data:-1;


}

int NextNeighbour(Graph G, int vex,int num ){

    ArcNode * p=G.vertices[vex].next;

    while(p->data!=num){


        p=p->next;

    }

    if(p->next)
        return p->next->data;

    else
        return -1;

}

void DFS(Graph G,int i){

visited[i]=true;

cout<<i<<endl;
for(int w=FirstNeighbour(G,i);w>=0;w=NextNeighbour(G,i,w)){

    if(!visited[w])
    DFS(G,w);

}

}
void DFSTraverse(Graph G){

    for(int i=0;i<G.vexnumber;++i){

        if(!visited[i])

            DFS(G,i);

    }

}


void BFS(Graph G,int i){

visited[i]=true;

EnQueue(Q,i);
cout<<i<<endl;

while(!isEmpty(Q)){
    int x;
    DeQueue(Q,x);

    for(int w=FirstNeighbour(G,x);w>=0;w=NextNeighbour(G,x,w)){


        if(!visited[w]){


          visited[w]=true;

          cout<<w<<endl;

          EnQueue(Q,w);
        }



    }


}

}
void BFSTraverse(Graph G){

    for(int i=0;i<G.vexnumber;++i){

        if(!visited[i])

            BFS(G,i);

    }

}


void isTree(Graph G,int i,int &n1,int &n2){  //判断是否为一棵树 要一次遍历n-1个边，n个顶点
n1++; //记录点
    visited[i]=true;

    for(int w=FirstNeighbour(G,i);w>=0;w=NextNeighbour(G,i,w)){
n2++; //记录边
        if(!visited[w])
            isTree(G,w,n1,n2);

    }

}
bool DFSStack(Graph graph,int i ){ //DFS非递归（答案写法)

    Stack stack;

    Push(stack,i);

    visited[i]=true;
    int k;
    while(stack.top!=-1) {


         Pop(stack,k);
         cout<<k<<endl;

        for(int w=FirstNeighbour(graph,k);w>=0;w=NextNeighbour(graph,k,w)){

            if(!visited[w])

            Push(stack,w);
            visited[w]=true;


        }

    }

}



bool DFSStack2(Graph graph,int i ){ //DFS非递归（类似于先序遍历的思路)


    Stack stack;



    Push(stack,i); //

    cout<<i<<endl;

    visited[i]=true;

    int w;


    while(stack.top!=-1) {

        int cur;

        GetTop(stack,cur);


        for(w=FirstNeighbour(graph,cur);w>=0;w=NextNeighbour(graph,cur,w)){

            if(!visited[w])

                break; //遇到一个没访问过的，就停止
        }

        if(w!=-1){
            visited[w]=true;
            cout<<w<<endl;

            Push(stack,w);
       }

        else

            Pop(stack,cur);



    }

}








void DFS_EXIST(Graph G,int i,int j,bool &exist ){ //进行一次DFS遍历，判断I到J是否有路径

    visited[i]=true;

    for(int w=FirstNeighbour(G,i);w>=0;w=NextNeighbour(G,i,w)){

        if(w==j)
            exist= true;


        if(!visited[w]&&!exist)
            DFS_EXIST(G,w,j,exist);

    }

}





void findpath(Graph graph,int i,int j,string s){ //尾递归寻找两点间所有路径


    for(int w=FirstNeighbour(graph,i);w>=0;w=NextNeighbour(graph,i,w)){

        char str[1]; //先新建一个字符数组

        sprintf(str,"%d",w); //数字转字符串


        if(w==j)

            cout<<s+","+str<<endl;


        else  {


            if(s.find(str)== string::npos ) //同一个路径不能有重复元素

                findpath( graph, w, j, s+","+str);


        }



    }





}


int main(){


    VNode v0;
    v0.data=0;
    VNode v1;
    v1.data=1;
    VNode v2;
    v2.data=2;
    VNode v3;
    v3.data=3;

    //ArcNode * a0=new ArcNode(0);

    ArcNode * a1=new ArcNode(1);

    ArcNode * a2=new ArcNode(2);

    ArcNode * a3=new ArcNode(3);


    v0.next=a2;

    a2->next=a1;

    v1.next=a3;

    v2.next=new ArcNode(3);


    Graph G;


    G.vertices[0]=v0;

    G.vertices[1]=v1;

    G.vertices[2]=v2;

    G.vertices[3]=v3;


    G.vexnumber=4;





 ///findpath(G,0,3,"0");

   DFSTraverse(G);

//BFSTraverse(G);


int vex=0;
int arc=0;


//isTree(G,0,vex,arc);

//cout<<vex<<endl;

//cout<<arc<<endl;

//bool exist;
//DFS_EXIST(G,2,0,exist);

//cout<<exist<<endl;
    return 0;
}

