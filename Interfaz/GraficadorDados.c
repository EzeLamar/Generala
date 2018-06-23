#include <stdio.h> 
#include <string.h>


char DADOS[6][5][10];


void dibujarDados(int d1,int d2, int d3, int d4, int d5){
	for(int i=0; i<5; i++){
		printf("%s  %s  %s  %s  %s\n",DADOS[d1][i],DADOS[d2][i],DADOS[d3][i],DADOS[d4][i],DADOS[d5][i]);
	}
}
void inicializarDados(){
	//DADO UNO 
	sprintf(DADOS[0][0],"%s","+-------+\0");
	sprintf(DADOS[0][1],"%s","|       |\0");
	sprintf(DADOS[0][2],"%s","|   o   |\0");
	sprintf(DADOS[0][3],"%s","|       |\0");
	sprintf(DADOS[0][4],"%s","+-------+\0");
	//DADO DOS
	sprintf(DADOS[1][0],"%s","+-------+\0");
	sprintf(DADOS[1][1],"%s","|     o |\0");
	sprintf(DADOS[1][2],"%s","|       |\0");
	sprintf(DADOS[1][3],"%s","| o     |\0");
	sprintf(DADOS[1][4],"%s","+-------+\0");
	//DADO TRES
	sprintf(DADOS[2][0],"%s","+-------+\0");
	sprintf(DADOS[2][1],"%s","|     o |\0");
	sprintf(DADOS[2][2],"%s","|   o   |\0");
	sprintf(DADOS[2][3],"%s","| o     |\0");
	sprintf(DADOS[2][4],"%s","+-------+\0");
	//DADO CUATRO
	sprintf(DADOS[3][0],"%s","+-------+\0");
	sprintf(DADOS[3][1],"%s","| o   o |\0");
	sprintf(DADOS[3][2],"%s","|       |\0");
	sprintf(DADOS[3][3],"%s","| o   o |\0");
	sprintf(DADOS[3][4],"%s","+-------+\0");
	//DADO CINCO
	sprintf(DADOS[4][0],"%s","+-------+\0");
	sprintf(DADOS[4][1],"%s","| o   o |\0");
	sprintf(DADOS[4][2],"%s","|   o   |\0");
	sprintf(DADOS[4][3],"%s","| o   o |\0");
	sprintf(DADOS[4][4],"%s","+-------+\0");
	//DADO SEIS
	sprintf(DADOS[5][0],"%s","+-------+\0");
	sprintf(DADOS[5][1],"%s","| o   o |\0");
	sprintf(DADOS[5][2],"%s","| o   o |\0");
	sprintf(DADOS[5][3],"%s","| o   o |\0");
	sprintf(DADOS[5][4],"%s","+-------+\0");
}
int main(int argc , char *argv[])  
{
	inicializarDados();
	
	dibujarDados(0,2,1,5,4);
	
	return 1;
	
}
