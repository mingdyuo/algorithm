


class Solution {
    
public:
    
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> pos;
        for(int i=0;i<order.length();i++){
            pos[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++){
            int minSize = min(words[i].length(), words[i+1].length());
            
            int j = 0;
            for(j=0;j<minSize;j++){
                if(pos[words[i][j]] < pos[words[i+1][j]]) break;
                else if(pos[words[i][j]] > pos[words[i+1][j]]) return false;
            }
            
            if(j==minSize && words[i].length() > words[i+1].length()) return false;
                            
        }
        return true;
        
    }
};
    