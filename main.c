#include <stdio.h>

// function parking lot:

void swap(double *a, double *b);  //function that swaps two values

void bubblesort(double arr[], int size);  // function that sorts an array from lowest to highest 

double findMedian(double arr[], int start, int end, int size);   // finds the median of an array

void findQuartiles(double arr[], int size, double *Q1, double *Q2, double *Q3); // Calculates the quartiles 

double findmean(double arr[], int size);  // computes the average of all values in the array


int main(void) {
    
    //------------------------- opens file and creates arrary------------------------------//
    
    double arr[15000];  // creates arrary
    
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
    
    //int a = size, b = size - 1; // position of the two positions in the array that need to be 
    //swapped (tentatively size and size - 1 for ease of use... can be changed to anything)
    
    //printf("%f\n%f\n", arr[a], arr[b]); checks values of array before swap
    
    //swap(&arr[a], &arr[b]);
    
    // printf("%f\n%f", arr[a], arr[b]); checks values after swap 
    
    //-----------------------------------bubble sorting----------------------------------//
    
    bubblesort(arr, size);
    
    for(i = 0; i < size; i++) printf("%f\n", arr[i]); //prints out the array  
 
    //------------------------------find median--------------------------//
    
    int start = 0, end = size; // start and end can be changed to any number to check median for a different range 
    double median; // used to store median 
    
    median = findMedian(arr, start, end, size); // uses the function to find the median 
    
    //--------------------------------Finding the mean----------------------//
    double mean1 = findmean(arr, size);
    
    printf("\n mean: %f", mean1);
    
}



void swap(double *a, double *b){
    
    double day; //creates variable which can temporarily store the position of a while it is swapped to be 
    day = *a; // stores position of a into variable
    *a = *b;  // sets the position of a to b
    *b = day;  // sets the position of b to day which is eqaul to the position of b 
    // therefore it sets the position of b to a...
    
}

void bubblesort(double arr[], int size){
  
       int scount = 1; // scount is the amount of times the array swaps in a certain amount of time 
    // needs to start at one to initalize the loop
    
    while (scount > 0){ // loop ends when a full run through of the list has gone thorugh without any swaps
        
        scount = 0; // sets scount to 0 because no swaps have been performed yet
        
        for(int i = 0; i < size - 1; i++){ // runs loop to check each pair of the array 
            
            if (arr[i] > arr[i + 1]) { // if the first pair of the array is larger then the second pair they swap
                
                //printf("%f\n%f\n", arr[i], arr[i+1]); checks values before swap
                swap(&arr[i], &arr[i + 1]); // swaps the two values 
                //printf("%f\n%f\n", arr[i], arr[i+1]); checks values after swap 
                scount += 1; // increases the swap count since two values have been swapped
            }
        }
    }
}

double findMedian(double arr[], int start, int end, int size){
    
    double medsize, even, median; // medsize is the size of median data, even is used to check if the amount of values are even
    
    medsize = (end - start) / 2;
    
    if ((end - start) % 2 == 0) median = (arr[(int)medsize] + arr[(int)(medsize + 1)])/2; // checks if there is an even number of values in the array
    //then since it is even it adds the two median values and divides them by two 
    
    else median = arr[(int)(medsize)]; // since it isn't even it's odd, it just finds the value from at the median position
    
    // all of this only works because the list is in ordered form...
    return(median);
    
}

double findmean(double arr[], int size){
    
    double sum = 0;
    
    for(int i = 0; i < size; i++) sum += arr[i];
    
    return(sum/size);
    
}


    
    
}


