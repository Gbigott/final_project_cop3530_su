#pragma once
#include <string>
#include <vector>
using namespace std;

// structure that contains all the information that we filter from the csv file
struct RecordsOfHomes
{
    int Room;
    int Prices;
    int SqFeet;
    double IDS;
    string City;
    RecordsOfHomes* Lptr = nullptr;
    RecordsOfHomes* Rptr = nullptr;
    RecordsOfHomes(double ids, int rooms_beds, int prices, string city, int sqfeet) : IDS{ids}, Room{rooms_beds}, Prices{prices}, City{city}, SqFeet(sqfeet) {}    
};

class OrderedMap
{
private:
    RecordsOfHomes* head1 = nullptr; // Sort prices
    RecordsOfHomes* head2 = nullptr; // Sort area
    void AddHeadHelper(RecordsOfHomes& target, RecordsOfHomes* loc, bool isArea);
    void InOrderHelper(vector<RecordsOfHomes>& target, RecordsOfHomes* loc, string sortCity, int minBeds);
    
public:
    void AddHead(double ids, int rooms_beds, int prices, string city, int sqfeet);
    vector<RecordsOfHomes> InOrder(bool isArea, string sortCity, int minBeds);
};
