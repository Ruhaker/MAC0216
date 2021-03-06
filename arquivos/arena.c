#include "arena.h"
#include <stdio.h>
#include <stdlib.h>


void inicializaArena(Arena *arena, int nrows, int ncols) {
	/*(arena, #linhas, #coluna) -> void
	Aloca dinamicamente uma matrix de células de tamanho nrowsxncols.
	Para fins de simplicidade incializamos "aleatoriamente" algumas
	células com cristais. Além disso, colocamos bases dos times, além de
	indicar que as células estão desocupadas. Esta função deve sempre ser
	chamada no início do jogo.*/
	arena->rows = nrows;
	arena->cols = ncols;
	arena->tempo = 0;
	arena->firstFree = 0;
	srand(time(NULL));
	arena->grid = (Celula **) malloc(sizeof(Celula *) * ncols);
	int i;
	for(i = 0; i < ncols; i++) {
	    arena->grid[i] = (Celula *) malloc(sizeof(Celula) * nrows);
	}

	for(int j = 0; j < nrows; j++) {
		if (j % 2 == 0) {
			for(int i = 1; i < ncols; i += 2) {
				arena->grid[i][j].o.ocupado = False;
				//Gera o terreno da case (i,j). Implementacao bem simples sem agrupamento
				arena->grid[i][j].t = rand() % 5;
				arena->grid[i][j].b.isBase = False;
				arena->grid[i][j].c = False;
				//Sets the bases
				if (j < 2) {
					arena->grid[i][j].b.isBase = True;
					arena->grid[i][j].b.team = BLUE;	
				}
				if (j >= nrows-2) {
					arena->grid[i][j].b.isBase = True;
					arena->grid[i][j].b.team = RED;	
				}
			}			
		}
		else {
			for(int i = 0; i < ncols; i += 2) {
				arena->grid[i][j].o.ocupado = False;
				//Gera o terreno da case (i,j). Implementacao bem simples sem agrupamento
				arena->grid[i][j].t = rand() % 5;
				arena->grid[i][j].b.isBase = False;
				arena->grid[i][j].c = False;
				//Sets the bases
				if (j < 2) {
					arena->grid[i][j].b.isBase = True;
					arena->grid[i][j].b.team = BLUE;	
				}
				if (j >= nrows-2) {
					arena->grid[i][j].b.isBase = True;
					arena->grid[i][j].b.team = RED;	
				}
			}
		}

	}
	for(int i = 0; i <= ncols; i++) {
		arena->grid[rand() % ncols ][rand() % (nrows)].c = True;
	}
}


void InsereExercito(Arena *arena, int size, INSTR *p, Time team) {
  	/*(arena, size, instruções, time) -> void
  	Insere no vetor de máquinas da Arena uma quantidade size de robôs de um time team*/
  	if(size > 100-arena->firstFree) {
  		printf("The Arena is full.\n");
  		return;
  	}
  	
	for(int i = arena->firstFree; i < size + arena->firstFree; i++){
		Maquina *robo;
		robo = cria_maquina(p);
		
		robo->t = team;
		arena->exercitos[i] = robo;
		robo->crystals = 0;
		robo->alive = True;
		robo->x = 1;
		robo->y = 0;
		
	}
	arena->firstFree += size;
	
}




void Atualiza(Arena *arena, int ciclos) {
	/*(arena, ciclos) -> 
	Executa, dado um time t, um número ciclos de vezes o vetor de instruções dos
	robôs daquele time.*/
    
    for(int i = 0; i < arena->firstFree; ++i) {
      exec_maquina(arena, arena->exercitos[i], ciclos);
    }
    arena->tempo += 1;
}

int tapaBuraco(Maquina* m[], int firstFree) {
	int i = -1, j = firstFree+1;
	while(1) {
		while(m[++i] != NULL);
		while(m[--j] == NULL);
		if(j < i ) break;
		Maquina* tmp = m[i];
		m[i] = m[j];
		m[j] = tmp;
	}
	if(j < 0)
		j = 0;
	else
		j++;
	return j;
}

void RemoveMortos(Arena *arena, Time t) {
	/*(arena, time) -> 
	Remove, dado um time t, do vetor de máquinas da arena, apenas aqueles que
	estão mortos. Ou seja, sua variável alive == true.*/
	
	for(int i = 0; i < arena->firstFree; i++) {
		if(arena->exercitos[i] != NULL && !arena->exercitos[i]->alive) {
			arena->exercitos[i] = NULL;
		}
	}
	arena->firstFree = tapaBuraco(arena->exercitos, arena->firstFree);
}

void removeExercito(Arena *arena, Time t) {
	/*(arena, time) -> void
	Dado um time t, descarta todos os robôs daquele time no vetor de máquinas da arena.
	Depois reoganiza os robôs para liberar espaço no vetor de robôs.*/

	for(int i = 0; i < arena->firstFree; i++) {
		if(arena->exercitos[i] != NULL && arena->exercitos[i]->t == t) {
			arena->exercitos[i] = NULL;
		}
	}


	arena->firstFree = tapaBuraco(arena->exercitos, arena->firstFree);
}	

// Funções simples para uma leitura melhor de funções anteriores
// Em especial as chamadas de sistema

Bool hasCrystal(Grid g, int i, int j) {
	return (g[i][j].c > 0);
}

Bool hasEnemy(Grid g, int i, int j, Time friendly) {
	if(g[i][j].o.ocupado && g[i][j].o.team != friendly)
		return True;
	return False;
}


Bool occupied(Grid g, int i, int j) {
	return g[i][j].o.ocupado;
}



