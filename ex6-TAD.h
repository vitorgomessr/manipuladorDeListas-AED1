typedef struct no * lista;

lista cria_lista();
int lista_vazia(lista A);
int insere_elem(lista *A, int elem);
int remove_elem(lista *A, int elem);
int get_elem_pos(lista A, int pos);
void apaga_lista(lista *A);
int remove_maior(lista *A);
int remove_pares(lista *A);
int insere_posicao(lista *A, int pos, int elem);
int inverte_lista(lista *A, lista *B);
