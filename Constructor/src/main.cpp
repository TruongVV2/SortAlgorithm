#include<iostream>
#include"pthread.h"
#include <mutex>          // std::mutex

#include"../inc/header.h"

#define NUM_THREAD     5

int couter = 0;
pthread_mutex_t mutex1;
std::mutex mtx;           // mutex for critical section

void *PrintGreeting(void *threadid)
{
  //mtx.lock();
  //std::cout << "Hello World! Thread ID is: " << threadid << std::endl;
  //mtx.unlock();
  pthread_exit(NULL);
}

void * funcC(void *data)
{
	
  for (int i = 0; i < 1000; i++) {
    pthread_mutex_lock(&mutex1);
	  couter += 1;
    pthread_mutex_unlock(&mutex1);
  }
  
	//printf("Gia tri couter trong Func:%d\n",couter);
  //std::cout << "value of counter in FuncC: " << couter << std::endl;
	
	return NULL;
}
void * funcC1(void *data)
{
	//pthread_mutex_lock(&mutex1);
	//couter += 200;
	//printf("Gia tri couter trong Func1:%d\n",couter);
  // mtx.lock();
  // std::cout << "value of counter in FunC: " << couter << std::endl;
  // mtx.unlock();
	//pthread_mutex_unlock(&mutex1);
	return NULL;
}

struct apple
{
  float weight;
  int c; 
} apple;

class subStudent: public student
{
  public:
    subStudent(): student(4)
    {
      m_number = 2;
      //std::cout << "default constructor of subStudent is called" << std::endl;
    }
/*     subStudent(int num) :student(num)
    {
       m_number = num;
       std::cout << "constructor parameter of subStudent is called" << std::endl;     
    } */

    ~subStudent()
    {
      //std::cout << "destructor of subStudent is called" << std::endl;
    }

};

// student stu_first;
// student stu_second(1);
// student stu_third(stu_first);
// student stu_fourth = stu_second;
// student stu_fifth;

student func()
{
  student t(10);
  return t;
}

int testMultithreadedWallet() 
{
  pthread_t threads[NUM_THREAD];

  for( int i=0; i < NUM_THREAD; i++ ){
    //std::cout << "main() : Creating thread! " << i << std::endl;
    pthread_create(&threads[i], NULL, funcC, NULL);
    //system("ps -Lf");
  }

   /* Telling the main thread to wait for the task completion of all its spawned threads.*/
  for (int j = 0; j < NUM_THREAD; j++)
  {
    pthread_join (threads[j], NULL);
    //pthread_detach(threads[j]);
  }
  return couter;
}

int main()
{
  // apple.weight = 1.1;
  // apple.c = 2;
  // std::cout << "weight: " << apple.weight << std::endl;
  // std::cout << "number: " << apple.c << std::endl;
  /* stu_fifth = stu_first; */
  /* subStudent subStu(0); */
  // student stu_plus = stu_first + stu_fifth;
  // std::cout << "m_value is: " << stu_second.getValue() << std::endl;
  // std::cout << "m_number is: " << stu_second.getNumber() << std::endl;
  // std::cout << "m_value of stu_plus is: " << stu_plus.getValue() << std::endl;
  // std::cout << "m_number of stu_plus is: " << stu_plus.getNumber() << std::endl;
  // pthread_t thread1, thread2;
	// pthread_create(&thread1,NULL,&funcC,NULL);
	// pthread_create(&thread2,NULL,&funcC1,NULL);
	// pthread_join(thread1,NULL);
	// pthread_join(thread2,NULL);
	// //printf("Gia tri cuoi cung cua counter: %d\n",couter);
  // std::cout << "Final value of counter: " << couter << std::endl;

  testMultithreadedWallet();

  for(int k = 0; k < 1000; k++)
  {
     if(couter != 5000)
     {
        std::cout << "Error at count = "<< k <<" Money in Wallet = "<< couter << std::endl;
     }
  }
  int n = 4;
  int arr[n] = {1, 3, 5, 7};
  for (int i = 0; i < n; i++) {
    std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
  }
  std::cout << "size of array arr: " << sizeof(arr) << std::endl;
  std::cout << "the number of element of array arr: " << sizeof(arr)/sizeof(arr[0]) << std::endl;
  int* ptr = arr;
  std::cout << "size of pointer: " << sizeof(ptr) << std::endl;
  std::cout << "first value of pointer: " << ptr[0] << std::endl;
  std::cout << "size of int: " << sizeof(int) << std::endl;
  std::cout << "address of first element arr: " << &arr[0] << std::endl;
  std::cout << "address of arr: " << &arr << std::endl;
  std::cout << "address of pointer: " << &ptr << std::endl;
  pthread_exit(NULL);
	return 0;

}