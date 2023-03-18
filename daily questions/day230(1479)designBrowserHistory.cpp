// class BrowserHistory {
// public:
//     vector<string> history;
//     int cur_idx;

//     BrowserHistory(string homepage) {
//         history.push_back(homepage);
//         cur_idx = 0;
//     }
    
//     void visit(string url) {
//         history.resize(cur_idx + 1); // Clear forward history as we can't go forward
//         history.push_back(url);
//         cur_idx++;
//     }
    
//     string back(int steps) {
//         int prev_idx = max(0, cur_idx - steps);
//         cur_idx = prev_idx;
//         return history[cur_idx];
//     }
    
//     string forward(int steps) {
//         int next_idx = min((int)history.size() - 1, cur_idx + steps);
//         cur_idx = next_idx;
//         return history[cur_idx];
//     }
// };
class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;
	
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>(); // Reset as can't go forward now
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>(); // Reset as can't go forward now
    }
    
    string back(int steps) {
        while(steps > 0 && history.size() > 1) { // As we can only move x steps & stesp>x then we return only x steps
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && future.size() > 0) {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};