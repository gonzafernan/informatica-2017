#ifndef headers_h
#define headers_h

struct posicion{
  int x;
  int y;
  struct posicion *hijos[8];
};

extern int matriz[10][10];

int main();
int recorre(struct posicion *A, struct posicion *B);

#endif
