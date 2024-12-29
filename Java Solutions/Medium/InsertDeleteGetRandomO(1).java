// Author: Dorian Knight
// Date: December 28th 2024
// Description: Insert delete get random O(1) Java solution
// Rank: Medium

class RandomizedSet {
    List<Integer> set;
    Random rand;
    public RandomizedSet() {
        set = new ArrayList<>();
        rand = new Random();
    }

    public boolean insert(int val) {
        if (set.indexOf(val) == -1){
            set.add(val);
            return true;
        }
        return false;
    }

    public boolean remove(int val) {
        int indexToRemove = set.indexOf(val);
        if (indexToRemove != -1){
            set.remove(indexToRemove);
            return true;
        }
        return false;
    }

    public int getRandom() {
        return set.get(rand.nextInt(set.size()));
    }
}