typedef int Item;

typedef struct stacknode* stackp;

struct stacknode{
  Item conteudo;
  stackp prox;
};

typedef struct stacknode stackNode;


void *mallocSafe (int);
stackp stackInit();
int stackEmpty(stackp);
void stackPush(stackp, Item);
Item stackPop(stackp);
Item stackTop(stackp);
void stackFree(stackp);
void stackDump(stackp);


  
