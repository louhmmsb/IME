typedef char Item;
typedef struct queuenode* queuep;
struct queuenode{
  Item conteudo;
  queuep prox;
};

void *mallocSafe (int nbytes);

typedef struct queuenode queueNode;

static queuep new(Item item, queuep next);

void queueInit();

int queueEmpty();

void queuePut (Item item);


Item queueGet();

void freeQueue();

    
