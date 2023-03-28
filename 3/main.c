#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float x, y, z;
}Vrh;

typedef struct {
	Vrh normala;
	Vrh vrh_x, vrh_y, vrh_z;
	unsigned short boja;
}Trokut;

typedef struct {
	Trokut* niz;
	int n;
}Objekt3D;

Objekt3D* citanje_objekta()	
{
	FILE* fd = fopen("primjerbin.stl", "r");

	if (!fd)
		perror("greska");

	fseek(fd, 80, SEEK_SET);


	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));

	int n;

	fread(&n, sizeof(int), 1, fd);

	objekt->n = n;

	Trokut* trok = (Trokut*)malloc(objekt->n * sizeof(Trokut));


	int i;
	for (i = 0; i < (objekt->n); i++)
		fread(&(trok[i]), 50, 1, fd);

	objekt->niz = trok;

	fclose(fd);

	return objekt;
}



void objekt3d_u_txtstl(Objekt3D* objekt)
{
	FILE* fd = fopen("objekt3d_u_txt.stl", "wt");

	fprintf(fd, "solid ime\n");

	int i;
	for (i = 0; i < (objekt->n); i++)
	{

		fprintf(fd, "facet normal %f %f %f\n", objekt->niz[i].normala.x, objekt->niz[i].normala.y, objekt->niz[i].normala.z);
		fprintf(fd, "outer loop\n");
		fprintf(fd, "vertex %f %f %f\n", objekt->niz[i].vrh_x.x, objekt->niz[i].vrh_x.y, objekt->niz[i].vrh_x.z);
		fprintf(fd, "vertex %f %f %f\n", objekt->niz[i].vrh_y.x, objekt->niz[i].vrh_y.y, objekt->niz[i].vrh_y.z);
		fprintf(fd, "vertex %f %f %f\n", objekt->niz[i].vrh_z.x, objekt->niz[i].vrh_z.y, objekt->niz[i].vrh_z.z);
		fprintf(fd, "endloop\n");
		fprintf(fd, "endfacet\n");
	}

	fprintf(fd, "end solid\n");

	fclose(fd);


}

void objekt3d_u_binstl(Objekt3D* objekt)
{
	FILE* fd = fopen("objekt3d_u_bin.stl", "wb");

	char zaglavlje[80] = { 0 };

	fwrite(zaglavlje, sizeof(char), 80, fd);
	fwrite(&(objekt->n), sizeof(int), 1, fd);

	int i;

	for (i = 0; i < (objekt->n); i++)
	{
		fwrite(&(objekt->niz[i]), 50, 1, fd);
	}

	fclose(fd);
}

void objekt3d_brisanje(Objekt3D* objekt)
{
	free(objekt->niz);
	free(objekt);
}

int main()
{

	Objekt3D* objekt_m = citanje_objekta();

	objekt3d_u_binstl(objekt_m);
	objekt3d_u_txtstl(objekt_m);
	objekt3d_brisanje(objekt_m);

	return 0;
}