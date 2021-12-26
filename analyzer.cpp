#include "analyzer.h"
namespace LLAnalyzer {

	bool NonTerminator::operator==(NonTerminator & nonTerminator)
	{
		return this->symbol == nonTerminator.symbol&& this->check == nonTerminator.check;
	}

	bool Base::isNull()
	{
		return typeid(this) == typeid(Ipsilon);
	}

	bool Base::operator==(Base & base)
	{
		return this->symbol == base.symbol;
	}

	bool Production::operator==(Production & production)
	{
		return this->left == production.left&&this->right == production.right;
	}
}