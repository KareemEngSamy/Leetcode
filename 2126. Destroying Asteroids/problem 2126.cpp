class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long current_mass = mass;

        sort(asteroids.begin(), asteroids.end());

        for (int x : asteroids) {
            if (current_mass < x) return false;
            current_mass += x;
        }

        return true;
    }
};