#include<iostream>
#include<vector>

using namespace std;

const int n_max=300;
const int ns_max=300;
const int c_infini=9999;

class t_graphe{
	//les attributs
	int n; //nombre de sommet du graphe
	public :
		int ns[n_max]; //nombre de successeur d'un sommet
		int s[n_max][ns_max]; //liste des successeur 
		float l[n_max][ns_max]; //liste des couts
	public :
		//les getters
		int getN();
		//les setters
		void setN(int n);
		/*permet d'afficher les composants du graphe : 
		nombre de sommets
		les successeurs de chaque sommet
		le cout de chaque arc*/
		void afficher_graphe();
		//intialiser un graphe a partir du console
		void saisir_un_graphe();
		//lire un graphe a partie d'un fichier texte
		void lire_un_graphe_fichier(std::string nom_fichier1,std::string nom_fichier2);
};
class t_solution{
	public :
		int m[n_max]; //les marques
		int p[n_max]; //En notant par où on passe
};
//insialiser un graphe dans le code
void exemple_de_graphe(t_graphe& mon_graphe);
void initialisation(t_graphe mon_graphe);
void Bellman(t_graphe& mon_graphe,int point_depart, int point_arrivee,int sequence);
void afficher_solution(t_solution ma_solution, int point_depart, int point_arrivee);
void Djikstra(t_graphe mon_graphe,int point_depart, int point_arrivee);
void Ordonnancement(t_graphe mon_graphe,int point_depart, int point_arrivee);