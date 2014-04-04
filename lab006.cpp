#include "cstdlib"
#include <iostream>
using namespace std;



//Stiva
typedef struct nod {
int nr_cuvinte;
int cheie;
float lungime_cioc;
char culoare[20];
struct nod *urm;
struct nod *prec;
}Tnod;

//pregatire nod
Tnod * prim, * ultim;
Tnod * pregatire_nod()
{ Tnod*p;
p=(Tnod*)malloc(sizeof(Tnod));
cout<<"Dati cheia"<<endl;
cin>>p->cheie;
cout<<"Dati culoarea papagalului"<<endl;
cin>>p->culoare;
cout<<"Dati lungimea ciocului"<<endl;
cin>>p->lungime_cioc;
cout<<"Dati nr de cuvinte pe care le poate spune"<<endl;
cin>>p->nr_cuvinte;
}

//inserare papagal
void push()
{Tnod*nou;
nou=pregatire_nod();
if(prim==0){prim=ultim=nou;
prim->prec=ultim->urm=0;
}

//caz particular
nou->urm=prim;
prim->prec=nou;
prim=nou;
prim->prec=0;
}
void pop()

//stergere papagal
{Tnod*p;
if(ultim==0)return;
p=ultim;
ultim=ultim->prec;
ultim->urm=0;
free(p);
}

int main(int argc, char const *argv[])
{
	pregatire_nod();
	
	return 0;
}