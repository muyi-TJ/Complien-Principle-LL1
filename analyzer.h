#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

namespace LLAnalyzer 
{
	enum Non
	{
		Normal,
		Left,
		Factor
	};//分别表示正常非终结符、由消除左递归产生的非终结符、由消除公共左因子产生的非终结符

	class First :public unordered_set<Terminator>
	{

	};//First集合

	class Follow :public unordered_set<Terminator>
	{

	};//Follow集合


	class Base
	{
	public:
		char symbol;//对应符号

		bool isNull();

		Base(char c)
		{
			symbol = c;
		}

		bool operator ==(Base& base);
	};//基类

	class Terminator : public Base
	{
	public:
		Terminator(char c) :Base(c){}
	};//终结符

	class NonTerminator :public Base
	{
	public:
		Non check = Non::Normal;//是否为消除左递归产生的非终结符
		bool operator ==(NonTerminator& nonTerminator);
		NonTerminator(char c,Non n):Base(c),check(n){}
	};//非终结符

	class Ipsilon :public Terminator
	{
	public:
		Ipsilon() :Terminator('$') {}
	};//空符,定义为$,一切$都表示空

	class Right :public vector<Base>
	{
	public:
		Right(initializer_list<Base> list)
		{
			for (auto a : list)
			{
				this->emplace_back(a);
			}
		}
	};//产生式右侧

	class Production
	{
	public:
		NonTerminator left;//产生式左侧符号
		Right right;//产生式右侧符号
		bool operator ==(Production& production);
		Production(NonTerminator n,Right r):left(n),right(r){}
	};//产生式


	class Translator
	{

	};//翻译器，内部提供将文法转换为LL(1)文法的函数

	class LLTable
	{

	};//用于提供LL(1)分析表

	class Parser
	{

	};//用于将测试用例进行自上而下语法分析

	class PublicProperties
	{
	public:
		static PublicProperties* instance;

		PublicProperties()
		{
			instance = this;
		}

		unordered_map <NonTerminator, First> firstOfNonTerminator;//非终结符的First
		unordered_map<Right, First> firstOfRight;//产生式右侧的First
		unordered_map<NonTerminator, Follow> follow;//非终结符的Follow
		unordered_map<pair<NonTerminator, Terminator>, Production> table;//LL(1)分析表
		unordered_set<Production> answer;//上次分析后所得到的答案数组

		unordered_set<NonTerminator> noTers;//文法中用到的非终结符
		unordered_set<Terminator> ters;//文法中用到的终结符
	};

}


