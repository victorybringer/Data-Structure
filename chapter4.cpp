#define maxsize 50
using namespace std;

#include "iostream"
#include "string"
typedef  struct BiTNode{

    BiTNode *lchild= nullptr;
    BiTNode *rchild= nullptr;

    int data;

    BiTNode(int data){
        this->data=data;

    }


}* BiTree;









typedef  struct  ThreadNode{

    int data;
    int ltag;
    int rtag;
    ThreadNode * lchild=nullptr;

    ThreadNode * rchild=nullptr;

    ThreadNode(int data,int ltag,int rtag){

        this->data=data;
        this->ltag=ltag;

        this->rtag=rtag;
    }



}*ThreadTree;
typedef struct Sqlist{

    int data[maxsize];



    int length=0;


};


typedef  struct  BiTNode2{

    char data;

    BiTNode2 * left=nullptr;

    BiTNode2 * right=nullptr;

    BiTNode2(char data){

        this->data=data;
    }



} * BiTree2;

typedef struct Queue{

    BiTree data[maxsize];

    int rear=0;

    int front=0;

    int tag=0;
};


typedef struct SqStack{

    BiTree data[maxsize];

    int top=-1;



};


bool isEmpty(SqStack &stack){

    if(stack.top!=-1)
        return 0;
    else
        return 1;


}



bool Push(SqStack &stack,BiTree x){

    if(stack.top==maxsize-1)
        return 0;

    stack.data[++stack.top]=x;
    return 1;

}


bool Pop(SqStack &stack,BiTree &x){

    if(isEmpty(stack))
        return 0;

    x=stack.data[stack.top--];

    return 1;


}



bool GetTop(SqStack &stack,BiTree &x){

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


bool EnQueue(Queue &Q, BiTree x) {


    if (Q.tag == 1 && Q.front == Q.rear)

        return 0;

    else {

        Q.data[Q.rear] = x;

        Q.rear = (Q.rear + 1) % maxsize;

        Q.tag = 1;

        return 1;

    }
}


bool DeQueue(Queue &Q,BiTree &x){


    if(isEmpty(Q))

        return 0;

    else{

        x=Q.data[Q.front];

        Q.front=(Q.front+1)%maxsize;

        Q.tag=0;

        return 1;
    }


}


void PreOrder(BiTree T){  //先序遍历

    if(T){

        cout<<T->data<<endl;

        PreOrder(T->lchild);

        PreOrder(T->rchild);


    }


}


void InOrder(BiTree T){ //中序遍历


    if(T){



        InOrder(T->lchild);
        cout<<T->data<<endl;
        InOrder(T->rchild);


    }


}


void PostOrder(BiTree T){  //后序遍历


    if(T){



        PostOrder(T->lchild);

        PostOrder(T->rchild);
        cout<<T->data<<endl;

    }


}


void LevelOrder(BiTree T){  //层次遍历

    Queue Q;

    EnQueue(Q,T);


    BiTNode *p;

    while(!isEmpty(Q)){

        DeQueue(Q,p);

        cout<<p->data<<endl;

        if(p->lchild)
            EnQueue(Q,p->lchild);
        if(p->rchild)
            EnQueue(Q,p->rchild);

    }





}

void InOrderTraversal(BiTree T){  //中序非递归


    BiTNode *p=T;

    SqStack stack;

    while(stack.top!=-1||p){


        if(p){

            Push(stack,p);


            p=p->lchild;
        }

        else{


            Pop(stack,p);

            cout<<p->data<<endl;
            p=p->rchild;

        }


    }




}

void PreOrderTraversal(BiTree T){  //先序非递归


    BiTNode *p=T;

    SqStack stack;

    while(stack.top!=-1||p){ //栈不空或指针不空时循环


        if(p){
            cout<<p->data<<endl;
            Push(stack,p);


            p=p->lchild;
        }

        else{


            Pop(stack,p);


            p=p->rchild;

        }


    }




}

int commonancestor(int i,int j){ //顺序存储的树中两个编号的最近公共结点

    while(i!=j)

        i>j?i/=2:j/=2;

    return i;

}




void ReverseLevelOrder(BiTree T){  //逆序层次遍历

    BiTNode *p=T;

    Queue Q;


    SqStack stack;


    EnQueue(Q,p);


    while(!(isEmpty(Q))){


        DeQueue(Q,p);

        Push(stack,p);

        //   cout<<p->data<<endl;

        if(p->lchild){
            EnQueue(Q,p->lchild);
        }

        if(p->rchild){
            EnQueue(Q,p->rchild);
        }


    }

    while(stack.top>-1){

        cout<<stack.data[stack.top--]->data<<endl;

    }


}

int findDepth(BiTree T){

if(!T)

    return 0;

else

    return 1+(findDepth(T->lchild)>findDepth(T->rchild)?findDepth(T->lchild):findDepth(T->rchild));



}

int findDepthLevelly(BiTree T){ //层序遍历求树的高度

    if(!T)
        return 0;



    int level=0;
    Queue Q;
    EnQueue(Q,T);





    int last=Q.rear; //指向下一层的第一个结点的位置



    BiTNode *p;

    while(!isEmpty(Q)){

        DeQueue(Q,p);



        if(p->lchild)
            EnQueue(Q,p->lchild);
        if(p->rchild)
            EnQueue(Q,p->rchild);

        if(Q.front==last){
            level++;
            last=Q.rear;
        }

    }

    return  level;

}

void PostOrderTraversal(BiTree T ){ //后序遍历递归

    SqStack stack;

    BiTree p=T;

    BiTree r= nullptr;  //新建一个指针，判断返回时是从左侧还是右侧返回的

    while(p||stack.top!=-1){

        if(p){

            Push(stack,p);

            p=p->lchild;

        }

        else{

            GetTop(stack,p); //这里暂时先不出栈

            if(p->rchild&&p->rchild!=r)      //说明右子树未访问

                p=p->rchild;

               else{

                Pop(stack,p);
                cout<<p->data<<endl; //确认左右子树均访问过，再访问
                r=p; //标记为已访问
                p= nullptr;  //指针置空，等待取栈顶

            }

        }


    }


}

void ancestorX(BiTree T ,int x){ //后序遍历递归，打印值为x的节点的祖先

    SqStack stack;

    BiTree p=T;

    BiTree r= nullptr;  //新建一个指针，判断返回时是从左侧还是右侧返回的

    while(p||stack.top!=-1){

        if(p){

            Push(stack,p);

            p=p->lchild;

        }

        else{


          GetTop(stack,p); //这里暂时先不出栈

            if(p->rchild&&p->rchild!=r)    //说明右子树未访问

                p=p->rchild;



            else{         //说明从右子树返回，这时栈中元素为祖先结点

                  Pop(stack,p);

                if(p->data==x){

                    cout<<p->data<<endl;

                    while(stack.top!=-1){
                        Pop(stack,p);
                        cout<<p->data<<endl;
                    }


                }

                r=p;
                p= nullptr;

            }


        }





    }


}


BiTNode * findcommonancestor2(BiTree T ,BiTNode *p1,BiTNode * p2){ //二叉链表中寻找公共祖先

    SqStack stack;
    SqStack stack2;
    BiTree p=T;

    BiTree r= nullptr;

    while(p||stack.top!=-1){

        if(p){

            Push(stack,p);

            p=p->lchild;

        }

        else{


           GetTop(stack,p);

            if(p->rchild&&p->rchild!=r){

                p=p->rchild;

            }

            else{

            Pop(stack,p);

                     if(p==p1){

                    for(int i=0;i<=stack.top;++i){

                        Push(stack2,stack.data[i]);


                    }

                }

                if(p==p2){

                    for(int i=stack.top;i>=0;--i){


                        for(int j=stack2.top;j>=0;--j){

                            if(stack2.data[j]==stack.data[i]) {

                                cout << "find nearest common ancestor " << stack.data[i]->data << endl;

                                return stack2.data[j];
                            }
                        }
                    }

                }

                r=p;
                p= nullptr;

            }


        }




    }

    return nullptr;
}



void pretopost (int s[],int length){ //先序满二叉树转后序
       
        if(length>0){  //相当于递归遍历中指针不为Null，这里是顺序存储所以用数组长度大于0
  
        int lchild[(length - 1) / 2]; //分成左子树，右子树

        for (int i = 1; i <= (length - 1) / 2; ++i) {

            lchild[i-1] = s[i];
        }


        int rchild[(length - 1) / 2];

        for (int i = 1; i <= (length - 1) / 2; ++i) {

            rchild[i-1] = s[i + (length - 1) / 2 ];
        }

        pretopost(lchild, (length - 1) / 2);

        pretopost(rchild, (length - 1) / 2);


        cout<<s[0]<<endl;

}



}



void formula(BiTree2 T,int deep){//输出中缀表达式。含括号


    if(T== nullptr)
        return;

    else if(T->left== nullptr&&T->right== nullptr)
        cout<<T->data;  //叶结点
    else {  //有子树


       if(deep>1) cout<<'('; // 深度为1不需要再加括号了
        formula(T->left,deep+1);
        cout<<T->data;
        formula(T->right,deep+1);
        if(deep>1) cout<<')';
    }


}




void InorderPostpre(ThreadTree T,ThreadNode *p){ //中序线索二叉树的后续前驱

    if(p->rtag==0)
        cout<<p->rchild->data;
    else if(p->ltag==0)
        cout<<p->rchild->data;
    else if(p->lchild== nullptr)
        cout<<"无后续前驱"<<endl;
    else {

        while(p->ltag==1&&p->lchild!= nullptr) {//一直沿着线索找到一个由左子树的祖先

            p=p->lchild;

            if(p->ltag==0)
            cout<<p->lchild->data<<endl;
            else
                cout<<""<<endl;



        }

    }












}







    void changechild(BiTree &T){ //左右子树交换 自上而下，递归

    BiTNode * temp;

    temp=T->lchild;

    T->lchild=T->rchild;

    T->rchild=temp;

    if(T->lchild)

        changechild(T->lchild);

    if(T->rchild)

        changechild(T->rchild);



}


bool isComplete(BiTree T){ //判断是否为完全二叉树

    if(!T)

        return 0;

    BiTNode *p=T;

    Queue Q;

    EnQueue(Q,p);


    while(!(Q.front==Q.rear&&Q.tag==0)){


        DeQueue(Q,p);

        //   cout<<p->data<<endl;

        if(p){
            EnQueue(Q,p->lchild);     //空结点也入列
            EnQueue(Q,p->rchild);
        }
        else{
            while(!(Q.front==Q.rear&&Q.tag==0)) {


                DeQueue(Q,p);  //空结点后不能有非空，否则说明不是和编号一一对应

                if(p)

                    return 0;

            }

        }


    }

    return  1;

}





void hasTwoChild(BiTree T,int &count){

    if(T->lchild&&T->rchild)

        count++;

    if(T->lchild)

        hasTwoChild(T->lchild,count);

    if(T->rchild)

        hasTwoChild(T->rchild,count);

}


int deletex(BiTree &tree,int x){ //递归删除根结点值为X的子树

   if(!tree||tree->data==x)
       tree=nullptr;

   else{
       deletex(tree->lchild, x);
       deletex( tree->rchild,x);

   }


}


int findWidthLevelly(BiTree T){ //层序遍历求树的宽度

    if(!T)
        return 0;


    int width=0;
    int count=0;
    int level=0;
    Queue Q;
    EnQueue(Q,T);





    int last=Q.rear; //指向下一层的第一个结点的位置



    BiTNode *p;

    while(!isEmpty(Q)){

        DeQueue(Q,p);

         count++;

        if(p->lchild)
            EnQueue(Q,p->lchild);
        if(p->rchild)
            EnQueue(Q,p->rchild);

        if(Q.front==last){

            last=Q.rear;
            level++;

            if(count>width)
                width=count;
            count=0;
        }

    }

    return  width;

}

ThreadNode * first(ThreadTree T){  //中序线索二叉树第一个结点

    while(T->ltag==0){
        T=T->lchild;
    }
    return  T;
}
ThreadNode * last(ThreadTree T){//中序线索二叉树最后一个结点

    while(T->rtag==0){
        T=T->rchild;
    }
    return  T;
}
ThreadNode * ordernext(ThreadTree T){//中序线索二叉树后继结点

    if(T->rtag==1)
        return T->rchild;

    else
        return first(T->rchild);


}
ThreadNode * orderbefore(ThreadTree T){//中序线索二叉树前驱结点

    if(T->ltag==1)
        return T->lchild;

    else
        return last(T->lchild);


}

BiTNode *head,*rear= nullptr;

void LinkAllleaf(BiTree tree){

    if(tree){

        LinkAllleaf(tree->lchild);

        if(!tree->lchild&&!tree->rchild){
            if(!rear){
                head=tree;
                rear=tree;
            }
            else{
                rear->rchild=tree;
                rear=tree;
            }

    }

        LinkAllleaf(tree->rchild);
    }


}


 BiTNode * LinkAllleaf2(BiTree T){ //层序遍历连接所有叶结点

    if(!T)
        return nullptr;


    Queue Q;
    EnQueue(Q,T);


    BiTNode *p;
     BiTNode *head= nullptr;
     BiTNode *rear=nullptr;
    while(!isEmpty(Q)){

        DeQueue(Q,p);

        if(!p->lchild&&!p->rchild){

            if(!rear){
                head=p;
                rear=p;
            }
            else{
                rear->rchild=p;
                rear=p;
            }



        }

        else{
        if(p->lchild)
            EnQueue(Q,p->lchild);
        if(p->rchild)
            EnQueue(Q,p->rchild);
    }




    }

    return  head;

}

bool similar(BiTree T1,BiTree T2){ //两棵树相似

    if((!T1&&!T2)||(T1&&T2&&!T1->lchild&&!T2->lchild&&!T1->rchild&&!T2->rchild))//两树为空或都只有一个根节点

        return  1;


    if((T1||T2)&&!(T1&&T2)) //两树之一为空

        return 0;


    return similar(T1->lchild, T2->lchild)&& similar(T1->rchild, T2->rchild);//递归



}



void PreorderNok(BiTree tree,int &count,int k){  //先序第K个元素

    if(tree){
        count++;


        if(count==k)
            cout<<tree->data<<endl;
        else{
        PreorderNok(tree->lchild,count,k);

            PreorderNok(tree->rchild,count,k);}


    }


}




void WPL(BiTree tree,int depth,int &total){  //带权路径长度之和

    if(tree){

        if(!tree->lchild&&!tree->rchild)
        total+=tree->data*depth;

        WPL(tree->lchild,depth+1,total);

        WPL(tree->rchild,depth+1,total);

        }


}



void Height(BiTree tree,int depth,int &max){  //递归求树的高度

    if(tree){

        depth++;


        cout<<tree->data<<",depth="<<depth<<endl;
         if(depth>max)
             max=depth;
        Height(tree->lchild,depth,max);

        Height(tree->rchild,depth,max);

    }


}





int ifbalance(BiTree T){ //判断是否为平衡二叉树

    if(!T)

        return 0;

    else{

        int lheight=ifbalance(T->lchild);
        int rheight=ifbalance(T->rchild);

        if(abs(lheight-rheight)<=1)
            return 1+(lheight>rheight?lheight:rheight);
        else
          cout<<"find unbalanced"<<T->data<<endl;


    }





}



int main(){

    BiTree tree=new BiTNode(1);;

    tree->lchild=new BiTNode(2);
   tree->lchild->rchild=new BiTNode(5);
    tree->rchild=new BiTNode(3);
   tree->rchild->rchild=new BiTNode(5);
    tree->rchild->rchild->lchild=new BiTNode(4);
   tree->rchild->rchild->rchild=new BiTNode(6);
    tree->rchild->rchild->rchild->rchild=new BiTNode(8);
//ReverseLevelOrder(tree);

//cout<<findDepth(tree)<<endl;


//int x=0;


  //  hasTwoChild(tree,x);


//cout<<x<<endl;

//cout<<commonancestor(4,7)<<endl;



  //  deletex(tree,5);


//LevelOrder(tree);

 //   cout<<findWidthLevelly(tree)<<endl;


    ThreadTree  threadTree=new ThreadNode(4,0,0);

    threadTree->lchild=new ThreadNode(2,0,0);


    threadTree->lchild->lchild=new ThreadNode(1,1,1);
    threadTree->lchild->lchild->rchild=threadTree->lchild;


    threadTree->lchild->rchild=new ThreadNode(3,1,1);
    threadTree->lchild->rchild->lchild=threadTree->lchild;

    threadTree->lchild->rchild->rchild=threadTree;


    threadTree->rchild=new ThreadNode(6,0,0);


    threadTree->rchild->lchild=new ThreadNode(5,1,1);

    threadTree->rchild->lchild->lchild=threadTree;
    threadTree->rchild->lchild->rchild=threadTree->rchild;



    threadTree->rchild->rchild=new ThreadNode(7,1,1);

    threadTree->rchild->rchild->lchild=  threadTree->rchild;



   // PreorderNok(tree,x,4);

  //  PreHeight(tree,1,x);

  // PostOrderTraversal(tree);

     //cout<<LinkAllleaf2(tree)->rchild->data<<endl;

    findcommonancestor2(tree, tree->rchild->rchild->lchild, tree->rchild->rchild->rchild->rchild);




    BiTree tree2=new BiTNode(1);;

    tree2->lchild=new BiTNode(2);

    tree2->rchild=new BiTNode(3);

    tree2->lchild->lchild=new BiTNode(4);

    tree2->lchild->rchild=new BiTNode(5);


    tree2->rchild->lchild=new BiTNode(6);

    tree2->rchild->rchild=new BiTNode(7);
    
    
    int list[7]={1,2,3,4,5,6,7};
  //  pretopost(list,7);
    BiTree2 tree3=new BiTNode2('*');;

    tree3->left=new BiTNode2('+');

    tree3->left->right=new BiTNode2('b');


    tree3->left->left=new BiTNode2('a');

    tree3->right=new BiTNode2('*');

    tree3->right->left=new BiTNode2('c');
    tree3->right->right=new BiTNode2('-');
    tree3->right->right->right=new BiTNode2('d');




   // formula(tree3,1);


   // InorderPostpre(threadTree,threadTree->rchild->lchild);

  // ifbalance(tree);
  //  int x=0;
 // Height(tree,0,x);
 // cout<<x<<endl;
}


