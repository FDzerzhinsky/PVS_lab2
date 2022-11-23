#include <iostream>
#include <algorithm>
#include <omp.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// Разделение по схеме Lomuto
int partition(int a[], int start, int end)
{
    // Выбираем крайний правый элемент в качестве опорного элемента массива
    int pivot = a[end];

    // элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
    // элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
    // равные элементы могут идти в любом направлении
    int pIndex = start;

    // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
    // увеличивается, и этот элемент будет помещен перед опорной точкой.
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    // поменять местами `pIndex` с пивотом
    swap(a[pIndex], a[end]);

    // вернуть `pIndex` (индекс опорного элемента)
    return pIndex;
}

// Процедура быстрой сортировки
void quicksort(int a[], int start, int end)
{
    // базовое условие
    if (start >= end) {
        return;
    }

    // переставить элементы по оси
    int pivot = partition(a, start, end);

    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    quicksort(a, start, pivot - 1);

    // повторяем подмассив, содержащий элементы, превышающие точку опоры
    quicksort(a, pivot + 1, end);
}

// C++ реализация алгоритма быстрой сортировки

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
                    quicksort(b, 0, n - 1);
            }
            //eTime = omp_get_wtime();
            eTime = std::clock();
            dTime = eTime - sTime;
            cout << "\n";
            cout << "\n";
            cout << "Time of algoritm execution: " << dTime << " sec." << " for number of threads: " <<k;
        }
    }


    


    //печатаем отсортированный массив
    /*
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    
    */

    return 0;
}