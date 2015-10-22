    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    using namespace std;


    int main()
    {
        int n;
        while(cin>>n)
        {
            int temp,t=0,ans;
            while(n--)
            {
                scanf("%d",&temp);

                if(t==0)
                {
                    ans=temp;
                    t++;
                }
                else
                {
                    if(ans==temp)
                    {
                        t++;
                    }
                    else
                    {
                        t--;
                    }

                }
            }
             cout<<ans<<endl;

        }


        return 0;
    }
