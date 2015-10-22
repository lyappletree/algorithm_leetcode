#include <iostream>
#include <stddef.h>

void findSum(int a[], int length, int sum,int& start, int& end){

int expected_sum = 0;

while (end<length)
{
  for(int i=start; i<=end; i++)
    expected_sum = expected_sum + a[i];
  if(expected_sum == sum)
    break;
  if(expected_sum < sum)
    end++;
  if(expected_sum > sum)
    start++;
  expected_sum = 0;
}

}

int main(int argc, char** argv) {

int start = 0;
int end = 1;

int a[11] = {14, 21, 24, 25, 28, 31, 32, 36, 39, 41, 47};
findSum(a, 11, 77, start, end);

std::cout<<"start:"<< start<<" end:"<<end;

}