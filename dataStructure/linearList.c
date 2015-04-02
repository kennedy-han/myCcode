#include <stdio.h>
#include <malloc.h>  
#include <stdlib.h> 

#define MAXSIZE 20	//存储空间初始分配量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;	//ElemType类型根据实际情况而定，这里假设为int
typedef int Status;	//函数的类型，其值是函数结果状态代码，如OK等

typedef struct
{
	ElemType data[MAXSIZE];	//数组存储数据元素，最大值为MAXSIZE	
	int length;	//线性表当前长度
}SqList;

/*
 * 查找
 * 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
 * 操作结果：用e返回L中第i个数据元素的值
 */
Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length == 0 || i < 1 || i > L.length)
	{
		return ERROR;	
	}
	*e = L.data[i-1];
	return OK;
}

/*
 * 插入
 * 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
 * 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
 */
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if(L->length == MAXSIZE)	//顺序线性表已经满
	{
		return ERROR;	
	}	
	if(i < 1 || i > L->length+1)	//当i不在范围内时
	{
		return ERROR;	
	}
	if(i <= L->length)	//若插入数据位置不在表尾
	{
			for(k = L->length-1; k >= i-1; k--)	//将要插入位置后数据元素向后移动一位
			{
				L->data[k+1] = L->data[k];
			}
	}
	L->data[i-1] = e;	//将新元素插入
	L->length++;
	return OK;
}

/*
 * 删除
 * 初始条件：顺序线性表L已存在，1<=ListLength(L)
 * 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
 */
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if(L->length == 0)	//线性表为空
	{
		return ERROR;	
	}	
	if(i < 1 || i > L->length)	//删除位置不正确
	{
		return ERROR;	
	}
	*e = L->data[i-1];
	if(i < L->length)		//如果删除不是最后的位置
	{
		for(k = i; k < L->length; k++)	//将删除位置后续元素前移
		{
			L->data[k-1] = L->data[k];	
		}	
		L->length--;
		return OK;
	}
}

/*
 * 遍历线性表
 */
void traverseList(SqList *list)
{
	int i;
	for(i = 0; i < list->length; i++)
	{
		printf("%d ", list->data[i]);	
	}	
	printf("\n");
}

//测试
int main(void)
{
	int length;
	int i;
	int value;
	
	//初始化线性表
	SqList *list = (SqList *)malloc(sizeof(SqList));
	if(NULL == list)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	
	//接收输入数据填充线性表
	printf("please input how many elements do you want: len = ");
	scanf("%d", &length);
	for(i = 0; i<length; i++)
	{
		if(i < MAXSIZE)
		{
			printf("please input No.%d element's value: ", i);
			scanf("%d", &value);
			if(!ListInsert(list, i+1, value))
			{
					printf("init insert faild!\n");
					exit(-1);
			}
		}
		else
		{
			printf("list is full!\n");
			break;	
		}
	}
	
	traverseList(list);
	
	//获取第2个数据
	int tmp;
	if(!GetElem(*list, 3, &tmp))
	{
			printf("GetElem error\n");
			exit(-1);
	}
	printf("The No.2 value is %d \n", tmp);

	printf("add data 9 at position 0\n");
	//在第0位置插入数据9
	if(!ListInsert(list, 1, 9))
	{
		printf("list insert error \n");
		exit(-1);
	}
	
	traverseList(list);
	
	//删除第1位置的数据
	int delData;
	if(!ListDelete(list, 2, &delData))
	{
		printf("list delete error \n");
		exit(-1);
	}
	printf("delete data is %d \n", delData);
	traverseList(list);
	
	return 0;
}