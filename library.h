#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void imprimir(char tab[16][32]){
	int l,c;
	for(l=0;l<16;l++){
		for(c=0;c<32;c++){
			printf("%c",tab[l][c]);
		}
		printf("\n");
	}
}

int verificador(char tab[16][32],char valor,int x,int y,int a,int auxiliar[2],int z){   //envio o valor da variável "sinal1" ou "sinal2" por parâmetro para "a", 
		if(tab[x][y-1]!=32 && tab[x][y-1]!=valor) a=0;				 					//de maneira que eu posso manter a mesma direção quando nenhum dos valores		  
		else if(tab[x][y+1]!=32 && tab[x][y+1]!=valor) a=1;	 								//ao redor de Andarilho for igual a "1";			      
		else if(tab[x-1][y]!=32 && tab[x-1][y]!=valor) a=2;
		else if(tab[x+1][y]!=32 && tab[x+1][y]!=valor) a=3;
		else return a;                                    					//Se não houver mudança ele já sai da função 
		
		if((a<2 && auxiliar[z]>=2) || (a>=2 && auxiliar[z]<2)) auxiliar[z]=a;  //verifica se mudou de direção (vertical ou horizontal).Se sim, atribui o valor de "a" à auxiliar
		else if(a==auxiliar[z]){
			if(a<2){
			 if(tab[x-1][y]!=32 && tab[x-1][y]!=valor) a=2;
			 else if(tab[x+1][y]!=32 && tab[x+1][y]!=valor) a=3;
			 else  a=((x-y)%2)+2;
			}else{
				if(tab[x][y-1]!=32 && tab[x][y-1]!=valor) a=0;				  
				else if(tab[x][y+1]!=32 && tab[x][y+1]!=valor) a=1;	
				else a=(x-y)%2;
			}	
			auxiliar[z]=a;
		}
		return a;
}

int andar(char tabuleiro [16] [32],int sinal,int l,int c){
	if(sinal==0){
		tabuleiro[l][c+1]=tabuleiro[l][c];
		tabuleiro[l][c]=' ';
		c++;
		return c;
	}else if(sinal==1){
		tabuleiro[l][c-1]=tabuleiro[l][c];
		tabuleiro[l][c]=' ';
		c--;
		return c;
	}else if(sinal==2){
		tabuleiro[l+1][c]=tabuleiro[l][c];
		tabuleiro [l][c]=' ';
		l++;
		return l;
	}else if(sinal==3){
		tabuleiro[l-1][c]=tabuleiro[l][c];
		tabuleiro[l][c]=' ';
		l--; 
		return l;
	}
}


