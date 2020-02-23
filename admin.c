#include "admin.h"
#include <stdio.h>
#define PASSWARD_LEN 4


static EnumSystemKey_t key = LOOK;

static unsigned char arr_Right_passward[PASSWARD_LEN]= {'1','2','3','4'};

int ID_Counter=0;
StrPataint_t arr_strPatient[100];

unsigned char arr_slotsStatus[6];

int temp_ID;


static void Admin_Add_NewPatient()
{
    arr_strPatient[ID_Counter].Patient_ID = ID_Counter;
    printf("Patient ID : %d\n",ID_Counter);

    printf("enter name :\n");
    scanf("%s",arr_strPatient[ID_Counter].name);

    printf("enter age :\n");
    scanf("%d",&arr_strPatient[ID_Counter].age);

    printf("enter gender \n1-male\n2-female :\n");
    scanf("%d",&arr_strPatient[ID_Counter].gender);

    arr_strPatient[ID_Counter].reserve_slot = NO_RESERVATION;

    ID_Counter++;
}

static void Admin_Edit_Patient()
{
    int Patint_ID;
    printf("\n\nenter patient ID\n");
    scanf("%d",&Patint_ID);
    if(Patint_ID < ID_Counter)
    {
        char ch;
        printf("\nto edit name press 'N'");
        printf("\nto edit age press 'A'");
        printf("\nto edit gender press 'G'");
        printf("\nto exist press 'E' \n");
        do
        {
            fflush(stdin);
            scanf("%c",&ch);

            switch(ch)
            {
            case 'N':
            {
                printf("enter new name \n");
                scanf("%s",arr_strPatient[Patint_ID].name);
                break;
            }
            case 'A':
            {
                printf("enter new age \n");
                scanf("%d",&arr_strPatient[Patint_ID].age);
                break;
            }
            case 'G':
            {
                printf("enter new gender 1-Male\n2-Female\n");
                scanf("%d",&arr_strPatient[Patint_ID].gender);
                break;
            }
            default :
            {
                //error
            }
            }
        }
        while(ch !='E');
    }
    else
    {
        printf("patient not exist");
    }
}

static void Admin_Reserve_Slot()
{
    unsigned char slot;
    printf("\nEnter patient ID\n");
    fflush(stdin);
    scanf("%d",&temp_ID);
    printf("\nEnter avaliable Slot");
    if(arr_slotsStatus[1]==0)
    {
        printf("\n1- 2 : 2.30");
    }
    if(arr_slotsStatus[2]==0)
    {
        printf("\n2- 2.30 : 3");
    }

    if(arr_slotsStatus[3]==0)
    {
        printf("\n3- 3 : 3.30");
    }

    if(arr_slotsStatus[4]==0)
    {
        printf("\n4- 4 : 4.30");
    }

    if(arr_slotsStatus[5]==0)
    {

        printf("\n5- 4.30 : 5\n");
    }

    fflush(stdin);
    scanf("%d",&slot);
    arr_strPatient[temp_ID].reserve_slot = slot;
    arr_slotsStatus[slot] = 1;
}

static void Admin_Cancel_Slot()
{
    int Patint_ID;
    unsigned char slot;
    printf("\nEnter patient ID\n");
    fflush(stdin);
    scanf("%d",&Patint_ID);

        if(arr_strPatient[Patint_ID].reserve_slot != NO_RESERVATION)
    {
        arr_slotsStatus[arr_strPatient[Patint_ID].reserve_slot] = 0;
        arr_strPatient[Patint_ID].reserve_slot = NO_RESERVATION;
        printf("Reservation Cancelled succefully");
        delay(2); // Wait a second
    }
    else
    {
        printf("patient has no reservation\n");
        delay(2); // Wait a second
    }
}



unsigned char Admin_CheckPassword(unsigned char* arr)
{
    unsigned char ret_Type = 1;
    unsigned int Check_Sum=0,i;
    unsigned char flag = 1;

    for(i=0; i<PASSWARD_LEN; i++)
    {
        if(arr[i]!=arr_Right_passward[i])
        {
            flag=0;
        }
    }

    if(flag)
    {
        key=UNLOOK;
        ret_Type = 0;
    }
    else
    {
        ret_Type =1;
    }
    return ret_Type;
}

void Admin_perform_operation(unsigned char op)
{
    switch(op)
    {
    case '1' :
    {
        Admin_Add_NewPatient();
        break;
    }
    case '2' :
    {
        Admin_Edit_Patient();
        break;
    }
    case '3' :
    {
        Admin_Reserve_Slot();
        break;
    }
    case '4' :
    {
        Admin_Cancel_Slot();
        break;
    }
    }
}


