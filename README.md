# MiniProjetC

##Code César

Beugnet Noah
Mangado Matéo
Lacomme Tessie
Guérin Romain

L'objectif de cette application est de pouvoir crypter un message ou bien decrypter un message en utilisant le codage César


Fonction :

- verif 	-> 	Entrée : 	chaine de caractère str contenant le message
					Cette fonction permet de vérifier si le message ne contient pas de caractère spécial ou de nombre
			Sortie : 	si le message utilise seulement des caractères pouvant être crypter (pas de caractères spéciaux ou de nombre)
					-> retourne la même chaine de caractère qu'en entrée
				Sinon
					-> retourne un 0 signifiant que le message ne peut pas être codé

- chiffrer 	->	Entrée :	Chaine de caractère txt et un entier dec
					Cette fonction permet de crypter le message txt en code César avec la clé dec
			Sortie : 	retourne la chaine de caractère crypter 

- dechiffrer ->	Entrée : 	Chaine de caractère txt et un entier dec
					Cette fonction permet de décrypter le message txt codé en César avec la clé dec
			Sortie : 	retourne la chaine de caractère décrypter

- affichage	->	Entrée : 	chaine de caractère message contenant le message (crypté ou décrypté) à afficher
					Cette fonction permet d'afficher le message dans la console
			Sortie :	retourne rien

