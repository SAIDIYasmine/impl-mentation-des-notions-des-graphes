#include "header.hpp"

void exemple_de_graphe(t_graphe& mon_graphe){
	mon_graphe.setN(14); 

	mon_graphe.ns[1] = 6;
	mon_graphe.s[1][1] = 2; 
	mon_graphe.s[1][2] = 4; 
	mon_graphe.s[1][3] = 5; 
	mon_graphe.s[1][4] = 6; 
	mon_graphe.s[1][5] = 7; 
	mon_graphe.s[1][6] = 8; 


	mon_graphe.l[1][1] = 0; 
	mon_graphe.l[1][2] = 400; 
	mon_graphe.l[1][3] = 400; 
	mon_graphe.l[1][4] = 400; 
	mon_graphe.l[1][5] = 450; 
	mon_graphe.l[1][6] = 0; 

	mon_graphe.ns[2] = 1;
	mon_graphe.s[2][1] = 3;

	mon_graphe.l[2][1] = 120;

	mon_graphe.ns[3] = 4;
	mon_graphe.s[3][1] = 4;
	mon_graphe.s[3][2] = 5;
	mon_graphe.s[3][3] = 6;
	mon_graphe.s[3][4] = 7;

	mon_graphe.l[3][1] = 180;
	mon_graphe.l[3][2] = 180;
	mon_graphe.l[3][3] = 180;
	mon_graphe.l[3][4] = 50;

	mon_graphe.ns[4] = 1;
	mon_graphe.s[4][1] = 14;

	mon_graphe.l[4][1] = 30;

	mon_graphe.ns[5] = 2;
	mon_graphe.s[5][1] = 9;
	mon_graphe.s[5][2] = 11;

	mon_graphe.l[5][1] = 30;
	mon_graphe.l[5][2] = 30;

	mon_graphe.ns[6] = 2;
	mon_graphe.s[6][1] = 9;
	mon_graphe.s[6][2] = 11;

	mon_graphe.l[6][1] = 60;

	mon_graphe.ns[7] = 2;
	mon_graphe.s[7][1] = 9;
	mon_graphe.s[7][2] = 11;

	mon_graphe.l[7][1] = 90;
	mon_graphe.l[7][2] = 90;

	mon_graphe.ns[8] = 2;
	mon_graphe.s[8][1] = 9;
	mon_graphe.s[8][2] = 11;

	mon_graphe.l[8][1] = 240;
	mon_graphe.l[8][2] = 240;

	mon_graphe.ns[9] = 3;
	mon_graphe.s[9][1] = 10;
	mon_graphe.s[9][2] = 12;
	mon_graphe.s[9][3] = 13;

	mon_graphe.l[9][1] = 180;
	mon_graphe.l[9][2] = 180;
	mon_graphe.l[9][3] = 180;

	mon_graphe.ns[10] = 1;
	mon_graphe.s[10][1] = 14;

	mon_graphe.l[10][1] = 30;

	mon_graphe.ns[11] = 3;
	mon_graphe.s[11][1] = 10;
	mon_graphe.s[11][2] = 12;
	mon_graphe.s[11][3] = 13;

	mon_graphe.l[11][1] = 240;
	mon_graphe.l[11][2] = 240;
	mon_graphe.l[11][3] = 240;

	mon_graphe.ns[12] = 1;
	mon_graphe.s[12][1] = 14;

	mon_graphe.l[12][1] = 360;

	mon_graphe.ns[13] = 1;
	mon_graphe.s[13][1] = 14;

	mon_graphe.l[13][1] = 240;

	mon_graphe.ns[14] = 0;
}
/*void exemple_de_graphe(t_graphe& mon_graphe){
	mon_graphe.setN(6); 

	mon_graphe.ns[1] = 3;
	mon_graphe.s[1][1] = 5; 
	mon_graphe.s[1][2] = 3; 
	mon_graphe.s[1][3] = 2; 


	mon_graphe.l[1][1] = 9; 
	mon_graphe.l[1][2] = 6; 
	mon_graphe.l[1][3] = 2; 

	mon_graphe.ns[2] = 3;
	mon_graphe.s[2][1] = 3; 
	mon_graphe.s[2][2] = 1; 
	mon_graphe.s[2][3] = 6; 


	mon_graphe.l[2][1] = 3; 
	mon_graphe.l[2][2] = 2; 
	mon_graphe.l[2][3] = 9; 

	mon_graphe.ns[3] = 3;
	mon_graphe.s[3][1] = 5; 
	mon_graphe.s[3][2] = 6; 
	mon_graphe.s[3][3] = 1; 


	mon_graphe.l[3][1] = 3; 
	mon_graphe.l[3][2] = 6; 
	mon_graphe.l[3][3] = 6; 

	mon_graphe.ns[4] = 1;
	mon_graphe.s[4][1] = 2;

	mon_graphe.l[4][1] = 4;

	mon_graphe.ns[5] = 2;
	mon_graphe.s[5][1] = 6;
	mon_graphe.s[5][2] = 3;

	mon_graphe.l[5][1] = 2;
	mon_graphe.l[5][2] = 3;

	mon_graphe.ns[6] = 1;
	mon_graphe.s[6][1] = 4;

	mon_graphe.l[6][1] = 4;

}
void exemple_de_graphe(t_graphe& mon_graphe){
	mon_graphe.setN(9); 

	mon_graphe.ns[1] = 2;
	mon_graphe.s[1][1] = 4; 
	mon_graphe.s[1][2] = 2; 

	mon_graphe.l[1][1] = 4; 
	mon_graphe.l[1][2] = 10; 

	mon_graphe.ns[2] = 2;
	mon_graphe.s[2][1] = 3;
	mon_graphe.s[2][2] = 5;

	mon_graphe.l[2][1] = 1;
	mon_graphe.l[2][2] = 2;

	mon_graphe.ns[3] = 2;
	mon_graphe.s[3][1] = 6;
	mon_graphe.s[3][2] = 8;

	mon_graphe.l[3][1] = 4;
	mon_graphe.l[3][2] = 2;

	mon_graphe.ns[4] = 1;
	mon_graphe.s[4][1] = 6;

	mon_graphe.l[4][1] = 12;

	mon_graphe.ns[5] = 2;
	mon_graphe.s[5][1] = 3;
	mon_graphe.s[5][2] = 8;

	mon_graphe.l[5][1] = 9;
	mon_graphe.l[5][2] = 3;

	mon_graphe.ns[6] = 1;
	mon_graphe.s[6][1] = 7;

	mon_graphe.l[6][1] = 5;

	mon_graphe.ns[7] = 2;
	mon_graphe.s[7][1] = 8;
	mon_graphe.s[7][2] = 9;

	mon_graphe.l[7][1] = 3;
	mon_graphe.l[7][2] = 3;

	mon_graphe.ns[8] = 1;
	mon_graphe.s[8][1] = 9;

	mon_graphe.l[8][1] = 3;

	mon_graphe.ns[9] = 0;
}*/