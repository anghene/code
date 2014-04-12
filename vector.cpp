#include "cstdlib"
#include "iostream"

using namespace std;

int x[10];
int n,i;

int maxim(int st,int dr)
{
	int max;
	if (st==dr) return x[st];

	else 
		{
			int pozmed=(dr+st)/2;
			int max1= maxim(st,pozmed);
			int max2= maxim(pozmed+1,dr);
			if (max1>max2) max=max1;
			else max=max2;
		}
}



int main(int argc, char const *argv[])
{


	cout << "cate elemente are vectorul ?";
	cin >> n;

	for (i = 0; i <= n; i++)
	{
		cout << "dati elementul x[" << i <<"]";
		cin >> x[i];
	}

	cout << "maximul este" << maxim(x[i],x[n]);	

	return 0;
}