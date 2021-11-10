/*
    Burada amaç girilen sayının/değerin kaç basamaklı bir sayı olduğunu bulmaktır.
    Bunu yaparken pow(üslü sayı) fonksiyonunu kullandım.
    Sayıları 9, 99, 999 .. pow(10, index) ile sırasıyla karşılaştırıp kaç basamaklı (return index) olduklarını buluyorum.

    Örnek olarak, diyelim ki sayı 9dan büyük, o halde aslında 10 ile 99 arasında mı diye kontrol ediyorum.
    Eğer bu da değilse daha sonra 100-999 ve işlem böyle devam ediyor. 
     Ne zaman ki baseNumber(9, 99 ..) elimdeki sayıdan(myNumber) büyük olur, 
    demekki sayım aralıktaki(9-99-999..) sayıların uzunluğunda diyorum ve basamakları buluyorum. 

    Çünkü sayı;
     9'dan küçük veya eşit ise   1 basamaklı  --> (10^1) - 1, return 1
     10 - 99 arasında(dahil) ise 2 basamaklı  --> (10^2) - 1, return 2
     100 ile 999 arasında ise    3 basamaklı  --> (10^3) - 1, return 3
     ..
    10^n ile 10^n-1 arasında ise n basamaklı  --> (10^4) - 1, return n

    Bu işlemi ise while döngüsü ile gerçekleştiriyorum. 
    baseNumber ilk kez elimdeki sayımdan büyük olana kadar üs değerini artırıyorum.
    Zaten ilk kez büyük olduğu noktada kaç basamklı olduğunu anlıyoruz.


*/

#define  OK     1
#define  NOT_OK 0



#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iomanip>

int getFigureNumber (long int myNumber);




int state{NOT_OK};


int main()
{



    srand(time(NULL));
    
    long int myNumber{rand()};
    int      myFigure{0};

    for (int i = 1; i < 15; i++)
    {
        myNumber = rand();
        myFigure = getFigureNumber(myNumber);

        //std::cout << pow(10,2) << std::endl;
        std::cout<< "myNumber is " << std::setw(9) << myNumber << " myFigure is " <<  myFigure << std::endl;
    }





}


int getFigureNumber (long int myNumber)
{
    int baseNumber{0};
    int myFigure{0};
    int i {0};

    // sayıları 9, 99, 999.. ile sırasıyla karşılaştır ve ilk defa büyük olduğu döngüde cevabı çıktı olarak ver.
    while ( state == NOT_OK)
    {
        baseNumber = pow(10,i);
 
        if (  (baseNumber -1) >= myNumber  )
        {
            myFigure = i ;
            state    = OK ;
        }else
        {
            ++i;
        }
    }
    state = NOT_OK;
    return myFigure;

}