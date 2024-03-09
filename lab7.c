#include <stdio.h>
#include <stdbool.h>


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n, int count[]){

    int i, j;
     
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                swap(&arr[j], &arr[j + 1]);
                count[arr[j]]++;
                count[arr[j + 1]]++;

            
            }  
        }   
    }
}


void selectionSort(int arr[], int n, int count[]) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[i], &arr[min_idx]);

        if (i != min_idx) {
            count[arr[i]]++;
            count[arr[min_idx]]++;

        }

    }
}


int main(){

    // initialize the arrays
    int array1[9]= {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[9]= {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int count1[100] = {0};
    int count2[100] = {0};
   



    // call the bubble sort for each array
    bubbleSort(array1, 9, count1);
    bubbleSort(array2, 9, count2);

    // print each count for array 1 and add up all the counts
    printf("array1 bubble sort: \n");
    int total1 = 0;
    for(int i = 0; i < 9; i++){
        printf("%d: %d\n", array1[i], count1[array1[i]]) ;
        total1 += count1[array1[i]] ;
    }

    // divide all the counts by 2 for the total
    printf("Total swaps: %d\n", total1 / 2);

 
    // print each count for array 2 and add up all the counts
    printf("\narray2 bubble sort: \n");
    int total2 = 0;
    for(int i = 0; i < 9; i++){
        printf("%d: %d\n", array2[i], count2[array2[i]]) ;
        total2 += count2[array2[i]] ;
    }

    // divide all the counts by 2 for the total
    printf("Total swaps: %d\n", total2 / 2);

   
    int array3[9]= {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[9]= {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int count3[100] = {0};
    int count4[100] = {0};

    // call the bubble sort for each array
    selectionSort(array3, 9, count3);
    selectionSort(array4, 9, count4);



    printf("\narray1 selection sort: \n");
    int total3 = 0;
    for(int i = 0; i < 9; i++){
        printf("%d: %d\n", array3[i], count3[array3[i]]) ;
        total3 += count3[array3[i]] ;
    }

    printf("Total swaps: %d\n", total3 / 2);



    printf("\narray2 selection sort: \n");
    int total4 = 0;
    for(int i = 0; i < 9; i++){
        printf("%d: %d\n", array4[i], count4[array4[i]]) ;
        total4 += count4[array4[i]] ;
    }

    printf("Total swaps: %d\n", total4 / 2);

    return 0;
    
}
