#include <stdio.h>
#include <stdlib.h>


/*
* int* podniz(int *niz, int start, int stop) – vra?a novi niz koji je kopija dijela niza od indeksa start do indeksa stop.
*/
int* podniz(int* niz, int start, int stop) {
	int i;
	int j = 0;
	int* niz2 = (int*)malloc(sizeof(int) * (stop - start));

	for (i = start; i < stop; i++,j++)
	{
		*(niz2+j) = *(niz + i);
	}

	return niz2;

}

int main()
{
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	int start = 3;
	int stop = 7;
	int* niz2 = podniz(&niz[0], start, stop);

	int i;

	for (i = 0; i < (stop-start); i++)
	{
		printf("%d ", *(niz2+i));
	}

	free(niz2);

	return 0;
}