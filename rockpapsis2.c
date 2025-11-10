#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. User choice function
int getUserChoice() {
    int choice = 0;
    do {
        printf("Choose an option\n");
        printf("1. ROCK\n");
        printf("2. PAPER\n");
        printf("3. SCISSORS\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);
    return choice;
}

// 2. Computer choice function
int getComputerChoice() {
    return (rand() % 3) + 1;
}

// 3. Winner check function
int checkWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        return 0; // Tie
    }
    else if ((userChoice == 1 && computerChoice == 3) ||
             (userChoice == 2 && computerChoice == 1) ||
             (userChoice == 3 && computerChoice == 2)) {
        return 1; // User wins
    }
    else {
        return 2; // Computer wins
    }
}

// 4. Main function
int main() {
    srand(time(NULL));
    printf("*** ROCK PAPER SCISSORS ***\n");

    int userChoice = getUserChoice();
    int computerChoice = getComputerChoice();

    // Print user choice
    switch(userChoice) {
        case 1: printf("You chose ROCK!\n"); break;
        case 2: printf("You chose PAPER!\n"); break;
        case 3: printf("You chose SCISSORS!\n"); break;
    }

    // Print computer choice
    switch(computerChoice) {
        case 1: printf("Computer chose ROCK!\n"); break;
        case 2: printf("Computer chose PAPER!\n"); break;
        case 3: printf("Computer chose SCISSORS!\n"); break;
    }

    // Decide the winner
    int result = checkWinner(userChoice, computerChoice);

    if (result == 0) {
        printf("It's a TIE!\n");
    }
    else if (result == 1) {
        printf("You WIN!\n");
    }
    else {
        printf("Computer WINS!\n");
    }

    return 0;
}
