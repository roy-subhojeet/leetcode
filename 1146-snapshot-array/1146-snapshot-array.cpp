class SnapshotArray {
public:
    int snapId;
    vector<vector<pair<int, int>>> historyRecords;
    SnapshotArray(int length) {
        snapId = 0;
        historyRecords.resize(length);
        for (int i = 0; i < length; ++i) {
            historyRecords[i].push_back(make_pair(0, 0));
        }
    }
    
    void set(int index, int val) {
        historyRecords[index].push_back(make_pair(snapId, val));
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(historyRecords[index].begin(), historyRecords[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};
/* 

The revised version of your SnapshotArray class presents a significant improvement over the initial version in several key aspects:

Memory Efficiency
Initial Version: It uses a 2D vector array where each sub-vector is initialized with a large size (5*10000). This approach can be extremely memory-inefficient, especially if many elements in the array don't change between snapshots.
Revised Version: It employs a vector of vectors of pairs (historyRecords), with each pair representing a snapshot ID and the value at that snapshot. This design only stores values when they change, drastically reducing memory usage.
Time Efficiency
Initial Version: In the snap function, it copies the entire state of the array for each snapshot, which is time-consuming, especially for large arrays where few elements change.
Revised Version: The snap function merely increments the snapId without needing to copy or iterate over the array. This is a much more efficient operation, especially for large arrays.
Complexity and Performance
Initial Version: Complexity increases as the array size and number of snapshots grow because it stores every value at every snapshot, even if unchanged.
Revised Version: It optimizes storage by keeping a history of changes only. The use of upper_bound in the get function allows for efficient retrieval of the value at a particular snapshot, as it performs a binary search.
Scalability
Initial Version: Due to its inefficient use of memory and time, it scales poorly with larger data sizes and more snapshots.
Revised Version: Scales better due to its efficient use of resources. It's more suitable for scenarios with a large number of snapshots or array elements.
Functional Improvement
Revised Version: It ensures that each set operation is associated with the current snapshot, which aligns better with the expected functionality of a snapshot array.
Error Handling and Robustness
While both versions lack explicit error handling (like out-of-bounds checks), the revised version's approach is inherently safer due to its efficient use of resources and reduced likelihood of memory-related issues.
In summary, the revised version is superior in terms of memory efficiency, time efficiency, complexity, performance, scalability, and alignment with the expected functionality of a snapshot array.
*/
/* Initial Point of Failure
class SnapshotArray {
public:
    vector<vector<int>> array;
    int snapID = 0;
    SnapshotArray(int length) {
        array.resize(length, vector<int>(5*10000));
    }
    
    void set(int index, int val) {
        array[index][snapID] = val;
    }
    
    int snap() {
        for(int i = 0; i < array.size(); ++i)
        {
            array[i][snapID+1] = array[i][snapID];
        }
        return snapID++;
    }
    
    int get(int index, int snap_id) {
        return array[index][snap_id];
    }
};
*/
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */