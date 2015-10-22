#include <stdio.h>
#include <iostream>

void swap (int v[], int i, int j) {
       int t;
	   if (v[i]!= v[j])
	     {
		    t = v[i];
			v[i] = v[j];
			v[j] = t;			
		 }
}

void perm (int v[], int n, int i) {

  int j;
  if (i == n)
  {
     for (j=0; j<n; j++) printf("%d", v[j]);
	 printf ("\n");
  }else
     for(j=i; j<n; j++)
	    {
		  // std::cout<<"i..."<<i<<"...j..."<<j<<"\n";
		  swap(v, i, j);
		  perm(v, n, i+1);
		  swap(v, i, j);
		}
}

int main(){
   int v[4] = {1, 3, 4, 2};
   perm(v, 4, 0);
   exit(0);
}