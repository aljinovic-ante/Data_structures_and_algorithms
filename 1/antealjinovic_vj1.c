#include <stdio.h>

int mystrlen(char str[])
{
	char* p = str;
	int brojac = 0;

	while (*p)
	{
		brojac++;
		p++;
	}

	return brojac;
}

void mystrcpy(char str[], char str2[])
{
	int i, j;
	for (i = 0; i < strlen(str2); i++)
	{
		str[i] = str2[i];
	}

	printf("%s", str);
}

void mystrcat(char str[], char str2[])
{
	int br = strlen(str);
	int br2 = strlen(str2);
	int i = 0;
	int pom = br;

	for (br; br < (pom + br2); br++)
	{
		str[br] = str2[i];
		i++;
	}

	printf("%s", str);
}




void reverse(char str[], char str2[])
{
	int i, j;

	for (i = 0; i < strlen(str2); i++)
	{
		str[i] = str2[strlen(str2) - i - 1];

	}

	printf("%s", str);
}

int mystrcmp(char str[], char str2[])
{
	int rez = 0;
	int i = 0;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] > str2[i])
		{
			rez = -1;
			break;
		}
		else if (str[i] < str2[i])
		{
			rez = 1;
			break;
		}
		else if (str[i] == str2[i])
			continue;
	}

	return rez;
}

/*
    //                0123456789012
	char str3[256] = "xxxabaaaaabaa";
	//                0123
	char str4[256] = "aaab";
*/
char* mystrstr(char *str3, char *str4)
{
	while (*str3)
	{
		char* pocetak = str3;
		char* sub = str4;

		while ((*str3 && *sub) & (*str3 == *sub))
		{
			str3++;
			sub++;
		}

		if (!*sub)
			return pocetak;

		str3 = pocetak + 1;
	}

	return NULL;

}

int main()
{
	//               0123
	char str[256] = "ante";
	//                01234
	char str2[256] = "balun";
	//                012345678
	char str3[256] = "xxxabaaaaabaa";
	//                0123
	char str4[256] = "aaab";


	//printf("%d", mystrlen(str3));
	//mystrcpy(str, str2);
	//mystrcat(str, str3);
	//reverse(str, str3);
	//printf("%d", mystrcmp(str, str2));
	


	char* pok = mystrstr(str3, str4);
	printf("substr i ostatak je: %s", pok);




	return 0;

}