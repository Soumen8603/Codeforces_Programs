#include <iostream>
#include <vector>
#include <climits>
#include <string.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        vector<int> nums(n);
        int maxIndex;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if(nums[i] == n){
             maxIndex = i;
            }
        }
        
       
        

        bool check = true;
        int left = maxIndex, right = maxIndex;
        int curr = n;

        while (check == true)
        {
            
            if (curr == 1)
            {
                cout << "YES" << endl;
                break;
            }
            else if ((left - 1 >= 0 && nums[left - 1] == curr - 1) || (right + 1 < n && nums[right + 1] == curr - 1))
            {
                if (left - 1 >= 0 && nums[left - 1] == curr - 1)
                {
                    left = left - 1;
                    curr--;
                }
                else
                {
                    right = right + 1;
                    curr--;
                }
                for (int i = left; i <= right; i++)
                {
                    nums[i] = curr;
                }
            }
            else
            {
                cout << "NO" << endl;
                check = false;
            }
        }
    }
}