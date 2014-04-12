#include "cstdlib"
#include "iostream"

using namespace std;

int x[10];
int n,i;

int cautarebinara(int st,int dr)
{
	int max;
	if (st==dr) 
	{
		if (st==valoare) int pozitie=st;
		else pozitie=-1;
	}

	else int pozmed=(dr+st)/2;
		{
			if (pozmed==valoare)
				pozitie=pozmed;
			else if (valoare>pozmed){
						cautarebinara(pozmed+1,)





					}
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