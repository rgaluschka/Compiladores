/* COMPONENTES:
	Clemilson Dias
	Arthur Foscarini
	Rafael Galuschka
*/

//estuturas de dados temporárias 
typedef struct comp_tree_t {
   int qtdeFilhos;
   struct comp_tree_t *filhos[];
} comp_tree_t;

//assinaturas das funções
int arvoreVazia(comp_tree_t *Arvore);
comp_tree_t* arvoreCria();
comp_tree_t* arvoreCriaNodo(int qtdeFilhos);
int arvoreInsereNodo(comp_tree_t *Raiz, comp_tree_t *novoNodo);
void arvoreRemoveNodo1(comp_tree_t *Nodo);
void arvoreImprime(comp_tree_t *Arvore);
void arvoreRemoveNodo(comp_tree_t *Arvore, comp_tree_t *Nodo);
