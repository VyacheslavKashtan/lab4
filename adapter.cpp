#include <iostream>
using namespace std;
class Detector
{
int value1;
public:
    Detector(double value1)
    {
        this->value1=value1;
    }
    Detector()
    {

    }
    virtual ~Detector()= default;
    virtual double getpercent()
    {
        return value1;
    }
};
class LegacyDetector
{
double value2;
public:
    LegacyDetector(double value2)
    {
        this->value2=value2;
    }
    LegacyDetector()
    {
        
    }
    double returnvalue()
    {
        return value2;
    }
};
class Adapter : public Detector
{
LegacyDetector *a_;
public:
    Adapter(LegacyDetector *a) : a_(a) {}
    double getpercent() override
    {
        double b = this->a_->returnvalue()*100;
        return b;
    }
};
void ClientCode( Detector *detector) 
{
    cout << detector->getpercent();
}
int main()
{
    Detector *detector = new Detector(44);
    ClientCode(detector);
    LegacyDetector *legacydetector = new LegacyDetector(0.5);
    Adapter *adapter = new Adapter(legacydetector);
    ClientCode(adapter);
    delete detector;
    delete legacydetector;
    delete adapter;
    return 0;
}