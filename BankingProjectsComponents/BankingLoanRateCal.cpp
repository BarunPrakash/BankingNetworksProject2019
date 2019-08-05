/*
 Designed By Barun 
Sqlite table creations.
sqlite schema creations.
create table stattically and dynamically

*/
#include<BankingHeader.h>


/***********************************************************************/

#if not_used 
typedef struct db
{
	char name[16];
	int acc;
	int blance;
}db;


db userDb[5];
//struct db *userDb;
//struct db testDB;
/**********************************************************************/

//function declerations
static int readFromSqlDB(void *data, int argc, char **argv, char **azColName);
void sqlDbProcess(void);

#endif
/****************************************************************************/
int  empD ::readFromSqlDB(void *data, int argc, char **argv, char **azColName)
{
	int i;
	char str[16],*strA;
	int testV,testV1;
//	userDb =(struct db*)malloc(10*sizeof( struct db));
	//fprintf(stderr, "%s: ", (const char*)data);
	for(i = 0; i<argc; i++)
	{

		if(strcmp(azColName[i], "NAME") == 0)
		{
         		//*(userDb[i]).name= argv[i] ? argv[i] : NULL;
			strcpy(userDb[i].name ,(argv[i] ? argv[i] : NULL));
			printf("%s\t",userDb[i].name);


		}
    		else if (strcmp(azColName[i], "ACC")  == 0)
		{
        	//	userDb[i]->acc= argv[i] ? argv[i]  : NULL;
			userDb[i].acc= atoi(argv[i] ? argv[i]  : NULL);
			printf("%d\t",userDb[i].acc);

		}
 		else if (strcmp(azColName[i], "BLANCE")  == 0)
		{
         	//	userDb[i]->blance = argv[i] ? argv[i]  : NULL;
			userDb[i].blance= atoi(argv[i] ? argv[i]  : NULL);
                        printf("%d\t",userDb[i].blance);

		}
		else
		{
                   //Do nothings !!
		}
		printf("\n");




//	 memcpy(&azColName[i], &userDb[i], sizeof(azColName[i])); 
//	printf("%s,%d,%d\n",userDb[i].name,userDb[i].acc,userDb[i].blance);
//      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
   
	printf("\n");
	return 0;
}
/************************************************************************************************************/
void  empD ::sqlDbProcess(void)
{

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
   	char *sql;
   	const char* data = "Callback function called";

   	/* Open database */
   	rc = sqlite3_open("mydatabaseTest.db", &db);

	if( rc ) 
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      		return;
        } 
	else 
	{
		fprintf(stderr, "Opened database successfully\n");
	}

   	/* Create SQL statement */
	sql = "SELECT * from BANKING";

   	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, readFromSqlDB, (void*)data, &zErrMsg);

	if( rc != SQLITE_OK ) 
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
   	} 
	else 
	{
	      fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);


}














#if not_used

int main(int argc, char* argv[]) 
{
   
sqlDbProcess();



   return 0;
}
#endif





