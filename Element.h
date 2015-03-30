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
using std::list;
using std::string;

class Element
{
	private:
		//Atributos
		string TagName;
		list<string> AttrList;
		string InnerHTML;
	
	public:
		//Metodos
		Element():TagName(string()),AttrList(list<string>()),InnerHTML(string()){}
		Element(string tagName_ ):TagName(tagName_),AttrList(),InnerHTML(){}
		Element(string tagName_,list<string> attrList_, string innerHTML_ ):TagName(tagName_),AttrList(attrList_),InnerHTML(innerHTML_){}
		Element(const Element &fuente);
		string tagName()const;
		list<string> attrList()const;
		string innerHTML()const;
		void setTagName(string tagName_);
		void setAttrList(list<string> attrList_);
		void setInnerHTML(string innerHTML_);
		void operator=(const Element &fuente);
};

#endif /* ELEMENT_H_ */
