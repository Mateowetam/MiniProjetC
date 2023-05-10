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

  // Ouvrir le fichier en mode écriture
  FILE *fichier = fopen("resultat.txt", "w");
  if (fichier == NULL) {
    printf("Erreur d'ouverture du fichier\n");
    return;
  }

  char *resultat;
  
  if (verif(message) != 0)
  {
    if (menu == 1)
    {
      fprintf(fichier, "Mode : Chiffrage\n");
      fprintf(fichier, "Message original : %s\n", message);
      fprintf(fichier, "Clé : %d\n", cle);
      resultat = chiffrer(message, cle);
    }
    else
    {
      fprintf(fichier, "Mode : Déchiffrage\n");
      fprintf(fichier, "Message original : %s\n", message);
      fprintf(fichier, "Clé : %d\n", cle);
      resultat = dechiffrer(message, cle);
    }
    
    fprintf(fichier, "Message résultant : %s\n", resultat);
    affichage(resultat);

    free(resultat);
  }
  else {
    printf("Message invalide chacal\n");
    fprintf(fichier, "Erreur : Message invalide\n");
  }

  // Fermer le fichier
  fclose(fichier);
}


int verif(char str[]) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (!isalnum(str[i])) {
      return 0;
    }
  }
  return 1;
}

char *chiffrer(char txt[], int dec)
{
  char *ch = malloc(sizeof(char) * (strlen(txt) + 1));
  dec = dec % 26;
  int i = 0;
  while (txt[i])
  {
    char c = txt[i];
    if (isupper(c))
    {
      ch[i] = ((c - 'A' + dec) % 26) + 'A';
    }
    else if (islower(c))
    {
      ch[i] = ((c - 'a' + dec) % 26) + 'a';
    }
    i++;
  }
  ch[i] = '\0';
  return ch;
}

char *dechiffrer(char txt[], int dec)
{
  char *ch = malloc(sizeof(char) * (strlen(txt) + 1));
  dec = dec % 26;
  int i = 0;
  while (txt[i])
  {
    char c = txt[i];
    if (isupper(c))
    {
      ch[i] = ((c - 'A' - dec + 26) % 26) + 'A';
    }
    else if (islower(c))
    {
      ch[i] = ((c - 'a' - dec + 26) % 26) + 'a';
    }
    i++;
  }
  ch[i] = '\0';
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
