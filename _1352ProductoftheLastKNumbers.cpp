//
// Created by Fangzhou Zhang on 2020/2/16.
//
class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }
    void add(int num) {
        if (num != 0) a.push_back(a.back() * num);
        else a = {1};
    }

    int getProduct(int k) {
        int last_idx = a.size() - 1;
        //k = last idx - first idx + 1
        int first_idx = last_idx - k;
        return k >= a.size() ? 0 : a[last_idx] / a[first_idx];
    }
private:
    vector<int> a = {1};
};
