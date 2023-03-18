#include <iostream>
#include <string>
#include <map>
using namespace std;
class Animal


{

protected:
        const char * name=NULL;
        
        map<string*,const char *> map;

private:
    
public:
   std::string* color_curr=NULL;
   std::map<string*,const char*>::iterator it;
    Animal(const char* n="Noname"): name(n){}
    ~Animal() {std::cout<<"animal out"<<std::endl;}
    virtual void speak() = 0;
    virtual void set_leg_no(int x) = 0;
    
    virtual void move()
    {
        std::cout<<"I move like a "<<name<<std::endl;
    }
     void avd()
    {
        std::cout<<"cry like a bitch "<<std::endl;
    }
   void color(std::string *color1)
   {    
        this->color_curr=color1;
        std::cout<<"color of the animal is: "<<*color_curr<<std::endl;
        this->insert_map();
   }
    string* get_color_info(string * color_info)
    {
        color_info = this->color_curr;
        return color_info;
    }
    void insert_map()
    {
        map[this->color_curr]= name;
        
    }
    void print_map()
    {
        if(this->color_curr==NULL || this->name == NULL)
        {
            cout<<"null"<<endl;
        }
        else
        {
            this->it = this->map.begin();
            while (this->it != this->map.end())
          {
            std::cout << "Key: " << *(this->it->first) << ", Value: " << this->it ->second << std::endl;
            ++it;
         }
        }

    }

};
class Dog: public Animal
{
    
    private:
    int leg_no;

    public:
    Dog(const char* name):Animal(name){}
     ~Dog() {std::cout<<"I quit"<<std::endl;}
    void speak() override
    {
        std::cout<<"Dog:"<<name<<std::endl;
    }

    void move() override
    {
        std::cout<<"my name is :"<<name<<"I have:"<<leg_no<<std::endl;
    }
    void set_leg_no(int x) override
    {
        this->leg_no= x;
    }


};
class Cat: public Animal
{
    private:
    int leg_no;
    public:
    Cat(const char* name):Animal(name){}
    ~Cat() {std::cout<<"CAT quit"<<std::endl;}
    void speak() override
    {
        std::cout<<"Cat:"<<name<<std::endl;
    }


    virtual void move()
    {
        std::cout<<"my name is :"<<name<<"I have:"<<leg_no<<std::endl;
    }
    void game()
    {
        std::cout<<"I like to play"<<std::endl;
    }
    
    void set_leg_no(int x) override
    {
        this->leg_no= x;
    }


};
