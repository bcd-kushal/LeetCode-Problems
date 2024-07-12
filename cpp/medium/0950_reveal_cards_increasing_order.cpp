#include <bits/stdc++.h>
using namespace std;

class Cards {
    private:
        vector<int> helper(vector<int> &arr, bool take_out) {
            stack<int> st;
            vector<int> resultant, aux;

            for(int i=arr.size()-1; i>=0; i--)
                st.push(arr[i]);

            while(!st.empty()) {
                if(take_out){        
                    resultant.push_back(st.top()); 
                    cout << "\nR -> " << st.top();
                }
                else    
                    aux.push_back(st.top()); 

                take_out = !take_out;
                st.pop();

                if(st.empty() && aux.size()>0) {    
                    cout << "\nYES" ;
                    for(int i=aux.size()-1; i>=0; i--)
                        st.push(aux[i]);
                    aux.clear();
                }
            }
            
            cout << "\nstack empty: " << st.empty() << endl;

            for(int i=aux.size()-1; i>=0; i--)
                cout << aux[i] << ",";

            return resultant;
        }

        bool increasingOrder(int a, int b) { return a < b; }

    public:
        vector<int> deckRevealedIncreasing(vector<int>& deck) {
            sort(deck.begin(),deck.end());
            for(const int i: deck)
                cout << i << ", ";
            return helper(deck, true);
        }
};

int main() {
    vector<int> deck = {17,13,11,2,3,5,7};
    Cards cards;

    auto start = chrono::steady_clock::now();
    auto ans = cards.deckRevealedIncreasing(deck);
    auto end = chrono::steady_clock::now();

    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}
