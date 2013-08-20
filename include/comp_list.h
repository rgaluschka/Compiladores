/* COMPONENTES:
	Clemilson Dias
	Arthur Foscarini
	Rafael Galuschka
*/

//estuturas de dados temporárias 
typedef struct comp_list_t {
   int info;
   struct comp_list_t* prox;
   struct comp_list_t* prev;
} comp_list_t;

//assinaturas das funções
int listaVazia(comp_list_t *Lista);
int listaQtdeNodos(comp_list_t *Lista);
comp_list_t* listaCria();
comp_list_t* listaCriaNodo(int info);
void listaInsereNodo(comp_list_t *Lista, comp_list_t *novoNodo);
void listaRemoveNodo(comp_list_t *Lista, int info);
comp_list_t* listaConcatena(comp_list_t *Lista1, comp_list_t *Lista2);
void listaImprime(comp_list_t *Lista);
