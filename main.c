#include <stdio.h>

// function parking lot:

void swap(double *a, double *b);  //function that swaps two values

void bubblesort(double arr[], int size);  // function that sorts an array from lowest to highest 

double findMedian(double arr[], int start, int end, int size);   // finds the median of an array

void findQuartiles(double arr[], int size,double *Q0, double *Q1, double *Q2, double *Q3, double *Q4); // Calculates the quartiles

void runQ4();
void runQ5();
void findoutliers(double arr[], int size, double Q1, double Q3);
void daytodate(int day);


int main(void) {
    
    //------------------------- opens file and creates arrary------------------------------//
    
    double arr[15000];  // creates arrary
    
    double Q0,Q1,Q2,Q3,Q4;//creates doubles for the quartiles 
    
    FILE *file;  // creates pointer
    
    file = fopen("Erie.txt", "r");  // creates the position for the file
//Call for Q4 and Q5
    runQ4();
    runQ5();
    
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
    
    printf("\n mean: %f\n", mean1);
    
    findQuartiles(arr, size, &Q0, &Q1, &Q2, &Q3, &Q4);
    printf("Q0=%lf, Q1=%lf, Q2=%lf, Q3=%lf, Q4=%lf\n",Q0,Q1,Q2,Q3,Q4);

}//end of main function 



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


void findQuartiles(double arr[], int size, double*Q0,double *Q1, double *Q2, double *Q3, double*Q4){    
 bubblesort(arr,size);//calls the function to sort the array from least to greatest
 *Q0=arr[0];//lowest element of the data set 
 *Q4=arr[size-1];//highest element of the data set, gets shifted one to the right since it indexes at zero
 *Q2=findMedian(arr,0,size,size);//calls the function to find the median starting from 0 to the end and assigns that to Q2
 int middle=size/2;// finds the midpoint of the data set 
 if(size%2==0){//if its even
   *Q1=findMedian(arr,0,middle,size);//[1,2|Q1 ,Q3|3,4] the median isn't included so its exluded 
   *Q3=findMedian(arr,middle,size,size);
 }//end of if 
 else{
     *Q1=findMedian(arr,0,middle,size);
     *Q3=findMedian(arr,middle+1,size,size);//skips the median(Q2) value 
 }//end of else 
 //findmean(arr,size);//finds mean of all data in the array
 
}//end of quartiles
    // part 2, finding the quartiles for lake superior 
/*double arr2[20000];
int c=0;//counter variable 
FILE*y=fopen("Superior.txt","r");
while(fscanf(y," %lf",&arr2[c])==1){
   // printf("entered while loop\n");
    printf("%d:%lf\n",c,arr2[c]);//checking to see if values are stored in the array
    c++;
}// end of while loop
fclose(y);*/
// Q4 function
void runQ4() {

    FILE *file = fopen("Erie.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    int day;
    double temps[30];
    double Q0, Q1, Q2, Q3, Q4;

    printf("\n--- Q4 RESULTS ---\n");

    while (fscanf(file, "%d", &day) == 1) {

        for (int i = 0; i < 30; i++) {
            fscanf(file, "%lf", &temps[i]);
        }

        double copy[30];
        for (int i = 0; i < 30; i++) copy[i] = temps[i];

        findQuartiles(copy, 30, &Q0, &Q1, &Q2, &Q3, &Q4);

        printf("Day %d: Q1=%.2f Q2=%.2f Q3=%.2f\n", day, Q1, Q2, Q3);

        findoutliers(copy, 30, Q1, Q3);
    }

    fclose(file);
}
// Q5 function
void runQ5() {

    FILE *file = fopen("Erie.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    double dailyavg[365];
    int index = 0;
    int day;
    double temps[30];

    while (fscanf(file, "%d", &day) == 1 && index < 365) {

        for (int i = 0; i < 30; i++) {
            fscanf(file, "%lf", &temps[i]);
        }

        dailyavg[index] = findmean(temps, 30);
        index++;
    }

    fclose(file);

    double min = dailyavg[0];
    double max = dailyavg[0];

    int coldday = 1;
    int hotday = 1;

    for (int i = 1; i < index; i++) {

        if (dailyavg[i] < min) {
            min = dailyavg[i];
            coldday = i + 1;
        }

        if (dailyavg[i] > max) {
            max = dailyavg[i];
            hotday = i + 1;
        }
    }

    printf("\n--- Q5 RESULTS ---\n");

    printf("Coldest Day: %d (%.2f°C)\n", coldday, min);
    daytodate(coldday);

    printf("Warmest Day: %d (%.2f°C)\n", hotday, max);
    daytodate(hotday);
}

void findOutliers(double arr[], int size, double Q1, double Q3) {

    double IQR = Q3 - Q1;
    double lower = Q1 - 1.5 * IQR;
    double upper = Q3 + 1.5 * IQR;

    for (int i = 0; i < size; i++) {
        if (arr[i] < lower || arr[i] > upper) {
            printf("   Outlier: %.2f\n", arr[i]);
        }
    }
}

void daytodate(int day) {

    int monthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int month = 0;

    while (day > monthdays[month]) {
        day -= monthdays[month];
        month++;
    }

    printf("Month %d Day %d\n", month + 1, day);
}
