# Projet 3 : Mini-système de gestion des processus (task manager)

## Objectif
Implémenter un gestionnaire de tâches basique pour Unix, similaire à la commande top. Le programme affichera les processus en cours d'exécution, leur PID, l'état du processus (en cours, suspendu, zombie, etc.), et la quantité de mémoire consommée. Il faudra ajouter des commandes permettant de tuer un processus, d’en suspendre un autre ou de modifier la priorité d’un processus à l'aide de kill et nice. L'affichage s'actualisera en temps réel.

# Concepts clés
Systèmes de fichiers Unix, signaux (kill, SIGKILL, SIGSTOP), gestion de processus avec fork et exec, utilisation des fichiers /proc sous Linux.

