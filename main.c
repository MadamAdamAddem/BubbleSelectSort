#include <stdio.h>
#include <stdlib.h>

//The original arrays
//Here because we have to perform both bubble and selection sort on the arrays
//So we return them to their original values w/ these.
int origArray1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
int origArray2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

int swapped1[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int swapped2[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//returns index in which needle is found
int findInArray(int* haystack, int size, int needle)
{
    for(int i=0; i<size; ++i)
    {
        if(haystack[i] == needle)
            return i;
    }

    return -1;
}

void bubbleSort(int* array, int size, int whichArray)
{
    int swapped = 0;
    for(int i=0; i<size-1; ++i)
    {
        if(array[i] > array[i+1])
        {
            swap(&array[i], &array[i+1]);

            //adds to corresponding swapped array to store how many times swapped
            if(whichArray == 1)
            {
                swapped1[findInArray(origArray1, 9, array[i])] += 1;
                swapped1[findInArray(origArray1, 9, array[i+1])] += 1;
            }
            else
            {
                swapped2[findInArray(origArray2, 9, array[i])] += 1;
                swapped2[findInArray(origArray2, 9, array[i+1])] += 1;
            }
            ++swapped;
        }
    }
    
    if(swapped == 0)
        return;
    else
        bubbleSort(array, size, whichArray);
}

void selectionSort(int* array, int size, int index, int whichArray)
{
    if(index == size-1)
        return;
    
    int min = index;
    for(int i=index; i<size; ++i)
    {
        if(array[i] < array[min])
        {
            min = i;
        }
    }

    swap(&array[min], &array[index]);
    if(whichArray == 1)
    {
        swapped1[findInArray(origArray1, 9, array[min])] += 1;
        swapped1[findInArray(origArray1, 9, array[index])] += 1;
     }
      else
        swapped2[findInArray(origArray2, 9, array[min])] += 1;
        swapped2[findInArray(origArray2, 9, array[index])] += 1;

    selectionSort(array, size, index+1, whichArray);
}

void copyArray(int* orig, int* new, int size)
{
    for(int i=0; i<size; ++i)
        new[i] = orig[i];
}

void printArray(int* array, int size)
{
    printf("\n");
    for(int i=0; i<size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int returnTotal(int* array, int size)
{
    int sum = 0;
    for(int i=0; i<size; ++i)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{

    int array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    bubbleSort(array1, 9, 1);
    selectionSort(array2, 9, 0, 2);

    printf("START OUTPUT\n\n");

    printf("Array1 Bubble Sort: \n");
    for(int i=0; i<9; ++i)
    {
        printf("\t%d: Swapped %d times\n", array1[i], swapped1[findInArray(origArray1, 9, array1[i])]);
    }
    printf("Total # of swaps: %d\n", returnTotal(swapped1, 9));

    printf("\nArray2 Selection Sort: \n");
    for(int i=0; i<9; ++i)
    {
        printf("\t%d: Swapped %d times\n", array2[i], swapped2[findInArray(origArray2, 9, array2[i])]);
    }
    printf("Total # of swaps: %d\n", returnTotal(swapped2, 9));

    //Returns arrays to their original states for next sorting
    copyArray(origArray1, array1, 9);
    copyArray(origArray2, array2, 9);
    for(int i=0; i<9; ++i)
    {
        swapped1[i] = 0;
        swapped2[i] = 0;
    }

    bubbleSort(array2, 9, 2);
    selectionSort(array1, 9, 0, 1);

    printf("\nArray1 Selection Sort: \n");
    for(int i=0; i<9; ++i)
    {
        printf("\t%d: Swapped %d times\n", array1[i], swapped1[findInArray(origArray1, 9, array1[i])]);
    }
    printf("Total # of swaps: %d\n", returnTotal(swapped1, 9));


    printf("\nArray2 Bubble Sort: \n");
    for(int i=0; i<9; ++i)
    {
        printf("\t%d: Swapped %d times\n", array2[i], swapped2[findInArray(origArray2, 9, array2[i])]);
    }
    printf("Total # of swaps: %d\n", returnTotal(swapped2, 9));

    return 0;
}






