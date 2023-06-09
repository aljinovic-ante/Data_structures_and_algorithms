#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	
	BSTree tree = NULL;
	return tree;

	// return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.

	if (*bst == NULL)
	{
		*bst = (BSTree)malloc(sizeof(Node));
		(*bst)->right = NULL;
		(*bst)->left = NULL;
		(*bst)->word = word;
	}
	else
	{
		if (!strcmp((*bst)->word, word))
			free(word);
		else if (strcmp((*bst)->word, word) > 0)
			AddNode((&(*bst)->left), word);
		else if (strcmp((*bst)->word, word) < 0)
			AddNode((&(*bst)->right), word);
	}

}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
	int left_max = 0;
	int right_max = 0;

	if (bst == NULL)
		return 0;

	left_max = BSTHeight(bst->left);
	right_max = BSTHeight(bst->right);

	if (left_max > right_max)
		return left_max + 1;
	return right_max + 1;

	
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)

	if (bst == NULL)
		return;

	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);


}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)

	if (bst == NULL)
		return;

	fprintf(fd, "%s ", bst->word);

	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)

	if (bst == NULL)
		return;


	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().


	BSTree tree = NewBSTree();
	char word[1024];

	while (fscanf_s(fd, "%s", word) != EOF)
		AddNode(&tree, _strdup(word));

	return tree;
	//return NULL;
}
