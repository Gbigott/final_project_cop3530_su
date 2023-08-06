#include "ordered_map.h"
using namespace std;

void OrderedMap::AddHeadHelper(RecordsOfHomes& target, RecordsOfHomes* loc, bool isArea) {
    if(loc == nullptr)
        return;
    int mainValue;
    if(isArea) {
        mainValue = target.SqFeet;
        if(loc->SqFeet < mainValue) { // Put largest areas first
            if(loc->Lptr == nullptr)
                loc->Lptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else
                AddHeadHelper(target, loc->Lptr, isArea);
        }
        else if(loc->SqFeet > mainValue) {
            if(loc->Rptr == nullptr)
                loc->Rptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else
                AddHeadHelper(target, loc->Rptr, isArea);
        }
        else { // If areas are equal, try to fill the first nullptr if available
            if(loc->Rptr == nullptr)
                loc->Rptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else if(loc->Lptr == nullptr)
                loc->Lptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else
                AddHeadHelper(target, loc->Lptr, isArea);
        }
            
    }
    else {
        mainValue = target.Prices;
        if(loc->Prices > mainValue) { // Put smallest prices first
            if(loc->Lptr == nullptr)
                loc->Lptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else
                AddHeadHelper(target, loc->Lptr, isArea);
        }
        else if(loc->Prices < mainValue) {
            if(loc->Rptr == nullptr)
                loc->Rptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else
                AddHeadHelper(target, loc->Rptr, isArea);
        }
        else { // If prices are equal, try to fill the first nullptr if available
            if(loc->Rptr == nullptr)
                loc->Rptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else if(loc->Lptr == nullptr)
                loc->Lptr = new RecordsOfHomes(target.IDS, target.Room, target.Prices, target.City, target.SqFeet);
            else
                AddHeadHelper(target, loc->Lptr, isArea);
        }
    }
}

void OrderedMap::AddHead(double ids, int rooms_beds, int prices, string city, int sqfeet) {
    if(head1 == nullptr) {
        head1 = new RecordsOfHomes(ids, rooms_beds, prices, city, sqfeet);
        //head2 = new RecordsOfHomes(ids, rooms_beds, prices, city, sqfeet);
        return;
    }
    RecordsOfHomes target (ids, rooms_beds, prices, city, sqfeet);
    AddHeadHelper(target, head1, 0);
    //AddHeadHelper(target, head2, 1);
}

void OrderedMap::InOrderHelper(vector<RecordsOfHomes>& target, RecordsOfHomes* loc, string sortCity, int minBeds) {
    if(loc == nullptr)
        return;
    // Left
    if(loc->Lptr != nullptr)
        InOrderHelper(target, loc->Lptr, sortCity, minBeds);
    if(target.size() >= 10)
        return;
    // Self
    if((loc->City == sortCity or sortCity == "") and loc->Room >= minBeds){
        RecordsOfHomes tempRecordsOfHomes = RecordsOfHomes(loc->IDS, loc->Room, loc->Prices, loc->City, loc->SqFeet);
        target.push_back(tempRecordsOfHomes);
    }
    if(target.size() >= 10)
        return;
    // Right
    if(loc->Rptr != nullptr)
        InOrderHelper(target, loc->Rptr, sortCity, minBeds);
    
}

vector<RecordsOfHomes> OrderedMap::InOrder(bool isArea, string sortCity, int minBeds) {
    vector<RecordsOfHomes> target;
    if(!isArea) {
        InOrderHelper(target, head1, sortCity, minBeds);
    }
    else
        InOrderHelper(target, head2, sortCity, minBeds);
    return target;
    
}
