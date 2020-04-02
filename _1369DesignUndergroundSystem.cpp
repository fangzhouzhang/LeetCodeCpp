//
// Created by Fangzhou Zhang on 2020/4/2.
//
class UndergroundSystem {
    unordered_map<int, pair<string, long>> checkin;
    unordered_map<string, pair<long, int>> time;
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        checkin[id] = make_pair(stationName, (long)t);
    }

    void checkOut(int id, string stationName, int t) {
        pair<string, long> &p = checkin[id];
        string key = p.first + "#" + stationName;

        time[key].first += t - p.second;
        time[key].second += 1;

        checkin.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "#" + endStation;
        return time[key].first * 1.0 / time[key].second;
    }
};
