#include <stdio.h>
#include <stdlib.h>

// Clears the terminal screen using standard ANSI escape sequences
void clearScreen() {
    printf("\033[H\033[J");
}

// Pauses execution and waits for the user to press Enter
void pauseForUser() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // Clear any leftover newline from previous input
    getchar(); // Wait for the user to press Enter
}

// Module 1: Physical Unit Conversions Sub-Menu
void runUnitConversions() {
    int subChoice;

    do {
        clearScreen();
        printf("========================================\n");
        printf("       PHYSICAL UNIT CONVERSIONS        \n");
        printf("========================================\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Kilograms to Pounds\n");
        printf("6. Pounds to Kilograms\n");
        printf("7. Return to Main Menu\n");
        printf("----------------------------------------\n");
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &subChoice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the invalid input from buffer
            pauseForUser();
            continue;
        }

        switch (subChoice) {
            case 1: {
                double c, f;
                printf("Enter temperature in Celsius: ");
                if (scanf("%lf", &c) != 1) {
                    printf("Invalid number entered.\n");
                    while (getchar() != '\n');
                } else {
                    f = (c * 9.0 / 5.0) + 32.0;
                    printf("Result: %.2f°C = %.2f°F\n", c, f);
                }
                pauseForUser();
                break;
            }
            case 2: {
                double c, f;
                printf("Enter temperature in Fahrenheit: ");
                if (scanf("%lf", &f) != 1) {
                    printf("Invalid number entered.\n");
                    while (getchar() != '\n');
                } else {
                    c = (f - 32.0) * 5.0 / 9.0;
                    printf("Result: %.2f°F = %.2f°C\n", f, c);
                }
                pauseForUser();
                break;
            }
            case 3: {
                double km, miles;
                printf("Enter distance in Kilometers: ");
                if (scanf("%lf", &km) != 1) {
                    printf("Invalid number entered.\n");
                    while (getchar() != '\n');
                } else {
                    miles = km / 1.60934;
                    printf("Result: %.2f km = %.2f miles\n", km, miles);
                }
                pauseForUser();
                break;
            }
            case 4: {
                double km, miles;
                printf("Enter distance in Miles: ");
                if (scanf("%lf", &miles) != 1) {
                    printf("Invalid number entered.\n");
                    while (getchar() != '\n');
                } else {
                    km = miles * 1.60934;
                    printf("Result: %.2f miles = %.2f km\n", miles, km);
                }
                pauseForUser();
                break;
            }
            case 5: {
                double kg, lbs;
                printf("Enter weight in Kilograms: ");
                if (scanf("%lf", &kg) != 1) {
                    printf("Invalid number entered.\n");
                    while (getchar() != '\n');
                } else {
                    lbs = kg * 2.20462;
                    printf("Result: %.2f kg = %.2f lbs\n", kg, lbs);
                }
                pauseForUser();
                break;
            }
            case 6: {
                double kg, lbs;
                printf("Enter weight in Pounds: ");
                if (scanf("%lf", &lbs) != 1) {
                    printf("Invalid number entered.\n");
                    while (getchar() != '\n');
                } else {
                    kg = lbs / 2.20462;
                    printf("Result: %.2f lbs = %.2f kg\n", lbs, kg);
                }
                pauseForUser();
                break;
            }
            case 7:
                printf("\nReturning to Main Menu...\n");
                break;
            default:
                printf("\nInvalid choice. Please select between 1 and 7.\n");
                pauseForUser();
        }

    } while (subChoice != 7);
}

// Module 2: Financial & Investment Calculator
void runFinancialCalculator() {
    double principal, rate, annualContribution;
    int years;

    clearScreen();
    printf("========================================\n");
    printf("     FINANCIAL & INVESTMENT SCHEDULE    \n");
    printf("========================================\n");

    printf("Enter initial principal amount ($): ");
    if (scanf("%lf", &principal) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        pauseForUser();
        return;
    }

    printf("Enter annual interest rate (e.g., 6.5 for 6.5%%): ");
    if (scanf("%lf", &rate) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        pauseForUser();
        return;
    }

    printf("Enter investment duration (years): ");
    if (scanf("%d", &years) != 1 || years <= 0) {
        printf("Invalid year count.\n");
        while (getchar() != '\n');
        pauseForUser();
        return;
    }

    printf("Enter additional annual contribution at end of each year ($): ");
    if (scanf("%lf", &annualContribution) != 1) {
        annualContribution = 0.0;
        while (getchar() != '\n');
    }

    printf("\n%-6s %-18s %-18s %-18s\n", "Year", "Starting Balance", "Interest Earned", "Ending Balance");
    printf("-------------------------------------------------------------------\n");

    double currentBalance = principal;
    for (int i = 1; i <= years; i++) {
        double startBal = currentBalance;
        double interestEarned = startBal * (rate / 100.0);
        currentBalance = startBal + interestEarned + annualContribution;

        printf("%-6d $%-17.2f $%-17.2f $%-17.2f\n", i, startBal, interestEarned, currentBalance);
    }
    printf("-------------------------------------------------------------------\n");
    printf("Final Portfolio Value: $%.2f\n", currentBalance);

    pauseForUser();
}

// Main Program Loop
int main() {
    int choice;

    do {
        clearScreen();
        printf("========================================\n");
        printf("       CLI MULTI-PURPOSE CALCULATOR     \n");
        printf("========================================\n");
        printf("1. Physical Unit Conversions\n");
        printf("2. Financial & Investment Schedule\n");
        printf("3. Exit Program\n");
        printf("----------------------------------------\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the invalid input
            pauseForUser();
            continue;
        }

        switch (choice) {
            case 1:
                runUnitConversions();
                break;
            case 2:
                runFinancialCalculator();
                break;
            case 3:
                clearScreen();
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select 1, 2, or 3.\n");
                pauseForUser();
        }

    } while (choice != 3);

    return 0;
}