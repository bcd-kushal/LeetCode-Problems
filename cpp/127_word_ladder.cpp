/*
A transformation sequence from word beginWord to word endWord using a dictionary
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 - Every adjacent pair of words differs by a single letter.
 - Every si for 1 <= i <= k is in wordList. Note: beginWord may not be in wordList.
 - sk == endWord
 
Given two words, beginWord and endWord, and a dictionary wordList, return
the number of words in the shortest transformation sequence from beginWord to endWord,
or 0 if no such sequence exists.

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

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



class Solution {
public:
    bool diff_of_one(string a, string b, int n){
        int count = 0;
        while(n-1>=0){
            if(a[n]!=b[n]){
                count+=1;
                if(count>=2)
                    return false;
            }
            n-=1;
        }
        return true;
    }




    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        wordList.push_back(endWord);

        int flag = 0;
        int ladderLen = 0;

        //BFS uses 2 queues for its working
        queue<string> used_words;
        queue<string> currQ;
        vector<string> nodesToThis;

        string present_word, next_word;
        present_word = beginWord;

        nodesToThis.push_back("");
        nodesToThis.clear();
        for(auto &word: wordList){
            if(diff_of_one(present_word,word))
                if(word==endWord){
                    flag=1;
                    break;
                }
                else
                    nodesToThis.push_back(word);
        }

        currQ.push(present_word);
        while(!currQ.empty()){

            if(nodesToThis.empty() && flag==0)
                return 0;

            if(flag==1)
                return 1+ladderLen;



            //move present word from currQ to used words
            string x = currQ.pop();
            used_words.push(x);
            //remove present word from wordList

            //push nodes to currQ
            //pop currQ
            //nodes.clear()
            //ladderLen+1
        }

    }
};
