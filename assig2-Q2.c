#include <stdio.h>
#include <string.h>

#define MAX 100

int codes[4] = {1, 2, 3, 4};
int stock[4] = {50, 10, 20, 8};
int price[4] = {100, 200, 300, 150};

char cname[50];
char cnic[20];

void customerInfo() {
    printf("Enter customer name: ");
    getchar(); // clear buffer
    gets(cname);
    printf("Enter CNIC: ");
    gets(cnic);
    printf("Customer info saved!\n");
}

void displayInventory() {
    printf("\nCode\tStock\tPrice\n");
    int i;
    for (i = 0; i < 4; i++)
        printf("%d\t%d\t%d\n", codes[i], stock[i], price[i]);
}

void updateInventory(int code, int qty) {
	int i;
    for (i = 0; i < 4; i++) {
        if (codes[i] == code) {
            stock[i] -= qty;
            if (stock[i] < 0) stock[i] = 0;
        }
    }
}

void addToCart(int cartCode[], int cartQty[], int *cartCount) {
    int code, qty;
    displayInventory();
    printf("\nEnter product code to add: ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &qty);
int i;
    for (i = 0; i < 4; i++) {
        if (codes[i] == code) {
            if (qty > stock[i]) {
                printf("Not enough stock!\n");
                return;
            } else {
                cartCode[*cartCount] = code;
                cartQty[*cartCount] = qty;
                (*cartCount)++;
                updateInventory(code, qty);
                printf("Added to cart!\n");
                return;
            }
        }
    }
    printf("Invalid product code!\n");
}

void displayBill(int cartCode[], int cartQty[], int cartCount) {
    int total = 0;
    printf("\n--- Customer Invoice ---\n");
    printf("Name: %s\nCNIC: %s\n", cname, cnic);
    printf("\nCode\tQty\tPrice\tTotal\n");
    int i,j;
    for (i = 0; i < cartCount; i++) {
        for (j = 0; j < 4; j++) {
            if (cartCode[i] == codes[j]) {
                int subtotal = cartQty[i] * price[j];
                printf("%d\t%d\t%d\t%d\n", codes[j], cartQty[i], price[j], subtotal);
                total += subtotal;
            }
        }
    }
    printf("---------------------------\n");
    printf("Total Bill: %d\n", total);

    char promo[20];
    printf("Enter promocode (if any): ");
    getchar();
    gets(promo);

    if (strcmp(promo, "Eid2025") == 0) {
        float discount = total * 0.25;
        float finalTotal = total - discount;
        printf("25%% discount applied!\nFinal Bill: %.2f\n", finalTotal);
    } else {
        printf("No discount applied.\n");
    }
}

int main() {
    int choice;
    int cartCode[MAX], cartQty[MAX];
    int cartCount = 0;

    while (1) {
        printf("\n--- Supermarket System ---\n");
        printf("1. Enter Customer Info\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Show Invoice\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: customerInfo(); break;
            case 2: displayInventory(); break;
            case 3: addToCart(cartCode, cartQty, &cartCount); break;
            case 4: displayBill(cartCode, cartQty, cartCount); break;
            case 0: printf("Exiting system...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

