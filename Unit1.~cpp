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
void createFile(char fileName[]);
void printExellentStudents(char fileName[]);
void editData(char fileName[]);


const int ARR_SIZE = 4;
const int MAX_NAME_SIZE = 128;
const int MAX_STARR_SIZE = 128;

struct student
{
    char name[MAX_NAME_SIZE];
    int yearOfBirdth;
    int group;
    int grades[ARR_SIZE]; // 0 - physics, 1 - math, 2 - Comp Sience, 3 - chemistry
    double avgGrade;
};

int main()
{


    char fileName[MAX_NAME_SIZE];
    int userChoice;
    bool toSwitch = true;


    while(toSwitch)
    {
        printf("Enter 1 to create file\nEnter 2 to show data\n");
        printf("Enter 3 to add element\n");
        printf("Enter 4 to see exellent students\nEnter 5 to edit data\n");
        printf("Enter 6 to close app\n");
        scanf("%d", &userChoice);

        switch(userChoice)
        {
            case 1:
            {
                createFile(fileName);
                break;
            }
            case 2:
            {
                showDataFromFile(fileName);
                break;
            }
            case 3:
            {
                addElement(fileName);
                break;
            }
            case 4:
            {
                printExellentStudents(fileName);
                break;
            }
            case 5:
            {
                editData(fileName);
                break;
            }
            case 6:
            {
                toSwitch = false;
                break;
            }
        }
    }


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

        fprintf(file, "%s %d %d %d %d %d %d %f\n", st.name,
                st.yearOfBirdth, st.group,
                st.grades[0], st.grades[1],
                st.grades[2], st.grades[3], st.avgGrade);

        printf ("\nElement added\n");
    }

    fclose (file);
    printf("\n\n");
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
        while((fscanf(file, "%s %d %d %d %d %d %d %lf\n", &st.name,
                  &st.yearOfBirdth, &st.group,
                  &st.grades[0], &st.grades[1],
                  &st.grades[2], &st.grades[3],
                  &st.avgGrade))!= EOF)
        {
            printf("\n%s %d %d %d %d %d %d %lf\n", st.name,
            st.yearOfBirdth, st.group,
            st.grades[0], st.grades[1],
            st.grades[2], st.grades[3], st.avgGrade);
        }
    }
    fclose (file);
    printf("\n\n");
}


void createFile(char fileName[])
{
    char temp[MAX_NAME_SIZE];
    printf("enter file name\n");
    scanf("%s", &temp);

    for(int i = 0; i < MAX_NAME_SIZE; i++)
    {
        fileName[i] = temp[i];
    }

    FILE *file;

    if ((file = fopen(fileName, "w")) == NULL)
    {
        printf("\nCannot create file.\n");
    }
    else
    {
        printf("\nfile Created!\n\n");
    }
    fclose (file);

}


void printExellentStudents(char fileName[])
{
    FILE *file;
    student st;
    student stArr[MAX_STARR_SIZE];

    int counter = 0;


    if ((file = fopen(fileName, "a+")) == NULL)
    {
        printf("\nCannot open file.\n");
    }
    else
    {
        while((fscanf(file, "%s %d %d %d %d %d %d %lf\n", &st.name,
             &st.yearOfBirdth, &st.group,
             &st.grades[0], &st.grades[1],
             &st.grades[2], &st.grades[3], &st.avgGrade))!= EOF)
        {
            if(st.avgGrade == 8 || st.avgGrade == 9 || st.avgGrade == 10)
            {
                printf("\n%s %d %d %d %d %d %d %lf\n",
                st.name, st.yearOfBirdth, st.group,
                st.grades[0], st.grades[1],
                st.grades[2], st.grades[3], st.avgGrade);

                stArr[counter] = st;
                counter++;

            }
        }
    }
    fclose (file);


    file = fopen("answer.txt", "w");
    fclose (file);
    file = fopen("answer.txt", "a+");

    fprintf(file, "-----------EXELLENT STUDENTS-----------------\n\n");

    for(int i = 0; i < counter; i++)
    {
        fprintf(file, "%s %d %d %d %d %d %d %f\n", stArr[i].name,
                stArr[i].yearOfBirdth, stArr[i].group,
                stArr[i].grades[0], stArr[i].grades[1],
                stArr[i].grades[2], stArr[i].grades[3], stArr[i].avgGrade);
    }

    printf("\n\n");
    fclose (file);
}


void editData(char fileName[])
{
    FILE *file;
    student st;
    student stArr[MAX_STARR_SIZE];
    int userChoice, counter = 0;


    if ((file = fopen(fileName, "r")) == NULL)
    {
        printf("\nCannot open file.\n");
    }
    else
    {
        while((fscanf(file, "%s %d %d %d %d %d %d %lf\n", &st.name,
                  &st.yearOfBirdth, &st.group,
                  &st.grades[0], &st.grades[1],
                  &st.grades[2], &st.grades[3],
                  &st.avgGrade))!= EOF)
        {
            printf("\n%d %s %d %d %d %d %d %d %lf\n", counter++,
            st.name, st.yearOfBirdth, st.group,
            st.grades[0], st.grades[1],
            st.grades[2], st.grades[3], st.avgGrade);

            stArr[counter] = st;
        }
    }

    fclose (file);

    printf("\n\nWhich element you want to edit? enter number\n");
    scanf("%d", &userChoice);


        printf("\nEnter name:\n");
        scanf("%s", &stArr[userChoice].name);

        printf("Enter year of birdth:\n");
        scanf("%s", &stArr[userChoice].yearOfBirdth);

        printf("Enter group number:\n");
        scanf("%d", &stArr[userChoice].group);

        printf("Enter grades physics, math, cs, chemistry:\n");
        scanf("%d\n", &stArr[userChoice].grades[0]);
        scanf("%d\n", &stArr[userChoice].grades[1]);
        scanf("%d\n", &stArr[userChoice].grades[2]);
        scanf("%d", &stArr[userChoice].grades[3]);

        stArr[userChoice].avgGrade = avgGrade(stArr[userChoice].grades);

    file = fopen(fileName, "w");
    fclose (file);

    file = fopen(fileName, "a+");

    for(int i = 0; i < counter; i++)
    {
        fprintf(file, "%s %d %d %d %d %d %d %f\n", stArr[i].name,
                stArr[i].yearOfBirdth, stArr[i].group,
                stArr[i].grades[0], stArr[i].grades[1],
                stArr[i].grades[2], stArr[i].grades[3], stArr[i].avgGrade);
    }

    fclose (file);

    printf("Edited! Result:\n\n");

    for(int i = 0; i < counter; i++)
    {
        printf("%s %d %d %d %d %d %d %f\n", stArr[i].name,
            stArr[i].yearOfBirdth, stArr[i].group,
            stArr[i].grades[0], stArr[i].grades[1],
            stArr[i].grades[2], stArr[i].grades[3],
            stArr[i].avgGrade);
    }

    printf("\n\n");

}

