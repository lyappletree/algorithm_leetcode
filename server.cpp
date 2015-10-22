#include <iostream>
#include <vector>
#include <stdio.h>

int main()
{
    vector<int> parents;
    FILE* fin = fopen("training.txt", "r");
    int n;
    fscanf(fin, "%d\n", &n);
	std::cout<<"n....."<< n<<"\n";
    // nodes staring from '1'
    parents.resize(n + 1);
    parents[1] = 1;
    
    for (int i = 0; i < n - 1; i++) {
        int parent, child;
        fscanf(fin, "%d,%d\n", &parent, &child);
		std::cout<<"child...."<< child <<"parent..."<< parent<<"\n";
        parents[child] = parent;
    }
    
    fclose(fin);
	
	return 1;
}  