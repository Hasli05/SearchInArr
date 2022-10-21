#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int recurseCounter = 0;


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


int indexOfSerchiningNumInArrBinarRecursion(int arr[], int left, int right,int center, int searchiningNumber)
{
    // left - початок області роботи, right - кінець області роботи
    recurseCounter++;
    
    center = (left + right) / 2;
    
    if (arr[center] > searchiningNumber)
    {
        right = center - 1;
        indexOfSerchiningNumInArrBinarRecursion(arr, left, right, center, searchiningNumber);
        
    }
    else if (arr[center] < searchiningNumber)
    {
        left = center + 1;
        indexOfSerchiningNumInArrBinarRecursion(arr, left, right, center, searchiningNumber);
    }
    else
    {
         return center;
    }
}
int indexOfSerchiningNumInArrLinearCycle(int arr[], int arrSize, int searchiningNumber, int* counter)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (searchiningNumber == arr[i])
        {
            return i;
        }
        *counter += 1;
    }
    printf("Помилка, такого числа немає в масиві\n");
}
int indexOfSerchiningNumInArrBinarCycle(int arr[], int left, int right, int center, int searchiningNumber, int *counter)
{
    // left - початок області роботи, right - кінець області роботи
    while (1)
    {
        
        center = (left + right) / 2;

        if (arr[center] > searchiningNumber)
        {
            right = center - 1;
        }
        else if (arr[center] < searchiningNumber)
        {
            left = center + 1;
        }
        else
        {
            return center;
        }
        *counter += 1;
    }
}

void infoOfBinarRecurtionMethod(int arr [], int sizeArr, int searchiningNumber)
{
    int center = 0;
    int index = indexOfSerchiningNumInArrBinarRecursion(arr, 0, sizeArr, center, searchiningNumber);

    printf("Пошук рекурсією зайняв %d операцій та видав індекс %d", recurseCounter, index);
}
void infoOfLinearCycleMethod(int arr[], int sizeArr, int searchiningNumber)
{
    int linearCycleCounter = 1;
    int index = indexOfSerchiningNumInArrLinearCycle(arr, sizeArr, searchiningNumber, &linearCycleCounter);

    printf("Пошук лінійним циклом зайняв %d операцій та видав індекс %d\n", linearCycleCounter, index);
}
void infoOfBinarCycleMethod(int arr[], int sizeArr, int searchiningNumber)
{
    int center = 0;
    int BinarCycleCounter = 1;
    int index = indexOfSerchiningNumInArrBinarCycle(arr, 0, sizeArr, center, searchiningNumber, &BinarCycleCounter);

    printf("\nПошук бінарним циклом зайняв %d операцій та видав індекс %d", BinarCycleCounter, index);
}


int consoleIndexInput ()
{
    printf("\nВведіть число індекс якого потрібно дізнатись: ");
    int searchiningNumber;
    scanf("%d", &searchiningNumber);

    return searchiningNumber;
}
void printArr(int arr[], int sizeArr)
{
    for (int i = 0; i < sizeArr; ++i)
    {
        printf("%d  ", arr[i]);
    }
}


void arrayInit(int arr[], int sizeArr)
{
    randomFillingArr(arr, sizeArr, 100);
    selectionSort(arr, sizeArr);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    srand(time(NULL));


    int arr[30];
    const int SIZE_ARRAY = sizeof(arr) / sizeof(int);

    arrayInit(arr, SIZE_ARRAY);
    printArr(arr, SIZE_ARRAY);
    
    int searchiningNumber = consoleIndexInput();


    infoOfLinearCycleMethod(arr, SIZE_ARRAY, searchiningNumber);

    infoOfBinarRecurtionMethod(arr, SIZE_ARRAY, searchiningNumber);

    infoOfBinarCycleMethod(arr, SIZE_ARRAY, searchiningNumber);
}