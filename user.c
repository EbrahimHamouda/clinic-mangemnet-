#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"

extern StrPataint_t arr_strPatient[100];
extern unsigned char arr_slotsStatus[5];
extern int ID_Counter;

char dummy;

void View_patient_record()
{
    int patient_ID;
    printf("enter patient ID\n");
    scanf("%d",&patient_ID);

    printf("name:%s\n",arr_strPatient[patient_ID].name);
    printf("age:%d\n",arr_strPatient[patient_ID].age);
    printf("Patient_ID:%d\n",arr_strPatient[patient_ID].Patient_ID);
    printf("gender:");

    if(arr_strPatient[patient_ID].gender==MALE)
    {
        printf("male\n");
    }
    else
    {
        printf("female\n");
    }
    fflush(stdin);
    scanf("%c",&dummy);
}


void View_today_reservations()
{
    int i;
    for(i=0; i<5; i++)
    {
        if(arr_slotsStatus[i] == 1)
        {
            switch (i+1)
            {
            case 1 :
                printf("2 : 2.30\n");break;
            case 2 :
                printf("2.30 : 3\n");break;

            case 3 :
                printf("3 : 3.30\n");break;

            case 4 :
                printf("4 : 4.30\n");break;

            case 5 :
                printf("4.30 : 5\n");break;
            }
        }
    }
    fflush(stdin);
    scanf("%c",&dummy);
}
