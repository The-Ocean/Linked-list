#pragma once
#include<stdlib.h>
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
 
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* cur = head;
	struct ListNode* node = head;

	int lenth = 1;
	while (cur != NULL)
	{
		cur = cur->next;
		lenth++;
	}
	for (int i = 1; i < (lenth + 1) / 2; i++)
	{
		node = node->next;
	}
	return node;
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

void Test_middleNode()
{
	struct ListNode* num1 = Creat(1);
	struct ListNode* num2 = Creat(2);
	struct ListNode* num3 = Creat(3);
	struct ListNode* num4 = Creat(4);
	struct ListNode* num5 = Creat(5);
	num1->next = num2; num2->next = num3; num3->next = num4;
	num4->next = num5;
	Print(num1);
	struct ListNode* node = middleNode(num1);
	Print(node);

}
