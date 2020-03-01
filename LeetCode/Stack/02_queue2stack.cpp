/*
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

queue包含的操作如下
q.push(x) 往队尾加x
q.pop() 把队头的元素移出, void 函数
q.front() 取值队头元素
q.back() 取值队尾元素
q.empty() 判断是否为非空
q.size() 拿到队列的size

stack希望存在的操作如下
s.push(x) 往队头加x
s.top() 取队头元素
s.empty() 判断是否为空
s.pop() 取队头元素的同时，将该元素移出

常规push 到pushQueue，stack的队头是pushQueue的队尾
pop时希望能取出stack的队头同时移出该元素，也就是取出pushQueue的队尾同时移除该元素
所以我们可以将除了队尾最后一个元素以外全部移入到popQueue（此时的popQueue是我们希望pop操作后的stack）
topValue取值pushQueue中除最后一个元素的队尾元素,是我们想要的top元素
pushQueue清空后,将pushQueue和topQueue交换，topValue返回

*/

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        topValue = x;
        pushQueue.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        while (pushQueue.size() > 1)
        {
            topValue = pushQueue.front();
            popQueue.push(topValue);
            pushQueue.pop();
        }
        int resvalue = pushQueue.front();
        pushQueue.pop();
        queue<int> tmp = pushQueue;
        pushQueue = popQueue;
        popQueue = tmp;
        return resvalue;
    }

    /** Get the top element. */
    int top()
    {
        return topValue;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return pushQueue.empty();
    }

private:
    std::queue<int> pushQueue;
    std::queue<int> popQueue;
    int topValue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */