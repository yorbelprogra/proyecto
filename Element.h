/*
 * Element.h
 *
 *  Created on: marzo 2015
 *      Author: yorbel y samuel
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Element
{
	private:
		string tagName;
		list<string> attrList;
		string innerHTML;
	public:
		Element(string tagName_,list<string> attrLisList_, string innerHTML_ ):tagName(tagName_),attrList(attrList),innerHTML(innerHTML){}
		Element(string tagName_ ):tagName(tagName_),attrList(),innerHTML(){}
		Element(const Element &fuente);
		string getTagName()const;
		list<string> getAttrList()const;
		string getInnerHTML()const;
		void setTagName(string tagName_);
		void setAttrList(list<string> attrList_);
		void setInnerHTML(string innerHTML_);
		void operator=(const Element &fuente);


};



#endif /* ELEMENT_H_ */
