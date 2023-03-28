#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <malloc.h>

typedef struct {
	int prioritet;
	void* ignore;
}Element;

typedef struct {
	Element* niz;
	int n;
}Red;

int duljina = 10;

/*
*					         00
*			   01				          02
*		03		     04			   05            06
*    07   08      09
*/

void print(Red* r)
{
	for (int i = 0; i < (r->n); i++)
		printf("%d\n", r->niz[i].prioritet);
}

void zamjena(Red* r, int roditelj, int i)
{
	Element tmp = r->niz[roditelj];
	r->niz[roditelj] = r->niz[i];
	r->niz[i] = tmp;
	
}


void zamjena2(Element* a, Element* b) {
	Element tmp = *a;
	*a = *b;
	*b = tmp;
}


void popravi_prema_vrhu(Red* r, int i)
{
	int roditelj = ((i - 1) / 2);


	Element dijete = r->niz[i];
	Element roditeljski_element = r->niz[roditelj];

	if (dijete.prioritet <= roditeljski_element.prioritet)
		return;

	
	zamjena(r, roditelj, i);
	popravi_prema_vrhu(r, roditelj);
	
}

void popravi_prema_vrhu_iterativno(Red* r, int i) {

	int roditelj = ((i - 1) / 2);

	Element roditeljski_element = r->niz[roditelj];

	while (r->niz[i].prioritet > roditeljski_element.prioritet) {

		zamjena(r,  roditelj,i );

		i = roditelj;
		roditelj = (i - 1) / 2;

		roditeljski_element = r->niz[roditelj];
	}

}

void dodaj_novi_elem(Red* r, int i)
{
	int indeks = r->n++;
	r->niz[indeks].prioritet = i;

	popravi_prema_vrhu_iterativno(r, indeks);

}

void popravi_do_dna(Red* r, int broj)
{
	//int lijevo_dijete = 2 * broj + 1;
	//int desno_dijete = 2 * broj + 2;
	//if (desno_dijete >= duljina || lijevo_dijete >= duljina)
	//	return;

	//if ( (r->niz[broj].prioritet < r->niz[lijevo_dijete].prioritet) && (r->niz[lijevo_dijete].prioritet >= r->niz[desno_dijete].prioritet) )
	//{
	//	//printf("test1\n");
	//	zamjena(r, broj, lijevo_dijete);
	//	popravi_do_dna(r, lijevo_dijete);
	//}
	//else if (r->niz[desno_dijete].prioritet >= r->niz[lijevo_dijete].prioritet && r->niz[broj].prioritet < r->niz[desno_dijete].prioritet)
	//{
	//	//printf("test2\n");
	//	zamjena(r, broj, desno_dijete);
	//	popravi_do_dna(r, desno_dijete);
	//}
	////
	int lijevo_dijete = 2 * broj + 1;
	int desno_dijete = 2 * broj + 2;

	if (lijevo_dijete >= r->n)
		return;

	Element* rod_elem = &(r->niz[broj]);
	Element* l_d_e = &(r->niz[lijevo_dijete]);

	if (desno_dijete >= r->n) {
		if (l_d_e->prioritet > rod_elem->prioritet) {
			zamjena2(rod_elem, l_d_e);
		}

		return;
	}

	Element* r_d_e = &(r->niz[desno_dijete]);

	if ((rod_elem->prioritet < l_d_e->prioritet) || (rod_elem->prioritet < r_d_e->prioritet)) {

		if (l_d_e->prioritet > r_d_e->prioritet) {
			zamjena2(rod_elem, l_d_e);
			popravi_do_dna(r, lijevo_dijete);
		}

		else {
			zamjena2(rod_elem, r_d_e);
			popravi_do_dna(r, desno_dijete);
		}
	}

}

void popravi_do_dna_iterativno(Red* r, int broj)
{

	//while (1)
	//{

	//	int lijevo_dijete = 2 * broj + 1;
	//	int desno_dijete = 2 * broj + 2;

	//	if (desno_dijete >= duljina || lijevo_dijete >= duljina)
	//		return;

	//	if ((r->niz[broj].prioritet < r->niz[lijevo_dijete].prioritet) && (r->niz[lijevo_dijete].prioritet >= r->niz[desno_dijete].prioritet))
	//	{
	//		//printf("test1\n");
	//		zamjena(r, broj, lijevo_dijete);
	//		broj = lijevo_dijete;
	//	}
	//	else if (r->niz[desno_dijete].prioritet >= r->niz[lijevo_dijete].prioritet && r->niz[broj].prioritet < r->niz[desno_dijete].prioritet)
	//	{
	//		//printf("test2\n");
	//		zamjena(r, broj, desno_dijete);
	//		broj = desno_dijete;
	//	}
	//	else
	//		return;
	//}
	Element* rod_elem;
	Element* r_d_elem;
	Element* l_d_elem;

	while (1) {

		int l_d_i = 2 * broj + 1;
		int r_d_i = 2 * broj + 2;

		if (l_d_i >= r->n)
			return;

		rod_elem = &(r->niz[broj]);
		l_d_elem = &(r->niz[l_d_i]);

		if (r_d_i >= r->n) {
			if (l_d_elem->prioritet > rod_elem->prioritet)
				zamjena2(rod_elem, l_d_elem);

			return;
		}

		r_d_elem = &(r->niz[r_d_i]);

		if ((rod_elem->prioritet < l_d_elem->prioritet) || (rod_elem->prioritet < r_d_elem->prioritet)) {
			if (l_d_elem->prioritet > r_d_elem->prioritet) {
				zamjena2(rod_elem, l_d_elem);
				broj = l_d_i;
			}

			else {
				zamjena2(rod_elem, r_d_elem);
				broj = r_d_i;
			}
		}

		else
			return;

	}

}

void ukloni_s_vrha(Red* r)
{

	if (r->n <= 0)
		return;

	Element vrh = r->niz[0];
	Element bot = r->niz[zadnji_element(r)];

	r->niz[0] = bot;
	r->niz[zadnji_element(r)].prioritet = -842150451;
	r->n--;

	popravi_do_dna(r, 0);

}

int zadnji_element(Red* r) {
	return r->n - 1;
}

int main()
{
	srand(time(NULL));
	Red* r = (Red*)malloc(sizeof(Red));
	r->niz = (Element*)malloc(sizeof(Element) * 100);
	r->n = 0;

	int arr[] = { 7,3,8,2,23,7,21,17,1,9};

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		dodaj_novi_elem(r, arr[i]);
	}

	print(r);

	ukloni_s_vrha(r);
	printf("nakon ukloni_s_vrha:\n");
	print(r);

	ukloni_s_vrha(r);
	printf("nakon ukloni_s_vrha:\n");
	print(r);

	free(r->niz);
	free(r);

	return 0;

}
