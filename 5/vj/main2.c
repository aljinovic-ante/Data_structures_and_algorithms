#include <stdio.h>
#include <ctype.h>
#include "dictionary2.h"

int readWord(FILE *fd, char *buffer)
{
	int c;
	
	do {
		c = fgetc(fd);				
		if(c == EOF)
			return 0;
	} while(!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if(c == 146)
			c = '\'';
	} while(isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE *fd;
	char buffer[1024];
	Dictionary dict;
				
	fd = fopen("liar.txt", "rt");
	if(fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	dict = create();
	while(readWord(fd, buffer))
	{
		printf("%s\n", buffer);
		add(dict, buffer);
	}

	fclose(fd);

	//print(dict);
	
	printf("\n\n\nFilterDictionary\n\n\n");

	filterDictionary(dict, filter);

	print(dict);

	////////
	//printf("\n#####################nakon filtriranja\n");

	printf("\n#####################ukupan_br_rijeci: %d\n", ukupan_br_rijeci(dict));

	printf("\n#####################najduza_rijec: %s\n", najduza_rijec(dict));

	printf("\n#####################dodaj na pocetak\n");
	dict = dodaj_na_pocetak(dict, "dodaj_na_pocetak");
	print(dict);

	printf("\n#####################dodaj_na_kraj\n");
	dict = dodaj_na_kraj(dict, "dodaj_na_kraj");
	print(dict);

	printf("\n#####################prije_odredenog_elementa\n");
	//prije mathematician
	dict = prije_odredenog_elementa(dict, "prije_odredenog_elementa");
	print(dict);

	printf("\n#####################na_odredeni_indeks\n");
	//na indeks 10
	dict = na_odredeni_indeks(dict, "na_odredeni_indeks");
	print(dict);

	printf("\n#####################ukloni_sa_pocetka\n");
	dict = ukloni_sa_pocetka(dict);
	print(dict);

	printf("\n#####################ukloni_sa_kraja\n");
	dict = ukloni_sa_kraja(dict);
	print(dict);

	printf("\n#####################ukloni_odredenu_rijec\n");
	//prije_odredenog_elementa
	dict = ukloni_odredenu_rijec(dict,"prije_odredenog_elementa");
	print(dict);

	printf("\n#####################ukloni_prvih_5_elemenata\n");
	dict = ukloni_prvih_5_elemenata(dict);
	print(dict);

	printf("\n#####################ukloni_zadnjih_5_elemenata\n");
	dict = ukloni_zadnjih_5_elemenata(dict);
	print(dict);

	printf("\n#####################ukloni_sve_sa_5_znakova\n");
	dict = ukloni_sve_sa_5_znakova(dict);
	print(dict);

	printf("\n#####################ukloni_sve_koje_pocinju_na_C\n");
	dict = ukloni_sve_koje_pocinju_na_C(dict);
	print(dict);
	
	printf("\n#####################dodaj_element_ispred_svake_rici_sa\n");
	dict = dodaj_element_ispred_svake_rici_sa(dict);
	print(dict);

	printf("\n#####################okreni_listu\n");
	dict = okreni_listu(dict);
	print(dict);

	printf("\n#####################zamini_prvi_i_zadnji\n");
	dict = zamini_prvi_i_zadnji(dict);
	print(dict);

	printf("\n#####################sa_kraja_na_poc\n");
	dict = sa_kraja_na_poc(dict);
	print(dict);

	printf("\n#####################sa_poc_na_kraj\n");
	dict = sa_poc_na_kraj(dict);
	print(dict);
	
	printf("\n#####################kopija\n");
	dict = kopija(dict);
	print(dict);

	printf("\n#####################u_novu_listu_kriterij\n");
	dict = u_novu_listu_kriterij(dict);
	print(dict);

	//


	////////


	//destroy(dict);

	/* da zaustavim ako nece
	int a = 0;

	scanf("%d", &a);
	*/
}