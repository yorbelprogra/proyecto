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
		void ponerInner(string cad, string& i);
		void actualizaHtmlInterno();
		string convertirEnString();
		void impresion(Node* p ,int cont );
		void buscar(string id, Node* ptrRaiz , Node **buscado,bool &band);
		void convertirEnArbol(string h);
		Node* c(string& don);
	public:

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
		void replaceChild(int p, string r);
		DOM_Tree getElementByID(string id);
		void operator=(const DOM_Tree &fuente);
		friend ostream &operator<<(ostream &out ,DOM_Tree d );
		~DOM_Tree();

};


#endif /* DOM_TREE_H_ */
