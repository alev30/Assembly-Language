#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int upperTriCalc(int square){
    if (square == 0){
        return 0;
    }
    else{
        return square + upperTriCalc(square-1);
    }

}

int main(int argc, char* argv[]) {

    std::ifstream mat_text1(argv[1]);
    std::ifstream mat_text2(argv[2]);

    int matrix_square = 0;
    mat_text1 >> matrix_square;
    mat_text2 >> matrix_square;



    int matrix_size = upperTriCalc(matrix_square);
    std::vector<int> mat1 (matrix_size);
    std::vector<int> mat2 (matrix_size);
    std::vector<int> output_matrix;

    for (int i =0 ; i < matrix_size; i++){
        mat_text1 >> mat1[i];
        mat_text2 >> mat2[i];
    }




    int matrix_A =0, matrix_B = 0, rowzeros = 0, colzeros = 0;

    int total, increment, second_increment;

    for (int i = 0; i < matrix_square; i++){
        for(int j = 0; j < matrix_square; j++){
            total = 0;
            increment = i+1;
            rowzeros = ((increment-1)*increment)/2;
            for (int k = 0; k < matrix_square; k++){
                if (k > j || k < i) continue;
                second_increment = k +1;
                matrix_A = mat1[matrix_square*i + k - rowzeros];
                colzeros = ((second_increment-1)*second_increment)/2;
                matrix_B = mat2[k*matrix_square+j -colzeros];
                total += (matrix_A*matrix_B);
            }
            if (j >= i) output_matrix.push_back(total);
        }
    }


    for (int i = 0; i < matrix_size; i++){
        std::cout<< output_matrix[i] << " ";
    }

    std::cout <<  std::endl;



    return 0;
}