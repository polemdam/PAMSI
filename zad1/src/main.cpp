#include <iostream>
#include <cstdlib>
#include <cstring>
#include "List.hh"
#include "Queue.hh"
#include "Stack.hh"
#include "Map.hh"
#include "PriorityQueue.hh"
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()

{
    List<int> list;
    Stack<string> stack;
    Queue<char> queue;
    PriorityQueue<string> priorityQueue;
    Map<char, string> map;

    cout << "........................LIST..........................." << endl;
    list.pushFront(1);
    list.pushFront(2);
    list.pushBack(3);
    list.remove(3);
    list.insert(4, 3);
    list.printList();
    cout << ">>>Operations on list: pushFront '1,'2' ; pushBack '3' ; remove 3rd element ; insert '4' on 3rd place<<<" << endl;
    cout << endl;

    cout << "...........................STACK........................." << endl;
    cout << endl;
    stack.push("stack");
    stack.push("in");
    stack.push("Bad");
    stack.pop();
    stack.push("Welcome");
    stack.printStack();
    cout << ">>>Operations on stack: push 'stack' ; push 'in' ; push 'Bad' ; pop ; push 'Welcome'<<<" << endl;
    cout << endl;

    cout << "...........................QUEUE.........................." << endl;
    cout << endl;
    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');
    queue.dequeue();
    queue.enqueue('d');
    queue.printQueue();
    cout << ">>>Operations on queue: enqueue 'a' ; enqueue 'b' ; enqueue 'c' ; dequeue ; enqueue 'd'<<<" << endl;
    cout << endl;

    cout << "....................PRIORITY QUEUE........................" << endl;
    cout << endl;
    priorityQueue.enqueue("aunt", 3);
    priorityQueue.enqueue("uncle", 1);
    priorityQueue.enqueue("mother", 5);
    priorityQueue.dequeue();
    priorityQueue.enqueue("father", 2);
    priorityQueue.printPriorityQueue();
    cout << ">>>Operations on priority queue: enqueue 'aunt' with priority '3' ; enqueue 'aunt' with priority '3'" << endl;
    cout << "enqueue 'mother' with priority '5' ; dequeue ; enqueue 'father' with priority '2'<<<" << endl;
    cout << endl;

    cout << "............................MAP............................" << endl;
    cout << endl;

    map.insert('r', "car");
    map.insert('q', "bus");
    map.insert('p', "train");
    map.remove(4);
    map.insert('k', "bike");
    map.printMap();
    cout << ">>>Operations on map: insert 'car' with key 'r' ; insert 'bus' with key 'q'" << endl;
    cout << "insert 'train' with key 'p' ; remove ; insert 'bike with key 'k'<<<" << endl;
    cout << endl;

    cout << "////////////////////////////////////////////////////////////////////" << endl;
    cout << "/.............ALTERNATIVE FUNCTIONS IN STL........................./" << endl;
    cout << endl;
    cout << "/.......................List......................................./" << endl;
    cout << endl;
    std::list<int> mylist;
    mylist.push_front(10);
    mylist.push_front(30);
    mylist.push_front(5);
    mylist.push_back(445);

    std::cout << "mylist contains:" << endl;
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it << endl;

    mylist.remove(5);
    mylist.pop_front();

    std::cout << "Operations on the list: remove '5' ; pop_front - mylist contains:" << endl;
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it << endl;

    std::cout << '\n';

    cout << "/...........................Stack................................../" << endl;
    cout << endl;
    std::stack<int> mystack;
    std::cout << "Operations on the stack: push '5','8','1','1' ; pop ; push '5'" << endl;
    cout << endl;
    mystack.push(5);
    mystack.push(8);
    mystack.push(1);
    mystack.push(1);
    mystack.pop();
    mystack.push(5);
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top() << endl;
        mystack.pop();
    }
    std::cout << '\n';

    cout << "/...........................Queue................................../" << endl;
    cout << endl;
    std::queue<int> myqueue;
    std::cout << "Operations on the queue: push '12','75','55','100' ; pop ; push '34' ; pop" << endl;
    std::cout << "myqueue contains: ";
    cout << endl;

    myqueue.push(12);
    myqueue.push(75);
    myqueue.push(55);
    myqueue.push(100);
    myqueue.pop();
    myqueue.push(34);
    myqueue.pop();
    while (!myqueue.empty())
    {
        std::cout << ' ' << myqueue.front();
        myqueue.pop();
        cout << endl;
    }
    std::cout << '\n';

    cout << "/.........................Priority Queue........................../" << endl;
    cout << endl;
    std::cout << "Operations on the priority queue: push 'r','b','p','m' ; pop ; push 'v' " << endl;
    std::cout << "mypq contains: ";
    cout << endl;

    std::priority_queue<char> mypq;

    mypq.push('r');
    mypq.push('b');
    mypq.push('p');
    mypq.push('m');
    mypq.pop();
    mypq.push('v');

    while (!mypq.empty())
    {
        std::cout << ' ' << mypq.top();
        mypq.pop();
        cout << endl;
    }
    std::cout << '\n';

    cout << "/.........................Map................................../" << endl;
    cout << endl;
    std::cout << "Operations on the map: insert: '100' with value 'a' ; '44' with value 'd' ; '867' with value 'v' ";
    std::cout << "'461' with value 'm'" << endl;
    std::cout << "mymap contains:\n";
    cout << endl;

    std::map<char, int> mymap;

    std::map<char, int>::iterator it = mymap.begin();
    mymap.insert(std::pair<char, int>('a', 100));
    mymap.insert(std::pair<char, int>('d', 44));
    mymap.insert(it, std::pair<char, int>('v', 876));
    mymap.insert(it, std::pair<char, int>('m', 461));

    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << "." << it->second << '\n';

    return 0;
}