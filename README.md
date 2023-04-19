# MiniProjetC

## Code César

Beugnet Noah<br>Mangado Mateo<br>Lacomme Tessie<br>Guérin Romain

L'objectif de cette application est de pouvoir crypter un message ou bien décrypter un message en utilisant le codage César.

| Nom de la fonction | Paramètres d'entrée | Paramètres de sortie | Exceptions |
| --- | --- | --- | --- |
| verif | `str` (chaine de caractère) : le message à vérifier | Si le message est valide : <br> la même chaine de caractères qu'en entrée.<br>Si le message n'est pas valide : 0 | Retourne 0 si le message contient des caractères spéciaux ou des nombres. |
| chiffrer | `txt` (chaine de caractère) : le message à crypter<br>`dec` (entier) correspondant à la clé de cryptage | `ch`, la chaine de caractère cryptée  | Aucune exception |
| dechiffrer | `txt` (chaine de caractère) : le message à décrypter<br>`dec` (entier) correspondant à la clé de décryptage | `ch`, la chaine de caractère décryptée | Aucune exception |
| affichage | `message` (chaine de caractère) : le message à afficher |  | Aucune exception | 
