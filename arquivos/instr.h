/* Códigos das instruções */
<<<<<<< Updated upstream
typedef enum {
  BLUE,
  RED
} Time;

typedef struct {
  int[100][100] grid;
} Grid;
=======
>>>>>>> Stashed changes

#include "structures.h"
//#include "maq.h"
typedef enum {
  PUSH,
  POP,
  DUP,
  ADD,
  SUB,
  MUL,
  DIV,
  JMP,
  JIT,
  JIF,
  CALL,
  RET,
  STS,
  RCS,
  EQ,
  GT,
  GE,
  LT,
  LE,
  NE,
  STO,
  RCL,
  END,
  PRN,
  STL,
  RCE,
  ALC,
  FRE,
  ATR
} OpCode;

typedef struct {
  int n;
} Cristais;

typedef struct {
  int busy;
} Ocupacao;

typedef struct  {
  int isBase;
  Time team;
} Base; 

typedef struct {
  Terreno t;
  Base b;
  Cristais c;
  Ocupacao o;
} Celula

typedef enum {
  ESTRADA,
  RIO,
  MONTANHA,
  LAMA,
  CAMPO
} Terreno;
/* Tipos dos operandos */
/* no momento, são todos inteiros */
typedef enum {
  NUM,
  ACAO,
  VAR

} Tipo;

/* } OPERANDO; */
typedef int OPERANDO;

<<<<<<< Updated upstream
=======
typedef struct {
  Tipo t;
  Maquina **chamador;
  union {
    int n;
    int ac;
    int v;
  };
}OPERANDO;
>>>>>>> Stashed changes
/* Instrução */
typedef struct {
  OpCode instr;
  OPERANDO op;
} INSTR;
