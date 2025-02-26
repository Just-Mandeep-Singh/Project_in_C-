/*In this program we will learn how to use Constructors and how point to derived class with base class
pointer */
#include <iostream>
using namespace std;
/*This problem with Hierachical Inheritance-> deriving of many classes from single base class*/
// base class:-
class Company
{
protected:
    string Name;
    int Number;

public:
    /* Company(string N, int M) : Name(N), Number(M){

    }
    */

    Company(string N, int M)
    {
        Name = N;
        Number = M;
    }
    virtual void Display()
    {
        // cout << "It is base class Display function" << endl;
        /*1.It is not neccesary to define virtual function
        2. cannot be static
        3.they accessed by object pointers
        4.If we already defind a virtual function in base class ,it is not necessity to define it in dervied class
        ,If we do not define Display() function in derived class So compiler make automatic call to base class
        Display() function  */
    }
};
/*Derived class 1 :-*/

class Tech : public Company
{
protected:
    int Software;
    float Rating;

public:
    /* Tech(string N,int M,int Sof ,float Rate) : Company(N,M),Software(Sof),Rating(Rate) */

    Tech(string N, int M, int Sof, float Rate) : Company(N, M)
    {
        Software = Sof;
        Rating = Rate;
    }
    void Display()
    {
        cout << "The number of the Company is " << Number << endl;
        cout << "The name of the Company is " << Name << endl;
        cout << "The number of Softwares that are performing in market is " << Software << endl;
        cout << "The average Rating of Softwares from the Market is " << Rating << endl;
    }
};

/*Derived class 2*/

class Space : public Company
{
protected:
    int Satellite;
    float rating;

public:
    /*
        Space(string N, int M, int St, float rate) : Company(N, M)
        {
            Satellite = St;
            rating = rate;
        }
          second way to intialize value to derived class member and to make call to base class constructor  */
    Space(string N, int M, int St, float rate) : Company(N, M), Satellite(St), rating(rate)
    {
    }
    void Display() override
    {
        cout << "The number of Company is " << Number << endl;
        cout << "The Name of the Company is " << Name << endl;
        cout << "The number of Satellite is " << Satellite << endl;
        cout << "The network rating of the Satellite is " << rating << endl;
    }
};

int main()
{
    int num;
    string name;
    int count;
    float feedback;
    cout << "Enter the number of the Company =" << endl;
    cin >> num;
    cout << "Enter the name of the Company is " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter the number of products = " << endl;
    cin >> count;
    cout << "Enter the average rating of " << name << " Company have = " << endl;
    cin >> feedback;
    Tech obj1(name, num, count, feedback);

    cout << "Enter the number of the Company =" << endl;
    cin >> num;
    cout << "Enter the name of the Company is " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter the number of products = " << endl;
    cin >> count;
    cout << "Enter the average rating of " << name << " Company have = " << endl;
    cin >> feedback;
    Space obj2(name, num, count, feedback);

    Company *ptr[2];
    ptr[0] = &obj1;
    ptr[1] = &obj2;
    ptr[0]->Display();
    cout << "\n**********************\n";
    ptr[1]->Display();
    return 0;
}