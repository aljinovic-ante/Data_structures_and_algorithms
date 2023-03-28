#include "dictionary2.h"
#include <malloc.h>
#include <string.h>

Dictionary create() {

    Dictionary dict = (Word*)malloc(sizeof(Word));
    dict->count = 0;
    dict->next = NULL;
    return dict;

}

void add(Dictionary dict, char* str) {

    Dictionary new = dict;

    while (new->next != NULL) {

        if ( !strcmp(new->next->word, str) ) {
            new->next->count++;
            return;
        }

        else if (strcmp(str, new->next->word) < 0) {
            Dictionary novi = (Dictionary)malloc(sizeof(Word));
            novi->word = strdup(str);
            novi->count = 1;
            novi->next = new->next;
            new->next = novi;
            return;
        }

        new = new->next;
    }

    new->next = (Dictionary)malloc(sizeof(Word));
    new->next->word = strdup(str);
    new->next->count = 1;
    new->next->next = NULL;

}

void print(Dictionary dict) {

    dict = dict->next;

    while (dict) {

       
        if (dict->count >= 100)
            printf("%d - %s\n", dict->count, dict->word);
        else if (dict->count >= 10)
            printf("%d  - %s\n", dict->count, dict->word);
        else
            printf("%d   - %s\n", dict->count, dict->word);


        dict = dict->next;
    }

}

void destroy(Dictionary dict) {

    while (dict != NULL) {
        Dictionary obrisi = dict;
		dict = dict->next;
		free(obrisi->word);
        free(obrisi);
    }

}
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w)) {

    if (indict->next == NULL)
        return NULL;

    Dictionary tmp = indict;

    while (tmp->next != NULL) {

        if (filter(tmp->next) == 1) {
            tmp = tmp->next;

        }
        else {
            Dictionary obrisi = tmp->next;
            tmp->next = tmp->next->next;
            //free(obrisi->word);
            free(obrisi);
        }

    }

    return indict;
}
int filter(Word* w) {

    if ( (w->count > 5 && w->count < 10) && strlen(w->word) > 3) 
        return 1;
    
    return 0;
  
}

int ukupan_br_rijeci(Dictionary dict)
{
    int br = 0;
    dict = dict->next;
    while (dict != NULL)
    {
        br = br + (dict->count);
        dict = dict->next;
    }

    return br;
}

char* najduza_rijec(Dictionary dict)
{
    Dictionary tmp = dict;
    tmp = tmp->next;
    char* str = strdup(tmp->word);
    while (tmp != NULL)
    {
        if (strlen(tmp->word) > strlen(str))
        {
            str = strdup(tmp->word);
        }
        tmp = tmp->next;
    }

    return str;
}

Dictionary dodaj_na_pocetak(Dictionary dict, char* str)
{
    Dictionary rijec = (Dictionary)malloc(sizeof(Word));
    rijec->count = 1;
    rijec->word = strdup(str);
    rijec->next = dict->next;
    dict->next = rijec;
    return dict;
}

Dictionary dodaj_na_kraj(Dictionary dict, char* str)
{
    Dictionary rijec = (Dictionary)malloc(sizeof(Word));
    rijec->count = 1;
    rijec->word = strdup(str);
    rijec->next =NULL;
    Dictionary tmp = dict;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = rijec;

    return dict;
}

Dictionary prije_odredenog_elementa(Dictionary dict, char* str)
{
    char elem[1024] = "mathematician";
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        if (!strcmp(tmp->next->word, elem))
        {
            Dictionary rijec = (Dictionary)malloc(sizeof(Word));
            rijec->word = strdup(str);
            rijec->count = 1;
            rijec->next = tmp->next;
            tmp->next = rijec;
            return dict;
        }
        tmp = tmp->next;
    }

    return dict;
}

Dictionary na_odredeni_indeks(Dictionary dict, char* str)
{
    int indeks = 20;
    int br = 0;
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        br++;
        if (br == indeks)
        {
            Dictionary rijec = (Dictionary)malloc(sizeof(Word));
            rijec->word = strdup(str);
            rijec->count = 1;
            rijec->next = tmp->next;
            tmp->next = rijec;
            return dict;
        }
        tmp = tmp->next;
    }

    return dict;
}

Dictionary ukloni_sa_pocetka(Dictionary dict)
{
    Dictionary obrisi = dict->next;
    dict->next = dict->next->next;
    free(obrisi->word);
    free(obrisi);

    return dict;
}

Dictionary ukloni_sa_kraja(Dictionary dict)
{
    Dictionary tmp = dict;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    Dictionary obrisi = tmp->next;
    tmp->next = tmp->next->next;
    free(obrisi->word);
    free(obrisi);

    return dict;
}

Dictionary ukloni_odredenu_rijec(Dictionary dict, char* str)
{
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        if (!strcmp(tmp->next->word, str))
        {
            Dictionary obrisi = tmp->next;
            tmp->next = tmp->next->next;
            free(obrisi->word);
            free(obrisi);
        }
        else
            tmp = tmp->next;
    }

    return dict;
}

Dictionary ukloni_prvih_5_elemenata(Dictionary dict)
{
    int br = 0;
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        if (br == 5)
            return dict;
        Dictionary obrisi = tmp->next;
        tmp->next = tmp->next->next;
        free(obrisi->word);
        free(obrisi);
        br++;
    }

    return dict;
}

Dictionary ukloni_sve_sa_5_znakova(Dictionary dict)
{
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        if (strlen(tmp->next->word) == 4)
        {
            Dictionary obrisi = tmp->next;
            tmp->next = tmp->next->next;
            free(obrisi->word);
            free(obrisi);
        }
        else
            tmp = tmp->next;
    }

    return dict;
}

Dictionary ukloni_zadnjih_5_elemenata(Dictionary dict)
{
    Dictionary br = dict;
    int brojac = 0;
    br = br->next;
    while (br != NULL)
    {
        brojac++;
        br = br->next;
    }
    int od = brojac - 5;
    int a = 0;
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        a++;
        if (a > od)
        {
            Dictionary obrisi = tmp->next;
            tmp->next = tmp->next->next;
            free(obrisi->word);
            free(obrisi);
        }
        else
            tmp = tmp->next;
    }
    return dict;
}

Dictionary ukloni_sve_koje_pocinju_na_C(Dictionary dict)
{
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        char* str = strdup(tmp->next->word);
        if (str[0] == 'c')
        {
            Dictionary obrisi = tmp->next;
            tmp->next = tmp->next->next;
            free(obrisi->word);
            free(obrisi);
        }
        else
            tmp = tmp->next;
    }

    return dict;
}

Dictionary dodaj_element_ispred_svake_rici_sa(Dictionary dict)
{
    Dictionary tmp = dict;
    char str[1024] = "DODANO";
    while (tmp->next != NULL)
    {
        if (tmp->next->count == 7)
        {
            Dictionary rijec = (Dictionary)malloc(sizeof(Word));
            rijec->count = 1;
            rijec->word = strdup(str);
            rijec->next = tmp->next;
            tmp->next = rijec;
            tmp = tmp->next->next;
        }
        else
            tmp = tmp->next;
    }

    return dict;
}

Dictionary okreni_listu(Dictionary dict)
{
    Dictionary tmp = dict;
    tmp = tmp->next;
    Dictionary okrenuta = NULL;
    while (tmp != NULL)
    {
        Dictionary elem = tmp;
        tmp = tmp->next;
        elem->next = okrenuta;
        okrenuta = elem;
    }
    dict->next = okrenuta;
    okrenuta = dict;

    return dict;
}

Dictionary zamini_prvi_i_zadnji(Dictionary dict)
{
    Dictionary tmp = dict;
    Dictionary prvi = dict->next;
    Dictionary drugi = dict->next->next;
    Dictionary zadnji;

    while (tmp->next->next != NULL)
        tmp = tmp->next;

    zadnji = tmp->next;
    tmp->next = prvi;
    prvi->next = NULL;
    zadnji->next = drugi;
    dict->next = zadnji;

    return dict;
}

Dictionary sa_kraja_na_poc(Dictionary dict)
{
    Dictionary tmp = dict;
    Dictionary zadnji;

    while (tmp->next->next != NULL)
        tmp = tmp->next;

    zadnji = tmp->next;
    tmp->next = tmp->next->next;

    zadnji->next = dict->next;
    dict->next = zadnji;

    return dict;
}

Dictionary sa_poc_na_kraj(Dictionary dict)
{
    Dictionary tmp = dict;
    Dictionary prvi = dict->next;
    dict->next = dict->next->next;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = prvi;
    prvi->next = NULL;

    return dict;
}

Dictionary kopija(Dictionary dict)
{
    Dictionary copy = NULL;
    Dictionary kraj = NULL;
    Dictionary tmp = dict->next;
    if (tmp != NULL)
    {
        copy = (Dictionary)malloc(sizeof(Word));
        copy->count = tmp->count;
        copy->word = strdup(tmp->word);
        copy->next = NULL;
        kraj = copy;
    }
    tmp = tmp->next;
    while (tmp != NULL)
    {
        Dictionary rijec = (Dictionary)malloc(sizeof(Word));
        rijec->count = tmp->count;
        rijec->word = strdup(tmp->word);
        rijec->next = NULL;
        kraj->next = rijec;
        kraj = kraj->next;
        tmp = tmp->next;
    }
    dict->next = copy;
    copy = dict;

    return copy;
}

Dictionary krit(Dictionary lst, Dictionary elem)
{
    Dictionary novi = (Dictionary)malloc(sizeof(Word));
    novi->count = elem->count;
    novi->word = strdup(elem->word);
    novi->next = NULL;
    if (lst == NULL)
        return novi;

    Dictionary tmp = lst;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = novi;
    novi->next = NULL;

    return lst;
}



Dictionary u_novu_listu_kriterij(Dictionary dict)
{
    Dictionary lst = NULL;
    Dictionary tmp = dict;
    while (tmp != NULL)
    {
        if (tmp->count ==9)
        {
            lst = krit(lst, tmp);
        }
        tmp = tmp->next;
    }
    dict->next = lst;
    lst = dict;

    return lst;
}