#include<iostream>
using namespace std;
class list_element{
    public:
        int d;
        list_element* next;
        list_element(int n=0, list_element* ptr = 0):d(n), next(ptr){}
};

ostream& operator<< (ostream& out, list_element* el){
    out<<el->d;
    return out;
}

class list{
    public:
    list():head(0),cursor(0){}
    int get_element(){
        return cursor->d;
    }
    void prepend(int n){
        if(head == 0){
            cursor = head = new list_element(n,head);
        }else{
            head = new list_element(n,head);
        }
    }
    void advance(){cursor = cursor->next;}

    void print(){
        list_element* h = head;
        while(h!=0){
            cout<<h<<", ";
            h = h->next;
        }
        cout<<"###"<<endl;
    }
    
    private:
        list_element* head;
        list_element* cursor;
    
};

int main(){
    list l;
    l.prepend(0);
    l.prepend(3);
    l.prepend(0);
    l.prepend(1);
    l.print();
}