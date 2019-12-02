#include "iostream"
#define MaxSize 50
using namespace std;


typedef  struct  Sqlist{

    int data[MaxSize];

    int length=0;

};


typedef struct LNode{

    int data;

    LNode (int data){
        this->data=data;
    }

    LNode *next= nullptr;

}*LinkList;


typedef struct SqStack{

    int data[MaxSize];

    int top=-1;



};

void swap(int &a,int &b) {
    int temp=a;

    a=b;

    b=temp;

}


bool isEmpty(SqStack &stack){

    if(stack.top!=-1)
        return 0;
    else
        return 1;


}
bool Push(SqStack &stack,int x){

    if(stack.top==MaxSize-1)
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


int length(LinkList L){

    int i=0;

    LNode *p=L->next;

    while(p){

        i++;
        p=p->next;
    }

    return i;



}




void InsertSort(Sqlist &list){ //顺序表插入排序

    int *data=list.data;

    for(int i=2;i<=list.length;++i){ //注意这里是等于号
        int j=i-1;
        data[0]=data[i];

        while(data[0]<data[j]){
            data[j+1]=data[j];//向后挪位
            j=j-1;
        }

        data[j+1]=data[0];

    }

}

void DoubleBubble(Sqlist &list) { //双向起泡,奇数趟从前往后，偶数趟从后往前

    int left = 0;                     //设置左指针
    int right = list.length - 1;      //设置右指针

    while (left < right) {

        for (int j = left; j <= right - 1; ++j) {

            if (list.data[j] > list.data[j + 1]) {

                swap(list.data[j],list.data[j+1]);
            }

        }

        right--;


        if (left >= right) {
            break;
        }

        for (int j = right; j >= left + 1; --j) {

            if (list.data[j] < list.data[j - 1]) {

                swap(list.data[j],list.data[j-1]);
            }

        }

        left++;


    }
}


void InsertSort(LinkList &L){ //单链表插入排序


    LNode *p,*pre,*q;
    p = L->next->next;		// 先保存下L的第二个元素，因为下一步要将L变成只有一个元素的有序表。
    L->next->next = NULL;	// 将L变成只有一个元素的有序表
    // 从L的第二个元素开始遍历整个L直至表尾
    while(p != NULL){
        q = p->next;
        pre = L;	// 先用pre来保存L。
        while(pre->next !=NULL && pre->next->data < p->data) // 遍历pre所指向的有序表L，直至找到比p大的节点
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }


}



void BubbleSort(Sqlist &list){ //顺序表冒泡排序

     for(int i=1;i<=list.length;++i){

            bool flag=false; //记录本趟是否发生交换

        for(int j=0;j<list.length-i;++j){

            if(list.data[j]>list.data[j+1]){

               swap(list.data[j],list.data[j+1]);
               flag=true;
            }

        }

        if(!flag) //说明表已经有序
         return;
    }

}


void BubbleSort(LinkList &L){ //单链表冒泡排序

    LNode *p=L->next;

    int len=length(L);

    int pass=1; //第一趟开始

    int i=0;   //单链表没有下标，但可以在了解表长后设置一个计数

    while(pass<=len){

        bool flag=false; //记录本趟是否发生交换
       while(i<len-pass){


           if(p->data>p->next->data){

               swap(p->data,p->next->data);
               flag=true;
           }

            p=p->next;
            i++;
        }

        if(!flag)
           return;

        p=L->next;
        i=0; //重置计数
        pass++;

    }


}


void SelectionSort(LinkList &L){ //链表的简单选择排序

    LNode *p =L->next;


    while(p!= nullptr) {

        LNode * minNode = p;

        for(LNode *t=p->next;t!= nullptr;t=t->next){

            if (t->data<minNode->data)

                minNode=t;

        }

        swap(p->data,minNode->data);

        p=p->next;


    }


}

void SelectionSort(Sqlist &L){ //顺序表的简单选择排序

    int *list=L.data;

    for(int i=0;i<L.length;++i){

        int minindex=i;

    for(int j=i+1;j<L.length;++j){

    if(list[j]<list[minindex])

                minindex=j;
              }

     swap(list[i],list[minindex]);

    }


}

int Partition(Sqlist &list,int low,int high){ //严蔚敏教材，快排分治法

    int pivot=list.data[low];


    while(low<high) {
        while (low < high && list.data[high] >= pivot){
            --high;

        }
        list.data[low] = list.data[high];

        while (low < high && list.data[low] <= pivot){
            ++low;

        }
        list.data[high] = list.data[low];
    }

    list.data[low]=pivot;

    return low;

}


void QuickSort(Sqlist &list,int low,int high){ //快速排序递归

    if(low<high) {

        int pivotpos = Partition(list, low, high);

        QuickSort(list, low, pivotpos - 1);

        QuickSort(list, pivotpos + 1, high);

    }
}


void  QuickSortStack(Sqlist &list,int low,int high){ //快排非递归

    int pivotpos = Partition(list, low, high);

    SqStack stack;

    Push(stack,low);
    Push(stack,high);

    while(!isEmpty(stack)){


        int high,low;
        Pop(stack,high);  //注意出栈顺序
        Pop(stack,low);

        if(low<high){

            int  pivotpos= Partition(list,low,high);

            Push(stack,low);
            Push(stack,pivotpos-1);
            Push(stack,pivotpos+1);
            Push(stack,high);

        }

    }

}
void display_Guard(Sqlist list){  //带哨兵位的顺序表输出，第一个元素用来存放哨兵位

    int i=1;


    while(i<=list.length){
        cout<<list.data[i]<<endl;
        ++i;
    }



}

void display(Sqlist list){  //顺序表输出

    int i=0;


    while(i<list.length){
        cout<<list.data[i]<<endl;
        ++i;
    }



}
void display(LinkList L){  //单链表输出

    LNode *p=L->next;

    while(p){

       cout<<p->data<<endl;
        p=p->next;
    }


}










int Partition2(Sqlist &list,int low,int high){ //教材习题的分治方法

    int pivot=list.data[low];

    int i=low;

    for(int j=low+1;j<=high;j++){

        if(list.data[j]<pivot)

         swap(list.data[++i],list.data[j]);  //往前开辟一个位置，把小的元素交换到前面（有可能自己交换自己）

    }


       swap(list.data[i],list.data[low]);                            //最后把枢轴放到合适的位置


    return  i;


}

void EvenToRight(Sqlist &list){ //分治思想，将所有的偶数移动到右侧

    int pivot=list.data[0];

    int low=0;

    int high=list.length;


    while(low<high){

        while(low<high&&list.data[high]%2==0){
            high--;}
        list.data[low]=list.data[high];

        while(low<high&&list.data[low]%2==1){
            low++;}
        list.data[high]=list.data[low];



    }
    list.data[low]=pivot;





}


void FindNok(Sqlist &list,int low,int high,int k){ //基于快速排序每次确定一个位置的原理，找到数组的第K个元素


    if(low<high) {

        int pivotpos = Partition(list, low, high);


        if(pivotpos==k-1)

            cout<<list.data[k-1]<<endl;


        if(pivotpos>k-1)


            FindNok(list, low, pivotpos - 1,k);


        if(pivotpos<k-1)


            FindNok(list, pivotpos + 1, high,k);

    }

    else{

        if(low==k-1){

            cout<<list.data[k-1]<<endl;
        }


    }







}

void AdjustDown(Sqlist &list,int k,int length){ //向下调整为大根堆


    list.data[0]=list.data[k];//哨兵位


    for(int i=2*k;i<=length;i*=2){

        if(i<length&&list.data[i]<list.data[i+1])
            i++;                                   //找到孩子节点中最大的

        if(list.data[0]>=list.data[i])           //若没有操作要做，不需继续向下调整
            break;

        else{
            list.data[k]=list.data[i];   //大的元素上移
            k=i; //继续向下调整


        }


        list.data[k]=list.data[0];//停放到最终位置上
    }



}
void BuildMaxHeap(Sqlist &list){ //自下而上调整为大根堆

    for(int i=list.length/2;i>0;--i)    //节点顺序存储，且第一个位置不放，下标从1开始

        AdjustDown(list,i,list.length);
}

void HeapSort(Sqlist &list){ //堆排序
    BuildMaxHeap(list); //初始建堆

    for(int i=list.length;i>1;--i){

       // cout<<list.data[1]<<endl; //输出开头元素
        swap(list.data[i],list.data[1]); //将堆首压入底部

        AdjustDown(list,1,i-1); //这是一种删除的方式,对剩余n-1个元素进行调整

    }


}



void ifSmallHeap(Sqlist list,int k,bool &valid ){ //判断是否为小根堆,

    if(valid) {

        if(k<=list.length) {

            int i = 2 * k;

            if (i <= list.length) {

                if (i < list.length && list.data[i] > list.data[i + 1]) //找到子节点最小的
                    i++;

                if(list.data[k]<list.data[i]){

                    ifSmallHeap(list,2*k,valid);
                    ifSmallHeap(list,2*k+1,valid);

                }

                else{
                    valid=false;
                }
            }
        }

    }






}

int list[9]; //需要一个辅助空间

void Merge(Sqlist &L,int low,int mid,int high){ //归并算法

    int i,j,k;

    for(k=low;k<=high;++k)
        list[k]=L.data[k];        //拷贝到辅助数组里

    for(i=low,j=mid+1,k=low;i<=mid&&j<=high;++k){

        if(list[i]<list[j])

            L.data[k]=list[i++];
        else
            L.data[k]=list[j++];

    }
    while(i<=mid)  L.data[k++]=list[i++];

    while(j<=high)  L.data[k++]=list[j++];


}

void MergeSort(Sqlist &L,int low,int high){ //归并排序递归

    if(low<high){

        int mid=(low+high)/2;

        MergeSort(L,low,mid);

        MergeSort(L,mid+1,high);


        Merge(L,low,mid,high);

    }

}

int main() {

    Sqlist list;
    list.data[0] = 0;

    list.data[1] = 12;
    list.data[2] = 17;


    list.data[3] = 78;

    list.data[4] = 9;
    list.data[5] = 45;
    list.data[6] = 65;

    list.data[7] = 87;
    list.data[8] = 32;
    list.length =9;

   // InsertSort(list);


    LinkList b=new LNode(9999) ;



    b->next=new LNode(1);;

    b->next->next=new LNode(2);;

    b->next->next->next=new LNode(3);

    b->next->next->next->next=new LNode(10);;




    //InsertSort(b);
//FindNok(list,0,8,3);
//QuickSort(list,0,8);

//QuickSortStack(list,0,8);
  //display(list);

//BubbleSort(b);

//display(b);

//BubbleSort(b);

MergeSort(list,0,8);



//display_Guard(list);

//SelectionSort(list);
display(list);

   // cout<<length(b)<<endl;











}