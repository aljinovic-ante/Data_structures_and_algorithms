#include <stdio.h>
#include <stdlib.h>

typedef struct _Element {
	int broj;
	struct _Element* next;
}Element; 
/*
dodaj_u_glavu
print
dodaj_na_kraj

dodaj_po_redu
brisi_elem
brisi listu
*/

Element* dodaj_u_glavu(Element* lst, int nb) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = nb;
	novi->next = lst;
	lst = novi;
	return lst;
}

void print(Element* lst)
{
	while(lst != NULL)
	{
		printf("%d->", lst->broj);
		lst = lst->next;
	}
	printf("NULL\n");
}

Element* dodaj_na_kraj(Element* lst, int nb)
{
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = nb;
	novi->next = NULL;
	if (lst == NULL)
		return novi;
	Element* tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = novi;
	return lst;
}

Element* dodaj_po_redu(Element* lst, int nb)
{
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->next = NULL;
	novi->broj = nb;
	if (lst == NULL)
		return novi;
	if (novi->broj < lst->broj)
	{
		novi->next = lst;
		return novi;
	}
	Element* tmp = lst;
	while (tmp->next != NULL)
	{
		if (novi->broj < tmp->next->broj)
		{
			novi->next = tmp->next;
			tmp->next = novi;
			return lst;
		}
		tmp = tmp->next;
	}
	tmp->next = novi;
	return lst;
}

Element* brisi_glavu(Element* lst)
{
	if (lst == NULL)
		return NULL;
	Element* brisi = lst;
	lst = lst->next;
	free(brisi);
	return lst;
}

Element* brisi_listu(Element* lst)
{
	while (lst != NULL)
	{
		Element* brisi = lst;
		lst = lst->next;
		free(brisi);
	}
}

Element* brisi_element(Element* lst, int nb)
{
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = nb;
	novi->next = NULL;
	if (lst == NULL)
		return NULL;
	if (lst->broj == novi->broj)
	{
		Element* obrisi = lst;
		lst = lst->next;
		free(obrisi);
		return lst;
	}
	Element* tmp = lst;
	while (tmp->next != NULL)
	{
		if (tmp->next->broj == novi->broj)
		{
			Element* obrisi = tmp->next;
			tmp->next = tmp->next->next;
			free(obrisi);
		}
		tmp = tmp->next;
	}

	return lst;

}

Element* spoji_listu(Element* lst, Element* lst2)
{
	if (lst == NULL)
		return lst2;
	Element* tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = lst2;
	return lst;
}

Element* okreni_listu(Element* lst)
{
	Element* nova_lista = NULL;
	while (lst != NULL)
	{
		Element* tmp = lst;
		lst = lst->next;
		tmp->next = nova_lista;
		nova_lista = tmp;
	}

	return nova_lista;
}

Element* okreni_list(Element* lst)
{
	Element* nova_lista = NULL;
	while (lst != NULL)
	{
		Element* tmp = lst;
		lst = lst->next;
		tmp->next = nova_lista;
		nova_lista = tmp;
	}
	return nova_lista;
}

Element* brisi_parne(Element* lst)
{
	if (lst == NULL)
		return NULL;

	Element* tmp = lst;

	

	while (tmp->next != NULL)
	{
		if (tmp->next->broj % 2 == 0)
		{
			Element* brisi = tmp->next;
			tmp->next = tmp->next->next;
			free(brisi);
		}
		else
			tmp = tmp->next;
	}

	if (lst->broj % 2 == 0)
	{
		Element* obrisi = lst;
		lst = lst->next;
		free(obrisi);
	}
	return lst;

}

Element* kopija(Element* lst)
{
	Element* copy = NULL;
	Element* kraj = NULL;
	if (lst != NULL)
	{
		copy = (Element*)malloc(sizeof(Element));
		copy->broj = lst->broj;
		copy->next = NULL;
		kraj = copy;
	}
	lst = lst->next;
	while (lst != NULL)
	{
		Element* tmp = (Element*)malloc(sizeof(Element));
		tmp->broj = lst->broj;
		tmp->next = NULL;
		kraj->next = tmp;
		kraj = kraj->next;
		lst = lst->next;
	}
	return copy;
} 


int main()
{
	Element* lst=NULL;
	Element* lst2=NULL;
	lst = dodaj_u_glavu(lst, 2);
	lst2 = dodaj_u_glavu(lst2, 2);
	lst = dodaj_u_glavu(lst, 1);
	lst = dodaj_u_glavu(lst, 1);
	lst2 = dodaj_na_kraj(lst2, 5);
	lst2 = dodaj_na_kraj(lst2, 5);
	lst = dodaj_na_kraj(lst, 9);
	lst = dodaj_na_kraj(lst, 6);
	lst = dodaj_na_kraj(lst, 6);
	lst2 = dodaj_na_kraj(lst2, 3);
	lst2 = dodaj_na_kraj(lst2, 2);
	lst2 = dodaj_na_kraj(lst2, 2);
	lst = dodaj_po_redu(lst, 4);
	lst2 = dodaj_po_redu(lst2, 1);
	lst2 = dodaj_po_redu(lst2, 1);

	print(lst);
	print(lst2);

	lst = brisi_glavu(lst);
	lst2 = brisi_element(lst2,5);
	print(lst);
	print(lst2);

	//lst = brisi_listu(lst);
	//print(lst);
	//print(lst2);
	printf("spoji liste:\n");
	lst = spoji_listu(lst, lst2);
	print(lst);
	printf("okreni listu:\n");
	lst = okreni_listu(lst);
	print(lst);
	printf("brisi parne:\n");
	lst = brisi_parne(lst);
	print(lst);
	printf("kopija\n");
	Element* copy = kopija(lst);
	print(copy);
}