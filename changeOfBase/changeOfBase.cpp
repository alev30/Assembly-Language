#include <iostream>
#include <string>
#include <vector>
#include <cmath>


double conversion(std::string num, double base, bool & alpha){
    double result = 0;
    double j = num.size() - 1;
    for (int i = 0; i < (short) num.size(); i++){
        if (isalpha(num[i]) && isupper(num[i]) && !isdigit(num[i])){
            result += ( (num[i]-55) * pow(base,j) );
            j--;
            alpha = true;
        }
        else if(isalpha(num[i])&& !isdigit(num[i])){
            result += ( (num[i]-87) * pow(base,j) );
            j--;
            alpha = true;
        }
        else{
            result += ((num[i] - '0') * pow(base,j) );
            j--;
        }
    }
    /*
    std::string cone;
    for (int i = 0; i < (short) vec.size(); i ++){
        cone.append(std::to_string(vec[i]));
    }

    std::string cone2;

    int result= 0;

    int j = 0;
    for (int i = (short) cone.size() -1; i >= 0; --i  ){
        double appy = (cone[j] - '0') * pow(base,(double) i );
        result += appy;
        ++j;
    }
     */

    return result;
}

int main() {
    std::cout << "Please enter the number's base: ";
    double base;
    std::cin >> base;
    std::cout << "Please enter the number: ";
    std::string number;
    std::cin >> number;

    bool alpha = false;

    double numberconvert = conversion(number, base, alpha);



    std::cout << "Please enter the new base: ";
    int newbase;
    std::cin >> newbase;
    auto tempNum = (uint)numberconvert;




    if (newbase > 10 && newbase < 37){
        std::string alphastring;
        while(tempNum > 0){
            if(tempNum% newbase >= 10 && tempNum % newbase <= 36){
                char cone = tempNum%newbase + 55;
                alphastring.push_back(cone);
            }
            else{
                char cone  = tempNum%newbase + '0';
                alphastring.push_back(cone);
            }
            tempNum /= newbase;
        }

        std::cout << number << " base " << base << " is ";
        for (int i = (short) alphastring.size() - 1; i >= 0; i--) {
            std::cout << alphastring[i];
        }
        std::cout << " base " << newbase << std::endl;


    }
    else {


        std::vector<int> newnum;


        while (tempNum > 0) {
            newnum.push_back(tempNum % newbase);
            tempNum /= newbase;
        }


        std::cout << number << " base " << base << " is ";
        for (int i = (short) newnum.size() - 1; i >= 0; i--) {
            std::cout << newnum[i];
        }
        std::cout << " base " << newbase << std::endl;
    }




    return 0;
}