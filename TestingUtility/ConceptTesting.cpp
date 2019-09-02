#include<iostream>
using namespace std;
#include<vector>
#include <bits/stdc++.h>
#include<initializer_list>
// initializer_list constructor



void underStandVector(void);
void enumCheck(void);

/***************************************************/
//c ++11 enum
enum class apple {green ,red};
enum class orange {big ,small};

void enumCheck(void)
{
	apple a =apple::green;
	orange o=orange::big;
/*	if(a==o)
		cout<<"green apple and big orange are same"<<'\n';
	else
	cout<<"not same"<<'\n';*/

}
/*************************************************/

void underStandVector(void)
{
	vector<int> v={12,13,15,15}; // initializer_list constructor c++11
	for(auto& i: v)
		cout<<i;


}
// uniform initializer

//c++11 extended the scope of curly brace initialization


class dog
{
	public:
	int age; //3rd
	dog(int a){age =a;} //2nd 
	dog(const initializer_list<int>& vec){  //1st choice
	age=*(vec.begin());
	}
};

dog d1 {5 };
/*********************************************/
// nullptr for 
void foo(int i) {cout<<"foo_init"<<endl;}
void foo(char* i) {cout<<"foo_char*"<<endl;}
/*************************************************/
//delegation in constructor
class dog1
{
	int p=0;  // inside initialization
	public:
	dog1(){cout<<"default constructor"<<'\n';}
	dog1(int a) : dog1() {p=a;}
};

int main()
{

	//underStandVector();
	 enumCheck();
	static_assert(sizeof(int*) ==8);//   compile time check

	//foo(nullptr); // Ambiguity

	auto i=0;
	cout<<i<<'\n';
	return 0;
	

}
