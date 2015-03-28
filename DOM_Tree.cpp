/*
 * DOM_Tree.cpp
 *
 *  Created on: 27/3/2015
 *      Author: yorbel y samuel
 */
#include "DOM_Tree.h"
DOM_Tree::DOM_Tree()
{
	raiz=NULL;
}
DOM_Tree::DOM_Tree(Element r, list<DOM_Tree> hijos)
{
	raiz= new Node(r,NULL,NULL);
	
	if(!hijos.empty())
	{
		Node *aux;
		raiz->setFirstChild(retornarCopia(hijos.front().raiz));
		hijos.pop_front();
		aux=raiz->getFirstChild();
		while(!hijos.empty())
		{
			aux->setNextSibling( retornarCopia(hijos.front().raiz) );
			hijos.pop_front();
			aux=aux->getNextSibling();
		}
	
	}
}
DOM_Tree::DOM_Tree(const DOM_Tree &fuente)
{

	this->raiz=retornarCopia(fuente.raiz);
}
Node* DOM_Tree::retornarCopia(Node *p) const
{
	 
	if(p==NULL)
	{
		return(NULL);
	}
	else
	{
		Node *nuevo = new Node;
		nuevo->setElement( p->getElement());
		nuevo->setFirstChild(retornarCopia(p->getFirstChild()));
		nuevo->setNextSibling(retornarCopia(p->getNextSibling()));
		return(nuevo);
 	}
	
}
DOM_Tree DOM_Tree::childNode(int p)
{
	DOM_Tree hijo;
	if()
}
