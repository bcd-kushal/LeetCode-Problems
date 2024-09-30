#include <string>
using namespace std;

class Solution {
string ones(int n) {
    switch(n) {
        case 0: return "";
        case 1: return "One ";
        case 2: return "Two ";
        case 3: return "Three ";
        case 4: return "Four ";
        case 5: return "Five ";
        case 6: return "Six ";
        case 7: return "Seven ";
        case 8: return "Eight ";
        case 9: return "Nine ";
    }
    return "";
}

string tens(int n) {
    switch(n) {
        case 0: return "";
        case 1: return "";
        case 2: return "Twenty ";
        case 3: return "Thirty ";
        case 4: return "Forty ";
        case 5: return "Fifty ";
        case 6: return "Sixty ";
        case 7: return "Seventy ";
        case 8: return "Eighty ";
        case 9: return "Ninety ";
    }
    return "";
}

string tensWithOne(int n) {
    switch(n) {
        case 10: return "Ten ";
        case 11: return "Eleven ";
        case 12: return "Twelve ";
        case 13: return "Thirteen ";
        case 14: return "Fourteen ";
        case 15: return "Fifteen ";
        case 16: return "Sixteen ";
        case 17: return "Seventeen ";
        case 18: return "Eighteen ";
        case 19: return "Nineteen ";
    }
    return "";
}

string getNumberName(int num) {
    if(num==0)
        return "";

    string name = "";
    int level = 0, dup = num%10;
    while(num>0) {
        if(level==0)
            name = ones(num%10);
        else if(level==1)
            if(num%10==1)   name = tensWithOne(10+dup);
            else            name = tens(num%10) + name;
        else if(level==2)
            name = ones(num%10) + "Hundred " + name;
        
        level += 1;
        num /= 10;
    }

    return name;
}

public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";

        vector<string> levels = {"","Thousand ","Million ","Billion "};
        string wordNum = "", word;
        int level = 0;
        while(num>0) {
            word = getNumberName(num%1000);
            num /= 1000;
            if(word.size() > 0)
                wordNum = word + levels[level] + wordNum;
            level += 1;
        }

        return wordNum.substr(0,wordNum.size()-1);
    }
};