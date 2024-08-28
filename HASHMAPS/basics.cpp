#include<iostream>
#include<map>
#include<unordered_map>
#include<pair>
using namespace std;


int main()
{
	unordered_map<string, int> m;
	//INSERTION
	//1st way
	pair<string, int> p = make_pair("Adina", 1);
	m.insert(p);
	
	//2nd way
	pair<string, int> pair2("hello", 2);
	m.insert(pair2);
	
	//3rd way
	m["Faraz"] = 4;		//creation of faraz pair
	m["Faraz"] = 9;		//updation of faraz pair
	
	//SEARCH
	cout<<m["Adina"]<<endl;
	cout<<m.at("Faraz")<<endl;
	
	//size
	cout<<m.size()<<endl;
	
	//to check presence
	cout<<m.count("Adina")<<endl;		//returns the presence of a value, is bool type
	cout<<m.count("bro")<<endl;
	
	//erase
	m.erase("Adina");
	cout<<m.size()<<endl;
	
	//accessing the map
	//thru iterator
	unordered_map<string, int> :: iterator it = m.begin();
	
	while(it != m.end())
	{
		cout<<it->first<<" "<<it->second<<endl;
		it++;
	}
	
	return 0;
}
