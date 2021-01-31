/*

There are four main characteristics of a good hash function:
1) The hash value is fully determined by the data being hashed.
2) The hash function uses all the input data.
3) The hash function "uniformly" distributes the data across the entire set of possible hash values.
4) The hash function generates very different hash values for similar strings.
 */

//https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
//https://github.com/aozturk/HashMap/tree/master/hashmap
//https://gist.github.com/aozturk/2368896



const int TABLE_SIZE = 128;

class HashEntry
{
public:
  int key;
  int value;

  HashEntry(int key, int value)
  {
    this->key = key;
    this->value = value;
  }
};


class HashMap
{
private:
  HashEntry **table; //HashEntry * table[];
  //table is undimensioned array of pointer to HashEntry

public:
  HashMap()
  {
    /*
     table = new HashEntry[TABLE_SIZE]
     is an array of HashEntry objects.

     table = new HashEntry*[TABLE_SIZE]
     is an array of HashEntry pointers.
     */
    table = new HashEntry * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
      table[i] = NULL;
    }
  }

  ~HashMap()
  {
    for (int i = 0; i < TABLE_SIZE; i++)
    {
      if (table[i] != NULL)
        delete table[i];
      delete[] table;
    }
  }

  int HashFunc(int key)
  {
    return key % TABLE_SIZE;
  }

  void Insert(int key, int value)
  {
    int hash = HashFunc(key);
    while (table[hash] != NULL && table[hash]->key != key)
    {
      hash = HashFunc(hash + 1);
    }

    if (table[hash] != NULL)
      delete table[hash];

    table[hash] = new HashEntry(key, value);
  }

  int Search(int key)
  {
    int  hash = HashFunc(key);
    while (table[hash] != NULL && table[hash]->key != key)
    {
      hash = HashFunc(hash + 1);
    }

    if (table[hash] == NULL)
      return -1;
    else
      return table[hash]->value;
  }

  void Remove(int key)
  {
    int hash = HashFunc(key);
    while (table[hash] != NULL)
    {
      if (table[hash]->key == key)
        break;
      hash = HashFunc(hash + 1);
    }

    if (table[hash] == NULL)
    {
      cout << "No Element found at key "<< key << endl;
      return;
    }
    else
    {
      delete table[hash];
    }

    cout<<"Element Deleted"<<endl;
  }

};

int main()
{
  HashMap hash;
  int key, value;
  int choice;
  while (1)
  {
    cout<<"\n----------------------"<<endl;
    cout<<"Operations on Hash Table"<<endl;
    cout<<"\n----------------------"<<endl;
    cout<<"1.Insert element into the table"<<endl;
    cout<<"2.Search element from the key"<<endl;
    cout<<"3.Delete element at a key"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1:
        cout<<"Enter element to be inserted: ";
        cin>>value;
        cout<<"Enter key at which element to be inserted: ";
        cin>>key;
        hash.Insert(key, value);
        break;
      case 2:
        cout<<"Enter key of the element to be searched: ";
        cin>>key;
        if (hash.Search(key) == -1)
        {
          cout<<"No element found at key "<<key<<endl;
          continue;
        }
        else
        {
          cout<<"Element at key "<<key<<" : ";
          cout<<hash.Search(key)<<endl;
        }
        break;
      case 3:
        cout<<"Enter key of the element to be deleted: ";
        cin>>key;
        hash.Remove(key);
        break;
      case 4:
        exit(1);
      default:
        cout<<"\nEnter correct option\n";
    }
  }
  return 0;
}
