#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <deque>
#include <assert.h>
//
using namespace std;

class Base{
public:
    static int hp[5]; // 每个兵种的生命值
    static char names[5][8];     // 表示每个兵种的名字

    bool stop;  // 是否已经不能再造武士了
    int po;     // 表示下个一兵种的类型
    int live;   // 司令部表示所剩生命值。
    int nums[5];    // 表示每个兵种的个数。
public:
    Base(int _live){
        po = 0;
        stop = false;
        live = _live;
        memset(nums,0,sizeof(nums));
    }
    virtual void product(int times) =0;
    virtual bool isStop() =0;
};

char Base::names[5][8] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Base::hp[5] = {0, 0, 0, 0, 0 };


class Red : public Base {
public:
    static int mp[];
    Red(int _live):Base(_live){
    }

    void product(int times) {

        printf("%03d ", times);
        for (int cnt=0; ; po=(po+1)%5,cnt++){
            if (cnt == 5){
                stop = true;
                printf("red headquarter stops making warriors\n");
                break;
            }
            if (Base::hp[mp[po]] <= live){
                nums[mp[po]]++;
                printf("red %s %d born with strength %d,%d %s in red headquarter\n",
                       names[mp[po]], times+1, Base::hp[mp[po]], nums[mp[po]], names[mp[po]]);
                live -= Base::hp[mp[po]];
                po = (po+1)%5;
                break;
            }
        }
    }
    bool isStop(){
        return stop;
    }

};
int Red::mp[] = {2, 3, 4, 1, 0};



class Blue : public Base {
public:
    static int mp[];
    Blue(int _live):Base(_live){
    }

    void product(int times) {

        printf("%03d ", times);
        for (int cnt=0; ; po=(po+1)%5,cnt++){
            if (cnt == 5){
                stop = true;
                printf("blue headquarter stops making warriors\n");
                break;
            }
            if (Base::hp[mp[po]] <= live){
                nums[mp[po]]++;
                printf("blue %s %d born with strength %d,%d %s in blue headquarter\n",
                       names[mp[po]], times+1, Base::hp[mp[po]], nums[mp[po]], names[mp[po]]);
                live -= Base::hp[mp[po]];
                po = (po+1)%5;
                break;
            }
        }
    }
    bool isStop(){
        return stop;
    }

};
int Blue::mp[] = {3, 0, 1, 2, 4};



int main(){

    int n(1);
    cin>> n;
    for (int ica = 1; ica<=n; ica++){
        printf("Case:%d\n", ica);
        int live;
        cin>> live;
        Red red(live);
        Blue blue(live);
        for(int i=0;i<5;i++)
            cin>> Base::hp[i];

        int times = 0;
        while(!red.isStop() || !blue.isStop()){
            if(!red.isStop())
                red.product(times);
            if(!blue.isStop())
                blue.product(times);
            times++;
        }

    }

}

