#include <stdio.h>
#include <string.h>

#define MAX 100

int isbns[MAX];
char titles[MAX][50];
float prices[MAX];
int qty[MAX];
int count = 0;

int findBook(int isbn) {
	int i;
    for (i = 0; i < count; i++)
        if (isbns[i] == isbn)
            return i;
    return -1;
}

void addNewBook() {
    int isbn;
    char title[50];
    float price;
    int q;

    if (count >= MAX) {
        printf("Inventory full!\n");
        return;
    }

    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    if (findBook(isbn) != -1) {
        printf("Book already exists!\n");
        return;
    }

    printf("Enter title: ");
    getchar();  // clear newline
    gets(title);
    printf("Enter price: ");
    scanf("%f", &price);
    printf("Enter quantity: ");
    scanf("%d", &q);

    isbns[count] = isbn;
    strcpy(titles[count], title);
    prices[count] = price;
    qty[count] = q;
    count++;

    printf("Book added!\n");
}

void processSell() {
    int isbn, sell;
    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    int i = findBook(isbn);
    if (i == -1) {
        printf("Book not found!\n");
        return;
    }
    printf("Enter copies to sell: ");
    scanf("%d", &sell);
    if (sell > qty[i])
        printf("Not enough stock!\n");
    else {
        qty[i] -= sell;
        printf("Sale done! Remaining: %d\n", qty[i]);
    }
}

void lowStockReport() {
    printf("\nLow Stock Books (<5):\n");
    int i;
    for (i = 0; i < count; i++)
        if (qty[i] < 5)
            printf("%d | %s | %.2f | %d\n", isbns[i], titles[i], prices[i], qty[i]);
}

void listAllBooks() {
    if (count == 0) {
        printf("No books in inventory.\n");
        return;
    }

    printf("\nAll Books in Inventory:\n");
    printf("ISBN\tTitle\t\tPrice\tQty\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", isbns[i], titles[i], prices[i], qty[i]);
    }
}

int main() {
    int ch;
    while (1) {
    	printf("\n--- Liberty Books Inventory ---\n");
    	printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Low-Stock Report (quantity < 5)\n");
        printf("4. List All Books\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addNewBook(); break;
            case 2: processSell(); break;
            case 3: lowStockReport(); break;
            case 4: listAllBooks() ; break;
            case 0: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
