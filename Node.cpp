/*
 * Node.cpp
 *
 *  Created on: 27/3/2015
 *      Author: yorbel y samuel
 */
#include "Node.h"


Element Node::element()const
{
	return(this->e);
}
Node* Node::firstChild()const
{
	return(firstBorn);
}
Node* Node::nextSibling()const
{
	return(rightBro);
}
void Node::setElement(Element e_)
{
	e=e_;
}
void Node::setFirstChild(Node *fc)
{
	firstBorn=fc;
}
void Node::setNextSibling(Node *ns)
{
	rightBro=ns;
}
void Node::operator=(const Node &fuente )
{
	e=fuente.element();
	firstBorn=fuente.firstChild();
	rightBro=fuente.nextSibling();
}
