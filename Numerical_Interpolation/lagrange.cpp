#include <iostream>
using namespace std;

int main()
{
	 float x[100], y[100], xp, yp=0, p;
	 int i,j,n;

	 cout<<"Index da repeticao: ";
	 cin>>n;
	 
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"y["<< i<<"] = ";
		  cin>>y[i];
	 }
	 cout<<"Ponto da interpolacao: ";
	 cin>>xp;

	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 printf("%.5f \n", yp);

	 return 0;
}