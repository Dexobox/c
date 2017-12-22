/********************************************************************************
File:        linked_list.h
Project:
*******************************************************************************/
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef unsigned int uint32_t;

typedef struct node_t
{
    uint32_t node_data;
    struct node_t   * pNextNode;
} LL_Node_t;

typedef struct
{
    LL_Node_t * head;
    LL_Node_t * tail;
    uint32_t count;
}LL_LinkedList_t;

void LL_Insert(LL_LinkedList_t * pList, uint32_t data);
void LL_Insert_Tail(LL_LinkedList_t * pList, uint32_t data);
void LL_Remove_Head(LL_LinkedList_t * pList);
void LL_Print_Node(LL_Node_t * pNode);
LL_Node_t * Find_tail_manual(LL_LinkedList_t * pList);
void split_odd_and_even(LL_LinkedList_t * pList,  LL_Node_t ** pOdd_List,LL_Node_t ** pEvenList );
void LL_RemoveNode(LL_LinkedList_t* pList, LL_Node_t * prev, LL_Node_t* current);
#endif
