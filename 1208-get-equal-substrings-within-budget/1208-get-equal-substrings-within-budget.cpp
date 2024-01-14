class Solution {
public:
    int equalSubstring(string s, string t, int maxc) {
       int sum=0,i=0,j=0,ans=0;
        while(j<s.size())
        {
            int a = s[j]-'a';
            int b = t[j]-'a';
           sum+=  abs(a-b);
           if(sum<=maxc)
           {
               j++;
               ans = max(ans,(j-i));
           }
            else if(maxc<sum)
            {
                while(maxc<sum)
                {
                    int x  = s[i]-'a';
                    int y = t[i]-'a';
                    sum-=abs(x-y);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};