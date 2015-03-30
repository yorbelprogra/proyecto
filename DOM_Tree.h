/*
 * DOM_Tree.h
 *
 *  Created on: marzo 2015
 *      Author: yorbel y samuel
 */

#ifndef DOM_TREE_H_
#define DOM_TREE_H_
#include "Node.h"
#include <string>
#include <list>
class DOM_Tree
{
	private:
		Node *raiz;
		Node *retornarCopia(Node *p);
		void destruir(Node *p);
		void ConvertirEnArbol();
	public:
		DOM_Tree();
		DOM_Tree(Element r, list<DOM_Tree> hijos);
		DOM_Tree(const DOM_Tree &fuente) const;
		DOM_Tree childNode(int p);
		void appendChild(DOM_Tree hijo);
		void appendChild(string h);
		void appendChild(int p, DOM_Tree hijo);
		void appendChild(int p, string h);
		void removeChild(int p);
		void replaceChild(int p, DOM_Tree reemplazo);
		DOM_Tree getElementByID();
		~DOM_Tree();
};


#endif /* DOM_TREE_H_ */
