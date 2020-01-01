#include <iostream>
#include <vector>

//Time Complexity: O(1) 
//Space Complexity: O(n)  

// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : Had some issues with vector intialization & resizing to ensure time doesn't go to O(n) 

using namespace std;

class MyHashSet {
public:
    
    int primary_size = 1000;
    int extended_size = 1000;
    
    vector<vector<bool>> hash_vector; 
    
    int primary(int key)
    {
        return key % primary_size;
    }
    
    int extended(int key)
    {
        return key/extended_size;
    }
    
    /** Initialize your data structure here. */
    MyHashSet() {
        hash_vector = vector<vector<bool>>(primary_size); //initalized to only 1000 spaces 
    }
    
    void add(int key) {
        int primary_hash = primary(key);
        int extended_hash = extended(key);
        
        if(hash_vector[primary_hash].empty())
            hash_vector[primary_hash].resize(extended_size); //extend to 1000*1000 spaces 2d
        
        hash_vector[primary_hash][extended_hash] = true;
    }
    
    void remove(int key) {
        int primary_hash = primary(key);
        int extended_hash = extended(key);
        
        if(!hash_vector[primary_hash].empty())
            hash_vector[primary_hash][extended_hash] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int primary_hash = primary(key);
        int extended_hash = extended(key);
        
        if(!hash_vector[primary_hash].empty())
            return hash_vector[primary_hash][extended_hash];
        return false;
        
    }
};