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
		aux=raiz->firstChild();
		while(!hijos.empty())
		{
			aux->setNextSibling( retornarCopia(hijos.front().raiz) );
			hijos.pop_front();
			aux=aux->nextSibling();
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
		nuevo->setElement( p->element());
		nuevo->setFirstChild(retornarCopia(p->firstChild()));
		nuevo->setNextSibling(retornarCopia(p->nextSibling()));
		return(nuevo);
 	}
	
}
DOM_Tree DOM_Tree::childNode(int p)
{
	DOM_Tree hijo;
	int posicion;
	Node *aux;
	posicion =1;
	aux=this->raiz->firstChild();
	while(aux!=NULL && posicion<p)
	{
		aux=aux->nextSibling();
		posicion++;
	}
	if(posicion==p && aux!=NULL)
	{
		Node *nuevo = new Node (aux->element(),aux->firstChild(),NULL);
		hijo.raiz=retornarCopia(nuevo);
	}
	return(hijo);
}
void DOM_Tree::appendChild(int p, DOM_Tree hijo)
{
	
	int posicion;
	Node *aux;
	posicion =1;
	aux=this->raiz->firstChild();
	while(aux!=NULL && posicion<p)
	{
		aux=aux->nextSibling();
		posicion++;
	}
	if(posicion==p && aux!=NULL)
	{
		hijo.raiz->setNextSibling(aux->nextSibling());
		aux->setNextSibling(hijo.raiz);
	}
	
}
void DOM_Tree::appendChild(int p, string h)
{
	
	int posicion;
	Node *aux;
	DOM_Tree hijo;
	hijo.convertirEnArbol(h);
	posicion =1;
	aux=this->raiz->firstChild();
	while(aux!=NULL && posicion<p)
	{
		aux=aux->nextSibling();
		posicion++;
	}
	if(posicion==p && aux!=NULL)
	{
		hijo.raiz->setNextSibling(aux->nextSibling());
		aux->setNextSibling(hijo.raiz);
	}
	
}
void DOM_Tree::appendChild(DOM_Tree hijo)
{
	Node *aux;
	Node *ptr;
	
	ptr=this->raiz->firstChild();
	
	while(ptr!=NULL)
	{	
		aux=ptr;
		ptr=ptr->nextSibling();
	}
	hijo.raiz->setNextSibling(NULL);
	aux->setNextSibling(hijo.raiz);
	
}
void DOM_Tree::appendChild(string h)
{
	Node *aux;
	Node *ptr;
	DOM_Tree hijo;
	hijo.convertirEnArbol(h);
	ptr=this->raiz->firstChild();
	
	while(ptr!=NULL)
	{	
		aux=ptr;
		ptr=ptr->nextSibling();
	}
	hijo.raiz->setNextSibling(NULL);
	aux->setNextSibling(hijo.raiz);
	
}
void DOM_Tree::removeChild(int p)
{
	if(p>0)
	{
		DOM_Tree eliminar;
		if(p==1)
		{
			eliminar.raiz=this->raiz->firstChild();
			this->raiz->setFirstChild(eliminar.raiz->nextSibling());
			eliminar.raiz->setNextSibling(NULL);
			
		}
		else
		{
			int posicion;
			Node *aux,*ptr;
	
			posicion =1;
			ptr=this->raiz->firstChild();
		
			while(ptr!=NULL && posicion<p)
			{
				aux=ptr;
				ptr=ptr->nextSibling();
				posicion++;
			}
			if(posicion==p && ptr!=NULL)
			{
				eliminar.raiz=ptr;
				aux->setNextSibling(eliminar.raiz->nextSibling());
				eliminar.raiz->setNextSibling(NULL);
				
			}
		}
		//eliminar.~DOM_Tree();
	
	}
	
}
void DOM_Tree::replaceChild(int p, DOM_Tree reemplazo)
{
	if(p>0)
	{
		DOM_Tree eliminar;
		if(p==1)
		{
			eliminar.raiz=this->raiz->firstChild();
			eliminar.raiz->setNextSibling(NULL);
			this->raiz->setFirstChild(reemplazo.raiz);
			
			
		}
		else
		{
			int posicion;
			Node *aux,*ptr;
	
			posicion =1;
			ptr=this->raiz->firstChild();
		
			while(ptr!=NULL && posicion<p)
			{
				aux=ptr;
				ptr=ptr->nextSibling();
				posicion++;
			}
			if(posicion==p && ptr!=NULL)
			{
				eliminar.raiz=ptr;
				aux->setNextSibling(reemplazo.raiz);
				reemplazo.raiz->setNextSibling(eliminar.raiz->nextSibling());
				eliminar.raiz->setNextSibling(NULL);
				
			}
		}
	//	eliminar.~DOM_Tree();
	
	}
	
}
DOM_Tree DOM_Tree::getElementByID(Element id)
{
	//Node *aux;
	DOM_Tree hijo_id;/*
	aux=this->this->raiz->firstChild();
	while(aux!= NULL && aux->element()!=id)
	{
		aux=aux->nextSibling();
	}
	if(aux!= NULL)
	{
		Node *nuevo=new(aux->element(),aux->firstChild(),NULL)
		hijo_id.raiz=retornarCopia(nuevo);
	}
	return(hijo_id);*/
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

				destruir(p->firstChild());
				destruir(p->nextSibling());
				delete p;
	}
}

void DOM_Tree::operator=(const DOM_Tree &fuente){
	
		this->retornarCopia(fuente.raiz);
	
}

void DOM_Tree::convertirEnArbol(string h){
	Node *nuevo;
	int pos1,pos2;
	Element e;
	
	
	/*std::size_t pos1 = h.find("<");
	std::size_t pos2 = h.find("<");
	
	std::string aux = h.substr(pos+1,pos-1);
	std::size_t pos1 = aux(" ");
	nuevo = new Node()
	
	
*/
	
}
