#include <stdio.h>
#include "maq.h"

INSTR prog[] = {


  {NUM, PUSH, { 9, WEST }},
  {NUM, CALL, { 4, WEST }},
  {NUM, PRN, { 0, WEST }},
  {NUM, END, { 0, WEST }},
  {NUM, ALC, { 1, WEST }},
  {NUM, DUP, { 0, WEST }},
  {NUM, STL, { 0, WEST }},
  {NUM, PUSH, { 1, WEST }},
  {NUM, EQ, { 0, WEST }},
  {NUM, JIF, { 13, WEST }},
  {NUM, PUSH, { 1, WEST }},
  {NUM, FRE, { 1, WEST }},
  {NUM, RET, { 0, WEST }},
  {NUM, RCE, { 0, WEST }},
  {NUM, PUSH, { 1, WEST }},
  {NUM, SUB, { 0, WEST }},
  {NUM, CALL, { 4, WEST }},
  {NUM, RCE, { 0, WEST }},
  {NUM, MUL, { 0, WEST }},
  {NUM, FRE, { 1, WEST }},
  {NUM, RET, { 0, WEST }},

};

int main() {
  Arena* battlefield = malloc(sizeof(Arena));
  printf("Arena feita.\n");

  inicializaArena(battlefield, 50, 50); 
  printf("Grid Inicializado.\n");

  InsereExercito(battlefield, 10, prog, BLUE);
  printf("Blue team off to work.\n");

  InsereExercito(battlefield, 10, prog, RED);
  printf("Red team off to work.\n");

  Atualiza(battlefield, 1000);
  for(int i = 0; i < battlefield->firstFree; i++) {
    if(battlefield->exercitos[i]->t == BLUE) printf("B ");
    else printf("R ");
  }

  removeExercito(battlefield, BLUE);
  printf("\n");

  for(int i = 0; i < battlefield->firstFree; i++) {
    if(battlefield->exercitos[i]== NULL) printf("B ");
    else printf("R ");
  }
  printf("\n");
  for(int i = 0; i < battlefield->firstFree; i++){
      if(battlefield->exercitos[i] != NULL)
        printf("Sucesso, bixo.\n");
      else
        printf("Po, bixo\n");
  }
  removeExercito(battlefield, RED);

  for(int i = 10; i < battlefield->firstFree; i++){
      if(battlefield->exercitos[i] != NULL)
        printf("Sucesso, bixo.\n");
  }
  for(int i = 0; i < battlefield->firstFree; i++) {
    if(battlefield->exercitos[i]== NULL) printf("B ");
    else printf("R ");
  }
  return 0;
  
}