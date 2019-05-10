#pragma once
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
	//1.拷贝val与next，并合并链表
	struct Node* cur = head;
	while (cur != NULL)
	{
		struct Node* node = (Node*)malloc(sizeof(Node));
		struct Node* next = cur->next;
		node->val = cur->val;
		node->next = cur->next;
		cur->next = node;
		cur = next;
	}
	//2.将random的值拷贝到新链表上
	cur = head;
	while (cur != NULL)
	{	
		// 1	2	 3	  4
		//	 1	  2	   3	 4
		struct Node* next = cur->next->next;
		if (cur->random== NULL)
		{
			cur->next->random = NULL;
			cur = next;
		}
		else
		{
			cur->next->random = cur->random->next;
			cur = next;
		}
	}
	//拆分链表
	cur = head;
	if (cur == NULL)
	{
		return NULL;
	}
		// 1	2	 3	  4
		//	 1	  2	   3	 4
	struct Node* nodehead = cur->next;//保存返回链表的头节点
	while (cur != NULL)
	{
		struct Node* temp = cur->next->next;
		if (temp == NULL)
		{
			cur->next = NULL;
			break;
		}
		else
		{
			cur->next->next = temp->next;
			cur->next = temp;
			cur = temp;
		}
	}
	return nodehead;
}

struct Node* Creat(int val)
{
	struct Node* head = (struct Node*)malloc(sizeof( Node));
	head->val = val;
	head->next = NULL;
	head->random = NULL;

	return head;
}

void Print(struct Node* head)
{
	for (head; head != NULL; head = head->next)
	{
		printf("0X%p(val=%d)-", head, head->val);
		if (head->random == NULL)
		{
			printf("(0X%p-random = NULL)", head);
		}
		else
		{
			printf("(%d-random->%d)", head->val, head->random->val);
		}
		printf("->");
	}
	printf("NULL\n");
}

void Test_copyRandomList()
{

	struct Node* num1 = Creat(1);
	struct Node* num2 = Creat(2);
	struct Node* num3 = Creat(3);
	struct Node* num4 = Creat(4);
	struct Node* num5 = Creat(5);
	struct Node* num6 = Creat(6);
	num1->next = num2; num2->next = num3; num3->next = num4; num4->next = num5; num5->next = num6;
	num1->random = num2; num2->random = num2; num5->random = num5; num6->random = NULL;
	Print(num1);
	struct Node* node = copyRandomList(num1);
	Print(node);
	Print(num1);
}
