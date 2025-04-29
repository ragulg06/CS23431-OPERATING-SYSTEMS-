#include <stdio.h>

int main() {
    int n, i, j;
    int burst[20], p[20];  // burst time and process number
    int waiting[20], turnaround[20];
    int temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
        p[i] = i;  // process numbers: 0, 1, 2, 3...
    }

    // Sort processes by burst time (Simple Bubble Sort)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(burst[i] > burst[j]) {
                // swap burst times
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                // swap process numbers to maintain correct process order
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    waiting[0] = 0;  // first process waiting time is 0
    for(i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    for(i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i]+1, burst[i], waiting[i], turnaround[i]);
        avg_wt += waiting[i];
        avg_tat += turnaround[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}