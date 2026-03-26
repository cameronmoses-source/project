#include <stdio.h>

// function parking lot:

void swap(double *a, double *b);  //function that swaps two values

void bubblesort(double arr[]);  // function that sorts an array from lowest to highest 

double findMedian(double arr[], int start, int end);   // finds the median of an array

void findQuartiles(double arr[], int size, double *Q1, double *Q2, double *Q3); // Calculates the quartiles 

double mean(double arr[], int size);  // computes the average of all values in the array


int main(void) {
    
    //------------------------- opens file and creates arrary------------------------------//
    
    double arr[100000];  // creates arrary
    
    FILE *file;  // creates pointer
    
    file = fopen("Erie.txt", "r");  // creates the position for the file
    
    int i = 0, size; // i is the counter variable whilst size tells the size of the file used for further claculations
    
    while(fscanf(file, "%lf", &arr[i]) == 1){ 
        
        //printf("%d   ", i); these two lines can be used to see array
        //printf("%f\n", arr[i]);
        i++; 
    }
    // reads every number into an array
    // array goes from the first day of year one all the way to the first day of year two 
    // which then goes to the second day of year one and so on...
    // the text also includes leap years so be careful of that
    
    fclose(file);
    
    size = i - 1 ; // counts the amount of times the loop runs and gives us the amount of days in the file
    
    //--------------------------swaps two different values (used for sorting)-------------------//
    
    //printf("%d\n", size); used to see the size of the file
    
    int a = size, b = size - 1; // position of the two positions in the array that need to be 
    //swapped (tentatively size and size - 1 for ease of use)
    
    //printf("%f\n%f\n", arr[a], arr[b]); checks values of array before swap
    
    swap(&arr[a], &arr[b]);
    
    // printf("%f\n%f", arr[a], arr[b]); checks values after swap 
    
    //-----------------------------------bubble sorting----------------------------------//
    
    
    
    
}



void swap(double *a, double *b){
    
    int day; //creates variable which can temporarily store the position of a while it is swapped to be 
    day = *a; // stores position of a into variable
    *a = *b;  // sets the position of a to b
    *b = day;  // sets the position of b to day which is eqaul to the position of b 
    // therefore it sets the position of b to a...
    
}


