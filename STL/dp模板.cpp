//01背包问题
//无优化

for(int i=1;i<=n;i++)
{
    for(int c=0;c<=m;c++)
    {
        f[i][c]=f[i-1][c];
        if(c>=w[i])
        f[i][c]=max(f[i][c],f[i-1][c-w[i]]+v[i]);
    }
}

//一维数组优化

for(int i=1;i<=n;i++)
{
    for(int c=m;c>=0;c--)
    {
        if(c>=w[i])
        f[c]=max(f[c],f[c-w[i]]+v[i]);
    }
}

//完全背包问题

for(int i=1;i<=n;i++)
{
    for(int c=0;c<=m;c++)
    {
        if(c>=w[i])
        f[c]=max(f[c],f[c-w[i]]+v[i]);
    }
}

//多重背包问题

for(int i=1;i<=n;i++)
{
    if(w[i]*a[i]>m)
    {
        for(int c=0;c<=m;c++)
        {
        if(c>=w[i])
        f[c]=max(f[c],f[c-w[i]]+v[i]);
        }
    }
    else
    {
         k=1;amount=a[i];
         while(k<amount)
         {
             for(int c=k*w[i];c>=0;c--)
             {
                 if(c>=w[i])
                 f[c]=max(f[c],f[c-w[i]]+k*v[i]);
             }
             amount-=k;
             k<<=1;
         }  
         for(int c=amount*w[i];c>=0;c--)
         {
             f[c]=max(f[c],f[c-w[i]]+amount*v[i]);
         }
    } 
}