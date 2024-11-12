class Solution {
public:
    vector<int> prices;
    map<int, int> max_beauty;

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ret;

        sort(items.begin(), items.end());

        int maxx_beauty = 0;
        for (int i=0; i<items.size(); i++) {
            int price = items[i][0];
            int beauty = items[i][1];
            maxx_beauty = max(maxx_beauty, beauty);

            if (max_beauty[price] == 0) {
                prices.push_back(price);
                max_beauty[price] = maxx_beauty;
                continue;
            }

            max_beauty[price] = max(max_beauty[price], maxx_beauty);
        }

        for (auto& query : queries) {
            int key = lower_bound(prices.begin(), prices.end(), query) - prices.begin();

            if (key == 0 && prices[key] > query) {
                ret.push_back(0);
                continue;
            }

            if (key == prices.size() || prices[key] > query) key--;

            ret.push_back(max_beauty[prices[key]]);
        }

        return ret;
    }
};