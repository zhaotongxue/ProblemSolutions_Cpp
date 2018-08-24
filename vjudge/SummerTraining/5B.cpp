#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int num;
/*
Over,看题解做的，别统计ಡωಡ
每个数包含的3的个数都是在减少的，包含3的个数相同的时候就把大的排到后面（因为*2）
*/
struct number {
    ll n;
    ll cnt;
    number(ll nc, ll cntc) :n(nc), cnt(cntc){};
    number(){};
    bool operator<(const number& handle) const{
        return this->cnt > handle.cnt;
    }
};
int main() {
    scanf("%d", &num);
    number arr[num];
    ll temp;
    for (int i = 0; i < num; i++) {
        ll cnt = 0;
        scanf("%lld", &temp);
        number n;
        n.n = temp;
        while(temp%3==0){
            cnt++;
            temp /= 3;
        }
        // number n(temp, cnt);
        n.cnt = cnt;
        arr[i] = n;
    }
    sort(arr, arr + num);
    for (int i = 0; i < num;i++){
        for (int j = i + 1; j < num;j++){
            if(arr[i].cnt==arr[j].cnt&&arr[i].n>arr[j].n){
                number t=arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    for (int i = 0; i < num;i++){
        printf("%lld ", arr[i].n);
    }
        /*
        deque<ll> ds[101];
        int index = 0;
        while (!nums.empty())
        {
            deque<ll> temp;
            set<ll>::iterator it = nums.end();
            it--;
            ll mxv = *it;
            nums.erase(it);
            temp.push_back(mxv);
            if (mxv % 3 == 0)
            {
                if (nums.contains(mxv / 3))
                {
                    temp.push_back(mxv / 3);
                    nums.erase(mxv / 3);
                }
            }
            if (mxv % 2 == 0)
            {
                deque<ll>::iterator itt = nums.find(mxv / 2);
                if (nums.contains(mxv / 2))
                {
                    temp.push_front(mxv / 2);
                    nums.erase(mxv / 2);
                    if (mxv / 2 % 2 == 0)
                    {
                        if (nums.contains(mxv / 2))
                        {
                            temp.push_front(mxv / 4);
                            nums.erase(mxv / 4);
                        }
                    }
                }
            }
            ds[index] = temp;
            index++;
        }
        deque<ll> res;
        for (deque<ll>::iterator it = ds[0].begin(); it != ds[0].end(); it++)
        {
            res.push_back(*it);
        }
        nums[0] = NULL;
        while (res.size() < nums)
        {
            for (int i = 1; i < index; i++)
            {
                if (ds[i] == NULL)
                    continue;
                if ((ds[i].back() * 2 == res.front()) || (ds[i].back() % 3 == 0
        && ds[i].back() / 3 == res.front()))
                {
                    for (deque<ll>::iterator it = ds[i].end(), it--; it !=
        ds[i].begin(); it--)
                    {
                        res.push_front(*it);
                    }
                    res.push_front(*(ds[i].begin()));
                    ds[i] = NULL;
                }
                else if ((res.back() % 3 == 0 && res.back() / 3 ==
        ds[i].front()) || (res.back() * 2 == ds[i].front()))
                {
                    for (deque<ll>::iterator it = ds[i].begin(); it !=
        ds[i].end(); it++)
                    {
                        res.push_back(*it);
                    }
                    ds[i] = NULL;
                }
            }
        }
        for (deque<ll>::iterator it = res.begin(); it != res.end(); it++)
        {
            printf("%d ", *it);
        }
        int nums;
        scanf("%d", &nums);
        set<ll> s;
        deque<ll> d;
        ll maxval = -1;
        for (int i = 0; i < nums;i++){
            ll t;
            scanf("%lld", &t);
            s.insert(t);
            if(t>maxval)
                maxval=t;
        }
        d.push_back(maxval);
        s.erase(maxval);
        ll k = 1;
        while(k=k*2){
            bool found = 0;
            for (set<ll>::iterator it = s.begin(); it != s.end();it++){
                if((*it)*k==maxval){
                    d.push_front(*it);
                    s.erase(it);
                    found = 1;
                    break;
                }
            }
            if(!found){
                break;
            }
        }
        k = 1;
        while(k=k*3){
            bool found = 0;
            for (set<ll>::iterator it = s.begin(); it != s.end();it++){
                if((*it)*k==maxval){
                    d.push_back(*it);
                    s.erase(it);
                    found = 1;
                    break;
                }
            }
            if(!found){}
        }

        int n;
        scanf("%d", &n);
        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            ll x;
            scanf("%lld", &x);
            s.insert(x);
        }
        deque<ll> dq;
        ll arr[200];
        memset(arr, -1, 200);
        set<ll>::iterator maxit, findit;
        maxit = s.end();
        maxit--;
        ll maxval = *maxit;
        dq.push_front(maxval);
        s.erase(maxit);
        if(!s.empty()&&maxval%2==0){
            findit = s.find(maxval / 2);
            if(findit!=s.end()){
                dq.push_front(maxval / 2);
                s.erase(maxval / 2);
            }
        }
        if(!s.empty()&&dq.front()%2==0){
            findit = s.find(dq.find(dq.front() / 2));
            if(findit!=s.end()){
                dq.push_front(dq.front() / 2);
                s.erase(it);
            }
        }
        if(!s.empty()&&dq.back()%3==0){
            findit = s.find(dq.back() / 3);
            if(findit!=s.end()){
                dq.push_back(dq.back() / 3);
                s.erase(findit);
            }
        }
        while(!s.empty()){
            findit = s.find(dq.front() * 2);
            if(findit!=s.end()){
                s.erase()
            }
            if(dq.front()%3==0){
                findit = s.find(dq.front() / 3);
                if(findit!=s.end()){
                    dq.push_front(dq.front()/3);
                    dq.erase(findit);
                }
            }
            if(s.empty())
                break;
        }
        if ((*maxit) % 2 == 0)
        {
            findit = s.find((*maxit) / 2);
            if (findit != s.end())
            {
                dq.push_front(*findit);
                s.erase(findit);
            }
        }
        dq.push_back(*maxit);
        if ((*maxit) % 3 == 0)
        {
            findit = s.find((*maxit) / 3);
            if (findit != s.end())
            {
                dq.push_back(*findit);
                s.erase(findit);
            }
        }
        s.erase(maxit);
        while (!s.empty())
        {
            int front = dq.front();
            int back = dq.back();
             findit = s.find(front * 3);
            if (findit != s.end())
            {
                dq.push_front(*findit);
                s.erase(findit);
            }
            if (back % 3 == 0)
            {
                findit = s.find(back / 3);
                if (findit != s.end())
                {
                    dq.push_back(*findit);
                    s.erase(findit);
                }
            }
            if (front % 2 == 0)
            {
                findit = s.find(front / 2);
                if (findit != s.end())
                {
                    dq.push_front(*findit);
                    s.erase(findit);
                }
            }
            // front = dq.front();
            findit = s.find(front * 3);
            if (findit != s.end())
            {
                dq.push_front(*findit);
                s.erase(findit);
            }
            if (back % 3 == 0)
            {
                findit = s.find(back / 3);
                if (findit != s.end())
                {
                    dq.push_back(*findit);
                    s.erase(findit);
                }
            }
            // front = dq.front();
            findit = s.find(back * 2);
            if (findit != s.end())
            {
                dq.push_back(*findit);
                s.erase(findit);
            }
        }
        for (deque<ll>::iterator it = dq.begin(); it != dq.end(); it++)
        {
            printf("%lld ", *it);
        }
        */
        return 0;
}