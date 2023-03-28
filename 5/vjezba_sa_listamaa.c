#include <stdio.h>
#include <stdlib.h>

typedef struct _Element {
	int broj;
	struct _Element* next;
}Element;

void print_list(Element* list)
{
	Element* tmp = list;
	while (tmp)
	{
		printf("%d-> ", tmp->broj);
		tmp = tmp->next;
	}
	printf("Null");
}

Element* dodaj_u_glavu(Element* list, int broj) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = list;
	list = novi;

	return list;

}


Element* dodaj_na_kraj(Element* list,int broj) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = NULL;
	if (list == NULL)
		return novi;
	Element* tmp = list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = novi;
	return list;
}

Element* dodaj_po_redu(Element* list, int broj)
{
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = NULL;
	if (list == NULL)
		return novi;
	if (novi->broj < list->broj)
	{ 
		novi->next = list;
		return novi;
	}
	Element* tmp = list;
	while (tmp->next)
	{
		if (novi->broj < tmp->next->broj)
		{
			novi->next = tmp->next;
			tmp->next = novi;
			return list;
		}
		tmp = tmp->next;
	}
	tmp->next = novi;
	
	return list;
}

Element* brisi_element(Element* list, int broj)
{
	if (!list)
		return NULL;
	if (list->broj == broj)
	{
		Element* brisi = list;
		list = list->next;
		free(brisi);
		return list;
	}
	Element* tmp = list;
	while (tmp->next != NULL)
	{
		if (tmp->next->broj == broj)
		{
			Element* brisi = tmp->next;
			tmp->next = tmp->next->next;
			free(brisi);
			return list;
		}
		tmp = tmp->next;
	}
	return list;
}

int main()
{
	/*
	Element* list;
	Element a, b, c;
	a.broj = 1;

	b.broj = 2;
	c.broj = 3;
	c.next = NULL;
	b.next = &c;
	a.next = &b;
	list = &a;

	Element* tmp = list->next->next;
	list->next->next = NULL;
	tmp->next = list;
	list = tmp;

	print_list(list);
	*/

	Element* list=NULL;

	list = dodaj_na_kraj(list,5);
	list = dodaj_na_kraj(list, 6);
	list = dodaj_na_kraj(list, 8);
	list = dodaj_u_glavu(list, 3);
	//print_list(list);
	list = dodaj_na_kraj(list, 10);
	list = dodaj_po_redu(list, 7);
	list = brisi_element(list, 6);
	print_list(list);

}
