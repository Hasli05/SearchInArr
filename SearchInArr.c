#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int recurseCounter = 0;


int consoleIndexInput ()
{
    printf("\nВведіть число індекс якого потрібно дізнатись: ");
    int searchiningNumber;
    scanf("%d", &searchiningNumber);

    return searchiningNumber;
}


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void selectionSort(int arr[], int sizeArr)
{
    int min_idx;

    for (int i = 0; i < sizeArr - 1; i++) {

        min_idx = i;

        for (int j = i + 1; j < sizeArr; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


int indexOfSerchiningNumInArrRecursion(int arr[], int left, int right,int center, int searchiningNumber)
{
    recurseCounter++;
    
    center = (left + right) / 2;
    
    if (arr[center] > searchiningNumber)
    {
        right = center - 1;
        indexOfSerchiningNumInArrRecursion(arr, left, right, center, searchiningNumber);
        
    }
    else if (arr[center] < searchiningNumber)
    {
        left = center + 1;
        indexOfSerchiningNumInArrRecursion(arr, left, right, center, searchiningNumber);
    }
    else
    {
         return center;
    }
}


int indexOfSerchiningNumInArrCycle(int arr[], int arrSize, int serchiningNumber, int* counter)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (serchiningNumber == arr[i])
        {
            return i;
        }
        *counter += 1;
    }
    printf("Помилка, такого числа немає в масиві\n");
}


void randomFillingArr(int arr[], int arrSize, int spreatInRandom)
{
    // spreatInRandom - область рандомайзера, повинно бути >= розміру масива

    _Bool inArray = 0;

    for (int i = 0; i < arrSize; )
    {
        inArray = 0;

        int tempNum = rand() % spreatInRandom;

        for (int j = 0; j < arrSize; j++)
        {
            if (arr[j] == tempNum)
            {
                inArray = 1;
            }
        }
        if (inArray == 0)
        {
            arr[i] = tempNum;
            i++;
        }
    }
}


void printArr(int arr[], int sizeArr)
{
    for (int i = 0; i < sizeArr; ++i)
    {
        printf("%d  ", arr[i]);
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    srand(time(NULL));


    int arr[30];

    const int SIZE_ARRAY = sizeof(arr) / sizeof(int);

    randomFillingArr(arr, SIZE_ARRAY, 100);
    selectionSort(arr, SIZE_ARRAY);

    printArr(arr, SIZE_ARRAY);

    
    int searchiningNumber = consoleIndexInput();


    int cycleCounter = 1;
    int indexFirst = indexOfSerchiningNumInArrCycle(arr, SIZE_ARRAY, searchiningNumber, &cycleCounter);

    printf("Пошук циклом зайняв %d операцій та видав індекс %d\n", cycleCounter, indexFirst);

    
    int center = 0;
    int indexSecond = indexOfSerchiningNumInArrRecursion(arr, 0, SIZE_ARRAY, center, searchiningNumber);

    printf("Пошук рекурсією зайняв %d операцій та видав індекс %d", recurseCounter, indexSecond);
}
