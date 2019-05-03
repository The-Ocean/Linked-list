#pragma once
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* Creat(int val)
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = val;
	head->next = NULL;
	return head;
}

void Print(ListNode *head) {
	for (ListNode *cur = head; cur != NULL; cur = cur->next) {
		printf("0x%p(%d)  -->  ", cur, cur->val);
	}
	printf("NULL\n");
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* newhead = NULL;
	struct ListNode* last = NULL;
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		//如果链表中的值不是val则将结点尾插进新链表
		if (cur->val != val)
		{
			//新链表为空
			if (newhead == NULL)
			{
				newhead = cur;
				last = newhead;
			}
			//新链表不为空
			else
			{
				last->next = cur;
				last = cur;
			}
		}
		cur = cur->next;
	}
	//如果last不为空，则要置空last
	if (last != NULL)
	{
		last->next = NULL;
	}
	return newhead;
}

void Test_remove_list()
{
	struct ListNode* num1 = Creat(1);
	struct ListNode* num2 = Creat(2);
	struct ListNode* num3 = Creat(6);
	struct ListNode* num4 = Creat(3);
	struct ListNode* num5 = Creat(4);
	struct ListNode* num6 = Creat(6);
	num1->next = num2; num2->next = num3; num3->next = num4;
	num4->next = num5; num5->next = num6;
	Print(num1);
	struct ListNode* head = removeElements(num1, 6);
	Print(head);
}
