/* 
380. Insert Delete GetRandom O(1)
Medium

Design a data structure that supports all following operations in average O(1) time.

    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

*/

/*
solution 1:just use unordered_set!
*/

/*
solution 2:
Idea is to use two data structures to do book-keeping:

    unordered_map<int, int> to store relationship
    vector to store relationship
    You can use the size from map or vector to determine how many elements are there but I tend to use a explicit member variable "size" to record as we are designing a new data structure.

    insert():
    simply add to map and push_back to vector
    increment size
    getRandom():
    generate a random integer randIdx from 0 to size - 1, and simply return the element at index randIdx (from the vector)
    remove():
    swap the element to be removed with the last element in the vector
    pop out the last element
    update book-keeping information in both data structures
    decrement size

*/
class RandomizedSet {
public:
    unordered_set<int> set;
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(set.find(val) == set.end()){
            set.insert(val);
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(set.find(val) != set.end()){
            set.erase(val);
            return true;
        }
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand()%(set.size());
        cout<<index<<":"<<set.size()<<endl;
        auto it = set.begin();
        std::advance(it, index);
        int x = *it;
        return x;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */