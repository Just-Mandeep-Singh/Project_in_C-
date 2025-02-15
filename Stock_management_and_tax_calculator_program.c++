/*In this program I will write an code manage
an accounting department of a Super_Market*/
#include <iostream>
using namespace std;
class Super_Market
{
private:
    int code[1000];
    float price[1000];
    float tax[1000];
    int num;
    int Dairy_cout = 0, Vegs_cout = 0, Others_count = 0;
    float total_price = 0;
    float total_tax = 0;

public:
    void prod_c();             // product count
    void prod_R(void);         // product for retailers
    void ident_prod_tax(void); // identifing_product_category_taxiation
    void prod_C(void);         // product for coustumers
};
void Super_Market::prod_c()
{
    cout << "Please! note that code of 1 to 10 for dairy product, code of 11 to 20 for veges\n";
    cout << "code of 21 to 30 is for other iteams\n";
    cout << "Enter how much product pending to arrange in system = ";
    cin >> num;
}
void Super_Market::prod_R()
{

    cout << " Enter the retail price of an product as well as " << endl;
    cout << "Enter the code of product to Identify the category of it ,Thankyou!" << endl;
    for (int i = 0; i < num; i++)
    {
        if (code[i] == '\n')
        {
            break;
        }
        else
        {
            cout << "Enter the code of product " << i + 1 << " = ";
            cin >> code[i];
            cout << "Enter it's retail price = ";
            cin >> price[i];
            total_price += price[i];
            cout << "\n****************************\n";
        }
    }
}
void Super_Market ::ident_prod_tax(void)
{

    for (int i = 0; i < num; i++)
    {
        if (code[i] <= 10 && code[i] >= 1)
        {
            Dairy_cout  = Dairy_cout + 1;
            tax[i] = price[i] * 0.05;
            cout << "Product number " << i + 1 << " dairy product it's tax will be " << tax[i] << endl;
            cout << "\n****************************\n";
        }
        else if (code[i] >= 11 && code[i] <= 20)
        {
            Vegs_cout = Vegs_cout + 1;
            tax[i] = price[i] * 0.10;
            cout << "product number " << i + 1 << " vegetable ,it's tax will be " << tax[i] << endl;
            cout << "\n****************************\n";
            // t_tax += tax[i];
        }
        else if (code[i] >= 21 && code[i] <= 30)
        {
            Others_count = Others_count + 1;
            tax[i] = price[i] * 0.15;
            cout << "product number " << i + 1 << " other iteams ,it's tax will be " << tax[i] << endl;
            cout << "\n****************************\n";
            //  t_tax += tax[i];
        }
        else
        {
            cout << "Sorry, This product is not in stock ";
        }
        total_tax += tax[i];
    }
}
void Super_Market::prod_C(void)
{
    cout << "Here is list of retail price,tax,price after taxiation" << endl;
    for (int i = 0; i < num; i++)
    {
        if (code[i] <= 10 && code[i] >= 1)
        {

            price[i] = price[i] + tax[i];
            cout << "Product number " << i + 1 << " dairy product it's tax will be " << tax[i] << endl;
            cout << "Price of the product for coustumers = " << price[i] << endl;
            cout << "\n****************************\n";
        }
        else if (code[i] >= 11 && code[i] <= 20)
        {
            price[i] = price[i] + tax[i];
            cout << "product number " << i + 1 << " vegetable ,it's tax will be " << tax[i] << endl;
            cout << "Price of the product for coustumers = " << price[i] << endl;
            cout << "\n****************************\n";
        }
        else if (code[i] >= 21 && code[i] <= 30)
        {
            price[i] = price[i] + tax[i];
            cout << "product number " << i + 1 << " other iteams ,it's tax will be " << tax[i] << endl;
            cout << "Price of the product for coustumers = " << price[i] << endl;
            cout << "\n****************************\n";
        }
    }
    cout << "Total number of Diary product = " << Dairy_cout  << "\n";
    cout << "Total number of vegetable product = " << Vegs_cout << "\n";
    cout << "Total number of Other Items categray = " << Others_count << "\n";
    cout << "Total, retail cost = " << total_price << endl;
    cout << "toatl, Taxation on the products = " << total_tax << endl;
}
int main()
{
    Super_Market s1;
    s1.prod_c();
    s1.prod_R();
    s1.ident_prod_tax(); // identifing_product_category_taxiation
    s1.prod_C();
    return 0;
}