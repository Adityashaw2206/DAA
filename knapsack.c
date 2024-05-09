#include <stdio.h>

void sortItems(int num, float weight[], float profit[], float ratio[]) {
    float temp;
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weight
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profit
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
}

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, u;
    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
        x[i] = u / weight[i];

    tp = tp + (x[i] * profit[i]);

    printf("\nThe result vector is:- ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);

    printf("\nMaximum profit is:- %f", tp);
}

int main() {
    float weight[20], profit[20], capacity;
    int num, i;
    float ratio[20];

    printf("\nEnter the no. of objects:- ");
    scanf("%d", &num);

    printf("\nEnter the wts and profits of each object:- ");
    for (i = 0; i < num; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("\nEnter the capacity of knapsack:- ");
    scanf("%f", &capacity);

    sortItems(num, weight, profit, ratio);
    knapsack(num, weight, profit, capacity);

    return 0;
}