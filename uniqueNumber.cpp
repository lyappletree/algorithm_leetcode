#include <iostream>

int FindNumberAppearingOnce(int numbers[], int length){
  int bitSum[32];
  for(int i=0; i<32; ++i)
     bitSum[i] = 0;
  for(int i=0; i<length; ++i)
   {
      int bitMask = 1;
	  for(int j=31; j>=0; --j)
	   {
	     int bit = numbers[i]& bitMask;
		 if(bit!=0) bitSum[j]+=1;
		 bitMask = bitMask<<1;
	   }
   }
   
   for(int j=0; j<32; j++)
     std::cout<<bitSum[j]<<"\n";
	 
   int result = 0;
   for(int i=0; i<32; ++i)
    {
	   result = result<<1;
	   result+= bitSum[i]%3;
	}
	return result;
}

int main(int argc, char** argv)
{
   int numbers[7] = {5, 5, 5, 7 , 7, 7, 4};
   std::cout<< FindNumberAppearingOnce(numbers, 7) <<"\n";
}