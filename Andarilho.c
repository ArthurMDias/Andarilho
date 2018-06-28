 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

main(){
	char tabuleiro[16] [32];
	int l,c,x,y,sinal1=0,sinal2=0,auxiliar[2]={},pos;
	for(l=0;l<16;l++){       							//Percorrerá todas as linhas
		for(c=0;c<32;c++){								//Todas as colunas de cada linha 
			if(l==0 || l==15){								//se for a primeira ou a  última linha
				if(l==0){										//se for a primeira linha
					if(c==0) tabuleiro[l][c]=201;					//se for a primeira coluna ele botará um caractere diferente
					else if(c==31) tabuleiro[l][c]=187;				//para última a mesma coisa acima
					else tabuleiro[l][c]=205;						//para o resto será o caractere padrão
				}else if(l==15){									//se for a última linha
					if(c==0) tabuleiro[l][c]=200;					//o mesmo esquema da primeira condição
					else if(c==31) tabuleiro[l][c]=188;
					else tabuleiro[l][c]=205;
				}
			} 
			else if(c==0 || c==31) tabuleiro[l][c]=186;  // se não for nem a primeira nem a ultima linha, o programa preecherá 
			else tabuleiro[l][c]=' '; 					 // a primeira e a última coluna com caractere padrão(vertical)
		}												//se não for nenhuma das condições a posição será preenchida por										
	}                                                   // caractere em branco
	
		for(l=3;l<13;l+=3){          //Laço para colocar obstáculos no mapa
			for(c=6;c<25;c+=6){
				if(l==3 || l==12){
					if(c==6||c==24) tabuleiro[l] [c]=169;
				}else{
					if(c==12 || c==18) tabuleiro[l][c]=169;
				}
			}
		}
		imprimir(tabuleiro);
		
		printf("Andarilho 1: ");
		scanf("%d %d",&l,&c);
		tabuleiro[l][c]=64;       //arroba
		printf("Andarilho 2: ");
		scanf("%d %d",&x,&y);
		tabuleiro[x][y]=244;      //PI
		system("cls");
		imprimir(tabuleiro);
		system("pause");
			while(l!=x || c!=y){
				sinal1=verificador(tabuleiro,tabuleiro[x][y],l,c,sinal1,auxiliar,pos);  //por padrão o andarilho anda para à direita, pois o sinal inicial que envio, nos dois casos, é igual a '0';
				if(sinal1<=1) c=andar(tabuleiro,sinal1,l,c);
				else l=andar(tabuleiro,sinal1,l,c);
				pos++;
				sinal2=verificador(tabuleiro,tabuleiro[l][c],x,y,sinal2,auxiliar,pos);
				if (sinal2<=1) y=andar(tabuleiro,sinal2,x,y);
				else x=andar(tabuleiro,sinal2,x,y);
				pos=0;
				system("cls");
				imprimir(tabuleiro);
				system("pause");
			}
				
}



