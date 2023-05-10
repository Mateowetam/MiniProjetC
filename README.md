# MiniProjetC

## Code César

Beugnet Noah<br>Mangado Mateo<br>Lacomme Tessie<br>Guérin Romain

L'objectif de cette application est de pouvoir crypter un message ou bien décrypter un message en utilisant le codage César.

| Nom de la fonction | Paramètres d'entrée | Paramètres de sortie | Exceptions |
| --- | --- | --- | --- |
| verif | `str` (chaine de caractère) : le message à vérifier | Si le message est valide : <br> `str`<br>Si le message n'est pas valide : <br>0 | Retourne 0 si le message contient des caractères spéciaux ou des nombres. |
| chiffrer | `txt` (chaine de caractère) : le message à crypter<br>`dec` (entier) correspondant à la clé de cryptage | `ch`, la chaine de caractère cryptée  | Aucune exception |
| dechiffrer | `txt` (chaine de caractère) : le message à décrypter<br>`dec` (entier) correspondant à la clé de décryptage | `ch`, la chaine de caractère décryptée | Aucune exception |
| affichage | `message` (chaine de caractère) : le message à afficher | Aucune sortie, car l'affichage s'effectue dans la fonction | Aucune exception | 

## Fonctions

### chiffrer

\```c
char *chiffrer(char txt[], int dec);
\```

#### Description

La fonction `chiffrer` chiffre le message donné en utilisant le chiffrement César. Le décalage utilisé pour le chiffrement est fourni par le paramètre `dec`.

Extrait de code :

\```c
char *ch = malloc(sizeof(char) * (strlen(txt) + 1));
int i = 0;
while (txt[i])
{
  char c = txt[i];
  if (isupper(c)) // Check si c'est une lettre majuscule
  {
    ch[i] = ((c - 'A' + dec) % 26) + 'A';
  }
  else if (islower(c)) // Check si c'est une lettre minuscule
  {
    ch[i] = ((c - 'a' + dec) % 26) + 'a';
  }
  else // si c'est autre chose (comme un chiffre)
  {
    ch[i] = c;
  }
  i++;
}
ch[i] = '\0';
return ch;
\```

### dechiffrer

\```c
char *dechiffrer(char txt[], int dec);
\```

#### Description

La fonction `dechiffrer` déchiffre le message donné qui a été précédemment chiffré avec le chiffrement César. Le décalage utilisé pour le déchiffrement est fourni par le paramètre `dec`.

Extrait de code :

\```c
char *ch = malloc(sizeof(char) * (strlen(txt) + 1));
int i = 0;
while (txt[i])
{
  char c = txt[i];
  if (isupper(c)) // Check si c'est une lettre majuscule
  {
    ch[i] = ((c - 'A' - dec + 26) % 26) + 'A';
  }
  else if (islower(c)) // Check si c'est une lettre minuscule
  {
    ch[i] = ((c - 'a' - dec + 26) % 26) + 'a';
  }
  else // si c'est autre chose (comme un chiffre)
  {
    ch[i] = c;
  }
  i++;
}
ch[i] = '\0';
return ch;
\```



