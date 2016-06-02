//栈 Stack
//顺序栈
#define StackSize 100;
typedef int SElemType;
typedef struct
{
	/* data */
	SElemType *elem;
	int top;		//栈顶指针
	int stacksize;	//分配的最大容量
} SqStack;

void InitStack(SqStack &S){
	S.elem=new SElemType[StackSize];
	S.top=-1;	//当前所含元素的个数
	S.stacksize=StackSize;
}

SElemType GetTopStack(SqStack &S, SElemType &e){
	if(S.top==-1) return NULL;
	else {
		e=S.elem[S.top];
		return e;
	}
}

void PushStack(SqStack &S, SElemType e){
	if(S.top==S.stacksize-1) IncrementStackSize(S)
	else S.ele[++S.top]=e;
}

Boolean PopStack(SqStack &S, SElemType e){
	if(S.top==-1) return FALSE;
	else {
		e=S.elem[S.top--];
		return TRUE;
	}
}

//链式栈
typedef int ElemType;
typedef struct Node
{
	/* data */
	ElemType data;
	struct Node *next;
} Node, *LinkList;
typedef LinkList LinkStack;

void InitLinkStack(LinkStack &S){S=NULL;}

void PushLinkStack(LinkStack &S, ElemType e){
	Node *p=new Node;
	p->data=e;
	p->next=S;
	S=p;
}

Boolean PopLinkStack(LinkStack &S, ElemType &e){
	Node *p, ElemType e;
	if(S){
		p=S;
		S=S->next;
		e=p->data;
		delete p;
		return TRUE;
	}
	return FALSE;
}



