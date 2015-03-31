#include <stdio.h>  
#include <stdbool.h>
#include <malloc.h>  
#include <stdlib.h> 

//define linked node
typedef struct Node
{
	int data;	//data area
	struct Node *pNext;	//pointer area
}Node, *PNODE;	//Node = struct Node, PNODE = struct Node *

//define function
PNODE createLinkList(void);	//create link
bool isEmpty(PNODE pHead);	//is empty
int getLenth(PNODE pHead);	//get length
bool insertElement(PNODE pHead, int pos, int val);	//insert function, param are link head, position, value
bool deleteElement(PNODE pHead, int pos, int *pVal);	//delete function, param are link head, position, value
void sort(PNODE pHead);	//bubbling sort link
void traverseLinkList(PNODE pHead);	//traverse link

int main(void)
{
	int val;	//use for save delete element
	PNODE pHead = NULL;	//PNODE = struct Node *
	pHead = createLinkList();	//create link and return pHead
	traverseLinkList(pHead);	//call traverseLink

	if(isEmpty(pHead))
		printf("link is null!\n");
	else
		printf("link is not null\n");

	printf("link length is: %d\n", getLength(pHead));

	sort(pHead);

	traverseLinkList(pHead);

	//insert a element
	if(insertElement(pHead, 4, 30))
		printf("insert done! value is %d\n", 30);
	else
		printf("insert error!\n");

	traverseLinkList(pHead);

	//delete element
	if(deleteElement(pHead, 3, &val))
		printf("delete done! element is %d\n", val);
	else
		printf("delete error!\n");

	traverseLinkList(pHead);
	system("pause");
	return 0;
}

PNODE createLinkList(void)
{
	int length;
	int i;
	int value;
	//create a first head without save value
	PNODE pHead = (PNODE)malloc(sizeof(Node));
	if(NULL == pHead)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	PNODE pTail = pHead;	//ptail is pointer to tail element
	pTail->pNext = NULL;	//empty the next pointer
	printf("please input how many elements do you want: len = ");
	scanf("%d", &length);
	for(i = 0; i<length; i++)
	{
		printf("please input No.%d element's value: ", i+1);
		scanf("%d", &value);
		PNODE pNew = (PNODE)malloc(sizeof(Node));
		if(NULL == pNew)
		{
			printf("malloc failed, exit!\n");
			exit(-1);
		}
		pNew->data = value;	//put value into new element
		pTail->pNext = pNew;	//put tail pointer to this
		pNew->pNext = NULL;	//new elements don't have next
		pTail = pNew;		//the tail pointer is this element
	}
	return pHead;
}

void traverseLinkList(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool isEmpty(PNODE pHead)
{
	if(NULL == pHead->pNext)
		return true;
	else
		return false;
}

int getLength(PNODE pHead)
{
	PNODE p = pHead->pNext;	//get first node
	int len = 0;
	while(NULL != p)
	{
		len++;
		p = p->pNext;
	}
	return len;
}

void sort(PNODE pHead)
{
	int len = getLength(pHead);
	int i,j,t;	//use for save temp var
	PNODE p,q;	//use for compare
	
	for(i = 0, p=pHead->pNext; i<len-1; i++,p=p->pNext)
	{
		for(j=i+1, q=p->pNext; j<len; j++,q=q->pNext)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				p->data = t;
			}
		}
	}
}

bool insertElement(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	//p is null? and get the position
	while(NULL != p && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	if(NULL ==p || i>pos-1)
		return false;

	//create a new element
	PNODE pNew = (PNODE)malloc(sizeof(Node));
	if(NULL == pNew)
	{
		printf("malloc failed! exit!\n");
		exit(-1);
	}
	pNew->data = val;
	//define a temp node, pointer to current node's next node
	PNODE q = p->pNext;
	//put p pointer to new element
	p->pNext = pNew;
	//put element next node
	pNew->pNext = q;
	return true;
}

bool deleteElement(PNODE pHead, int pos, int *pVal)
{
	int i = 0;
	PNODE p = pHead;
	//p is null? and get position
	while(NULL != p->pNext && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	if(NULL == p->pNext || i>pos-1)
	{
		return false;
	}
	//save node that will be delete
	*pVal = p->pNext->data;
	//delete node behind p
	PNODE q = p->pNext;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}
