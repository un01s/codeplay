/*
 * leetcode 155
 * minStack
 * 
 * use another stack to implement this min stack
 *
 */

class MinStack {
public:
    MinStack() {
    }

    void push(int x) {
        if (st.size() == 0) {
            st.push({x, x});
        } else {
            st.push({x, min(x, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int> > st;
};

