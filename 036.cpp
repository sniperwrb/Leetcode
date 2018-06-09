class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[9][9];
        int b[9];
        int i,j,k,l,m;
        bool f;
        f=true;
        for (i=0;i<9;i++)
        {
            for (j=0;j<9;j++)
            {
                a[i][j]=board[i][j]-48;
            }
        }
        for (i=0;i<9;i++)
        {
            for (j=0;j<9;j++)
            {
                b[j]=0;
            }
            for (j=0;j<9;j++)
            {
                if ((a[i][j]>=1)&&(a[i][j]<=9))
                {
                    b[a[i][j]-1]++;
                }
            }
            for (j=0;j<9;j++)
            {
                if (b[j]>1)
                {
                    f=false;
                }
            }
        }
        for (i=0;i<9;i++)
        {
            for (j=0;j<9;j++)
            {
                b[j]=0;
            }
            for (j=0;j<9;j++)
            {
                if ((a[j][i]>=1)&&(a[j][i]<=9))
                {
                    b[a[j][i]-1]++;
                }
            }
            for (j=0;j<9;j++)
            {
                if (b[j]>1)
                {
                    f=false;
                }
            }
        }
        for (i=0;i<9;i+=3)
        {
            for (j=0;j<9;j+=3)
            {
                for (k=0;k<9;k++)
                {
                    b[k]=0;
                }
                for (k=0;k<3;k++)
                {
                    for (l=0;l<3;l++)
                    {
                        if ((a[i+k][j+l]>=1)&&(a[i+k][j+l]<=9))
                        {
                            b[a[i+k][j+l]-1]++;
                        }
                    }
                }
                for (k=0;k<9;k++)
                {
                    if (b[k]>1)
                    {
                        f=false;
                    }
                }
            }
        }
        return f;
    }
};