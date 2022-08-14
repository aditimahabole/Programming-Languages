/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList,
return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

*/

//IN GRAPH WE USE BFS BECAUSE IF WE USE DFS WE WILL HAVE MANY PATHS,BUT IN TREES WE HAVE UNIQUE PATH SO ITS BETTER TO USE DFS IN TREES THAN GRAPH

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        
      unordered_set<string> s;
      bool is_present=false; //checks if endword is present or not
      for(auto word:wordList)
      {
        if(endWord.compare(word)==0)
        {
          is_present=true;
        }
        s.insert(word);
      }
      
      if(is_present==false)
      {
        return 0;
      }
      //aplly bfs uusing queue this problem is a graph problem
      // source to destination type Q
      
      queue<string>q;
      q.push(beginWord);
      int depth=0;
      
      
      while(!q.empty())
      {
        depth+=1;
        int d_size=q.size();// no. of elements at that level
        
        while(d_size--)
        {
          string curr=q.front();
          q.pop();
          //check for all possible 1 depth words
          
          for(int i=0;i<curr.size();i++)// h i t
          {
            string temp=curr;
            for(char c='a';c<='z'; ++c)
            {
              temp[i]=c;
              
             
              if(curr.compare(temp)==0)
              {
                // temp = hit now making combinations ait bit cit dit----hit 
                //as we got h continue we neend not to tranform again to hit 
                continue;//skip the same word
              }
              if(temp.compare(endWord)==0)
              {
                return depth+1;//found end word
              }
              
              if(s.find(temp)!=s.end())//if temp is present in that set
              {
                q.push(temp);
                s.erase(temp);
                // and we check if word is present in set if yes 
                //then push to queue and erase from that set as we cannot use that word again
              }
            }
          }
        }
      }
      return 0;
    }
