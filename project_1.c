#include <stdio.h>
#include <string.h>

struct DC_Cafe_Item {
    char name[100];
    double price;
    int quantity;
};


void displayMenu() {
    printf("Welcome to DC CAFE\n");
    printf("Menu:\n");
    printf("1. Tea - ₹120.00\n");
    printf("2. Coffee - ₹150.00\n");
    printf("3. Espresso - ₹180.00\n");
    printf("4. Americano - ₹165.00\n");
    printf("5. Cappuccino - ₹210.00\n");
    printf("6. Cookies - ₹90.00\n");
    printf("7. Brownies - ₹120.00\n");
    printf("8. Donuts - ₹105.00\n");
    printf("9. Danish Pastries - ₹195.00\n");
}

int main() {
    int numItems;
    double totalBill = 0.0;
    char customerName[100];

    displayMenu();

    printf("\nEnter the number of items ordered: ");
    scanf("%d", &numItems);

    struct DC_Cafe_Item items[numItems];

    for (int i = 0; i < numItems; i++) {
        printf("\nEnter details for item %d:\n", i + 1);

        int choice;
        printf("Enter the item number (1-9): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid choice. Please enter a number between 1 and 9.\n");
            i--;
            continue;
        }
        switch (choice) {
            case 1:
                strcpy(items[i].name, "Tea");
                items[i].price = 120.00;
                break;
            case 2:
                strcpy(items[i].name, "Coffee");
                items[i].price = 150.00;
                break;
            case 3:
                strcpy(items[i].name, "Espresso");
                items[i].price = 180.00;
                break;
            case 4:
                strcpy(items[i].name, "Americano");
                items[i].price = 165.00;
                break;
            case 5:
                strcpy(items[i].name, "Cappuccino");
                items[i].price = 210.00;
                break;
            case 6:
                strcpy(items[i].name, "Cookies");
                items[i].price = 90.00;
                break;
            case 7:
                strcpy(items[i].name, "Brownies");
                items[i].price = 120.00;
                break;
            case 8:
                strcpy(items[i].name, "Donuts");
                items[i].price = 105.00;
                break;
            case 9:
                strcpy(items[i].name, "Danish Pastries");
                items[i].price = 195.00;
                break;
        }

        printf("You selected: %s\n", items[i].name);

        printf("Enter the quantity: ");
        scanf("%d", &items[i].quantity);

        double itemAmount = items[i].price * items[i].quantity;
        totalBill += itemAmount;
    }

    printf("\nEnter customer's name: ");
    scanf("%s", customerName);

    printf("\nConfirm your order (Y/N): ");
    char confirmation;
    scanf(" %c", &confirmation);

    if (confirmation == 'Y' || confirmation == 'y') {
        printf("\nDC CAFE - Cafe Bill for %s:\n", customerName);
        printf("----------------------------\n");
        for (int i = 0; i < numItems; i++) {
            printf("%s (Quantity: %d) - ₹%.2lf\n", items[i].name, items[i].quantity, items[i].price * items[i].quantity);
        }
        printf("\nTotal Bill: ₹%.2lf\n", totalBill);
        printf("----------------------------\n");
    } else {
        printf("\nOrder canceled. No bill generated.\n");
    }

    return 0;
}
