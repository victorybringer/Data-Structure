#include "iostream"
#define MaxSize 50
using namespace std;


typedef  struct  Sqlist{

    int data[MaxSize];

    int length=0;

};




void SqSearch(Sqlist list,int key){ //一般顺序表的顺序查找

    int *data=list.data;
    data[0]=key; //哨兵位，防止下标越界

    int i;
    for(i=list.length;data[i]!=key;--i){}

        cout<<i<<endl;

}


void B_Search(Sqlist list,int low,int high,int key){ //二分查找

    if(low<=high){ //这里是等于，区别于归并排序

        int mid=(low+high)/2;

        if(list.data[mid]==key)
            cout<<mid<<endl;

        else if(list.data[mid]<key)

            B_Search(list,mid+1,high,key);


        else
            B_Search(list,low,mid-1,key);

    }


}


void SIMPLE_MATCH(Sqlist main,Sqlist sub,int pos){ //简单模式匹配,主串回溯

    int i=pos,j=1;

    int *mainstring=main.data;

    int *substring=sub.data;

    while(i<=main.length&&j<=sub.length){


        if(mainstring[i]==substring[j]){
            ++i;++j;
        }

        else{   //回退

            i=i-(j-1)+1; //匹配起始位置+1
            j=1;

        }


    }


if(j>sub.length)
cout<<"start from "<<i-(j-1)<<endl;


}


void get_next(Sqlist T,int next[]){ //得到next数组

    int *list=T.data;

    int i=1,j=0;
    next[1]=0;

    while(i<T.length){

        if (j==0||list[i] == list[j]) {

            ++i;
            ++j;

            next[i]=j;
        }

        else
            j=next[j];

    }

}





void KMP_MATCH(Sqlist main,Sqlist sub,int next[],int pos) { //改进的模式匹配,主串不回溯

    int i=pos, j = 1;

    int *mainstring = main.data;

    int *substring = sub.data;

    while (i <= main.length && j <= sub.length) {


        if (j==0||mainstring[i] == substring[j]) {

            ++i;
            ++j;

        }

        else
            j=next[j];

        }

    if(j>sub.length)
        cout<<"start from "<<i-(j-1)<<endl; //匹配起始位置
}







int main(){

    Sqlist list;
   // list.data[0]=1;
    list.data[1]=2;

    list.data[2]=6;

    list.data[3]=8;
    list.data[4]=6;

    list.data[5]=10;

     list.length=5;



     Sqlist list2;

    list2.data[1]=6;

    list2.data[2]=8;
    list2.data[3]=6;

    list2.length=3;


    int next[4]={0,0,1,1};  //第一位不要考虑


    //B_Search(list,1,5,6);
    SIMPLE_MATCH(list,list2,1);





    return 0;
}