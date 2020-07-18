class Solution {
public:
    void reverseString(vector<char>& s) {
        int sizeS = s.size();
        for ( int i = 0; i < sizeS / 2; i++ ) {
            int temp = s[i];
            s[i] = s[sizeS - 1 - i];
            s[sizeS - 1 - i] = temp;
        }
    }
};
