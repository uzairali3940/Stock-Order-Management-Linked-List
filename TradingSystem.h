#ifndef TRADING_SYSTEM_H
#define TRADING_SYSTEM_H
#include <string>
// Original priority queue structures retained.
struct OrderNode {int orderID;std::string investorName;std::string stockSymbol;std::string orderType;int quantity;int priority;OrderNode* next;};
class PriorityQueue {
private: OrderNode* front; OrderNode* rear; int count;
public: PriorityQueue();void Add(OrderNode* order);OrderNode* Remove();bool IsEmpty() const;bool IsNotEmpty() const;void PrintQueue() const;~PriorityQueue();
};
// Lab 5 addition: linked list used to manage a separate, rearrangeable order collection.
struct OrderListNode {int orderID;std::string investorName;std::string stockSymbol;std::string orderType;int quantity;int priority;OrderListNode* next;};
class OrderList {
private: OrderListNode* head;int count;OrderListNode* GetNodeAt(int index) const;void Clear();
public: OrderList();OrderList(const OrderList& other);OrderList& operator=(const OrderList& other);~OrderList();
 void Insert(OrderListNode* order);OrderListNode* Remove();void InsertAt(OrderListNode* order,int index);OrderListNode* RemoveAt(int index);
 bool Swap(int first,int second);void Sort();void Reverse();void Print() const;bool IsEmpty() const;bool IsNotEmpty() const;int Size() const;
};
OrderListNode* CreateOrder(const OrderNode& order);
#endif
