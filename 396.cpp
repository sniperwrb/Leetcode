class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int l,i,s,m,v;
        l=A.size();
        m=0;
        s=0;
        for (i=0;i<l;i++)
        {
            s=s+A[i];
            m=m+i*A[i];
        }
        v=m;
        for (i=l-1;i>=0;i--)
        {
            v=v-l*A[i]+s;
            if (v>m)
            {
                m=v;
            }
        }
        return m;
    }
};