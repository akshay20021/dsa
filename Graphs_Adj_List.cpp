// Question no.10
#include <bits\stdc++.h>
using namespace std;
#define MAX 10
class Graph
{
public:
  vector<int> adjLst[MAX];
  int no_of_cities;
  string *cities;

  Graph(int no_of_cities)
  {
    this->no_of_cities = no_of_cities;
    cities = new string[no_of_cities];

    // for(int i=0;i<no_of_cities)
    // {
    //   adjLst[i]=0;
    // }
  }

  void read()
  {
    for (int i = 0; i < no_of_cities; i++)
    {
      string city;
      cout << "Enter the " + to_string(i) + " number city: ";
      cin >> city;
      cities[i] = city;
    }

    for (int i = 0; i < no_of_cities; i++)
    {
      for (int j = 0; j < no_of_cities; j++)
      {
        if (i != j)
        {
          int cost;
          cout << "Enter the cost to travel from city " + cities[i] + " to " + cities[j] + ": ";
          cin >> cost;
          adjLst[i].push_back(cost);
          adjLst[j].push_back(cost);
        }
      }
    }
  }

  void display()
  {
    cout << "The Adjacency List is: " << endl;
    for (int i = 0; i < no_of_cities; i++)
    {
      cout << "List no:- " << cities[i] << "->";
      vector<int>::iterator it;
      for (it = adjLst[i].begin(); it != adjLst[i].end(); it++)
      {
        cout << *it << " ";
      }
      cout << endl;
    }
  }

  // void Check_path(string source, string destination)
  // {
  //   int s;
  //   int d;
  //   for (int i = 0; i < no_of_cities; i++)
  //   {
  //     if (cities[i] == source)
  //     {
  //       s = i;
  //       break;
  //     }
  //   }

  //   for (int i = 0; i < no_of_cities; i++)
  //   {
  //     if (cities[i] == destination)
  //     {
  //       d = i;
  //       break;
  //     }
  //   }
  //   for (int i = 0; i < no_of_cities; i++)
  //   {
  //     vector<int>::iterator it;
  //     for (it = adjLst[i].begin(); it != adjLst[i].end(); it++)
  //     {
  //       if (it == s)
  //       {
  //         it = s;
  //         cout << "The cost to travel from the city " + source + " to city " + destination + " is: " << endl;
  //         break;
  //       }
  //       else
  //       {
  //         cout<<"There  is no path present."<<endl;
  //         break;
  //       }
  //     }
  //   }
  // }

  void is_connected(int source, vector<bool> &visited)
  {
    visited[source]=true;
    for(int i=0;i<no_of_cities;i++)
    {
      vector<int>:: iterator it;
      for(it=adjLst[i].begin();it!=adjLst[i].end();it++)
      {
        if(*it!=0 and visited[i]!=true)
        {
          is_connected(i,visited);
        }
      }
    }
  }
};

int main()
{
  int no_of_cities;
  cout << "Enter total number of cities: ";
  cin >> no_of_cities;
  Graph g(no_of_cities);
  g.read();
  g.display();
  // g.Check_path("Pune", "Mumbai");
  vector<bool> visited(no_of_cities);
  for(int i=0;i<no_of_cities;i++)
  {

    visited[i]=false;
  }
  bool flag = true;
  g.is_connected(0,visited);
  for (int i = 0; i < no_of_cities; i++)
  {
    if (visited[i] == false)
    {
      flag = false;
      break;
    }
  }
  if (flag == true)
  {
    cout << "The graph is connected" << endl;
  }
  else
  {
    cout << "The Graph is not connected." << endl;
  }
}