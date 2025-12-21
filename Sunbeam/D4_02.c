#include<stdio.h>
#include<string.h>

struct employee {
    char emp_name[50];
    int emp_id;
    int emp_salary;
};

int main(){
    struct employee e1;

    printf("Enter Employee Name: ");
    scanf("%s", e1.emp_name);
    printf("Enter Employee Id: ");
    scanf("%d", &e1.emp_id);
    printf("Enter Employee Salary: ");
    scanf("%d", &e1.emp_salary);

    printf("Employee Name: %s\n", e1.emp_name);
    printf("Employee Id: %d\n", e1.emp_id);
    printf("Employee Salary: %d\n", e1.emp_salary);

    return 0;
}
