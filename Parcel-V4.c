#include <stdio.h>
#include <string.h>

#define BASE_CHARGE  150
#define CHARGE_PER_KILO  50

int globalTrackingCode = 0;
int globalWeight = 0;
double globalCharge = 0.0;

void print_banner(void)
{
    printf("**********************************************\n");
    printf("+----Welcome to Courier Parcel Tracker------+\n");
    printf("**********************************************\n\n");

}

void print_menu()
{
    int choice;
    printf("+-------------MENU------------------+\n");
    printf("\t1. Book a Parcel\n");
    printf("\t2. View Current Parcel\n");
    printf("\t3. Exit\n");
    printf("Enter choice: ");
    
}

double inputParcelData(){

    int Code;
    int Weight;

    printf("\n**** Enter Parcel Details **\n");

    printf("Enter tracking code: ");
    scanf("%d", &Code);

    while(Code <= 0){
        printf("Invalid code. Must be greater than 0.\n");
        printf("Enter tracking code: ");
        scanf("%d", &Code);
    }
    globalTrackingCode = Code;

    printf("Enter weight in grams: ");
    scanf("%d", &Weight);

    while(Weight <= 0){

        printf("Invalid weight. Weight must be greater than 0.\n");
        printf("Enter weight in grams: ");
        scanf("%d", &Weight);
    }

    globalWeight = Weight;
}

double computeCharge()
{
    int extra_weight = 0;
    int extra_kg = 0;
    if(globalWeight == 0){
        printf("\nNo parcel booked yet.\n");
        return 0;
    }

    if(globalWeight <= 500){
        globalCharge = BASE_CHARGE;
    }
    else{
        extra_weight = globalWeight - 500;
        extra_kg = (extra_weight + 999) / 1000;
        globalCharge = BASE_CHARGE + (extra_kg * CHARGE_PER_KILO);

    }

    printf("\n----------Classification--------\n");
    if(globalWeight <= 500){
        printf("Category: Light Parcel\n");
    }
    else if(globalWeight > 500 && globalWeight <=2000){

        printf("Category: Standard Parcel\n");
    }
    else{
        printf("Category: Heavy Parcel\n");
    }
    

}

double displayReceipt()
{
    if(globalTrackingCode == 0){
        printf("\nNo parcel data to display.\n");
        return 0;
    }

    printf("\n----Receipt---\n");
    printf("Tracking Code: %d\n", globalTrackingCode);
    printf("Weight:        %d g\n", globalWeight);
    printf("Total Charge:  %.2fTk\n", globalCharge);
    printf("-----------------\n");


}
int main(void){


    int menuChoice = -1;
   
    print_banner();

    while(menuChoice != 0){
        print_menu();
        scanf("%d", &menuChoice);


        switch(menuChoice)
        {
            case 1:
               inputParcelData();
               computeCharge();
               displayReceipt();
               break;

            case 2:
                displayReceipt();
                break;
            
            case 0:
                printf("\nExiting the program\n");
                break;

            default:
                printf("\nInvalid choice. Please choose between 1, 2 or 3.\n");
                break;

        }
          
    }

  
    return 0;
}