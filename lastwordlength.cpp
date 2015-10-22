#include<string>
#include<iostream>    
	int lengthOfLastWord(string s) {
        int len = s.length();
        if (len==0)
          return 0;
        if (len == 1 && s[0] ==' ')
           return 0;
        if (len == 1 && s[0]!=' ')
           return 1;
        
        int i=0;
        int j=0;
        string sub_str;
        while(s[j]==' ' && j<len)
        {
            j++;
        }
        if (j == len)
          return 0;
        i = j;
        sub_str = s.substr(i, len-i); 
        len = sub_str.length();
        i = 0;
        while(len>0)
        {
           std::size_t found = sub_str.find(' ');
           j = found;
           if(found!= std::string::npos)
           {
               while (sub_str[j]==' ' && j<len)
                    j++;
               if (j == len)
                  return found-i;
               else
               {
                   i = j;
               }
           }
           else
           {
               return len;
           }
           
           sub_str = sub_str.substr(i, len-i); 
           std::cout<<"sub_str........"<< sub_str <<"\n";
           len = sub_str.length();
           i = 0;
           
        }
	}
	
	int main()
	{
	 string s = "This is a nice day"; 
	 std::cout<< lengthOfLastWord(s);
	}