# MiniProjetC
https://github.com/Mateowetam/MiniProjetC
## Code César

Beugnet Noah<br>Mangado Mateo<br>Lacomme Tessie<br>Guérin Romain

L'objectif de cette application est de pouvoir crypter un message ou bien décrypter un message en utilisant le codage César.

| Nom de la fonction | Paramètres d'entrée | Paramètres de sortie | Exceptions |
| --- | --- | --- | --- |
| verif | `str` (chaine de caractère) : le message à vérifier | Si le message est valide : <br> `str`<br>Si le message n'est pas valide : <br>0 | Retourne 0 si le message contient des caractères spéciaux ou des nombres. |
| chiffrer | `txt` (chaine de caractère) : le message à crypter<br>`dec` (entier) correspondant à la clé de cryptage | `ch`, la chaine de caractère cryptée  | Aucune exception |
| dechiffrer | `txt` (chaine de caractère) : le message à décrypter<br>`dec` (entier) correspondant à la clé de décryptage | `ch`, la chaine de caractère décryptée | Aucune exception |
| affichage | `message` (chaine de caractère) : le message à afficher | Aucune sortie, car l'affichage s'effectue dans la fonction | Aucune exception | 

## Mode d'emploi

Grâce au makefile, il suffit dans le terminal d'éxécuter `makefile`, puis de lancer `./cesar` pour commencer à chiffrer ou déchiffrer.
Vous avez alors devant vous un menu, où vous choisissez votre action, puis laissez-vous guider ! 



## Fonctions

### chiffrer et dechiffrer

```c
char *chiffrer(char txt[], int dec);
char *dechiffrer(char txt[], int dec);
```

#### Description

La fonction `chiffrer` chiffre le message donné en utilisant le chiffrement César. Le décalage utilisé pour le chiffrement est fourni par le paramètre `dec`.

La fonction `dechiffrer` déchiffre le message donné qui a été précédemment chiffré avec le chiffrement César. Le décalage utilisé pour le déchiffrement est fourni par le paramètre `dec`.

Leurs structures se ressemblent, donc voici les explications communes à ces deux fonctions :

```c
char *ch = malloc(sizeof(char) * (strlen(txt) + 1));
```
Cette ligne de code alloue dynamiquement de la mémoire pour une nouvelle chaîne de caractères `ch` qui sera utilisée pour stocker le message chiffré ou déchiffré.

Ensuite, on parcourt tout le message, caractère par caractère, et on effectue le décalade souhaité.

```c
ch[i] = ((c - 'A' - dec + 26) % 26) + 'A';
```

| --------- | chiffrer | dechiffrer |
| --------- | ------------- |  ------------- |
| Pour les majuscules | ```c ch[i] = ((c - 'A' + dec) % 26) + 'A'; ``` | ```c ch[i] = ((c - 'A' - dec + 26) % 26) + 'A'; ``` |
| Pour les minuscules | ```c ch[i] = ((c - 'a' + dec) % 26) + 'a'; ``` | ```c ch[i] = ((c - 'a' - dec + 26) % 26) + 'a'; ``` |


Dans ces lignes de décalages qu'on trouve dans `chiffrer` et `déchiffrer`, voici les étapes que nous effectuons :

1. `(c - 'A')` : on décale le caractère `c` pour qu'il soit compris entre 0 et 25 (dans l'espace des nombres entiers), c'est-à-dire que 'A' devient 0, 'B' devient 1, etc.

2. `(c - 'A' - dec)` : ici, on soustrait la clé de déchiffrement `dec` au résultat précédent. Cela décale notre lettre chiffrée de `dec` positions vers la gauche dans l'alphabet.

3. `(c - 'A' - dec + 26)` : on ajoute 26 pour s'assurer que le résultat précédent est positif. C'est nécessaire parce que le chiffrement César est circulaire (après 'Z', on revient à 'A'), et en C, l'opérateur modulo `%` pourrait sinon donner un résultat négatif.

4. `((c - 'A' - dec + 26) % 26)` : on utilise le modulo `%` pour garantir que le résultat se situe entre 0 et 25.

5. `((c - 'A' - dec + 26) % 26) + 'A'` : enfin, on ajoute 'A' au résultat pour décaler les nombres entre 0 et 25 de retour à leurs correspondances de lettres ASCII (0 devient 'A', 1 devient 'B', etc.). Le résultat est une lettre majuscule déchiffrée.

Pour les lettres minuscules, il faut simplement changer le `A` en `a`, et pour le chiffrage, nous effectuons la même chose, mais en décalant vers la droite avec `+ dec` !

### verif

```c
int verif(char str[]);
```

#### Description

La fonction `verif` permet de vérifier si le message ne contient que des caractères .

```c
for (i = 0; str[i] != '\0'; i++) {
if (!isalnum(str[i])) {
    return 0;
}
}
return 1;
```
On parcourt tout le message et on retourne 0 à la manière d'un booléen si on ne rencontre pas un caractère alpha-numérique.

### affichage

```c
void affichage(char message[]);
```

#### Description

La fonction `affichage` permet d'afficher un message à l'utilisateur. Cette fonction est utilisée pour afficher le message chiffré ou déchiffré, ou bien pour signaler une erreur.

```c
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
```

La fonction vérifie si la longueur du message est égale à zéro. Si c'est le cas, cela signifie qu'il y a eu une erreur dans le processus de chiffrement ou de déchiffrement, probablement parce que le message d'origine contenait un caractère qui ne peut pas être chiffré ou déchiffré (comme un caractère spécial). Dans ce cas, la fonction affiche un message d'erreur.
Si la longueur du message n'est pas zéro, alors le processus de chiffrement ou de déchiffrement a réussi, et la fonction affiche le message.