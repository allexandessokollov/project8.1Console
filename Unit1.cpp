//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#pragma argsused


void addElement(char fileName[]);
float avgGrade(int arr[]);
void showDataFromFile(char fileName[]);


const int ARR_SIZE = 4;

struct student
{
    char name[64];
    int yearOfBirdth;
    int group;
    int grades[ARR_SIZE]; // 0 - physics, 1 - math, 2 - Comp Sience, 3 - chemistry
    double avgGrade;
};

int main()
{


    char fileName[128];
    int userChoice;
    printf("enter file name\n");
    scanf("%s", &fileName);




   
    showDataFromFile(fileName);


    puts("\n\n\nPress any key ... ");
    getch();
    getch();

    return 0;
}





float avgGrade(int arr[])
{
    float temp = 0;

    for(int i = 0; i < ARR_SIZE; i++)
    {
        temp += arr[i];
    }

    return temp / ARR_SIZE;
}


void addElement(char fileName[])
{
    FILE *file;
    student st;

    if ((file = fopen(fileName, "a+")) == NULL)
    {
        printf("\nCannot open file.\n");
    }
    else
    {
        printf("Enter name:\n");
        scanf("%s", &st.name);

        printf("Enter year of birdth:\n");
        scanf("%s", &st.yearOfBirdth);

        printf("Enter group number:\n");
        scanf("%d", &st.group);

        printf("Enter grades physics, math, cs, chemistry:\n");
        scanf("%d\n", &st.grades[0]);
        scanf("%d\n", &st.grades[1]);
        scanf("%d\n", &st.grades[2]);
        scanf("%d", &st.grades[3]);

        st.avgGrade = avgGrade(st.grades);

        fprintf(file, "%s %d %d %d %d %d %d %f\n", st.name, st.yearOfBirdth, st.group,
             st.grades[0], st.grades[1], st.grades[2], st.grades[3], st.avgGrade);

        printf ("\nElement added\n");
    }

    fclose (file);
}



void showDataFromFile(char fileName[])
{
    FILE *file;
    student st;


    if ((file = fopen(fileName, "r")) == NULL)
    {
        printf("\nCannot open file.\n");
    }
    else
    {
        while((fscanf(file, "%s %d %d %d %d %d %d %lf\n", &st.name, &st.yearOfBirdth, &st.group,
             &st.grades[0], &st.grades[1], &st.grades[2], &st.grades[3], &st.avgGrade))!= EOF)
        {
            printf("\n%s %d %d %d %d %d %d %lf\n", st.name, st.yearOfBirdth, st.group,
             st.grades[0], st.grades[1], st.grades[2], st.grades[3], st.avgGrade);
        }
    }
    fclose (file);
}

