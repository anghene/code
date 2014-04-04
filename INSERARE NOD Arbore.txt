#include <cstdlib>
#include <iostream>

using namespace std;
typedef struct nod{ int cheie;
struct nod*dr;
struct nod*st;
}
Tnod;
//parcurgere preordine
void preordine(Tnod*p)
{
     if(p==0)
     return;
     else
     {cout <<p->cheie;
     preordine(p->st);
     preordine(p->dr);
     }
}
//parcurgere postordine
void postordine(Tnod*p)
{
     if(p==0)
     return;
     else
     {
         postordine(p->st);
         postordine(p->dr);
         cout<<p->cheie;
}
}
//parcurgere inordine 
void inordine(Tnod*p)
{  if(p==0)
   return;
   else
   { inordine(p->st);
   cout<<p->cheie;
   inordine(p->dr);
}
}
//cautare 
Tnod *cautare(int valoare)
{
     Tnod *p , *rad;
     
     p=rad;
     if(rad==0)
     return 0;
     while(p!=0)
{
     if(p->cheie==valoare)
     return p;
     if(p->cheie<valoare)
     p=p->dr;
     if(p->cheie>valoare)
     p->st;
     }
     return p;
}
//Pregatire nod
Tnod*pregatire_nod()
{Tnod*p;
p=(Tnod*)malloc(sizeof(Tnod));
cout<<"Dati cheia";
cin>>p->cheie;
return p;
}

//inserarea unui nod in ABC
void inserare_nod()
{
  Tnod *p, *nou, *rad;
  nou=pregatire_nod();
  nou->st=nou->dr=0;
if(rad==0)
{rad=nou;
return;
}
p=rad;
while(1)
if(p->cheie<nou->cheie)
{if(p->dr==0)
{p->dr=nou;
return;
}
else {p=p->dr;} 
}
else
{if(p->st==0)
{p->st=nou;
return;
}
else {p=p->st;} 
}
}
//creare arbore
void creare_abc()
{int n; 
cout<<"n=";
cin>>n; rad=0;
for(i=0; i<n; i++)
inserare_nod();

     

         
     
int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
