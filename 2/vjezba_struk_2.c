#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
}Tocka2D;

typedef struct {
	float x, y,z;
}Tocka3D;

Tocka3D* pretvori(Tocka2D* t, int n)
{
	Tocka3D* nt = (Tocka3D*)malloc(sizeof(Tocka3D) * n);

	for (int i = 0; i < n; i++)
	{
		nt[i].x = t[i].x;
		nt[i].y = t[i].y;
		nt[i].z = t[i].x + t[i].y;
	}

	return nt;
}

int main()
{
	Tocka2D t[] = { {1,3},{-3,2},{5,-2} };

	Tocka3D* nt = pretvori(&t, sizeof(t) / sizeof(t[0]));
	
	for (int i = 0; i < sizeof(t) / sizeof(t[0]); i++)
	{
		printf("%f %f %f\n", nt[i].x, nt[i].y, nt[i].z);
	}

}

/*
Tocka3D* pretvori(Tocka2D* t)
{
	Tocka3D* nt = (Tocka3D*)malloc(sizeof(Tocka3D));
	nt->x = t->x;
	nt->y = t->y;
	nt->z = t->x + t->y;

	return nt;
}

int main()
{
	Tocka2D t[] = {1,3};

	Tocka3D* nt = pretvori(&t);

	printf("%f %f %f", nt->x, nt->y, nt->z);
}*/