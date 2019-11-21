#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex < this->size)
        {
            pNode = this->pFirstNode;
            for(int i = 0; i < nodeIndex; i++)
            {
                pNode = pNode->pNextNode;
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    if(this != NULL && nodeIndex <= this->size && nodeIndex >= 0)
    {
        Node* newNode = (Node*) malloc(sizeof(Node));

        newNode->pElement = pElement;

        if(nodeIndex == 0 && this->size == 0)
        {
            newNode->pNextNode = NULL;
            this->pFirstNode = newNode;
            this->size = (this->size)+1;
        }else if(nodeIndex == 0 && this->size > 0)
        {
            newNode->pNextNode = this->pFirstNode;
            this->pFirstNode = newNode;
            this->size = (this->size)+1;
        }else if(nodeIndex > 0 && nodeIndex < ll_len(this))
        {
            newNode->pNextNode = getNode(this, nodeIndex);
            getNode(this, nodeIndex-1)->pNextNode = newNode;
            this->size = (this->size)+1;
        }else if(nodeIndex > 0 && nodeIndex == ll_len(this))
        {
            getNode(this, nodeIndex-1)->pNextNode = newNode;
            newNode->pNextNode = NULL;
            this->size = (this->size)+1;
        }

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;

    if(this != NULL)
    {
        newNode = (Node*) malloc(sizeof(Node));
        newNode->pElement = pElement;
        newNode->pNextNode = NULL;

        if(this->size == 0)
        {
            this->pFirstNode = newNode;
            this->size = (this->size)+1;
        }else
        {
            (getNode(this, (this->size)-1))->pNextNode = newNode;
            this->size = (this->size)+1;
        }

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodeAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        nodeAux = getNode(this, index);
        returnAux = (void*) nodeAux->pElement;
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodeAux = NULL;

    if(this != NULL && index >= 0 && index < this->size)
    {
        nodeAux = getNode(this, index);
        nodeAux->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(index == 0)
        {
            nodeAux = getNode(this, 0);
            this->pFirstNode = nodeAux->pNextNode;
            free(nodeAux);
        }else if(index > 0 && index != (ll_len(this)-1))
        {
            nodeAux = getNode(this, index);
            getNode(this, index-1)->pNextNode = nodeAux->pNextNode;
            free(nodeAux);
        }else if(index > 0 && index == (ll_len(this)-1))
        {
            nodeAux = getNode(this, index);
            getNode(this, index-1)->pNextNode = NULL;
            free(nodeAux);
        }

        this->size = (this->size)-1;

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        for(int i = 0; i < ll_len(this); i++)
        {
            ll_remove(this, i);
        }
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int clearAux;
    clearAux = ll_clear(this);

    if(this != NULL && clearAux == 0)
    {
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL)
    {
        pNode = this->pFirstNode;
        for(int i = 0; i < ll_len(this); i ++)
        {
            if(pNode->pElement == pElement)
            {
                returnAux = i;
                break;
            }
            pNode = pNode->pNextNode;
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && this->size == 0)
    {
        returnAux = 1;
    }else if(this != NULL && this->size > 0)
    {
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = getNode(this, index)->pElement;
        ll_remove(this, index);
    }

    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_indexOf(this, pElement) > -1)
        {
            returnAux = 1;
        }else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int contador = 0;

    if(this != NULL && this2 != NULL)
    {
        Node* nodeAux = this2->pFirstNode;

        for(int i = 0; i < ll_len(this2); i++)
        {
            if(ll_contains(this, nodeAux->pElement) == 1)
            {
                contador++;
            }

            nodeAux = nodeAux->pNextNode;
        }

        if(contador == ll_len(this2) && contador > 0)
        {
            returnAux = 1;
        }else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int contador;

    if(this != NULL && from >= 0 && to <= this->size)
    {
        cloneArray = ll_newLinkedList();
        for(contador = from; contador < to; contador++)
        {
            pElement = ll_get(this, contador);
            ll_add(cloneArray, pElement);
        }
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, this->size);
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pAux = NULL;
    void* pElement = NULL;
    void* pNextElement = NULL;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(int i = 0; i < (this->size-1); i++)
        {
            pElement = ll_get(this, i);

            for(int j = i+1; j < (this->size); j++)
            {
                pNextElement = ll_get(this, j);

                if(pFunc(pElement, pNextElement) < 0 && order == 0)
                {
                    pAux = pElement;
                    pElement = pNextElement;
                    pNextElement = pAux;
                }else if(pFunc(pElement, pNextElement) > 0 && order == 1)
                {
                    pAux = pNextElement;
                    pNextElement = pElement;
                    pElement = pAux;
                }

                ll_set(this, i, pElement);
                ll_set(this, j, pNextElement);
            }
        }

        returnAux = 0;
    }

    return returnAux;
}
