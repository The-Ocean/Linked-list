#pragma once
#include<stdlib.h>
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
	//思路：创建一个新链表，将旧链表头插入新链表A
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = cur->next;
	while (cur != NULL)
	{
		cur->next = newhead;
		newhead = cur;
		cur = next;
		if (next != NULL)
		{
			next = next->next;
		}
	}
	return newhead;
}

void Print(struct ListNode* head)
{
	for (head; head != NULL; head = head->next)
	{
		printf("0x%p(%d)  -->  ", head, head->val);
	}
	printf("NULL\n");
}

struct ListNode* Creat(int val)
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = val;
	head->next = NULL;
	return head;
}

void Test_reverse_list()
{
	struct ListNode* num1 = Creat(1);
	struct ListNode* num2 = Creat(2);
	struct ListNode* num3 = Creat(3);
	struct ListNode* num4 = Creat(4);
	struct ListNode* num5 = Creat(5);
	num1->next = num2; num2->next = num3; num3->next = num4;
	num4->next = num5;

	Print(num1);
	struct ListNode* node = reverseList(num1);
	Print(node);
}