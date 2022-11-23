#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std;
int main()
{
    double sTime, eTime, dTime;
    int i, n, * a;
    int sum = 0;
    n = 100000000;
    a = new int[n];
    std::srand(111);
    for (i = 0; i < n; i++)
        a[i] = std::rand();

    sTime = omp_get_wtime();
    for (i = 0; i < n; i++)
        sum += a[i];
    cout << "Summ of your array: " << sum;
    cout << "\n";
    eTime = omp_get_wtime();
    dTime = eTime - sTime;
    cout << "Program execution time : " << dTime << '\n';
    return 0;
}