/*
 * DOM_Tree.h
 *
 *  Created on: marzo 2015
 *      Author: yorbel y samuel
 */

#ifndef DOM_TREE_H_
#define DOM_TREE_H_
#include "Node.h"
#include "Element.h"
#include <string>
#include <list>
	using std::string;
	using std::list;
	using namespace std;

class DOM_Tree
{
	private:
		Node *raiz;
		Node* retornarCopia(Node *p)const;
		void destruir(Node *p);
		void esCerrado(string &h,string &aux,int &pos1,int &pos2 , bool &band);
		void buscar(string h , Node* ptrRaiz,Node** hermano);
		void imprimirArbol(Node*  , int );
	public:
		void convertirEnArbol(string h);
		DOM_Tree();
		DOM_Tree(Element r, list<DOM_Tree> hijos);
		DOM_Tree(const DOM_Tree &fuente);
		DOM_Tree childNode(int p);
		void appendChild(DOM_Tree hijo);
		void appendChild(string h);
		void appendChild(int p, DOM_Tree hijo);
		void appendChild(int p, string h);
		void removeChild(int p);
		void replaceChild(int p, DOM_Tree reemplazo);
		DOM_Tree getElementByID(Element id);
		void operator=(const DOM_Tree &fuente);
		void imprimir(int);
		friend std::ostream& operator<<(ostream& salida,const DOM_Tree& D);
	//	friend std::ostream& operator<<(ostream& salida,const Node** ptrRaiz);
		~DOM_Tree();
};


#endif /* DOM_TREE_H_ */
