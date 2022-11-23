
#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
	double sTime, eTime, dTime;
	int n = 10000000, i;
	double pi, h, sum, x;
	h = 1.0 / (double)n;
	sum = 0.0;

	sTime = omp_get_wtime();
#pragma omp parallel for private(x) shared(w) reduction (+: sum) num_threads(8) 
	
		for (i = 1; i <= n; i++)
		{
			x = h * ((double)i - 0.5);
			sum += (4.0 / (1.0 + x * x));
		}
	eTime = omp_get_wtime();

	pi = h * sum;
	dTime = eTime - sTime;

	cout << fixed;
	cout.precision(50);
	cout << "pi= " << pi << endl;
	cout << "Program execution time : " << dTime << '\n';
	return 0;
}