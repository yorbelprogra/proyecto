/*
 * Node.h
 *
 *  Created on: marzo 2015
 *      Author: deidara
 */

#ifndef NODE_H_
#define NODE_H_
#include "Element.h"
#include <iostream>

class Node
{
	private:
		Element e;
		Node *firstBorn;
		Node *rightBro;
	public:
	Node():e(Element()),firstBorn(NULL),rightBro(NULL){}
	Node(Element e_, Node *fc,Node *ns):e(e_),firstBorn(fc),rightBro(ns){}
	Node(Element e_):e(e_),firstBorn(NULL),rightBro(NULL){}
	Node(const Node &fuente ){	
		e = fuente.element();
		firstBorn = fuente.firstChild();
		rightBro = fuente.nextSibling();
	}
	Element element() const;
	Node* firstChild() const;
	Node* nextSibling() const;
	void setElement(Element e_);
	void setFirstChild(Node *fc);
	void setNextSibling(Node *nc);
	void operator=(const Node &fuente );
};

#endif 
