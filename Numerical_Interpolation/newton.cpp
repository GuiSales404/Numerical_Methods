#include <iostream>
#include <iomanip>

using namespace std;

float u_cal(float u, int n)
{
              float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u - i);
	return temp;
}
int fact(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}
int main()
{

	float n = 4;
	float x[] = { 20, 30, 45, 55 };
	float y[4][4];
	y[0][0] = 0.99807;
	y[1][0] = 0.99826;
	y[2][0] = 0.99849;
	y[3][0] = 0.99919;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}
	
	float value = 25;


	float sum = y[0][0];
	float u = (value - x[0]) / (x[1] - x[0]); 
	for (int i = 1; i < n; i++) {


		sum = sum + (u_cal(u, i) * y[0][i]) / fact(i);
	}

	printf("P3(x) = %.5f \n", sum);
	return 0;
}