#include <stdio.h>

int main() {
    int n, m;
    printf("Enter processes and resources: ");
    scanf("%d %d", &n, &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    printf("Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Maximum Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    printf("Available Resources:\n");
    for (int i = 0; i < m; i++) scanf("%d", &avail[i]);

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) printf("%d ", need[i][j]);
        printf("\n");
    }

    int finish[n], safeSeq[n], work[m], count = 0;
    for (int i = 0; i < n; i++) finish[i] = 0;
    for (int i = 0; i < m; i++) work[i] = avail[i];

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i]) continue;
            int j;
            for (j = 0; j < m; j++)
                if (need[i][j] > work[j]) break;
            if (j == m) {
                for (int k = 0; k < m; k++) work[k] += alloc[i][k];
                safeSeq[count++] = i;
                finish[i] = found = 1;
            }
        }
        if (!found) {
            printf("\nSystem is NOT in SAFE state! Deadlock may occur.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state!\nSafe sequence: ");
    for (int i = 0; i < n; i++) printf("P%d%s", safeSeq[i], i < n-1 ? " -> " : "\n");
    return 0;
}
