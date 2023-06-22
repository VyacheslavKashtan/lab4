#include <iostream>
#include <string>
using namespace std;
class Object
{
    int date;
    int month;
public:
    Object(int date, int month)
    {
        this->date=date;
        this->month=month;
    }
    int datee()
    {
        return date;
    }
    int monthh()
    {
        return month;
    }
};
class Function
{
    public: 
    virtual int smth(int x,int y) = 0;
    virtual string smth1(string s) = 0;
};
class Serializer :  public Function
{
    int x;
    int y;
    public:
    int smth(int x,int y) override 
    {
        cout<<"do serializer ";
        cout<<to_string(x)<<" "<<to_string(y)<<" "; 
        return 0;
    }
    string smth1(string s) override
    {
        cout<<" ";
    }
};
class Deserializer :  public Function
{
    string s;
    public:
    string smth1(string s) override 
    {
        cout<<"do deserializer ";
        cout<<stoi(s)<<" ";
        return 0;
    }
    int smth(int x,int y) override 
    {
        cout<<" ";
    }
};
int main() 
{
    Object object(6,12);
    int x = object.datee();
    int y = object.monthh();
    string s = "612";
    cout<<x<<" "<<y<<" ";
    Function* serializer = new Serializer();
    Function* deserializer = new Deserializer();
    serializer->smth(x,y);
    deserializer->smth1(s);
    return 0;
}