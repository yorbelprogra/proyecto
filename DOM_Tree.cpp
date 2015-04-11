/*
 * DOM_Tree.cpp
 *
 *  Created on: 27/3/2015
 *      Author: yorbel y samuel
 */
#include "DOM_Tree.h"

DOM_Tree::DOM_Tree()
{
	raiz=NULL;	//arbol nulo
}
DOM_Tree::DOM_Tree(Element r, list<DOM_Tree> hijos)//constructor copia
{
	raiz= new Node(r,NULL,NULL);//que el nodo raiz con r y inicialmente no tiene hijos

	if(!hijos.empty())	//la lista puede estar vacia en ese caso no se hace nada
	{
		Node *aux;		//variable aux ira apuntado a los distintos hijos
		raiz->setFirstChild(retornarCopia(hijos.front().raiz));	//al inicio creo el hijo izquierdo que es el primero en la lista
		hijos.pop_front();										//quito el hijo izquierdo de la lista
		aux=raiz->firstChild();									//aux hara que el hizo izquierdo apunte a su hermano derecho
		while(!hijos.empty())									//si todavia hay hijos se iran agregando
		{
			aux->setNextSibling( retornarCopia(hijos.front().raiz) );//los hermanos van apuntando a su proximo hermano
			hijos.pop_front();
			aux=aux->nextSibling();
		}
		this->actualizaHtmlInterno();		//el Html interno puede no estar actualizado
	}
}
DOM_Tree::DOM_Tree(const DOM_Tree &fuente)
{
	this->raiz=retornarCopia(fuente.raiz);	//se hace una copia desde la raiz de la fuente
}
Node* DOM_Tree::retornarCopia(Node *p) const//va creando espacios de memoria nuevos que contienen una copia de la info de los nodos de p
{

	if(p==NULL)
	{
		return(NULL);
	}
	else
	{
		Node *nuevo = new Node;					//crea el nuevo nodo
		nuevo->setElement( p->element());		//llena los nodos con la info del nodo al que apunta p en preorden
		nuevo->setFirstChild(retornarCopia(p->firstChild()));
		nuevo->setNextSibling(retornarCopia(p->nextSibling()));
		return(nuevo);
 	}

}
DOM_Tree DOM_Tree::childNode(int p)
{
	DOM_Tree hijo;
	if(p>0 && this->raiz!=NULL)//se asegura que la posicion no sea negativa
	{
		int posicion;
		Node *aux;
		posicion =1;
		aux=this->raiz->firstChild();
		while(aux!=NULL && posicion<p)//el mientras ubica a aux en el hijo correcto
		{
			aux=aux->nextSibling();
			posicion++;
		}
		if(posicion==p && aux!=NULL)
		{
			Node *nuevo = new Node (aux->element(),aux->firstChild(),NULL);//no quiero que se genere una copia de los hermanos del hijo
			hijo.raiz=retornarCopia(nuevo);//le doy a DOM_Tree de retorno la copia del hijo indicado
		}
	}
	return(hijo);//retorno
}
void DOM_Tree::appendChild(int p, DOM_Tree hijo)
{
	if(p>0 && this->raiz!=NULL)//se asegura que la posicion no sea negativa
	{
		int posicion;
		Node *aux;
		Node *ptr;


		posicion =1;
		aux=NULL;
		ptr=this->raiz->firstChild();
		while(ptr!=NULL && posicion<p)//el mientras ubica a aux y ptr en la posion correcta
		{
			aux=ptr;
			ptr=ptr->nextSibling();
			posicion++;
		}
		if(ptr==NULL && p==1)//si no hay hijos y la posicion es 1, esta bien insertar el arbol como hijo
		{
			this->raiz->setFirstChild(hijo.raiz);
		}
		else
		{
			if(aux==NULL && p==1)//si la posiion es 1 y hay un hijo izquierdo requiere que la raiz apunte al nuevo hijo
			{
				hijo.raiz->setNextSibling(ptr);
				raiz->setFirstChild(hijo.raiz);
			}
			else
			{
				if(posicion==p)//para cualquier otra posicion distinta de 1 el hijo anterior apunta al nuevo y el nuevo al que apuntaba anterior
				{
					aux->setNextSibling(hijo.raiz);
					hijo.raiz->setNextSibling(ptr);
				}

			}

		}
		hijo.raiz=NULL;
		this->actualizaHtmlInterno();//cuando se inserta un nuevo hijo el Html interno tiene ahora a ese hijo por eso se actualiza el Html
	}
}
void DOM_Tree::appendChild(int p, string h)
{
	DOM_Tree hijo;
	hijo.convertirEnArbol(h);	//convierto al string en un arbol
	this->appendChild(p,hijo);	//luego llamo al procedimiento normal y le doy el arbol formado
	hijo.~DOM_Tree();
}
void DOM_Tree::appendChild(DOM_Tree hijo)//este es igual al de la posicion pero se ubica en la posicion final
{
	if(this->raiz!=NULL)
	{
		Node *aux;
		Node *ptr;
		//pudiera llamar al procedimiento appendChild(int,DOM_Tree) pero igual se tendria que hacer un cilo mientas para encontrar la ultima pos
		aux=NULL;
		ptr=this->raiz->firstChild();

		while(ptr!=NULL)
		{
			aux=ptr;
			ptr=ptr->nextSibling();
		}
		if(aux==NULL)//se prefiere agregar de una vez
		{
			this->raiz->setFirstChild(hijo.raiz);// el caso cuando no hay hijos
		}
		else
		{
			aux->setNextSibling(hijo.raiz);//el caso cuando hay hijos y el hijo anterior debe apuntar al nuevo hijo
		}
		hijo.raiz=NULL;
		this->actualizaHtmlInterno();//cuando agrego un hijo nuevo debo de actualizar el Html

	}

}
void DOM_Tree::appendChild(string h)
{
	DOM_Tree hijo;
	hijo.convertirEnArbol(h);//convierto al string en un arbol
	this->appendChild(hijo);//le doy el arbol al procedimiento anterior para que lo agrege
	hijo.~DOM_Tree();

}
void DOM_Tree::removeChild(int p)
{
	if(p>0 && this->raiz!=NULL)
	{
			DOM_Tree eliminar;

			int posicion;
			Node *aux,*ptr;

			posicion =1;
			aux=NULL;
			ptr=this->raiz->firstChild();

		while(ptr!=NULL && posicion<p)//el mientras ubica a aux y ptr en la posion indicada
		{
			aux=ptr;
			ptr=ptr->nextSibling();
			posicion++;
		}
		if(ptr!=NULL)//si no hay hijos no se puede eliminar nada
		{
			if(aux==NULL)//si el el hijo mas a la izquierdo se debe se hacer que su padre apunte al proximo hijo
			{
				eliminar.raiz=this->raiz->firstChild();
				raiz->setFirstChild(eliminar.raiz->nextSibling());
				eliminar.raiz->setNextSibling(NULL);
			}
			else//para cualquier otro hijo se hace que el hermano anterior apunte al proximo
			{
				eliminar.raiz=ptr;
				aux->setNextSibling(eliminar.raiz->nextSibling());
				eliminar.raiz->setNextSibling(NULL);

			}
		}
		eliminar.~DOM_Tree();//libero la memoria del hijo a eliminar
		this->actualizaHtmlInterno();//cuando se elimina un hijo tambien cambie el Html interno
	}

}
void DOM_Tree::replaceChild(int p, DOM_Tree reemplazo)
{


	if(p>0 && this->raiz!=NULL)
	{
		DOM_Tree eliminar;
		int posicion;
		Node *aux,*ptr;

		posicion =1;
		aux=NULL;
		ptr=this->raiz->firstChild();

		while(ptr!=NULL && posicion<p)//se ubica aux y ptr en la posicion indicada
		{
			aux=ptr;
			ptr=ptr->nextSibling();
			posicion++;
		}
		if(ptr!=NULL)//si no hay hijos no se puede reemplazar nada
		{
			if(aux==NULL)//si hay que reemplazar el hijo mas ala izquierda hay que hacer que el padre apunte al nuevo hijo
			{

				eliminar.raiz=ptr;
				raiz->setFirstChild(reemplazo.raiz);
				reemplazo.raiz->setNextSibling(eliminar.raiz->nextSibling());//el nuevo hijo apunta al hermano del reemplao
				eliminar.raiz->setNextSibling(NULL);



			}
			else//para cualquier otro reemplazo hay que hacer que el hermano izquierdo apunte al nuevo
			{
				eliminar.raiz=ptr;
				aux->setNextSibling(reemplazo.raiz);
				reemplazo.raiz->setNextSibling(eliminar.raiz->nextSibling());//el nuevo hijo apunta al hermano del reemplao
				eliminar.raiz->setNextSibling(NULL);
			}
			reemplazo.raiz=NULL;
		}
		eliminar.~DOM_Tree();//libero la memoria del reemplazado
		this->actualizaHtmlInterno();//igualmente hay que actulizar el Html interno
	}

}
void DOM_Tree::replaceChild(int p, string r)
{

	DOM_Tree reemplazo;
	reemplazo.convertirEnArbol(r);//convierto el string en DOM_Tree
	this->replaceChild(p,reemplazo);//se le da el arbol al procedimiento anterior
	reemplazo.~DOM_Tree();

}
DOM_Tree DOM_Tree::getElementByID(string id)
{

	Node* buscado=NULL;
	DOM_Tree d;
	bool band=false;

	buscar(id,raiz,&buscado,band);//busca el id entre todos los nodos
	if(buscado == NULL){	//si no lo encuentra retorna un subarbol vacio
		return d;
	}else{				//si lo encuentra retorna un subarbol

		d.raiz = this->retornarCopia(buscado);		//la variable buscado retorna la direccion del nodo donde encuentra el id
		d.raiz->setNextSibling(NULL); 
		return d;
	}
}
//este es un preorden que busca en la lista de attrlist de cada nodo del arbol generado
void DOM_Tree::buscar(string id, Node* ptrRaiz , Node **buscado,bool &band){
	Node*aux;
	Element e;
	list<string> L_e;

	if(ptrRaiz != NULL ){
		e = ptrRaiz->element();

		L_e = e.attrList();

		if(!L_e.empty() ){

				while( !L_e.empty() && !band ){
				//		cout<<L_e.front()<<" con "<<id<<endl;
					if( L_e.front() == id ){
						*buscado = ptrRaiz;
						band = true;
					}else{
						L_e.pop_front();
					}

				}
			}

			aux = ptrRaiz->firstChild();
			while(aux != NULL){
				buscar(id,aux,buscado,band);
				aux = aux->nextSibling();
			}
	}
}
DOM_Tree::~DOM_Tree()
{
	destruir(this->raiz);//destruir libera cada nodo
	this->raiz=NULL;	//el nodo al que raiz apunta esta liberado pero todavia tiene esa direccion por eso coloco NULL a la raiz
}
void DOM_Tree::destruir(Node *p)
{
	if(p!= NULL)
	{
				//libera en profundidad con los hijos mas a la dererecha primero y de ultimo el padre
				destruir(p->firstChild());
				destruir(p->nextSibling());
				delete p;
	}
}

void DOM_Tree::operator=(const DOM_Tree &fuente){

		this->raiz=retornarCopia(fuente.raiz);	//hace una copia desde la raiz de fuente y se lo pasa a la raiz del DOM_Tree destino

}
void DOM_Tree::convertirEnArbol(string don)
{
	this->raiz=c(don);
}
Node* DOM_Tree::c(string& don)
{

	string a_;			//variable para el tagName
	list<string> b_;	//lista para los atributos
	string b;			//ira recibiendo cada uno de los atributos de la lista
	string c_;			//variable para el HTML interno


	int pos1,pos2;		//iran teniendo las posiones de donde comienza < y >
	int att;			//contendra la posicion de los espacios en blanco de la lista de atributos
	string sub;			//ira teniendo <todoo el texto que esta aqui entre estos simbolos>

	pos1=don.find('<');
	pos2=don.find('>');

	sub=don.substr(pos1+1,pos2-1);		//le paso a sub el tag con las lista de atributos si los hay claro
	don.erase(pos1,pos2+1);				//borro del string todoo ese tag con sus atributos

	att=sub.find(" ");					//busco si hay atribuyos inspeccionando si hay espacios en blanco att tendra la direccion del espacio
	if(att!=-1)
	{
		a_=sub.substr(0,att);		//saco el tag de la sub cadena

		sub.erase(0,att+1);			//borro el tag y me quedo con los atributos

		while(!sub.empty())			//mientras haya atributos voy llenando la lista b_ de atributos
		{
			att=sub.find(" ");
			if(att!=-1)
			{
				b=sub.substr(0,att);
				sub.erase(0,att+1);
			}
			else
			{
				b=sub;
				sub.erase(0,sub.size());
			}
			b_.push_back(b);
		}
	}
	else		//si no hay atributos ya tengo el tag y se lo doy a a_ que es la variable para el tag
	{
		a_=sub;
	}
	ponerInner(don,c_);	//ya tengo el tag y la lista de atributos solo falta el Html interno...ponerIneer lo coloca en c_
	Element e_entrada(a_,b_,c_);	//creo el elemento con los datos del nodo
	Node *p= new Node(e_entrada,NULL,NULL);	//creo el nodo y le doy el elemento que acabo de crear

	pos1=don.find("<");	//es momento de averiguar que viene
	if(don[pos1+1]!='/')	//si el tag no se va a cerrar quito cualquier comentario antes de sus hijos en caso de que haya
	{
		don.erase(0,pos1);

	}
	if(don[0]=='<' && don[1]!='/')//ya quite cualquier comentario antes de sus hijos y ahora averiguo si realmente tiene hijos <cualquierLetra
	{

			Node *aux;
			p->setFirstChild(c(don));//creo primero el hio izquierdo recursivamente con el string que ahora tiene de cabecera al hijo

			aux=p->firstChild();//ya cree el primer hijo ahora averiguo si tiene hermanos
			while(don[0]=='<' && don[1]!='/')//tiene hermanos si viene <cualquierLetra..la recurcion anterior se habra tragado
			{								//los caracteres del hijo anterior y alante queda solo el proximo hijo(si los ahi)
				aux->setNextSibling(c(don));//comienzo a crear los hermanos

				aux=aux->nextSibling();
			}

	}

	pos1=don.find(">");	//esto elimina la cerradura del tag despues de haver creado todos sus hijos </
	don.erase(0,pos1+1);
	return(p);			//retorno el primer hijo en caso del ser padre el anterior o el hermano en caso de ser hermano el anterior

}
void DOM_Tree::ponerInner(string cad,string& i)
{
	stack<string> t;
	int x,y;	//variables para la posicion de < y >
	bool salir;

	x=cad.find('<');	//x tiene la posion de <
	y=cad.find('>');	//y tiene la posion de >

	salir=false;
	while(!salir)	//cuando se encuentre el tag de cerradura del tag que invoco el ciclo acaba
	{
		x=cad.find('<');	//busco la posion de <
		y=cad.find('>');	//busco la posicion de >
		if(cad[x+1]=='/')	//si es cerradura del tag
		{

			if(t.empty())	//si la pila esta vacia quiere decir que ya se llego al tag de cerraduta del tag que invoco el procedimiento
			{
				if(x!=0)	//si hay alguan comentario antes del tag de cerradura este se concatena
				{
					i+=cad.substr(0,x);	//se concatena
					cad.erase(0,x);	//se borra lo procesado
				}
				salir=true;	//ya se hayo el tag de cerradura por lo tanto se acaba el ciclo
			}
			else
			{
				i+=cad.substr(0,y+1);	//si pila no esta vacia quiere decir que el tag de cerradura encontrado pertenece al
										//que esta de ultimo en la pila todoo lo que esta en la cadena antes de este tag se concatena
				cad.erase(0,y+1);		///borro lo procesado
				t.pop();				//quito el tag de la pila
			}

		}
		else//si no es cerradura del tagname se esta abriendo un nuevo tag que tambien es parte del HTML interno...este se concatena
		{
			i+=cad.substr(0,y+1);
			t.push(cad.substr(x+1,y-1));//el tagName nuevo se pone en una pila para saber de quien pertene el proximo tag de cerradura
			cad.erase(0,y+1);			//se borra lo procesado
		}

	}
}
string DOM_Tree::convertirEnString()
{

	string salida;
	string atributo;
	list<string> atributos;
	salida+="<";				//comienzo con <
	salida+=this->raiz->element().tagName();//luego el nombre del tag
	atributos=this->raiz->element().attrList();

	while(!atributos.empty())//concateno la lista de tributos
	{

		salida+=" ";
		salida+=atributos.front();
		atributos.pop_front();

	}
	salida+=">";
	salida+=this->raiz->element().innerHTML();//concateno el Html que el posee
	salida+="</";//cierro el tag
	salida+=this->raiz->element().tagName();
	salida+=">";

	return(salida);
}
void DOM_Tree::actualizaHtmlInterno()
{

	Node *aux;
	aux=this->raiz->firstChild();
	if(aux!=NULL)
	{
		DOM_Tree hijo;
		string nuevoHtml;
		hijo.raiz=aux;
		nuevoHtml+=hijo.convertirEnString();
		aux=aux->nextSibling();

		while(aux!=NULL)
		{
			hijo.raiz=aux;
			nuevoHtml+=hijo.convertirEnString();//ha cada hijo lo convierto en texto y lo concateno
			aux=aux->nextSibling();

		}
		hijo.raiz=NULL;
		int p1,p2;
		string cadena;
		cadena=this->raiz->element().innerHTML();

		p1=cadena.find('<');
		p2=cadena.find_last_of('>');
		if(p1==-1)
		{
			cadena+=nuevoHtml;
		}
		else
		{
			cadena.replace(p1,(p2-p1)+1,nuevoHtml);
		}


		Element e2(raiz->element().tagName(),raiz->element().attrList(),cadena);//reemplazo el nuevo Html en el padre 
		raiz->setElement(e2);
	}

}

ostream &operator<<(ostream &out ,DOM_Tree d){

	Node* p;
	Element e;
	list<string> L;
	int cont = 0;
	string aux;

	if(d.raiz != NULL){
		cout<<"<!doctype html>"<<endl;//doctype lo imprimo al principio
		p = d.raiz;
		d.impresion(p,cont);
	}

	return out;
}
void DOM_Tree::impresion(Node* p , int cont){

	Node *aux,*aux1;
	Element e;
	list<string> L;
	int i,pos;
	string auxInner,a;

	if( p != NULL){

		for(i=1;i<=cont;i++){ cout<<"	";}

		e = p->element();

		cout<<"<"<<e.tagName();

		L = e.attrList();

		if(!L.empty()){
			while(!L.empty() ){
				cout<<" "<<L.front();
				L.pop_front();
			}
		}
		cout<<">";

		auxInner = e.innerHTML();
		if(auxInner[0] != '<'){	//si el primer caracter es distito de cero es que lo que viene no es un hijo ej
			pos = auxInner.find("<");	//hola soy bata<p></p> en este caso auxInner = hola soy bata
			auxInner = auxInner.substr(0,pos);
			cout<<auxInner;
		}
		aux1=aux = p->firstChild();		///aux1 si es null idica que debe identar porque cerro hoja

		if(aux != NULL){
			cout<<endl;
		}

		while(aux != NULL){
			impresion(aux,cont+1);
			aux = aux->nextSibling();
		}
		if(aux1 != NULL)
		for(i=1;i<=cont;i++){ cout<<"	";}

		cout<<"</"<<e.tagName();
		cout<<">"<<endl;

	}


}
