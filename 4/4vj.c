#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BIGRAND (rand() * rand())
/*
	presjek(skupA, skupB) – funkcija ra?una dužinu presjeka dva skupa

•	presjek_jedan_sortiran(skupA, skupB) – funkcija ra?una dužinu presjeka dva skupa,
gdje je skupB sortirani niz tako da se funkcija oslanja na upotrebu upotrebom bsearch() funkcije(iz stdlib.h)

•	presjek_oba_sortirana(skupA, skupB) – funkcija ra?una dužinu presjeka dva skupa,
gdje je su oba skupa sortirana i mogu?e je samo i?i naprijed sa indeksima po oba skupa

•	presjek_po_indeksima(skupA, skupB) – funkcija kreira dva nova niza (indexA i indexB) i ispunjava ih sa 0.
Dužine nizova su odre?ene najve?im brojem u skupA i skupB. Zatim se za svaki broj iz skupA upiše 1 na njegov indeks u njegovom „indeks“ nizu indexA.
Isto se napravi i za skupB.
Zatim se u novi niz (presjek) broje samo brojevi koji se pojavljuju u oba niza na istom indeksu odnosno imaju 1 u indexA i indexB nizovima.

•presjek_po_indeksima(skupA, skupB) – funkcija kreira dva nova niza (indexA i indexB) i ispunjava ih sa 0.
Dužine nizova su odre?ene najve?im brojem u skupA i skupB. Zatim se za svaki broj iz skupA upiše 1 na njegov indeks u njegovom „indeks“ nizu indexA.
Isto se napravi i za skupB.
Zatim se u novi niz (presjek) broje samo brojevi koji se pojavljuju u oba niza na istom indeksu odnosno imaju 1 u indexA i indexB nizovima.
*/

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void shuffle(int* niz, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int j = i + BIGRAND % (n - i);
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}

}

int* generiraj(int n)
{
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = 1 + BIGRAND % 3;
	for (int i = 1; i < n; i++)
	{
		niz[i] = niz[i - 1] + BIGRAND % 3 + 1;
	}

	shuffle(niz, n);

	return niz;
}

int presjek(int* niz1, int* niz2,int duljina_niza)
{
	int i, j;
	int brojac = 0;


	for (i = 0; i < duljina_niza; i++)
	{
		for (j = 0; j < duljina_niza; j++)
		{
			if (niz1[i] == niz2[j])
				brojac++;
		}

	}

	return brojac;

}

int presjek_oba_sortirana(int* niz1, int* niz2, int duljina_niza)
{
	int i, j;
	int brojac = 0;

	int niz1index = 0, niz2index = 0;

	qsort(niz1, duljina_niza, sizeof(int), cmp);
	qsort(niz2, duljina_niza, sizeof(int), cmp);

	while ((niz1index < duljina_niza) && (niz2index < duljina_niza))
	{
		if (niz1[niz1index] == niz2[niz2index])
		{
			brojac++;
			niz1index++;
			niz2index++;
		}
		else if (niz1[niz1index]>niz2[niz2index])
		{
			niz2index++;
		}
		else
			niz1index++;
	}

	

	return brojac;
}


int presjek_jedan_sortiran(int* niz1, int* niz2, int duljina_niza)
{
	
	int i, j;
	int brojac = 0;
	int* pom;
	qsort(niz2, duljina_niza, sizeof(int), cmp);
	for (i = 0; i < duljina_niza; i++)
	{
		pom = bsearch(niz1 + i, niz2, duljina_niza, sizeof(int), cmp);
		if (pom != NULL)
			brojac++;
	}

	return brojac;
	
}

void presjek_po_indeksima(int* niz1, int* niz2, int duljina_niza)
{

	int max1 = niz1[0];
	int max2 = niz2[0];
	for (int i = 0; i < duljina_niza; i++)
	{
		if (niz1[i] > max1)
			max1 = niz1[i];
		if (niz2[i] > max2)
			max2 = niz2[i];
	}
	//printf("max je %d - %d\n", max1, max2);
	int* indexa = (int*)malloc(sizeof(int) * max1);
	int* indexb = (int*)malloc(sizeof(int) * max2);


	for (int i = 0; i < max1; i++)
	{
		indexa[i] = 0;
	}

	for (int i = 0; i < max2; i++)
	{
		indexb[i] = 0;
	}
	/*for (int i = 0; i < max1; i++)
	{
		printf("%d ", indexa[i]);
	}
	printf("\n");
	for (int i = 0; i < max2; i++)
	{
		printf("%d ", indexb[i]);
	}
	printf("\n");*/

	for (int i = 0; i < duljina_niza; i++)
	{
		indexa[niz1[i] - 1] = 1;
	}

	for (int i = 0; i < duljina_niza; i++)
	{
		indexb[niz2[i] - 1] = 1;
	}
	/*printf("Popunjavanje indeksa\n");
	for (int i = 0; i < max1; i++)
	{
		printf("%d ", indexa[i]);
	}
	printf("\n");
	for (int i = 0; i < max2; i++)
	{
		printf("%d ", indexb[i]);
	}
	printf("\nPresjek \n");*/
	//Zatim se u novi niz (presjek) broje samo brojevi koji se pojavljuju u oba niza na istom indeksu odnosno imaju 1 u indexA i indexB nizovima.
	//int* presjek = (int*)malloc(sizeof(int) * (max1 + max2));
	int k = 0;

	for (int i = 0; i < max1; i++)
	{

		if (indexa[i] == 1 && indexb[i] == 1)
		{
			//presjek[k] = i + 1;
			k++;
		}


	}
	/*for (int i = 0; i < k; i++)
	{
		printf("%d ", presjek[i]);
	}*/
	free(indexa);
	free(indexb);
	return k;
}

int main()
{

	srand(time(NULL));
	clock_t start_t, end_t;
	double total_t;
	int i;
	int velicina = 10000;
	int korak = 30000;
	
	while(velicina<300000)
	{
	
		int* niz1 = generiraj(velicina);
		int* niz2 = generiraj(velicina);
	
		start_t = clock();
		presjek(niz1, niz2,velicina);
		//presjek_jedan_sortiran(niz1, niz2,velicina);
		//presjek_oba_sortirana(niz1, niz2,velicina);
		//presjek_po_indeksima(niz1, niz2,velicina);
		
		end_t = clock();
	
		printf("end_t = %ld\n", end_t);
		total_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;

		printf("velicina %d - total_t %lf\n", velicina, total_t);
	
		free(niz1);
		free(niz2);

		velicina += korak;
	

	}


	

	/*
	start_t = clock();
	for (int i = 0; i < duljina_niza; i++)
	{
		printf("%d %d\n", niz1[i], niz2[i]);
	}
	printf("\nduzine presjeka [presjek] je: %d\n\n", presjek(niz1, niz2));
	end_t = clock();
	printf("vrijeme 1. funkcije %ld\n", end_t);
	printf("vrijeme potrebno u sekundama: %f \n\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);




	start_t = clock();
	qsort(niz2, duljina_niza, sizeof(int), cmp);
	for (int i = 0; i < duljina_niza; i++)
	{
		printf("%d %d\n", niz1[i], niz2[i]);
	}
	printf("\nduzine presjeka [presjek_jedan_sortiran] je: %d \n\n", presjek_jedan_sortiran(niz1, niz2));
	end_t = clock();
	printf("vrijeme 2. funkcije %ld\n", end_t);
	printf("vrijeme potrebno u sekundama: %f \n\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);




	start_t = clock();
	qsort(niz1, duljina_niza, sizeof(int), cmp);
	for (int i = 0; i < duljina_niza; i++)
	{
		printf("%d %d\n", niz1[i], niz2[i]);
	}
	printf("\nduzine presjeka [presjek_oba_sortirana] je: %d\n\n", presjek_oba_sortirana(niz1, niz2));
	end_t = clock();
	printf("vrijeme 3. funkcije %ld\n", end_t);
	printf("vrijeme potrebno u sekundama: %f \n\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);




	printf("\n\n");
	start_t = clock();
	presjek_po_indeksima(niz1, niz2);
	end_t = clock();
	printf("vrijeme 4. funkcije [presjek_po_indeksima] %ld\n", end_t);
	printf("vrijeme potrebno u sekundama: %f \n\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
	*/



}