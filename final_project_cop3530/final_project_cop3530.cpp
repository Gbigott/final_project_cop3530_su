#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

struct RecordsOfHomes
{
    RecordsOfHomes (int rooms_beds,int prices,string city)
    {
        Room = rooms_beds;

    }

    int Room;
    int Prices;
    string City;

  
};

int main()
{
    ifstream infile;
    vector<RecordsOfHomes> info;
    infile.open("housing.csv");
    
    if(!(infile.is_open()))
    {
        cout << "not file detected" << endl;
    }
    else
    {
        string s;
        string temp;
        cout << " processing info..." << endl;

        while(getline(infile,s)){
            //temp = s.substr(1);
            string ids;
            string url;
            string region;
            string region_url;
            int price;
            string type;
            string sq_feet;
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

            getline(inputString,ids,',');
            getline(inputString,url,',');
            getline(inputString,region,',');
            getline(inputString,region_url,',');
            getline(inputString,temp,',');
            price = atoi(temp.c_str());
            getline(inputString,type,',');
            getline(inputString,sq_feet,',');
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

            RecordsOfHomes records(beds, price, region);

            info.push_back(records);

             
             
        }
        infile.close();

        
    }
    
    
    cout<<"Welcome to our housing search app! please choose your search method:"<<endl;
    cout<<"1.search by room count"<<endl;
    cout<<"2.search by area"<<endl;

    int selectOption;

    cin>>selectOption;

    if(selectOption == 1)
    {
        cout<<"please select the minimum number of rooms to search for:"<<endl;

    }



    return 0;
}