#include "TradingSystem.h"
#include <iostream>
#include <utility>
PriorityQueue::PriorityQueue():front(nullptr),rear(nullptr),count(0){}
void PriorityQueue::Add(OrderNode* order){if(!order)return;order->next=nullptr;if(!front)front=rear=order;else if(order->priority<front->priority){order->next=front;front=order;}else{OrderNode*p=front;while(p->next&&p->next->priority<=order->priority)p=p->next;order->next=p->next;p->next=order;if(!order->next)rear=order;}++count;}
OrderNode* PriorityQueue::Remove(){if(!front)return nullptr;OrderNode*t=front;front=front->next;if(!front)rear=nullptr;t->next=nullptr;--count;return t;}
bool PriorityQueue::IsEmpty()const{return front==nullptr;}bool PriorityQueue::IsNotEmpty()const{return front!=nullptr;}
void PriorityQueue::PrintQueue()const{if(IsEmpty()){std::cout<<"No pending stock orders.\n";return;}for(OrderNode*p=front;p;p=p->next)std::cout<<"\nOrder ID: "<<p->orderID<<"\nInvestor: "<<p->investorName<<"\nStock Symbol: "<<p->stockSymbol<<"\nOrder Type: "<<p->orderType<<"\nQuantity: "<<p->quantity<<"\nPriority: "<<p->priority<<"\n-----------------------------\n";}
PriorityQueue::~PriorityQueue(){while(front){OrderNode*t=front;front=front->next;delete t;}rear=nullptr;}
OrderList::OrderList():head(nullptr),count(0){}
OrderListNode* OrderList::GetNodeAt(int i)const{if(i<0||i>=count)return nullptr;OrderListNode*p=head;while(i--)p=p->next;return p;}
void OrderList::Clear(){while(head){OrderListNode*t=head;head=head->next;delete t;}count=0;}
OrderList::OrderList(const OrderList&o):head(nullptr),count(0){for(OrderListNode*p=o.head;p;p=p->next){OrderListNode*n=new OrderListNode{p->orderID,p->investorName,p->stockSymbol,p->orderType,p->quantity,p->priority,nullptr};InsertAt(n,count);}}
OrderList& OrderList::operator=(const OrderList&o){if(this==&o)return *this;Clear();for(OrderListNode*p=o.head;p;p=p->next){OrderListNode*n=new OrderListNode{p->orderID,p->investorName,p->stockSymbol,p->orderType,p->quantity,p->priority,nullptr};InsertAt(n,count);}return *this;}
OrderList::~OrderList(){Clear();}
void OrderList::Insert(OrderListNode*o){if(!o)return;o->next=head;head=o;++count;}
OrderListNode* OrderList::Remove(){if(!head)return nullptr;OrderListNode*t=head;head=head->next;t->next=nullptr;--count;return t;}
void OrderList::InsertAt(OrderListNode*o,int i){if(!o)return;if(i<0)i=0;if(i>count)i=count;if(i==0){Insert(o);return;}OrderListNode*p=GetNodeAt(i-1);o->next=p->next;p->next=o;++count;}
OrderListNode* OrderList::RemoveAt(int i){if(i<0||i>=count)return nullptr;if(i==0)return Remove();OrderListNode*p=GetNodeAt(i-1);OrderListNode*t=p->next;p->next=t->next;t->next=nullptr;--count;return t;}
bool OrderList::Swap(int a,int b){if(a<0||a>=count||b<0||b>=count)return false;if(a==b)return true;OrderListNode*x=GetNodeAt(a),*y=GetNodeAt(b);std::swap(x->orderID,y->orderID);std::swap(x->investorName,y->investorName);std::swap(x->stockSymbol,y->stockSymbol);std::swap(x->orderType,y->orderType);std::swap(x->quantity,y->quantity);std::swap(x->priority,y->priority);return true;}
void OrderList::Sort(){for(OrderListNode*i=head;i;i=i->next)for(OrderListNode*j=i->next;j;j=j->next)if(i->orderID>j->orderID){std::swap(i->orderID,j->orderID);std::swap(i->investorName,j->investorName);std::swap(i->stockSymbol,j->stockSymbol);std::swap(i->orderType,j->orderType);std::swap(i->quantity,j->quantity);std::swap(i->priority,j->priority);}}
void OrderList::Reverse(){OrderListNode*prev=nullptr,*cur=head;while(cur){OrderListNode*n=cur->next;cur->next=prev;prev=cur;cur=n;}head=prev;}
void OrderList::Print()const{if(IsEmpty()){std::cout<<"No orders in the linked-list collection.\n";return;}int i=0;for(OrderListNode*p=head;p;p=p->next)std::cout<<"\nIndex: "<<i++<<"\nOrder ID: "<<p->orderID<<"\nInvestor: "<<p->investorName<<"\nStock Symbol: "<<p->stockSymbol<<"\nOrder Type: "<<p->orderType<<"\nQuantity: "<<p->quantity<<"\nPriority: "<<p->priority<<"\n-----------------------------\n";std::cout<<"Total orders: "<<count<<'\n';}
bool OrderList::IsEmpty()const{return head==nullptr;}bool OrderList::IsNotEmpty()const{return head!=nullptr;}int OrderList::Size()const{return count;}
OrderListNode* CreateOrder(const OrderNode&o){return new OrderListNode{o.orderID,o.investorName,o.stockSymbol,o.orderType,o.quantity,o.priority,nullptr};}
