/*
 * Solution description
 * 
 * Creates a stack to store all open bracket characters and iterates through the string until it finds the
 * corresponding closing bracket. Once closing bracket is found, the open bracket will be popped from the string
 * By the end of the string, if the stack is empty, that meant that every open bracket found its corresponding
 * closing bracket, if not, some open brackets don't have closing brackets and the string is false
 */

class Solution {
public:
    bool isValid(string s) {
        // Stores the brackets in order of appearance and pops them once the corresponding closing bracket has been found
        stack<char> bracket_stack;
        bool ret_val = false;
        for (int i=0; i<s.length(); i++)
        {
            if (bracket_stack.empty())
            {
                if (s[i] == ')' or s[i] == '}' or s[i] == ']')
                {
                    // If there are no more brackets to be closed but yet still you encounter a closed bracket, we will know that this string is false, no need to keep searching
                    return ret_val;
                }
                else
                {
                    // Get next bracket
                    bracket_stack.push(s[i]);
                }
            }
            else
            {
                // Check for corresponding closing bracket and pop the current open bracket off the stack
                if ((s[i] == '}' && bracket_stack.top() == '{') ||
                    (s[i] == ')' && bracket_stack.top() == '(') ||
                    (s[i] == ']' && bracket_stack.top() == '['))
                {
                    // corresponding closing bracket has been found.
                    // Pop open bracket off the stack
                    bracket_stack.pop();
                }
                else
                {
                    // Found an open bracket to push onto the stack
                    bracket_stack.push(s[i]);
                }
            }
        }
        if (bracket_stack.empty())
        {
            // Every open bracket has a corresponding close bracket, string is true
            ret_val = true;
            return ret_val;
        }
        else
        {
            // Not every open bracket has a corresponding close bracket, string is false
            return ret_val;
        }

        // Deallocates memory to prevent memory leak
        bracket_stack.~stack();
    }
};