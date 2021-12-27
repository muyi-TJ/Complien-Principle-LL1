#include "analyzer.h"
namespace LLAnalyzer {

	bool NonTerminator::operator==(NonTerminator & nonTerminator)
	{
		return this->symbol == nonTerminator.symbol&& this->check == nonTerminator.check;
	}

	void NonTerminator::outPut()
	{
		switch (check)
		{
			
		case LLAnalyzer::Normal:cout << symbol;
			break;
		case LLAnalyzer::Left:cout << symbol << '\'';
			break;
		case LLAnalyzer::Factor:cout << symbol << '\'' << '\'';
			break;
		default:
			break;
		}
	}

	bool Base::isNull()
	{
		return typeid(this) == typeid(Ipsilon);
	}

	bool Base::operator==(Base & base)
	{
		return this->symbol == base.symbol;
	}

	void Base::outPut()
	{
		cout << symbol;
	}

	bool Production::operator==(Production & production)
	{
		return this->left == production.left&&this->right == production.right;
	}
	void Production::outPut()
	{
		this->left.outPut();
		cout << " -> ";
		this->right.outPut();
		cout << endl;
	}
	void Right::outPut()
	{
		for (auto a : this->bases)
		{
			a.outPut();
		}
	}
	bool Right::operator==(Right & right)
	{
		return this->bases==right.bases;
	}
}