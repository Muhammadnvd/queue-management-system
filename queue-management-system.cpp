#include<iostream>

#include<conio.h>

using namespace std;

int nor_que=0,exp_que=0;

class CustomerNode

{

	public:

		int id,item;

		string name;

		string type;

		CustomerNode *next_add;

};

class CustomerQueue

{

	public:

		CustomerNode *head = NULL;

		int get_id();

		string get_name();

		int get_item();

		int set_id(int id);

		string set_name(string name);

		int set_item(int item);

		void addQueue();

		void removeQueue(int id);

		void display();

};

	int CustomerQueue::get_id()

	{

		int id;

		cout<<"\n\nCustomer ID : ";

		cin>>id;

		return id;

	}

	string CustomerQueue::get_name()

	{

		string name;

		cout<<"\n\nCustomer Name : ";

		cin>>name;

		return name;

	}

	int CustomerQueue::get_item()

	{

		int item;

		cout<<"\n\nGrocery Items Purchased : ";

		cin>>item;

		return item;

	}

	int CustomerQueue::set_id(int id)

	{

		return id;

	}

	string CustomerQueue::set_name(string name)

	{

		return name;

	}

	int CustomerQueue::set_item(int item)

	{

		return item;

	}

	void CustomerQueue::addQueue()

	{

		cout<<"\n-----Enter Customer Information-----";

		CustomerNode *new_node = new CustomerNode;

		new_node -> id = get_id();

		new_node -> name = get_name();

		new_node -> item = get_item();

		if(new_node -> item <= 5)

		{

			new_node -> type = "Express";

			exp_que++;

			cout<<"\n\n-----Customer Entered in Express Queue-----";

			cout<<"\n\nTotal Customers in Express Queue : "<<exp_que;

		}

		else

		{

			new_node -> type = "Normal";

			nor_que++;

			cout<<"\n\n-----Customer Entered in Normal Queue-----";

			cout<<"\n\nTotal Customers in Normal Queue : "<<nor_que;

		}

		new_node -> next_add = NULL;

		if(head == NULL)

		{

			head = new_node;

		}

		else

		{

			CustomerNode *ptr = head;

			while(ptr -> next_add != NULL)

			{

				ptr = ptr -> next_add;

			}

			ptr -> next_add = new_node;

		}

	}

	void CustomerQueue::removeQueue(int id)

	{

		if(head -> id == id)

		{

			CustomerNode *ptr = head;

			head = head -> next_add;

			delete ptr;

		}

		else

		{

			CustomerNode *pre = head;

			CustomerNode *ptr = head;

			while(ptr != NULL)

			{

				if(ptr -> id == id)

				{

					pre -> next_add = ptr -> next_add;

					delete ptr;

					break;

				}

				pre = ptr;

				ptr = ptr -> next_add;

			}

		}

	}

	void CustomerQueue::display()

	{

		CustomerNode *ptr = head;

		cout<<"\n\n-----Normal Queue Customers Information-----";

		while(ptr != NULL)

		{

			if(ptr -> type == "Normal")

			{

				cout<<"\n\nCustomer Name : "<<set_name(ptr -> name);

				cout<<"\n\nCustomer ID : "<<set_id(ptr -> id);

				cout<<"\n\nNumber of Grocery Items Purchased : "<<set_item(ptr -> item);

				nor_que--;

				cout<<"\n\nTotal Customers in Normal Queue : "<<nor_que;

				removeQueue(ptr -> id);

			}

			ptr = ptr -> next_add;

		}

		ptr = head;

		cout<<"\n\n-----Express Queue Customers Information-----";

		while(ptr != NULL)

		{

			if(ptr -> type == "Express")

			{

				cout<<"\n\nCustomer Name : "<<set_name(ptr -> name);

				cout<<"\n\nCustomer ID : "<<set_id(ptr -> id);

				cout<<"\n\nNumber of Grocery Items Purchased : "<<set_item(ptr -> item);

				exp_que--;

				cout<<"\n\nTotal Customers in Express Queue : "<<exp_que;

				removeQueue(ptr -> id);

			}

			ptr = ptr -> next_add;

		}

	}

main()

{

	CustomerQueue obj;

	char x;

	do{

		obj.addQueue();

		cout<<"\n\nDo you want enter another customer? input y or Y for Yes and n or N for No : ";     

		cin>>x;

	}while(x == 'y' || x == 'Y');

	obj.display();

	getch();

	return 0;


}
