#include <iostream>
using namespace std;
bool isHillNumber(int num) 
{
    int prevDigit = -1; 
    bool increasing = true; 
    bool peakReached = false; 
    while (num > 0) 
    {
    int currentDigit = num % 10; 
        num /= 10; 
         if (increasing)
         {
            if (currentDigit < prevDigit && prevDigit != -1) 
            {
                increasing=true;
                peakReached = true;
            } else if (currentDigit == prevDigit) {
                
                return false;
            }
        } else
         {
          if (currentDigit >= prevDigit) {
                return false; 
        }
        }
prevDigit = currentDigit; 
    }
return peakReached; 
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (isHillNumber(number)) 
    {
        cout << number << " is a hill number." << endl;
    } else 
    {
        cout << number << " is not a hill number." << endl;
    }

    return 0;
}
