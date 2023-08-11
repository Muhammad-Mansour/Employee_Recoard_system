/*************************************************************
 * @file   : employee_recoard_system.c
 * @author : mohamed mansour
 * @brief  : this file.c contains the definitions of the functions.
****************************************************************/

#include"employee_recoard_system.h"

//function to start the main app
void app(){

        system("cls");
    LL_t *newlist= LL_createList();
    
    char choice=0;
    int option=0;

    do
    {
        system("cls");

        printf(
            "* * * * * * * * * * * * * * * * * * * *\n"

            "1-Add a new employee data.\n"
            "2-Delete the data of an employee.\n"
            "3-Modify the data of an employee.\n"
            "4-View the data of an employee.\n"
            "5-View all the employee's data.\n"
            "6-Exit.\n"

            "* * * * * * * * * * * * * * * * * * * *\n");

        fflush(stdin);
        printf("your choice : ");
        scanf(" %d",&option);
        
        switch (option)
        {
            case 1:
                system("cls");
                add_employee(newlist);
                break;

            case 2:
                system("cls");
                delete_employee(newlist);
                break;

            case 3:
                system("cls");
                modify_employee(newlist);
                break;

            case 4:
                system("cls");
                display_employee(newlist);
                break;

            case 5:
                system("cls");
                display_allEmployees(newlist);
                break;

            case 6:
                system("cls");
                printf("Thanks for using the program\n");
                Sleep(1000);
                exit(0);
                break;
        
            default:
                printf("invalid choice\n");
                break;
        }

        printf("\n\nThanks for using the program press any key to continue or (ESC) to exit.\n");
    }while (getch() != 27);

    printf("Thanks for using the program\n");
    Sleep(1000);
    free_LL(newlist);
}


//function to create an employee
ST_data_t *create_employee(LL_t *listOfEmployee)
{
  if (listOfEmployee == NULL)
        return NULL;

    //crete the employee node and check if not created
    ST_data_t *new_employee= malloc(1*sizeof(ST_data_t));
    if (new_employee == NULL)    
        return NULL;

    //scanning the data of the employee
    printf("\n* * * * * * * * * * * * * * * * * * * *\n");
    printf("Enter the name : ");
    scanf(" %[^\n]s",new_employee->name);

    fflush(stdin);
    printf("Enter the title : ");
    scanf(" %[^\n]s",new_employee->title);

    printf("Enter the age : ");
    scanf("%d",&new_employee->age);
    
    do
    {
        printf("Enter the ID : ");
        scanf("%d",&new_employee->ID);

    } while (id_checker(listOfEmployee , new_employee->ID) == EmployeeSystem_NOT_OK);
    
    
        
    printf("Enter the salary : ");
    scanf("%f",&new_employee->salary);
    
    return new_employee;
}

//function to check if the id is repeated
EN_EMPLOYEE_STATE id_checker (LL_t *listofEmployee, int id_ofEmployee)
{
    if (listofEmployee == NULL)
        return EmployeeSystem_NOT_OK;

    //current node to check the id of all nodes
    node_t *current = listofEmployee->head;
    short counter=0;
    while (current != NULL)
    {
        //if the id is spoted
        if (current ->data.ID == id_ofEmployee)
            counter ++;

        current = current->next;  
    }
    if (counter == 1)
    {
        printf("id is repeated\n");
        return EmployeeSystem_NOT_OK;
    }
    return EmployeeSystem_OK;
}

//function to add the employee at the end of the list
EN_EMPLOYEE_STATE add_employee(LL_t *listOfEmployee)
{
    
    ST_data_t data;  
    unsigned short number_ofemployee=0;

    printf("how many employee you want to add : ");
    scanf("%d",&number_ofemployee);
    
    
    for(short i=1; i<= number_ofemployee; i++){

    fflush(stdin);
    data = *create_employee(listOfEmployee);
    LL_appendNode(listOfEmployee,data);
    printf("\nAdding completed successfully\n");
    }
    return EmployeeSystem_OK;
}

//function to delete an employee with id
EN_EMPLOYEE_STATE delete_employee(LL_t *listOfEmployee)
{
    int ID_ofEmployee=0;
    printf("Enter the id of the employee : ");
    scanf("%d",&ID_ofEmployee);
    LL_deleteNode_value(listOfEmployee,ID_ofEmployee);
    return EmployeeSystem_OK;
}

//function to modify the data of an employee
EN_EMPLOYEE_STATE modify_employee(LL_t *listOfEmployee)
{
    int ID_ofEmployee,choice;

    //check if the list wasn't created
    if(listOfEmployee == NULL)
        return EmployeeSystem_NOT_OK;

    //check if list is empty
    if(listOfEmployee->head==NULL)
    {
        printf("list is empty\n");
        return EmployeeSystem_NOT_OK;
    }


    //create node to access the node wanted to modify and make changes
    node_t *newData_of_employee=malloc(1*sizeof(node_t));
    if(newData_of_employee == NULL)
        return EmployeeSystem_NOT_OK;

    printf("Enter the id of the employee : ");
    scanf("%d",&ID_ofEmployee);
    newData_of_employee = LL_search_node(listOfEmployee,ID_ofEmployee);

    if (newData_of_employee == NULL)
        return EmployeeSystem_EMPTY;
    

    //
    printf("to modify:-\n"
                "1-the whole date.\n"
                "2-name\n"
                "3-title\n"
                "4-age\n"
                "5-id\n"
                "6-salary\n\n");
    printf("chose the data you want to edit : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        newData_of_employee->data = *create_employee(listOfEmployee);
        printf("\nDone editing \n\n");
        break;

    case 2:
        printf("Enter the new name : ");
        fflush(stdin);
        scanf(" %[^\n]s",newData_of_employee->data.name);
        printf("\nDone editing \n\n");
        break;

    case 3:
        printf("Enter the new title : ");
        fflush(stdin);
        scanf(" %[^\n]s",newData_of_employee->data.title);
        printf("\nDone editing \n\n");
        break;

    case 4 : 
        printf("Enter the new age : ");
        fflush(stdin);
        scanf(" %d",&newData_of_employee->data.age);
        printf("\nDone editing \n\n");
        break;

    case 5:
        do
        {
            printf("Enter the ID : ");
            scanf("%d",&newData_of_employee->data.ID);

        } while (id_checker(listOfEmployee , ID_ofEmployee) == EmployeeSystem_NOT_OK);
        printf("\nDone editing \n\n");
        break;

    case 6:
        printf("Enter the new salary : ");
        fflush(stdin);
        scanf(" %f",&newData_of_employee->data.salary);
        printf("\nDone editing \n\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }
    return EmployeeSystem_OK;
}

//function to display an employee with id
EN_EMPLOYEE_STATE display_employee(LL_t *listOfEmployee)
{
    short ID_ofEmployee=0;
    printf("enter the id of the employee : ");
    scanf("%d",&ID_ofEmployee);
    LL_displayNode(listOfEmployee,ID_ofEmployee);
    return EmployeeSystem_OK;
}

//function to display all employees
EN_EMPLOYEE_STATE display_allEmployees(LL_t *listOfEmployee)
{
    LL_displayList(listOfEmployee);
    
    return EmployeeSystem_OK;
}