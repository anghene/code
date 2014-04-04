#include <cstdlib>
#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct nod{
        int cheie;
        struct nod*st;
        struct nod*dr;
        }tnod;

tnod * rad;

tnod * pregatire_nod()
{ tnod*p; int cheie;
  p=(tnod*)malloc(sizeof(tnod));
  cout<<"Dati cheia : ";  
  cin>>cheie;                  
}


void preordine(tnod *p)
{if (p==0) return;
 else { 
      cout << p->cheie;
      preordine(p->st);
      preordine(p->dr);
      }
}

void postordine(tnod *p)
{if (p==0) return;
 else { 
      postordine(p->st);
      postordine(p->dr);
      cout << p->cheie;
      }
}


void inordine(tnod *p)
{ if (p!=0) 
	{
		inordine(p->st);
			cout << p->cheie;
		inordine(p->dr);
	}

}

tnod * cautare(int valoare)
{   tnod*p;
    if (rad==0) {cout << "nu avem noduri in arbore" ; return 0;}
    p=rad;
    
    while (p!=0) { 
                   if (p->cheie==valoare) {return p;}
                   if (p->cheie<valoare) { // mergem in dreapta
                                             p=p->dr;
                                           }
                   if (p->cheie>valoare) { // mergem in dreapta
                                             p=p->st;
                                           }                                           
                 }
    
    cout << "nu am gasit valoarea cautata";             
    return p;
    
}

void inserare_nou()
{ tnod*p,*nou;
  nou=pregatire_nod();
  nou->st=nou->dr=0;
  
                    if (rad==0)
                    {rad=nou;return;}
  p=rad;
  
  while(1) {
            if (p->cheie<nou->cheie)
               {    if(p->dr==0) {p->dr=nou; return;}
                    else p=p->dr; } 
                                    
            else { if (p->st==0) {p->st=nou; return;}
                    else p=p->st; }
            }
            
}


void creare_abc()
{int n, i;
 cout << "n="; cin >> n;
 rad=0;
 for (i=0;i<=n;i++) {  inserare_nou(); }
}




void stergere (int valoare)
{tnod *p, *tatap;
 p=rad;
 
 while (p!=0)
       { if (p->cheie==valoare) break;
         if (p->cheie>valoare) { tatap=p;
                             p=p->st;
                             };
         if (p->cheie < valoare) { tatap=p;
                               p=p->dr;};
         if (p==0) {cout << "not found"; return; }
         
         if ((p->st==0)&&(p->dr==0))
            { if (p==rad) {rad=0; free(p); return;}
              if (tatap->st==p)
                 { tatap->st=0;
                   free(p);
                   return;
                   }
              if (tatap->dr==p)
                 { tatap->dr=0;
                   delete p;
                   return;
                   }
        }
        
        if (p->st==0)
                     {  if (tatap->dr==p)
                           { tatap->dr=p->dr;
                             delete p;
                             return;
                             }
                        if (tatap->st==p) 
                           { tatap->st==p->dr;
                             delete p;
                             return; }
                     }  
                     
        if (p->dr==0)
                     {   if (tatap->st==0)
                            {tatap->st=p->st;
                             free(p);
                             return;                     
                             }
                    
                         if (tatap->dr==p) {
                             tatap->dr=p->st;
                             free(p);
                             return;
                             }
                             
                     }       
                     
 // caz nod intern cu 2 subarbori
 
        tnod *pp,*tatapp;
        tatapp=p;
        pp=p->st;
        
                 while (pp!=0)
                       {tatapp=pp;
                       pp=pp->dr;}
        if (tatapp==p) {
                       p->cheie=pp->cheie;
                       tatapp->st==pp->st;
                       delete pp;
                       }
                       
        else {    p->cheie==pp->cheie;
                  tatapp->dr==pp->st;
                  delete pp;
                  return;
             }
}} // sf functie       


void stergere_abc(tnod*p)
{    if (p==0) return;
     else {
          stergere_abc(p->st);
          stergere_abc(p->dr);
          delete p;
          }
     
     }


int main()
{ 
	tnod * vlad;
	creare_abc();
	vlad = cautare(3);
	if (vlad) cout << "vlad exista in arbore";

    system("pause");
}




   