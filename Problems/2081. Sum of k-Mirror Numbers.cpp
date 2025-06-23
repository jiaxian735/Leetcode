class Solution {
public:
    bool base(long long k, int n) {
        if (k < n)
            return 1;
        string q;
        while (k > 0) {
            q.push_back('0' + k % n);
            k /= n;
        }
        for (int i = 0, j = q.size() - 1; i < j; i++, j--) {
            if (q[i] != q[j])
                return 0;
        }
        return 1;
    }
    long long kMirror(int k, int n) {
        long long ans{}, t = 1, l = 9;
        for (int i = 0; i < l; i++) {
            if (base(t + i, k)) {
                ans += t + i;
                n--;
            }
            if (!n)
                return ans;
        }
        for (int i = 0; i < l; i++) {
            if (base((t + i) * 11, k)) {
                ans += (t + i) * 11;
                n--;
            }
            if (!n)
                return ans;
        }
        while (1) {
            t *= 10;
            l *= 10;
            for (int i = 0; i < l; i++) {
                string s = to_string(t + i), v = s;
                v.pop_back();
                reverse(v.begin(), v.end());
                long long a = stoll(s + v);
                if (base(a, k)) {
                    ans += a;
                    n--;
                }
                if (!n)
                    return ans;
            }
            for (int j = 0; j < l; j++) {
                string s = to_string(t + j), v = s;
                reverse(v.begin(), v.end());
                long long a = stoll(s + v);
                if (base(a, k)) {
                    ans += a;
                    n--;
                }
                if (!n)
                    return ans;
            }
        }
    }
};
