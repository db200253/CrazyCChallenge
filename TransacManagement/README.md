# Projet 7 : Implémentation d’un système de gestion des transactions bancaires

## Objectif
Implémenter un système de gestion de transactions bancaires multi-threadé. Chaque client bancaire doit pouvoir exécuter plusieurs opérations simultanément sur ses comptes (dépôts, retraits, virements). Il faudra utiliser des mutex pour éviter les conditions de concurrence lors de l'accès aux comptes. Le système devra être résilient aux problèmes comme les deadlocks, et aura un mécanisme pour détecter et résoudre les éventuels conflits d’accès aux ressources partagées.

## Concepts clés
Multithreading, mutex, synchronisation, deadlocks, gestion des transactions concurrentes.

