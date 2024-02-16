class Solution {
public:
    string updateBoard(string board) {
        bool iterate = true;
        vector<string> matches = {"BBB", "YYY", "GGG", "RRR", "WWW"};
        while(board.size() > 0 && iterate == true) {
            iterate = false;
            for (auto match: matches) {
                std::size_t found = board.find(match);
                int len = 3;
                if (found != std::string::npos) {
                    char c = match[0];
                    for (int i = found+3; i < board.size(); i++) {
                        if (board[i] == c) {
                            len++;
                        } else {
                            break;
                        }
                    }
                    board = board.substr(0, found) + board.substr(found+len);
                    iterate = true;
                }
            }
        }       
        return board;
    }
    int findMinStep(string board, string hand) {
        unordered_set<string> visited;
        int steps = 0;
        sort(hand.begin(), hand.end());      
        queue<string> q;
        q.push(board + "#" + hand);      
        while(q.size() > 0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string cur = q.front();
                q.pop();           
                string curboard = cur.substr(0, cur.find("#"));
                string curhand = cur.substr(cur.find("#") + 1);
                for (int j = 0; j < curboard.size(); j++) {
                    for (int k = 0; k < curhand.size(); k++) {
                        if (k > 0 && curhand[k] == curhand[k-1]) continue;
                        bool worthTrying = false;
                        if(curboard[j] == curhand[k]) worthTrying = true;
                        if(j > 0 && curboard[j] == curboard[j - 1] && curboard[j] != curhand[k])
                            worthTrying = true;
                    
                        if (worthTrying) {
                            string newboard = curboard.substr(0, j) +
                                curhand[k] + curboard.substr(j);
                            string newhand = curhand.substr(0, k) + curhand.substr(k+1);
                            
                            newboard = updateBoard(newboard);
                            if (newboard == "") return steps + 1;
                            
                            string explore = newboard+"#"+newhand;
                            if (visited.find(explore) == visited.end()){
                                visited.insert(explore);
                                q.push(explore);
                            }
                        }
                    }
                }
            
            }
            steps++;
        }
        
        return -1;
    }
};