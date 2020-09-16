#include <iostream>
#include <set>



int main () {
    
    std::set<int> myset= {8,1, 2,5};  
    std::set<int>::iterator it;  

    std::cout<<"Before erasing the element: \n";  
    for (it=myset.begin(); it!=myset.end(); ++it) {
        std::cout << *it << '\n';  
    }
        
    it=myset.begin();
    int element=  *it;
    myset.erase(it);

    std::cout<<"After  erasing " <<  element << " the initial element: \n";  
    for (it=myset.begin(); it!=myset.end(); ++it) {
        std::cout << *it << '\n';  
    }

    it=myset.begin();
    element=  *it;
    myset.erase(it);

    // coping a set into other set
    std::set<int> rest = myset; 

    std::cout<<"After  erasing " <<  element << " the initial element: \n";  
    for (it= rest.begin(); it!= rest.end(); ++it) {
        std::cout << *it << '\n';  
    }


    return 0;
}

