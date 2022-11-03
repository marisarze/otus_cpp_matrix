/**
 * @file print_ip.cpp
 * @author marisarze (you@domain.com)
 * @brief functions for printing ip
 * @version MY_PROJECT_VERSION
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <map>
#include <fmt/core.h>


template <typename T, size_t num_dimensions, T default_value>
class Matrix {
    private:
        std::map<int, Matrix<T, num_dimensions-1, default_value>> content;
    public:
        //template<typename T, size_t other_num_dimension> friend class Matrix;
        Matrix() = default;
        Matrix(const Matrix<T, num_dimensions, default_value>&& other);
        size_t size();
        Matrix<T, num_dimensions-1, default_value>& operator[](int index);

};

template <typename T, size_t num_dimensions, T default_value>
Matrix<T, num_dimensions-1, default_value>& Matrix<T, num_dimensions, default_value>::operator[](int index){
    return content[index];
}

template <typename T, size_t num_dimensions, T default_value>
size_t Matrix<T, num_dimensions, default_value>::size(){
    size_t count = 0;
    for (auto it=content.begin();it!=content.end();it++){
        count += (it->second).size();
    };
    return count;
};

template <typename T, T default_value>
class Matrix<T, 1, default_value> {
    private:
        T defval = default_value;
        std::map<int, T> content;
    
    public:
        size_t size();
        T& operator[](int index);
};

template <typename T, T default_value>
T& Matrix<T, 1, default_value>::operator[](int index){
    content[index] = default_value;
    return content[index];
};


template <typename T, T default_value>
size_t Matrix<T, 1, default_value>::size(){
    size_t count = 0;
    for(auto it=content.begin();it!=content.end();it++){
        count++;
        fmt::print("found: {}", it->second);
    }
    return count;
}



