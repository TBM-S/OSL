#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, head, total = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    int req[n], visited[n];
    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++) { scanf("%d", &req[i]); visited[i] = 0; }
    printf("Enter initial head position: "); scanf("%d", &head);

    printf("\n===== SSTF Disk Scheduling =====\n");
    for (int i = 0; i < n; i++) {
        int min = INT_MAX, idx = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int d = abs(req[j] - head);
                if (d < min) { min = d; idx = j; }
            }
        }
        visited[idx] = 1; total += min;
        printf("Move %d -> %d (Distance: %d)\n", head, req[idx], min);
        head = req[idx];
    }
    printf("Total Seek: %d | Avg: %.2f\n", total, (float)total / n);
    return 0;
}
