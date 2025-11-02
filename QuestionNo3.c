#include <stdio.h>

#define ROWS 3
#define COLS 3

void updateSector(int grid[ROWS][COLS], int row, int col, int bit, int value) {
    if (value == 1)
        grid[row][col] |= (1 << bit);   // set bit
    else
        grid[row][col] &= ~(1 << bit);  // clear bit
}

void querySector(int grid[ROWS][COLS], int row, int col) {
    int status = grid[row][col];

    printf("\nSector (%d,%d) Status:\n", row, col);
    printf("Power: %s\n", (status & (1 << 0)) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & (1 << 1)) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (status & (1 << 2)) ? "YES" : "NO");
}

void runDiagnostic(int grid[ROWS][COLS]) {
    int overloaded = 0, maintenance = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & (1 << 1)) 
                overloaded++;
            if (grid[i][j] & (1 << 2))  
                maintenance++;
        }
    }

    printf("\nSystem Diagnostic Report:\n");
    printf("Overloaded Sectors: %d\n", overloaded);
    printf("Maintenance Required Sectors: %d\n", maintenance);
}

int main() {
    int grid[ROWS][COLS] = {0};
    int choice, row, col, bit, value;

    while (1) {
        printf("\n--- IESCO Power Grid Monitoring System ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        switch (choice) {
            case 1:
                printf("Enter sector coordinates (row col): ");
                scanf("%d %d", &row, &col);
                if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
                    printf("Invalid coordinates!\n");
                    break;
                }
                printf("Enter bit to modify (0=Power, 1=Overload, 2=Maintenance): ");
                scanf("%d", &bit);
                printf("Enter value (1=Set, 0=Clear): ");
                scanf("%d", &value);
                updateSector(grid, row, col, bit, value);
                printf("Sector updated successfully.\n");
                break;

            case 2:
                printf("Enter sector coordinates (row col): ");
                scanf("%d %d", &row, &col);
                if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
                    printf("Invalid coordinates!\n");
                    break;
                }
                querySector(grid, row, col);
                break;

            case 3:
                runDiagnostic(grid);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    printf("Exiting system. Goodbye!\n");
    return 0;
}
