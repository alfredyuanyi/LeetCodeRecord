#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode *position;

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode *l1,struct ListNode *l2){
    int length1, length2, carry;
    int i;
    struct ListNode *position1, *position2, *temp, *loop;
    position1 = l1;
    position2 = l2;
    struct ListNode *result = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(position1->val + position2->val >= 10){
        carry = 1;
        result->val = (position1->val + position2->val) % 10;
    }
    else{
        carry = 0;
        result->val = position1->val + position2->val;
    }
    
    result->next = NULL;
    temp = result;
    length1 = length2 = 0;
    while(position1){
        length1++;
        position1 = position1->next;
    }
        
    while(position2){
        length2++;
        position2 = position2->next;
    }
        
    position1 = l1->next;
    position2 = l2->next;
    loop = length1 > length2? position1: position2;
    while(loop){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(position1 != NULL && position2 != NULL){
            node->val = (position1->val + position2->val + carry) % 10;
            if((position1->val + position2->val + carry) >= 10)
                carry = 1;
            else
                carry = 0;
            node->next = NULL;
            temp->next = node;
            temp = node;
            position1 = position1->next;
            position2 = position2->next;
        }
        else if(position2 != NULL){
            node->val = (position2->val + carry) % 10;
            if((position2->val + carry) >= 10)
                carry = 1;
            else
                carry = 0;
            node->next = NULL;
            temp->next = node;
            temp = node;
            position2 = position2->next;
        }
        else if(position1 != NULL){
            node->val = (position1->val + carry) % 10;
            if((position1->val + carry) >= 10)
                carry = 1;
            else
                carry = 0;
            node->next = NULL;
            temp->next = node;
            temp = node;
            position1 = position1->next;
        }
        loop = loop->next;
    }
    if(carry == 1){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;
        temp->next = node;
    }
    return result;
}


int main(){
    position l1 = (position)malloc(sizeof(struct ListNode));
    l1->val = 5;
    // position node = (position)malloc(sizeof(struct ListNode));
    // node->val = 4;
    // l1->next = node;
    // position node1 = (position)malloc(sizeof(struct ListNode));
    // node1->val = 3;
    // node1->next = NULL;
    // node->next = node1;
    position l2 = (position)malloc(sizeof(struct ListNode));
    l2->val = 5;
    // position node2 = (position)malloc(sizeof(struct ListNode));
    // node2->val = 6;
    // l2->next = node2;
    // position node3 = (position)malloc(sizeof(struct ListNode));
    // node3->val = 4;
    // node2->next = node3;
    // node3->next = NULL;
    position result = addTwoNumbers(l1, l2);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}