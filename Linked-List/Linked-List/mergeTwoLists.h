#pragma once
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	struct ListNode* head1 = l1;
	struct ListNode* head2 = l2;
	struct ListNode* node = NULL;
	struct ListNode* head = node;
	struct ListNode* last = node;
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	while (head1 != NULL && head2 != NULL)
	{
		//124
		//134
		if (head1->val < head2->val)
		{
			if (node == NULL)
			{
				node = head1;
				head = node;
				last = head;
				head1 = head1->next;
				continue;
			}
			//else
			//{
				last->next = head1;
				last = head1;
				head1 = head1->next;
				continue;
			//}
		}
		//else 
		//{
			if (node == NULL)
			{
				node = head2;
				head = node;
				last = head;
				head2 = head2->next;
				continue;
			}
			//else
			//{
				last->next = head2;
				last = head2;
				head2 = head2->next;
			//}

		//}
	}
	if (head1 == NULL)
	{
		last->next = head2;
		return head;
	}
	if (head2 == NULL)
	{
		last->next = head1;
		return head;
	}
	return head;
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

void Test_mergeTwoLists()
{
	struct ListNode* num1 = Creat(1);
	struct ListNode* num2 = Creat(1);
	struct ListNode* num3 = Creat(2);
	struct ListNode* num4 = Creat(3);
	struct ListNode* num5 = Creat(4);
	struct ListNode* num6 = Creat(4);
	num1->next = num3; num3->next = num5; 
	num2->next = num4; num4->next = num6;
	Print(num1);
	Print(num2);
	struct ListNode* node = mergeTwoLists(num1, num2);
	Print(node);
}