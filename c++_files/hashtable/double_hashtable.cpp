#include <iostream>
#define TABLE_SIZE 6
#define PRIME 5
using namespace std;

class DoubleHashtable
{
    int *hashtable;
    int current_size;
    void insert_double_hash(int index, int val)
    {
        int index_hash2 = hash2(val);
        for (int i = 1; true; i++)
        {
            int new_index = (index + i * index_hash2) % TABLE_SIZE;
            if (hashtable[new_index] == -1)
            {
                hashtable[new_index] = val;
                break;
            }
        }
    }

  public:
    bool isFull()
    {
        return current_size >= TABLE_SIZE;
    }
    DoubleHashtable()
    {
        hashtable = new int[TABLE_SIZE];
        current_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            hashtable[i] = -1;
        }
    }
    int hash1(int key)
    {
        return key % TABLE_SIZE;
    }
    int hash2(int key)
    {
        return PRIME - (key % PRIME);
    }
    void insert(int val)
    {
        if (isFull())
            return;
        int index_hash1 = hash1(val);
        if (hashtable[index_hash1] != -1)
        {
            insert_double_hash(index_hash1, val);
        }
        else
            hashtable[index_hash1] = val;
        current_size++;
    }
    void display() 
    { 
        for (int i = 0; i < TABLE_SIZE; i++) 
        { 
            if (hashtable[i] != -1) 
                cout << i << " --> "
                     << hashtable[i] << endl; 
            else
                cout << i << endl; 
        } 
    } 
};

int main()
{
    int arr[] = {19, 27, 50, 12, 421, 2};
    int n = sizeof(arr)/sizeof(arr[0]); 
    DoubleHashtable hash_table;
    for(int i = 0; i < n; i++) {
        hash_table.insert(arr[i]);
    }
    hash_table.display();
    return 0;
}