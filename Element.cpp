/*
 * Element.cpp
 *
 *  Created on: marzo 2015
 *      Author: yorbel y samuel
 */

#include "Element.h"

Element::Element(const Element &fuente)
{
	TagName=fuente.tagName();
	AttrList=fuente.attrList();
	InnerHTML=fuente.innerHTML();
}
string Element::tagName()const
{
	return(TagName);
}
list<string> Element::attrList()const
{
	return(AttrList);
}
string Element::innerHTML()const
{
	return(InnerHTML);
}
void Element::setTagName(string tagName_)
{
	this->TagName=tagName_;
}
void Element::setAttrList(list<string> attrList_)
{
	this->AttrList=attrList_;
}
void Element::setInnerHTML(string innerHTML_)
{
	this->InnerHTML=innerHTML_;
}
void Element::operator=(const Element &fuente)
{
	TagName=fuente.tagName();
	AttrList=fuente.attrList();
	InnerHTML=fuente.innerHTML();
}
