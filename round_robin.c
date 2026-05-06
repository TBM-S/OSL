#include <stdio.h>

int main() {
    int n, quantum, time = 0, complete = 0;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: "); scanf("%d", &n);
    int bt[n], rem[n], wt[n];

    printf("Enter Burst Times:\n");
    for (int i = 0; i < n; i++) { printf("P%d: ", i+1); scanf("%d", &bt[i]); rem[i] = bt[i]; }
    printf("Enter Time Quantum: "); scanf("%d", &quantum);

    while (complete < n)
        for (int i = 0; i < n; i++)
            if (rem[i] > 0) {
                int t = rem[i] > quantum ? quantum : rem[i];
                time += t; rem[i] -= t;
                if (rem[i] == 0) { wt[i] = time - bt[i]; complete++; }
            }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        int tat = wt[i] + bt[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat);
        avg_wt += wt[i]; avg_tat += tat;
    }
    printf("Avg WT: %.2f | Avg TAT: %.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}
