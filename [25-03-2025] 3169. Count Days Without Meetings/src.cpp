class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        int curEndDay = 1;
        int freeDays = 0;
        
        for (int i = 0; i < meetings.size(); i++) {
            if (curEndDay < meetings[i][0]) {
                freeDays += meetings[i][0] - curEndDay - (i == 0 ? 0 : 1);
            }
            curEndDay = max(meetings[i][1], curEndDay);
        }
        
        return freeDays + days - curEndDay;
    }
};
