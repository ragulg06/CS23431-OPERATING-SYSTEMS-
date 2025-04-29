#include <stdio.h>

int main(){
    int n, i;
    int bt[10], wt[10], tat[10];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process: \n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    wt[0] = 0;
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
    for(i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTrunaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f", avg_tat/n);
    return 0;
}