#include "ArrayEmployees.h"

static int Employee_incrementalID = 0;
static int Sector_incrementalID = 0;

int employee_getID(void)
{
	return Employee_incrementalID += 1;
}

int sector_getID(void)
{
	return Sector_incrementalID += 1;
}

int initEmployees(Employee list[], int len)
{
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = EMPTY;
		}
	}

	return 0;
}

int getEmptyIndex(Employee list[], int len)
{
	int returnValue = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == EMPTY)
			{
				returnValue = i;
				break;
			}
		}
	}

	return returnValue;
}

int addEmployees(Employee list[], int len, Sector listOfSector[], int lenSector)
{
	int returnValue = -1;
	int i;

	i = getEmptyIndex(list, len);
	if(i != -1)
	{
		list[i] = requestEmployeeData(list, len, listOfSector, lenSector);
		list[i].id = employee_getID();
		list[i].idSector = sector_getID();
		list[i].isEmpty = FULL;
		returnValue = 0;
	}
	return returnValue;
}

Employee requestEmployeeData(Employee list[], int len, Sector listSector[], int lenSector)
{
	Employee myEmployee;

	printf("Enter a name: ");
	fflush(stdin);
	scanf("%[^\n]", myEmployee.name);

	printf("Enter a last name: ");
	fflush(stdin);
	scanf("%[^\n]", myEmployee.lastName);

	printf("Enter a salary: ");
	scanf("%f", &myEmployee.salary);

	printf("Enter a sector: ");
	fflush(stdin);
	scanf("%[^\n]", myEmployee.description);

	return myEmployee;
}

int Employee_modify(Employee list[], int len)
{
	int returnValue = -1;
	int auxiliary;
	int option;
	int i;

	printEmployees(list, len);

	printf("Enter your ID");
	scanf("%d", &auxiliary);

	for(i = 0; i < len; i++)
	{
		if(auxiliary == list[i].id)
		{
			if(list[i].isEmpty == EMPTY)
			{
				puts("The employee is unsubscribed");
				break;
			}
			else
			{
				printf("Enter an option:\n1- Name\n2- Last name\n3- Salary\n4- Sector");
				scanf("%d", &option);

				switch(option)
				{
					case 1:
						printf("Enter a name: ");
						fflush(stdin);
						scanf("%[^\n]", list[i].name);
					break;
					case 2:
						printf("Enter a last name: ");
						fflush(stdin);
						scanf("%[^\n]", list[i].lastName);
					break;
					case 3:
						printf("Enter a salary: ");
						scanf("%f", &list[i].salary);
					break;
					case 4:
						printf("Enter a sector: ");
						fflush(stdin);
						scanf("%[^\n]", list[i].description);
					break;
				}
				returnValue = 0;
			}
			break;
		}
	}

	return returnValue;
}

int findEmployeeById(Employee list[], int len, int ID)
{
	int returnValue = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == ID && list[i].isEmpty == FULL)
			{
				returnValue = i;
				break;
			}
		}
	}

	return returnValue;
}

int removeEmployee(Employee list[], int len)
{
	int returnValue = -1;
	int idEmployee;
	int index;
	int flag = 0;

	if(printEmployees(list, len))
	{
		flag = 1;
	}
	if(flag)
	{
		printf("Enter an ID to remove an employee: ");
		scanf("%d", &idEmployee);

		while(findEmployeeById(list, len, idEmployee) == -1)
		{
			puts("The ID does not exist");
			printf("Re-enter the ID: ");
			scanf("%d", &idEmployee);
		}

		index = findEmployeeById(list, len, idEmployee);
		list[index].isEmpty = REMOVED;

		returnValue = 0;
	}

	return returnValue;
}

void printOneEmployee(Employee myEmployee)
{
	printf("|%6d|%13s|%16s|%12.2f|%11d|%22s|\n", myEmployee.id,
																									myEmployee.name,
																									myEmployee.lastName,
																									myEmployee.salary,
																									myEmployee.idSector,
																									myEmployee.description
																									    );
    printf("|_____________________________________________________________________________________|\n");
}

int printEmployees(Employee list[], int len)
{
	int i;
	int returnValue = -1;
	int counter = 0;

	printf("|  ID  |    Name     |   Last name    |   Salary   | ID Sector |       Sector         |\n");
	printf("|_____________________________________________________________________________________|\n");

	for(i = 0; i < len; i++)
	{
		if(list != NULL && len > 0)
		{
			if(list[i].isEmpty == FULL)
			{
				printOneEmployee(list[i]);
				counter++;
			}
		}
	}

	if(counter > 0)
	{
		returnValue = 1;
	}

	return returnValue;
}

int sortEmployees(Employee list[], int len, int order)
{
	Employee auxiliary;
	int returnValue = -1;
	int i;
	int j;

	if(list != NULL && len > 0)
	{
		switch(order)
		{
			case 1:
				for(i = 0; i < len - 1; i++)
				{
					for(j = i + 1; j < len; j++)
					{
						if(list[i].isEmpty == FULL && list[j].isEmpty == FULL)
						{
							if(strcmp(list[i].lastName, list[j].lastName) < 0 && strcmp(list[i].description, list[j].description) > 0)
							{
								auxiliary = list[i];
								list[i] = list[j];
								list[j] = auxiliary;
							}
						}
					}
				}
				returnValue = 0;
				break;
			case 0:
				for(i = 0; i < len - 1; i++)
				{
					for(j = i + 1; j < len; j++)
					{
						if(list[i].isEmpty == FULL && list[j].isEmpty == FULL)
						{
							if(strcmp(list[i].lastName, list[j].lastName) < 0 && strcmp(list[i].description, list[j].description) < 0)
							{
								auxiliary = list[i];
								list[i] = list[j];
								list[j] = auxiliary;
							}
						}
					}
				}
				returnValue = 0;
				break;
		}
	}

	return returnValue;
}

int calculateAverageSalary(Employee list[], int len)
{
	int returnValue = -1;
	int i;
	float accumulatorSalary = 0;
	int aboveAverageCounter = 0;
	float averageSalary;
	int counter = 0;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FULL)
			{
				accumulatorSalary += list[i].salary;
				counter++;
			}
		}

		averageSalary = accumulatorSalary / counter;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FULL && list[i].salary > averageSalary)
			{
				aboveAverageCounter++;
			}
		}

		returnValue = 0;
	}

	printf("Total salaries are: %.2f\n", accumulatorSalary);
	printf("The average salary is: %.2f\n", averageSalary);
	printf("The number of employees above the average salary is: %d\n", aboveAverageCounter);

	return returnValue;
}
