class Solution {
public:
    int passThePillow(int n, int time) {
        int tripCount = time / (n - 1);
        time %= (n - 1);

        if (tripCount % 2 == 0) {
            return 1 + time;
        }
        return n - time;
    }
};