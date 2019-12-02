#define maxsize 50
using namespace std;

#include "iostream"

typedef struct Sqlist{

    int data[maxsize];



    int length=0;


};
typedef struct LNode{

    int data;

    LNode (int data){
        this->data=data;
    }

    LNode *next= nullptr;

}*LinkList;




typedef struct SqStack2{

    char data[maxsize];

    int top=-1;



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

bool isEmpty(SqStack2 &stack){

    if(stack.top!=-1)
        return 0;
    else
        return 1;


}


bool Push(SqStack2 &stack,int x){

    if(stack.top==maxsize-1)
        return 0;

    stack.data[++stack.top]=x;
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

bool Pop(SqStack2 &stack,char &x){

    if(isEmpty(stack))
        return 0;

    x=stack.data[stack.top--];

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



 bool isValid(Sqlist &list){   //1代表入栈操作，0代表出栈操作，判断一个操作序列的合法性

    SqStack stack;



    for(int i=0;i<list.length;++i){
        int x;

        if(list.data[i]==1){
            Push(stack,1);
       }
        else{
            if(isEmpty(stack))
                return 0;
            else
                Pop(stack,x);
        }
    }
     return  1;

}






bool isRerverse(LinkList  &L,int n){   //判断一个序列的中心对称性

       SqStack stack;

        LNode *p=L->next;

        for( int i=0;i<n/2;++i){

            Push(stack,p->data);

            p=p->next;

        }



    if(n%2==1)
    p=p->next;//p后移过中心结点

while(p!=nullptr)  {

    int x;
    GetTop(stack,x);
    if(p->data==x){
        p=p->next;
        Pop(stack,x);
    }
    else
        break;
}

if(p!= nullptr)

    return 0;
else
    return 1;




}


bool match(char list[],int length){  //括号匹配

SqStack2 stack;


    for(int i=0;i<length;++i){
        char x;

        if(list[i]=='{'||list[i]=='('||list[i]=='['){
            Push(stack,list[i]);
        }
        else{

            Pop(stack,x);
            if(list[i]==']'&&x!='[')
                return 0;

            if(list[i]=='}'&&x!='{')
                return 0;

            if(list[i]==')'&&x!='{')
                return 0;


        }
    }

    if(stack.top!=-1)
    return  0;
    else
        return 1;




}
int main(){

    Sqlist list;

    list.data[0]=1;

    list.data[1]=1;

    list.data[2]=1;

    list.data[3]=0;

     list.length=4;
//cout<<isValid(list)<<endl;

    LinkList a=new LNode(9999) ;



    a->next=new LNode(1);;

    a->next->next=new LNode(2);;

    a->next->next->next=new LNode(2);

    a->next->next->next->next=new LNode(1);;


   // cout<<isRerverse(a,4)<<endl;


   char str[5]={'{','[',']','}','{'};


cout<<match(str,5)<<endl;
}

