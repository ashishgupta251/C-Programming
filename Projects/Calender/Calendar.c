#include<stdio.h>

void printCalendar(int month, int year);
int getFirstDayOfMonth(int month, int year);
int isLeapYear(int year);
const char* getMonthName(int month);

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12) {
        printf("Invalid month! Please enter a value between 1 and 12.\n");
        return 1;
    }

    printCalendar(month, year);
    return 0;
}

void printCalendar(int month, int year) {
    int daysInMonth;
    const char* monthName = getMonthName(month);
    
    // Determine the number of days in the month
    if (month == 2) {
        daysInMonth = isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    printf("\n  %s %d\n", monthName, year);
    printf("Su Mo Tu We Th Fr Sa\n");

    // Get the first day of the month
    int firstDay = getFirstDayOfMonth(month, year);

    // Print leading spaces
    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int getFirstDayOfMonth(int month, int year) {
    // Zeller's Congruence algorithm to find the day of the week
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int dayOfWeek = (1 + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - 2 * j) % 7;
    return (dayOfWeek + 5) % 7; // Adjust to make Sunday = 0
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

const char* getMonthName(int month) {
    const char* monthNames[] = {
        "Invalid", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[month];
}
