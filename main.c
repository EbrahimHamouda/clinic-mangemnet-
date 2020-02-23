#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "Data_types.h"
#include "user.h"


#define MAX_ATTEMPS 3

enmMood_t  Mood;
unsigned Password_Wrongcounter=0;
unsigned char op;

int main()
{

    printf("Enter MOOD:\n1-Admin\n2-user\n");
    scanf("%d",&Mood);

    if(Mood==ADMIN)
    {
        unsigned char arr[4];
        do
        {
            Password_Wrongcounter++;
            printf("\nenter passward please\n");
            scanf("%s",arr);

            if(Password_Wrongcounter >= MAX_ATTEMPS)
            {
                printf("********************************\nSystem_close");
                return 0;
            }
        }
        while(Admin_CheckPassword(arr));

        while(1)
        {
            system("cls");
            printf("choose operation :\n1. Add new patient record\n2. Edit patient record\n3. Reserve a slot with the doctor \n4. Cancel reservation.\n5. restart system\n");
            fflush(stdin);
            scanf("%c",&op);
            if(op=='5')
            {
                main(); // error
            }
            Admin_perform_operation(op);
        }
    }
    else if(Mood==USER)
    {
        char op;
        while(1)
        {
            system("cls");
            printf("choose operation :\n1. View patient record\n2. View today reservations\n");
            fflush(stdin);
            scanf("%c",&op);
            if(op =='1')
            {
                View_patient_record();
            }
            else
            {
                View_today_reservations();
            }
        }
    }
    else
    {
        // error
    }

    return 0;
}



