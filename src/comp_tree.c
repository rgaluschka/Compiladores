/* COMPONENTES:
	Clemilson Dias
	Arthur Foscarini
	Rafael Galuschka
*/

#include <stdlib.h>
#include <stdio.h>
#include "comp_tree.h"

//função que verifica se a árvore informada por parâmetro está vazia
int arvoreVazia(comp_tree_t *Arvore) {
   return Arvore == NULL;
}

//função que inicializa uma árvore - retorna um ponteiro NULL
comp_tree_t* arvoreCria() {
   comp_tree_t *p;

   p = NULL;
   return p;
}

//função que cria um nodo da árvore
comp_tree_t* arvoreCriaNodo(int qtdeFilhos) {
   comp_tree_t *novoNodo;
   int i;

   novoNodo = (comp_tree_t *) malloc(sizeof(comp_tree_t) + sizeof(int) * qtdeFilhos);

   novoNodo->qtdeFilhos = qtdeFilhos;
   for (i = 0; i < qtdeFilhos; i++)
      novoNodo->filhos[i] = NULL;

   return novoNodo;
}

//função que insere um nodo na árvore. Retorna 0 se der erro e 1 se ok.
int arvoreInsereNodo(comp_tree_t *Raiz, comp_tree_t *novoNodo) {
   comp_tree_t *aux = Raiz;
   int i;

   //percorro o array de filhos dessa raiz
   i = 0;
   while (i < Raiz->qtdeFilhos) 
   {
      //verifico se é posição válida
      if (Raiz->filhos[i] == NULL)
      {
         //é, aponto essa posição para o novo nodo
         Raiz->filhos[i] = novoNodo;
         return 1;
      }
      //continuo a procura
      i = i + 1;
   }
   //se cheguei aqui é porque não havia posições disponíveis
   return 0;
}

//função que remove um nodo da árvore
void arvoreRemoveNodo1(comp_tree_t *Nodo) {
   int i;

   if (arvoreVazia(Nodo) == 1)
      return;
   //percorro o array de filhos recursivamente, liberando-os
   i = 0;
   while (i < Nodo->qtdeFilhos)
   {
      //verifico se tem nodo filho
      if (Nodo->filhos[i] != NULL)
      {
         //tem...removo-o
         arvoreRemoveNodo1(Nodo->filhos[i]);
      }
      i = i + 1;
   }
   //libero o nodo
   free(Nodo);
   return;       
}

//função que remove um nodo da árvore (e todos os seus filhos)
void arvoreRemoveNodo(comp_tree_t *Arvore, comp_tree_t *Nodo) {
   comp_tree_t *aux;
   int i;

   aux = Arvore;
   //verifico se a árvore está vazia
   if (arvoreVazia(aux) == 1)
      return;
   //verifico se o nodo a ser excluído é a raiz
   if (aux == Nodo)
      {
        //é...percorro o array de filhos, liberando-os
        arvoreRemoveNodo1(aux);
        return;
      }
   else
      {
        //percorro os filhos da árvore até achar o nodo a ser excluído
        i = 0;
        while (i < aux->qtdeFilhos)
        {
          arvoreRemoveNodo(aux->filhos[i], Nodo);
          i = i + 1;
        }
      }
   //se cheguei aqui é porque o nodo não foi encontrado na árvore
   return;
}

//função que imprime a árvore
void arvoreImprime(comp_tree_t *Arvore) {
   comp_tree_t *aux;
   int i;

   aux = Arvore;
   //verifico se a árvore está vazia
   if (arvoreVazia(aux) == 1)
      return;
   //imprimo o nodo
   printf("Nodo com %d filhos.\n",Arvore->qtdeFilhos);
   //percorro os filhos da árvore até achar o nodo a ser excluído
   i = 0;
   while (i < aux->qtdeFilhos)
   {
     printf("Iniciando subarvore %d.\n",i);
     arvoreImprime(aux->filhos[i]);
     printf("Terminando subarvore %d.\n",i);
     i = i + 1;
   }
   return;
}
