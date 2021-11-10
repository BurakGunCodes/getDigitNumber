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

    cout ile sayıları çıktı olarak verirken, sayılar daha düzgün görünsün diye iomanip kütüphanesini ekledim.
    Böylece sayıların basamak sayısı farklı bile olsa ekranda düzenli görünecekler, kayma olmayacak.

    time kütüphanesi ile rand fonksiyonunun her seferinde farklı değişken üretmesini sağladık.
    Eğer kullanmasaydık rand() herzaman aynı değerleri verecekti. 

*/


// DEFINE VARIABLES
#define  OK     1
#define  NOT_OK 0


// INCLUDE LIBRARY
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iomanip>

// PUBLIC FUNCTIONS
int sumOfDigitFactorial(int myNumber, int digitNumber);
int getFigureNumber (long int myNumber);
int factorial(int number);


// DECLARE GLOBAL VARIABLES
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

        std::cout<< "myNumber is " << std::setw(7) << myNumber  << ", "
                 << "myFigure is " <<   myFigure   <<    ", "   << "sum of digit fact " 
                 << sumOfDigitFactorial(myNumber,myFigure)      << std::endl;
    }



}

int factorial(int number)
{
    int fact{1};
    for( int i = 1; i<= number; i++)
    {
     fact = fact * i ;
    }

    return fact ;

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
 
        if ( (baseNumber -1) >= myNumber )
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

int sumOfDigitFactorial(int myNumber, int digitNumber)
{

    // i. basamaktaki sayi = [mod(10^i) - mod(i) ] / (10^i)  
    int* ptr_array;
  
    ptr_array = (int*)calloc( digitNumber,sizeof(int) ); 

    int base{0};

    for(int i = 1 ; i<= digitNumber ; i++)
    {
        base = pow(10,i);

        //i. digit = [mod(10^i) - mod(10^(i-1))] / 10^i
        ptr_array[digitNumber - i] = ( ((int)myNumber % ( base ) - ((int)myNumber % (base/10) ) ) / (base/10) ) ; 
    }

    //for(int i = 0 ; i< digitNumber ; i++)
    //{
    //    std::cout << " " << ptr_array[i] ;
    //}
    // std::cout << std::endl;
    
    int sumOfFact{0};

    for(int i = 0; i< digitNumber;  i++)
    {
        sumOfFact = sumOfFact + factorial( ptr_array[i] ) ;
    }

    free(ptr_array);

    return sumOfFact ;
}