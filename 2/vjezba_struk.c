#include <stdio.h>
#include <stdlib.h>

/*
Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). 
Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima:

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova.
Nizovi su dužine n (≥ 3).

Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača na vrhove poligona kojima su obje koordinate pozitivne. 
Broj elemenata u nizu će biti spremljen u np parametar.

*/

typedef struct {
	float x, y;
}Tocka;

typedef struct {
	Tocka* niz;
	int n;
}Poligon;

Poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	Poligon* novi_pol = (Poligon*)malloc(sizeof(Poligon));
	novi_pol->n = n;
	novi_pol->niz = (Tocka*)malloc(sizeof(Tocka) * n);

	for (int i = 0; i < n; i++)
	{
		novi_pol->niz[i].x = niz_x[i];
		novi_pol->niz[i].y = niz_y[i];
	}

	return novi_pol;
}

Tocka** pozitivni(Poligon* p, int* np)
{
	Tocka** pokazivaci = (Tocka**)malloc(sizeof(Tocka*)*(p->n));

	for (int i = 0; i < (p->n); i++)
	{
		if (p->niz[i].x > 0 && p->niz[i].y > 0)
		{
			pokazivaci[*np] = &(p->niz[i]);
			(*np)++;
		}
	}

	return pokazivaci;
}

int main()
{
	float niz_x[] = { 1,-3,0.1,5 };
	float niz_y[] = { 0.1,3,2,-5 };

	Poligon* novi_pol = novi_poligon(niz_x, niz_y, sizeof(niz_x) / (sizeof(niz_x[0])));
	
	int np = 0;

	Tocka** pokazivaci = pozitivni(novi_pol, &np);


	for (int i = 0; i < sizeof(niz_x) / (sizeof(niz_x[0])); i++)
	{
		printf("%f | %f\n", novi_pol->niz[i].x, novi_pol->niz[i].y);
	}

	printf("\n");

	for (int i = 0; i < np; i++)
	{
		printf("%f | %f\n", pokazivaci[i]->x, pokazivaci[i]->y);
	}

	free(pokazivaci);
	free(novi_pol);

}