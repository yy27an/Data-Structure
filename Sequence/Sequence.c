//折半查找
#include <stdio.h>
int main(){
	int a[15],temp;
	bool sign=ture;
	for(int i=0;i<15;i++){
		scanf("请依次输入15个数:%d",&a[i]);
	}
	printf("请输入查找数:\n");
	scanf("%d",&temp);
	for(int i,start=0,end=14;start<=end){
		i=start+(end-start)/2;
		if(temp==a[i]) {printf("可以找到是％d个数",a[i+1]);sign=break;}
		else if(temp>a[i]) start=i+1;
		else end=i-1;
	}
	if(sign) printf("没有找到\n");
	printf("\n");
	fflush(stdin);  //刷新键盘缓冲区
 	getchar();
    return 0;
}
//对分查找
int BinarySearch(const ElementType A[], ElementType x, int N){
	int Low,Mid,High;
	Low=0; High=N-1;
	while(Low<=High){
		Mid=(Low+High)/2;
		if(A[Mid]<x) Low=Mid+1;
		else if(A[Mid]>x) High=Mid-1;
		else return Mid;
	}
	return NoFound;
}

——————————————————————————————————————————————————————————————————————————————————————
//冒泡排序,从大到小
#include <stdio.h>
int main(){
	int t,a[10];
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	//int a[10]={25,17,76,34,77,8,189,87,69,10};
	for(int j=0;j<9;j++){
		for(int i=0;i<9-j;i++){
			if(a[i]>a[i+1]) {t=a[i];a[i]=a[i+1];a[i+1]=t;}
		}
	}
	for(int i=0;i<10;i++){
		printf("排序结果为:%d",a[i]);
	}
	printf("\n");
	fflush(stdin);  //刷新键盘缓冲区
 	getchar();
    return 0;
}

void BubbleSort1(int a[],int n){
	int i,j;
	for(i=0;i<10;i++)
		for(j=1;j<n-i;j++)
			if(a[j-1]>a[j]) swap(a[j-1],a[j]);
}

void BubbleSort2(int a[],int n){
	int j,k; bool flag;
	k=n; flag=true;
	while(flag){
		flag=false;
		for(j=1;j<k;j++)
			if(a[j-1]>a[j]) {swap(a[j-1],a[j]);flag=true;}
		k--;
	}
}

void BubbleSort3(int a[],int n){
	for(int flag=n,k;flag;){
		k=flag;flag=0;
		for(int j=1;j<k;j++)
			if(a[j-1]>a[j]) {swap(a[j-1],a[j]);flag=j;}
	}
}

——————————————————————————————————————————————————————————————————————————————————————

//选择法排序
#include <stdio.h>
int main(){
	int a[10],k,t;
	prinf("请输入10个数:\n");
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<9;i++){
		k=i;
		for(int j=i+1;j<10;j++) if(a[k]>a[j]) k=j;//k换成i区别
		if(k!=i) t=a[i];a[i]=a[k];a[k]=a[i];
	}
	for(int i=0;i<10;i++){
		printf("排序结果为:%d",a[i]);
	}
	printf("\n");
	fflush(stdin);  //刷新键盘缓冲区
 	getchar();
    return 0;
}

void ChooseSort(int a[],int n){
	for(int i=0,k;i<(n-1);i++)
		for(int j=i+1;j<n;j++){
			k=i;
			if(a[k]>a[j]) k=j;
		}
		if(k!=i) swap(a[i],a[k]);
}

——————————————————————————————————————————————————————————————————————————————————————
//插入排序
void InsertSort1(int a[],int n){
	for(int i=1;i<n;i++)
		if(a[i]<a[i-1]){
			int temp=a[i];
			for(j=i-1;j>=0&&temp<a[j];j--) a[j+1]=a[j];
			a[j+1]=temp;
		}
}

void InsertSort2(int a[],int n){
	for(int i=1;i<n;i++){
		int j=i-1, temp=a[i];
		while(j>=0&&temp<a[j]){
			a[j+1]=a[j]; j--;
		}
		a[j+1]=temp;
	}
}

void InsertSort3(int a[],int n){
	for(int i=1;i<n;i++)
		for(int j=i-1;j>=0&&a[j+1]<a[j];j--)
			swap(a[j],a[j+1]);
}

//用折半查找法找出检查数前面有序数列的插入位置
void BinaryInsertSort(int a[],int n){
	for(int i=2;i<n;i++){
		int index=FindInsertIndex(a,i,a[i]);
		if(i!=index){
			int j=i, temp=a[i];
			while(j>index){a[j]=a[j-1];j--;}
			a[j]=temp;
		}
	}
}

int FindInsertIndex(int a[],int iLen,int iData){
	int iBegin=0, iEnd=iLen-1, index=-1;
	while(iBegin<iEnd){
		int inedx=iBegin+(iEnd-iBegin)/2;
		if(iData<a[index]) iEnd=index-1;
		else iBegin=index+1;
	}
	if(iData>=a[index]) index++;
	return index;
}
——————————————————————————————————————————————————————————————————————————————————————

//快速排序
void QuickSort(int a[],int l,int r){
	//swap(l,(l+r)/2); 
	for(l<r){
		int i=l,j=r,x=a[l];
		while(i<j){
			while(i<j&&a[j]>=x) j--;
		    if(i<j) a[i++]=a[j];
		    while(i<j&&a[i]<=x) i++;
		    if(i<j) a[j--]=a[i];
		}
		a[i]=x;
		QuickSort(a,l,i-1);
		QuickSort(a,i+1.r)
	}
}

——————————————————————————————————————————————————————————————————————————————————————
//归并排序
//将有二个有序数列a[first...mid]和a[mid...last]合并。  
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  
void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);    //左边有序  
        mergesort(a, mid + 1, last, temp); //右边有序  
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并  
    }  
}  
bool MergeSort(int a[], int n)  
{  
    int *p = new int[n];  
    if (p == NULL)  
        return false;  
    mergesort(a, 0, n - 1, p);  
    delete[] p;  
    return true;  
}

bool MerageSort(int a[],int n){
	int *p=new int[n];
	if(p==NULL) return false;
	meragesort(a,0,n-1,p);
	delete[] p;
	return true;
}

void meragesort(int a[],int first,int last,int temp[]){
	for(first<last){
		int mid=(first+last)/2;
		meragesort(a,first,mid,temp);
		meragesort(a,mid+1,last,temp);
		MerageArray(a,first,mid,last,temp);
	}
}

void MerageArray(int a[],int first,int mid,int last,int temp[]){
	int i=first,j=mid+1,m=mid,n=last,k=0;
	while(i<=mid&&j<=last){
		if(a[i]<=a[j]) temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid) temp[k++]=a[i++];
	while(j<=last) temp[k++]=a[j++];
	for(i=0;i<k;i++) a[first+i]=temp[i];
}

——————————————————————————————————————————————————————————————————————————————————————
//希尔排序
void shellsort1(int a[],int n){
	int i,j,grap;
	for(grap=n/2;grap>0;grap/=2)
		for(i=0;i<grap;i++)
			for(int j=i+grap;j<n;j++){
				if(a[j]<a[j-grap]){
					int temp=a[j],k=j-grap;
					while(k>=0&&temp<a[k]){
						a[k+grap]=a[k];
					}
					a[k+grap]=temp;
				}
			}
}

void shellsort2(int a[],int n){
	for(int grap=n/2;grap>0;grap/=2)
		for(int i=grap;i<n;i++)
			for(int j=i-grap;j>=0&&a[j]>a[j+grap];j--)
				swap(a[j],a[j+grap]);
}

——————————————————————————————————————————————————————————————————————————————————————
#include <stdio.h>
#include <string.h>
//完全数 123
void AllRange(char *a,int k,int m){
	if(k==m){
		static int j=1;
		printf("第%3d个排列为\t%s\n",j,a)
	}
	else{
		for(int i=k;i<=m;i++){
			swap(a,a+k,a+i);   //后两数交换
			AllRange(a,k+1,m);
			swap(a,a+k,a+i);  //交换的两数还原,在这里是递归嵌套，所以最后会还原为123
		}
	}
}
void swap(char *a,char *b){
	char t=*a; *a=*b; *b=t;
}
int main(){
	char a[]="123";
	AllRange(a,0,strlen(a)-1);
	fflush(stdin);  //刷新键盘缓冲区
 	getchar();
    return 0;
}
——————————————————————————————————————————————————————————————————————————————————————
//计算输入字符串的单词个数
#include <stdio.h>
int main(){
	char s[80];
	gets(s);
	for(int i=0,word=0,num-0;;a[i]!='\0';i++)
		if(a[i]==' ') word=0;
	    else if(word==0){word=1;num++}
	printf("%d\n",num);
}

——————————————————————————————————————————————————————————————————————————————————————
//计数排序
void CountSort1(int a[],int b[],int n,int k)
{
	int c[k+1],i,value,pos;
	for(i=0;i<k;i++) c[i]=0;
	for(i=0;i<n;i++) c[a[i]]++;
	for(i=1;j<k;i++) c[a[i]]+=c[a[i-1]];
	for(int i=n-1;i>=0;i--){
		value=a[i]; pos=c[value]; b[pos-1]=value;c[value]--;  //c[a[i]]--; b[c[a[i]]]=a[i];
	}
	for(i=0;i<n;i++) a[i]=b[i];
}
int Range(int a[],int n){
	int min=a[0],max=a[0],k;
	for(int i=0;i<n;i++){
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
	}
	return (max-min+1);
}
int main(){
	int a[8],b[8]=0,k;
	printf("请输入8个数\n");
	for(int i=0;i<8;i++){
		scanf("%d",&a[i]);
	}
	k=Range(a,8);
	CountSort1(a,b,8,k);
	for(int i=0;i<8;i++){
		printf("%d",a[i]);
	}
}

/*个人感觉其实不太像计数了，因为存在比较关系后计数，而不是
按照元素出现的次数累加计算位数*/
void CountSort2(int data[],int n)
{
	int i,j,count,*data_;
	data_=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) data_[i]=0;
	for(i=0;i<n;i++){
		count=0;
		for(j=1;j<n;j++) if(a[j]<a[i]) count++;
		while(data_[count]!=0) count++;
	    data_[count]=a[i];
	}
	for(i=0;i<n;i++) data[i]=data_[i];
	free(data_);
}

——————————————————————————————————————————————————————————————————————————————————————
/*基数排序在计数排序的基础上
LSD的基数排序适用于位数少的数列，如果位数多的话，使用MSD的效率会比较好
LSD从低位到高位排序，每次循环都是全元素位数排序
MSD从高位到底位，根据高位排序后在分治排序，所以在一定程度上两种算法不同*/

//MSD
#include <iostream>
#include <malloc.h>
using namespace std;
int GetDigit(int x,int d){
	int a[]={1,1,10};
	return ((x/a[d])%10);
}
void PrintArr(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
}
void MsdRadxSort(int a[],int begin,int end,int d){
	const int radix=10;
	int count[radix],i,j;
	for(i=0;i<radix;i++) count[i]=0;
	int *bucket=(int *)malloc((end-begin+1)*sizeof(int));
    for(i=begin;i<=end;i++) count[GetDigit(a[i],d)]++;
    for(i=1;i<radix;i++) count[i]+=count[i-1];
    for(i=end;i>=begin;i--){
    	j=GetDigit(a[i],d); bucket[count[j]-1]=a[i]; count[j]--;
    }
    for(i=begin,j=0;j<=end;i++,j++) a[i]=bucket[j];
    free(bucket);
    for(i=0;i<radix;i++){
    	int p1=begin+(i-1>=0?count[i];0);
    	int p2=count[i]-1;
    	if(p1<p2&&d>1) MsdRadxSort(a,p1,p2,d-1);
    }
}
void main(){
	int a[]={12,14,54,5,6,3,9,8,47,89};
	int len=sizeof(a)/sizeof(int);
	pintf("排序前输出如下:\n");
	PrintArr(a,len);
	MsdRadxSort(a,0,len-1,2);
	pintf("排序后输出如下:\n");
	PrintArr(a,len);
}

//LSD
#include <stdio.h>
#include <iostream>
#include <malloc.h>
using namespace std;
#define MAXSIZE 10000;
int GetDigit(int x,int d){
	int a[]={1,1,10,100};
	return (x/a[d])%10;
}
void PrintArr(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
}
void LsdRadixSort(int a[],int begin,int end,int d){
	const int radix=10;
	int count[radix],i,j;
	int *bucket=(int *)malloc((end-begin)*sizeof(int));
	for(int k=;k<=d;k++){
		for(i=0;i<radix;i++) count[i]=0;
		for(i=beign;i<=end;i++) count[GetDigit(a[i],k)]++;
		for(i=1;i<radix;i++) count[i]+=count[i-1];
		for(i=end;i>=begin;i++){
			j=GetDigit(a[i],k);
			count[j]--;
			bucket[count[j]]=a[i];
		}
		for(i=begin,j=0;i<=end;i++) a[i]=bucket[j];
	}
    free(bucket); free(count);
}
void main(){
	int br[10]={.....};
	LsdRadixSort(br,0,9,3);
	PrintArr(br,10);
}

//用二维数组形式实现
#include <math.h>
void TestBS(){
	int a={...};
	int *a_p=a;
	int size=sizeof(a)/sizeof(int);
	BucketSort1(a_p,size);
	for(int i=0;i<size;i++) printf("%d ",a[i]);
	int t; scanf("%d",&t); //这里百度百科怎么会有一个输入赋值t搞不懂
}
void BucketSort1(int *p,int n){
	int maxnum=FindMaxNum(p,n);
	int looptimes=GetLoopTimes(maxnum);
	for(int i=1;i<=looptimes;i++) BucketSort2(p,n,i);
}
FindMaxNum(int *p,int n){
	int max=*p; //max=0
	for(int i=i;i<n;i++) if(*(p+i)>max) max=*(p+i);
	return max;
}
GetLoopTimes(int max){
	int temp=max/100,count=1;
	while(temp!=0) {temp/=10; count++;}
	return count;
}
void BucketSort2(int *p,int n,int loop){
	int bucket[10][20];
	int tempnum=pow(10,loop-1);
	int i,j;
	for(i=0;i<n;i++){
		int rownum=(*(p+i)/tempnum)%10;
		for(j=0;j<20;j++)
			if(bucket[rownum][j]!=NULL)
				{bucket[rownum][j]=*(p+i); break;}
	}
	int k=0;
	for(i=0;i<10;i++)
		for(j=0;j<20;j++)
			if(bucket[i][j]!=NULL){
				*(p+k)=bucket[i][j];
				bucket[i][j]=NULL;
				k++;
			}
}

——————————————————————————————————————————————————————————————————————————————————————
//算法分析
//给定整数列含负数，求最大和的子序列，共三种function
//时间复杂度 O(N^3)
int MaxSubsequenceSum1(const int A[], int N){
	int ThisSum,MaxSum,i,j,k;
	MaxSum=0;
	for(i=0;i<N;i++)			
		for(j=i;j<N;j++){
			ThisSum=0;
			for(k=i;k<=j;k++) ThisSum+=A[k];				//从头依序遍历
				if(ThisSum>MaxSum) MaxSum=ThisSum;
		}
	return MaxSum;
}
//时间复杂度 O(N^2)
int MaxSubsequenceSum2(const int A[], int N){
	int ThisSum,MaxSum,i,j;
	MaxSum=0; ThisSum=0;
	for(i=0;i<N;i++)
		for(j=i;j<N;j++){
			ThisSum+=A[j];
			if(ThisSum>MaxSum) MaxSum=ThisSum;
		}
}
//分治
static int MaxSubSum(const int A[], int Left, int Right){
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int Center,i;
	if(Left==Right)
		if(A[left]>0) return A[Left];
		else return 0;
	Center=(Left+Right)/2;
	MaxLeftSum=MaxSubSum(A,Left,Center);
	MaxRightSum=MaxSubSum(A,Center+1,right);

	MaxLeftBorderSum=0; LeftBorderSum=0;
	for(i=Center;i>=Left;i--){
		LeftBorderSum+=A[i];
		if(LeftBorderSum>MaxLeftBorderSum) MaxLeftBorderSum=LeftBorderSum;
	}

	MaxRightBorderSum=0; RightBorderSum=0;
	for(i=Center+1;i<=Right;i++){
		RightBorderSum+=A[i];
		if(RightBorderSum>MaxRightBorderSum) MaxRightBorderSum=RightBorderSum;
	}
	return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
}

int MaxSubsequenceSum3(const int A[], int n){
	return MaxSubSum(A,0,N-1);
}

int MaxSubsequenceSum4(){
	int ThisSum,MaxSum,i;
	MaxSum=ThisSum=0；
	for(i=0;i<N;i++){
		ThisSum+=A[i];
		if(ThisSum>MaxSum) MaxSum=ThisSum;
		else if(ThisSum<0) ThisSum=0;
	}
	return MaxSum;
}

——————————————————————————————————————————————————————————————————————————————————————
