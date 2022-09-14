//
// Created by morak on 2021. 11. 18..
//

#ifndef SOLUTION_N_DIM_SORT_H
#define SOLUTION_N_DIM_SORT_H

#include <iostream>
#include <vector>
#include "dual_sort.h"



//PASS-ol, tükörképével van feltöltve a mátrix, így ellenőrzi az operator sorrendben
void print_2D(int matrixSize, std::vector<std::vector<int>> temp) {
    std::cout << std::endl;
    std::cout << "2D matrix:  ";
    std::cout << std::endl;

    for (unsigned int i = 0; i < matrixSize; ++i) {
        for (unsigned int j = 0; j < matrixSize; ++j) {
            if (temp[j][i] < 10) {
                std::cout << "0";
            }
            std::cout << temp[j][i] << " ";
        }
        std::cout << std::endl;
    }


}

void print_3D(int matrixSize, std::vector<std::vector<std::vector<int>>> temp3) {
    std::cout << std::endl;
    std::cout << "3D matrix:  ";
    std::cout << std::endl;

    for (int h = 0; h < matrixSize; ++h) {
        std::cout << h << "z: " << std::endl;
        for (unsigned int i = 0; i < matrixSize; ++i) {
            for (unsigned int j = 0; j < matrixSize; ++j) {
                if (temp3[h][j][i] < 10) {
                    std::cout << "0";
                }
                std::cout << temp3[h][j][i] << " ";
            }
            std::cout << std::endl;
        }

    }
}


//N-dimenzióra is működik, gyors rendező swapja
void swapInt_n(std::pair<int, std::vector<int> > &a, std::pair<int, std::vector<int> > &b) {


    a.first = a.first + b.first;
    for (unsigned int i = 0; i < a.second.size(); ++i) {
        a.second[i] = a.second[i] + b.second[i];

    }


    b.first = a.first - b.first;
    for (unsigned int i = 0; i < a.second.size(); ++i) {
        b.second[i] = a.second[i] - b.second[i];

    }

    a.first = a.first - b.first;
    for (unsigned int i = 0; i < a.second.size(); ++i) {
        a.second[i] = a.second[i] - b.second[i];
    }

}

//N-dimenzióra is működik, gyors rendező operatora '<', ahol x,y,z szerint is rendez feladatkiíráshoz megfelelően
bool operator<(const std::pair<int, std::vector<int>> &lhs, const std::pair<int, std::vector<int>> &rhs) {
    if (lhs.first != rhs.first) {
        return lhs.first < rhs.first;
    } else {
        for (int i = 0; i < lhs.second.size(); ++i) {
            if (lhs.second[i] > rhs.second[i]) {
                return lhs.second[i] > rhs.second[i];
            }
        }

    }
    return false;
}


int divide_n(std::pair<int, std::vector<int> > *a, int down, int up) {

    std::pair<int, std::vector<int> > pivot = a[down];
    int left = down;
    int right = up;


    while (left < right) {
        //a[left] <= pivot
        while ((!(a[left] < pivot || pivot < a[left]) || a[left] < pivot) && left < up) {

            left = left + 1;

        }
        //a[right]>= pivot
        while (!(a[right] < pivot) && right > down) {
            right = right - 1;

        }


        if (left < right) {
            swapInt_n(a[left], a[right]);
        }


    }
    a[down] = a[right];
    a[right] = pivot;
    return right;
}

void quickSort_n(std::pair<int, std::vector<int> > *A, int down, int up) {

    if (down < up) {
        int q = divide_n(A, down, up);
        quickSort_n(A, down, q - 1);
        quickSort_n(A, q + 1, up);
    }

}

//3D mátrixot feltölti
void convertToMatrix_n(std::vector<int> vector, std::vector<std::vector<std::vector<int> > > &matrix, int size) {

    std::vector<std::pair<int, std::vector<int> > > squareDistance_n;

    for (int h = 0; h < size; ++h) {
        for (int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) {

                std::vector<int> coords;
                coords.push_back(j);
                coords.push_back(i);
                coords.push_back(h);
                int temp_square;
                temp_square = pow(j, 2) + pow(i, 2) + pow(h, 2);

                squareDistance_n.push_back(std::make_pair(temp_square, coords));

            }
        }
    }


    quickSort_n(&squareDistance_n[0], 0, squareDistance_n.size() - 1);

    for (int k = 0; k < vector.size(); ++k) {

        //matrix[squareDistance_n[k].second[0]][squareDistance_n[k].second[1]][squareDistance_n[k].second[2]] = vector[k];
        matrix[squareDistance_n[k].second[2]][squareDistance_n[k].second[0]][squareDistance_n[k].second[1]] = vector[k];

    }

}


//2D
void swapInt(std::pair<int, std::pair<int, int>> &a, std::pair<int, std::pair<int, int>> &b) {


    a.first = a.first + b.first;
    a.second.first = a.second.first + b.second.first;
    a.second.second = a.second.second + b.second.second;

    b.first = a.first - b.first;
    b.second.first = a.second.first - b.second.first;
    b.second.second = a.second.second - b.second.second;

    a.first = a.first - b.first;
    a.second.first = a.second.first - b.second.first;
    a.second.second = a.second.second - b.second.second;

}

//2D operator "<" x,y szerint is rendez egyenlő távolságra
bool operator<(const std::pair<int, std::pair<int, int>> &lhs, const std::pair<int, std::pair<int, int>> &rhs) {
    if (lhs.first != rhs.first) {
        return lhs.first < rhs.first;
    } else if (lhs.second.first != rhs.second.first) {
        return lhs.second.first > rhs.second.first;
    } else if (lhs.second.second != rhs.second.second) {
        return lhs.second.second > rhs.second.second;
    }
    return false;
}


int divide(std::pair<int, std::pair<int, int> > *a, int down, int up) {

    std::pair<int, std::pair<int, int> > pivot = a[down];
    int left = down;
    int right = up;


    while (left < right) {
        //a[left]<=pivot
        while ((!(a[left] < pivot || pivot < a[left]) || a[left] < pivot) && left < up) {

            left = left + 1;

        }
        //a[right] >= pivot
        while (!(a[right] < pivot) && right > down) {
            right = right - 1;

        }


        if (left < right) {
            swapInt(a[left], a[right]);
        }


    }


    a[down] = a[right];
    a[right] = pivot;
    return right;
}

//2D quicksort
void quickSort_2D(std::pair<int, std::pair<int, int> > *A, int down, int up) {

    if (down < up) {
        int q = divide(A, down, up);
        quickSort_2D(A, down, q - 1);
        quickSort_2D(A, q + 1, up);
    }

}

void convertToMatrix(std::vector<int> vector, std::vector<std::vector<int >> &matrix, int size) {

    std::vector<std::pair<int, std::pair<int, int> > > squareDistance;

    std::vector<int> temp;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            int temp_square;
            temp_square = pow(j, 2) + pow(i, 2);

            squareDistance.push_back(std::make_pair(temp_square, std::make_pair(j, i)));
            //felcserélve a i,j eredeti
            temp.push_back(temp_square);
        }

    }

    quickSort_2D(&squareDistance[0], 0, squareDistance.size() - 1);

    for (int k = 0; k < vector.size(); ++k) {

        matrix[squareDistance[k].second.first][squareDistance[k].second.second] = vector[k];
        //matrix[squareDistance[k].second.second][squareDistance[k].second.first] = vector[k];

    }

}

std::vector<std::vector<int>> sort_2D(std::vector<int> v) {
    dual_sort(v, v.size());
    int matrixSize = std::ceil(sqrt(v.size())) + 1;
    std::vector<std::vector<int>> temp;
    for (unsigned int i = 0; i < matrixSize; ++i) {
        std::vector<int> temp2;
        temp.push_back(temp2);
        for (unsigned int j = 0; j < matrixSize; ++j) {
            temp[i].push_back(0);
        }
    }

    convertToMatrix(v, temp, matrixSize);

    ///print
    print_2D(matrixSize, temp);

    return temp;
}

/**
 * 3D-be rendezi a megadott vektort
 *
 * @param v rendezendo vektor
 * @return rendezett 3D matrix
 */


std::vector<std::vector<std::vector<int>>> sort_3D(std::vector<int> v) {
    dual_sort(v, v.size());

    int matrixSize = std::ceil(std::cbrt(v.size())) + 1;
    std::vector<std::vector<std::vector<int>>> temp3;
    for (unsigned int h = 0; h < matrixSize; ++h) {
        std::vector<std::vector<int>> temp;
        for (unsigned int i = 0; i < matrixSize; ++i) {
            std::vector<int> temp2;
            temp.push_back(temp2);
            for (unsigned int j = 0; j < matrixSize; ++j) {
                temp[i].push_back(0);
            }

        }
        temp3.push_back(temp);

    }


    convertToMatrix_n(v, temp3, matrixSize);

    ///print
    print_3D(matrixSize, temp3);


    return temp3;
}

#endif //SOLUTION_N_DIM_SORT_H
