#include <iostream>
#include <stdio.h>
using namespace std;

typedef int DataType;
 struct SeqList{
   DataType  *elem;
   int Max; //表示线性表最大长度
   int curNum;//表示线性表中数据元素的个数
} ;


typedef  struct SeqList *PseqList;

//函数功能：创建一个空的顺序线性表，线性表最多能存放max个数据元素 
PseqList createNullList(int max) 
{
	PseqList head = new struct SeqList ;
	head->curNum = 0;
	head->Max = max ;
	head->elem = new DataType[max] ;
 	return head ; 
}

//函数功能： 在顺序线性表表尾插入数据元素 
 void insertTail(PseqList slist, DataType x)
 {
    //此处填写代码，实现在顺序表表尾插入数据元素x的功能
	/********** Begin **********/
 	slist->elem[slist->curNum] = x;
	slist->curNum += 1;
 	 
	/********** End **********/
 } 
 
 //输出线性表中所有数据元素，以空格为分界符 
void printList(PseqList slist) 
{
 	for(int i = 0 ;i < slist->curNum ;i++)
 	   cout<<slist->elem[i]<<" " ;
 } 
 
void replace(PseqList slist , DataType x , DataType y)
{
 	//在此处填写代码，实现将线性表slist中数据元素值为x的替换为值y
    /********** Begin **********/
 	for (int i = 0; i < slist->curNum; i++)
	 {
		if(slist->elem[i] == x)
			slist->elem[i] = y;
	 }
	 
 	 
	/********** End **********/
 }

int  main(void){
   PseqList  L1 ;
   int n=20, x , i;
   L1 = createNullList( n); 
   int datanum;
   cin>>datanum ; //输入待插入数据元素个数 
   //读入待插入的数据元素，并插入到线性表尾部 
   for(i =0 ;i < datanum ;i++)   {
         scanf("%d",&x); 
         insertTail(L1 ,x ); 
   }
   //输出线性表L1中数据元素的值 
   // printList(L1);
   // cout<<endl;
   //输入待替换的数据元素值 
   scanf("%d",&x); 
   replace(L1 , x , 999); //将线性表L1中值为x的数据元素替换为999
   printList(L1);  
}

 
// 5 12 23 12 45 6 12
// 999 23 999 45 6

// 6 12 1 1 34 34 5 1
// 12 999 999 34 34 5 