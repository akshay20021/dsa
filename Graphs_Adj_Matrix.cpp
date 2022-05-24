// Question no.9
#include <bits\stdc++.h>
using namespace std;
#define MAX 10
class Graph
{
public:
  int AdjMat[MAX][MAX]; // --> Delcaration of Adjacency Matrix
  int no_of_cities;
  string *cities;

  Graph(int no_of_cities)
  {
    this->no_of_cities = no_of_cities;
    cities = new string[no_of_cities]; // --> Creating an dynamic array for citites.
    for (int i = 0; i < MAX; i++)
    {
      for (int j = 0; j < MAX; j++)
      {
        AdjMat[i][j] = 0; // Initializing the Adjacent Matrix with 0.
      }
    }
  }

  void read() // --> Taking input for Adjacency Matrix
  {
    for (int i = 0; i < no_of_cities; i++)
    {
      string city;
      cout << "Enter the " + to_string(i) + " number city here: ";
      // Here, "to_string(i)" will convert the integer to string.
      cin >> city;
      cities[i] = city;
    }

    for (int i = 0; i < no_of_cities; i++)
    {
      for (int j = 0; j < no_of_cities; j++)
      {
        if (i != j) // --> Here, it means that for any city should not be any self loop i.e (the source city is same as the destination city).
        {
          int cost;
          cout << "Enter the cost to travel from city " + cities[i] + " to " + cities[j] + ": ";
          cin >> cost;
          AdjMat[i][j] = cost;
        }
      }
    }
  }

  void display()
  {
    cout << "The adjacency Matrix is: " << endl;
    for (int i = 0; i < no_of_cities; i++)
    {
      for (int j = 0; j < no_of_cities; j++)
      {
        cout << AdjMat[i][j] << " ";
      }
      cout << endl;
    }
  }
  void check_path(string source, string destination)
  {
    int s;
    int d;
    for (int i = 0; i < no_of_cities; i++)
    {
      if (cities[i] == source) // Here, if the city at i'th value is same as the source city then we will store the source city's location i.e (i value) in the variable "s" and then break the loop.
      {
        s = i;
        break;
      }
    }
    for (int i = 0; i < no_of_cities; i++) // Here, if the city at i'th value is same as the destination city then we will store the destination city's location i.e (i value) in the variable "d" and then break the loop.
    {
      if (cities[i] == destination)
      {
        d = i;
        break;
      }
    }
    if (AdjMat[s][d])
    // Here, we will check whether a path is present between the source city and the destination.
    // Here, "s" refers to the lication of the source city in the Adjacent Matrix.
    // Here, "d" refers to the location of the destination city in the Adjaceny Matrix.
    {
      cout << "The cost to travel from the city " + source + " to city " + destination + " is: " + to_string(AdjMat[s][d]);
    }
    else
    {
      cout << "There is no path from city " + source + " to city " + destination << "\n";
    }
  }

  void is_connected(int source, vector<bool> &visited)
  {
    visited[source] = true;
    for (int i = 0; i < no_of_cities; i++)
    {
      if (AdjMat[source][i] != 0 and visited[i] != true)
      {
        is_connected(i, visited);
      }
    }
  }
};

int main()
{
  cout << "Enter total no of cities: ";
  int no_of_cities;
  cin >> no_of_cities;

  Graph g(no_of_cities);
  g.read();
  g.display();
  g.check_path("Pune", "Chennai");

  vector<bool> visited(no_of_cities);
  for (int i = 0; i < no_of_cities; i++)
  {
    visited[i] = false;
  }
  g.is_connected(0, visited);
  bool flag = true;
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