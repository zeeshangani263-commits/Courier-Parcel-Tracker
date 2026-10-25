#include <stdio.h>
#include <string.h>

#define BASE_CHARGE  150
#define CHARGE_PER_KILO  50

void print_banner(void)
{
    printf("**********************************************\n");
    printf("+----Welcome to Courier Parcel Tracker------+\n");
    printf("**********************************************\n\n");

}

int print_menu()
{
    int choice;
    printf("   +-------------MENU------------------+\n");
    printf("\t1. Book a Parcel\n");
    printf("\t2. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

double getWeightInput(){

    double weight = 0.0;
    printf("Enter the weight in grams: ");
    scanf("%lf", &weight);
    return weight;
}

double computeCharge(int weightGrams)
{
    double charge;
    int extra_weight = 0;
    int extra_kg = 0;

    if(weightGrams <= 500){

        charge = BASE_CHARGE;
    }
    else
    {
        extra_weight = weightGrams - 500;
        extra_kg = (extra_weight + 999) / 1000;
        charge = BASE_CHARGE + (extra_kg * CHARGE_PER_KILO);

    }
    return charge;


}

void displayReceipt(char code[], int weight, double charge)
{
    printf("\n----Receipt---\n");
    printf("Tracking Code: %s\n", code);
    printf("Weight:        %d g\n", weight);
    printf("Total Charge:  %.2fTk\n", charge);
    printf("-----------------\n");


}
int main(void){


    char trackingCode[50];
    int weightGrams;
    double finalCharge;
    int menuChoice;


    print_banner();

    menuChoice = print_menu();

    if (menuChoice == 1){

        printf("Enter Tracking Code: ");
        scanf("%s", trackingCode);


        weightGrams = getWeightInput();

        finalCharge = computeCharge(weightGrams);

        displayReceipt(trackingCode, weightGrams, finalCharge);
    }

    else{

        printf("Exiting the program\n");
    }
    return 0;
}