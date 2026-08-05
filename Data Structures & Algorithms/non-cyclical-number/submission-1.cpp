class Solution {
public:
    int sum_of_digs(int n)
    {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        while(sum_of_digs(n) != 1)
        {
            int x = sum_of_digs(n);
            if(s.contains(x))return false;
            s.insert(x);
            n = x;
        }
        return true;
    }
};
