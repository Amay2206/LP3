#include <stdio.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

void sort(struct Job a[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].profit < a[j+1].profit) {
                struct Job t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job a[n];
    for(int i=0;i<n;i++) {
        printf("ID , Deadline , Profit:");
        scanf(" %c %d %d", &a[i].id, &a[i].deadline, &a[i].profit);
    }

    sort(a,n);

    int result[n];
    for(int i=0;i<n;i++) result[i] = -1;

    for(int i=0;i<n;i++) {
        for(int j=a[i].deadline-1;j>=0;j--) {
            if(result[j] == -1) {
                result[j] = i;
                break;
            }
        }
    }

    printf("Selected jobs: ");
    for(int i=0;i<n;i++)
        if(result[i] != -1)
            printf("%c ", a[result[i]].id);

    return 0;
}
