#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"  /*动态存储分配函数头文件,当对内存区进行操作时,调用相关函数.ANSI标准建议使用stdlib.h头文件*/

//顺序线性表
const LIST_INIT_SIZE=100;  //线性表初始化分配最大的空间容量
const LISINCREMENTSIZE=10;	   //增补空间

typedef int ElemType;
typedef struct
{
	//ElemType data[MaxSize];
	ElemType *elem;		//存储数据元素的一维数组
	int length;			//线性表的当前长度
	int listsize;		//当前分配的数组容量以ElemType为单位
	int incrementsize;	//增补的容量以ElemType为单位
} SqList;
//初始化
void InitList_Sq(SqList &L, int maxsize=LIST_INIT_SIZE, int incresize=LISINCREMENTSIZE){
	//L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	L.elem=new ElemType[maxsize];		//所含元素的最大存储容量
	if(!L.elem) return 0;
	L.length=0;							//当前线性表中的所含有的元素个数
	L.listsize=maxsize;					//可容纳的maxsize个数据元素
	L.incrementsize=incresize;			//需要扩容的元素空间
}
//扩容函数
void Increment_Sq(SqList &L){
	//为顺序表扩大incrementsize个元素空间
	//定义临时线性表a， 辅助数据
	ElemType a[];
	a=new ElemType[L.listsize+L.incrementsize];		
	for(int i=0;i<L.length;i++) a[i]=L.elem[i];			//搬移原空间数据
	delete[] L.elem;					//释放原空间L.elem
	L.elem=a;							//移交空间首地址
	L.listsize+=L.incrementsize;		//更改更新后的容量信息
}
//查找
int LocateElem_Sq01(SqList &L, ElemType e){
	int i=1; 		//第一个元素的位序
	int P=L.elem;	//第一个元素的存储位置
	while(i<=L.length&&*p++!=e) ++i;		//e!=L.date[i]
	if(i<=length) return i;
	else return 0;
}
//插入
void Insert_Sq(SqList &L, int i, ElemType e){
	//在顺序线性表L的第i个元素之前插入新元素e
	//i合法值在1<=i<=L.length+1，若表中容量不足，则需增量扩容
	if(L.length>=L.listsize) Increment(L);
	else if(i<1||i>L.length+1) ErrorMessage("i值不合法");		//插入在最后一个
	else{
		q=&(L.elem[i-1]);			//q为插入的位置
		for(p=&(L.elem(L.length-1));p>=q;--p) *(p+1)=*p;
		*q=e;
		++L.length;
	}
}
//删除
void Delete_Sq(SqList &L, int i, ElemType &e){
	if(L.length<=0) ErrorMessage("空表");
	else if(i<1||i>L.length) ErrorMessage("i值不合法");
	else{
		p=&(L.elem[i-1]);
		e=*p;
		q=L.elem+L.length-1；
		for(++p;p<=q;++p) *(p-1)=*p;
		--L.length;
	}
}
//插入与删除平均需一定一半的元素
//销毁
void DestroyList_Sq(SqList &L){
	delete[] L.elem;
	L.listsize=0;
	L.length=0;
}

int Compare(SqList A, SqList B){
	//A<B则返回-1,A=B则返回0，A>B则返回1
	// int i=0;
	// while(i<A.length&&i<B.length){
	// 	if(A.elem[i]<B.elem[i]) return (-1);
	// 	else if(A.elem[i]>B.elem[i]) return (1);
	// 	else i++;
	// }
	for(int i=0;i<A.length&&i<B.length;i++){
		if(A.elem[i]<B.elem[i]) return (-1);
		else if(A.elem[i]>B.elem[i]) return (1);
		else i++;
	}
	if(A.length<B.length) return (-1);
	else if(A.length>B.length) return (1);
	else return (0);
}

//本算法实现请m个与后n的元素互换
void Exchange01(SqList &A, int m, int n){
	for(k=1;k<=n;k++){
		int w=A.elem[m+k-1];
		for(i=m+k-1;i>=k;i--) A.elem[i]=A.elem[i-1];
		A.elem[k-1]=w;
	}
}
//本算法将数组R中s到t的元素逆置
void Invert(ElemType &R[], int s, int t){
	for(k=s;k<=(s+t)/2;k++){
		w=R[k];
		R[k]=R[t-k+s];
		R[t-k+s]=w;
	}
}
void Exchange02(SqList &A, int m, int n){
	Invert(A.elem, 0, m+n-1);
	Invert(A.elem, 0, n-1);
	Invert(A.elem, n, m+n-1);
}
//
void Purge_Sq(SqList &A, SqList &B){
	A.elem[0]=B.elem[0];
	A.length=1;
	for(int i=0;i<B.length;i++){
		int e=B.elem[i];
		int j=0;
		while(j<A.length&&A.elem[j]!=e) ++j;
		if(j==A.length){
			A.elem[A.length]=e;
			A,length++;
		}
	}
}
//逆置
//定义顺序表为:
#define maxsize 100
typedef struct 
{
	int data[maxsize];//定义数据域
	int len;         //定义顺序表长度;
} sqlist;

//逆制一个顺序表的函数:
sqlist rev(sqlist sq){   //顺序表为sq;
	int i,temp,k=sq.len;
	for(i=0;i<k/2;i++){
		temp=sq.data[i];
		sq.data[i]=sq.data[k-i-1];
		sq.data[k-i-1]=temp;
	}
	for(i=0;i<k;i++)
	printf("%d",sq.data[i]);
	return sq;
}


//C++，指针使用少点，更加清晰
#define ListSize 100;
typedef int DataType;
typedef struct 
{
	/* data */
	DataType data[ListSize];
	int length;
} SeqList;

void InitList(SeqList *L){L->length=0;}

int LengthList(SeqList *L){ return L->length;}

DataType GetElementValue(SeqList *L, int i){ return L->data[i-1];}

int GetElementIndex(SeqList *L, DataType t){
	int i=0;
	// for(i=0;i<L->length;i++) if(t==L->data[i]) return i+1;
	// if(i==0) return NULL;
	while(i<L->length&&L->data[i]!=t) i++;
	if(L->data[i]==t) return i+1;
	else return NULL;
}

void InsertList(SeqList *L, DataType t, int i){
	//将t插入顺序表的第i个结点位置
	int j;
	if(L->length>=ListSize) ErrorMessage("表已满需扩容");
	else if(i<1||i>L->length+1) ErrorMessage("插入位置错误");
	else{
		for(j=L->length-1;j>=i-1;j--) L->data[j+1]=L->data[j];
			L->data[i-1]=t;
			L->length++;
	}
}

void DeleteList(SeqList *L, int i){
	int j;
	if(L->length==0) ErrorMessage("空表")；
	else if(i<1||i>L->length) ErrorMessage("删除位置有误")；
	else{
		for(j=i;j<=L->length-1;j++) L->data[j-1]=L->date[j];
		L->length--;
	}
}

——————————————————————————————————————————————————————————————————
//Draft

#define ListSize 100;
typedef int DataType;
typedef struct
{
	/* data */
	DataType data[ListSize];
	int length;
} SeqList;

void InitList(SeqList *L){ L->length=0; }

void LengthList(SeqList *L) { return L->length; }

DataType GetElementValue(SeqList *L, int i){ return L->data[i-1];}

int GetElementIndex(SeqList *L, DataType t){
	int i=0;
	while(i<L->length&&L->data[i]!=t) i++;
	if(L->data[i]==t) return i+1;
	else return NULL;
}

void InsertList(SeqList *L, DataType t, int i){
	int j;
	if(L->length>=ListSize) Errormessage("表已满");
	else if(i<1||i>L->length+1) Errormessage("插入位置有误");
	else{
		for(j=length-1;j>=i-1;j--) L->data[j+1]=L->data[j];
		L->data[i-1]=t; L->length++;
	}
}

void DeleteList(SeqList *L, int i){
	int j;
	if(L->length==0) Errormessage("表为空");
	else if(i<1||i>L->length) Errormessage("删除位置有误");
	else{
		for(j=i;j<L->length;j++) L->data[j-1]=L->data[j];
		L->length--;
	}
}

//全表逆置
void Invert(SeqList *L){
	int n=L->length,temp;
	for(int i=0;i<n/2;i++){temp=a[i]; a[i]=a[n-i-1]; a[n-i-1]=temp; }
}

void InvertLocal01(DataType R[], int h, int t){
	int temp;
	for(k=h;k<=(h+t)/2;k++){
		temp=R[k];
		R[k]=R[t-k+h];
		R[t-k+h]=temp;
	}
}
void InvertLocal02(SeqList *L, int h, int t){
	int temp;
	for(int k=h;k<=(h+t)/2;k++){
		temp=L->data[k];
		L->data[k]=L->data[t-k+h];
		L->data[t-k+h]=temp;
	}
}
void Exchange02(SeqList *L, int m, int n){
	InvertLocal02(L, 0, m+n-1);
	InvertLocal02(L, 0, n-1);
	InvertLocal02(L, n, m+n-1);
}
//这个单边的置换不太好
void Exchange01(SeqList *L, int m, int n){
	for(int k=0;k<=n;k++){
		int w=L->data[m+k-1];
		for(i=m+k-1;i>=k;i--) L->data[i]=L->data[i-1];
		L->data[k-1]=w;
	}
}


