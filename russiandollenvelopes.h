#ifndef RUSSIANDOLLENVELOPES
#define RUSSIANDOLLENVELOPES

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PAIR;

ostream& operator<<(ostream& out, const map<int,PAIR>& p) {
    map<int,PAIR>::const_iterator it = p.cbegin();
    while(it != p.cend()) {
        out << it->first << "\t(" << it->second.first << "," << it->second.second << ")" << endl;
        ++it;
    }
    return out;
}

ostream& operator<<(ostream& out, const vector<PAIR>& p) {
    vector<PAIR>::const_iterator it = p.begin();
    cout << 1 << endl;
    while(it != p.end()) {
        out << "(" << it->first << "," << it->second << ")" << endl;
        ++it;
    }
    return out;
}

ostream& operator<<(ostream& out, const map<PAIR,int>& p) {
    map<PAIR,int>::const_iterator it = p.cbegin();
    while(it != p.cend()) {
        out << "(" << it->first.first << "," << it->first.second << ")\t" << it->second << endl;
        ++it;
    }
  return out;
}


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
//        cout << envelopes << endl;
        map<int, pair<int, int>> area_w_h_map;
        map<pair<int, int>, int> w_h_count_map;

        vector<pair<int, int>>::const_iterator it;
        it = envelopes.cbegin();
        while(it != envelopes.end()) {
            area_w_h_map[it->first * it->second] = *it;
            w_h_count_map[*it] = 0;
            ++it;
        }

        map<int, pair<int, int>>::const_iterator it1 = area_w_h_map.cbegin();
        w_h_count_map[it1->second] = 1;

//        cout << area_w_h_map << endl;
//        cout << w_h_count_map << endl;

        map<int, pair<int, int>>::const_iterator it2;
        for(it1 = area_w_h_map.cbegin(); it1 != area_w_h_map.cend(); ++it1) {
            for(it2 = area_w_h_map.cbegin(); it2 != it1; ++it2) {
                if(it1->second.first > it2->second.first && it1->second.second > it2->second.second
                   && w_h_count_map[it1->second] < w_h_count_map[it2->second] + 1) {
                    w_h_count_map[it1->second] = w_h_count_map[it2->second] + 1;
                }
            }
        }
        --it1;

        return w_h_count_map[it1->second];
    }

    void test() {
        vector<pair<int,int>> envelopes{{1,2},{5,6},{3,4},{5,2}};
        sort(envelopes.begin(),envelopes.end());

//        int max = maxEnvelopes(envelopes);
        cout << envelopes << endl;
    }
};

#endif // RUSSIANDOLLENVELOPES

