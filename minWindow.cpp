    #include <iostream>
	#include <vector>
	#include <string>
	#include <queue>
	
	string minWindow(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();
        
        if(lenS==0 || lenT==0 || lenS<lenT)
          return "";
        vector<int> mapT(128,0);
        vector<int> isMapT(128, false);
        queue<pair<char, int> > myqueue;
        
        for(int i=0; i<lenT; i++)
          {
              mapT[t[i]]++;
              isMapT[t[i]] = true;
          }
        int window;
        int min_window = lenS+1;
        int start = -1;
        int min_left = -1;
        int min_right = -1;
        for(int i=0; i<lenS; i++)
          {   
              if (lenT>0)
              {
                  if(isMapT[s[i]]== true)
                  {   // std::cout<<"Ying Liu........1...\n";
                      myqueue.push(make_pair(s[i],i));
                      // std::cout<<"Ying Liu........5...\n";
                      if(mapT[t[i]]>0)
					  {
                        mapT[t[i]]--;
					  }
                        lenT--;
                  }
              }
              else
              {  // std::cout<<"Ying Liu........2...\n";
                 start = myqueue.front().second;
                 // std::cout<<"Ying Liu........3...\n";
				 std::cout<<"i......"<<i<<"\n";
                 window = i - start;
                 if(min_window >= window)
                 {   // std::cout<<"Ying Liu........4...\n";
                     min_window = window;
                     min_left = start;
                     min_right = i;
                 }
                 // deque 
                 char c = myqueue.front().first;
                 myqueue.pop();
                 mapT[c]++;
                 lenT++;
              }
          }
        std::cout<<"Ying Liu........6...\n";  
		std::cout<<"min_left............."<< min_left<<"....min_right....."<< min_right <<"\n";
        if (min_left!=-1 && min_right!=-1)
        {  
           string str = s.substr(min_left, min_window);
           std::cout<<str;
           return str;
        }
        else
           return "";
    }
	
	int main()
	{
	  string s = "adobecodebanc";
	  string t = "abc";
	  std::cout<< minWindow(s,t)<<"\n"; 
	}