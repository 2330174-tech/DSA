class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[') {
                nums.push(k);
                strs.push(curr);

                k = 0;
                curr = "";
            }
            else if (ch == ']') {
                int repeat = nums.top();
                nums.pop();

                string temp = strs.top();
                strs.pop();

                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }

                curr = temp;
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};