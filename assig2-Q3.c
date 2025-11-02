#include <stdio.h>

#define ROWS 3
#define COLS 3

#define POWER 1 
#define OVERLOAD 2
#define MAINT 4   

void updateSector(int grid[ROWS][COLS], int r, int c, int flag, int set) {
    if (set)
        grid[r][c] |= flag;   // turn ON bit
    else
        grid[r][c] &= ~flag;  // turn OFF bit
}

void querySector(int grid[ROWS][COLS], int r, int c) {
    int val = grid[r][c];
    printf("\nSector (%d,%d) Status:\n", r, c);
    printf("Power: %s\n", (val & POWER) ? "ON" : "OFF");
    printf("Overload: %s\n", (val & OVERLOAD) ? "YES" : "NO");
    printf("Maintenance: %s\n", (val & MAINT) ? "REQUIRED" : "NO");
}

void diagnostic(int grid[ROWS][COLS]) {
    int over = 0, maint = 0;
    int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] & OVERLOAD) over++;
            if (grid[i][j] & MAINT) maint++;
        }
    }
    printf("\nSystem Diagnostic Report:\n");
    printf("Overloaded sectors: %d\n", over);
    printf("Maintenance required: %d\n", maint);
}

int main() {
    int grid[ROWS][COLS] = {0};
    int choice, r, c, flag, set;

    while (1) {
        printf("\n--- IESCO Power Grid ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter row and column (0-%d): ", ROWS - 1);
            scanf("%d%d", &r, &c);
            printf("1.Power  2.Overload  3.Maintenance\nChoose flag: ");
            scanf("%d", &flag);
            if (flag == 1) flag = POWER;
            else if (flag == 2) flag = OVERLOAD;
            else flag = MAINT;
            printf("Set(1) or Clear(0): ");
            scanf("%d", &set);
            updateSector(grid, r, c, flag, set);
            printf("Sector updated!\n");
            break;

        case 2:
            printf("Enter row and column (0-%d): ", ROWS - 1);
            scanf("%d%d", &r, &c);
            querySector(grid, r, c);
            break;

        case 3:
            diagnostic(grid);
            break;

        case 0:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

