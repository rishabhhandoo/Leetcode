class MyCalendarThree {
    private:
    map<int,int> umap;
    int maxx=0;
    public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        umap[start]++;
        umap[end]--;
        
        int sum=0;
        for(auto itr:umap)
        {
            sum+=itr.second;
            maxx=max(sum,maxx);
        }
        return maxx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */