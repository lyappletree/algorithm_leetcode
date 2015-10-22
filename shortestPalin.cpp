#include <iostream>
#include <string>
    bool isPalindrome(string s)
    {
        int len = s.length();
        
        if (len == 0)
          return true;
        
        if (len == 1)
          return true;
          
        int i = 0;
        int j = len - 1;
        
        while(s[i] == s[j] && i<=j)
        {
            i++;
            j--;
        }
        
        if (i<=j)
          return false;
        else
          return true;
    }

    string shortestPalindrome(string s) {
        
        
        int len = s.length();
        std::cout<<"len......." << len <<"\n";
        string results =s;
        int index[] = {-1, -1};
        if (len == 0)
          return "";
          
        if (len == 1)
          return results+s;
          
        int left = 0;
        int right = len-1;
        
        while (s[0] != s[right] && right>=0)
        {
            right--;
        }
        
        // string s_sub = s.substr(0, right+1);
        // std::cout<<"s_sub........." << s_sub <<"\n";
        while(!isPalindrome(s.substr(0, right+1)) && right>0)
        {
            right--;
        }
        std::cout<<"right......." << right<<"\n";
        
        if (right==0)
        {
           for(int i =1; i<len; i++) 
             results=s[i]+results;
        }
        if (right>0)
        {
		   std::cout<<"s........" << s <<"\n";
           for(int i= right+1; i<len; i++)
		   {
		     
             results =s[i] + results;
			 std::cout<<"results........" << results <<"\n";
		   }
			
        }
        return results;
    }
	
	 string shortestPalindrome2(string s) {
        
        
        int len = s.length();
        string results =s;
        int index[] = {-1, -1};
        int lt = -1;
        if (len == 0)
          return "";
          
        if (len == 1)
          return results;
          
        int left = 0;
        int right = len-1;
        
        int mid = left + (right - left)/2;
        
        bool flag = false;
        std::cout<<"mid......."<< mid <<"\n";
        
        for (int i = 0; i<=mid; i++)
        {
            // even
            int len2 = i+1;
            int len3 = i;
            
            if (s.substr(0,len3)== s.substr(i+1,len3))
               right = i+len3;
               
            if (s.substr(0, len2) == s.substr(i+1, len2))
            {
                std::cout<<"Ying Liu...........1.....\n";
               right = i+len2;
            }
               
            std::cout<<"s.substr(0,len3)....."<< s.substr(0,len3)<<"...s.substr(i+1,len3)....."<< s.substr(i+1,len3)<<"\n";
            std::cout<<"s.substr(0, len2)....."<<s.substr(0, len2)<<"...s.substr(i+1, len2)...."<<s.substr(i+1, len2)<<"\n";
               
        
        }
        std::cout<<"right........."<< right<<"\n";
        
        
        if (right == left)
        {
           for(int i =left+1; i<len; i++) 
             results=s[i]+results;
        }
        if (right>left)
        {
           for(int i= right+1; i<len; i++)
             results=s[i]+results;
        }
        return results;
    }
	
	int main()
	{
	   string s = "abbacd";
	   std::cout<< shortestPalindrome2(s) <<"\n";
	   return -1;
	}
	
