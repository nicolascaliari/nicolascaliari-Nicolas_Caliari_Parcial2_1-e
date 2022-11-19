#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->size;
    }
    return retorno;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* auxNode = NULL;

    if(this != NULL && nodeIndex>= 0 && nodeIndex<ll_len(this))
    {
        auxNode = this->pFirstNode;
        for(int i=0; i<nodeIndex; i++)
        {
            auxNode = auxNode->pNextNode;
        }
    }

    return auxNode;
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

    int retorno = -1;

   Node* auxNode = (Node*)malloc(sizeof(Node*));

   Node* auxPrevNode=NULL;


    if(auxNode != NULL && this != NULL && nodeIndex >= 0 && pElement != NULL && nodeIndex<=ll_len(this))
    {
        auxNode->pElement=pElement;

        if(nodeIndex == 0)
        {

            auxNode->pNextNode = this->pFirstNode;
            this->pFirstNode = auxNode;
            this->size++;
            retorno=0;
        }
        else
        {
           auxPrevNode = getNode(this,nodeIndex-1);

           if(auxPrevNode != NULL)
           {
               auxNode->pNextNode = auxPrevNode->pNextNode;
               auxPrevNode->pNextNode = auxNode;
               this->size++;
               retorno=0;
           }


        }



    }



    return retorno;
}

int ll_add(LinkedList* this, void* pElement)
{

    int retorno=-1;

    if(this != NULL && pElement != NULL)
    {

        if(addNode(this, ll_len(this), pElement)==0)
        {

            retorno=0;

        }


    }



    return retorno;

}

void* ll_get(LinkedList* this, int index)
{
    Node* auxNode = NULL;
    void* pRetorno = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {

       auxNode = getNode(this, index); //Validar.

       pRetorno = auxNode->pElement;

    }

    return pRetorno;
}

int ll_set(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;
    Node* auxNode = NULL;

    if(this != NULL && pElement != NULL && index >= 0 && index < ll_len(this))
    {

        auxNode = getNode(this, index);
        auxNode->pElement = pElement;
        retorno = 0;

    }


    return retorno;
}


int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    Node* auxNode = NULL;
    Node* auxPrevNode = NULL;

    retorno=-1;

    if(this != NULL && index >= 0 && index < ll_len(this)){

        auxNode = getNode(this,index);

        if(index==0){

            this->pFirstNode=auxNode->pNextNode;
            this->size--;


        }else{

            auxPrevNode = getNode(auxNode,index-1);
            auxPrevNode->pNextNode = auxNode->pNextNode;
            this->size--;

        }
        free(auxNode);
        retorno=0;

    }

    return retorno;
}

int ll_clear(LinkedList* this) {
    int retorno = -1;
    int longitudLinkedList = ll_len(this);
    if (this != NULL && longitudLinkedList > 0) {
        for (int i = 0; i < longitudLinkedList; i++) {
            ll_remove(this, 0); // Elimina los nodos segun indice
        }
        retorno = 0;
    }
    return retorno;
}

int ll_deleteLinkedList(LinkedList* this) {
    int retorno = -1;
    if (this != NULL) {
        ll_clear(this);
        free(this); // Elimina puntero estructura linkedlist
        retorno = 0;
    }
    return retorno;
}

int ll_indexOf(LinkedList* this, void* pElement) {
    int retorno = -1;
    int longitudLinkedlist = ll_len(this);
    Node* auxNode;
    if (this != NULL && pElement != NULL && longitudLinkedlist > 0) {
        for (int i = 0; i < longitudLinkedlist; i++) {
            auxNode = getNode(this, i);
            if (auxNode != NULL && auxNode->pElement == pElement) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int ll_isEmpty(LinkedList* this)
{
    int retorno=-1;//null
    if(this!=NULL)
    {
        if(ll_len(this)>0)
        {
            retorno=0;//no vacia
        }
        else
        {
            retorno=1;//vacia
        }

    }
    return retorno;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno=-1;
    if(this!=NULL && index>=0  && index<=ll_len(this) && pElement!=NULL)
    {   //validar funcion
        addNode(this,index,pElement);
        retorno=0;
    }
    return retorno;
}

void* ll_pop(LinkedList* this,int index)
{
    void* retorno=NULL;
    void * auxPElement;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {   auxPElement=ll_get(this,index);
        if(auxPElement!=NULL)
        {
            retorno=auxPElement;
            ll_remove(this,index);
        }
    }
    return retorno;

}

//Me dice si un elemento esta dentro de una linkedlist
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno=-1;//null
    if(this!=NULL && pElement!=NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {
            retorno=1;//si contiene
        }
        else
        {
            retorno=0;//si no contiene
        }
    }
    return retorno;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno=-1;
    int len;
    if(this!=NULL && this2!=NULL)
    {  //ver si hay que validar que una list2 sea menor que list
        len=ll_len(this2);
        if(len==0)
        {
            retorno=0;
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if(ll_contains(this,ll_get(this2,i))==0)
                {
                    retorno=0;//no contiene
                    break;
                }
                else
                {
                    retorno=1;//contiene
                }
            }
        }
    }
    return retorno;
}

LinkedList* ll_subList(LinkedList* this,int from,int to) {
    LinkedList* subList = NULL;
    void*auxPElement;

    if(this != NULL && to > from && to <= ll_len(this) && from >= 0 && from < ll_len(this))
    {
        subList = ll_newLinkedList();
        if(subList != NULL)
        {
            for(int i = from ; i < to ; i++)
            {
                auxPElement = ll_get(this,i);
                if(auxPElement != NULL)
                {
                    ll_add(subList,auxPElement);

                }
            }
        }
    }
    return subList;
}


LinkedList* ll_clone(LinkedList* this) {
    LinkedList* cloneList = NULL;
    if(this != NULL) {
        cloneList = ll_subList(this,0,ll_len(this));
    }
    return cloneList;
}







/*
 * \brief Cuenta la cantidad de elementos que cumplen con el criterio que es definido por la funcion que recibe como parametro!
 *  \param this LinkedList puntero a la lista
 *  \param fn funcion a aplicar
 *  \return el acumulado
 */
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int acumulador = 0;
	int i;
    void* aux;
    int longitud;
    if(this!=NULL)
    {
		longitud = ll_len(this);
        for(i = 0; i < longitud; i++)
        {
            aux = (void*)ll_get(this,i);
            acumulador += fn(aux);
        }
    }
	return acumulador;
}
