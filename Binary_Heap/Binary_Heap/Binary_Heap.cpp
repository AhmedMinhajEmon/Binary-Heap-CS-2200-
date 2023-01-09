
// Lab 7: 
// Priority Queue: Binary Heap, Imeplementaion of Emergency System
// 
// Given the startup project with a basic binary heap implementation, implement the following emergency system tasks:
// Note: The implementation supports both digits and strings, you do not have to use both, just use one type
// 
// Implement an Emergency System Record, where each element (patient) is entered into the priority queue, is assigned the following attributes:
// 1- patient's Name, Admission Date & Time
// 2- Criticality level
// 3- Anticipated Departure time
// 4- Assigned Emergency Physician 
// 5- Periodically, pull out most critical condition from the queue
// 6- Once the treatment is received (simply when the patient is removed from critical queue), he/she will be entered into a end of day array
// 7- Data in the End of day array record will be automatically sorted (need to verify and highlight in the report)
// 
//


#include <iostream>
#include <sstream>
#include <string>
#include "BinaryHeap.h"
using namespace std;

class record {
public:
    int criticality;
    char name[10];
    string Name, Dr_name, date, departure;
    record(){}
    record(int criticality, string name, string Dr_name, string date, string departure) {
        this->criticality = criticality;
        this->Name = name;
        this->date = date;
        this->Dr_name = Dr_name;
        this->departure = departure;
    }
    void print_info() {
        cout << "Name: " << Name << endl;
        cout << "Doctor's Name: " << Dr_name << endl;
        cout << "Crticality level: " << criticality << endl;
        cout << "Date: " << date << endl;
        cout << "Anticipated Departure: " << departure << endl;
    }
    int getCriticality() {
        return criticality;

    }
};

// Test program
int main()
{

    // Two heaps: string & int heaps
    BinaryHeap<string> h1;
    BinaryHeap<int>    h2;
    record l_1[10];
    record p_0(12, "Ahmed Minhaj", "Pr. X", "12/8/2022", "12/8/2022-9.00 PM");
    l_1[0] = p_0;
    record p_1(17, "Ahmed Wasif", "Pr.y", "12/9/2022", "12/9/2022-9.00 PM");
    l_1[1] = p_1;
    record p_2(8, "Abdul Bari", "Pr. Z", "12/10/2022", "12/10/2022-1.00 PM");
    l_1[2] = p_2;
    record p_3(1, "Md. Kamal", "Pr. A", "12/20/2022", "12/21/2022-10.00 PM");
    l_1[3] = p_3;


    h2.insert(l_1[0].criticality);
    h2.insert(l_1[1].criticality);
    h2.insert(l_1[2].criticality);
    h2.insert(l_1[3].criticality);
  



    cout << "Begin test... " << endl;
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            if (h2.findMin() == l_1[i].criticality) { l_1[i].print_info(); break; }
        }
        h2.deleteMin();
        cout << endl;
        cout << endl;
    }


    cout << "End test... added and deleted some heap entries entries" << endl;
    return 0;
}
