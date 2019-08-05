#include<string.h>
#include<stdint.h>
#include<limits.h>
#include<stdio.h>
/**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include<string.h>
#include<stdlib.h>
/****************************************************/
#include<iostream>	
using namespace std;
#define maxsize  5

#define not_used 0

#ifndef MESSAGE
   #define MESSAGE "You wish!"
#endif

/***********************************************/
/*
 *
 * using Class Definition

*/




class empD
{ 
/***********************************************/
	//classic container 
	public:
	typedef struct db
	{
		char name[16];
		int acc;  
		int blance;
	}db;
	db userDb[5];
/************************************/
	#if not_used	
	unsigned int AccountNo;
	char strEmpName[16];
	#endif
	protected:
	char valuableForLoan[5][16];
	public:
	#if not_used
	unsigned int savingAccoutRs;
	void getDataIntoClass(void);
	#endif
	int readFromSqlDB(void *data, int argc, char **argv, char **azColName);
	void sqlDbProcess(void);
	void printEligibiltyMessageOnScreen(void)
	{
               for(uint8_t  mov=0; mov<maxsize;mov++)
		{
	 		printf("NAME:-%5s\n",userDb[mov].name);
			printf("ACC:-%5d\n",userDb[mov].acc);
			printf("Rate:-%5s\n",valuableForLoan[mov]);
		}


      }
// void AccesStructureObject(void);


};

void AccesStructureObject(void);




