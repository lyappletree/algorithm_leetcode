#include<iostream>
#include<string>
#include<map>

bool isIsomorphic(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();
        
        if (lenS!= lenT)
          return false;
          
        string str = "";
        int tmp_map2[256];
        for(int i=0; i<256; i++)
          tmp_map2[i] = 0;
          
        map<char, char> mymap;
        map<char, char>::iterator it;
        for (int i=0; i< lenT; i++)
        {  std::cout<<"Ying Liu.......3........\n";
            it = mymap.find(s[i]);
            if (it== mymap.end())
            {  std::cout<<"Ying Liu.......2........"<<tmp_map2[t[i]]<<"\n";
               if (tmp_map2[t[i]]==0)
               {
                  mymap[s[i]] = t[i];
                  str+=t[i];
                  tmp_map2[t[i]]=1;
                  std::cout<<"Ying Liu.......1........\n";
               }
               else
                 return false;
            }
            else
              str+=it->second;
        }
        std::cout<<"ying Liu......"<< str<<"\n";
        if (t==str)
          return true;
        else
          return false;
        
    }

	int main()
	{
	  string s = "ab";
	  string t = "aa";
	  
	  std::cout<<isIsomorphic(s, t)<<"\n";
	}