#ifndef _HEADER_H
#define _HEADER_H

#define MAX 5

class student {
    public:
        static int test;
        static int Ftest();
        //default constructor
        student();
        //constructor with parameters
        student(int number);
        //copy constructor
    public:
        student(const student& stu);
        //assign constructor
        student& operator = (const student& stu);
        //overload operator +
        student operator + (const student& stu);
        //overload operator +=
        student& operator += (const student& stu);
        //get m_number
        int getNumber()
        {
            return m_number;
        }
        //get m_value
        int getValue()
        {
            return m_value;
        }
    public: 
        ~student();
    protected:
        int m_number;
        int m_value;


};

#endif /*_HEADER_H*/
