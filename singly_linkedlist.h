/*************************************************************
 * @file   : singly_linkedlist.h
 * @author : mohamed mansour
 * @brief  : this file.c contains the declaration of the functions 
 *           that helps you to deal with linkedlist to make or delete node
 *           and search in nodes and free all nodes at the end.
****************************************************************/

#ifndef LINKED_LIST_h
#define LINKED_LIST_h


typedef enum tag_en_ll{
    LL_OK,
    LL_NOT_OK,
    LL_EMPTY,
    LL_FULL,
    LL_NOT_CREATED,
    INVALID_POSITION,
    NODE_NOT_CREATED,
    NODE_CREATED,
    LL_FREE,
    NODE_NOT_FOUND,
}EN_LINKEDLIST_STATE;

typedef struct tage_data
{
    char name[20];
    char title[20];
    unsigned int age;  
    unsigned int ID;
    float salary;
    
}ST_data_t;


typedef struct tage_node
{
    
    struct tage_node *next;
    ST_data_t data;
}node_t;

typedef struct tag_linkedList
{
    unsigned int size;
    node_t * head;
    
}LL_t;

#include<stdio.h>
#include<stdlib.h>
#include"employee_recoard_system.h"
#include<conio.h>



//functio to create new linkedlist 
LL_t* LL_createList ();

//functio to create new node and take value as parameter
node_t *createNode (ST_data_t val);

//functio to add new node at the end to linkedlist and take value as parameter
EN_LINKEDLIST_STATE LL_appendNode (LL_t *mylist, ST_data_t val);

//delete node at givin value (id)
EN_LINKEDLIST_STATE LL_deleteNode_value (LL_t *mylist, int val);

//function to display all nodes
EN_LINKEDLIST_STATE LL_displayList (LL_t *mylist);

//functioon to display spicfic node by value (id)
EN_LINKEDLIST_STATE LL_displayNode (LL_t *mylist, int val);

//function to search in linkeslist by value (id)
node_t *LL_search_node(LL_t * mylist , int val );

//function to free linkedlist
EN_LINKEDLIST_STATE free_LL (LL_t *mylist);

#endif