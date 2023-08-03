#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include <algorithm>  
#include<map>

using namespace std;

struct RecordsOfHomes
{
    RecordsOfHomes ( double ids,int rooms_beds,int prices,string city)
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

bool operator <(const RecordsOfHomes& i, const RecordsOfHomes& j)
{
    return i.IDS < j.IDS;
}

void printVec(vector<RecordsOfHomes> row) {
    
    for (int i = 0; i < 10; i++) {
        cout << row[i].IDS <<" "<<row[i].City<<" "<<row[i].Prices<<" "<<row[i].Room<<endl;
    }
}
vector<RecordsOfHomes> insert_on_heap(vector<RecordsOfHomes>& info)
{
  vector<RecordsOfHomes> temp = info;
 make_heap (info.begin(),info.end());

 return temp;

}

vector<RecordsOfHomes> Read_file(string in_file)
{
    ifstream infile;
    vector<RecordsOfHomes> saved_info;
    infile.open(in_file);
    
    if(!(infile.is_open()))
    {
        cout << "not file detected" << endl;
    }
    else
    {
        string s;
        
        cout << " processing info..." << endl;
        getline(infile, s);

        while(getline(infile,s)){
            double ids;
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

            getline(inputString,temp,',');
            ids = atof(temp.c_str());
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

            RecordsOfHomes records(ids,beds, price, region);

            saved_info.push_back(records);

             
             
        }
        infile.close();



        
    }

    return saved_info;

}
int main()
{
    
    vector<RecordsOfHomes> info;
    string file = "housing.csv";
    info = Read_file("housing.csv");
    
    
    cout<<"Welcome to our housing search app! please choose your search method:"<<endl;
    cout<<"1.search by room count"<<endl;
    cout<<"2.search by area"<<endl;
    
    int selectOption;
    cin>>selectOption;

    if(selectOption == 1)
    {
        int selection_op;
        cout<<"1. Use maps"<<endl;
        cout<<"2.Use maxheap"<<endl;
        cin>>selection_op;

        if(selection_op == 1)
        {
            //insert your map function here.
            cout<<"please select the minimum number of rooms to search for:"<<endl;
        }
        else if(selection_op == 2)
        {
            vector<RecordsOfHomes> insertheap = insert_on_heap(info);

            printVec(insertheap);


            cout<<"please select the minimum number of rooms to search for:"<<endl;

        }
        

       

    }
    else if(selectOption == 2)
    {
        int selection_op;
        cout<<"1. Use maps"<<endl;
        cout<<"2.Use minheap"<<endl;
        cin>>selection_op;

        if(selection_op == 1)
        {
            //insert your map function here.
            cout<<"please enter the name of the city you looking for:"<<endl;
            string city_name;
            cin >> city_name;

        }
        else if(selection_op == 2)
        {
            cout<<"please select the minimum number of rooms to search for:"<<endl;
             string city_name;
             cin >> city_name;
        }
    }



    return 0;
}