
/****************************************************************
 * Designed by Barun .
 * Date : 8 sept 2019
 * Scope :- To get the credit  coupon  best on Amount transition .
 * It tell you saving money after coupon distribution .
 */

//HDFC HDFCWalletCoupan

#include<iostream>
#include<thread>
#include<vector>
#include<mutex>


#define User     5

class  HDFCWalletCoupan final
{
	int SumAmountWallet=0;
	std::mutex mutex;
public:
	HDFCWalletCoupan() :SumAmountWallet(6000){}
    int getMoney()   { 	return SumAmountWallet; }
    void addMoney(int money)
    {
		mutex.lock();
    //	for(int i = 0; i < money; ++i)
	//	{
	        std::cout<<"Before"<<SumAmountWallet<<'\n'  ; 
			SumAmountWallet = SumAmountWallet -money;
			for(int i=0;i<100;i++);
			std::cout<<SumAmountWallet<<'\n';
	//	}
		mutex.unlock();
    }
};



/***************************************************************/
int ProcessHDFCWalletCoupan()
{
    HDFCWalletCoupan HDFCWalletCoupanObject;
    unsigned short int UserCreditarr[User]={500,1000,1500,700,300};
    std::vector<std::thread> HDFCuser;
    for(unsigned int noOfUser = 0; noOfUser < User; ++noOfUser){
        HDFCuser.push_back(std::thread(&HDFCWalletCoupan::addMoney, &HDFCWalletCoupanObject, UserCreditarr[noOfUser]));
    }

    for(unsigned int noOfUser = 0; noOfUser < HDFCuser.size() ; noOfUser++)
    {
        HDFCuser.at(noOfUser).join();
    }
    return HDFCWalletCoupanObject.getMoney();
}

/*******************************************************************/

void processHDFCWallet(void)
{
	int val = 0;
		for(int k = 0; k < 5; k++)
		{
			if((val = ProcessHDFCWalletCoupan()) == 6000)
			{
				std::cout <<  "  not !!!Money in HDFCWalletCoupan = "<<val << std::endl;
	//break;
			}
		}
}
/**************************************************/

int main()
{
	processHDFCWallet();
	return 0;
}
