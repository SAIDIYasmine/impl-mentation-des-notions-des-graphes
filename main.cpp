#include "source.cpp"
#include <stdlib.h>

int main(){
	t_graphe mon_graphe;
	int choix1=-1;
	while (choix1!=0){
		system("CLS");
		cout << "########" <<endl;
		cout << "entrer : \n1- si vous voulez utiliser le graphe dans le fichier exemple.cpp\n2- si vous voulez saisir votre graphe depuis la ligne de commance\n3- si vous voulez lire votre graphe d'apres un fichier texte\n0- si vous voulez quitter le programme" << endl;
		cin >> choix1;
		if (choix1==0){
			break;
		}
		if(choix1==1){
			exemple_de_graphe(mon_graphe);
		}
		if (choix1==2){
			mon_graphe.saisir_un_graphe();
		}
		if (choix1==3){
			string file1,file2;
			cout << "entrer le nom du fichier qui contient les sommets et les successeurs : "<<endl;
			cin>>file1;
			cout << "entrer le nom du fichier qui contient les couts des arcs : "<<endl;
			cin>>file2;
			mon_graphe.lire_un_graphe_fichier(file1,file2);
		}
		int choix2=-1;
		while(choix2!=0){
			system("CLS");
			cout << "########" <<endl;
			cout << "\nentrer : \n1- pour afficher le graphe\n2- pour appliquer l'algorithme de Djikstra sur le graphe\n3- pour appliquer Belmman sur le graphe\n4- pour appliquer l'ordonnancement\n0- pour changer le graphe"<< endl;
			cin >> choix2;
			if (choix2==1){
				mon_graphe.afficher_graphe();
				Sleep(4000);
			}
			if (choix2==2){
				int point_depart,point_arrive;
				cout<< "saisir le point de depart : "<<endl;
				cin>>point_depart;
				cout<< "saisir le point d'arrivee : "<<endl;
				cin>>point_arrive;
				Djikstra(mon_graphe,point_depart,point_arrive);
				Sleep(4000);
			}
			if (choix2==3){
				int point_depart,point_arrive;
				cout<< "saisir le point de depart : "<<endl;
				cin>>point_depart;
				cout<< "saisir le point d'arrivee : "<<endl;
				cin>>point_arrive;
				cout << "entrer la permutation que vous voulez appliquer par Bellman :"<<endl;
				int tab[mon_graphe.getN()];
				for(int i=0;i<mon_graphe.getN();i++){
					tab[i]=i;
				}
				Bellman(mon_graphe,point_depart,point_arrive,tab);
				Sleep(4000);
			}
			if (choix2==4){
				int point_depart,point_arrive;
				cout<< "saisir le point de depart : "<<endl;
				cin>>point_depart;
				cout<< "saisir le point d'arrivee : "<<endl;
				cin>>point_arrive;
				Ordonnancement(mon_graphe,point_depart,point_arrive);
				Sleep(4000);
			}
		}
	}
	return 0;
}