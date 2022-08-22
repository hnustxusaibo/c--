#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 1e3+5;

class MyCircularDeque {
public:
    int que[2500];
    int l,r;
    int kk;
    int size;
    MyCircularDeque(int k) {
        l = r = 1000;
        size = 0;
        kk = k;
    }
    
    bool insertFront(int value) {
        if(size==kk) return false;
        que[r++]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==kk) return false;
        que[--l]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0) return false;
        r--;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0) return false;
        l--;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0) return -1;
        return que[r-1];
    }
    
    int getRear() {
        if(size==0) return -1;
        return que[l];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == kk;
    }
};