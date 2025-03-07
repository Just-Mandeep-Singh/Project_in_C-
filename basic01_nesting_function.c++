/*In this program we will ,what is nesting of member function
class and  how we can use or we are using in real world!

1. nesting of member function is making a call to  member function  using the
refrenece of another member function or we can say making a call to member
function in another member function.

2. Two are major advantages of using nesting of function
->privacy of data
-> secuity from attact
normal users can not assess that function even programmer can not directly access  that
data */
 //It calculates student scores, averages, and results.
#include <iostream>
using namespace std;
class Score
{
private:
    int number;
    static float total;
    float average;
  
    void check_marks(void);
    void check_average(void);
    int static pass, fail;
float *ptr;
public:
 
    void num_subjects(void);
    void marks(void);
    void result(void);
};
/*To use static variable we have to intialize them out of the class */
int Score ::pass = 0;
int Score ::fail = 0;
float Score ::total = 0;
void Score ::num_subjects(void)
{
    cout << "Please! ,Enter how many subjects you have = ";
    cin >> number;
    /* I declared it later because to avoid memory leckage */
     ptr = new float[number]; // to declred array in C++ by memory allocation
   
}

void Score ::marks(void)
{
    for (int i = 0; i < number; i++)
    {
        cout << "Enter your marks in " << i << " subject = ";
        cin >> ptr[i];
        total += ptr[i];
    }
}

void Score ::check_marks(void)
{
    for (int i = 0; i < number; i++)
    {
        if (ptr[i] < 33 && ptr[i] > 0)
        {
            cout << "Sorry your failed in " << i<< " subject marks is =" << ptr[i] << endl;

            fail += 1;
        }
        if (ptr[i] >=33 && ptr[i] <= 100)
        {
            cout << "Congratulations! your passed in " << i  << " subject marks is = " << ptr[i] << endl;
            pass += 1;
        }
        else
        {
            cout << "Sorry! unvalid marks entred by you!" << endl;
        }
    }
}
void Score ::check_average(void)
{
    average = total / number;
    if (average < 35 && average > 0)
    {
        cout << "Sorry your are failed your average is less then minimum score " << average << endl;
    }
    else if (average >= 35 && average <= 100)
    {
        cout << "Congratulations! you average more than minimum score  " << average << endl;
    }
    else{
        cout<<"invalid average calculated! "<<endl;
    }
}
void Score ::result(void)
{
    /*nesting of member functions */
    check_marks();
    check_average();
    cout << "you are passed in " << pass << endl;
    cout << "you are failed in " << fail << endl;
    cout << "your average score is " << average << endl;
    delete (ptr); // free the memorary allocated to ptr[] array
}
int main()
{
    /*I want user can only see and make call to public memeber function but I want to make rest of
    function run in behind */
    Score Obj;
    Obj.num_subjects();
    Obj.marks();
    Obj.result();
    /*void check_marks(void); , void check_average(void); I can not make direct call
    to that function in main() function  because they declared privately So, to make
    nesting of this functions call them from the any public function according to our convenience or use
    at this time I use result()function */

    return 0;
}
