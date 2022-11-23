#include <iostream>
#include <algorithm>
#include <omp.h>
#include <cstdlib>
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
int main()
{
    int* a;
    double sTime, eTime, dTime;
    const int n = 1000000;
    a = new int [n];

    std::srand(111);
    for (int i = 0; i < n; i++)
    {
        a[i] = std::rand();
    }
    cout << "Array is generated now. Wait for sort...";
    sTime = omp_get_wtime();
    quicksort(a, 0, n - 1);
    eTime = omp_get_wtime();
    dTime = eTime - sTime;

    // печатаем отсортированный массив
    /*for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    */
    cout << "\n";
    cout << "\n";
    cout << "Time of algoritm execution: " << dTime << " sec.";

    return 0;
}