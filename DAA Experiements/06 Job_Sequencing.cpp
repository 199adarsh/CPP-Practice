#include <iostream>
#include <algorithm>
using namespace std;

struct Job { int deadline, profit; };

bool cmp(Job a, Job b) { return a.profit > b.profit; }

int main() {
    Job jobs[] = {{2,100},{1,19},{2,27},{1,25}};

    sort(jobs, jobs+4 , cmp);

    int slots[2] = {-1,-1}; 
    int totalProfit = 0;

    for (int i = 0; i < 4; i++)
        for (int j = jobs[i].deadline-1; j >= 0; j--)
            if (slots[j] == -1) {
                slots[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }

    cout << totalProfit;
}