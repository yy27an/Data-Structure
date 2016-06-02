//双向链表
typedef int ElemType;
typedef struct DNode
{
	/* data */
	ElemType data;
	struct DNode *prior, *next;
} DNode, *DLinkList;
//双向链表建立，采用尾插法建立双链表
DLinkList CreateDList(){
	Node *L, *p, *r;
	L=(Node *)malloc(sizeof(Node));		//申请头结点
	L->next=NULL;
	r=L;
	r-next=NULL;				//r为指向终端结点的指针
	ElemType e;					
	while(scanf("%d", &e)!=EOF){
		p=(Node *)malloc(sizeof(Node));
		p->data=e;
		p->next=r->next;
		r->next=p;
		r=p;
	}
	r->next=NULL;
	return L;
}
int GetElemtDList(DLinkList &L, ElemType e){		
	DLinkList p;			//p为搜索点
	p=L->next;
	int i=1;				
	while(p!=NULL&&p->data!=e) {i++; p=p->next;}
	if(p==NULL) return NULL;
	else return i;
}

//带头结点的双向循环链表L中p结点之前插入s结点
void InsertDList(DLinkList &L, DNode *p, DNode *s){
	s->prior=p->prior; p->prior->next=s;
	s->next=p; p->prior=s;
}
//将p插入到s后面
s->next=p->next; p->next->prior=s;
s->prior=p; p->next=s;

//删除带头结点的双向循环链表L中的p结点，并返回e的数据元素
void DeleteDList(DLinkList &L, DNode *p, ElemType e){
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
}

DLinkList InsertDList(DLinkList &L, int i, ElemType e){
	DLinkList p,s;
	p=L->next;
	for(int tempi=1;tempi<i-1;tempi++) p=p->next;
	s=(Node *)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next; p->next->prior=s;
	s->prior=p;	p->next=s;
	return L;
}

DLinkList DeleteDList(DLinkList &L, int i){
	int tempi=1;
	DLinkList p;
	p=L->next;
	while((tempi++)!=i&&p!=NULL) p=p->next;
	if(p==NULL) printf("位置不合法。\n");
	else if(p->next==NULL) {
		p->prior->next=NULL;
		free(p);
	}
	else{
		p->prior->next=p->next;
		p->next->prior=p->prior;
		free(p);
	}
	return L;
}


