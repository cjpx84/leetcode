#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
 };


void list_show_all_node(struct ListNode *head)
{
    struct ListNode *p = head;
    while (p != NULL) {
        printf(" %d", p->val);
        p = p->next;
    }
    printf("\n");
}

void list_add_node (struct ListNode** head, struct ListNode** curr, int val)
{
    struct ListNode *p = NULL;

    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (p != NULL) {
        p->val = val;
        p->next = NULL;
        /*first node */
        if (*head == NULL) {
            *head = p;
            *curr = p;
        } else {
        /*only add the node to behind curr*/
            if (*curr != NULL) {
                (*curr)->next = p;
                *curr = p;
            }
        }
    }
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = NULL;
    struct ListNode *q = NULL;
    struct ListNode *head = NULL;
    struct ListNode *curr = NULL;
    int val = 0;
    int carry = 0;
    int v1 = 0;
    int v2 = 0;
    p = l1;
    q = l2;

    while (p != NULL || q != NULL || carry !=0) {
        v1 = p != NULL ? p->val : 0;
        v2 = q != NULL ? q->val : 0;
        val = (v1 + v2 + carry) % 10;
        carry = (v1 + v2 + carry) / 10;

        list_add_node(&head, &curr, 0);
        curr->val = val;
        p = p != NULL ? p->next : NULL;
        q= q != NULL ? q->next : NULL;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = NULL;
    struct ListNode *q = NULL;
    struct ListNode *head = NULL;
    struct ListNode *curr = NULL;
    int val = 0;
    int carry = 0;
    int v1 = 0;
    int v2 = 0;
    p = l1; 
    q = l2; 

    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 0;
    while (p != NULL || q != NULL || carry != 0) { 
        if (curr == NULL)
            curr = head;
        else {
            curr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            curr->next->val = 0;
            curr = curr->next;
        }
        v1 = p != NULL ? p->val : 0;
        v2 = q != NULL ? q->val : 0;
        val = (v1 + v2 + carry) % 10; 
        carry = (v1 + v2 + carry) / 10;
        curr->val = val;
        curr->next = NULL;
        
        p = p != NULL ? p->next : NULL;
        q= q != NULL ? q->next : NULL;
    }   
    return head;
}
            

int main()
{
    struct ListNode *h1, *h2;
    struct ListNode *curr1, *curr2;
    struct ListNode *head;
    list_add_node(&h1, &curr1, 1);
    list_add_node(&h2, &curr2, 9);
    list_add_node(&h2, &curr2, 9);
    head = addTwoNumbers(h1, h2);
    printf("xxxx\n");
    list_show_all_node(head);
    return 0;
}

