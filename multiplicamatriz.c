#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(){ 
	int linha, coluna, i, somaprod1, somaprod2, ordem,a;
	struct timeval inicio, final;
	float tmili;

	long matriz4[3][3]={{3,0,0},{0,6,0},{0,0,9}};
	long matriz3[3][3]={{3,0,0},{0,6,0},{0,0,9}};
	long matriz1[3][3]={{7,-2,0},{-2,6,-2},{0,-2,5}};
	long matriz2[3][3]={{7,-2,0},{-2,6,-2},{0,-2,5}};

	ordem=3;	
	gettimeofday(&inicio, NULL);
		
	for(a = 1; a <25; a++)
		for(linha=0; linha< ordem; linha++){
			for(coluna=0; coluna< ordem; coluna++){ 
				somaprod2=0; 
				somaprod1=0; 
				for(i=0; i< ordem; i++){
					somaprod1+=matriz1[linha][i]*matriz2[i][coluna]; 
					somaprod2+=matriz3[linha][i]*matriz4[i][coluna]; 
				}	
				matriz2[linha][coluna]=somaprod1; 					matriz3[linha][coluna]=somaprod2; 

			} 
		}

	gettimeofday(&final, NULL);
	tmili = (float) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	
	for(linha=0; linha< ordem; linha++){ 
		for(coluna=0; coluna< ordem; coluna++) 
			printf("%ld ", matriz2[linha][coluna]); 
		printf("\n"); 
	}  
	for(linha=0; linha< ordem; linha++){ 
		for(coluna=0; coluna< ordem; coluna++) 
			printf("%ld ", matriz3[linha][coluna]); 
		printf("\n"); 
	}  


	 printf("Tempo de execução da multiplicação: %.3f milissegundos\n", tmili);
	return 0;
}
