#include <string>
#include <map>
#include <iostream>
#include <vector>

int getMin(map<char,int> m){
       map<char,int>::iterator it;
       int min=200000;
       for(it=m.begin(); it!=m.end(); it++)
         if (min>it->second)
            min = it->second;
       return min;
}

void printMap(map<char, int> mymap)
{
  std::cout<<"print map.....\n";
  map<char, int>::iterator it;
  for(it=mymap.begin(); it!=mymap.end(); it++)
     std::cout<< it->first<<"..."<<it->second;
  std::cout<<"\n";
}

string findMinWin(string s, string t)
{

        int lenS = s.length();
        int lenT = t.length();
        
        if(lenS==0 || lenT==0 || lenS<lenT)
          return "";
          
        int exist[lenS];
          
        int found =0;
        map<char, int> mymap;
        map<char, int>::iterator it;
        int left =0;
        int right = 0;
        int min;
        int winSize = lenS+1;
        for(int i=0; i<lenT; i++)
          mymap[t[i]] +=1 ;
       printMap(mymap); 
        int j=0;  
        for(; j<lenS; j++)
          {
            if(found!=lenT)
            {
             it = mymap.find(s[j]);
             if(it->second>0&& it!=mymap.end())
             {
                it->second--;
                found++;
                exist[j] = 1;
             }
            }
            else
              break;
          }
        min = 0;
        winSize = j;
        std::cout<<j<<"\n";
        while(j<lenS&& found==lenT)
        {
            it = mymap.find(s[j]);
            // std::cout<<j<<"...."<<s[j]<<"\n";
			// std::cout<<"ying LIu..." << (it!=mymap.end())<<"....\n";
            if(it!=mymap.end())
             {  // std::cout<<"Ying Liu3\n";
                 right = j;
                 exist[j]=1;
                 
                 bool flag = false;
                 // for(;left<=right; left++)
                 // {
                     if(s[left]==s[j] && flag == false)
                      {
                        left++;
                        flag = true;
                      }
                     if(flag==true)
                      {
                        while(exist[left]==0||s[left]==s[j])
                          left++;
                        
                      }
                 //}
			   std::cout<<"left...."<<left<<"...right..."<<right<<"\n";
               int tmp = right-left+1;
               if(winSize>tmp)
               {
                 min = left;
                 winSize = tmp;
               }
             }
         j++;   
        }
      return s.substr(min, winSize);
    

}

int main()
{
   // string str = "ADOBECODEBANC";
   // string T = "ABC";
   string str = "a";
   string T = "b";
   
   string mm = findMinWin(str, T);
   std::cout<<mm;

}