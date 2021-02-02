#include <stdio.h>

// Code made for exam.

int main() {
    int quantity[100], orderSize;
    char orders[100];
    float totalPurchase, totalDiscount, grandTotal = 0.00;

    printf("Enter the total number of orders: ");
    scanf("%d", &orderSize);

    printf("\nATTENTION: BUNDLE BUYING IS NOT AVAILABLE DUE TO CUSTOMER COMPLAINTS. \n");
    printf("BY MANAGEMENT\n");

    printf("\nITEMS \n");
    printf("A. Item_A \n");
    printf("B. Item_B \n");
    printf("C. Item_C \n");
    printf("D. Item_D \n");
    printf("E. Item_E \n");

    for (int i = 1; i <= orderSize; i++) {
        printf("\nEnter Order %d: ", i);
        scanf(" %c",&orders[i]);
        printf("Quantity: ");
        scanf("%d",&quantity[i]);
    }

    for (int i = 1; i <= orderSize; i++) {
        if (orders[i] == 'A') {
            totalPurchase = totalPurchase + 3400.00 * quantity[i];

            if (quantity[i] >= 3) {
                totalDiscount = totalDiscount + (3400.00 * quantity[i]) * 0.18;
                grandTotal = grandTotal + (3400.00 * quantity[i]) * 0.18;
            } else if (quantity[i] == 2) {
                totalDiscount = totalDiscount + (3400.00 * quantity[i]) * 0.15;
                grandTotal = grandTotal + (3400.00 * quantity[i]) * 0.15;
            } else {
                grandTotal = grandTotal + 3400.00 * quantity[i];
            }
        }

        if (orders[i] == 'B') {
            totalPurchase = totalPurchase + 1034.00 * quantity[i];

            if (quantity[i] >= 3) {
                totalDiscount = totalDiscount + (1034.00 * quantity[i]) * 0.18;
                grandTotal = grandTotal + (1034.00 * quantity[i]) * 0.18;
            } else if (quantity[i] == 2) {
                totalDiscount = totalDiscount + (1034.00 * quantity[i]) * 0.15;
                grandTotal = grandTotal + (1034.00 * quantity[i]) * 0.15;
            } else {
                grandTotal = grandTotal + 1034.00 * quantity[i];
            }
        }

        if (orders[i] == 'C') {
            totalPurchase = totalPurchase + 240.50 * quantity[i];

            if (quantity[i] >= 3) {
                totalDiscount = totalDiscount + (240.50 * quantity[i]) * 0.18;
                grandTotal = grandTotal + (240.50 * quantity[i]) * 0.18;
            } else if (quantity[i] == 2) {
                totalDiscount = totalDiscount + (240.50 * quantity[i]) * 0.15;
                grandTotal = grandTotal + (240.50 * quantity[i]) * 0.15;
            } else {
                grandTotal = grandTotal + 240.50 * quantity[i];
            }
        }

        if (orders[i] == 'D') {
            totalPurchase = totalPurchase + 2019.00 * quantity[i];

            if (quantity[i] >= 3) {
                totalDiscount = totalDiscount + (2019.00 * quantity[i]) * 0.18;
                grandTotal = grandTotal + (2019.00 * quantity[i]) * 0.18;
            } else if (quantity[i] == 2) {
                totalDiscount = totalDiscount + (2019.00 * quantity[i]) * 0.15;
                grandTotal = grandTotal + (2019.00 * quantity[i]) * 0.15;
            } else {
                grandTotal = grandTotal + 2019.00 * quantity[i];
            }
        }

        if (orders[i] == 'E') {
            totalPurchase = totalPurchase + 92.00 * quantity[i];

            if (quantity[i] >= 3) {
                totalDiscount = totalDiscount + (92.00 * quantity[i]) * 0.18;
                grandTotal = grandTotal + (92.00 * quantity[i]) * 0.18;
            } else if (quantity[i] == 2) {
                totalDiscount = totalDiscount + (92.00 * quantity[i]) * 0.15;
                grandTotal = grandTotal + (92.00 * quantity[i]) * 0.15;
            } else {
                grandTotal = grandTotal + 92.00 * quantity[i];
            }
        }
    }

    printf("\nTotal Purchase: Php %.2f", totalPurchase);
    printf("\nTotal Discount: Php %.2f", totalDiscount);
    printf("\nTotal: Php %.2f", grandTotal);

    return 0;
}
