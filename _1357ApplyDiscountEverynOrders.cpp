//
// Created by Fangzhou Zhang on 2020/2/25.
//
class Cashier {
private:
    int n;
    int next_id;
    int discount;
    unordered_map<int, int> map;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        next_id = 1;
        this->n = n;
        this->discount = discount;
        for (int i = 0; i < products.size(); i++) map[products[i]] = prices[i];
    }

    double getBill(vector<int> product, vector<int> amount) {
        bool dis = (next_id % n == 0) ? true : false;
        double money = 0;
        for (int i = 0; i < product.size(); i++) {
            int price = map[product[i]];
            money += price * amount[i];
        }
        if (dis) money = money - (discount * money) / 100;
        next_id++;
        return money;
    }
};
