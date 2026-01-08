#include <stdio.h>

#define TOTAL_SEATS 10

void displaySeats(int seats[]);
void bookSeat(int seats[]);
void cancelSeat(int seats[]);

int main() {
    int seats[TOTAL_SEATS] = {0};
    int choice;
    printf("--- Railway Booking System ---\n");
    do {
        printf("\n1. Show Seats\n2. Book\n3. Cancel\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: displaySeats(seats); break;
            case 2: bookSeat(seats); break;
            case 3: cancelSeat(seats); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}

void displaySeats(int seats[]) {
    printf("\nSeats: ");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("[%d:%s] ", i + 1, (seats[i] == 0) ? "A" : "B");
    }
    printf("\n");
}

void bookSeat(int seats[]) {
    int s;
    printf("Seat (1-%d): ", TOTAL_SEATS);
    scanf("%d", &s);
    if (s < 1 || s > TOTAL_SEATS) printf("Invalid!\n");
    else if (seats[s-1] == 1) printf("Already booked!\n");
    else {
        seats[s-1] = 1;
        printf("Booked!\n");
    }
}

void cancelSeat(int seats[]) {
    int s;
    printf("Seat (1-%d): ", TOTAL_SEATS);
    scanf("%d", &s);
    if (s < 1 || s > TOTAL_SEATS) printf("Invalid!\n");
    else if (seats[s-1] == 0) printf("Not booked!\n");
    else {
        seats[s-1] = 0;
        printf("Cancelled!\n");
    }
}