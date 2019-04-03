class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if (tree.size() == 0) {
            return 0;
        }
        
        int result = 0;
        unordered_map<int, int> window;
        int left = 0;
        
        for(int i = 0; i < tree.size(); i ++) {
            window[tree[i]] ++;
            while (window.size() >= 3) {
                window[tree[left]] --;
                if (window[tree[left]] == 0) {
                    window.erase(tree[left]);
                }
                left ++;
            }
            if (result < i + 1 - left) {
                result = i + 1 - left;
            }
        }
        
        return result;
    }
};