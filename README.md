# Roadmap du Crazy C Challenge

## Introduction
Aprés plus de 4 ans d'études dans le domaine du numérique (à la création de ce repo) une idée un peu folle m'est venue en tête. J'ai tout simplement besoin de casser mes habitudes et de sortir de ma zone de confort en tant que développeur en réalisant 14 projets articulés en 7 phases distinctes en n'utilisant que le langage C. L'objectif est de finir cela avant la fin de mes études (le 30 Septembre 2025), ce qui ne me laisse qu'un an pour passer d'un niveau intermédiaire à un niveau confirmé.


## Table des matières

1. [Phase 1 : Gestion avancée de la mémoire et optimisation](#phase-1--gestion-avancée-de-la-mémoire-et-optimisation)
2. [Phase 2 : Programmation système et Unix avancé](#phase-2--programmation-système-et-unix-avancé)
3. [Phase 3 : Structures de données et algorithmes avancés](#phase-3--structures-de-données-et-algorithmes-avancés)
4. [Phase 4 : Multithreading avancé et concurrence](#phase-4--multithreading-avancé-et-concurrence)
5. [Phase 5 : Optimisation avancée et gestion du cache](#phase-5--optimisation-avancée-et-gestion-du-cache)
6. [Phase 6 : Projets avancés et finalisation](#phase-6--projets-avancés-et-finalisation)
7. [Phase 7 : Systèmes distribués et embarqués](#phase-7--systèmes-distribués-et-embarqués)

---

## Phase 1 : Gestion avancée de la mémoire et optimisation

### Projet 1 : Simulateur d'allocation de mémoire
- **Concepts à étudier** :
  - Allocation dynamique (`malloc`, `calloc`, `realloc`, `free`).
  - Fragmentation de la mémoire.
  - Arithmétique des pointeurs.
  - Gestion des erreurs d'allocation.
- **Outils à utiliser** :
  - Valgrind
  - GDB
  - Heap visualizer (`heaptrack`)

### Projet 2 : Analyseur de fuites de mémoire
- **Concepts à étudier** :
  - Techniques de détection de fuites de mémoire.
  - Wrapping de fonctions.
  - Gestion de structures dynamiques.
- **Outils à utiliser** :
  - Valgrind
  - GDB
  - AddressSanitizer (Clang)

---

## Phase 2 : Programmation système et Unix avancé

### Projet 3 : Mini-système de gestion des processus
- **Concepts à étudier** :
  - Gestion des processus (`fork`, `exec`, `wait`).
  - Signaux Unix (SIGKILL, SIGSTOP, etc.).
  - Analyse des fichiers `/proc` sur Linux.
- **Outils à utiliser** :
  - htop/top
  - ps
  - strace

### Projet 4 : Serveur Web multi-threadé
- **Concepts à étudier** :
  - Programmation réseau (sockets TCP/IP).
  - Multithreading avec POSIX Threads.
  - Synchronisation des threads (mutex, sémaphores).
- **Outils à utiliser** :
  - Wireshark
  - Netcat (nc)
  - Curl
  - GDB

---

## Phase 3 : Structures de données et algorithmes avancés

### Projet 5 : Arbre AVL (auto-équilibré)
- **Concepts à étudier** :
  - Structures de données : Arbres binaires, AVL.
  - Algorithmes d'équilibrage d'arbres (rotations).
  - Complexité logarithmique.
- **Outils à utiliser** :
  - Graphviz (Dot)
  - GDB

### Projet 6 : Système de gestion de graphes et algorithmes de parcours
- **Concepts à étudier** :
  - Structures de données : Graphes.
  - Algorithmes de parcours (DFS, BFS).
  - Algorithmes de plus courts chemins (Dijkstra).
- **Outils à utiliser** :
  - Graphviz
  - Boost Graph Library (BGL)
  - GDB

---

## Phase 4 : Multithreading avancé et concurrence

### Projet 7 : Système de gestion des transactions bancaires
- **Concepts à étudier** :
  - Multithreading avec POSIX Threads.
  - Synchronisation (mutex, sémaphores).
  - Concurrence (race conditions, deadlocks).
- **Outils à utiliser** :
  - GDB
  - Valgrind (Helgrind)
  - ThreadSanitizer (Clang)

### Projet 8 : Implémentation d’un thread-safe logging system
- **Concepts à étudier** :
  - File d'attente sécurisée (`thread-safe`).
  - Synchronisation avec mutex et condition variables.
  - Buffering pour l'écriture efficace sur disque.
- **Outils à utiliser** :
  - GDB
  - Logrotate
  - Valgrind (Helgrind)

---

## Phase 5 : Optimisation avancée et gestion du cache

### Projet 9 : Profiler de performances
- **Concepts à étudier** :
  - Analyse des goulots d'étranglement.
  - Gestion du cache CPU.
  - Mesure du temps d'exécution.
- **Outils à utiliser** :
  - Gprof
  - Valgrind (Cachegrind)
  - Perf

### Projet 10 : Optimisation d’un algorithme de tri parallèle
- **Concepts à étudier** :
  - Algorithmes de tri (tri rapide, tri fusion).
  - Programmation parallèle.
  - Optimisation du cache CPU.
- **Outils à utiliser** :
  - OpenMP
  - Gprof
  - Perf

---

## Phase 6 : Projets avancés et finalisation

### Projet 11 : Système de fichiers custom
- **Concepts à étudier** :
  - Systèmes de fichiers Unix.
  - Gestion des blocs mémoire.
  - Droits d'accès Unix.
- **Outils à utiliser** :
  - FUSE (Filesystem in Userspace)
  - Lsof
  - GDB

### Projet 12 : Système de simulation d'ordonnancement de processus
- **Concepts à étudier** :
  - Algorithmes d'ordonnancement (FIFO, Round-Robin, SJF, Priorité).
  - Gestion des files d'attente.
  - Performances CPU.
- **Outils à utiliser** :
  - Perf
  - Gprof
  - GDB

---

## Phase 7 : Systèmes distribués et embarqués

### Projet 13 : Système de messagerie distribuée
- **Concepts à étudier** :
  - Sockets réseaux (TCP/IP).
  - Tolérance aux pannes.
  - Algorithmes de consensus.
- **Outils à utiliser** :
  - Wireshark
  - ZeroMQ
  - GDB

### Projet 14 : Simulateur de réseau de capteurs pour systèmes embarqués
- **Concepts à étudier** :
  - Systèmes embarqués et IoT.
  - Protocole de communication sans fil (ZigBee, Bluetooth).
  - Optimisation énergétique.
- **Outils à utiliser** :
  - ns-3
  - Contiki OS / TinyOS
  - Arduino IDE
  - GDB

---

## Contact
Pour toute question ou suggestion, n'hésitez pas à ouvrir une issue ou à me contacter directement.

