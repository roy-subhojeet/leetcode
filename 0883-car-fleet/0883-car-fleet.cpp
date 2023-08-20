class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars; // {position, time to reach target}
        
        // Step 1: Calculate the time each car takes to reach the target from its starting position.
        for (int i = 0; i < n; i++) {
            // The formula used here is distance/speed = time.
            // Distance to target for car[i] = target - position[i]
            double time = static_cast<double>(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Step 2: Sort the cars by their starting position in descending order.
        // This ensures that the car closest to the target comes first.
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        int fleets = 0;  // Count of car fleets.
        double maxTime = 0; // Keeps track of the time taken by the car closest to the target in the current fleet.

        // Step 3: Iterate over each car starting from the one closest to the target.
        for (int i = 0; i < n; i++) {
            // If the car[i] takes more time to reach the target than the car which is
            // leading the current fleet (i.e., maxTime), then this car forms a new fleet.
            if (cars[i].second > maxTime) {
                maxTime = cars[i].second;
                fleets++;  // Increment the fleet count.
            }
            // Otherwise, car[i] will be part of the current fleet led by the car reaching
            // the target in maxTime, as cars[i] cannot overtake and will move at the speed of the leading car.
        }

        return fleets;  // Return the total number of fleets that will reach the target.
    }
};
