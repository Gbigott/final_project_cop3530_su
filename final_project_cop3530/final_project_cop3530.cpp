#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>  
#include <map>
#include "ordered_map.h"
#include <iomanip>

using namespace std;

// structure that contains all the information that we filter from the csv file
struct RecordsOfHomes
{
    RecordsOfHomes (double ids,int rooms_beds,int prices,string city)
    {
        IDS = ids;
        Room = rooms_beds;
        Prices = prices;
        City = city;


    }

    int Room;
    int Prices;
    double IDS;
    string City;

  
};
// this is a helper operator that i use for the make_heap function from algorimth library (not necesary, will be erase later)
// bool operator <(const RecordsOfHomes& i, const RecordsOfHomes& j)
// {
//     return i.IDS < j.IDS;
// }

//helper function for printing the heapmax vector.
void printVec(vector<RecordsOfHomes> row) {
    
    for (int i = 0; i < 10; i++) {
        cout.precision(17);
        cout << row[i].IDS <<" "<<row[i].City<<" "<<row[i].Prices<<" "<<row[i].Room<<endl;
    }
}

// void printVec(vector<int> row) {

//     for (int i = 0; i < row.size(); i++) {
//         cout << row[i] <<"  ";
//     }
// }

vector<RecordsOfHomes> Read_file(string in_file, OrderedMap &map)
{
    ifstream infile;
    vector<RecordsOfHomes> saved_info;
    infile.open(in_file);
    
    if(!(infile.is_open()))
    {
        cout << "Warning: no file detected" << endl;
    }
    else
    {
        string s;
        
        cout << "Processing info..." << endl;
        getline(infile, s);

        while(getline(infile,s)){
            double ids;
            string url;
            string region;
            string region_url;
            int price;
            string type;
            string sq_feet_temp;
            int sq_feet;
            int beds;
            string baths;
            string cats_allow;
            string dogs_allow;
            string smoking_allow;
            string wheelschair;
            string electric_car;
            string furniture;
            string laundry_option;
            string parking_options;
            string image_url;
            string description;
            string lat;
            string long_s;
            string state;
            string temp = "";

            stringstream inputString(s);

            getline(inputString,temp,',');
            ids = atof(temp.c_str());
            getline(inputString,url,',');
            getline(inputString,region,',');
            getline(inputString,region_url,',');
            getline(inputString,temp,',');
            price = atoi(temp.c_str());
            getline(inputString,type,',');
            getline(inputString,sq_feet_temp,',');
            sq_feet = atoi(sq_feet_temp.c_str());
            getline(inputString,temp,',');
            beds = atoi(temp.c_str());
            getline(inputString,baths,',');
            getline(inputString,cats_allow,',');
            getline(inputString,dogs_allow,',');
            getline(inputString,smoking_allow,',');
            getline(inputString,wheelschair,',');
            getline(inputString,electric_car,',');
            getline(inputString,furniture,',');
            getline(inputString,laundry_option,',');
            getline(inputString,parking_options,',');
            getline(inputString,description,',');
            getline(inputString,lat,',');
            getline(inputString,long_s,',');
            getline(inputString,state,',');

            RecordsOfHomes records(ids,beds, price, region);

            saved_info.push_back(records);
            map.AddHead(ids, beds, price, region, sq_feet);
             
             
        }
        infile.close();



        
    }

    return saved_info;

}

// helper function for the creation of max heap
 void heapify_down(vector<RecordsOfHomes>& info,double n,double i)
 {
    double smallest = i; 
    
    double l = 2 * i + 1; 
    double r = 2 * i + 2; 

    if (l < n && info[l].IDS > info[smallest].IDS)
    smallest = l;

    if (r < n && info[r].IDS > info[smallest].IDS)
    smallest = r;

    if (smallest != i) {
    RecordsOfHomes temp = info[i];
    info[i] = info[smallest];
    info[smallest] = temp;

    heapify_down(info, n, smallest);

        

    }
 }

// function creates the heap
 vector<RecordsOfHomes> insert_on_heap(vector<RecordsOfHomes>& info)
{
    vector<RecordsOfHomes> temp = info;

    double starting_point = ((temp.size())/2)-1;

    for(double i = starting_point ;i>=0; i--)
    {
        heapify_down(temp,temp.size(),i);
    }


 return temp;

}
   
int main()
{
    
    vector<RecordsOfHomes> info;
    //string file = "housing.csv";
    OrderedMap map;
    info = Read_file("housing.csv", map);
    
    
    cout<<"Welcome to our housing search app! please choose your search method:"<<endl;
    cout<<"1.search by room count"<<endl;
    cout<<"2.search by area"<<endl;
    
    int selectOption;
    cin>>selectOption;

    //for search by count of beds.
    if(selectOption == 1)
    {
        int selection_op;
        cout<<"1. Use maps"<<endl;
        cout<<"2. Use maxheap"<<endl;
        cin>>selection_op;

        if(selection_op == 1)
        {
            cout<<"Please select the minimum number of beds to search for:"<<endl;
            int minbeds;
            cin >> minbeds;
            cout<<"Please enter the name of the city you looking for:"<<endl;
            string city_name;
            cin >> city_name;
            vector<Node> result = map.InOrder(0, city_name, minbeds);
            if(result.size() == 0) {
                cout << "No matching houses found" << endl;
            } else {
            cout << "Houses with at least " << minbeds << " beds:" << endl;
            cout << setw(6) << "Rooms" << setw(10) << "Price" << setw(20) << "City" << setw(10) << "Area" << endl;
            for(unsigned int i = 0; i < result.size(); i++) {
                cout << "  " << result.at(i).Room << "   $" << setw(9) << result.at(i).Prices << setw(20) << result.at(i).City << setw(10) << result.at(i).SqFeet << endl;
            }
            // in this case you can add an if statement that compares the input number of beds you are looking for. if it appears.
            // it will return every aparment in that city from the map
            // if not it just return a message of not found
            }
        }
        else if(selection_op == 2)
        {
           vector<RecordsOfHomes> insertheap = insert_on_heap(info);
           // vector<int> insertheap = insert_on_heap(info);
           // printVec(insertheap);

            // in this case you can add an if statement that compares the input with the number of beds you are looking for. if it appears.
            // it will return every aparment in that city from the maxheap.
            // if not it just return a message of not found.


            cout<<"Please select the minimum number of beds to search for:"<<endl;

        }
        
    }
    //for searching by  area.
    else if(selectOption == 2)
    {
        int selection_op;
        cout<<"1. Use maps"<<endl;
        cout<<"2. Use minheap"<<endl;
        cin>>selection_op;

        if(selection_op == 1)
        {
            cout<<"Please enter the name of the city you looking for:"<<endl;
            string city_name;
            cin >> city_name;
            vector<Node> result = map.InOrder(1, city_name, 0);
            if(result.size() == 0) {
                cout << "Not found" << endl;
            } else {
            cout << "Houses in " << city_name << " by area: " << endl;
            cout << setw(6) << "Rooms" << setw(10) << "Price" << setw(20) << "City" << setw(10) << "Area" << endl;
            for(unsigned int i = 0; i < result.size(); i++) {
                cout << "  " << result.at(i).Room << "   $" << setw(9) << result.at(i).Prices << setw(20) << result.at(i).City << setw(10) << result.at(i).SqFeet << endl;
            }
            // in this case you can add an if statement that compares the input with the name of the city. if it appears.
            // it will return every aparment in that city from the map
            // if not it just return a message of not found
            }
        }
        else if(selection_op == 2)
        {
            // in this case you can add an if statement that compares the input with the name of the city. if it appears.
            // it will return every aparment in that city from the heap.
            // if not it just return a message of not found.
            cout<<"Please enter the name of the city you looking for:"<<endl;
             string city_name;
             cin >> city_name;
        }
    }
    
    return 0;
}
