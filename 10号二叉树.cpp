#include <iostream>
#include <malloc.h>
using namespace std;
char ch;
int m, n;
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef BiTree QueueElementType;
typedef struct Node
{
    QueueElementType data;
    struct Node  *next;
} LinkQueueNode;

typedef struct
{
    LinkQueueNode *front; 
    LinkQueueNode *rear;
} LinkQueue;


//ǰ�����������������
void InitBiTree(BiTree& T) {
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		InitBiTree(T->lchild);
		InitBiTree(T->rchild);
	}
}
//����������
void TraverseBiTree(BiTree T, int number) {
	if (T) {
		if (number == 0) cout << T->data << " ";//�������
		TraverseBiTree(T->lchild, number);
		if (number == 1) cout << T->data << " ";//�������
		TraverseBiTree(T->rchild, number);
		if (number == 2) cout << T->data << " ";//�������
	}
}
//�ڵ���
int NodeCout(BiTree T) {
	if (T)
		return NodeCout(T->lchild) + NodeCout(T->rchild) + 1;
	else
		return 0;
}
//Ҷ�ӽڵ���
int LeafNodeCout(BiTree T) {
	if (T) {
		if (T->lchild or T->rchild) {
			return LeafNodeCout(T->lchild) + LeafNodeCout(T->rchild);
		}
		else
			return 1;
	}
	else
		return 0;
}

//������ʾ��
void Dent(BiTree T, int depth) {
	int i;
	if (T) {
		for (i = 0; i < depth; i++) {
			cout << T->data;
		}
		cout << endl;
		Dent(T->lchild, depth - 1);
		Dent(T->rchild, depth - 1);
	}
}

//��ʼ������
int InitQueue(LinkQueue *Q ) {
    Q->front=(LinkQueueNode * )malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL){
        Q->rear=Q->front;
        Q->front->next=NULL;
        return 1;
    }
    else return 0;//���
}
//Ԫ��x�������� β�巨
int EnterQueue(LinkQueue *Q,QueueElementType x) {
    LinkQueueNode * newnode;
    newnode=(LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if(newnode != NULL){

        newnode->data=x;
        newnode->next=NULL;
        Q->rear->next=newnode;
        Q->rear=newnode;
        return 1;
    }
    else
		return 0;
}
//�����г��� �ӿ�ʼ��ͷ��ʼȡ
int DeleteQueue(LinkQueue *Q,QueueElementType *x ) {
    LinkQueueNode *p;
    if(Q->front==Q->rear)
        return 0;
    p=Q->front->next;
    Q->front->next=p->next;
    if(Q->rear==p )
         Q->rear=Q->front;  //���ȥ�����p�󣬶���Ϊ�� ��Ҫ���ǽ������ÿ�
    *x=p->data;
    free(p);
    return 1;
}
//��α���
int LevelOrderTraverse(BiTree  T) {
	LinkQueue  Q;
    BiTree p;
    InitQueue(&Q);
    if(T==NULL)
		return 0;
    EnterQueue(&Q,T);
    while(Q.front!=Q.rear){
        if(DeleteQueue(&Q,&p));
            cout<<p->data;
        if(p->lchild)
			EnterQueue(&Q,p->lchild);
        if(p->rchild)
			EnterQueue(&Q,p->rchild);
    }
    return 1;

}
//���������
int Depth(BiTree T) {
	if (T) {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		return m > n ? m + 1 : n + 1;
	}
	else
		return 0;
}
//����չʾ
void ShowFuntion() {
	cout << "\t\t\t\t�� �� �� �� ϵ ͳ" << endl;
	cout << "***************************************************************************" << endl;
	cout << "1.��������\t2.������ʾ\t3.�������\t4.�������\t5.�������" << endl;
	cout << "6.��α���\t7.��Ҷ����\t8.��ڵ���\t9.�������\t0.��    ��" << endl;
	cout << "***************************************************************************" << endl;
	cout << "��ѡ����Ӧ�Ĺ�����ţ�";
}
int main() {
	int j;
	BiTree Tree=NULL;
	while (true) {
		ShowFuntion();
		cin >> j;
		cout << endl;
		switch (j) {
		case 1:
			cout<<"ǰ�������������������'#'��ʾ�գ�"<<endl;
			InitBiTree(Tree);
			break;
		case 2:
			cout<<"������ʾ"<<endl;
			Dent(Tree, Depth(Tree));
			break;
		case 3:
			cout << endl << "�������:";
			TraverseBiTree(Tree, 0);
			cout<<endl;
			break;
		case 4:
			cout << endl << "�������:";
			TraverseBiTree(Tree, 1);
			cout<<endl;
			break;
		case 5:
			cout << endl << "�������:";
			TraverseBiTree(Tree, 2);
			cout<<endl;
			break;
		case 6:
			cout << "��α���" ;
			LevelOrderTraverse(Tree);
			cout<<endl;
			break;
		case 7:
			cout << "Ҷ�ӽڵ�����";
			cout<<LeafNodeCout(Tree)<<endl;
			break;
		case 8:
			cout << "�ڵ�����";
			cout<<NodeCout(Tree)<<endl;
			break;
		case 9:
			cout << "��������ȣ�";
			cout<<Depth(Tree)<<endl;
			break;
		case 0:return 0;
		}
	}
}
