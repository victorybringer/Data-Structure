#define maxsize 50

#include "iostream"
#include "string"
using namespace std;


typedef struct Sqlist{

    int data[maxsize];



    int length=0;


};

bool insert(Sqlist &list,int n,int data) {

    if (n < 0 || n > list.length || list.length == maxsize)
        return -1;

    else {

        for (int i = list.length - 1; i >= n; --i) {

            list.data[i + 1] = list.data[i];
        }
        list.data[n] = data;

        list.length++;

    }
}
    bool deleteele(Sqlist &list,int n){

        if(n<0||n>=list.length||list.length==0)
            return -1;

        else{

            for(int i=n;i<list.length;++i){

                list.data[i]=list.data[i+1];
            }


            list.length--;

        }


}


void display(Sqlist list){

    for(int i=0;i<list.length;++i){

       cout<< list.data[i]<<endl;
    }
}


 string deletemin(Sqlist &list) { //删除顺序表最小结点，并返回值

    if(list.length==0)

        return "empty list";

    else {

        int *array=list.data;

        int min=array[0];

        int index=0;

        for(int i=1;i<list.length;++i) {

            if (array[i]<min) {

                min=array[i];
                index=i;
            }
        }


        array[index]=array[list.length-1]; //空位由最后一个元素填补

        list.length--;

        return min+"";
    }
}


 void swap(int a,int b,int * arr) {
    int temp=arr[a];

    arr[a]=arr[b];

    arr[b]=temp;


}

 void  reverselist(Sqlist &arr) { //将顺序表元素逆置

    if(arr.length!=0) {


        for(int i=0;i<arr.length/2;++i) {

            swap(i,arr.length-1-i,arr.data);

        }

    }

}



 void delete_X(Sqlist &arr,int x) { //移动法，删除顺序表中所有值为X的元素
    int *array=arr.data;
    int k=0;

    for(int i=0;i<arr.length;++i) {

        if(array[i]==x)

            k++;       //遇到x,计数加一

        else
            array[i-k]=array[i];  //向前移动k个单位

    }

    arr.length=arr.length-k;
}
 bool delete_range(Sqlist &arr,int s,int t) { //删除有序顺序表中所有值介于s,t之间的元素


    if(s<t||arr.length==0)

        return false;

    else {

        int *array=arr.data;

        int i,j;

        for(i=0;i<arr.length&&array[i]<s;++i) {}

        if(i==arr.length) //判断有无越界

            return false;

        else {

            for(j=i;j<arr.length&&array[j]<=t;++j) {}

            while(j<arr.length) { //移动

                array[i]=array[j];

                ++j;
                ++i;

            }

            arr.length=i; //


            return true;
        }
    }


}

bool delete_range2(Sqlist &arr,int s,int t) { //删除一般顺序表中所有值介于s,t之间的元素


    if(s<t||arr.length==0)

        return false;

    else {

        int *array=arr.data;

        int k=0;

        for(int i=0;i<arr.length;++i) {

            if(array[i]>=s&&array[i]<=t)

                k++;       //遇到x,计数加一

            else
                array[i-k]=array[i];  //向前移动k个单位

        }

        arr.length=arr.length-k;

        return true;

    }


}



 bool delete_repeat(Sqlist &arr) { //删除有序表中重复的元素


    if(arr.length==0)

        return false;

    else {

        int *array=arr.data;



        int i = 0,j=0;

        while(i<arr.length) {

            int k=0; //计数


            for(j=i+1;j<arr.length&&array[j]==array[i];++j,++k) {}


            for(int t=j;t<arr.length;++t) {

                array[t-k]=array[t];
            }

            arr.length-=k;
            ++i;
        }

        return true;

    }


}


static Sqlist combine(Sqlist arr1, Sqlist arr2) { //合并两个有序顺序表

    int length1=arr1.length;

    int length2=arr2.length;


    Sqlist newarray;


    int i=0,j=0;

    while(i<length1&&j<length2) {


        if(arr1.data[i]<arr2.data[j])

            newarray.data[newarray.length++]=arr1.data[i++];

        else

            newarray.data[newarray.length++]=arr2.data[j++];

    }

    while(i<length1) {

        newarray.data[newarray.length++]=arr1.data[i++];
    }


    while(j<length2) {

        newarray.data[newarray.length++]=arr2.data[j++];
    }



    return newarray;

}









static void exchangearr(Sqlist & arr,int m) { //交换两个有序顺序表(不需要额外辅助空间)

int n=arr.length-m;

    if(arr.length>m) {


        for(int i=0;i<m/2;++i) {

            swap(i,m-1-i,arr.data);

        }

        for(int i=0;i<n/2;++i) {

            swap(m+i,n-1-i+m,arr.data);

       }


        for(int i=0;i<arr.length/2;++i) {

            swap(i,arr.length-1-i,arr.data);

        }


    }


}


static void findxandinsert(Sqlist & arr,int x) { //找到有序顺序表中数值为X的元素，若无，就插入进表

    int *array=arr.data;

    int low=0;

    int high=arr.length-1;


    int mid = 0;

    while(low<=high) {

        mid=(low+high)/2;


        if(array[mid]==x) {

            break;
        }

        if(array[mid]<x) {

            low=mid+1;
        }

        if(array[mid]>x) {

            high=mid-1;
        }

    }



    if(array[mid]==x&&mid!=arr.length-1) {
        cout<<mid<<endl;
        swap(mid,mid+1,array);
    }

    if(low>high) {

        insert(arr,x, low);
    }



}





static void findmainele(Sqlist arr) { //统计大于一半的频数
//假设所有的数均在0到50之间
    int array[maxsize];


    for(int i=0;i<arr.length;++i){

       array[arr.data[i]]++;
    }

    for(int i=0;i<maxsize;++i) {

        if (array[i] > arr.length / 2)
            cout << i << endl;

    }



}

static int findminint(Sqlist arr) {  //最小正整数




    int *array=arr.data;

    int max=array[0];

    for(int i=1;i<arr.length;++i) {

        if(array[i]>max)

            max=array[i];

    }

    Sqlist newint;
    newint.length=max;

    for(int i=0;i<arr.length;++i) {

        if(array[i]-1>=0)
        newint.data[array[i]-1]=1;

    }


    int i;

    for( i=0;i<newint.length;++i) {

        if(newint.data[i]!=1) {

            break;


        }

    }


    return i+1;



}


int main(){

    Sqlist list;
    cout<<&list<<endl;
    list.data[0]=1;
    list.data[1]=5;
    list.data[2]=6;
    list.data[3]=4;
    list.data[4]=2;
    list.length=5;


//reverselist(list);

cout<<findminint(list)<<endl;
 //display(list);

}

