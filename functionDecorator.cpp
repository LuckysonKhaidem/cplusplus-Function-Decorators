// This examples shows you how to implement function decorators in c++ using lambda expressions

#include <iostream>
#include <vector>
#include <functional>


std::function<int (std::vector<int>&)> sumFunctionWrapper(int (*mapFunction)(int)) {
  auto decoratedSumFunction = [&mapFunction](std::vector<int>& v) {
      int accumulator = 0;
      for(int i = 0; i < v.size() ; i ++ )
        accumulator += mapFunction(v[i]);
      return accumulator;
  };
  return decoratedSumFunction;
}


int main(void) {

  std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

  int sum = sumFunctionWrapper([](int x){return x;})(v);
  int sumOfSquares = sumFunctionWrapper([](int x) { return x*x;})(v);
  int sumOfCubes = sumFunctionWrapper([](int x) {return x*x*x;})(v);

  std::cout << "The sum is " << sum << std::endl;
  std::cout << "Sum of squares is " << sumOfSquares << std::endl;
  std::cout << "Sum of cubes is "<< sumOfCubes << std::endl;


  return 0;
}
