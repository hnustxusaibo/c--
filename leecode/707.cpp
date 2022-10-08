#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

int sum[100005];

class MyLinkedList {
public:
    
    list<int> linkList;

    MyLinkedList() {
        linkList.clear();
    }
    
    int get(int index) {
        return *find(index);
    }
    
    list<int>::iterator find(int index) {
       list<int>::iterator it = linkList.begin();
       while(index--) it++;
       return it;
    }

    void addAtHead(int val) {
        linkList.emplace_front(val);
    }
    
    void addAtTail(int val) {
        linkList.emplace_back(val);
    }
    
    void addAtIndex(int index, int val) {
        linkList.emplace(find(index),val);
    }
    
    void deleteAtIndex(int index) {
        linkList.erase(find(index));
    }
};