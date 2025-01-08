// Author: Dorian Knight
// Date: January 8th 2025
// Description: Ransom Note Java Solution
// Topics: Hash Table | String | Counting
// Rank: Easy

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        // Construct hashmap
        HashMap<String, Integer> letters = new HashMap<>(magazine.length());
        String letterToAdd;
        Integer letterQuantity;
        for (int i=0; i<magazine.length(); i++) {
            letterToAdd = magazine.substring(i, i+1);
            // check if letter is already in hash map
            letterQuantity = letters.get(letterToAdd);
            if (letterQuantity != null) {
                // Increment the value associated with the key
                letterQuantity++;
                letters.put(letterToAdd, letterQuantity);
            }

            else {
                letters.put(letterToAdd, 1);
            }
        }

        // Evaluate if ransom note can be assembled using characters in magazine
        String ransomChar;
        int j;
        boolean isPossible = false;
        for (j=0; j<ransomNote.length(); j++) {
            ransomChar = ransomNote.substring(j, j+1);
            letterQuantity = letters.get(ransomChar);

            if (letterQuantity == null) {
                // This letter doesn't exist in the magazine
                isPossible = false;
                break;
            }

            else {
                // Letter was found, change hashmap to reflext remaining letters
                isPossible = true;
                letterQuantity--;
                if (letterQuantity == 0) {
                    // No more of this letter, remove the entry from the hashmap
                    letters.remove(ransomChar);
                }

                else {
                    // Update quantity of specific letter
                    letters.put(ransomChar, letterQuantity);
                }
            }
        }

        return isPossible;
    }
}