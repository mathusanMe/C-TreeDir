# TREEDIR - Projet de Langage C
## 1. Guide d'utilisation pour run.sh afin de compiler
Ce script `run.sh` vous permet de compiler, tester et exécuter le programme.

Les options que vous pouvez utiliser avec ce script sont :

* a : Force une recompilation complète du programme en exécutant make clean avant make all.
* b : Active le mode verbeux. Par défaut, toutes les sorties seront envoyées à la sortie standard.
* t : Effectue les tests après la compilation du programme.
* v : Exécute le programme avec Valgrind pour vérifier les fuites de mémoire.
* o : Redirige la sortie vers un fichier. Par exemple, -o output.txt enverra la sortie vers le fichier output.txt.

### Exemple d'utilisation
Voici quelques exemples sur comment utiliser ce script :

- Recompiler dans son entièreté le programme :
    ```bash
    ./run.sh -a
    ```

- Compiler le programme et effectuer les tests :
    ```bash
    ./run.sh -a -t
    ```
- Compiler et exécuter le programme avec sortie plus détaillée :
    ```bash
    ./run.sh -b
    ```

- Compiler et exécuter le programme avec Valgrind :
    ```bash
    ./run.sh -v
    ```

N'oubliez pas de donner les permissions d'exécution au script avec chmod +x run.sh s'il n'est pas déjà exécutable.
N'oubliez pas de donner les permissions d'exécution au script avec `chmod +x run.sh` s'il n'est pas déjà exécutable.

## 2. Guide d'utilisation de ./program avec un fichier texte

La compilation avec run.sh produit un exécutable program qui peut être utilisé pour exécuter le programme. Il accepte un certain nombre d'options, que vous pouvez combiner à votre convenance :

-v : Active le mode verbeux.
-t : Exécute les tests intégrés.
-o : Redirige la sortie vers un fichier. Par exemple, -o output.txt enverra la sortie vers le fichier output.txt.

### Exemples
- Pour exécuter le programme avec un fichier texte en mode verbeux :
    ```bash
    ./program -v <fichier texte>
    ```

- Pour exécuter les tests intégrés en mode verbeux :
    ```bash
    ./program -v -t
    ```

- Pour exécuter le programme avec un fichier texte et rediriger la sortie vers un fichier :
    ```bash
    ./program -o output.txt <fichier texte>
    ```

- Pour exécuter les tests intégrés et rediriger la sortie vers un fichier :
    ```bash
    ./program -t -o output.txt
    ```

- Pour lancer Valgrind lors de l'exécution du programme avec un fichier texte, utilisez la commande suivante :
    ```bash
    valgrind ./program <fichier texte>
    ```
- Une version plus détaillée de Valgrind peut être obtenue en utilisant la commande suivante :
    ```bash
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./program <fichier texte>
    ```