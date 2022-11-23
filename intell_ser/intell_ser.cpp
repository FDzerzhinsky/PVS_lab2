#include <iostream>
#include <omp.h>
using namespace std;
double serial_pi() 
{
    int n = 1000000;
    double pi, h, sum, x;
    h = 1.0 / (double)n;
    sum = 0.0;

    for (int i = 1; i <= n; i++) {
        x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x * x));
    }
    pi = h * sum;

    return pi;
}
int main()
{
    double sTime, eTime, dTime;
    sTime = omp_get_wtime();
    cout << serial_pi() << endl;
    eTime = omp_get_wtime();
    dTime = eTime - sTime;
    cout << "Program execution time " << dTime << '\n';
       return 0;
}

