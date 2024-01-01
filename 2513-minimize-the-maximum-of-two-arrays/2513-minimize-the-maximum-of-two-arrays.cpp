class Solution {
public:
    constexpr long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    
    void bs(long l, long h, int divisor1, int divisor2, long lcm, long& ans, int c1, int c2) {
        while (l <= h) {
            long mid = l + (h - l) / 2;
            long a = mid - (mid / divisor1);
            long b = mid - (mid / divisor2);
            long c = mid - (mid / divisor1) - (mid / divisor2) + (mid / lcm);
            
            if (a >= c1 && b >= c2 && a + b - c >= c1 + c2) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long g = gcd(max(divisor1, divisor2), min(divisor1, divisor2));
        long lcm = (long(divisor1) * long(divisor2)) / g;
        
        long ans = 1000000000;
        bs(2, 10000000000, divisor1, divisor2, lcm, ans, uniqueCnt1, uniqueCnt2);
        
        return static_cast<int>(ans);
    }
};
