#define maxsize 50
#define  MaxVertexNum 100
using namespace std;

#include "iostream"
#include "string"
typedef  struct BiTNode {

    BiTNode* lchild = NULL;
    BiTNode* rchild = NULL;

    int data;

    BiTNode(int data) {
        this->data = data;

    }


}*BiTree;

typedef struct ArcNode {


    int data;



    ArcNode* next = NULL;
    ArcNode(int data) {

        this->data = data;
    }

};


typedef struct LNode {

    int data;

    LNode(int data) {
        this->data = data;
    }

    LNode* next = NULL;

}*LinkList;


typedef struct VNode {


    int data;


    ArcNode* next = NULL;



};

typedef struct Graph {

    VNode vertices[MaxVertexNum];

    int vexnumber;



};


void findeminandmax(BiTree T) {

    BiTNode* p = T;

    while (p->rchild) {
        p = p->rchild;
    }

    cout << "最大元素" << p->data << endl;

    p = T;

    while (p->lchild) {
        p = p->lchild;
    }

    cout << "最小元素" << p->data << endl;

}


void swap(int& a, int& b) {
    int temp = a;

    a = b;

    b = temp;

}


void SelectionSort(LinkList& L) { //链表的简单选择排序

    LNode* p = L->next;


    while (p) {

        LNode* minNode = p;

        for (LNode* t = p->next; t; t = t->next) {

            if (t->data < minNode->data)

                minNode = t;

        }

        swap(p->data, minNode->data);

        p = p->next;


    }


}



void display(LinkList L) {

    LNode* p = L->next;

    while (p) {

        cout << p->data << endl;
        p = p->next;
    }


}


void Allcombine(char data[], int length, string s) {

    if (s.length() == length)

        cout << "全排列序列" + s << endl;

    else

        for (int i = 0; i < length; ++i) {

            if (s.find(data[i]) == string::npos)

                Allcombine(data, length, s + data[i]);

        }


}



bool visited[MaxVertexNum];



int FirstNeighbour(Graph G, int vex) {


    return G.vertices[vex].next ? G.vertices[vex].next->data : -1;


}

int NextNeighbour(Graph G, int vex, int num) {

    ArcNode* p = G.vertices[vex].next;

    while (p->data != num) {


        p = p->next;

    }

    if (p->next)
        return p->next->data;

    else
        return -1;

}







void DFS(Graph G, int i) {

    visited[i] = true;

   
    for (int w = FirstNeighbour(G, i); w >= 0; w = NextNeighbour(G, i, w)) {
        
        if (!visited[w])
            DFS(G, w);

    }

}
void DFSTraverse(Graph G) {

    int count = 0;

    for (int i = 0; i < G.vexnumber; ++i) {

        if (!visited[i]) {
            count++; //连通分量数+1
            DFS(G, i);
        }



    }

    cout<<"连通分量数"<<count<<endl;
}




int main() {

    BiTree  T = new BiTNode(4);

    T->lchild = new BiTNode(2);


    T->lchild->lchild = new BiTNode(1);

    T->lchild->rchild = new BiTNode(3);


    T->rchild = new BiTNode(6);


    T->rchild->lchild = new BiTNode(5);

    T->rchild->rchild = new BiTNode(7);





    findeminandmax(T);




    VNode v0;
    v0.data = 0;
    VNode v1;
    v1.data = 1;
    VNode v2;
    v2.data = 2;
    VNode v3;
    v3.data = 3;

   



    ArcNode* a1 = new ArcNode(1);

    ArcNode* a2 = new ArcNode(2);

    ArcNode* a3 = new ArcNode(3);

    v0.next = a2;

    v2.next = new ArcNode(3);
  

    Graph G;
 

    G.vertices[0] = v0;

    G.vertices[1] = v1;

    G.vertices[2] = v2;

    G.vertices[3] = v3;


    G.vexnumber = 4;



    LinkList b = new LNode(9999);



    b->next = new LNode(4);

    b->next->next = new LNode(2);

    b->next->next->next = new LNode(1);
    b->next->next->next->next = new LNode(10);
    b->next->next->next->next->next = new LNode(3);


    SelectionSort(b);

    display(b);


    char data[4] = { '1','2','3','4' };

    Allcombine(data, 4, "");


    DFSTraverse(G);

}
