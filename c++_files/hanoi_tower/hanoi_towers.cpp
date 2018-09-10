#include <iostream>
#include <deque>

using namespace std;

void move_disk(deque<int>& from, deque<int>& to){
    to.push_front(from.front());
    from.pop_front();
}

void hanoi_tower(deque<int>& from, deque<int>& to) {
    if( from.size() == 1) {
        move_disk(from, to);
    }
    if ( from.size() > 1) {
        deque<int> aux;
        int tempValue = from.back();
        from.pop_back();
        hanoi_tower(from, aux);
        to.push_front(tempValue);
        hanoi_tower(aux, to);
    }
}
void print_queue(deque<int> q){
    while(q.size() > 0) {
        cout << q.front() << ", ";
        q.pop_front();
    }
}
int main() {
    deque<int> from, to;
    for(int i = 0; i < 20;i++) {
        from.push_front(i+1);
    }
    cout << "printing from" << endl;
    print_queue(from);
    hanoi_tower(from, to);
    cout << endl << "printing to" << endl;
    print_queue(to);
    return 0;
}