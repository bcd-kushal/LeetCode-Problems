#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<bool,vector<pair<int,int>>> adjacentCellsHasTargetElement(vector<vector<char>> &board, char target, int i, int j, int m, int n) {
        bool doesExist = false;
        vector<pair<int,int>> coords;
        
        // top ---------------------------------\
        if(i-1>0 && j-1>0 && board[i-1][j-1]==target){
            doesExist |= true;
            coords.push_back(new_pair(i-1,j-1));
        }
        if(i-1>0 && board[i-1][j]==target){
            doesExist |= true;
            coords.push_back(new_pair(i-1,j));
        }
        if(i-1>0 && j+1<m && board[i-1][j+1]==target){
            doesExist |= true;
            coords.push_back(new_pair(i-1,j+1));
        }
        
        // side ways ---------------------------------\
        if(j+1<m && board[i][j+1]==target){
            doesExist |= true;
            coords.push_back(new_pair(i,j+1));
        }
        if(j-1>0 && board[i][j-1]==target){
            doesExist |= true;
            coords.push_back(new_pair(i,j-1));
        }
        
        
        // bottom ---------------------------------\
        if(i+1<n && j-1>0 && board[i+1][j-1]==target){
            doesExist |= true;
            coords.push_back(new_pair(i+1,j-1));
        }
        if(i+1<n && board[i+1][j]==target){
            doesExist |= true;
            coords.push_back(new_pair(i+1,j));
        }
        if(i+1<n && j+1<m && board[i+1][j+1]==target){
            doesExist |= true;
            coords.push_back(new_pair(i+1,j+1));
        }
        
        
        
        return new_pair(doesExist,coords);
    }
    
    bool wordFound(pair<int,int> coord, int word_index, int word_size, vector<vector<char>> &board, string word, int rows, int cols) {
        
        pair<bool,vector<pair<int,int>>> x;
        
        while(word_index < word_size) {
            x = adjacentCellsHasTargetElement(board, word[word_index], coord.first, coord.second, rows, cols);
            
            // if no adjacent have target that means no path is there...
            if(!x.first)
                return false
            else {
                vector<pair<int,int>> authentic_coords = x.second;
                
            }    
            
                
            
        }
        
        
        
        
        
    }
public:
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        // initialization -----------
        int rows = sizeof(board)/sizeof(board[0]);
        int cols = sizeof(board[0])/sizeof(board[0][0]);
        
        int word_size = word.size();
        pair<int,int> curr_coord = new_pair(0,0);
        char curr_char_index = 0;
        
        
        
        //find the first position where search will start --------
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[curr_char_index]) {
                    curr_coord = new_pair(i,j);
                    
                    // if search word is a single letter...
                    if(word_size==1)    return true;

                    // call the helper function whenever the char is found...
                    if(wordFound(curr_coord, curr_char_index+1, word_size, board, word, rows, cols))
                        return true;
                }
            }
        }
        
        return false;
        
    }
};
