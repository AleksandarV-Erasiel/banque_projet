# Projet Banque C++

Ce projet a été réalisé par Aleksandar VASILJEVIC & William DENOYER en M2 IISC à CY Cergy Paris Université dans le cadre de l'atelier de **C++**. Sa vocation a donc été de résumer et de mettre en pratique les connaissances acquises tout au long de l'atelier.

## Fichier de configuration

Le fichier de configuration est un fichier texte (par défaut : "config.txt") donnant les différents paramètres d'entrés de notre simulation de banque. Il est organisé de la manière suivante :

    # t0 dureePrevue tempsEntreArrivees nbCaissiers
    0 100 1 3
    1.0 # dureeTraitement Caissier n°1
    1.0 # dureeTraitement Caissier n°2
    1.0 # dureeTraitement Caissier n°3

La première ligne contient le temps initial, la durée de simulation prévue, le temps moyen entre arrivées des clients et le nombre de caissiers dans la simulation. Ce dernier donne une indication sur le nombre de ligne à lire, où chaque ligne représente la durée de traitement de chaque caissier.

## Exécution

Afin d'exécuter ce projet, il suffit de lancer la commande `make` et de lancer l'exécutable avec la commande `Simulation <config_file_path>` dans un terminal.

## Documentation

Le projet est documenté via l'outil "Doxygen". Afin de générer cette documentation, il suffit de lancer la commande `make doc` dans un terminal.