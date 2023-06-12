#include <stdio.h>
#include<iostream>
#include<string>
#include<memory>
using namespace std;
/******************************
Designed: Barun Prakash, Date:10/06/2023, Objective:To understand OOAD-C++11,C++14.,Vesion:1.0.0
****************************/
class LCDcluster  
{
    private:
    uint32_t LDD_tunnigConfig;
    string  cruseControlType;
    float tempDispFq;
    public:
    void setTuningConfig(uint32_t tunnig) {LDD_tunnigConfig=tunnig;}
    void setCruseControlType(const string & str){ cruseControlType=str;}
    void setTempdispFq(float fq){ tempDispFq=fq;}
    //void setTempdispFq(float fq): tempDispFq(fq){}
    void Debug(void)
    {
   
        cout<<"LDD_tunnigConfig:-" <<LDD_tunnigConfig<<"cruseControlType:-"<<cruseControlType<<"tempDispFq:-"<<tempDispFq<<endl;
    }
   
     
};
// Abstract Builder
class LDDtunnigConfigBuilder
{
    protected:
    unique_ptr<LCDcluster> c_LCDcluster;
    public:
    virtual ~LDDtunnigConfigBuilder(){};
    LCDcluster* getLCDcluster(void)
   {
        return c_LCDcluster.get();
       
    }
    void creatLCDclusterIntance(void)
    {
        c_LCDcluster =make_unique<LCDcluster>();
    }
    virtual void buildTuningConfig(void)=0;
    virtual void builCruseControlType(void)=0;
    virtual void buildTempdispFq(void)=0;
   
};
#if 0
LCDcluster* LCDcluster::getLCDcluster()
{
    return c_LCDcluster.get();
}
#endif
class LevelA_grafic : public LDDtunnigConfigBuilder
{
   
    public:
    virtual ~LevelA_grafic(){}
    virtual void buildTuningConfig(void)
    {
        c_LCDcluster->setTuningConfig(1);
    }
    virtual void builCruseControlType(void)
    {
       c_LCDcluster->setCruseControlType("2XGrafic");
    }
    virtual void buildTempdispFq(void)
    {
       c_LCDcluster->setTempdispFq(32.5);    
    }
   
};
class LevelB_grafic : public LDDtunnigConfigBuilder
{
   
    public:
    virtual ~LevelB_grafic(){}
    virtual void buildTuningConfig(void)
    {
        c_LCDcluster->setTuningConfig(2);
    }
    virtual void builCruseControlType(void)
    {
       c_LCDcluster->setCruseControlType("4XGrafic");
    }
    virtual void buildTempdispFq(void)
    {
       c_LCDcluster->setTempdispFq(34.5);    
    }
   
};

class LevelC_grafic : public LDDtunnigConfigBuilder
{
   
    public:
    virtual ~LevelC_grafic(){}
    virtual void buildTuningConfig(void)
    {
        c_LCDcluster->setTuningConfig(3);
    }
    virtual void builCruseControlType(void)
    {
       c_LCDcluster->setCruseControlType("8XGrafic");
    }
    virtual void buildTempdispFq(void)
    {
       c_LCDcluster->setTempdispFq(35.5);    
    }
   
};
class factoryProduction
{
    private:
    LDDtunnigConfigBuilder *LDDtunnigConfigBuilder_V;
    public:
    void startProductTest(void)
    {
      //  LDDtunnigConfigBuilder_V->getLCDcluster->Debug();
    }
    void makeStartProduct(LDDtunnigConfigBuilder *pb)
    {
        LDDtunnigConfigBuilder_V=pb;
        LDDtunnigConfigBuilder_V->creatLCDclusterIntance();
        LDDtunnigConfigBuilder_V->buildTuningConfig();
        LDDtunnigConfigBuilder_V->builCruseControlType();
        LDDtunnigConfigBuilder_V->buildTempdispFq();
    }
};
int main()
{
 factoryProduction factoryProduction_obj;
 LCDcluster LCDcluster_ob;
 LevelA_grafic  LevelA_grafic_obj;
 LevelB_grafic  LevelB_grafic_obj;
 LevelC_grafic  LevelC_grafic_obj;
 factoryProduction_obj.makeStartProduct(&LevelA_grafic_obj);
 factoryProduction_obj.startProductTest();
 factoryProduction_obj.makeStartProduct(&LevelB_grafic_obj);
 factoryProduction_obj.startProductTest();
 factoryProduction_obj.makeStartProduct(&LevelC_grafic_obj);
 factoryProduction_obj.startProductTest();
//LCDcluster_ob.Debug();
 
    return 0;
}
