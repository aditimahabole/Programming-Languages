
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, 
return all the shortest transformation sequences from beginWord to endWord,
or an empty list if no such sequence exists.
Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

*/
vector<vector<string>> res;
    vector<string> te;
    unordered_map<string, int> mp;
    string b;
    void dfs(string s)  // Step 2
    {
        te.push_back(s);
        if (s == b)
        {
            vector<string> x = te;
            reverse(x.begin(), x.end());
            res.push_back(x);
            te.pop_back();
            return;
        }
        int cur = mp[s];
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            for (char cc = 'a'; cc <= 'z'; cc++)
            {
                s[i] = cc;
                if (mp.count(s) && mp[s] == cur - 1)
                    dfs(s);
            }
            s[i] = c;
        }
        te.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        b = beginWord;
        queue<string> q;
        int k = beginWord.size();
        q.push({beginWord});
        mp[beginWord] = 0;
        while (!q.empty())  // Step 1
        {
            int n = q.size();
            while (n--)
            {
                string t = q.front();
                q.pop();
                int x = mp[t] + 1;
                for (int i = 0; i < k; i++)
                {
                    string temp = t;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp[i] = ch;
                        if (!mp.count(temp) && dict.count(temp))
                            mp[temp] = x;
                            q.push(temp);
                    }
                }
            }
        }
        if (mp.count(endWord))
            dfs(endWord);
        return res;
    }
