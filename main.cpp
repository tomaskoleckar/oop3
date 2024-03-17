#include "ExtendedArray.h"

using namespace std;




int main()
{
    ExtendedArray * e1 = new ExtendedArray(10); 
    ExtendedArray * e2 = new ExtendedArray(10); 
    ExtendedArray * e3 = new ExtendedArray(10); 

    e1->fillWithRandomNumbers(0,20);
    e2->fillWithRandomNumbers(0,20);
    e3->fillWithRandomNumbers(0,20);


    cout << "First array : ";
    e1->printArr();

    cout << "Second array : ";
    e2->printArr();

    cout << "Third array : ";
    e3->printArr();

    ExtendedArray * e1a2 = e1->merge(e2);

    cout << "First and second merged : ";
    e1a2->printArr();

    ExtendedArray * e2s3 = e2->intersect(e3);

    cout << "Second and third shared items : ";
    e2s3->printArr();



    delete e1;
    delete e2;
    delete e3;
    delete e1a2;
    delete e2s3;

    return 0;
}
