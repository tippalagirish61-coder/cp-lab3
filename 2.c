#include <stdio.h>
#include <string.h>
struct Employee {
   int employee_id;
   char name[20];
   int salary;
};
struct Organisation {
   char organisation_name[20];
   char org_number[20];
   struct Employee emp;
};
int main() {
   struct Organisation org;
   strcpy(org.organisation_name, "TechCorp");
   strcpy(org.org_number, "TC12345");
   org.emp.employee_id = 101;
   strcpy(org.emp.name, "Alice");
   org.emp.salary = 50000;
   printf("Organisation: %s\n", org.organisation_name);
   printf("Employee: %s, Salary: %d\n", org.emp.name, org.emp.salary);
}