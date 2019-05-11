#pragma once
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void Print(struct ListNode* head)
{
	for (head; head != NULL; head = head->next)
	{
		printf("0X%p(val=%d)-> ", head, head->val);
	}
	printf("NULL\n");
}

ListNode* partition(ListNode* pHead, int x) {
	ListNode* small = (ListNode*)malloc(sizeof(ListNode));
	ListNode* big = (ListNode*)malloc(sizeof(ListNode));
	ListNode* smallhead = small;
	ListNode* bighead = big;
	ListNode* cur = pHead;
	while (cur)
	{
		if (cur->val < x)
		{
			small->next = cur;
			small = small->next;
		}
		else
		{
			big->next = cur;
			big = big->next;
		}
		cur = cur->next;
	}
	big->next = NULL;
	small->next = bighead->next;
	return smallhead->next;

}


struct ListNode* Creat(int val)
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = val;
	head->next = NULL;
	return head;
}


void Test_partition()
{
	struct ListNode* num1 = Creat(4);
	struct ListNode* num2 = Creat(2);
	struct ListNode* num3 = Creat(3);
	struct ListNode* num4 = Creat(1);
	struct ListNode* num5 = Creat(7);
	struct ListNode* num6 = Creat(6);
	num1->next = num2; num2->next = num3; num3->next = num4; 
	num4->next = num5; num5->next = num6; num6->next = NULL;
	Print(num1);
	int k = 3;
	struct ListNode* node = partition(num1, k);
	Print(node);
}
