/*
 * DOM_Tree.h
 *
 *  Created on: marzo 2015
 *      Author: yorbel y samuel
 */

#ifndef DOM_TREE_H_
#define DOM_TREE_H_
#include "Node.h"
#include <list>
class DOM_Tree
{
	private:
		Node *raiz;
		Node *retornarCopia(Node *p);
	public:
		DOM_Tree();
		DOM_Tree(Element r, list<DOM_Tree> hijos);
		DOM_Tree(const DOM_Tree &fuente) const;
		DOM_Tree childNode(int p);
};


#endif /* DOM_TREE_H_ */
