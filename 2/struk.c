#include <stdio.h>
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
	Tocka *vrhovi;
	int n;
}Poligon;

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) {
	Poligon* poligon = (Poligon*)malloc(sizeof(Poligon));
	poligon->n = n;

	poligon->vrhovi = (Tocka*)malloc(sizeof(Tocka) * n);

	for (int i = 0; i < n; i++)
	{
		poligon->vrhovi[i].x = *(niz_x + i);
		poligon->vrhovi[i].y = *(niz_y + i);

	}

	return poligon;

}

Tocka** pozitivni(Poligon *p, int *np) {
	int n = *np;
	Tocka** poz_vrh = (Tocka**)malloc(sizeof(Tocka*)*n);
	int j = 0;
	*np = 0;
	for (int i = 0; i < n; i++)
	{
		if ((p->vrhovi[i].y > 0) && (p->vrhovi[i].x >0))
		{
			poz_vrh[j] = &(p->vrhovi[i]);
			j++;
			(*np)++;
		}
	}


	return poz_vrh;
}


int main2()
{
	float niz_x[] = { 1,2,-3 };
	float niz_y[] = { -4,5,6 };
	int n = sizeof(niz_x) / sizeof(niz_x[0]);

	

	Poligon *poligon = novi_poligon(niz_x, niz_y, n);

	for (int i = 0; i < n; i++)
	{
		printf("%f %f\n", poligon->vrhovi[i].x, poligon->vrhovi[i].y);
	}

	int np = n;

	Tocka** poz_vrh = pozitivni(poligon, &np);

	for (int i = 0; i < np; i++)
	{
		printf("pozitivne su: %f %f\n", poz_vrh[i]->x, poz_vrh[i]->y);
	}

	free(poligon);
	free(poz_vrh);
}