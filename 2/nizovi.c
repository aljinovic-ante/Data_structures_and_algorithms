#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int* podniz(int *niz, int start, int stop) – vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.

int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th. O
riginalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth.

int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela.
Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.
*/
/*
int* podniz(int *niz, int start, int stop) {
	int* novi_niz = (int*)malloc(sizeof(int)*(stop - start));

	int i, j = 0;

	for (i = start; i < stop; i++, j++)
	{
		*(novi_niz + j) = *(niz + i);
	}

	return novi_niz;
}

int main()
{
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	int start = 3;
	int stop = 7;

	int *novi_niz = podniz(niz, start, stop);

	for (int i = 0; i < (stop - start); i++)
	{
		printf("%d ", novi_niz[i]);
	}

	free(novi_niz);
}
*//*
int* filtriraj(int *niz, int n, int th, int *nth) {

	int i, j = 0;

	int brojac = 0;

	for (i = 0; i < n; i++)
	{
		if (*(niz + i) < th)
		{
			brojac++;
		}
	}

	*nth = 0;
	int* novi_niz = (int*)malloc(sizeof(int)*brojac);
	for (i = 0; i < n; i++)
	{
		if (*(niz + i) < th)
		{
			*(novi_niz + j) = *(niz + i);
			j++;
			*nth = *nth + 1;
		}
	}

	return novi_niz;
}
int main()
{
	int niz[] = { 1,-2,3,-4,-5,6,-7,8,-9,10 };
	int n = sizeof(niz) / sizeof(niz[0]);
	int th = 0;
	int nth;
	int *novi_niz = filtriraj(niz, n, th, &nth);

	for (int i = 0; i < nth; i++)
	{
		printf("%d ", *(novi_niz+i));
	}

	free(novi_niz);
}*/

int** podijeli(int *niz, int n)
{
	int i, j=0;
	int* prvi_dio = (int*)malloc(sizeof(int)* (n / 2));
	int* drugi_dio = (int*)malloc(sizeof(int)* ((n+1) / 2));

	for (i = 0; i < n; i++)
	{
		if (i < (n / 2))
			*(prvi_dio + i) = *(niz + i);
		if ((i + 1) > (n / 2))
		{
			*(drugi_dio + j) = *(niz + i);
			j++;
		}
	}

	int ** dva_pokazivaca = (int**)malloc(sizeof(int*) * 2);

	dva_pokazivaca[0] = &prvi_dio[0]; // dva_pokazivaca[0] = prvi_dio;
	dva_pokazivaca[1]= &drugi_dio[0];

	return dva_pokazivaca;
}

int main(){
	
		int niz[] = { 1,-2,3,-4,-5,6,-7,8,-9,10,11};
		int n = sizeof(niz) / sizeof(niz[0]);

		int** dva_pokazivaca = podijeli(niz, n);

		int i = 0;

		for (i = 0; i < n/2; i++)
		{
			printf("%d. broj u prvom nizu: %d\n",i+1, *(dva_pokazivaca[0] + i));
		}
		printf("\n\n");
		for (i = 0; i < ((n + 1) / 2); i++)
		{
			printf("%d. broj u drugom nizu: %d\n", i + 1, *(dva_pokazivaca[1] + i));
		}

		free(dva_pokazivaca);
	
		
	
}