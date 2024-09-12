# Projet 8 : Implémentation d’un thread-safe logging system

## Objectif
Créer un système de journalisation (logging system) capable d'enregistrer de manière thread-safe des messages provenant de différents threads en parallèle. Chaque message doit être horodaté et écrit dans un fichier de log. Il faudra utiliser un mécanisme de file d'attente sécurisé (queue) pour bufferiser les messages et assurer que l’écriture dans le fichier se fait sans conflit. Il faudra implémenter des mécanismes de verrouillage efficaces pour gérer la concurrence tout en minimisant les blocages.

## Concepts clés
Threads, queues sécurisées (thread-safe), mutex, conditions, systèmes de fichiers.
	

