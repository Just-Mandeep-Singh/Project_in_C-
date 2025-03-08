/*In this program, I am tried to give example of how to use friend function 
,friend class and Constructors in Class(OOPs ) of C++ .
1. friend functions -> those function functions can access the public or private members of 
class even they are not part of that class and they do not need any obj to make call . 
2. friend class -> those class have full access of another class .
3. Constructor -> this member function invoke automatically when we declare 
obj is created with it's class */
#include<iostream>
using namespace std;
class base;
class calculation{
    public:
    void product(base);
};
class base{
    int num1, num2;
    friend void calculation:: product(base obj1);
    public:
    base(int a,int b){
        num1 =a ,num2=b;
    }
};
/*This friend function cannot directly access member of class 
we have to send an object of that class as argument in this function*/
void calculation :: product(base obj1){
    cout<<obj1.num1<<"*"<<obj1.num2<<"="<<obj1.num1*obj1.num2;
}
int main(){
/*sending arguements through constructor*/
    base obj(2,45);//->impilicit call
    //base obj = base(2,5);->explicit call
    calculation obj2;
 obj2.product(obj);
    return 0;
}