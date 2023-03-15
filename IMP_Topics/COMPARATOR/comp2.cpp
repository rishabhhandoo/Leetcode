int findMinimumTime(vector<vector<int>>& tasks) {
    int res = 0;
    // Determines whether work has been done before 
    int range[2001] = {0};
    // Sort by interval end time 
    sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){return a[1] < b[1];});

//Input: tasks = [[2,3,1],[4,5,1],[1,5,2]]
// Output: 2
// Explanation: 
// - The first task can be run in the inclusive time range [2, 2].
// - The second task can be run in the inclusive time range [5, 5].
// - The third task can be run in the two inclusive time ranges [2, 2] and [5, 5].
// The computer will be on for a total of 2 seconds.