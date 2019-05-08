#pragma once
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* cur = pListHead;
	int lenth = 0;
	while (cur != NULL)
	{
		lenth++;
		cur = cur->next;
	}
	if (k > lenth)
	{
		return NULL;
	}
	cur = pListHead;
	int i = lenth - k;
	while (i > 0)
	{
		cur = cur->next;
		i--;
	}
	return cur;
}

struct ListNode* Creat(int val)
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = val;
	head->next = NULL;
	return head;
}

void Print(struct ListNode* head)
{
	for (head; head != NULL; head = head->next)
	{
		printf("0X%p(val=%d)-> ", head, head->val);
	}
	printf("NULL\n");
}

void Test_FindKthToTail()
{
	struct ListNode* num1 = Creat(1);
	struct ListNode* num2 = Creat(2);
	struct ListNode* num3 = Creat(3);
	struct ListNode* num4 = Creat(4);
	struct ListNode* num5 = Creat(5);
	num1->next = num2; num2->next = num3; num3->next = num4;
	num4->next = num5;
	Print(num1);
	int k = 6;
	struct ListNode* node = FindKthToTail(num1, k);
	Print(node);
}
