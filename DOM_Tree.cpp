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
	int posicion;
	Node *aux;
	posicion =1;
	aux=this->raiz->getFirstChild();
	while(aux!=NULL && posicion<p)
	{
		aux=aux->getNextSibling();
		posicion++:
	}
	if(posicion==p && aux!=NULL)
	{
		Node *nuevo = new(aux->getElement(),aux->getFirstChild(),NULL);
		hijo.raiz=retornarCopia(nuevo);
	}
	return(hijo);
}
void DOM_Tree::appendChild(int p, DOM_Tree hijo)
{
	
	int posicion;
	Node *aux;
	posicion =1;
	aux=this->raiz->getFirstChild();
	while(aux!=NULL && posicion<p)
	{
		aux=aux->getNextSibling();
		posicion++:
	}
	if(posicion==p && aux!=NULL)
	{
		hijo.raiz->setNextSibling(aux->getNextSibling());
		aux->getNextSibling(hijo.raiz);
	}
	
}
void DOM_Tree::appendChild(int p, string h)
{
	
	int posicion;
	Node *aux;
	DOM_Tree hijo;
	hijo.convertirEnArbol(h);
	posicion =1;
	aux=this->raiz->getFirstChild();
	while(aux!=NULL && posicion<p)
	{
		aux=aux->getNextSibling();
		posicion++:
	}
	if(posicion==p && aux!=NULL)
	{
		hijo.raiz->setNextSibling(aux->getNextSibling());
		aux->getNextSibling(hijo.raiz);
	}
	
}
void DOM_Tree::appendChild(DOM_Tree hijo)
{
	Node *aux;
	Node *ptr;
	
	ptr=this->raiz->getFirstChild();
	
	while(ptr!=NULL)
	{	
		aux=ptr;
		ptr=ptr->getNextSibling();
	}
	hijo.raiz->setNextSibling(NULL);
	aux->getNextSibling(hijo.raiz);
	
}
void DOM_Tree::appendChild(string h)
{
	Node *aux;
	Node *ptr;
	DOM_Tree hijo;
	hijo.convertirEnArbol(h);
	ptr=this->raiz->getFirstChild();
	
	while(ptr!=NULL)
	{	
		aux=ptr;
		ptr=ptr->getNextSibling();
	}
	hijo.raiz->setNextSibling(NULL);
	aux->getNextSibling(hijo.raiz);
	
}
void DOM_Tree::removeChild(int p)
{
	if(p>0)
	{
		DOM_Tree eliminar;
		if(p==1)
		{
			eliminar.raiz=this->raiz->getFirstChild();
			this->raiz->setFirstChild(eliminar.raiz->getNextSibling());
			eliminar.raiz->setNextSibling(NULL);
			
		}
		else
		{
			int posicion;
			Node *aux,*ptr;
	
			posicion =1;
			ptr=this->raiz->getFirstChild();
		
			while(ptr!=NULL && posicion<p)
			{
				aux=ptr;
				ptr=ptr->getNextSibling();
				posicion++:
			}
			if(posicion==p && ptr!=NULL)
			{
				eliminar.raiz=ptr;
				aux->setNextSibling(eliminar.raiz->getNextSibling());
				eliminar.raiz->setNextSibling(NULL);
				
			}
		}
		eliminar.~DOM_Tree();
	
	}
	
}
void DOM_Tree::replaceChild(int p, DOM_Tree reemplazo)
{
	if(p>0)
	{
		DOM_Tree eliminar;
		if(p==1)
		{
			eliminar.raiz=this->raiz->getFirstChild();
			eliminar.raiz->setNextSibling(NULL);
			this->raiz->setFirstChild(reemplazo.raiz);
			
			
		}
		else
		{
			int posicion;
			Node *aux,*ptr;
	
			posicion =1;
			ptr=this->raiz->getFirstChild();
		
			while(ptr!=NULL && posicion<p)
			{
				aux=ptr;
				ptr=ptr->getNextSibling();
				posicion++:
			}
			if(posicion==p && ptr!=NULL)
			{
				eliminar.raiz=ptr;
				aux->setNextSibling(reemplazo.raiz);
				reemplazo.raiz->setNextSibling(eliminar.raiz->getNextSibling());
				eliminar.raiz->setNextSibling(NULL);
				
			}
		}
		eliminar.~DOM_Tree();
	
	}
	
}
DOM_Tree DOM_Tree::getElementByID(Element id)
{
	Node *aux;
	DOM_Tree hijo_id;
	aux=this->this->raiz->getFirstChild();
	while(aux!= NULL && aux->getElement()!=id)
	{
		aux=aux->getNextSibling();
	}
	if(aux!= NULL)
	{
		Node *nuevo=new(aux->getElement(),aux->getFirstChild(),NULL)
		hijo_id.raiz=retornarCopia(nuevo);
	}
	return(hijo_id);
}
DOM_Tree::~DOM_Tree()
{
	destruir(this->raiz);
	this->raiz=NULL;
}
void DOM_Tree::destruir(Node *p)
{
	if(p!= NULL)
	{

				destruir(p->getFirstChild());
				destruir(p->getNextSibling());
				delete p;
	}
}

void DOM_Tree::convertirEnArbol(strin h){
	Node *p;
}
