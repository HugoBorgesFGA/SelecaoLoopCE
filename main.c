/*
 * main.c
 *
 *  Created on: 12/02/2015
 *      Author: hugo
 *      Description: Coding for food :)
 */

#include <stdlib.h>
#include <stdio.h>

int main(){
	// Variáveis principais do problema :)
	FILE *arquivo;
	unsigned char tmp, i, letra;

	// Tenta abrir o arquivo e saltar as 54 (0x36) posições do cabeçalho
	arquivo = fopen("testImage.bmp", "r");
	fseek(arquivo, 0x36, SEEK_SET);

	// Sai pegando conjunto de 8 bytes com esteganografia para formar 1 byte
	// de informação útil. A variável letra armazena o byte útil, ou seja,
	// um caractere da mensagem.
	do{
		// Inicia
		letra = 0x00;

		for(i = 0; i < 8; i++){
			// Pega um pixel da imagem (8 bits)
			fscanf(arquivo, "%c", &tmp);

			// Desloca o bit menos significante para compor a letra
			// Pega o bit menos significativo do byte: tmp & 0x01
			// Desloca ele de acordo com sua posição interna i: x << i
			// Acumula com os resultados anteriores para composição do byte: letra |=
			letra |= (tmp & 0x01) << i;
		}

		// Printa o caractere na tela :)
		printf("%c", letra);
	}while(letra != '\0');


	// Fim:
	printf("\n\n Cheguei ao fim :)");
}
