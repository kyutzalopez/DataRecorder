#include <stdio.h>
#include <string.h>

typedef struct DATE{
    int month;
    int day;
    int year; 
} DATE;

typedef struct PERSON{
    char name [100];
    DATE birthdate;
    char gender[2];
    double annualIncome;
} PERSON;

void populate (PERSON *x){
    printf("Enter a name: ");
    scanf ("%s", x->name);

    printf("\nEnter a birthday as MM/DD/YYYY: ");
    scanf ("%i/%i/%i", &x->birthdate.month, &x->birthdate.day, &x->birthdate.year);

    printf("\nEnter a gender: ");
    scanf ("%s", x->gender);

    printf("\nEnter an annual income: ");
    scanf ("%lf", &x->annualIncome);
}

void print (PERSON x){
    printf("NAME - %s\n", x.name);
    printf("BIRTHDATE - %i/%i/%i\n", x.birthdate.month, x.birthdate.day, x.birthdate.year);
    printf("GENDER - %s\n", x.gender);
    printf("ANNUAL INCOME - $%.2lf\n", x.annualIncome);

}
int leapYear (PERSON x){
    int daysInMonth [] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int monthIndex = 0;
    monthIndex = x.birthdate.month;
    //printf("%i\n", daysInMonth[monthIndex - 1]);

    if (x.birthdate.year % 4 != 0){        
        //printf("AHHHHHH");
        if (x.birthdate.day > daysInMonth[monthIndex - 1] || x.birthdate.day < 1){
            return 0; //not valid
        } 
    }
    else {
        daysInMonth[1] = 29;
        if (x.birthdate.day > daysInMonth[monthIndex - 1] || x.birthdate.day < 1){
            return 0; //not valid
        }
    }
    return 1; //valid
}

int dataValidation (PERSON x){  
   // validating the gender 
    if (x.birthdate.month < 1 || x.birthdate.month > 12){
        printf("Not a valid month.\n");
        return 0;
        }
    
    int validility = leapYear(x);
    if (validility == 0){
        printf("Not a valid day of this month\n");
        return 1;
        } 
   
    if ((strcmp(x.gender,"M") != 0) && (strcmp(x.gender,"F") != 0) && (strcmp(x.gender,"O") != 0)){
        printf("Not a valid gender.\n");
        return 2;
        }  
    
    if (x.annualIncome < 0 || x.annualIncome > 1000000){
        printf("Not a valid income\n");
        return 3;
    }
    return -1;
}

void bigFunction(PERSON p1){

    populate (&p1);
    int c = dataValidation (p1);

    while (c != -1){
        if (c == 0){
            printf("Enter a valid month\n");
            scanf ("%i", &p1.birthdate.month);
        }
        else if (c == 1){
            printf("Enter a valid day\n");
            scanf ("%i", &p1.birthdate.day);
        }
        else if (c == 2){
            printf("Enter a valid gender\n");
            scanf ("%s", p1.gender);
        }
        else if (c == 3){
            printf("Enter a valid income\n");
            scanf ("%lf", &p1.annualIncome);
        }
        c = dataValidation (p1);
    }
    print(p1);
}

void populate(PERSON *x);
int leapYear(PERSON x);
int dataValidation(PERSON x);
void print(PERSON x);
void bigFunction(PERSON p1);
int main(){
    PERSON p1;
    PERSON p2;
    PERSON p3;

    bigFunction(p1);
    printf("\n");
    bigFunction(p2);
    printf("\n");
    bigFunction(p3);
}
