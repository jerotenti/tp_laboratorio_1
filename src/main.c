#include "ArrayEmployees.h"
#define TAM_STRUCT_EMPLOYEE 3
#define TAM_STRUCT_SECTOR 3

int main(void) {
	setbuf(stdout, NULL);
	Employee listEmployees[TAM_STRUCT_EMPLOYEE];
	Sector listSector[TAM_STRUCT_SECTOR];
	int option;
	int sortOrder;

	initEmployees(listEmployees, TAM_STRUCT_EMPLOYEE);

	do
	{
		printf("0. EXIT\n");
		printf("1. REGISTER employee\n");
		printf("2. DEREGISTER employee\n");
		printf("3. MODIFY employee\n");
		printf("4. SHOW all employees\n");
		printf("5. SORT employees by last name and industry in ascending order\n");
		printf("6. SORT employees by last name and industry in descending order\n");
		printf("7. SHOW total, average and above-average salary amounts\n");

		printf("Enter an option: ");
		scanf("%d", &option);

		switch(option)
		{
			case 1:
				if((addEmployees(listEmployees, TAM_STRUCT_EMPLOYEE, listSector, TAM_STRUCT_SECTOR)) == 0)
				{
					puts("- Employee successfully registered");
				}
				else
				{
					puts("- There's no more room to register employees");
				}
			system("pause");
			break;
			case 2:
				if(removeEmployee(listEmployees, TAM_STRUCT_EMPLOYEE) == 0)
				{
					puts("\n- Successful employee deregister");
					printEmployees(listEmployees, TAM_STRUCT_EMPLOYEE);
				}
				else
				{
					puts("\n- Employee deregister canceled");
				}
			system("pause");
			break;
			case 3:
				if(Employee_modify(listEmployees, TAM_STRUCT_EMPLOYEE))
				{
					puts("\n- Successful employee modification\n");
					printEmployees(listEmployees, TAM_STRUCT_EMPLOYEE);
				}
			system("pause");
			break;
			case 4:
				printEmployees(listEmployees, TAM_STRUCT_EMPLOYEE);
			system("pause");
			break;
			case 5:
				sortOrder = 1;
				sortEmployees(listEmployees, TAM_STRUCT_EMPLOYEE, sortOrder);
			system("pause");
			break;
			case 6:
				sortOrder = 0;
				sortEmployees(listEmployees, TAM_STRUCT_EMPLOYEE, sortOrder);
			system("pause");
			break;
			case 7:
				calculateAverageSalary(listEmployees, TAM_STRUCT_EMPLOYEE);
			system("pause");
			break;
		}
	}while(option != 0);

	puts("\n* Finished program *");

	return 0;
}
