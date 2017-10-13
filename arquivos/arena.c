#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

void InsereExercito(Arena *arena, int size, INSTR *p, int time) {
	
	for(int i = arena->lastFree; i < 100; i++){
		Maquina robo;
		robo = cria_maquina(p);
		robo->t = time;
		arena->exercitos[i] = robo;
	}

	if(size > 100-arena->lastFree) printf("The Arena is full.\n"); 
}


//Implement quicksort partition. Assim nao precisamos nos preocupar em retirar os robos
void RemoveExercito(Arena *arena,Time t) {
	for(int i = 99; i >=0; i--) {
		if(arena->exercitos[i] != NULL && arena->exercitos[i]->t == t) {
			arena->exercitos[i] = NULL;
		}
	}

	
}	

void Atualiza(Arena *arena, int ciclos) {
   for(int i = 0; i < 100; ++i) {
      exec_maquina(arena->exercitos[i], ciclos);
   }
   arena->tempo += 1;
}

void RemoveMortos(Arena *arena, Time t){
	for(int i = 99; i >=0; i--) {
		if(arena->exercitos[i] != NULL && arena->exercitos[i]->isDead) {
			arena->exercitos[i] = NULL;
		}
	}
}

bool hasCrystal(Grid g, int i, int j){
	return (g[i][j].c > 0);
}

bool hasEnemy(Grid g, int i, int j, Team friendly){
	if(g[i][j].o.ocupado && g[i][j].o.time != friendly)
		return true;
	return false;
}


bool notOcupied(Grid g,Grid g, int i, int j){
	return !g[i][j].o.ocupado;
}

void inicializaGrid(Arena *arena, int nrows, int ncols) {
	arena->grid = malloc(nrows * sizeof(Grid *));
	for(int i = 0; i < nrows; i++) {
	    arena->grid[i] = malloc(ncolumns * sizeof(Grid));
	    if(arena->exercitos[i] == NULL) {
	        fprintf(stderr, "out of memory\n");
	        exit or return
	    }
	}
	for(int j = 0; j < nrows; j++) {
		if (j % 2 == 0) {
			for(int i = 1; i < ncols; i += 2) {
				arena->grid[i][j].o = false;
				arena->grid[i][j].n = i+j;
			}
		}
		else {
			for(int i = 0; i < ncols; i += 2) {
				arena->grid[i][j].o = false;
				arena->grid[i][j].n = i+j;
				
				//TODO: inicializar as outras coisas
				//arena->exercitos[i][j].base
				//arena->exercitos[i][j].

			}
		}
	}
}
