#include <stdio.h>
#include <string.h>

#define BASE_CHARGE  150
#define CHARGE_PER_KILO  50

int main(void){

    printf("**********************************************\n");
    printf("+----Welcome to Courier Parcel Tracker------+\n");
    printf("**********************************************\n\n");

    printf("   +-------------MENU------------------+\n");
    printf("\t1. Book a Parcel\n");
    printf("\t2. Update status\n");
    printf("\t3. Track by code\n");
    printf("\t4. Parcels by district\n");
    printf("\t5. Revenue Report\n");
    printf("\t6. Save & load\n\n");

    char Tracking_Code[50];
    int weight_grams = 0;
    int extra_weight = 0;
    int extra_kg = 0;
    double charge = 0.0;

    printf("Enter Tracking Code: ");
    scanf("%s", Tracking_Code);

    printf("Enter Parcel Weight in Grams: ");
    scanf("%d", &weight_grams);

    if(weight_grams > 500)
    {
        extra_weight = weight_grams - 500;
        extra_kg = (extra_weight+999) / 1000;
        charge = BASE_CHARGE + (extra_kg * CHARGE_PER_KILO);
    }

    printf("The Tracking Code is\t: %s\n", Tracking_Code);
    printf("The parcel price\t: %.2ftk\n", charge);

    






    printf("");
    return 0;
}