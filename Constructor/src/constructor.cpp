#include<iostream>
#include"../inc/header.h"

int student::test = 10;

student::student()
{
    int x = 10;
    int y = 10;
    int &r = x;
    int &w = r;

    m_number = 10;
    m_value = 1;
    std::cout << "default constructor is called" << test << std::endl;
}

int student::Ftest()
{
    std::cout << "default constructor is called" << test << std::endl;
}

student::student(const student& stu)
{
    this->m_number = stu.m_number;
    std::cout << "copy constructor is called" << std::endl;
}

student& student::operator = (const student& stu)
{
    this->m_number = stu.m_number;
    std::cout << "assignment constructor is called" << std::endl;
}

student student::operator + (const student& stu)
{
    student st;
    st.m_number = m_number + stu.m_number;
    st.m_value = m_value + stu.m_value;
    std::cout << "overload operator + is called" << std::endl;
    return st;
}

student& student::operator += (const student& stu)
{
    this->m_number += stu.m_number;
    this->m_value += stu.m_value;
    std::cout << "overload operator += is called" << std::endl;
    return *this;
}

student::student(int num)
{
    m_number = num;
    std::cout << "constructor with parameter is called" << std::endl;
}

student::~student()
{
    std::cout << "destructor is called" << std::endl;
}