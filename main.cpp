// This program can divide an array/vector into different pieces while keeping the first&last 2 elements fixed

#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned pieces = 8;

    vector<unsigned> myArray;

    for(unsigned i =0 ; i<180;i++){
        myArray.push_back(i);
    }

    unsigned vectorSize = myArray.size();

    unsigned chunk = (vectorSize-4) / pieces;

    unsigned bonus = (vectorSize-4) % pieces;

    cout<<"chuck: "<<chunk<<endl;
    cout<<"bonus: "<<bonus<<endl;

    vector<unsigned> bounds;

    for(unsigned lastBound = 2;lastBound<vectorSize-3; lastBound+=chunk){
        bounds.push_back(lastBound);

        if(bonus){
            bonus--;
            lastBound++;
        }
    }
    bounds.push_back(vectorSize-3);

    for(unsigned j = 0 ; j<bounds.size();j++){
        cout<<bounds[j]<<" ";
    }
    cout<<endl;

    for(unsigned i = 0; i<bounds.size()-1;i++){
        cout<<bounds[i]<<"->"<<bounds[i+1]<<": ";
        for(unsigned j = bounds[i];j<bounds[i+1];j++){
            cout<<myArray[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}