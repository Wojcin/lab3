#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Slav.h"


printf("# Containers\n");
REPORT_CONTAINERS;
printf("## vector\n");


// Umieść Słowian w losowej kolejności w wektorze.

vectorOfSlavs.push_back(&slavs[0]);
 	
for(int i=0; i<n; i++) 
{
    int position = rand() % vectorOfSlavs.size();
    vectorOfSlavs.insert(vectorOfSlavs.begin()+position,&slavs[i]);
}

// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
 
 vector<Slav*>::iterator it = vectorOfSlavs.begin();
 vector<Slav*>::iterator end = vectorOfSlavs.end();
 	
while(it != end)
{
    cout << (*it)->description() << endl;
    it++;
}


REPORT_CONTAINERS;
printf("## set\n");

// Przenieś wszystkich Słowian z wektoru do zbioru.

for(int i=0; i<n; i++) 
{
    setOfSlavs.insert(vectorOfSlavs[i]);
}	
vectorOfSlavs.clear();

REPORT_CONTAINERS;
printf("## map\n");

// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór

set< Slav *>::iterator it_setOfSlavs = setOfSlavs.begin();


	
for(;it_setOfSlavs!=setOfSlavs.end();it_setOfSlavs=setOfSlavs.erase(it_setOfSlavs)) 
{
    mapOfSlavs[*it_setOfSlavs]=*(it_setOfSlavs=setOfSlavs.erase(it_setOfSlavs));
}

// Wykorzystując iterator, wyświetl wszystkie pary Słowian

for (map<Slav *, Slav *>::iterator it=mapOfSlavs.begin(); it!=mapOfSlavs.end(); it++)
{
    cout<<it->first->description()<<"  =>  "<<it->second->description()<<endl;
}
    
REPORT_CONTAINERS;
}

printf("## queue\n");

// Umieść Słowian w kolejce.

for (int i = 0; i<n; i++)
{
queueOfSlavs.push(&slavs[i]);
}

REPORT_ADAPTERS;

printf("## stack\n");

// Przenieś Słowian z kolejki do stosu.

while(!queueOfSlavs.empty()) 
{
    stackOfSlavs.push(queueOfSlavs.front());
    queueOfSlavs.pop();
}
 REPORT_ADAPTERS;

// Wyświetl Słowian zdejmowanych ze stosu.
 
while (!stackOfSlavs.empty())
{
    cout<<(*(stackOfSlavs.top())).description()<<endl;
    stackOfSlavs.pop();
}

	REPORT_ADAPTERS;
}
 