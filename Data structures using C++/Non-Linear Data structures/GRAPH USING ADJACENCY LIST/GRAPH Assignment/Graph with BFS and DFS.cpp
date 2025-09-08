#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class Queue
{
public:
    node *front, *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return (true);
        }
        else
        {
            return (false);
        }
    }
    void enqueue(int val)
    {
        node *n = new node;
        n->data = val;
        n->next = NULL;
        if (isEmpty()) // jab list empty ho
        {
            rear = n;
            front = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }

    node *get_rear()
    {
        return (rear);
    }
    node *get_front()
    {
        return (front);
    }

    bool isPresent(int val)
    {
        node *t = front;
        while (t != NULL)
        {
            if (t->data == val)
            {
                return true;
            }
            t = t->next;
        }
        return false;
    }

    void Empty()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
    void dequeue()
    {
        node *temp;
        if (isEmpty())
        {
            cout << "Error:List is Empty Can Not Delete";
        }
        else if (front->next == NULL)
        {
            delete front;
            front = NULL;
            rear = NULL;
        }
        else
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    int count()
    {
        if (isEmpty())
        {
            return (0);
        }
        int c = 0;
        node *t;
        t = front;
        while (t != NULL)
        {
            t = t->next;
            c++;
        }
        return (c);
    }
    Queue(Queue &q)
    {
        node *t = q.front;
        while (!isEmpty())
        {
            dequeue();
        }

        while (t != NULL)
        {
            enqueue(t->data);
            t = t->next;
        }
    }

    Queue &operator=(Queue &q)
    {
        node *t = q.front;
        while (!isEmpty())
        {
            dequeue();
        }
        while (t != NULL)
        {
            enqueue(t->data);
            t = t->next;
        }
        return (q);
    }
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
    void print()
    {
        node *t = front;
        while (t != NULL)
        {
            cout << "[" << t->data << "]" << " ";
            t = t->next;
        }
        cout << endl;
    }
};

class stack
{
public:
    node *top;
    stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    stack(stack &s1)
    {
        node *t1, *t2, *n;
        t1 = s1.top;
        t2 = NULL;
        while (t1 != NULL)
        {
            n = new node;
            n->data = t1->data;
            if (top == NULL)
            {
                top = n;
            }
            else
            {
                t2->next = n;
            }
            t1 = t1->next;
            t2 = n;
        }
        if (t2 != NULL)
        {
            t2->next = NULL;
        }
    }
    void push(int val)
    {
        node *n = new node;
        n->data = val;
        n->next = NULL;
        if (top == NULL)
        {
            top = n;
        }
        else
        {
            n->next = top;
            top = n;
        }
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Error:Stack UnderFlow\n";
        }
        else
        {
            node *t = top;
            top = top->next;
            delete t;
        }
    }

    void print()
    {
        if (top == NULL)
        {
            cout << "Error:Stack is Empty Can't Print\n";
        }
        else
        {
            node *t;
            t = top;
            while (t != NULL)
            {
                cout << "[" << t->data << "]" << endl;
                t = t->next;
            }
            cout << endl;
        }
    }
    int peek()
    {
        return (top->data);
    }
    ~stack()
    {
        while (top != NULL)
        {
            pop();
        }
    }

    void reverse()
    {
        int temp;
        node *t1, *t2, *t3;
        if (top == NULL)
        {
            cout << "Error:Stack is Empty can't Reverse\n";
        }
        else if (top->next == NULL)
        {
            cout << "Error:Stack Has Only One Element Can't Reverse\n";
        }
        else if (top->next->next == NULL)
        {
            temp = top->data;
            top->data = top->next->data;
            top->next->data = temp;
        }
        else
        {
            t1 = top;
            t2 = top->next;
            t3 = top->next->next;
            t1->next = NULL;
            while (t2 != NULL)
            {
                t2->next = t1;
                t1 = t2;
                t2 = t3;
                if (t3 == NULL)
                {
                    continue;
                }
                t3 = t3->next;
            }
            top = t1;
        }
    }
    int Length(int n)
    {
        int i = 0;
        while (n != 0)
        {
            i++;
            n = n / 10;
        }
        return i;
    }
    bool IsPlaindrome(int n)
    {
        stack s;
        int length = Length(n);
        int i = length / 2;
        while (i != 0)
        {
            s.push(n % 10);
            n = n / 10;
            i--;
        }
        if (length % 2)
        {
            n = n / 10;
        }
        while (n != 0)
        {
            if (n % 10 == s.peek())
            {
                s.pop();
                n = n / 10;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool isPlaindrome(int n)
    {
        stack s1, s2;
        node *t1, *t2;

        while (n != 0)
        {
            s1.push(n % 10);
            s2.push(n % 10);
            n = n / 10;
        }
        s2.reverse();
        t1 = s1.top;
        t2 = s2.top;
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->data != t2->data)
            {
                return (false);
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return (true);
    }
};

class Graph
{
public:
    int v;
    node **list;

    Graph()
    {
    }

    Graph(int n)
    {

        int i = 0;
        v = n;
        list = new node *[n];
        while (i < n)
        {
            list[i] = NULL;
            i++;
        }
    }

    void AddEdge(int i, int e)
    {
        i--;
        node *n = new node;
        node *t;
        n->data = e;
        n->next = NULL;
        if (list[i] == NULL)
        {
            list[i] = n;
        }
        else
        {
            t = list[i];

            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
    }

    void Print_List()
    {
        int i = 0;
        node *t;
        while (i < v)
        {
            t = list[i];
            cout << i + 1 << ":";
            while (t != NULL)
            {
                cout << "[" << t->data << "]" << "-->";
                t = t->next;
            }
            cout << endl;
            i++;
        }
    }

    void BFS(int start)
    {
        node *t, *temp;
        int current, i;
        bool *visited = new bool[v];
        Queue queue;
        for (i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        visited[start - 1] = true;
        queue.enqueue(start);
        while (queue.isEmpty() != true)
        {
            temp = queue.get_front();
            current = temp->data;
            cout << current << " ";
            queue.dequeue();
            t = list[current - 1];
            while (t != NULL)
            {
                if (visited[t->data - 1] == false)
                {
                    queue.enqueue(t->data);
                    visited[t->data - 1] = true;
                }
                t = t->next;
            }
        }
    }

    void DFS(int start)
    {
        int current, i;
        node *t, *rev, *temp;
        stack s1;
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        s1.push(start); // PEHLA NODE VISITED

        while (s1.isEmpty() != true)
        {
            current = s1.peek();
            s1.pop();
            if (visited[current - 1] == false)
            {
                cout << current << " ";
                visited[current - 1] = true;
                t = list[current - 1];
                rev = NULL;
                while (t != NULL) // REVERSE A LIST
                {
                    node *n = new node;
                    n->data = t->data;
                    n->next = rev;
                    rev = n;
                    t = t->next;
                }
                while (rev != NULL)
                {
                    if (visited[rev->data - 1] == false)
                    {
                        s1.push(rev->data);
                    }
                    temp = rev;
                    rev = rev->next;
                    delete temp;
                }
            }
        }
    }

    ~Graph()
    {
        int i=0;
        node *t;
        while(i<v)
        {
            t=list[i];
            while(t!=NULL)
            {
                node *n=t;
                t=t->next;
                delete n;
            }
        }
        delete [] list;
    }
};

int main()
{
    int n;
    Graph g1(5);

    g1.AddEdge(1, 2); // 1 node ke edg
    g1.AddEdge(1, 5);

    g1.AddEdge(2, 1);
    g1.AddEdge(2, 3);
    g1.AddEdge(2, 5);

    g1.AddEdge(3, 2);
    g1.AddEdge(3, 4);
    g1.AddEdge(3, 5);

    g1.AddEdge(4, 3);
    g1.AddEdge(4, 5);

    g1.AddEdge(5, 1);
    g1.AddEdge(5, 2);
    g1.AddEdge(5, 3);
    g1.AddEdge(5, 4);

    g1.Print_List();
    cout << endl;

    g1.BFS(1);
    cout << endl;

    g1.DFS(1);

    return 0;
}