# Projet 4 : Serveur Web multi-threadé

## Objectif
Implémenter un serveur web multi-threadé capable de répondre aux requêtes HTTP de manière concurrente. Le serveur pourra accepter plusieurs connexions en parallèle, lire les requêtes HTTP, servir des fichiers statiques (HTML, CSS, images) et renvoyer des réponses HTTP valides. Il utilisera des sockets pour la communication réseau et gèrera chaque requête dans un thread séparé. Il faudra limiter le nombre de threads en cours pour éviter d'épuiser les ressources du système (utilisation d'une file de threads).

## Concepts clés
Programmation réseau avec sockets, threads POSIX (pthread), gestion des threads (thread pool), gestion concurrente.

