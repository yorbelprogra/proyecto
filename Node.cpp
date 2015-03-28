/*
 * Node.cpp
 *
 *  Created on: 27/3/2015
 *      Author: yorbel y samuel
 */
#include "Node.h"
Node::Node(const Node &fuente)
{
	e=fuente.getElement();
	firstChild=fuente.getFirstChild();
	nextSibling=fuente.getNextSibling();
}
Element Node::getElement()
{
	return(Element);
}
Node* Node::getFirstChild()
{
	return(firstChild);
}
Node* Node::getNextSibling()
{
	return(nextSibling);
}
void Node::setElement(Element e_)
{
	e=e_;
}
void Node::setFirstChild(Node *fc)
{
	firstChild=fc;
}
void Node::setNextSibling(Node *ns)
{
	nextSibling=ns;
}
void Node::operator=(const Node &fuente )
{
	e=fuente.getElement();
	firstChild=fuente.getFirstChild();
	nextSibling=fuente.getNextSibling();
}
