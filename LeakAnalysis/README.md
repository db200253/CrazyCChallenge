# Projet 2 : Analyseur de fuites de mémoire

## Objectif
Créer un programme qui analyse les fuites de mémoire dans un programme C. L'outil devra surveiller toutes les allocations dynamiques (avec malloc, calloc, etc.) et vérifier si toutes les zones de mémoire allouées ont été libérées à la fin de l'exécution du programme. Pour chaque fuite détectée, le programme affichera le nombre d'octets non libérés et la ligne de code où l'allocation a eu lieu. Cela sera fait en interceptant les appels à malloc et free via des wrappers.

## Concepts clés
Wrapping de fonctions, gestion des fuites mémoire, utilisation de valgrind.