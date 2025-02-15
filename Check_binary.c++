/*usage of classes and objects*/
#include <iostream>
using namespace std;

class student
{
private:
    int result;
    
     
   // int *array;

public:
    int subject;
   
int n;
 int array[];
       void n_marks()
    {
        cout << "Enter how much Marks you would like to store =  ";
        cin >> n;
        array[n];
    }
    void enter();
    void check_M();
    void check_A();
    void final();
};
void student ::enter()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter your marks in " << i + 1 << " Subject = ";
        cin >> array[i];
    }
}
void student ::check_M()
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] < 30 && 0 < array[i])
        {
            cout << "Sorry! but you are failed in " << i + 1 << " Subject" << endl;
        }
        else if (array[i] > 30 && array[i] < 100)
        {
            cout << "Congratulation! you are passed in " << i + 1 << " subject " << endl;
        }
        else
        {
            cout << "Sorry, invaild Marks entered by user in " << i + 1 << " subject " << endl;
        }
    }
}

void student ::check_A()
{
    static int c = 0;
    for (int i = 0; i < n; i++)
    {
        c = c + array[i];
    }
    if ((c / n) < 33 && (c / n) > 0)
    {
        cout << "Sorry! you are failed, because your average is less than minimum ceriteria " << endl;
    }
    if ((c / n) > 33 && (c / n) < 100)
    {
        cout << "congratulation! you are passed, because your average is above than minimum ceriteria " << endl;
    }
    else
    {
        cout << "Invailed average check Marks enter by user " << endl;
    }
}
int main()
{
    student s;
   s.n_marks();
    s.enter();
    s.check_M();
    s.check_A();
    // s.final();
    return 0;
}