#include "cstdlib"
#include "iostream"

using namespace std;
typedef struct nod
{ 
int cheie;
struct nod*urm;
struct nod*prec;
}Tnod;
Tnod *prim,*ultim;
//Creare lista vida
void creare_lista_vida()
{ 
prim=ultim=0;
}
//Pregatire nod
Tnod*pregatire_nod()
{
Tnod *p;
p=(Tnod*)malloc(sizeof(Tnod));
cout<<"Dati cheia";
cin>>p->cheie;
return p;
}
//Cautare nod
Tnod *cautare_nod( int valoare)
{ 
Tnod *p;
p=prim;
while(p!=0)
if(valoare==p->cheie) 
return p;
else p=p->urm;
return 0;
}
//inserare prim,ultim,dupa,inainte
//Inserare dupa prim
void inserare_prim()
{ 
Tnod *nou;
nou=pregatire_nod();
if(prim==0)
{ 
prim=ultim=nou;
prim->prec=ultim->urm=0;
}
else
{
nou->urm=prim;
prim->prec=nou;
prim=nou;
prim->prec=0;
}
}
//Inserare dupa ultim
void inserare_ultim()
{ 
Tnod*nou;
nou=pregatire_nod();
if(ultim==0)
{ 
prim=ultim=nou;
prim->prec=ultim->urm=0;
}
else
{
ultim->urm=nou;
nou->prec=ultim;
ultim=nou;
ultim->urm=0;
}
}
//Inserare dupa nod
void inserare_dupa_nod()
{
int valoare;
Tnod *p,*nou;
cout<<"Dati valoarea cautata: "<<endl;
cin>>valoare;
p=cautare_nod(valoare);
if(p==0) return; 
if(p==ultim) 
inserare_ultim();
else
{
//caz general
nou->urm=p->urm;
p->urm=nou;
nou->prec=p;
(p->urm)->prec=nou;
}
}
//Inserare inaintea unui nod
void inserare_inainte_nod()
{ 
Tnod *p,*nou;
int valoare;
cout<<"Dati val. cautata: "<<endl;
cin>>valoare;
p=cautare_nod(valoare);
if(p==0)
return;
if(p==prim)
inserare_prim();
else
{
//caz general
nou=pregatire_nod();
nou->urm=p;
(p->prec)->urm=nou;
nou->prec=p->prec;
p->prec=nou;
}
}
//STERGERE LISTA
//Stergerea primului nod
void stergere_prim()
{
Tnod*prim_vechi;
if(prim==0)
return;
//caz particular
prim_vechi=prim;
prim=prim->urm;
free(prim_vechi);
}
//Stergere ultim
void stergere_ultim()
{
Tnod *ultim_vechi;
if(ultim==0)
return;
ultim_vechi=ultim;
ultim=ultim->prec;
ultim->urm=0;
free(ultim_vechi);
}
//Stergerea unui nod oarecare
void stergere_nod()
{
Tnod *p;
int valoare;
cout<<"Dati valoarea: "<<endl;
cin>>valoare;
p=cautare_nod(valoare);
if(p==0)
return;
if(p==prim)
{
stergere_prim();
return;
}
if(p==ultim)
{
stergere_ultim();
return;
}
(p->urm)->prec=p->prec;
(p->prec)->urm=p->urm;
free(p);
}
//Stergere lista
void stergere_lista()
{
while(prim!=0) stergere_prim();
}
//Listare
void tiplista()
{
Tnod*p;
p=prim;
while(p!=0)
{ 
cout<<p->cheie<<endl;
p=p->urm;
}
}
//Main program
int main(int argc, char *argv[])
{int c,valoare;
Tnod *p;
do{
cout<<"Pentru creare lista vida apasati 1"<<endl;
cout<<"Pentru pregatirea unui nod apasati 2"<<endl;
cout<<"Pentru cautarea unui nod apasati 3"<<endl;
cout<<"Pentru inserarea primului nod apasati 4"<<endl;
cout<<"Pentru inserarea ultimului nod apasati 5"<<endl;
cout<<"Pentru inserarea unui nod dupa un nod cautat apasati 6"<<endl;
cout<<"Pentru inserarea unui nod inainte un nod cautat apasati 7"<<endl;
cout<<"Pentru stergerea primului nod apasati 8"<<endl;
cout<<"Pentru stergere listei apasati 9"<<endl;
cout<<"LISTARE 10"<<endl;
cout<<"Pentru iesirea din meniu apasati 0"<<endl;
cin>>c;
switch(c)
{
case 1:creare_lista_vida(); break;
case 2:pregatire_nod(); break;
case 3:
{ cout<<"dati valoarea cautata: ";
cin>>valoare;
p=cautare_nod(valoare); break;}
case 4:inserare_prim(); break;
case 5:inserare_ultim(); break;
case 6:inserare_dupa_nod(); break;
case 7:inserare_inainte_nod(); break;
case 8:stergere_prim(); break;
case 9:stergere_lista(); break;
case 10:tiplista(); break;
}
} while(c!=0);
system("PAUSE");
return EXIT_SUCCESS;
}