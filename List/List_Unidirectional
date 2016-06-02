//单向链表的基本操作

typedef int ElemType;
typedef struct LNode  //定义链表节点类型
{
	/* data */
	ElemType data;		//单链表中的数据域 
	struct LNode *next;	//单链表中的指针域
} LNode, *LinkList;		//分别定义结构体变量， 结构体指针存储地址

int LengthList(LinkList L){
	LNode *p=L; int k=0;
	while(p){ k++; p=p->next;}
	return k;
}

LNode* GetElem(LinkList L, ElemType e){
	LNode *p=L;
	while(p&&p->data！=e) p=p->next;
	return p;
}
//插在p节点前面
void InsertList(LinkList &L, LNode *p, LNode *s){
	//指针P指向L为头指针的某一个节点，将s结点插入到p结点之前
	if(p==L){s->next=L; L=s;}
	else {
		LNode *q=L;
		while(q->next！=p) q=q->next;
		q->next=s; s->next=p;
	}
}
//删除p多指向的节点并返回该值e
void　DeleteList(LinkList &L, LNode *p){
	ElemType e;
	if(p==L) L=p->next;
	else{
		LNode *q=L;
		while(q->next!=p) q=q->next;
		q->next=q->next->next;
	}
	e=p->data; delete p;
}
//逆序创建链表
void CreateList_Invert(LinkList &L, ElemType A[], int n){
	L=NULL; L->next=NULL;
	for(i=n-1;i>=0;--i){
		Node *s=(LNode *)malloc(sizeof(LNode));
		s->data=A[i];
		s->next=L;
		L=s;
	}
}
//顺序创建链表
void CreateList(LinkList &L, ElemType A[], int n){
	L=NULL;
	LNode *r=L;
	for(i=0;i<n;i++){
		Node *s=(LNode *)malloc(sizeof(LNode));
		s->data=A[i];
		r->next=s 
		r=s;
	}
	if(r!=NULL) r->next=NULL;
	return L;
}
//逆置单链表
void InvertLinkList(LinkList &L){
	//逆置头指针L所在的表
	LNode *p=L; L=NULL;		//逆置后的链表初值为空表
	while(p){				//p为待排序的头指针
		LNode *s=p; p=p->next;			//从p所指链表中删除第一个结点(s结点), s即为头结点
		s->next=L; L=s;				//将s结点插入到逆置表的表头
	}
}


