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
	};//�ֱ��ʾ�������ս������������ݹ�����ķ��ս�������������������Ӳ����ķ��ս��

	class First :public unordered_set<Terminator>
	{

	};//First����

	class Follow :public unordered_set<Terminator>
	{

	};//Follow����


	class Base
	{
	public:
		char symbol;//��Ӧ����

		bool isNull();

		Base(char c)
		{
			symbol = c;
		}

		bool operator ==(Base& base);
	};//����

	class Terminator : public Base
	{

	};//�ս��

	class NonTerminator :public Base
	{
	public:
		Non check = Non::Normal;//�Ƿ�Ϊ������ݹ�����ķ��ս��
		bool operator ==(NonTerminator& nonTerminator);

	};//���ս��

	class Ipsilon :public Base
	{
	public:
		Ipsilon() :Base('$') {}
	};//�շ�,����Ϊ$,һ��$����ʾ��

	class Right :public vector<Base>
	{

	};//����ʽ�Ҳ�

	class Production
	{
	public:
		NonTerminator left;//����ʽ������
		Right right;//����ʽ�Ҳ����
		bool operator ==(Production& production);
	};//����ʽ


	class Translator
	{

	};//���������ڲ��ṩ���ķ�ת��ΪLL(1)�ķ��ĺ���

	class LLTable
	{

	};//�����ṩLL(1)������

	class Parser
	{

	};//���ڽ����������������϶����﷨����

	class PublicProperties
	{
	public:
		static PublicProperties* instance;

		PublicProperties()
		{
			instance = this;
		}

		unordered_map <NonTerminator, First> firstOfNonTerminator;//���ս����First
		unordered_map<Right, First> firstOfRight;//����ʽ�Ҳ��First
		unordered_map<NonTerminator, Follow> follow;//���ս����Follow
		unordered_map<pair<NonTerminator, Terminator>, Production> table;//LL(1)������
		unordered_set<Production> answer;//�ϴη��������õ��Ĵ�����

		unordered_set<NonTerminator> noTers;//�ķ����õ��ķ��ս��
		unordered_set<Terminator> ters;//�ķ����õ����ս��
	};

}


