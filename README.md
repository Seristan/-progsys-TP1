# -progsys-TP1

**Compte rendu TP1 séance 1 Constant BRISSIER Audric OLIVIER**

Question 1 : Affichage d'un message d'accueil suivi d'un prompt

```
Dans un premier temps, on défini le message d'introduction qu'on affiche ensuite dans la console.

On met en place une boucle infini qui aura pour but de permettre l'écriture d'une commande par l'utilisateurs, le tout en ajoutant le prompt "enseash" devant chaque prompt
pour indiquer qu'on se trouve toujours dans notre programme. On continue tant qu'une commande n'est pas reconnu.

on a défini la fonction exit ici mais c'est une erreur, on en reparlera donc à la question concerné.

Ces affichage de messages de bienvenue et du prompt enseash seront ensuite mis sous forme de fonction externe au "main" pour simplifier la lecture du programme.
```

Question 2 : Execution d'une commande reçu et retour au prompt

```
a) Lecture de la commande saisie

On attend que l'utilisateur envoi un nom de fonction. Pour reconnaitre la fonction exit, il est important de chercher le caractère "\n" afin de détecter que l'utilisateur veut finir sa commande et veut l'envoyer, on remplacera cet \n par un \0 afin de marquer.
```

```
b) Execution d'une commande simple (sans argument)

Pour executer une commande, on doit utiliser la fonction fork(), afin de créer un processur fils permettant de faire tourner la commande en question sans interferer avec le programme principal.
```

```
c) Retour au prompt enseash% et attente de la commande suivante

on boucle simplement à "displayPrompt" une fois la commande executé avec succès"
```

Question 3 : Gestion de la sortie du shell avec la commande “exit” ou un ctrl +d 
```
On créer la fonction exit qui permet de fermer de force le processus principal et donc interrompre simplement notre programme avec un "break";"
On créer aussi une fonction "bye_message()" sans argument, qui ecrit "bye bye", qu'on utilisera à l'utilisation de exit ou ctrl+d
```

Question 4 : Affichage du code de retour (ou du signal) de la commande précédente dans le prompt :
```
On ajoute dans cet partie le code permettant de vérifier si le code s'execute avec succes ou non
Dans le cas où une erreur est détecté, on affiche "exit:1", qui signifie que le processus ne n'est pas terminé normalement.
Si aucune erreur n'est détecté, on affiche "exit:0", signifiant que la commande s'est exécuté sans problème.
Dans tout les cas on retourne ensuite au prompte initial.
```


