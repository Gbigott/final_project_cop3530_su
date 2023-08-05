#pragma once
#include <string>
#include <vector>
using namespace std;

struct Node
{
    int Room;
    int Prices;
    int SqFeet;
    double IDS;
    string City;
    Node* Lptr = nullptr;
    Node* Rptr = nullptr;
    Node(double ids, int rooms_beds, int prices, string city, int sqfeet) : IDS{ids}, Room{rooms_beds}, Prices{prices}, City{city}, SqFeet(sqfeet) {}    
};

class OrderedMap
{
private:
    Node* head1 = nullptr; // Sort prices
    Node* head2 = nullptr; // Sort area
    void AddHeadHelper(Node& target, Node* loc, bool isArea);
    void InOrderHelper(vector<Node>& target, Node* loc, string sortCity, int minBeds);
    
public:
    void AddHead(double ids, int rooms_beds, int prices, string city, int sqfeet);
    vector<Node> InOrder(bool isArea, string sortCity, int minBeds);
    
    
    
};
