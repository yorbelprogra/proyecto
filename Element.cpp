/*
 * Element.cpp
 *
 *  Created on: marzo 2015
 *      Author: yorbel y samuel
 */
#include "Element.h"
Element::Element(const Element &fuente)
{
	tagName=fuente.getTagName();
	attrList=fuente.getAttrList();
	innerHTML=fuente.getInnerHTML();
}
string Element::getTagName()const
{
	return(tagName);
}
list<string> Element::getAttrList()const
{
	return(attrList);
}
string Element::getInnerHTML()const
{
	return(innerHTML);
}
void Element::setTagName(string tagName_)
{
	tagName=tagName_;
}
void Element::setAttrList(list<string> attrList_)
{
	attrList=attrList_;
}
void Element::setInnerHTML(string innerHTML_)
{
	innerHTML=innerHTML_;
}
void Element::operator=(const Element &fuente)
{
	tagName=fuente.getTagName();
	attrList=fuente.getAttrList();
	innerHTML=fuente.getInnerHTML();
}
