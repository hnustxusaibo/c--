#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e5 + 5;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int sum = 0;
        map<int,int> myMap;
        myMap[capacity] = 0;
        for(int i=0;i<n;i++){
            map<int,int> tmpMap;
            for (const auto& [key, value] : myMap) {
                if(key>=plants[i]) {
                    tmpMap[key-plants[i]] = min(,value+1)
                }
            }
        }
    }
};