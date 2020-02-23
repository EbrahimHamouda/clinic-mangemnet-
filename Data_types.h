#pragma once
typedef enum
{
    MALE=1,
    FEMALE
} enmGender_t;

typedef enum
{
    NO_RESERVATION=0,
    _2_TO_2_30=1,
    _2_30_TO_3=2,
    _3_TO_3_30=3,

    _4_TO_4_30=4,
    _4_30_TO_5=5,

} EnmSlot_t;

typedef struct
{
    char name[10];
    int age;
    enmGender_t gender;
    unsigned int Patient_ID;
    EnmSlot_t reserve_slot;
} StrPataint_t;

typedef enum
{
    ADMIN =1,
    USER =2,
} enmMood_t;

typedef enum
{
    LOOK,
    UNLOOK,
} EnumSystemKey_t;

