/*************************************************************
 * @file   : employee_recoard_system.h
 * @author : mohamed mansour
 * @brief  : this file.c contains the declaration of the functions 
 *           that helps you to deal with employees to add an employee or delete
 *           or modify his data also to display employees.
****************************************************************/

#ifndef EMPLOYEE_APP_H
#define EMPLOYEE_APP_H

#include <stdio.h>
#include <stdlib.h>
#include "singly_linkedlist.h"

typedef enum tage_employee{
    EmployeeSystem_OK,
    EmployeeSystem_NOT_OK,
    EmployeeSystem_EMPTY,
}EN_EMPLOYEE_STATE;

//function to start the main app
void app();
//function to create an employee
ST_data_t *create_employee(LL_t *listOfEmployee);

//function to check if the id is repeated
EN_EMPLOYEE_STATE id_checker (LL_t *listofEmployee, int id_ofEmployee);

//function to add the employee at the end of the list
EN_EMPLOYEE_STATE add_employee (LL_t *listOfEmployee);

//function to delete an employee with id
EN_EMPLOYEE_STATE delete_employee (LL_t *listOfEmployee);

//function to modify the data of an employee
EN_EMPLOYEE_STATE modify_employee (LL_t *listOfEmployee);

//function to display all employees
EN_EMPLOYEE_STATE display_employee (LL_t *listOfEmployee);

//function to display an employee with id
EN_EMPLOYEE_STATE display_allEmployees (LL_t *listOfEmployee);

#endif