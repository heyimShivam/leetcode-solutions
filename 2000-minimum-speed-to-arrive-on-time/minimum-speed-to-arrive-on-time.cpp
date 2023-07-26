class Solution {
public:
    bool valid(vector<int> &dist, double hour, int speed) {
        double time = 0;

        for (int i = 0; i < dist.size(); i++) {
            time = ceil(time);
            time += (double) dist[i] / speed;

            if (time > hour) return false;
        }

        return true;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) return -1;

        int left = 1, right = 1e7;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (!valid(dist, hour, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};