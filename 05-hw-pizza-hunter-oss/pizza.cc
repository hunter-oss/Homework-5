/**
 *   @file: pizza.cc
 * @author: Hunter Douglas
 *   @date: April 5th 20221
 *  @brief: Filter through input document and read different orders of pizza
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

///Constants, structures, classes, and function prototypes

using namespace std;

//Creating structure
struct Pizza
{
    char size;
    string type;
    int numToppings;
};

//Function that loads the pizzas
int loadPizzas(struct Pizza pizzas[])
{
    int i=0;
    string fileName;

    cout << "\nEnter the pizza log file name: ";
    cin >> fileName;

    //Opening file for reading
    fstream fin(fileName, ios::in);

    //Temporary pizza
    struct Pizza temp;

    //Reading data
    while(fin.good())
    {
        fin >> temp.size >> temp.type >> temp.numToppings;

        //Storing in array
        pizzas[i] = temp;
        i++;
    }
    fin.close();

    return i;
}

//Function that returns number of small and large pizzas
void getLargeSmallPizzas(struct Pizza pizzas[], int cnt, int &large, int &small)
{
    int i;

    //Initially set to 0
    large = 0;
    small = 0;

    //Iterating over array
    for(i=0; i<cnt; i++)
    {
        //Comparing values
        if(pizzas[i].size == 'l' || pizzas[i].size == 'L')
    {
        large++;
    }
    else if(pizzas[i].size == 's' || pizzas[i].size == 'S')
    {
        small++;
    }
    }
}

//Function that returns the total price of all pizzas
double getTotal(struct Pizza pizzas[], int cnt)
{
    int i;
    double total=0;

    //Iterating over array
    for(i=0; i<cnt; i++)
    {
//Comparing values
        if(pizzas[i].size == 'l' || pizzas[i].size == 'L')
        {
            //Pizza cost
            total = total + 8;
            //Toppings cost
            total = total + (pizzas[i].numToppings * 2);
        }
        else if(pizzas[i].size == 's' || pizzas[i].size == 'S')
        {   
            //Pizza cost
            total = total + 5;
            //Toppings cost
            total = total + (pizzas[i].numToppings * 1);
        }

        //Converting type to lower
        transform((pizzas[i].type).begin(), (pizzas[i].type).end(), (pizzas[i].type).begin(), ::tolower);

        //Checking for wheat pizza
        if((pizzas[i].type).compare("wheat") == 0)
        {
        total = total + 1;
        }
    }
    return total;
}

//Function that output results
void displayResult(int large, int small, double total)
{
    int i;

    cout << fixed << setprecision(2);
    //Printing result
    cout << "\nThe total number of pizzas sold: " << (large + small);
    cout << "\nThe number of large pizzas sold: " << large;
    cout << "\nThe number of small pizzas sold: " << small;
    cout << "\nThe total price of all pizzas: $" << total << "\n\n";
}

//Main function
int main()
{
    //Creating an array of objects
    struct Pizza pizzas[100];
    int cnt=0, large, small;
    double total;

    //Calling functions
    cnt = loadPizzas(pizzas);
    getLargeSmallPizzas(pizzas, cnt, large, small);
    total = getTotal(pizzas, cnt);
    displayResult(large, small, total);

    return 0;
}