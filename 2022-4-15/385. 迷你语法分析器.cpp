/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {

public:
    NestedInteger deserialize(string ss) {
        if (ss[0] != '[')
            return NestedInteger(stoi(ss));
        stack<NestedInteger> st;
        string num = "";
        int s = 0, n = static_cast<int>(ss.size());
        while (s < n) {
            if (ss[s] == '[') {
                st.emplace(NestedInteger());
                ++s;
            } else if (ss[s] == '-' || isdigit(ss[s])) {
                int e = s + 1;
                while (e < n && isdigit(ss[e]))
                    ++e;
                num = ss.substr(s, e - s);
                if (st.empty())
                    st.emplace(NestedInteger());
                st.top().add(NestedInteger(stoi(num)));
                num.clear();
                s = e;
            } else if (ss[s] == ']') {
                if (st.size() > 1) {
                    NestedInteger nt = st.top();
                    st.pop();
                    st.top().add(nt);
                }
                ++s;
            } else {
                ++s;
            }
        }
        return st.top();
    }
};