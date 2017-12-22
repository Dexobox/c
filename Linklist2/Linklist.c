/********************************************************************************
File:        linked_list.c
Project:
*******************************************************************************/
#include "Linklist.h"
#include <stdio.h>
#include <stdlib.h>

void LL_Init(LL_LinkedList_t * pList)
{
    pList->head = NULL;
    pList->tail = NULL;
    pList->count = 0;
}

void LL_Insert_Tail(LL_LinkedList_t * pList, uint32_t data)
{
   LL_Node_t * tmp = (LL_Node_t *)malloc(sizeof(LL_Node_t));
    tmp->pNextNode = NULL;
    tmp->node_data = data;

   if(pList->count == 0)
   {
       pList->head = tmp;
       pList->tail = tmp;
   }else
   {
       pList->tail->pNextNode = tmp;
       pList->tail = tmp;
   }
   pList->count++;
}

void LL_Insert_Head(LL_LinkedList_t * pList, uint32_t data)
{
    LL_Node_t * tmp = pList->head;

    pList->head = (LL_Node_t *) malloc(sizeof(LL_Node_t));
    pList->tail = tmp;
    pList->count++;
}


void LL_Remove_Head(LL_LinkedList_t * pList)
{
    pList->head = pList->head->pNextNode;
    pList->count--;
}

void LL_Print_Node(LL_Node_t * pNode)
{
    printf("Node Addr: %p \n\t Node Data: %u \n\t pNextNode:%p \n\n",pNode, pNode->node_data, pNode->pNextNode);
}

LL_Node_t * Find_tail_manual(LL_LinkedList_t * pList)
{
    LL_Node_t * curr_node = pList->head;

    while (curr_node->pNextNode != NULL)
    {
        curr_node = curr_node->pNextNode;
    }

    return curr_node;
}

void LL_RemoveNode(LL_LinkedList_t * pList, LL_Node_t * prev, LL_Node_t* current)
{
    if(prev == NULL) //! This means you are trying to remove the head
    {
        pList->head = current->pNextNode;
        return;
    }
    //when node is in middle of the list
    prev->pNextNode = current->pNextNode;

}

void split_odd_and_even(LL_LinkedList_t * pList,  LL_Node_t ** pOddList,LL_Node_t ** pEvenList )
{
    LL_Node_t * current = pList->head;
    LL_Node_t * prev = NULL;
    LL_Node_t * tmp = NULL;
    LL_Node_t * removed_node;

    //! Pretend tail pointer is not available
    LL_Node_t * tail = Find_tail_manual(pList);

    //! Save off the tail
    tmp  = tail;

    // printf("tmp %p tmp %u \n", tmp, tmp->node_data);
    while(current != tmp)
    {
        // printf("current data : %d \n",current->node_data );
        if(current->node_data % 2 == 0)
        {

            //! Current node is removed
            LL_RemoveNode(pList, prev, current);
            removed_node = current;
            // printf("removed data %u\n", current->node_data);

            pList->tail->pNextNode = removed_node;
            pList->tail = removed_node;

            //!
            prev = current;
            current = removed_node->pNextNode;
            removed_node->pNextNode = NULL;
        }
        else
        {
            prev = current;
            current = current->pNextNode;
        }
        // printf("current data end: %d \n",current->node_data );
    }

    //! handling for the last node
    if (current->node_data % 2 == 0)
    {
        //! Current node is removed
        LL_RemoveNode(pList, prev, current);
        removed_node = current;

        //! send the removed node to back of the list
        *pEvenList = current->pNextNode;
        pList->tail->pNextNode = removed_node;
        pList->tail = removed_node;

        //! Close the lists
        current->pNextNode = NULL;
        prev->pNextNode = NULL;

    }else
    {
        *pEvenList = current->pNextNode;
        current->pNextNode = NULL;
    }
    *pOddList = pList->head;
}

void main()
{
    uint32_t i = 0;
    LL_LinkedList_t linklist1;
    LL_Node_t * odd_head;
    LL_Node_t * even_head;

    //! Test Case for Insertion
    LL_Init(&linklist1);
    printf("Init Done!\n");
    for(i=0; i<11; i++)
    {
        LL_Insert_Tail(&linklist1, i);
    }

    //! Prints for visual checking the links (bcus DDD doesnt work on windows >:( ) 
    LL_Node_t * tmp = linklist1.head;
    do
    {
        LL_Print_Node(tmp);
        tmp = tmp->pNextNode;
    }while (tmp != NULL);
    // Find_tail_manual(&linklist1);

    //! Function to split the linklist into odd and even test
    split_odd_and_even(&linklist1, &odd_head, &even_head);
    tmp = odd_head;

    //! More visual checking
    printf("printing_odd_list \n");
    do
    {
        LL_Print_Node(tmp);
        tmp = tmp->pNextNode;
        // printf("tmp->pNextNode\n");
    }while (tmp != NULL);

    tmp = even_head;
    
    //! Even More visual checking
    // printf("printing_even_list \n");
    do
    {
        // printf("tmp->pNextNode :%p \n",tmp );
        LL_Print_Node(tmp);
        tmp = tmp->pNextNode;
    }while (tmp != NULL);
}

