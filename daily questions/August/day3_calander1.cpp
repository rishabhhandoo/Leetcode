class MyCalendar {
public:
    unordered_map<int,int> umap;
    bool book(int s1, int e1) {
         for(auto itr : umap)
         {
            if( !(itr.second <= s1 || itr.first >= e1))   return false;
         }
             umap[s1] = e1;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */