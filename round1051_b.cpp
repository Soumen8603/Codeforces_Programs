#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int coupons, items;
        cin >> items >> coupons;
        vector<int> itemsv(items);
        vector<int> couponsv(coupons);
        for (int i = 0; i < items; i++)
        {
            cin >> itemsv[i];
        }
        for (int i = 0; i < coupons; i++)
        {
            cin >> couponsv[i];
        }

        sort(itemsv.begin(), itemsv.end(), std::greater<>());
        sort(couponsv.begin(), couponsv.end());

        long long total_price = 0;
        for (int price : itemsv)
        {
            total_price += price;
        }

        long long total_savings = 0;
        int product_pointer = 0;

        for (int i = 0; i < coupons; i++)
        {
            int coupon_size = couponsv[i];

            if (product_pointer + coupon_size <= items)
            {

                int free_item_index = product_pointer + coupon_size - 1;
                total_savings += itemsv[free_item_index];

                product_pointer += coupon_size;
            }
            else
            {

                break;
            }
        }
        cout << total_price - total_savings << endl;
    }
    return 0;
}