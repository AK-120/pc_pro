#include <stdio.h>
#include <string.h>

struct DC_Cafe_Item {
    char name[100];
    double price;
    int quantity;
};

// Function to display the menu and prices
void displayMenu() {
    printf("Welcome to DC CAFE\n");
    printf("Menu:\n");
    printf("1. Tea - $2.00\n");
    printf("2. Coffee - $2.50\n");
    printf("3. Espresso - $3.00\n");
    printf("4. Americano - $2.75\n");
    printf("5. Cappuccino - $3.50\n");
    printf("6. Cookies - $1.50\n");
    printf("7. Brownies - $2.00\n");
    printf("8. Donuts - $1.75\n");
    printf("9. Danish Pastries - $3.25\n");
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

        // Set item details based on user's choice
        switch (choice) {
            case 1:
                strcpy(items[i].name, "Tea");
                items[i].price = 2.00;
                break;
            case 2:
                strcpy(items[i].name, "Coffee");
                items[i].price = 2.50;
                break;
            case 3:
                strcpy(items[i].name, "Espresso");
                items[i].price = 3.00;
                break;
            case 4:
                strcpy(items[i].name, "Americano");
                items[i].price = 2.75;
                break;
            case 5:
                strcpy(items[i].name, "Cappuccino");
                items[i].price = 3.50;
                break;
            case 6:
                strcpy(items[i].name, "Cookies");
                items[i].price = 1.50;
                break;
            case 7:
                strcpy(items[i].name, "Brownies");
                items[i].price = 2.00;
                break;
            case 8:
                strcpy(items[i].name, "Donuts");
                items[i].price = 1.75;
                break;
            case 9:
                strcpy(items[i].name, "Danish Pastries");
                items[i].price = 3.25;
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

    // Confirmation step for the entire order
    printf("\nConfirm your order (Y/N): ");
    char confirmation;
    scanf(" %c", &confirmation);

    if (confirmation == 'Y' || confirmation == 'y') {
        printf("\nDC CAFE - Cafe Bill for %s:\n", customerName);
        printf("----------------------------\n");
        for (int i = 0; i < numItems; i++) {
            printf("%s (Quantity: %d) - $%.2lf\n", items[i].name, items[i].quantity, items[i].price * items[i].quantity);
        }
        printf("\nTotal Bill: $%.2lf\n", totalBill);
        printf("----------------------------\n");
    } else {
        printf("\nOrder canceled. No bill generated.\n");
    }

    return 0;
}
