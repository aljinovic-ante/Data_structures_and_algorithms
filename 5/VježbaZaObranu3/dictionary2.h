#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct Word {
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next; 
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w));

int filter(Word* w);

///////////////////////////////
///////////////////////////////
///////////////////////////////
int ukupan_br_rijeci(Dictionary dict);

char* najduza_rijec(Dictionary dict);

Dictionary dodaj_na_pocetak(Dictionary dict, char* str);

Dictionary dodaj_na_kraj(Dictionary dict, char* str);

Dictionary prije_odredenog_elementa(Dictionary dict, char* str);

Dictionary na_odredeni_indeks(Dictionary dict, char* str);

Dictionary ukloni_sa_pocetka(Dictionary dict);

Dictionary ukloni_sa_kraja(Dictionary dict);

Dictionary ukloni_odredenu_rijec(Dictionary dict,char* str);

Dictionary ukloni_prvih_5_elemenata(Dictionary dict);

Dictionary ukloni_sve_sa_5_znakova(Dictionary dict);

Dictionary ukloni_zadnjih_5_elemenata(Dictionary dict);

Dictionary ukloni_sve_koje_pocinju_na_C(Dictionary dict);

Dictionary dodaj_element_ispred_svake_rici_sa(Dictionary dict);

Dictionary okreni_listu(Dictionary dict);

Dictionary zamini_prvi_i_zadnji(Dictionary dict);

Dictionary sa_kraja_na_poc(Dictionary dict);

Dictionary sa_poc_na_kraj(Dictionary dict);

Dictionary u_novu_listu_kriterij(Dictionary dict);

Dictionary kopija(Dictionary dict);


#endif