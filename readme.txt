# TREEDIR - Projet de Langage C

## 1. Guide d'utilisation pour run.sh afin de compiler 

Ce script `run.sh` vous permet de compiler et de tester le programme.

### Commandes

Il y a plusieurs commandes que vous pouvez utiliser avec ce script :

- `compile` : Cette commande va compiler le programme en utilisant le Makefile du répertoire. Si l'option `a` est spécifiée, elle nettoiera également les constructions précédentes.

- `test` ou `tests` : Cette commande va d'abord compiler le programme puis exécuter nos tests.

- `valgrind` : Cette commande va compiler le programme et l'exécuter avec valgrind pour vérifier les fuites de mémoire.

- Aucun argument : Si vous exécutez le script sans aucune commande, il compilera et exécutera le programme principal.


### Options

De plus, il y a plusieurs options que vous pouvez utiliser avec ce script :

- `-v` : Par défaut, toutes les sorties seront envoyées à `/dev/null`. Si vous voulez voir la sortie dans votre terminal, utilisez l'option `-v`.

- `-a` : Cette option forcera une recompilation complète du programme en exécutant `make clean` avant `make all`.

Attention, à bien mettre les options avant les commandes.

### Exemple d'utilisation

Voici quelques exemples sur comment utiliser ce script :

- Compiler le programme :
    ```
    ./run.sh -a compile
    ```

- Exécuter nos tests :
    ```
    ./run.sh test
    ```

- Compiler et exécuter le programme avec sortie visible dans le terminal :
    ```
    ./run.sh -v
    ```

- Compiler le programme et l'exécuter avec valgrind :
    ```
    ./run.sh valgrind
    ```

N'oubliez pas de donner les permissions d'exécution au script avec `chmod +x run.sh` s'il n'est pas déjà exécutable.

## 2. Guide d'utilisation de `./program` avec un fichier texte

La compilation avec `run.sh` produit un executable `program` qui peut être utilisé pour exécuter le programme. 
Il prend un fichier texte en entrée et exécute les commandes du fichier texte. Les resultats sont affichés dans le terminal.

### Commandes

- Pour exécuter le programme avec un fichier texte, utilisez la commande suivante :
    ```
    ./program <fichier texte>
    ```

- Pour lancer valgrind lors de l'exécution du programme avec un fichier texte, utilisez la commande suivante :
    ```
    valgrind ./program <fichier texte>
    ```

- Une version plus détaillée de valgrind peut etre obtenue en utilisant la commande suivante :
    ```
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./program <fichier texte>
    ```