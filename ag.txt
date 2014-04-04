#include <cstdlib>
#include <iostream>

using namespace std;

tnod * p;
p=pLC;
do { // acces parcurgere
     p=p->urm;} while (p!=pLC;);

//cautare nod

tnod * cautareLC(int valoare);
{tnod * p;
p=pLC;
do{
      if(p->cheie==valoare) return p;
                            p=p->urm;      
      }while(p!=pLC);
return 0;

}

// inserare nod dupa pLC

void inserare_dupa_pLC()
     { tnod * nou;
       nou = pregatire_nod();
       
       if (pLC==0) {
                   pLC=nou;
                   pLC->urm=pLC;
                   return;
                   }
     // caz general
            nou->unu=pLC->urm;
            pLC->urm=nou;
     //pLC = nou;
           }

void crearelistacirculara()
     { int n; // nr predefinit de noduri
       int raspuns; 
       tnod * nou;
       pLC=0;
       cout << "Cate noduri doriti ?"; cin >> n;
       for (int i=0, i<n, i++) inserare_dupa_pLC();
     }
       
//inserare dupa un nod oarecare

void inseraredupanodoarecare(int valoare)
{    tnod * nou, p;
     if (pLC==0) return; // lista vida
     p=pLC;
     do {
         if (p->cheie==valoare) break;
         else p=p->urm;
         
         
         
         

     }  
