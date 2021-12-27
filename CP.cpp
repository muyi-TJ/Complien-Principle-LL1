// CP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "analyzer.h"

using namespace LLAnalyzer;

void initialize()
{
	unordered_map<pair<NonTerminator, Terminator>, Production> table;
	Terminator i = Terminator('i');
	Terminator plus = Terminator('+');
	Terminator mulity = Terminator('*');
	Terminator left = Terminator('(');
	Terminator right = Terminator(')');
	Terminator end = Terminator('#');
	Ipsilon ipsilon = Ipsilon();
	NonTerminator E = NonTerminator('E', Non::Normal);
	NonTerminator Estar = NonTerminator('E', Non::Left);
	NonTerminator T = NonTerminator('T', Non::Normal);
	NonTerminator Tstar = NonTerminator('T', Non::Left);
	NonTerminator F=NonTerminator('F',Non::Normal);
	table[pair<NonTerminator, Terminator>{E, i}] = Production(E, Right({ T,Estar }));
	table[pair<NonTerminator, Terminator>{E, left}] = Production(E, { T,Estar });
	table[pair<NonTerminator, Terminator>{Estar, plus}] = Production(Estar, { plus,T,Estar });
	table[pair<NonTerminator, Terminator>{Estar, right}] = Production(Estar, { ipsilon });
	table[pair<NonTerminator, Terminator>{Estar, end}] = Production(Estar, { ipsilon });
	table[pair<NonTerminator, Terminator>{T, i}] = Production(T, Right({ F,Tstar }));
	table[pair<NonTerminator, Terminator>{T, left}] = Production(T, { F,Tstar });
	table[pair<NonTerminator, Terminator>{Tstar, plus}] = Production(Tstar, { ipsilon });
	table[pair<NonTerminator, Terminator>{Tstar, mulity}] = Production(Tstar, { mulity,F,Tstar });
	table[pair<NonTerminator, Terminator>{Tstar, right}] = Production(Tstar, { ipsilon });
	table[pair<NonTerminator, Terminator>{Tstar, end}] = Production(Tstar, { ipsilon });
	table[pair<NonTerminator, Terminator>{F, i}] = Production(F, Right({ i }));
	table[pair<NonTerminator, Terminator>{F, left}] = Production(F, Right({ left,E,right }));
	PublicProperties::instance->table = table;

}

int main()
{
    std::cout << "Hello World!\n";
	PublicProperties();
	initialize();



}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
