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
	DOM_Tree hijo;std::cout<<1<<std::endl;
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
	Node *nuevo,*act;
	Node *hermano=NULL;
	string aux,name,auxAtributo,inner;
	int pos1,pos2;
	bool band,es_hermano=false;
	list<string> L;
	Element e;
	  Element f,g;

	pos1 = h.find("<"); pos2 = h.find(">");
	//cout<<"esta son las pos "<<pos1<<pos2<<endl;
	aux = h.substr(pos1+1 , pos2-1);
	//cout<<"raiz"<<aux<<endl;
	nuevo = new Node (aux);
	act = raiz = nuevo;

	 h = h.substr(pos2+1);
	///ya tengo la raiz
	while(!h.empty()){
	
	 
	  //cout<<h<<endl<<endl<<endl;
	  esCerrado(h,aux,pos1,pos2,band);
	  

	  
	    //buscar atributos
	    if(band == false){
	      	//  cout<<" nombre de la etiqueta "<<aux<<endl;
		//  cout<<"es resto de la cadena "<<h<<endl;
		  pos1 = aux.find(" ");
		  if(pos1 != -1){
		  
		    name = aux.substr(0,pos1);
		    aux = aux.substr(pos1+1);
		  
		  //revisar;
		    while(!aux.empty()){
			pos1 = aux.find(" ");
			if(pos1 != -1){
			    auxAtributo = aux.substr(0,pos1);
			    L.push_back(auxAtributo);
			    aux =aux.substr(pos1+1);
			  
			}else{
			    L.push_back(aux);
			    aux.clear();	  
			}	
		    }
		
		    
		  }else{
		    name = aux;
		  }
		  
		//es porque hay un inner 
		if(h[0] != '<'){
		  
		    pos1 = h.find("<");
		    inner = h.substr(0,pos1);
		    h = h.substr(pos1);
		    
		    e.setTagName(name);
		    if(!L.empty())
		      e.setAttrList(L);
		    
		    e.setInnerHTML(inner);
		    
		//  cout<<endl<<inner<<endl;
		}else{
		  
		      e.setTagName(name);
		      if(L.empty())
		      e.setAttrList(L);
		  
		}
		//cout<<" name"<<name<<"hola bebe"<<e.tagName()<<endl;
	//	cout<<"inner "<<inner<<endl;
		//cout<<"es resto de la cadena2 "<<h<<endl;
		nuevo = new Node(e);
		
		if(es_hermano){
		  hermano->setNextSibling(nuevo);
		  //y me falta colocar que apunte a el
		  f =hermano->element();
		  g = hermano->nextSibling()->element();
		  cout<<"este es mi hermano "<<f.tagName()<<" es el derecho "<<g.tagName()<<endl<<endl;
		  es_hermano = false;
		}else{
		  f =nuevo->element();
		 cout<<" el tag "<<f.tagName()<<endl; 
		  act->setFirstChild(nuevo);
		//  f = act->firstChild()->element();
		//    cout<<" el  elemento "<<f.tagName()<<endl;
		}
		
	      act = nuevo;
	      
	    }else{
	      
		aux = aux.substr(1);
		 buscar(aux,raiz,&hermano);
		es_hermano = true;
	    }
	
	
	
	f = act->element();
	//cout<<"este es el hijo "<<f.tagName()<<endl;
	    inner = " ";name= " ";
	}
}

void DOM_Tree::esCerrado(string &h,string &aux,int &pos1,int &pos2,bool &band){
  int buscar;
  
  pos1 = h.find("<");
  pos2 = h.find(">");
  aux = h.substr(pos1+1,pos2-1);
// cout<<endl<<" este es aux "<<aux<<endl;
  buscar = aux.find("/");
  if(buscar == -1)
    band = false;
  else{
    band =true;
    aux = aux.substr(0);
  }
  h = h.substr(pos2+1);
  
 //  cout<<endl<<" este es aux "<<buscar<<aux<<endl;
}

void DOM_Tree::buscar(string h , Node* ptrRaiz,Node **hermano){
  Node* aux;
  Element e;
  
  if(ptrRaiz != NULL){
    e =ptrRaiz->element(); 
  // cout<<" tag name "<<e.tagName()<<" h "<<h<<endl;
    if(e.tagName()== h){
      *hermano = ptrRaiz;
      //cout<<" 	LO ENCONTRE "<<endl;
    }
    aux = ptrRaiz->firstChild();
    while(aux != NULL){
      buscar(h,aux,hermano);
      aux = aux->nextSibling();
    }
    
  }

}

void DOM_Tree::imprimir(int e){
  imprimirArbol(raiz,e);
}

void DOM_Tree::imprimirArbol(Node *nodoRaiz , int totalEspacios){
  int i;
  Element e;
  Node* aux;
	// e = nodoRaiz->firstChild()->element();
  cout<<" "<<e.tagName()<<endl;
  while(nodoRaiz != NULL){
    imprimirArbol(nodoRaiz->nextSibling(),totalEspacios+1);
    for(i= 1 ;i <= totalEspacios; i++)
      cout<< " ";
	 e= nodoRaiz->element();
      cout<<e.tagName()<<endl;
      nodoRaiz = nodoRaiz->firstChild();
      totalEspacios +=5;
      
  }
}

ostream& operator<<(std::ostream& salida , const DOM_Tree& D ){
	Element e;
	list<string> h;
	DOM_Tree aux;
	
	if(D.raiz != NULL){
		
		e = D.raiz->element();
		cout<<"<"<<e.tagName()<<endl;
		h = e.AttrList();
	
		while(! h.empty() ){
			cout<<" "<<h.front();
			h.pop_front();
		}
		cout<<">";
		cout<<e.innerHTML;
		aux = this->getElementByID();
		while(aux != NULL){
			return (operator<<(salida , ) );
			aux = aux->nextSibling();
			
		}
	}
*/

}
