class MyCalendarTwo {
    private: 
        map<int,int> umap;
    public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        umap[start]++;
        umap[end]--;
        int sum=0;
        for(auto itr: umap)
        {
            sum+=itr.second;
            if(sum>=3)
            {
                umap[start]--;
                 umap[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */