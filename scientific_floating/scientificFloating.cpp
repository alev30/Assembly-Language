#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char* argv[]) {

    std::cout << "Please enter a float: ";
    float flo;
    std::cin >> flo;


    bool zero = true;
    unsigned int float_int = *((unsigned int*)&flo);
    std::vector<int> binary_vec;
    int exp = 0;
    std::string output;

    for(int i=31;i>=0;i--){
        if(!(float_int & (1 << i))) {
            binary_vec.push_back(0);
        }
        if((float_int & (1 << i))){
            binary_vec.push_back(1);
            zero = false;
        }
    }

    if (zero) {
        std::cout<< "0E0" << std::endl;
        return 0;
    }

    if (flo < 0){
        output.push_back('-');
    }
    output.append("1.");

    int index = 0;

    for(int i = 9; i < 32; i++)  {
        for ( int j = i + index; j < 32; j++){
            if (binary_vec[j]==1){
                output.append(std::to_string(binary_vec[i]));
                break;
            }
        }
    }


    for(int i = 1; i <9; i++){
        if(binary_vec[i] == 1)
            exp += pow(2,8-i);
    }

    exp -= 127;

    output.push_back('E');
    output.append(std::to_string(exp));

    std::cout<< output <<std::endl;

    return 0;
}