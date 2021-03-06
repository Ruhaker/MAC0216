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
  {ACAO, ATTK, { 0, NEAST }},
  {INTER, PUSH, { 0, NWEST }},
};
int main(){
  Arena* battlefield = malloc(sizeof(Arena));

  printf("Arena feita.\n");
  inicializaArena(battlefield, 10, 10); 
  printf("Grid Inicializado.\n");
  InsereExercito(battlefield, 10, prog, BLUE);
  printf("Blue team off to work.\n");
  InsereExercito(battlefield, 10, prog, RED);
  
  printf("Red team off to work.\n");
  Atualiza(battlefield, 1000);
  Atualiza(battlefield, 1000);
  Atualiza(battlefield, 1000);
  Atualiza(battlefield, 1000);
  Atualiza(battlefield, 1000);
  Atualiza(battlefield, 1000);
  

  return 0;
  
}