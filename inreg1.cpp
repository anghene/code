#include "cstdlib"
#include "iostream"

using namespace std;

typedef struct nod
{ int cheie;
	struct nod *urm;
	
}tnod;

tnod *prim, *ultim;

//fct creare lista vida

void creare_lista_vida();
{
	prim=ultim=0;
}

//fct pregatire nod
tnod * pregatire_nod(){
	tnod *p;
	p=(tnod*)malloc(sizeof(tnod));
	cout << "Dati cheia";
	cin >> p->cheie;
	return p;
}

//fctie cautare nod
tnod * cautare_nod(int valoare)
{
	tnod *p;
	p=prim;
	while(p!=0)
		{if (valoare==p->cheie) return p;
			else p=p->urm; return 0;
}}

//functie inserare prim
void inserare_prim() {
	tnod * nou;
	nou=pregatire_nod();

	if (prim==0) {
	prim=ultim=nou;
	ultim->urm=0;
	return; }

	nou->urm=prim;
	prim=nou;

}


//fctie inserare ultim
void inserare_ultim(){
	tnod * nou;
	nou=pregatire_nod();

	if (ultim==0) {
		prim=ultim=nou;
		ultim->urm=0;
		return;
	}

	// caz gen

	ultim->urm=nou;
	nou->urm=0;
	ultim=nou;
}


//inserare dupa
void inserare_dupa_nod(){
	int valoare;
	tnod * p, *nou;
	cout << "dati valoarea cautata:"
	cin >> valoare;

	p=cautare_nod(valoare);


	if (p==0) return;
	if (p==ultim) {
		inserare_ultim();
	 	return;
	}
// caz gen
	nou=pregatire_nod();
	nou->urm=p->urm;
	p->urm=nou;
}


// inserare inainte nod
void inserare_inainte_nod(){
	int valoare;
	tnod *p, *prec, *nou;
	cout << "Dati valoare:";
	cin >> valoare;

	p=prim;

	while(p!=0) {
		if (p->cheie==valoare) {if (p==prim) {inserare_prim(); return;}}
		//caz gen
		nou=pregatire_nod();
		nou->urm=p;
		prec->urm=nou;
		return;
		}

	prec=p;
	p=p->urm;

}


// stergere lista

void stergere_prim() {
	tnod * prim_vechi;
	if (prim==0) return;
	if (prim==ultim) {
		free(prim);
		prim=ultim=0;
		return;
	}
//caz part
	prim_vechi=prim;
	prim=prim->urm;
	free(prim_vechi);
}

//stergere lista
void stergere_lista(){
	while (prim!=0) stergere_prim();
}

void tiparire_lista(){
	tnod*p;
	p=prim;
	while(p!=0) {
		cout p->cheie; p=p->urm;
	}
}

