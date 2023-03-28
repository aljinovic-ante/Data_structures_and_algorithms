#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	
	HashTable* hash = (HashTable*)malloc(sizeof(HashTable));
	hash->table = (Bin**)malloc(sizeof(Bin*) * size);
	hash->size = size;
	hash->load = 0;

	for (int i = 0; i < (hash->size) ; i++)
		hash->table[i] = NULL;

	return hash;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu

	int i = hash(word) % ht->size;

	Bin* novi = (Bin*)malloc(sizeof(Bin));
	novi->word = word;
	novi->next = ht->table[i];

	

	ht->table[i] = novi;
	ht->load++;
}

int Get(HashTable *ht, char *word)
{
	int i = hash(word) % ht->size;

	Bin* elem = ht->table[i];

	while (elem != NULL)
	{
		if (!strcmp(word, elem->word))
			return 1;
		else
			elem = elem->next;
	}

	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)

	for (int i = 0; i < (ht->size); i++)
	{
		Bin* elem = ht->table[i];

		while (elem != NULL)
		{
			Bin* obrisi = elem;
			elem = elem->next;
			free(obrisi->word);
			free(obrisi);

		}
	}

	free(ht->table);
	free(ht);

}