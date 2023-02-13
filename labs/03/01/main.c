#include <stdio.h>
#include <stdlib.h>

const char *months[12] = {
    "Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug",
    "Sep", "Oct", "Nov", "Dec"
};

/**
 * Function: readData
 * ------------------
 * Reads the data from the file and returns a pointer to the array of floats.
 * Note: This function allocates memory for the array of floats.
 *
 * filename: the name of the file to read from
 *
 * returns: pointer to the array of Data structs
 **/
float *readData(const char *filename) {
    const int months = 12;
    float *data = (float*)malloc(sizeof(float) * months);

    FILE *fp = fopen(filename, "r+");
    if(fp == NULL){
        printf("Please check your file again!\n");
    }

    for (int i = 0; i < months; i++) {
        fscanf(fp, "%f", &data[i]);
    }

    return data;
}

/**
 * Function: printMonthlySales
 * ---------------------------
 * Prints the monthly sales report.
 *
 * sales: array of sales (floats) for each month
 *
 * returns: void
*/
void printMonthlySales(float *sales) {
    for (int i = 0; i < 12; i++) {
        printf("%s : $%.2f\n", months[i], sales[i]);
    }
}

/**
  * Function: calcMinMaxAverage
  * ---------------------------
  * Calculates the minimum, maximum, and average sales for the year.
  *
  * sales: array of sales (floats) for each month
  *
  * returns: void
  **/
void printMinMaxAverage(float *sales) {
    float sum = 0;
    float avg = 0;
    int minMonth = 0;
    int maxMonth = 0;

    float min = sales[0];
    float max = sales[0];

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) {
            minMonth = i;
            min = sales[i];
        }

        if (sales[i] > max) {
            maxMonth = i;
            max = sales[i];
        }

        sum += sales[i];
    }

    avg = sum / 12;

    printf("Min: $%.2f (%s)\n", min, months[minMonth]);
    printf("Max: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Avg: $%.2f\n", avg);
}

/**
  * Function: calcSixMonthMovingAverage
  * ----------------------------------
  * Calculates the six month moving average for each month.
  * Note: This function assumes that the sales array is already sorted in ascending order.
  *
  * sales: array of sales (floats) for each month.
  * movingAvg: pointer to the array of six month moving averages.
  *
  * returns: void
  **/
void printSixMonthMovingAverage(float *sales) {
    float movingAvg[7];

    for (int i = 0; i <= 6; i++) {
        float sum = 0;

        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }

        movingAvg[i] = sum / 6;
    }

    for (int i = 0; i <= 6; i++) {
        printf("%s - %s : $%.2f\n", months[i], months[i + 5], movingAvg[i]);
    }
}

/**
  * Function: printSortedData
  * -------------------------
  * Prints the sales report in descending order.
  *
  * sales: array of sales (floats) for each month
  *
  * returns: void
  **/
void printSortedData(float *sales) {
    int indices[12];

    for (int i = 0; i < 12; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales[indices[i]] < sales[indices[j]]) {
                float temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        printf("%s : $%.2f\n", months[indices[i]], sales[indices[i]]);
    }
}

int main() {
    float *sales = readData("sales.txt");

    printf("--------------------\n");
    printf("Monthly Sales Report\n");
    printf("--------------------\n");
    printMonthlySales(sales);

    printf("--------------------\n");
    printf("Min, Max, Avg. Sales\n");
    printf("--------------------\n");
    printMinMaxAverage(sales);

    printf("--------------------\n");
    printf("6-Month Rolling Avg.\n");
    printf("--------------------\n");
    printSixMonthMovingAverage(sales);

    printf("--------------------\n");
    printf("Sales Report (Desc.)\n");
    printf("--------------------\n");
    printSortedData(sales);

    printf("--------------------\n");
    return 0;
}

