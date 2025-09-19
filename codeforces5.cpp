#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        long long res;
        int first = 0;
        int second = 0;
        if(a == b){
            cout << 0 << endl;
        }
        else if (b > a)
        {
            if (y < x)
            {
                if ((b - a) % 2 == 0)
                {
                    first = (b - a) / 2;
                    second = (b - a) / 2;
                }
                else
                {
                    if (a % 2 == 0)
                    {
                        first = (b - a) / 2;
                        second = first + 1;
                    }
                    else
                    {
                        first = (b - a) / 2 + 1;
                        second = first - 1;
                    }
                }
            }
            else
            {
                first = b - a;
                second = 0;
            }
            cout << (first * x + second * y) << endl;
        }
        else{
            if(a % 2 != 0 && a - b == 1){
                cout<<y<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }

    
}