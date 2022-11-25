#include <iostream>
#include <algorithm>
#include <omp.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int a[], int start, int end)
{
    int right = a[end];
    int sIndex = start;

    for (int i = start; i < end; i++)
    {
        if (a[i] <= right)
        {
            swap(a[i], a[sIndex]);
            sIndex++;
        }
    }
        swap(a[sIndex], a[end]);
    return sIndex;
}

void qsort(int a[], int start, int end)
{
    if (start >= end) 
        return;
    int opor = partition(a, start, end);
    qsort(a, start, opor - 1);
    qsort(a, opor + 1, end);
}

int *arrback(int arr[], const int n)
{
    int *second;
    second = new int[n];
    int stkn;
    for (int i = 0; i < n; i++)
    {
        stkn = arr[i];
        second[i] = stkn;
    }
    return second;
}

int main()
{
    int * a, *b;
    double sTime, eTime, dTime;
    const int n = 1000000;
    a = new int[n];

    std::srand(111);
    std::clock_t start;
    for (int i = 0; i < n; i++)
    {
        a[i] = std::rand();
    }
    cout << "Array is generated now. Wait for sort...";

    for (int k = 1; k <= 8; k++)
    {
        b = arrback(a, n);
        if (k == 1 or k == 2 or k == 4 or k == 8)
        {
            //sTime = omp_get_wtime();
            sTime = std::clock();
#pragma omp parallel shared(a) num_threads(k)
            {
#pragma omp single nowait            
                    qsort(b, 0, n - 1);
            }
            //eTime = omp_get_wtime();
            eTime = std::clock();
            dTime = eTime - sTime;
            cout << "\n";
            cout << "\n";
            cout << "Time of algoritm execution: " << dTime << " mSec." << " for number of threads: " <<k;
        }
    }
    return 0;
}