class Solution {
public:
    bool noOneFront(int& num) {
        num++;
        return (num == 10 ? num = 0 : 1);
    }
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1;i >= 0;i--) {
            if (noOneFront(digits[i])) break;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};

