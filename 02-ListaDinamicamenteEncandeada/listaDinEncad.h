//Arquivo listaDinEncad.h
struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct elemento* Lista;
//Assinatura das fun??es
Lista* cria_lista();//ok
void libera_lista(Lista* li);//ok
int tamanho_lista(Lista* li);//ok
int lista_vazia(Lista* li);//ok
int insere_lista_inicio(Lista* li, struct aluno al);//ok
int remove_lista_inicio(Lista* li);//ok
int insere_lista_final(Lista* li, struct aluno al);//ok
int insere_lista_ordenada(Lista* li, struct aluno al);//ok
void imprime_lista(Lista* li);//ok
int remove_lista_final(Lista* li);//ok
int remove_lista(Lista* li, int mat);//ok
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);//ok
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);//ok
