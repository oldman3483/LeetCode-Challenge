#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    for (int i=1;i<pricesSize;i++)
    {
        if (prices[i-1]<prices[i])
            profit += prices[i] - prices[i-1];

    }
    return profit;
}

int main(void)
{
    int out;
    int prices[6] = {7,1,5,3,6,4};
    out = maxProfit(prices, 6);
    printf("profit = %d \n", out);
}