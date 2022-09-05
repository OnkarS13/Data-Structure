
#include <stdio.h>

struct Student
{
    int roll_no;
    char *name[100];
    char gender;
    float marks;
};

int main()
{
    struct Student s[3]; // created for 3 students

    for (int i = 0; i < 3; i++)
    {
    printf("Enter Roll no:- \n");
    scanf("%d", &s[i].roll_no);

    printf("Enter Name:- ");
    scanf(" %[^\n]", s[i].name);

    printf("Enter Gender:- ");
    scanf(" %c", &s[i].gender);

    printf("Enter Marks:- \n");
    scanf("%f", &s[i].marks);
    }

    printf("\t\t\t\t Student Information !");
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nSr.No\tRoll No.\tName\tGender\tMarks");
    printf("\n------------------------------------------------------------------------------------------");
    for(int i = 0 ; i <3; i++)
    {
        printf("\n%d\t%d\t\t%s\t%c\t%.2f", i+1 , s[i].roll_no, s[i].name, s[i].gender, s[i].marks);
    }

    printf("\n------------------------------------------------------------------------------------------");

    int max = s[0].marks;
    for(int i = 0; i < 3; i++)
    {
        if(s[i].marks > max)
        {
            max = s[i].marks;
        }
    }

    printf("\nHighest marks among students is %d", max);
    
    printf("\n------------------------------------------------------------------------------------------");

    int min = s[0].marks;
    for(int i = 0; i < 3; i++)
    {
        if(s[i].marks < min)
        {
            min = s[i].marks;
        }
    }

    printf("\nLowest marks among students is %d", min);

    printf("\n------------------------------------------------------------------------------------------");

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if(s[i].marks < s[j].marks)
            {
                int temp = s[i].marks;
                s[i].marks = s[j].marks;
                s[j].marks = temp;

                float tem = s[i].roll_no;
                s[i].roll_no = s[j].roll_no;
                s[j].roll_no = tem;

                char te = s[i].gender;
                s[i].gender = s[j].gender;
                s[j].gender = te;

                char *temps = *s[i].name;
                *s[i].name = *s[j].name;
                *s[j].name = temps;

            }
        }
    }
    

    printf("\n\t\t\t\t Student Information in Descending Order!");
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nSr.No\tRoll No.\tName\tGender\tMarks");
    printf("\n------------------------------------------------------------------------------------------");

    for(int i = 0; i < 6; i++)
    {
        printf("\n%d\t%d\t\t%s\t%c\t%.2f", i+1 , s[i].roll_no, s[i].name, s[i].gender, s[i].marks);
    }

    printf("\n------------------------------------------------------------------------------------------");

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if(s[i].marks > s[j].marks)
            {
                int temp = s[i].marks;
                s[i].marks = s[j].marks;
                s[j].marks = temp;

                float tem = s[i].roll_no;
                s[i].roll_no = s[j].roll_no;
                s[j].roll_no = tem;

                char te = s[i].gender;
                s[i].gender = s[j].gender;
                s[j].gender = te;

                char *temps = *s[i].name;
                *s[i].name = *s[j].name;
                *s[j].name = temps;

            }
        }
    }
    

    printf("\n\t\t\t\t Student Information in Asscending Order!");
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nSr.No\tRoll No.\tName\tGender\tMarks");
    printf("\n------------------------------------------------------------------------------------------");

    for(int i = 0; i < 3; i++)
    {
        printf("\n%d\t%d\t\t%s\t%c\t%.2f", i+1 , s[i].roll_no, s[i].name, s[i].gender, s[i].marks);
    }

    return 0;
}

