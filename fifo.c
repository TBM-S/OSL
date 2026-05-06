#include <stdio.h>

int main() {
    int n, f, faults = 0, idx = 0;
    printf("Enter number of pages: "); scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: "); scanf("%d", &f);
    int frames[f];
    for (int i = 0; i < f; i++) frames[i] = -1;

    printf("\nFIFO Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int hit = 0;
        for (int j = 0; j < f; j++) if (frames[j] == pages[i]) { hit = 1; break; }
        if (!hit) { frames[idx] = pages[i]; idx = (idx+1) % f; faults++; }

        printf("Page %d -> ", pages[i]);
        for (int j = 0; j < f; j++) frames[j] != -1 ? printf("%d ", frames[j]) : printf("- ");
        printf(" (%s)\n", hit ? "Hit" : "Fault");
    }
    printf("Faults: %d | Fault Ratio: %.2f | Hit Ratio: %.2f\n",
           faults, (float)faults/n, (float)(n-faults)/n);
    return 0;
}
