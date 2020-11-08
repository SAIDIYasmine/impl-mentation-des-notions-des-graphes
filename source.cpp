#include "exemple.cpp"
#include <fstream>
#include <windows.h>

int t_graphe::getN(){
	return t_graphe::n;
}
void t_graphe::setN(int n){
	t_graphe::n=n;
}
void t_graphe::afficher_graphe(){
	cout << endl << "nombre de sommets est :" << t_graphe::n << endl << endl;
	for (int i=1; i<t_graphe::n+1; i++){
		cout << "Le nombre des successeurs du sommet num " << i << " est : " << t_graphe::ns[i] << endl;
	}
	cout << endl;
	for (int i=1; i<t_graphe::n+1; i++){
		for (int j=1; j<t_graphe::ns[i]+1; j++){
			cout << "Le successeur num " << j << "du sommet "<< i << " est :" << t_graphe::s[i][j] << endl;
		}
	cout << endl;
	}	
	for (int i=1; i<t_graphe::n+1; i++){
		for (int j=1; j<t_graphe::ns[i]+1; j++){
			cout << "Le cout de l'arc "<< i << "->" << t_graphe::s[i][j] << " est : " << t_graphe::l[i][j] << endl;
		}
		cout << endl;
	}
}
void t_graphe::lire_un_graphe_fichier(std::string nom_fichier1,std::string nom_fichier2){
	ifstream monFlux1(nom_fichier1, ios::app);
	ifstream monFlux2(nom_fichier2, ios::app);
	if(monFlux1 && monFlux2){
		int n,ns,s;
		float l;
		monFlux1.seekg(0,ios::beg); //au commencement du fichier
		monFlux2.seekg(0,ios::beg); //au commencement du fichier
		while(!monFlux1.eof() || !monFlux2.eof()){
			monFlux1>>n;
			t_graphe::n=n;
			cout <<"n= "<<t_graphe::n << endl;
			monFlux1>>ns;
			t_graphe::ns[n]=ns;
			cout <<"ns= "<<t_graphe::ns[n] << endl;
			for (int i=1;i<ns+1;i++){
				monFlux1>>s;
				t_graphe::s[n][i]=s;
				cout <<"s= "<<t_graphe::s[n][i] << endl;
				monFlux2>>l;
				t_graphe::l[n][i]=l;
				cout <<"l= "<<t_graphe::l[n][i] << endl;
			}
		}
	}
	else{
		cout << "impossible d'ouvrir le fichier" <<endl;
	}
}


void t_graphe::saisir_un_graphe(){
	int n;
	cout << "entrer le nombre de sommets : ";
	cin >> n;
	t_graphe::n=n;
	for(int i=1;i<n+1;i++){
		int ns;
		cout << "entrer le nombre de successeurs du sommet num " << i << " : ";
		cin >> ns;
		t_graphe::ns[i]=ns;
		for (int j=1;j<ns+1;j++){
			int s;
			cout << "entrer le successeur num "<< j << " du sommet num " << i << " : ";
			cin >>s;
			t_graphe::s[i][j]=s;
			cout << "entrer le cout de l'arc "<< i << "->" << s << " : ";
			int l;
			cin >>l;
			t_graphe::l[i][j]=l;
		}
	}
} 
void afficher_solution(t_solution ma_solution, int point_depart, int point_arrivee){
	vector<int> plus_court_chemin;
	int s=point_arrivee;
	while(s!=point_depart){
		plus_court_chemin.push_back(s);
		s=ma_solution.p[s];
	}
	plus_court_chemin.push_back(point_depart);
	int i=plus_court_chemin.size()-1;
	while (i!=-1){
		cout << plus_court_chemin[i] << " ";
		i--;
	}
}
void Bellman(t_graphe& mon_graphe,int point_depart, int point_arrivee,int sequence[6]){
	//initialisations 
	t_solution ma_solution;
	int changement = 1;
	for (int i=1;i<mon_graphe.getN()+1;i++){
		ma_solution.m[i]=c_infini;
		ma_solution.p[i]=0;
	}
	ma_solution.m[point_depart]=0;
	while (changement == 1) {
		changement = 0;
		for (int j = 1; j < mon_graphe.getN()+1; j++) {
			//on modifie les marques des successeurs du noeud courant
			int courant = sequence[j-1];
			for (int k = 1; k < mon_graphe.ns[courant]+1; k++) {
				int s = mon_graphe.s[courant][k];
				if (ma_solution.m[courant] + mon_graphe.l[courant][k] < ma_solution.m[s]) {
					ma_solution.m[s] =ma_solution.m[courant] + mon_graphe.l[courant][k];
					ma_solution.p[s] = courant;
					changement = 1;
				}
			}
		}
	}
	cout << "\nLe plus court chemin d'apres Bellman est : \n";
	afficher_solution(ma_solution,point_depart,point_arrivee);
}
void Djikstra(t_graphe mon_graphe,int point_depart, int point_arrivee){
	//initialisation
	t_solution ma_solution;
	int t[mon_graphe.getN()]; 
	for (int i=1;i<mon_graphe.getN()+1;i++){
		ma_solution.m[i]=c_infini;
		ma_solution.p[i]=-1;
		t[i]=0;
	}
	ma_solution.m[point_depart]=0;
	int i_min,s_min;
	for (int i=1;i<mon_graphe.getN()+1;i++){
		//Recherche d'un nœud de distance minimale
		i_min=c_infini;
		s_min=-1;
		for(int j=1;j<mon_graphe.getN()+1;j++){
			if((ma_solution.m[j]<i_min) && (t[j]==0)){
				s_min=j;
				i_min=ma_solution.m[j];
			}
		}
		//Mise à jour des distances
		t[s_min]=1;
		for (int k=1;k<mon_graphe.ns[s_min]+1;k++){
			if (mon_graphe.l[s_min][k]+ma_solution.m[s_min]<ma_solution.m[mon_graphe.s[s_min][k]]){
				ma_solution.m[mon_graphe.s[s_min][k]]=mon_graphe.l[s_min][k]+ma_solution.m[s_min];
				ma_solution.p[mon_graphe.s[s_min][k]]=s_min;
			}
		}
	}
	cout << "\nLe plus court chemin d'apres Djikstra est : \n";
	afficher_solution(ma_solution,point_depart,point_arrivee);
}
void Ordonnancement(t_graphe mon_graphe,int point_depart, int point_arrivee){
	//initialisation
	t_solution ma_solution;
	int t[mon_graphe.getN()]; 
	for (int i=1;i<mon_graphe.getN()+1;i++){
		ma_solution.m[i]=-1;
		ma_solution.p[i]=-1;
		t[i]=0;
	}
	ma_solution.m[point_depart]=0;
	int i_max,s_max;
	for (int i=1;i<mon_graphe.getN()+1;i++){
		//Recherche d'un nœud de distance maximale
		i_max=-1;
		s_max=-1;
		for(int j=1;j<mon_graphe.getN()+1;j++){
			if((ma_solution.m[j]>i_max) && (t[j]==0)){
				s_max=j;
				i_max=ma_solution.m[j];
			}
		}
		//Mise à jour des distances
		t[s_max]=1;
		for (int k=1;k<mon_graphe.ns[s_max]+1;k++){
			if (mon_graphe.l[s_max][k]+ma_solution.m[s_max]>ma_solution.m[mon_graphe.s[s_max][k]]){
				ma_solution.m[mon_graphe.s[s_max][k]]=mon_graphe.l[s_max][k]+ma_solution.m[s_max];
				ma_solution.p[mon_graphe.s[s_max][k]]=s_max;
			}
		}
	}
	cout << "\nLe chemin critique est : \n";
	afficher_solution(ma_solution,point_depart,point_arrivee);	
}