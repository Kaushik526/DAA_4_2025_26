#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<int> deadline(n);
    vector<int> profit(n);

    cout << "Enter deadlines:\n";
    for(int i = 0; i < n; i++) {
        cin >> deadline[i];
    }

    cout << "Enter profits:\n";
    for(int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    vector<pair<int,int>> jobList;
    for(int i = 0; i < n; i++) {
        jobList.push_back(make_pair(profit[i], deadline[i]));
    }

    sort(jobList.begin(), jobList.end(), greater<pair<int,int>>());

    int lastDeadline = 0;
    for(int i = 0; i < n; i++) {
        if(deadline[i] > lastDeadline)
            lastDeadline = deadline[i];
    }

    vector<bool> timeSlot(lastDeadline + 1, false);

    int jobCount = 0;
    int maxProfit = 0;

    for(int i = 0; i < n; i++) {
        int d = jobList[i].second;

        while(d > 0) {
            if(!timeSlot[d]) {
                timeSlot[d] = true;
                jobCount++;
                maxProfit += jobList[i].first;
                break;
            }
            d--;
        }
    }

    cout << "\nMaximum jobs done: " << jobCount << endl;
    cout << "Maximum profit earned: " << maxProfit << endl;

    return 0;
}
