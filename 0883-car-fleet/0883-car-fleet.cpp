class Solution {
public:
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars; // {position, time to reach target}
    
    // Step 1: Calculate time for each car to reach target.
    for (int i = 0; i < n; i++) {
        double time = static_cast<double>(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    // Step 2: Sort cars by their starting position.
    sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.first > b.first;
    });

    int fleets = 0;
    double maxTime = 0; // Time taken by the previous car to reach the target.

    // Step 3: Iterate over each car from the one closest to the target.
    for (int i = 0; i < n; i++) {
        if (cars[i].second > maxTime) {
            maxTime = cars[i].second;
            fleets++;
        }
    }

    return fleets;
}

};