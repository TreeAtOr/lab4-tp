#include "queue.h"
#include "set.h"
#include <cstdlib>
#include <iostream>

template <typename T> int maxDiff(T *array, int size) {
  if (size <= 0)
    throw std::runtime_error("Array size must be positive");
  T min = array[0], max = array[0];

  for (int i = 0; i < size; i++) {
    if (array[i] < min)
      min = array[i];
    if (array[i] > max)
      max = array[i];
  }

  return max - min;
}

void task1() {
  int type = 0;
  std::cout << "1 - int" << std::endl
            << "2 - float" << std::endl
            << "3 - double" << std::endl
            << "4 - char" << std::endl;
  std::cin >> type;

  void *arr;

  int size = rand() % 50 + 50;
  switch (type) {
  case 1:
    arr = new int[size];
    for (int i = 0; i < size; i++) {
      ((int *)arr)[i] = rand() % 100;
      std::cout << ((int *)arr)[i] << " ";
    }
    std::cout << std::endl << maxDiff((int *)arr, size) << std::endl;
    break;
  case 2:
    arr = new float[size];
    for (int i = 0; i < size; i++) {
      ((float *)arr)[i] = rand() % 100;
      std::cout << ((float *)arr)[i] << " ";
    }
    std::cout << std::endl << maxDiff((float *)arr, size) << std::endl;
    break;
  case 3:
    arr = new double[size];
    for (int i = 0; i < size; i++) {
      ((double *)arr)[i] = rand() % 100;
      std::cout << ((double *)arr)[i] << " ";
    }
    std::cout << std::endl << maxDiff((double *)arr, size) << std::endl;
    break;
  case 4:
    arr = new char[size];
    for (int i = 0; i < size; i++) {
      ((char *)arr)[i] = rand() % 100;
      std::cout << ((char *)arr)[i] << " ";
    }
    std::cout << std::endl << maxDiff((char *)arr, size) << std::endl;
    break;
  default:
    std::cout << "Enter valid number" << std::endl;
  }
}

template <typename T>  void task2() {
  int type = 0;
  std::cout << "1 - create set" << std::endl
            << "2 - add to set" << std::endl
            << "3 - sum sets" << std::endl
            << "4 - clone sets" << std::endl
            << "5 - cross sets" << std::endl
            << "6 - print set" << std::endl;
  Set<T> *prev = NULL;
  Set<T> *cur = NULL;
  Set<T> *tmp = NULL;
  while (true) {
    std::cout << "> ";
    std::cin >> type;
    if (type == 1) {
      if (cur == NULL) {
        cur = new Set<T>();
      } else {
        prev = cur;
        cur = new Set<T>();
      }
    }
    if (type == 2) {
      if (!cur)
        cur = new Set<T>();
      T in = 0;
      std::cin >> in;
      cur->add(in);
    }
    if (type == 3) {
      if (cur && prev) {
        if (cur->size() > 0 && prev->size() > 0) {
          Set<T> res = *cur + *prev;
          tmp = new Set<T>(res.clone());
          prev = cur;
          cur = tmp;
        }
        if (cur->size() <= 0 && prev->size() > 0) {
          Set<T> *swp = prev;
          prev = cur;
          cur = swp;
        }
      }
    }
    if (type == 4) {
      if (cur) {
        tmp = new Set<T>(cur->clone());
        prev = tmp;
      }
    }
    if (type == 5) {
      if (cur && prev) {
        if (cur->size() > 0 && prev->size() > 0) {
          Set<T> res = *cur * *prev;
          tmp = new Set<T>(res.clone());
          prev = cur;
          cur = tmp;
          continue;
        }
        prev = cur;
        cur = new Set<T>();
      }
    }
    if (type == 6) {
      if (cur) {
        std::cout << "Result:" << std::endl;
        cur->show();
      }
    }
  }
}



void task2() {
  int type = 0;
  std::cout << "1 - int" << std::endl
            << "2 - float" << std::endl
            << "3 - double" << std::endl
            << "4 - char" << std::endl;
  std::cin >> type;
  switch (type) {
  case 1:
    task2<int>();
  case 2:
    task2<float>();
  case 3:
    task2<double>();
  case 4:
    task2<char>();
  }
}

int main(int argc, char *argv[]) {
  std::cout << argv[1] << std::endl;
  if (argc > 1) {
    if (argv[1][0] == '1')
      task1();
    if (argv[1][0] == '2')
      task2();
    return 0;
  }
  task2();
}