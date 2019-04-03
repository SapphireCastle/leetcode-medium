class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if (tree.size() == 0) {
            return 0;
        }
        
        int idx1, frts1, idx2, frts2, maxFrts, i;
        idx1 = frts1 = idx2 = frts2 = i = maxFrts = 0;

        while (i < tree.size()) {
            if (tree[i] == tree[idx1]) {
                frts1 ++;
                if (i - 1 > 0 && tree[i] != tree[i - 1]) {
                    idx1 = i;
                }
            } else if (tree[i] == tree[idx2]) {
                frts2 ++;
                if (i - 1 > 0 && tree[i] != tree[i - 1]) {
                    idx2 = i;
                }
            } else {
                if (maxFrts < frts1 + frts2) {
                    maxFrts = frts1 + frts2;
                }

                if (idx1 < idx2) {
                    frts1 = 1;
                    frts2 = i - idx2;
                    idx1 = i;
                } else if (idx1 > idx2){
                    frts1 = i - idx1;
                    frts2 = 1;
                    idx2 = i;
                } else {
                    idx2 = i;
                    frts2 = 1;
                }
            }
            i ++;
        }

        if (maxFrts < frts1 + frts2) {
            maxFrts = frts1 + frts2;
        }
        
        return maxFrts;
    }
};