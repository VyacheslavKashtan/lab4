#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
class Event;
class Mediator {
public:
    virtual void Notify(Event *sender, string event) const = 0;
};
class Event {
protected:
    Mediator *mediator_;
public:
    Event(Mediator *mediator = nullptr) : mediator_(mediator) { }
    void set_mediator(Mediator *mediator) 
    {
        this->mediator_ = mediator;
    }
    virtual ~Event(){}
};

class EventListener1 : Event 
{
string str;
public:
    string reverseline(string str)
    {
        cout << "ReversedLine\n";
        reverse(str.begin(), str.end());
        this->mediator_->Notify(this, str);
        return str;
    }
};
class EventListener2 : Event
{
string str;
public:
    string nospaceline(string str)
    {
        cout << "NospaceLine\n";
        remove_if(str.begin(), str.end(),isspace);
        this->mediator_->Notify(this, str);
        return str;
    }
};
class ConcreteMediator : public Mediator {
private:
    EventListener1 *eventListener1_;
    EventListener2 *eventListener2_;
    string str;
public:
    ConcreteMediator(EventListener1 *c1, EventListener2 *c2)  
    {
        eventListener1_=c1;
        eventListener2_=c2;
        eventListener1_->set_mediator(this);
        eventListener2_->set_mediator(this);
    }
    void Notify(Event *sender, string event) const override
    {
        this->eventListener1_->reverseline(str);
        this->eventListener2_->nospaceline(str);
    }
};
void ClientCode() {
    EventListener1 *c1 = new EventListener1;
    EventListener2 *c2 = new EventListener2;
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2);
    string y;
    cin>>y;
    c1->reverseline(y);
    c2->nospaceline(y);
    delete c1;
    delete c2;
    delete mediator;
}
int main()
{
    ClientCode();
    return 0;
}