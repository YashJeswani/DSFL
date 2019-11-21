#include<iostream>
#include<fstream>
using namespace std;
struct emp
{
	int id;
	char name[25];
	long long int phone;
	int salary;
};
struct HT
{
  emp e;
  int chain;
};
class HashTable
{
	int hash;
  char filename[25];
public:
	HashTable(int n,char filenamecpy[])
	{
    fstream f;
    strcpy(filename,filenamecpy);
    f.open(filename , ios::in);
    hash = n;
    if(f.fail())
    {
      f.close();
      f.open(filename,ios::out |ios::binary);
      HT t;
      t.e.id = -1;
      strcpy(t.e.name,"NULL");
      t.e.phone = -1;
      t.e.salary = -1;
      t.chain = -1;
      for(int i =0 ;i<hash;i++)
        f.write((char *)&t,sizeof(HT));
    }
    f.close();
  }
  int insert(emp);
	void display(int);
	int search(int);
  void modify(int);
	void displayall();
};

int HashTable::insert(emp data)
{
	int i = data.phone%hash;
  fstream f;
  f.open(filename,ios::in|ios::out|ios::binary);
  f.seekg(i * sizeof(HT),ios::beg);
  HT t;
  f.read((char *)&t,sizeof(HT));
	if(t.e.phone == -1)//When there is a direct hash match
	{
	   f.seekp(i * sizeof(HT),ios::beg);
     t.e = data;
     t.chain = -1;
     f.write((char *)&t , sizeof(t));
     f.close();
     return 0;
	}
	else
	{
    //Linear Probe to find start of chain
    int start = i;
		do
		{
      start ++;
      if(t.e.phone == -1 || t.e.phone % hash == i){
        break;
      }
      f.read((char *)&t , sizeof(HT));
      if(f.fail()){
        f.seekg(0,ios::beg);
        f.seekp(0,ios::beg);
        start = 0;
        f.read((char *)&t , sizeof(HT));
        continue;
      }
		}
		while(start != i);
  //  cout<<"Found start of chain -"<<start-1<<"\n";
		if(start == i){
    //  cout<<"Table FUll\n";
      f.close();
      return -2;
    }
    if(t.e.phone == -1)
    {
    //  cout<<"No Start of chain Exists Creating new chain\n";
      t.e = data;
      t.chain = -1;
      if(start == 0)
        start = hash;
      f.seekp((start-1) * sizeof(HT),ios::beg);
      f.write((char *)&t , sizeof(HT));
      return 0;
    }
    else
    {
      if(t.chain != -1)
      {
        //cout<<"Trying to find end of chain\n";
        start = t.chain;
        //Finds end of chain;
        while(t.chain != -1)
        {
          f.seekg(t.chain * sizeof(HT), ios::beg);
          f.seekp(t.chain * sizeof(HT),ios:: beg);
          start = t.chain;
          f.read((char*)&t,sizeof(HT));
        }
        start ++;
      }
        //trying to linear probe
      int temp = start;
      do
  		{
        if(t.e.phone == -1){
          break;
        }
        start ++;
        f.read((char *)&t , sizeof(HT));
        if(f.fail()){
          f.seekg(0,ios::beg);
          start = 0;
          f.read((char *)&t , sizeof(HT));
          continue;
        }
  		}
  		while(start != temp);
      if(start == temp)
      {
        f.close();
        return -2;
      }
      else
      {
        //cout<<temp<<" "<<start;
        t.e = data;
        t.chain = -1;
        if(start == 0)
          start = hash;
        f.seekp((start-1) * sizeof(HT),ios::beg);
        f.write((char *)&t,sizeof(HT));

        if(temp == 0)
          temp = hash;
        f.seekg((temp - 1) *sizeof(HT),ios::beg);
        f.read((char *)&t,sizeof(HT));
        f.seekp((temp - 1) *sizeof(HT),ios::beg);
      //  cout<<t.e.phone;
        t.chain = start - 1;
        f.write((char *)&t,sizeof(HT));
        return 0;
      }
    }
  }
}

int HashTable::search(int query)
{

	int i = query%hash;
  fstream f;
  f.open(filename,ios::in|ios::out|ios::binary);
  f.seekg(i * sizeof(HT),ios::beg);
  HT t;
  f.read((char *)&t,sizeof(HT));
  if(t.e.phone == -1)
  {
    //cout<<"Not Possible case";
      f.close();
      return -1;
  }
	else if(i == t.e.phone % hash && query == t.e.phone)
  {
  //  cout<<"Direct Hit";
    f.close();
		return i;
  }
	else
	{
		int start = i;
    int flag =0;
    do
    {
      //cout<<t.e.phone<<"\n";
      if(t.e.phone == -1 || t.e.phone % hash == i){
        break;
      }
      start ++;
      f.read((char *)&t , sizeof(HT));
      if(f.fail()){
        f.seekg(0,ios::beg);
        f.seekp(0,ios::beg);
        start = 0;
        f.read((char *)&t , sizeof(HT));
        flag =1;
      }
    }
    while(start != i);
    //cout<<"Found Start of chain -"<<start;
    if(start == i && flag == 1){
      //cout<<"Entire Table Searched\n";
      f.close();
      return -1;
    }
    if(t.e.phone == -1)
    {
      f.close();
      return -1;
    }

    //cout<<"Trying to find end of chain\n";
    //Finds end of chain;
    while(t.chain != -1 && t.e.phone != query)
    {
      //cout<<t.e.phone<<"\n";
      f.seekg(t.chain * sizeof(HT), ios::beg);
      start = t.chain;
      f.read((char*)&t,sizeof(HT));
    }
    f.close();
    if(t.e.phone == query)
      return start;
    else
      return -1;

	}
	return -1;

}

void HashTable::display(int index)
{
  HT t;
  fstream f;
  f.open(filename,ios::in|ios::binary);
  f.seekg(index * sizeof(HT),ios::beg);
  f.read((char *)&t,sizeof(HT));
	cout<<t.e.id<<"\t\t"<<t.e.name<<"\t\t"<<t.e.phone<<"\t\t"<<t.e.salary<<"\t\t"<<t.chain<<"\n";
  f.close();
}

void HashTable::displayall()
{
	for(int i =0 ;i<hash;i++)
    display(i);
}
void head()
{
	cout<<"|Employee ID| Employee Name | Phone Number | Employee Salary|Chain|\n";
}

void HashTable::modify(int index)
{
  fstream f;
  f.open(filename,ios::in|ios::out|ios::binary);
  f.seekg(index* sizeof(HT),ios::beg);
  HT t;
  f.read((char *)&t,sizeof(HT));
  cout<<"Enter New Name:";
  cin>>t.e.name;
  cout<<"Enter New ID:";
  cin>>t.e.id;
  cout<<"Enter New Salary:";
  cin>>t.e.salary;
  f.seekp(index* sizeof(HT),ios::beg);
  f.write((char *)&t,sizeof(HT));
  f.close();
}


int main()
{
  cout<<"Enter File Name :";
  char filename[25];
  cin>>filename;
  HashTable h(20,filename);
  emp e;
  int flag;
  int choice;
  do {
    cout<<"\n\n\nPress 1 to insert Data into Database\nPress 2 to Search From the Database\nPress 3 to modify\nPress 4 to Display Database\nPress 5 to exit\nEnter Choice:";
    cin>>choice;
    switch (choice) {
      case 1:
        cout<<"Enter Employee ID:";
        cin>>e.id;
        cout<<"Enter Employee Name:";
        cin.ignore();
        cin.getline(e.name,25);
        cout<<"Enter Phone Number:";
        cin>>e.phone;
        cout<<"Enter Salary:";
        cin>>e.salary;
        cout<<h.insert(e);
        break;

      case 2:
        cout<<"Enter Phone Number:";
        cin>>e.phone;
        flag = h.search(e.phone);
        if(flag != -1){
          head();
          h.display(flag);}
        else
          cout<<"Record Not Found\n\n";
        break;

      case 3:
        cout<<"Enter Phone Number of Record :";
        cin>>e.phone;
        flag = h.search(e.phone);
        if(flag != -1)
          h.modify(flag);
        else
          cout<<"Record Not Found\n\n";
        break;

      case 4:
        head();
        h.displayall();
        break;
      case 5:
        break;
    }
  }
  while(choice != 5);
}



//						OUTPUT
/*
Enter File Name :databs



Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:1
Enter Employee ID:123
Enter Employee Name:Sahil
Enter Phone Number:8806635393
Enter Salary:12323345
0


Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:1
Enter Employee ID:234
Enter Employee Name:Soham
Enter Phone Number:7276703686
Enter Salary:3212312
0


Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:1
Enter Employee ID:254
Enter Employee Name:Amod
Enter Phone Number:13
Enter Salary:23121312
0


Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:4
|Employee ID| Employee Name | Phone Number | Employee Salary|Chain|
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
234             Soham           7276703686              3212312         -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
123             Sahil           8806635393              12323345                14
254             Amod            13              23121312                -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1



Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:1
Enter Employee ID:2312
Enter Employee Name:xyz
Enter Phone Number:26
Enter Salary:321312
0


Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:4
|Employee ID| Employee Name | Phone Number | Employee Salary|Chain|
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
234             Soham           7276703686              3212312         7
2312            xyz             26              321312          -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
123             Sahil           8806635393              12323345                14
254             Amod            13              23121312                -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1
-1              NULL            -1              -1              -1



Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:2
Enter Phone Number:26
|Employee ID| Employee Name | Phone Number | Employee Salary|Chain|
2312            xyz             26              321312          -1



Press 1 to insert Data into Database
Press 2 to Search From the Database
Press 3 to modify
Press 4 to Display Database
Press 5 to exit
Enter Choice:5
*/
