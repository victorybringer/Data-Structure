#define maxsize 50
using namespace std;

#include "iostream"
#define  MaxVertexNum 100
typedef struct Sqlist{

    int data[maxsize];



    int length=0;


};
typedef struct LNode{

    int data;

    LNode (int data){
        this->data=data;
    }

    LNode *next= NULL;

}*LinkList;



typedef struct ArcNode {


    int data;



    ArcNode* next = NULL;
    ArcNode(int data) {

        this->data = data;
    }

};



typedef struct VNode {


    int data;


    ArcNode* next = NULL;



};

typedef struct Graph {

    VNode vertices[MaxVertexNum];

    int vexnumber;



};

typedef struct SqStack{

    int data[maxsize];

    int top=-1;



};
typedef struct Queue{

    int data[maxsize];

    int rear=0;

    int front=0;

    int tag=0;
};




bool isEmpty(SqStack &stack){

    if(stack.top!=-1)
        return 0;
    else
        return 1;


}




bool Push(SqStack &stack,int x){

    if(stack.top==maxsize-1)
        return 0;

    stack.data[++stack.top]=x;
    return 1;

}
bool Pop(SqStack &stack,int &x){

   if(isEmpty(stack))
       return 0;

   x=stack.data[stack.top--];

    return 1;


}
bool GetTop(SqStack &stack,int &x){

    if(isEmpty(stack))
        return 0;

    x=stack.data[stack.top];


    return 1;


}




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

        Q.rear = (Q.rear + 1) % maxsize;

        Q.tag = 1;

        return 1;

    }
}


bool DeQueue(Queue &Q,int &x){


        if(isEmpty(Q))

            return 0;

        else{

            x=Q.data[Q.front];

            Q.front=(Q.front+1)%maxsize;

            Q.tag=0;

            return 1;
        }


}

void reverseStack(SqStack &stack){  //用队列将栈中元素逆置

Queue Q;

while(!isEmpty(stack)){

int x;

Pop(stack,x);


EnQueue(Q,x);


}


while(!isEmpty(Q)){


int x;

DeQueue(Q,x);

Push(stack,x);


}

}

void display(SqStack stack){

while(stack.top!=-1){

cout<<stack.data[stack.top--]<<endl;

}
}


void powerlist(char data[], int length,int curpos, string s) { //幂集

    if (curpos == length){

       if(s.length()==0){

         cout << "幂集序列空集"<< endl;
       }
       else
       cout << "幂集序列" + s << endl;
       
    }

       

    else{

    powerlist(data, length, curpos+1,s + data[curpos]);
    powerlist(data, length, curpos+1,s);
    }

}

void deleteArcNode(Graph G,int i,int j){//删除边i,j,无向图多删除一次j,i

ArcNode *p=G.vertices[i].next;

if(p->data==j){  //要删除第一个结点

  G.vertices[i].next=p->next;

  //free(p);
}

else{

ArcNode *pre=p;

p=p->next;

while(p->data!=j){

pre=pre->next;
p=p->next;

}

pre->next=p->next;

//free(p);


}




}


bool Search(LinkList L,int key,int mode){ //三种查找

LNode *p=L->next;

if(mode==0){//无序

while(p!=NULL){

if(p->data==key){

return 1;

}

else
p=p->next;


}


}

if(mode==1){//顺序


while(p->data<key){

p=p->next;

}

if(p->data==key)

return 1;

else

return 0;

}

if(mode==2){//逆序


while(p->data>key){

p=p->next;

}

if(p->data==key)

return 1;

else

return 0;

}





}

int main(){


   SqStack stack;

    
    for( int i=0;i<5;++i){

            Push(stack,i);

           
        }

    display(stack); //逆置前

reverseStack(stack);

    display(stack); //逆置后


char data[3]={'1','2','3'};

powerlist(data,3,0,"");
    LinkList b = new LNode(9999);



    b->next = new LNode(4);

    b->next->next = new LNode(2);

    b->next->next->next = new LNode(1);
    b->next->next->next->next = new LNode(10);
    b->next->next->next->next->next = new LNode(3);


cout<<Search(b,11,0)<<endl;


}