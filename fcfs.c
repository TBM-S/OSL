#include <stdio.h>

int main() {
    int n;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: "); scanf("%d", &n);
    int bt[n], wt[n], tat[n];

    printf("Enter Burst Times:\n");
    for (int i = 0; i < n; i++) { printf("P%d: ", i+1); scanf("%d", &bt[i]); }

    wt[0] = 0;
    for (int i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
        avg_wt += wt[i]; avg_tat += tat[i];
    }
    printf("Avg WT: %.2f | Avg TAT: %.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}
