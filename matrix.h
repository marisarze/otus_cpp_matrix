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
        std::map<int, Matrix<T, num_dimensions-1, default_value>> value;
    public:
        //template<typename T, size_t other_num_dimension> friend class Matrix;
        Matrix() = default;

        template<T other_default>
        Matrix(const Matrix<T, num_dimensions, other_default>& other_matrix);

        template<T other_default>
        Matrix(Matrix<T, num_dimensions, other_default>&& other_matrix);
        size_t size();
        Matrix<T, num_dimensions-1, default_value>& operator[](int index);

};

template <typename T, size_t num_dimensions, T default_value>
template <T other_default>
Matrix<T, num_dimensions, default_value>::Matrix(const Matrix<T, num_dimensions, other_default>& other_matrix){
    this->value = other_matrix.value;
}

template <typename T, size_t num_dimensions, T default_value>
template <T other_default>
Matrix<T, num_dimensions, default_value>::Matrix(Matrix<T, num_dimensions, other_default>&& other_matrix){
    this->value = other_matrix.value;
}

template <typename T, size_t num_dimensions, T default_value>
Matrix<T, num_dimensions-1, default_value>& Matrix<T, num_dimensions, default_value>::operator[](int index){
    return value[index];
}

template <typename T, size_t num_dimensions, T default_value>
size_t Matrix<T, num_dimensions, default_value>::size(){
    size_t count = 0;
    for (auto it=value.begin();it!=value.end();it++){
        count += (it->second).size();
    };
    return count;
};


template <typename T, T default_value>
class Matrix<T, 0, default_value> {
    private:
        bool is_default = true;
        T value = default_value;
    public:
        Matrix() = default;
        Matrix(T value);
        Matrix<T, 0, default_value>& operator=(T&& other_value);
        Matrix<T, 0, default_value>& operator=(const T& other_value);

        template <T other_default>
        Matrix<T, 0, default_value>& operator=(Matrix<T, 0, other_default>&& other_matrix);
        
        template <T other_default>
        Matrix<T, 0, default_value>& operator=(const Matrix<T, 0, other_default>& other_matrix);

        size_t size();
        operator T();
};

template <typename T, T default_value>
Matrix<T, 0, default_value>::Matrix(T value){
    this->is_default = false;
    this->value = value;
}

template <typename T, T default_value>
template <T other_default>
Matrix<T, 0, default_value>& Matrix<T, 0, default_value>::operator=(Matrix<T, 0, other_default>&& other_matrix){
    this->is_default = false;
    this->value = other_matrix.value;
    return *this;
}

template <typename T, T default_value>
Matrix<T, 0, default_value>& Matrix<T, 0, default_value>::operator=(T&& other_value){
    this->is_default = false;
    this->value = other_value;
    return *this;
}

template <typename T, T default_value>
template <T other_default>
Matrix<T, 0, default_value>& Matrix<T, 0, default_value>::operator=(const Matrix<T, 0, other_default>& other_matrix){
    this->is_default = false;
    this->value = other_matrix.value;
    return *this;
}

template <typename T, T default_value>
Matrix<T, 0, default_value>& Matrix<T, 0, default_value>::operator=(const T& other_value){
    this->is_default = false;
    this->value = other_value;
    return *this;
}

template <typename T, T default_value>
Matrix<T, 0, default_value>::operator T(){
    return value;
}

template <typename T, T default_value>
size_t Matrix<T, 0, default_value>::size(){
    if(is_default) return 0;
    return 1;
}





