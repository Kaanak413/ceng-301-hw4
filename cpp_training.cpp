using namespace std;
#include <iostream>
#include "class.h"
//function overloading,compile time
void test(int a,int b);
void test(int a,float b);
void test(float a,float b);

void test(int a,int b)
{
    std::cout<<"test1:"<<a+b<<std::endl;
}
void test(int a,float b)
{
    std::cout<<"test:"<<a+b<<std::endl;
}


void test(float a,float b)
{
    std::cout<<"test3:"<<a+b<<std::endl;
}


int main()
{
    int a =5;
    int b =6;
    int op = 7;
    int opk = 8;
    float c= 5.6;
    float d= 55.4;
    std::string s = "blue";
    std::string *strptr = &s;
    std::string *info = nullptr;
    test(a,b);
    test(a,c);
    test(c,d);
    // Animal *aPtr = new Animal("Osa");
    // aPtr->speak();
    
    
    
    Dog *dptr = new Dog("Karabas");
    dptr->set_leg_no(a);
    dptr->move();
    Cat p("okee");
    Cat & xd = p;
    Animal &ppp = p;
    ppp.set_leg_no(op);
    ppp.avd();
    ppp.move();
    xd.set_leg_no(b);
    xd.move();
    xd.color(strptr);
   
    info = xd.get_color_info(info);
    std::cout<<*info<<std::endl;
    Cat *cptr = new Cat("loki");
    cptr->set_leg_no(b);
    cptr->move();
    cptr->avd();
    cptr->color(strptr);
    xd.print_map();
    return 0;
}