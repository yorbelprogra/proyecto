/*
 * Node.h
 *
 *  Created on: marzo 2015
 *      Author: deidara
 */

#ifndef NODE_H_
#define NODE_H_
#include "Element.h"

class Node
{
	private:
		Element e;
		Node *firstChild;
		Node *nextSibling;
	public:
	Node(Element e_, Node *fc,Node *ns):e(e_),firstChild(fc),nextSibling(ns){}
	Node(Element e_):e(e_),firstChild(NULL),nextSibling(NULL){}
	Node(const Node &fuente );
	Element getElement() const;
	Node *getFirstChild() const;
	Node *getNextSibling() const;
	void setElement(Element e_);
	void setFirstChild(Node *fc);
	void setNextSibling(Node *nc);
	void operator=(const Node &fuente );
};




#endif /* NODE_H_ */
