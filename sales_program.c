#include <stdio.h>
int x = 12;
int y = 2;

//Function to calculate average given array, start index, and end index
double average(double sales[x][y], int start, int end){
    double total;
    double average;
    int length = (end - start)+1;
    for (int i = start-1; i < end; i++){
        total += sales[i][1];
    }
    average = total/length;
    return average;
}

//Function returns month given value from the sales array
const char* month(double m){
    static char* months[] = {"January ", "February","March   ","April   ","May     ","June    ","July    ","August  ","September","October ","November","December"};
    int a = (int) m;
    return months[a];

}

//Function formats and prints the monthy sales report given input array
void monthly_report(double sales[x][y]){
    printf("%s\n%s\t\t%s\n", "Monthly Sales Report for 2022: ", "Month", "Sales");
    for(int i = 0; i < 12; i++){
        printf("%s\t%s%.02f\n", month(sales[i][2]),"$",sales[i][1]);
        
    }
    printf("\n\n");
}

//Function calulates minimum and maximum sales months and averages.It then formats and prints the sales summary
void sales_summary(double sales[x][y]){
    int min;
    int max;
    for (int i = 0; i < 12; i++){
        if (i == 0){
            min = 0;
            max = 0;
        }else{
            if(sales[i][1] < sales[min][1]){
                min = i;
            }
            if(sales[i][1] > sales[max][1]){
                max = i;
            }
        }
    }
    printf("%s\n", "Sales Summary: ");
    printf("%s\t%s%.02f\t%s\n", "Minimum sales:","$",sales[min][1],  month(sales[min][2]));
    printf("%s\t%s%.02f\t%s\n","Maximum sales:", "$",sales[max][1], month(sales[max][2]));
    double av = average(sales,1,12);
    printf("%s\t%s%.02f\n","Average sales:","$",av);
    printf("\n\n");

}

//Function formats and prints the six month moving average sales report given input array
void moving_average(double sales[x][y]){
    printf("%s\n", "Six-Month Moving Average Report");
    printf("%s\t%s%.02f\n", "January  - June     ","$",average(sales,1,6));
    printf("%s\t%s%.02f\n", "February - July     ","$",average(sales,2,7));
    printf("%s\t%s%.02f\n", "March    - August   ","$",average(sales,3,8));
    printf("%s\t%s%.02f\n", "April    - September","$",average(sales,4,8));
    printf("%s\t%s%.02f\n", "May      - October  ","$",average(sales,5,10));
    printf("%s\t%s%.02f\n", "June     - November ","$",average(sales,6,11));
    printf("%s\t%s%.02f\n", "July     - December ","$",average(sales,7,12));
    printf("\n\n");
}

//Function copies input array in to array order. It then sorts the array from highest value to lowest value and prints
void high_low(double sales[x][y]){
    printf("%s\n%s\t\t%s\n", "Sales Report (Highest to Lowest): ", "Month", "Sales");
    double order[12][2];
    for(int p =0; p <12;p++){
        order[p][1]=sales[p][1];
        order[p][2]= sales[p][2];
    }
    for (int i = 0; i< 12-1; i++){
        for (int j = 0; j < 12-i -1; j++){
            if (order[j][1] < order[j+1][1]){
                double temp_sales = order[j][1];
                order[j][1] = order[j+1][1];
                order[j+1][1] =temp_sales;
                double temp_month = order[j][2];
                order[j][2] = order[j+1][2];
                order[j+1][2] =temp_month;

            }
        }
    }
    for(int k = 0; k <12; k++){
        printf("%s\t%s%.02f\n", month(order[k][2]),"$",order[k][1]);
    }
}

//Main takes in file input from a file titled "input.txt" and calls necessary functions
int main(){
    double sales[12][2];
    FILE *input;
    input = fopen("input.txt", "r");

    for(int i = 0; i < 12; i ++){
        fscanf(input,"%lf",&sales[i][1]);
        sales[i][2] = i;
    }

    monthly_report(sales);
    sales_summary(sales);
    moving_average(sales);
    high_low(sales);

}