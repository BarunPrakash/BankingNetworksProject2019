/*************************************************************************

Designed  By Barun Prakash.
Date:26 May 2018.
Mission : Explore Architecture Design  using c++11 !!
Goal!! :
1.Exploring cpp using multiple design pattern (creational/structural/Behavioral)
2.Exploring ALgo using multiple oops concepts
(class utility ,Constructor/Destructor, inheritance and polymorphism)
3.Exploring Dynamic Programming.
4.Exploring Multithreading using c++11/c++14/c++17.
5.Exploring STL (inbuilt Datastructue container).
6.Designed UML modeling  (Behavioral & Structural).
7.Tree component building using cmake/ Makefile.
8.Diagnostic application using shell programming.
9.Build management using python.
10.Version control maintained by RCS/Soft copy is  Available on GIT.
11.Tools Vim ,ctags cscope,

******************/
// function Deceleration

#include<BankingHeader.h>
#include<iostream>
using namespace std;
//void AccesStructureObject(void);



#if not_used
void empD ::getDataIntoClass(void)
{

 cout<<"Enter Acc No"<<'\n';
 cin>>AccountNo;
 cout<<"Enter Name"<<'\n';
 cin>>strEmpName;
 cout<<"Enter SavingNo:-"<<'\n';
 cin>>savingAccoutRs;


}
#endif

class loanDep : public empD
{

   public:
	void checkValidtyOfFunc(void)
	{
		unsigned int tempVal=0;
  	 	for(uint8_t  mov=0; mov<maxsize;mov++)
		{
	 		if(userDb[mov].blance >30000)
			{
				tempVal= userDb[mov].blance -10000;
				printf("Congratulation !! you are eligible for  loan:-%d\n",tempVal);
				strcpy(valuableForLoan[mov] ,"@3");
  			}
			else
	  		{
				tempVal= userDb[mov].blance -5000;
				printf("Congratulation !! you are eligible for  loan:-%d\n",tempVal);
	
	   			strcpy(valuableForLoan[mov] ,"@5");

	  		}
	 	}
	}



};


void AccesStructureObject(void)
{
	loanDep ld;
	ld.sqlDbProcess();
	ld.checkValidtyOfFunc();
        ld.printEligibiltyMessageOnScreen();


#if not_used
	loanDep Lobj[2];
	for(uint8_t  mov=0; mov<maxsize;mov++)
	{
		Lobj[mov].getDataIntoClass();
	}

	 for(uint8_t  mov=0; mov<maxsize;mov++)
	 {
	 	printf("----------------------------\n");

  		Lobj[mov].checkValidtyOfFunc();
  		Lobj[mov].printEligibiltyMessageOnScreen();

  		printf("----------------------------\n");
 	}
#endif
}

























