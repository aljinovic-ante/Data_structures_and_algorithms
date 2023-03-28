#include "dictionary.h"
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

    if ( (w->count >= 5 && w->count <= 10) && strlen(w->word) > 3) 
        return 1;
    
    return 0;
  
}