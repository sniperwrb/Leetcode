class Solution {
public:
    string getHint(string secret, string guess) {
        int s[10];
        int g[10];
        int i,l,a,b;
        for (i=0;i<10;i++)
        {
            s[i]=0;
            g[i]=0;
        }
        l=secret.length();
        a=0;
        for (i=0;i<l;i++)
        {
            s[secret[i]-48]++;
            g[guess[i]-48]++;
            if (secret[i]==guess[i])
            {
                a++;
            }
        }
        b=0;
        for (i=0;i<10;i++)
        {
            if (s[i]<g[i])
            {
                b=b+s[i];
            }
            else
            {
                b=b+g[i];
            }
        }
        b=b-a;
        string c;
        c=to_string(a)+"A"+to_string(b)+"B";
        return c;
    }
};