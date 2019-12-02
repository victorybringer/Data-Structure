#define maxsize 50

#include "iostream"
#include "string"
using namespace std;


typedef struct LNode{

    int data;

    LNode (int data){
        this->data=data;
    }

    LNode *next= nullptr;

}*LinkList;


typedef struct DLNode{

    int data;

    DLNode (int data){
        this->data=data;
    }

    DLNode *next= nullptr;
    DLNode *pre= nullptr;
}*DLinkList;


void InsertHead(LinkList &L) {


    int x;

    scanf("%d",&x);

    while(x!=9999){

    LNode *p = new LNode(x);

    p->next = L->next;

    L->next = p;

    scanf("%d",&x);
    }
}

void Inserttail(LinkList &L,int data) {

    LNode *rear=L;

    int x;

    scanf("%d",&x);

    while(x!=9999){

        LNode *p = new LNode(x);

        rear->next = p;
        rear=p;

        scanf("%d",&x);
    }


}


LNode * GetElebyindex(LinkList  &L,int index){ //带头结点,返回第i个位置的结点

    if(index==0){


        return L;
    }
    else{
    int count=0;
    LNode *p=L->next;


    while(p!= nullptr){

        ++count;

        if(count==index)
            break;

        p=p->next;
        }
        return  p;

    }



}

LinkList insert(LinkList &L,int index,int data){

    LNode *p=GetElebyindex(L,index-1);

    LNode * s= new LNode(data);

    s->next = p->next;

    p->next = s;


}


LinkList deleteele(LinkList &L,int index){

    LNode *p=GetElebyindex(L,index-1);

    LNode *s=p->next;

    p->next= s->next;

    free(s);


}

void deleteele_stack(LinkList &L,int targetindex,int curindex){

   if(curindex!=targetindex){

       deleteele_stack(L->next,targetindex,curindex+1);
   }

   else{
       LNode *p=L;
       L=L->next;
       free(p);
   }
}





LinkList display(LinkList &L){

   LNode *p=L;

   while (p!= nullptr){

       cout<<p->data<<endl;

       p=p->next;
   }

}




void reverse(LinkList L){ //单链表逆置



    LNode * p=L->next;
    LNode * r; //

    L->next=NULL; //断链

    while(p!=NULL){

        r=p->next;

        p->next=L->next;//断链

        L->next=p;

        p=r;

    }

}


void deletex_stack(LinkList &L,int x) { //递归删除数据为X的所有结点

    if(L!=nullptr){

        if(L->data==x) {

            LNode *p=L;
            L=L->next;
            free(p);
            deletex_stack(L,x);
        }

        else

            {

            deletex_stack(L->next,x);

        }

    }

}

 void deletex(LinkList &L,int x) { //删除数据为X的所有结点

    LNode* p=L->next;

    LNode* pre=L;

    while(p!=nullptr) {

        if(p->data==x) {


            LNode * q = p;  //遍历还需用到这个名字p，所以要另外定义一个名字

            pre->next = p->next;

            p = p->next;

            free(q);


        }

        else {

            pre=p;
            p=p->next;
        }

    }





}

static void reverseprint(LinkList &L) { //反向输出序列

 reverse(L);
 display(L);


}

 void deletemin(LinkList &L) { //删除最小结点

    LNode* pre=L;

    LNode* p=L->next;

    LNode* minpre=L;
    LNode* minlink=L->next;



    while(p!=nullptr) {


        if(p->data<minlink->data) {


            minlink=p;

            minpre=pre;


        }

        else {



            p=p->next;
            pre=pre->next;
        }

    }

    cout<<minlink->data<<endl;
    minpre->next=minlink->next;

    free(minlink);

}


void deleteminrepeatly(LinkList &L) { //依次删除最小结点，最后删除头结点

   while(L->next){

       deletemin(L);

   }

   free(L);

}



int length(LinkList L){ //链表长度，不计入头结点

    LNode *p=L->next;

    int k=0;

    while(p!= nullptr){
        k++;
        p=p->next;

    }

    return  k;

}

LNode * SearchCommon(LinkList &l1,LinkList &l2){ //找两个链表的公共结点

    int n1=length(l1);
    int n2=length(l2);
    LNode * longlist;
    LNode * shortlist;
    if(n1>n2)
    {
        longlist=l1->next;
        shortlist=l2->next;
    }

    else{

        longlist=l2->next;
        shortlist=l1->next;
    }

    int dist=n1-n2>0?n1-n2:n2-n1;


    while(dist>0){

        longlist=longlist->next;
        dist--;
    }

    while(longlist!= nullptr){

        if(longlist==shortlist)

            return longlist;

        else{
            longlist=longlist->next;
            shortlist=shortlist->next;

        }

    }
        return nullptr;


}


void dividebyeven(LinkList &A,LinkList &B){ //按照奇偶分成两个表,保持相对顺序不变

    int k=0;

    LNode *p=A->next;
    LNode *p1=A;
    LNode *p2=B;

    A->next=NULL; //断链

    while(p!=NULL){
        k++;

        LNode *r =p->next;


        if(k%2==1){

            p1->next=p;

            p1=p;

            p1->next= nullptr;

        }
        else{
            p2->next=p;

            p2=p;
            p2->next= nullptr;

        }

        p=r;
    }



}

void deleterepeat(LinkList &A){ //删除重复元素

    LNode *p=A->next;


    while(p!=NULL){

        LNode *t=p->next;

        while(t!=NULL&&t->data==p->data){
            LNode * q=t;
            p->next=t->next;
            t=t->next;
            free(q);

        }


        p=t;



    }

}


void  combine(LinkList &A,LinkList &B){ //合并两个单链表，并以递减顺序存储




    LNode * p1=A->next;

    LNode * p2=B->next;

    A->next=NULL; //断链

    while(p1&&p2){

        if(p1->data<=p2->data){

            LNode *r=p1->next;

            p1->next=A->next;

            A->next=p1;

            p1=r;
        }


        else{
            LNode *r=p2->next;

            p2->next=A->next;

            A->next=p2;

            p2=r;

        }



    }

    while(p1){
        LNode *r=p1->next;

        p1->next=A->next;

        A->next=p1;

        p1=r;
    }


    while(p2){
        LNode *r=p2->next;

        p2->next=A->next;

        A->next=p2;

        p2=r;
    }

}


void cross(LinkList &A,LinkList &B,LinkList &C){ //找到两个有序单链表的公共元素，并放入新的单链表C


  
    LNode * p1=A->next;

    LNode * p2=B->next;

    LNode * p3=C;
    while(p1&&p2){

        if(p1->data<p2->data){
            p1=p1->next;
        }

        else{
            if(p1->data>p2->data)

                p2=p2->next;

            else
               {

                LNode * t=new LNode(p1->data);

                p3->next=t;
                p3=t;

                p1=p1->next;
                p2=p2->next;

            }
        }






    }


}


void cross(LinkList &A,LinkList &B){ //找到两个有序单链表的公共元素，并存于第一个表中



    LNode * p1=A->next;

    A->next= nullptr; //断链


    LNode * rear=A; //尾指针


    LNode * p2=B->next;



    while(p1&&p2){

        if(p1->data<p2->data){
            p1=p1->next;
        }

        else{
            if(p1->data>p2->data)

                p2=p2->next;

            else
            {

             LNode *t=p1->next;

             rear->next=p1;


             p1->next= nullptr;//断链,尾插法

             rear=p1;

             p1=t;

            }
        }






    }


}

bool ifSub(LinkList &A ,LinkList &B ){ //判断B是否是A的子序列，采用简单的类似于模式匹配的算法

    LNode *p1=A->next;
    LNode *pre=A->next; //记住每一次匹配的起点，之后匹配失败会退回
    LNode *p2=B->next;


    while(p1&&p2){


        if(p1->data==p2->data){

            p1=p1->next;
            p2=p2->next;
        }


else{

    pre=pre->next;

    p1=pre;

    p2=B->next;

}




    }


if(p2== nullptr)

    return 1;

else

    return 0;






}


void combinetworerverse(LinkList &A ,LinkList &B ){ //连接两个带头结点循环链表，A为起点

    LNode * h1=A;
    while(h1->next!=A){h1=h1->next;}


    LNode *h2 =B;
    while(h2->next!=B){h2=h2->next;}


    h1->next=B;

    h2->next=A;



}


bool ifmirror(DLinkList &A){//判断一个带头结点循环双链表是否对称

    DLNode *rear=A->pre;

    DLNode *front=A->next;


    while(rear!=front&&front->next!=rear){

        if(rear->data!=front->data)
            return 0;


    }

    return 1;


}

void deleteabsolute(LinkList &A,int range){//删除绝对值相同结点,仅保留第一次出现的

    int list[range+1];

    for(int i=0;i<=range;++i){

        list[i]=0;
    }

    LNode *p=A->next;
    LNode *pre=A;

    while(p!= nullptr){




        if(list[abs(p->data)]==0){

        list[abs(p->data)]++;
        pre=p;
        p=p->next;
        }


        else{
        LNode *r=p;
        pre->next=p->next;
        p=p->next;
        free(r);

        }


    }


}


void reverseK(LinkList &A,int k){  //找到单链表倒数第K个结点

    LNode *p=A->next;

    LNode *q=A->next;

    int count=1;


    while(p->next){
        p=p->next;

        if(count<k)
          count++;
        else
         q=q->next;

    }
    cout<<q->data<<endl;


}


int main(){

    LinkList a=new LNode(9999) ;



       a->next=new LNode(1);;

     a->next->next=new LNode(2);;

   a->next->next->next=new LNode(-2);

   a->next->next->next->next=new LNode(5);;


    LinkList b=new LNode(9999) ;



    b->next=new LNode(2);;

    b->next->next=new LNode(3);;

    b->next->next->next=new LNode(8);

    b->next->next->next->next=new LNode(10);;

   //deletex_stack(a,2);
//deletex(a,2);

 // deleteele_stack(a,0,0);
 // display(a);

 //deleteminrepeatly(a);

 //LinkList  B=new LNode(9999);
   // dividebyeven(a,B);
   //deleterepeat(a);

//combine(a,b);

  //     LinkList c=new LNode(9999);
   // cross(a,b);

   //deleteabsolute(a,5);
   // display( a);


   reverseK(a,3);
}