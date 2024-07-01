#include <bits/stdc++.h>
using namespace std;

class Meeting {
    private:
        vector<int> commonDuration(vector<int> &a, vector<int> &b) {
            if(a[1] < b[0] || b[1] < a[0])      return {};
            return { max(a[0],b[0]), min(a[1],b[1])};
        }

    public: 
        vector<int> scheduleMeeting(vector<vector<int>> &slot1, vector<vector<int>> &slot2, int &duration) {
            auto ptr1 = slot1.begin();
            auto ptr2 = slot2.begin();

            while(ptr1!=slot1.end() && ptr2!=slot2.end()) {
                vector<int> common_duration = commonDuration(*ptr1,*ptr2);
                if(common_duration.size()) {
                    int range = common_duration[1] - common_duration[0];
                    if(range >= duration)
                        return { common_duration[0], common_duration[0]+duration };
                }

                if((*ptr2)[1] < (*ptr1)[1])
                    ptr2 += 1;
                else if((*ptr1)[1] < (*ptr2)[1])
                    ptr1 += 1;
                else {
                    ptr1 += 1;
                    ptr2 += 1;
                }
            }

            return {};
        }
};

int main() {
    vector<vector<int>> slot1 = {{10,50}, {60,120}, {140,210}};
    vector<vector<int>> slot2 = {{0,15},  {60,70},  {140,210}};
    int duration = 8;
    Meeting meeting;

    auto start = chrono::steady_clock::now();
    vector<int> time = meeting.scheduleMeeting(slot1, slot2, duration);
    auto end = chrono::steady_clock::now();
    for(auto it: time)
        cout << it << "...";
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    
    return 0;
}
