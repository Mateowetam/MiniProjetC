# MiniProjetC

## Code César

Beugnet Noah
Mangado Mateo
Lacomme Tessie
Guérin Romain

L'objectif de cette application est de pouvoir crypter un message ou bien décrypter un message en utilisant le codage César.


Fonction :

- verif 	-> 	Entrée : 	Chaine de caractère "str" contenant le message.
					Cette fonction permet de vérifier si le message ne contient pas de caractère spécial ou de nombre.
			Sortie : 	Si le message utilise seulement des caractères pouvant être cryptés (pas de caractères spéciaux ou de nombres).
					-> retourne la même chaine de caractères qu'en entrée.
				Sinon
					-> retourne un 0 signifiant que le message ne peut pas être codé.

- chiffrer 	->	Entrée :	Chaine de caractère txt et un entier "dec".
					Cette fonction permet de crypter le message txt en code César avec la clé "dec".
			Sortie : 	retourne la chaine de caractère cryptée.

- dechiffrer ->	Entrée : 	Chaine de caractère txt et un entier "dec".
					Cette fonction permet de décrypter le message txt codé en César avec la clé "dec".
			Sortie : 	retourne la chaine de caractère décryptée.

- affichage	->	Entrée : 	Chaine de caractère "message" contenant le message (cryptée ou décryptée) à afficher.
					Cette fonction permet d'afficher le message dans la console.
			Sortie :	Ne retourne rien.
			
			## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Collaboration](#collaboration)
5. [FAQs](#faqs)
### General Info
***
Write down the general informations of your project. It is worth to always put a project status in the Readme file. This is where you can add it. 
### Screenshot
![Image text](https://www.united-internet.de/fileadmin/user_upload/Brands/Downloads/Logo_IONOS_by.jpg)
## Technologies
***
A list of technologies used within the project:
* [Technologie name](https://example.com): Version 12.3 
* [Technologie name](https://example.com): Version 2.34
* [Library name](https://example.com): Version 1234
## Installation
***
A little intro about the installation. 
```
$ git clone https://example.com
$ cd ../path/to/the/file
$ npm install
$ npm start
```
Side information: To use the application in a special environment use ```lorem ipsum``` to start
## Collaboration
***
Give instructions on how to collaborate with your project.
> Maybe you want to write a quote in this part. 
> It should go over several rows?
> This is how you do it.
## FAQs
***
A list of frequently asked questions
1. **This is a question in bold**
Answer of the first question with _italic words_. 
2. __Second question in bold__ 
To answer this question we use an unordered list:
* First point
* Second Point
* Third point
3. **Third question in bold**
Answer of the third question with *italic words*.
4. **Fourth question in bold**
| Headline 1 in the tablehead | Headline 2 in the tablehead | Headline 3 in the tablehead |
|:--------------|:-------------:|--------------:|
| text-align left | text-align center | text-align right |
