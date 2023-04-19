#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cesar.h"
/******************************************************************************
 *  ASR => 4R2.04                                                              *
 *******************************************************************************
 *                                                                             *
 *  N° de Sujet : 3                                                            *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Intitulé : - Chiffrement de messages                                       *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom-prénom1 :  Noah Beugnet                                                *
 *                                                                             *
 *  Nom-prénom2 :  Tessie Lacomme                                              *
 *                                                                             *
 *  Nom-prénom3 :  Romain Guérin                                               *
 *                                                                             *
 *  Nom-prénom4 :  Mateo Mangado                                               *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom du fichier : cesar.c                                                   *
 *                                                                             *
 ******************************************************************************/

void main()
{
  int menu;
  int cle;
  char message[50];

  printf("**************************\n");
  printf(" 1 - Coder un message\n");
  printf(" 2 - Decoder un message\n");
  printf("**************************\n");

  printf("Que voulez-vous faire ?\n");
  scanf("%d", &menu);

  printf("Quel est le message ?\n");
  scanf("%s", message);

  printf("Quelle est la clé ?\n");
  scanf("%d", &cle);

  char *resultat;

  if (verif(message) != 0)
  {
    if (menu == 1)
    {
      resultat = chiffrer(message, 8);
      affichage(message);
    }
    else
    {
      resultat = dechiffrer(message, 8);
    }
    affichage(resultat);

    free(resultat);
  }
  else {
    printf("Message invalide chacal\n");
  }
}

char *verif(char str[])
{
  int i;
  for (i = 0; str[i] != '\0'; i++)
  {
    if (!isalnum(str[i]))
    {
      return 0;
    }
  }
}

char *chiffrer(char txt[], int dec)
{
  char *ch = malloc(sizeof(char) * (strlen(txt) + 1));
  int i = 0;
  while (txt[i])
  {
    char c = txt[i];
    char a;
    if (c < 'a')
    {
      a = 'A';
    }
    else
    {
      a = 'a';
    }
    ch[i] = ((c - a + dec) % 26 + a);
    i++;
  }
  ch[strlen(txt)] = '\0';
  return ch;
}

char *dechiffrer(char txt[], int dec)
{
  char *ch = malloc(sizeof(char) * (strlen(txt) + 1));
  char a;
  int i = 0;
  while (txt[i])
  {
    char c = txt[i];
    if (c < 'a')
    {
      a = 'A';
    }
    else
    {
      a = 'a';
    }
    ch[i] = ((c - a - dec + 26) % 26) + a;
    i++;
  }
  ch[strlen(txt)] = '\0';
  return ch;
}

void affichage(char message[])
{

  printf("*************************\n");
  if (strlen(message) == 0)
  {
    printf("Erreur : il y a un caractère spécial incodable\n");
  }
  else
  {
    printf("Le message : %s\n", message);
  }
  printf("*************************\n");
}
