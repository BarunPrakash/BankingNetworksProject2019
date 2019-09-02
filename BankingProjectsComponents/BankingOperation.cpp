/*************************************************
Name:	Designed By Barun.
Date:	2 sept 2019.
Goal:   Improving c++11 using Factorty (creational design ) pattern.
Mission: To delvelop scanale ,Romable for ccp file for Banking Layered Arch
	
	


**************************************************/

#include <stdexcept>
#include <iostream>
#include <memory>
using namespace std;

/***************************************************/


#if 0
void ProcessLoanToCustomer(LoanDispatchDep::CustomerType CustomerType);
void processLoan(void);
#endif

#define maxAmount 	50000000u   //string litral
#define silverService 	105000
#define goldService   	115000
#define dimondService 	120000

#define Debug0ff  	1

/*************************************************************************/


class HDFC_CREDIT {
	
	public:
	virtual int ApprovalLoanAmount() const = 0;
	virtual ~HDFC_CREDIT() {}  /* without this, no destructor for derived HDFC_CREDIT's will be called. */
	protected:
	#if Debug0ff
	unsigned int DepositLoanAmount=maxAmount;  //c++11 Allows
	#endif
};


/*********************************************************/

class SilverCustomer: public HDFC_CREDIT {
	public:
	virtual int ApprovalLoanAmount() const override 
	{
		cout<<"LeftAmountInBank:"<<DepositLoanAmount-silverService <<endl;
	 	return silverService ; 
	}
	virtual ~SilverCustomer() {}
};

/*************************************************************/
class GoldCustomer : public HDFC_CREDIT {
	public:
	virtual int ApprovalLoanAmount() const override
	{
		cout<<"LeftAmountInBank:"<<DepositLoanAmount-goldService  <<endl; 
		return goldService ; 
	}
	virtual ~GoldCustomer() {}
};

/************************************************************/
class DimondCustomer : public HDFC_CREDIT {
	public:
	virtual int ApprovalLoanAmount() const  override final
	{
		 cout<<"LeftAmountInBank:"<<DepositLoanAmount-dimondService  <<endl;
 		return dimondService ; 
	}
	virtual ~DimondCustomer() {}
};

/*****************************************************************/
class LoanDispatchDep final {
	public:
	enum CustomerType {
		Silver,
		Gold,
		Dimond
	};
	#if Debug0ff
	static unique_ptr<HDFC_CREDIT> createPizza(CustomerType Customertype) {
		switch (Customertype) {
		case Silver: return make_unique<SilverCustomer>();
		case Gold:      return make_unique<GoldCustomer>();
		case Dimond:    return make_unique<DimondCustomer>();
		}
		throw "invalid loan  type.";
	}
	#endif
};
/*********************************************************************/

// Create all available pizzas and print their prices

void ProcessLoanToCustomer(LoanDispatchDep::CustomerType Customertype)
{
	unique_ptr<HDFC_CREDIT> Loan = LoanDispatchDep::createPizza(Customertype);
	cout << "Loan Amount " << Customertype << " is " << Loan->ApprovalLoanAmount() << std::endl;
}


/******************************************************************/

void processLoan(void)
{

	ProcessLoanToCustomer(LoanDispatchDep::Silver);
	ProcessLoanToCustomer(LoanDispatchDep::Gold);
	ProcessLoanToCustomer(LoanDispatchDep::Dimond);
}


/********************************************************************************/
#if 0
int main()
{
	processLoan();
	return 0;
}
#endif
