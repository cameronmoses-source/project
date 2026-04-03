#include <stdio.h>

// function parking lot:

void swap(double *a, double *b);  //function that swaps two values

void bubblesort(double arr[], int size);  // function that sorts an array from lowest to highest 

double findMedian(double arr[], int start, int end, int size);   // finds the median of an array

void findQuartiles(double arr[], int size,double *Q0, double *Q1, double *Q2, double *Q3, double *Q4); // Calculates the quartiles

void runQ4(int out);

void runQ5();

void findoutliers(double arr[], int size, double Q1, double Q3);

void daytodate(int day);

double findmean(double arr[], int size);

double summerlovin(double arr[]);

//-------------------------------------------------------------------------------------------//


int main(void) {
    
    //------------------------- opens file and creates arrary------------------------------//
    
    double arr[15000];  // creates arrary
    
    double Q0,Q1,Q2,Q3,Q4;//creates doubles for the quartiles 
    
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
    
    size = i; // counts the amount of times the loop runs and gives us the amount of days in the file
    
    //printf("%f", summerlovin(arr)); //finds the summer average i love summer 
  
    //--------------------------swaps two different values (used for sorting)-------------------//
    
    //printf("%d\n", size); used to see the size of the file
    
    //int a = size, b = size - 1; // position of the two positions in the array that need to be 
    //swapped (tentatively size and size - 1 for ease of use... can be changed to anything)
    
    //printf("%f\n%f\n", arr[a], arr[b]); checks values of array before swap
    
    //swap(&arr[a], &arr[b]);
    
    // printf("%f\n%f", arr[a], arr[b]); checks values after swap 
    
    //-----------------------------------bubble sorting----------------------------------//
    
    //bubblesort(arr, size);
    
    //for(i = 0; i < size; i++) printf("%f\n", arr[i]); //prints out the array  
 
    //------------------------------find median--------------------------//
    
    //int start = 0, end = size; // start and end can be changed to any number to check median for a different range 
    //double median; // used to store median 
    //median = findMedian(arr, start, end, size); // uses the function to find the median 
    
    //--------------------------------Finding the mean----------------------//
    //double mean1 = findmean(arr, size);
    
    //-------------------------------------//
    
    /*
    //findQuartiles(arr, size, &Q0, &Q1, &Q2, &Q3, &Q4);
    //printf("Q0=%lf, Q1=%lf, Q2=%lf, Q3=%lf, Q4=%lf\n",Q0,Q1,Q2,Q3,Q4);
    //double IQR,lowerbound,upperbound;
    //IQR=Q3-Q1;
    //lowerbound = Q1 - 1.5 * IQR;
    upperbound = Q3+1.5*IQR; 
    
    printf("L: %f, U: %f", lowerbound, upperbound);
    
    int c,year;
    
    
    for(c=0; c<size; c++){
        arr[c];
        if(arr[c]<lowerbound || arr[c]>upperbound){
            //printf("Outlier:%.2ffound at month:%d\n",arr[c], c);
        }//end of if 
        
    }//end of for 
    
    */
   
    
    int question = 1;
    int out;
    
    while(question > 0 && question < 7){
        printf("What question would you like to veiw? (please input a number from 1 - 6) type anything else to end:  ");
        
        scanf("%d", &question);
        if (question == 1){
            printf("\nQUESTION 1: The helper functions can be seen at top of the code, and below the main function");
        }
        if (question == 2){
            out = 0;
            runQ4(out);
        }
        if (question == 3){
            out = 1;
            runQ4(out);
            
        }
        if (question == 4){
            out = 0;
            runQ4(out);
        }
        if (question == 5){
            
            runQ5();
            
        }
        if (question == 6){
            printf("Average summer temp:  %f\n", summerlovin(arr));
            
            
        }
        
    }

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
    
    int count = end - start;
    
    int mid = start + count / 2.0;
    
    if (count % 2 == 0) return(arr[mid - 1] + arr[mid]) / 2.0;
    else return(arr[mid]);
    
    
}

double findmean(double arr[], int size){
    
    double sum = 0;
    
    for(int i = 0; i < size; i++) sum += arr[i];
    
    return(sum/size);
    
}

double summerlovin(double arr[]){
    
    int lake;
    FILE *file = NULL;
    
    printf("what file do you want to see?\nSUPERIOR: 1\nERIE: 2\nHURON: 3\nST.CLAIR:4\nONTARIO: 5\nMICHIGAN: 6\n");
    scanf("%d", &lake);
    while(lake < 1 || lake > 6){
       printf("please enter a proper number:  ");
       scanf("%d", &lake);
    }
    
    
    char *filename[] = { "Superior.txt", "Erie.txt", "Huron.txt", "St.Clair.txt", "Ontario.txt", "Michigan.txt"};
    
    file = fopen(filename[lake - 1], "r");
    

    if (file == NULL) {
        printf("Error opening file\n");
    }
    
    int i = 0, size; // i is the counter variable whilst size tells the size of the file used for further claculations
    
    while(fscanf(file, "%lf", &arr[i]) == 1){ 
        
        //printf("%d   ", i); these two lines can be used to see array
        //printf("%f\n", arr[i]);
        i++; 
    }
    fclose(file);
    
    double sum = 0; 
    int count = 0;
    
    for( int i = 170 * 30 - 1; i < 265 * 30 - 1; i++) {
        
        sum += arr[i];
        count += 1;
    }
    
    return(sum/(double)count);
}


void findQuartiles(double arr[], int size, double*Q0,double *Q1, double *Q2, double *Q3, double*Q4){    
    bubblesort(arr,size);//calls the function to sort the array from least to greatest
 
    int posQ2, count = 0, x = 0;
 
    *Q0=arr[0];//lowest element of the data set 
 
    *Q4=arr[size-1];//highest element of the data set, gets shifted one to the right since it indexes at zero
 
    *Q2=findMedian(arr,0,size,size);
 
    while(x != 1){
        if(arr[count] == *Q2) x = 1;
        else count++;
        
        if (count == 30000) break;
    }
    
    *Q1 = findMedian(arr, 0, x, size);
    *Q3 = findMedian(arr, x, size, size);
    
}



void runQ4(int out) {
    int lake;
    FILE *file = NULL;
    
    printf("what file do you want to see?\nSUPERIOR: 1\nERIE: 2\nHURON: 3\nST.CLAIR:4\nONTARIO: 5\nMICHIGAN: 6\n");
    scanf("%d", &lake);
    while(lake < 1 || lake > 6){
       printf("please enter a proper number:  ");
       scanf("%d", &lake);
    }
    
    
    char *filename[] = { "Superior.txt", "Erie.txt", "Huron.txt", "St.Clair.txt", "Ontario.txt", "Michigan.txt"};
    
    file = fopen(filename[lake - 1], "r");
    

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    double temps[30];
    double Q0, Q1, Q2, Q3, Q4;
    int day = 1;

    while (day <= 365) {
        for (int i = 0; i < 30; i++) {
            if (fscanf(file, "%lf", &temps[i]) != 1) {
                fclose(file);
                return;
            }
        }
        
        double copy[30];
        
        for (int i = 0; i < 30; i++) copy[i] = temps[i];
        
        findQuartiles(copy, 30, &Q0, &Q1, &Q2, &Q3, &Q4);
        if (out = 0){
        printf("\nDay %d:\n", day);
        
        printf("Q1 = %.2f, Q2 = %.2f, Q3 = %.2f\n", Q1, Q2, Q3);
        }
        
        if (out = 1) findoutliers(copy, 30, Q1, Q3);
        
        day++;
    }

    fclose(file);
}
// Q5 function
void runQ5() {

    int lake;
    FILE *file = NULL;
    
    printf("what file do you want to see?\nSUPERIOR: 1\nERIE: 2\nHURON: 3\nST.CLAIR:4\nONTARIO: 5\nMICHIGAN: 6\n");
    scanf("%d", &lake);
    while(lake < 1 || lake > 6){
       printf("please enter a proper number:  ");
       scanf("%d", &lake);
    }
    
    
    char *filename[] = { "Superior.txt", "Erie.txt", "Huron.txt", "St.Clair.txt", "Ontario.txt", "Michigan.txt"};
    
    file = fopen(filename[lake - 1], "r");
    

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

void findoutliers(double arr[], int size, double Q1, double Q3) {

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





