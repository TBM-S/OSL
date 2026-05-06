#include <stdio.h>

#define SWAP(a,b) { int t=a; a=b; b=t; }

int main() {
    int n;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: "); scanf("%d", &n);
    int pid[n], bt[n], wt[n];

    printf("Enter Burst Times:\n");
    for (int i = 0; i < n; i++) { pid[i] = i+1; printf("P%d: ", i+1); scanf("%d", &bt[i]); }

    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (bt[i] > bt[j]) { SWAP(bt[i], bt[j]); SWAP(pid[i], pid[j]); }

    wt[0] = 0;
    for (int i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        int tat = wt[i] + bt[i];
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat);
        avg_wt += wt[i]; avg_tat += tat;
    }
    printf("Avg WT: %.2f | Avg TAT: %.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}
