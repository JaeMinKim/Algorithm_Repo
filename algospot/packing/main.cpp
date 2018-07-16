// https://algospot.com/judge/problem/read/PACKING

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Item {
    private:
    string name;
    int needs;
    int volume;

    public:
    Item(string _name, int _vol, int _needs) : name(_name), needs(_needs), volume(_vol) {}
    string getName(void) { return name; }
    int getNeeds(void) { return needs; }
    int getVol(void) {return volume; }
};

struct ItemCmp {
    bool operator()(Item a, Item b) {
        return a.getNeeds() < b.getNeeds();
    }
};

int main(void)
{
    priority_queue<Item, vector<Item>, ItemCmp> pq;
    int itemCnt;
    int maxVol;
    int resultNeeds;

    cin>> itemCnt;
    cin>> maxVol;

    while(itemCnt--) {
        string tmpName;
        int tmpVol;
        int tmpNeeds;

        cin>> tmpName;
        cin>> tmpVol;
        cin>> tmpNeeds;

        pq.push(Item(tmpName, tmpVol, tmpNeeds));
    }

    Item item = pq.top();
    cout<< item.getName();

    return 0;
}

/*
6 10
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4
*/