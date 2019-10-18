#include <bits/stdc++.h>
using namespace std;

std::string convertFromArabicToRoman(int);
int convertFromRomanToArabic(const std::string&);

int main() {
    std::string number;

    while(cin >> number)
    {
        if ('0' < number[0] && number[0] <= '9') {
            int num = 0; num = stoi(number);
            std::string arabicResult = convertFromArabicToRoman(num);
            std::cout << arabicResult << std::endl;
        }else{
            int romanResult =  convertFromRomanToArabic(number);
            std::cout << romanResult << std::endl;
        }
    }

    return 0;
}

std::string convertFromArabicToRoman(int number)
{
    int divisors[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romanos[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string result;
    for(int i = 0; i < 13; i++)
    {
        if(number >= divisors[i]){
            int div = number / divisors[i];
            number = number % divisors[i];
            for(int k = 0; k < div; k++)
                result += romanos[i];
        }
    }
    return result;
}


int convertFromRomanToArabic(const std::string& number)
{
    int result = 0;

    for (int i = 0; i < static_cast<int>(number.size()); ++i)
    {
        switch(number[i]){
            case 'M':{ result += 1000; break; }
            case 'D':{ result += 500; break; }
            case 'L':{ result += 50; break; }
            case 'V':{ result += 5; break; }
            case 'C':{
                if (number[i+1] == 'D' || number[i+1] == 'M') {
                    if (number[i+1] == 'D') { result += 400; }
                    else { result += 900; }
                    ++i;
                }
                else{ result += 100; }
                break;
            }
            case 'X':{
                if (number[i+1] == 'L' || number[i+1] == 'C') {
                    if (number[i+1] == 'L') { result += 40; }
                    else { result += 90; }
                    ++i;
                }
                else{ result += 10; }
                break;
            }
            case 'I':{
                if (number[i+1] == 'V' || number[i+1] == 'X') {
                    if (number[i+1] == 'V') { result += 4; }
                    else { result += 9; }
                    ++i;
                }
                else{ result += 1; }
                break;
            }
        }
    }

    return result;
}
