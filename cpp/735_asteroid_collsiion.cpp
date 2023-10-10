vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        //st.push(asteroids[1]);
        
        int i=1;
        while(i<asteroids.size()){
            
            int t=-9999;
            if(!st.empty())
                t=st.top();
            
            
            st.push(asteroids[i]);
            i+=1;
            
            if(t!=-9999)
            while((t<0&&st.top()>0)||(t>0&&st.top()<0)){
                t=st.top();
                st.pop();
                if(!st.empty()){
                    if(abs(st.top())==abs(t))
                        st.pop();
                    else if(abs(st.top())>abs(t)){}
                    else{
                        st.pop();
                        st.push(t);
                    }
                }
                else
                    st.push(t);
                
                if(!st.empty()){
                    t=st.top();
                    st.pop();
                }
                else
                    break;
            }

        }
        
        vector<int> ans={};
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }