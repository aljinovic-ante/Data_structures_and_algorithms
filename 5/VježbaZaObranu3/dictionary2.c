#include "dictionary2.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

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

        if(dict->count >= 100)
            printf("%d - %s\n", dict->count, dict->word );
        else if(dict->count >= 10)
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
    dict = dict->next;
    int br = 0;
    while (dict != NULL)
    {
        br = br + (dict->count);
        dict = dict->next;
    }

    return br;
}

char* najduza_rijec(Dictionary dict)
{
    dict = dict->next;
    char* str = strdup(dict->word);
    while (dict != NULL)
    {
        if (strlen(dict->word) > strlen(str))
        {
            str = strdup(dict->word);
        }
        dict = dict->next;
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
    rijec->next = NULL;
    Dictionary tmp = dict;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = rijec;

    return dict;

}

Dictionary prije_odredenog_elementa(Dictionary dict, char* str)
{
    char odr_ele[1024] = "mathematician";
    Dictionary rijec = (Dictionary)malloc(sizeof(Word));
    rijec->word = strdup(str);
    rijec->count = 1;
    rijec->next = NULL;
    Dictionary tmp = dict;

    while (tmp->next != NULL)
    {
        if (!strcmp(tmp->next->word, odr_ele))
        {
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
    int indeks = 10; 
    int br = 0;
    Dictionary rijec = (Dictionary)malloc(sizeof(Word));
    rijec->word = strdup(str);
    rijec->count = 1;
    rijec->next = NULL;
    Dictionary tmp = dict;

    while (tmp->next != NULL)
    {
        if (br == indeks)
        {
            rijec->next = tmp->next;
            tmp->next = rijec;
            return dict;
        }
        br++;
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
    {
        tmp = tmp->next;
    }
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
            return dict;
        }
        tmp = tmp->next;
    }

    return dict;
}

Dictionary ukloni_prvih_5_elemenata(Dictionary dict)
{
    Dictionary tmp = dict;
    int br = 0;
    while (tmp->next != NULL && br<5)
    {
        br++;
        Dictionary obrisi = tmp->next;
        tmp->next = tmp->next->next;
        free(obrisi->word);
        free(obrisi);
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
    Dictionary tmp = dict;
    int dokle = 0;
    tmp = tmp->next;
    while (tmp != NULL)
    {
        dokle++;
        tmp = tmp->next;
    }
    int od = dokle - 5;
    int br = 0;
    Dictionary tmp2 = dict;
    while (tmp2->next != NULL)
    {
        br++;
        if (br > od && br <= dokle)
        {
            Dictionary obrisi = tmp2->next;
            tmp2->next = tmp2->next->next;
            free(obrisi->word);
            free(obrisi);
        }
        else
            tmp2 = tmp2->next;
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
    char str[1024] = "DODANO";
    Dictionary tmp = dict;
    while (tmp->next != NULL)
    {
        if (strlen(tmp->next->word) == 8)
        {
            Dictionary rijec = (Dictionary)malloc(sizeof(Word));
            rijec->count = 1;
            rijec->next = tmp->next;
            rijec->word = strdup(str);
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
    Dictionary okrenuta = NULL;
    Dictionary tmp = dict;
    tmp = tmp->next;
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

//Dictionary zamini_prvi_i_zadnji(Dictionary dict)
//{
//    Dictionary tmp = dict;
//    Dictionary first = dict;
//    Dictionary last=NULL;
//    Dictionary drugi = dict->next->next;
//
//    while (tmp->next->next != NULL)
//    {
//        tmp = tmp->next;
//    }
//
//    last = tmp->next;
//    tmp->next = first->next;
//    tmp = tmp->next;
//    tmp->next = NULL;
//    dict->next = last;
//    last->next = drugi;
//
//    return dict;
//}

Dictionary zamini_prvi_i_zadnji(Dictionary dict)
{
    Dictionary tmp = dict;
    Dictionary prvi = dict->next;
    Dictionary drugi = dict->next->next;
    Dictionary zadnji;

    while (tmp->next->next != NULL)
        tmp = tmp->next;

    zadnji = tmp->next;
    prvi->next = NULL;
    tmp->next = prvi;

    zadnji->next = drugi;
    dict->next = zadnji;

    return dict;
}


Dictionary sa_kraja_na_poc(Dictionary dict)
{
    Dictionary tmp = dict;

    while (tmp->next->next != NULL)
        tmp = tmp->next;

    Dictionary zadnji = tmp->next;
    tmp->next = NULL;

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
/*


Dictionary dodaj_na_kraj2(Dictionary lst,Dictionary elem)
{
    Dictionary novi = (Dictionary)malloc(sizeof(Word));
    novi->count = elem->count;
    novi->word = strdup(elem->word);
    novi->next = NULL;

 

    if (lst == NULL)
    {
        return novi;
    }
    Dictionary tmp = lst;

    while (tmp->next != NULL)
        tmp = tmp->next;
 
    tmp->next = novi;

    
   return lst;
  
}

Dictionary u_novu_listu_kriterij(Dictionary dict)
{
    Dictionary tmp = dict;
    Dictionary lst = NULL;
    int flag = 0;
    char str[1024];
    Dictionary prvi=NULL;


    while (tmp != NULL)
    {
        if (tmp->count == 9)
        {
            if (!flag)
            {
                prvi = tmp;
                flag = 1;
            }
            lst = dodaj_na_kraj2(lst, tmp);
            
            
        }
        tmp = tmp->next;
    }
    prvi->next = lst->next;
    lst->next = prvi;
    return lst;
}
*/

Dictionary kopija(Dictionary dict)
{
    Dictionary copy = NULL;
    Dictionary kraj = NULL;
    Dictionary tmp = dict;
    tmp = tmp->next;
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
        Dictionary novi = (Dictionary)malloc(sizeof(Word));
        novi->count = tmp->count;
        novi->word = strdup(tmp->word);
        novi->next = NULL;
        kraj->next = novi;
        kraj = kraj->next;
        tmp = tmp->next;

    }
    
    dict->next = copy;
    copy = dict;
    return copy;
}
/*
Dictionary sa_kraja_na_poc(Dictionary dict)
{
    Dictionary tmp = dict;
    Dictionary prvi = dict->next;
    Dictionary zadnji;

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    zadnji = tmp->next;
    tmp->next = tmp->next->next;
    zadnji->next = prvi;
    dict->next = zadnji;

    return dict;

}

Dictionary sa_poc_na_kraj(Dictionary dict)
{
    Dictionary tmp = dict;
    Dictionary prvi = dict->next;
    dict->next = dict->next->next;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    prvi->next = NULL;
    tmp->next = prvi;

    return dict;
}*/
