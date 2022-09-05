#include <stdio.h>

struct Student
{
    int roll_no;
    char name[10];
    char gender;
    float marks;
    
};

int main()
{
    struct Student s; // object is created

    printf("Enter Roll no:- ");
    scanf("%d", &s.roll_no);

    printf("Enter Name:- ");
    scanf(" %[^\n]", s.name); // This is used for taking info from user with space
 
    printf("Enter Gender:- ");
    scanf(" %c", &s.gender);

    printf("Enter Marks:- ");
    scanf("%f", &s.marks);

    printf("\n--------------------------------\n");

    printf("Roll no.is %d \n", s.roll_no);
    printf("Name is %s \n", s.name);
    printf("Gender is %c \n", s.gender);
    printf("Marks are %.2f \n", s.marks);

    return 0;
}