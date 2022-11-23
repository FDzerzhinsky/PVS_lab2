#include <iostream>
#include <omp.h>
#include <cstdlib>

using namespace std;

int sumParal(int nTrds, int n, int *a)
{
    int sum = 0;
#pragma omp parallel shared(a) reduction (+: sum) num_threads(nTrds) 
    {
#pragma omp for 
        for (int i = 0; i < n; i++)
            sum = sum + a[i];
    }
    return sum;
}

int main()
{
    int i, n, * a;
    double sTime, eTime, dTime;
    n = 100000000;
    a = new int[n];
    cout << "Array is generated. Wait for sum calculation...\n";
    cout << "\n";
    std::srand(111);
    for (i = 0; i < n; i++)
    {
        a[i] = std::rand();
    }
    cout << "";
    
    for (int i = 1; i <= 8; i++)
    {
        if (i == 1 or i == 2 or i == 4 or i == 8)
        {
            sTime = omp_get_wtime();
            cout << "Summ of your array: " << sumParal(i, n, a) << '\n';
            eTime = omp_get_wtime();
            dTime = eTime - sTime;
            cout << "Program execution time: " << dTime << " sec. on " << i << " thread(s)" << '\n' << '\n';
        }
    }
    return 0;        
}
