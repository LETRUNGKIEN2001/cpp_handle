#include <iostream>

class CanBo
{
    protected:
        std::string name;
        std::string address;
        int age;
        std::string gender;
    public:

        std::string getName(){return name;}
        virtual void getInfor()
        {
            std::cout<<"Thong tin can bo: " << "Name: " << name << " Age: "<< age << " "<<address <<" "<< gender << std::endl;
        }
        CanBo(std::string name, std::string address, int age, std::string gender) :
            name(name), address(address), age(age), gender(gender){}
};


class Worker : public CanBo
{
    private:
        int level;
    public:
        
        Worker(std::string name, std::string address, int age, std::string gender, int level):
            CanBo(name, address,  age, gender), level(level) {}
        void getInfor() override 
        {
            std::cout<<"Thong tin can bo: " << "Name: " << name << " Age: "<< age << " "<<address <<" "<< gender <<" " <<"Level "<< level << std::endl;
        }
};

class Engineer : public CanBo
{
    private:
        std::string major;
    public:
        Engineer(std::string name, std::string address, int age, std::string gender, std::string major):
            CanBo(name, address,  age, gender), major(major) {}
        void getInfor() override 
        {
            std::cout<<"Thong tin can bo: " << "Name: " << name << " Age: "<< age << " "<<address <<" "<< gender <<" " <<"Major: "<< major << std::endl;
        }
};

class Staff : public CanBo
{
    private:
        std::string work_domain;
    public:
        Staff(std::string name, std::string address, int age, std::string gender, std::string work_domain):
            CanBo(name, address,  age, gender), work_domain(work_domain) {}
        void getInfor() override 
        {
            std::cout<<"Thong tin can bo: " << "Name: " << name << " Age: "<< age << " "<<address <<" "<< gender <<" " <<"Work domain: "<< work_domain << std::endl;
        }
};

class Management_1 {
private:
    CanBo** list_canbo;  // Array of pointers to CanBo objects
    int capacity;       // Maximum capacity of the array
    int num_canbo;      // Number of CanBo objects currently stored

public:
    Management_1(int initialCapacity) : capacity(initialCapacity), num_canbo(0) {
        list_canbo = new CanBo*[capacity];
    }

    // Destructor to free memory
    ~Management_1() {
        for (int i = 0; i <num_canbo; ++i){
            delete list_canbo[i];
        }
        delete[] list_canbo;
    }

    void add_Canbo(CanBo* person) {
        if (num_canbo < capacity) {
            list_canbo[num_canbo] = person;
            num_canbo++;
        } 
        else{
            std::cout << "Exceed the number allowed" << std::endl;
        }
    }

    void getListCanbo()
    {
        for (int i =0; i < num_canbo; ++i)
        {
            list_canbo[i]->getInfor() ;
        }
    }

    void findStaff(const std::string& name)
    {
        bool found = false;
        for (int i =0; i<num_canbo; i++)
        {
            if (list_canbo[i]->getName() == name)
            {
                found = true;
                std::cout << "Found " << name << " with information as below" << std::endl; 
                list_canbo[i]->getInfor();
                break;
            }
        
        
     }
        if (found == false)
        {
            std::cout <<"Not Found!"<< std::endl;
        }
   }
   void leaveOut()
   {
    std::cout << "Quit out the list of staff" << std::endl;
   }
        };
        
    
int main()
{
    Worker s1("Rooney", "England", 40, "Female", 2);
    s1.getInfor();
    Engineer s2("Messi", "Argentina", 35, "Male", "Computer");
    Staff s3("Neymar", "Brazil", 37, "Male", "Marketing");
    Management_1 ds1(100);
    ds1.add_Canbo(&s1); //pass by reference
    ds1.add_Canbo(&s2);
    ds1.add_Canbo(&s3);
    ds1.getListCanbo();
    ds1.findStaff("Neymar");
    ds1.leaveOut();
    return 0;
}