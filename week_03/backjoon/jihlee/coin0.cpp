#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> coin_type;

int main()
{
    int coin_num = 0, target_price = 0, coin = 0;
    cin >> coin_num >> target_price;

    for (int i = 0; i < coin_num; i++) {
        cin >> coin;
        coin_type.push_back(coin);
    }

    int min_coin_num = 0;
    for (int i = 0; i < coin_num; i++) {
        if (target_price == 0)
            break;
            
        min_coin_num += target_price / coin_type.back();
        target_price = target_price % coin_type.back();
        coin_type.pop_back();
    }
    cout << min_coin_num << endl;
}