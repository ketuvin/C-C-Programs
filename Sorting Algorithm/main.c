#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Created by: KEVIN G. FUENTES

int main()
{

    char file[255];

    int choice;

    do {
    printf("\nInput the name of the file:\n");
    scanf("%s", file);

    FILE *myFile;
    myFile = fopen(file, "r");

    //read file into array
    int arr[15000], i;
    int n = sizeof(arr)/sizeof(arr[0]);

    if (myFile == NULL)
    {
        printf("\nError Reading File\n");
        exit (0);
    }
    for (i = 0; i < n; i++)
    {
        fscanf(myFile, "%d,", &arr[i] );

    }

    fclose(myFile);

    printf("\nWhat do you want to do?\n");
    printf("\n1. Bubble Sort");
    printf("\n2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("\nChoice: ");
    scanf("%d",&choice);

    clock_t tic = clock();

    switch(choice) {

    case 1:

        printf("\nBUBBLE SORT METHOD\n");
        bubbleSort(arr,n);
        printArray(arr,n);
        break;

    case 2:
        printf("\n\nINSERTION SORT METHOD\n");
        insertionSort(arr,n);
        printArray(arr,n);
        break;

    case 3:
        printf("\n\nSELECTION SORT METHOD\n");
        selectionSort(arr,n);
        printArray(arr,n);
        break;

    case 4:
        printf("\n\nMERGE SORT METHOD\n");
        mergeSort(arr, 0, n-1);
        printArray(arr,n);
        break;

    case 5:
        printf("\n\nQUICK SORT METHOD\n");
        quickSort(arr, 0, n-1);
        printArray(arr,n);
        break;

    case 6:
        printf("\n\nHEAP SORT METHOD\n");
        heapSort(arr,n);
        printArray(arr,n);
        break;
    }

    clock_t toc = clock();

    printf("\n\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    getch();
    printf("\nWant to try again?\n");
    printf("\n1 - YES\n");
    printf("0 - NO\n");
    printf("\nCHOICE: ");
    scanf("%d",&choice);
    } while(choice!=0);
}

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void swap(int *xpointer, int *ypointer)
{
    int temp = *xpointer;
    *xpointer = *ypointer;
    *ypointer = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    int j;
    for (j = low; j <= high-1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapSort(int a[], int n)
{
    int i,t;

    heapify(a,n);

    for(i = n-1; i > 0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        adjust(a,i);
    }
}


void heapify(int a[], int n)
{
    int k,i,j,item;

    for(k = 1; k < n; k++)
    {
        item = a[k];
        i = k;
        j = (i-1)/2;

        while((i>0)&&(item>a[j]))
        {
            a[i] = a[j];
            i = j;
            j = (i-1)/2;
        }
        a[i] = item;
    }
}

void adjust(int a[], int n)
{
    int i, j, item;

    j = 0;
    item = a[j];
    i = 2*j+1;

    while(i<=n-1)
    {
        if(i+1 <= n-1)
            if(a[i] <a[i+1])
                i++;
        if(item<a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2*j+1;
        }
        else
            break;
    }
    a[j] = item;
}
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

