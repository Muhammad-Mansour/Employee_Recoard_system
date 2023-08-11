/*************************************************************
 * @file   : singly_linkedlist.c
 * @author : mohamed mansour
 * @brief  : this file.c contains the definitions of the functions.
****************************************************************/


#include "singly_linkedlist.h"

//functio to create new linkedlist 
LL_t* LL_createList()
{
    //create the list
    LL_t *mylist= malloc(1*sizeof(LL_t));

    //if the list didnt created
    if (mylist == NULL)
    {
        printf("linkedkist not created.\n");
        return mylist;
    }

    //list is empty
    mylist->head=NULL;
    mylist->size=0;
    return mylist;
}

//functio to create new node and take value as parameter
node_t *createNode(ST_data_t val)
{
    node_t * newnode = malloc(1*sizeof(node_t));
    //if node wansn't created
    if(newnode == NULL)
        return NULL;
    
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

//functio to add new node at the end to linkedlist and take value as parameter
EN_LINKEDLIST_STATE LL_appendNode(LL_t *mylist,ST_data_t val)
{
    //if the list not exist
    if (mylist==NULL)
        return LL_NOT_OK;
    

    //create the node
    node_t *newnode=createNode(val);

    //check if the linkedlist is empty
    if(mylist->head==NULL)
    {
        mylist->head=newnode;
        mylist->size =1;
        return LL_OK;
    }
    
    
    //create current to to detect the last node
    node_t *current=  mylist->head;

    while (current->next!=NULL)
    {

        current=current->next;
    }

    current->next=newnode;
    mylist->size ++;
    return LL_OK;
}

//delete node at givin value (id)
EN_LINKEDLIST_STATE LL_deleteNode_value(LL_t *mylist,int val)
{
    //if the list wasn't created
    if (mylist == NULL)
        return LL_NOT_OK;
    
    //check if no elements in the list
    if(mylist->head == NULL)
    {
        printf("list is empty.");
        return LL_EMPTY;
    }

    node_t * current =  mylist->head;

    //if user want to delete head node
    if (mylist->head->data.ID == val)
    {
        
        mylist->head = current->next;
        current = NULL;
        mylist->size--;
        printf("Done Deleting.\n");
        return LL_OK;
    }

    
    node_t * prev = current ;
    
    while (current != NULL)
    {
        if (current->data.ID == val)
        {
            prev->next = current->next;
            free(current);
            mylist->size--;
            printf("Done Deleting.\n");
            return LL_OK;
        }
        prev = current;
        current = current->next;  
    }
    printf("Deletion faild.\n");
    return NODE_NOT_FOUND;
}

//function to display all nodes 
EN_LINKEDLIST_STATE LL_displayList(LL_t *mylist)
{
    //if the list wasn't created
    if (mylist == NULL) 
        return LL_NOT_OK;
    
    if(mylist->head == NULL) 
    {
        printf("list is empty.\n");
        return LL_EMPTY;
    }
        
    node_t *current = mylist->head;
    if (current==NULL)
        return NODE_NOT_CREATED;
    
    //printing all nodes and the number of nodes
    while(current!=NULL)
    {
        printf("name : %s\n",current->data.name);
        printf("title : %s\n",current->data.title);
        printf("age : %d\n",current->data.age);
        printf("ID : %d\n",current->data.ID);
        printf("salary : %g\n",current->data.salary);
        printf("\n* * * * * * * * * * * * * * * * * * * *\n");
        current=current->next;
    }
    printf("\nnumber of employee : %d\n",mylist->size);
    return LL_OK;
}

//functioon to display spicfic node by value (id)
EN_LINKEDLIST_STATE LL_displayNode(LL_t *mylist,int val)
{
    //create node to detect the wanted node and print it
    node_t *current = LL_search_node(mylist, val);

    if (current == NULL)
        return LL_NOT_OK;
    

    while (current != NULL)
    {
        if (current->data.ID == val)
            break;
        
        current = current->next;
    }
    
    if(current != NULL)
    {
    printf("\n* * * * * * * * * * * * * * * * * * * *\n\n");
    printf("name : %s \n",current->data.name);
    printf("title : %s \n",current->data.title);
    printf("age : %d\n",current->data.age);
    printf("id : %d\n",current->data.ID);
    printf("salary : %.1f\n",current->data.salary);
    printf("\n* * * * * * * * * * * * * * * * * * * *\n");
    return LL_OK;
    }

    printf("Node not found.\n");
    return NODE_NOT_FOUND;
}

//function to search in linkeslist by val (id)
node_t *LL_search_node(LL_t * mylist , int val )
{
    //check if lit wasn't created
    if(mylist == NULL)
        return NULL;
    
    //check if list is empty
    if(mylist->head == NULL)
        return NULL;
        
    //create node to access the wanted node
    node_t *current = mylist->head;
    
    while (current != NULL)
    {
        if(current->data.ID == val)
            return current;

        current = current->next;
    }

    printf("not found\n");
    return NULL;
}

//function to free linkedlist 
EN_LINKEDLIST_STATE free_LL(LL_t *mylist)
{
    //if the list didnt created
    if (mylist==NULL)
        return LL_NOT_OK;
    //if list is empty
    if (mylist->head == NULL)
    {
        free(mylist);
        return LL_EMPTY;
    }

    node_t *current = mylist->head;
    if(current == NULL)
        return NODE_NOT_CREATED;
    
    while (current!=NULL)
    {
        mylist->head=mylist->head->next;
        free(current);
        current=mylist->head;
    }

    return LL_FREE;
}


