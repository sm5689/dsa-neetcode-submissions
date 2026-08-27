class Solution {
public:
    int digSqSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = digSqSum(n);
        while (fast != 1 && slow != fast) {
            slow = digSqSum(slow);
            fast = digSqSum(digSqSum(fast));
        }
        return fast == 1;
    }
};
