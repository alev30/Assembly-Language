#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char* argv[]) {


    std::vector<int> argvec(argc);
    bool upper;

    std:: cout << "You entered the word: ";

    for (int i = 1; i < argc; i++){
        upper =  false;
        std::string temp = argv[i];
        int tempval =  std::stoi(temp);
        if (tempval >= 67108865){
            tempval -= 67108864;
            argvec[i-1]= tempval;
            upper = true;
        }
        else{
            argvec[i-1]= tempval;
        }

        if (upper){
            auto tempchar = char('a' + log2((double) (argvec[i - 1])));
            tempchar = tempchar - 32;
            std::cout << tempchar;
        }
        else {
            std::cout << char('a' + log2((double) (argvec[i - 1])));
        }
    }


    std::cout << std::endl;
    return 0;
}