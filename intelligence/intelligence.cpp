#include <iostream>
#include <omp.h>
#pragma omp;
using namespace std;

double piNumber(int ntr)
{
    int n = 1000000;
    double pi, h, sum, x;
    h = 1.0 / (double)n;
    sum = 0.0;
#pragma omp parallel private(i) shared(n) reduction(+: sum) num_threads(ntr) 
    {
        for (int i = 1; i <= n; i++) 
        {
#pragma omp atomic
            x = h * ((double)i - 0.5);
            sum += (4.0 / (1.0 + x * x));
        }
        pi = h * sum;
        cout << "COUNTER OF THREADS\n";
        return pi;
    }
}
int main()
{
    cout << "pi number will calculate now. Please, wait...\n";
    cout << "\n";
    double sTime, eTime, dTime;
    int i;

    for (int i = 1; i <= 8; i++) {
        if (i == 1 or i == 2 or i == 4 or i == 8) 
        {
            sTime = omp_get_wtime();
            cout.precision(30);
            cout <<"pi = "<< piNumber(i) << endl;
            eTime = omp_get_wtime();
            dTime = eTime - sTime;
            cout.precision(7);
            cout << "For number of threads = " << i << " Program execution time : " << dTime << '\n';
            cout << '\n';
        }
    }
    return 0;
}

