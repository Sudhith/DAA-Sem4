#include <stdio.h>

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];
    float ratio[n];

    // input
    for(int i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d: ", i+1);
        scanf("%d %d", &profit[i], &weight[i]);

        ratio[i] = (float)profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // ---- sorting based on ratio (descending) ----
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(ratio[j] < ratio[j+1])
            {
                // swap ratio
                float temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;

                // swap profit
                int t = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = t;

                // swap weight
                t = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = t;
            }
        }
    }

    // ---- selecting items ----
    float totalProfit = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(W >= weight[i])   // take full item
        {
            totalProfit += profit[i];
            W -= weight[i];
        }
        else                 // take fraction
        {
            totalProfit += ratio[i] * W;
            break;
        }
    }

    printf("Maximum profit = %.2f", totalProfit);

    return 0;
}
