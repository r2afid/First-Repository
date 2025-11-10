#include <stdio.h>

// Function declarations
void menu(float *balance);
void deposit(float *balance);
void withdraw(float *balance);
void checkBalance(float balance);

// Function to show menu
void menu(float *balance) {
    int choice;
    printf("\n====== Mini Bank System ======\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deposit(balance);
            break;
        case 2:
            withdraw(balance);
            break;
        case 3:
            checkBalance(*balance);
            break;
        case 4:
            printf("Thank you for using Mini Bank System!\n");
            return; // exits
        default:
            printf("Invalid choice!\n");
    }

    // after action, return to menu
    menu(balance);
}

// Deposit function
void deposit(float *balance) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0) {
        *balance += amount; // update balance
        printf("Deposited: %.2f\n", amount);
    } else {
        printf("Invalid amount!\n");
    }
}

// Withdraw function
void withdraw(float *balance) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= *balance) {
        *balance -= amount; // update balance
        printf("Withdrawn: %.2f\n", amount);
    } else {
        printf("Insufficient balance or invalid amount!\n");
    }
}

// Check balance function
void checkBalance(float balance) {
    printf("Current Balance: %.2f\n", balance);
}

// Main function
int main() {
    float balance = 0.0;
    menu(&balance); // start program
    return 0;
}
