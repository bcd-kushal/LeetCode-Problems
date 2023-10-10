bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1 && flowerbed[0]==0)
            return true;
        
        if(flowerbed[0]==0 && flowerbed[1]==0){
            if(n==0)
                return true;
            
            --n;
            flowerbed[0]=1;
        }
        
        if(n==0)
            return true;
        
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0){
            --n;
            flowerbed[flowerbed.size()-1]=1;
        }
        
        if(n==0)
            return true;
        
        //----------------------------------------------------------
        
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                if(n==0)
                    return true;
                
                --n;
                flowerbed[i]=1;
            }
            
            if(n==0)
                return true;
        }
        
        return false;
    }