/* COMPONENTES:
	Clemilson Dias
	Arthur Foscarini
	Rafael Galuschka
*/

//estuturas de dados temporárias 
typedef struct {
   char *chave;
   struct comp_dict_item_t *prox;
} comp_dict_item_t;

typedef struct {
   int info;
   comp_dict_item_t *Itens;
} comp_dict_t;

//assinatura das funções
int dicionarioExiste(comp_dict_t *Dicionario);
comp_dict_t* dicionarioCria(int info);
comp_dict_item_t* dicionarioCriaItem(char *chave);
void dicionarioInsereItem(comp_dict_t *Dicionario, comp_dict_item_t *novoItem);
int dicionarioProcuraChave(comp_dict_t *Dicionario, char *Chave);
void dicionarioRemoveChave(comp_dict_t *Dicionario, char *Chave);
void dicionarioRemove(comp_dict_t *Dicionario);
void dicionarioImprime(comp_dict_t *Dicionario);
