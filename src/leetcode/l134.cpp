#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
 * 首先我尝试了暴力解决，时间复杂度O(n^2)，可是有个case超时了。这就说明时间复杂度不能太高，应该很可能在O(n)量级，即遍历所有加油站一次就能解决。

然后我就参考了别人的方法。首先明白两点：

 1. 如果从一个加油站不能到达下一个加油站，那么之后的所有加油站都不能到
 2. 如果能走一圈，那么所有的gas之和肯定大于等于所有cost之和

所以，在进行遍历时，一方面要记录当前测试的加油站在哪，即start；另一方面要记录在到达start加油站之前缺少的gas之和是多少。

因此只要对所有加油站从标号0开始遍历一次，在遍历时，如果当前加油站不能到达下个加油站，那么start就标记为下个加油站（因为当前加油站对此后所有加油站都不能到）；记录从标号0的加油站到标号为start的加油站所有缺少的gas之和need，遍历结束时，判断车厢剩的油是否大于等于从标号0的加油站到start之间缺少的gas之和need。

如果遍历一次结束时油箱剩的gas能大于等于need，说明剩的油可以补充汽车从0跑到start缺少的gas，故返回start；否则无解，返回-1.
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() <= 0){
            return -1;
        }
        // 我们计算 cost - gas 那这就是从 i -> i+1 的时候 tank中最少要有的油
        // 那我们肯定能得到一个最缺油的点 t
        // 那意味着到达 t 的时候我们最少要需要的tank的数，
        // 然后我们开始反向推导，那有可能还是在某个点需要 油，那就又变为继续需要的油变多
        // 那怎么计算需要的油呢？
        // tank + gas[i] - cost[i] < 0，则意味着需要
        // need = -(tank + gas[i] - cost[i])
        // 此时从下一个站开始的 tank = 0
        // 我们重新计算直到 tank + gas[i] - cost[i] < 0 ，此时意味着我们又需要
        // 从下一个站点开始
        int need = 0;
        int tank = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            tank = tank + gas[i] - cost[i];
            if (tank<0){
                need += -tank;
                start = i+1;
                tank = 0;
            }
        }
        return tank - need >=0 ? start % gas.size() : -1;
    }
};

int main () {
    Solution s;
    vector<int> gas={4};
    vector<int> cost = {5};
    cout << s.canCompleteCircuit(gas,cost) << endl;
}
