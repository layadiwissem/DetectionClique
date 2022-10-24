
#include <bits/stdc++.h>
using namespace std;
  

  
// sauvegarde de noeud dans un tableau
int store[100], n;
  
// Graph
int graph[100][100];
  
// Degree of the vertices
int d[100];
  
// Fonction pour vérifier si l'ensemble de sommets donné
// // dans le tableau est une clique ou non
bool is_clique(int b)
{
    //declachement dune boucle 
    // pour le noeud selectionne
    for (int i = 1; i < b; i++) {
        for (int j = i + 1; j < b; j++)
  
            // dans le cas  dun noeud introuvable
            if (graph[store[i]][store[j]] == 0)
                return false;
    }
    return true;
}
  int clique =0;
// Fonction daffichage de clique
void print(int n)
{
    for (int i = 1; i < n; i++)
    
    cout <<  store[i] << " ";
    cout << "\n ";
  clique ++;
 
}
  
// Fonction pour trouver les cliques de  size s
void findCliques(int i, int l, int s)
{
    // verifie si on peut inséré un noeud i+1
    for (int j = i + 1; j <= n - (s - l); j++)
  
        // si le degre de graphe est suffisnt
        if (d[j] >= s - 1) {
  
            //ajout de neoud
            store[l] = j;
  
            // si le graphe ne represent pas une clique de taille S
            
            //on ajoute un autre noeud 
            if (is_clique(l + 1))
  
                //  si la loungeur de clique != de la taille s
                if (l < s) 
  
                    // Recursivitie pour lajout dun noeud
                    findCliques(j, l + 1, s);
  
                // sinon 
                else
                    print(l + 1);
        }
}
  

int main()
{
    int edges[][2] = {{3, 2},{4, 1},{4, 2},{4, 3},{5, 1},{6, 1},
				{7,1},{7, 5},{7, 6},{8 ,1},{8, 2},
				{8, 3},{8 ,4},{9, 1},{9, 3},{10, 3},
				{11 ,1},{11, 5},{11 ,6},{12 ,1},{13,1},{13, 4},
				{14, 1},{14,2},{14, 3},{14, 4},{17, 6},{17, 7},
	{18, 1},{18, 2},{20, 1},{20, 2},{22, 1},{22, 2},{26, 24},{26, 25}};
	
    int k = 3;
    int size = sizeof(edges) / sizeof(edges[0]);
    n =size;
    
    printf("*******************Projet Systeme d'aide a la decision********************\n\n");
    printf("***Algorithme de la detection des cliques de taille 'k' dans un graphe ***\n\n");
    printf("************************Les cliques trouve *******************************\n\n");
   
     
       for (int i = 0; i < size; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
        d[edges[i][0]]++;
        d[edges[i][1]]++;
               }
    findCliques(0,1, k);
    
    printf("\n \n \n**********************Le nombre de clique trouve de taille 3 est %d********\n\n", clique);
  		     return 0;
}
