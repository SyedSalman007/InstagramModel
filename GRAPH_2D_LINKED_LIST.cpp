#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class node
{
	public:
		bool frd;
		string node_name;
		string frd_name;
		node* down;
		node* left;	
		node()
		{
			down = left = NULL;
			frd = false;
		}
		node(bool frd,string node_name)
		{
			this->frd = frd;
			this->node_name = node_name;
			down = left = NULL;
		}
};
class graph
{
	private:
		node* head;
	public:
		graph()
		{
			head = NULL;
		}
		graph(string name)
		{
			node* ptr = new node;
			ptr->node_name = name;
			head = ptr;
			ptr->down = NULL;	
		}	
		void insert(string name)
		{
			node* ptr = new node;
			ptr->node_name = name;
			if(head == NULL)
			{
				head = ptr;
				ptr->down = NULL;
				return;
			}
			node* temp = head;
			while(temp->down != NULL)
			{
				temp = temp->down;
			}
			temp->down = ptr;
			ptr->down = NULL;
		}
		void print_node()
		{
			node* temp = head;
			while(temp != NULL)
			{
				cout<<temp->node_name<<" ";
				temp = temp->down;
			}
			cout<<endl;
		}
		void print_link_of_node(string name)
		{
			node* temp = head;
			node* temp1 = head;
			while(temp != NULL)
			{
				temp1 = temp;
				if(temp->node_name == name)
				{
					cout<<"LINKS OF "<<name<<" : ";
					while(temp1 != NULL)
					{
						cout<<temp1->frd_name<<" ->";
						temp1 = temp1->left;
					}
					break;
				}
				temp = temp->down;
			}
			cout<<endl;
		}
		void insert_link()
		{
			string d_name,l_name;
			int x = 1;
			while(x != 0)
			{
				cout<<"THE AVAILABLE NODE OF GARPH ARE : ";
				print_node();
				cout<<"ENTER THE NODE NAME FROM WHICH YOU WANT TO MAKE LINK : ";
				cin>>d_name;
				cout<<"ENTER THE NODE NAME TO WHICH YOU TO CONNECT : ";
				cin>>l_name;
				node* temp = head;
				while(temp != NULL)
				{
					if(temp->node_name == d_name)
					{
						node* temp2 = head;
						node* ptr = new node;
						ptr->frd_name = l_name;
						ptr->frd = true;
						while(temp->left != NULL)
						{
							temp = temp->left;
						}
						temp->left = ptr;
						ptr->left = NULL;
						break;
					}
					temp = temp->down;
				}				
				cout<<"PRESS [1] TO MAKE FURTHER LINKS"<<endl
					<<"PRESS [0] TO EXIT : \t";
					cin>>x;
			}
		}
		void display_graph()
		{
			node* temp1 = head;
			node* temp2 = head;
			while(temp1 != NULL)
			{
				cout<<temp1->node_name;
				temp2 = temp1;
				while(temp2 != NULL)
				{
					cout<<temp2->frd_name<<"->";
					temp2 = temp2->left;
				}
				temp1 = temp1->down;
				cout<<endl<<"|"<<endl;
			}
		}
		void display_friends(string name)
		{
			node* temp1 = head;
			while(temp1->node_name != name)
			{
				temp1 = temp1->down;
			}
//			cout<<"Friends of "<<temp1->node_name<<" are : ";	
			node* temp2 = temp1->left;
			while(temp2 != NULL)
			{
				cout<<" "<<temp2->frd_name;
				temp2 = temp2->left;
			}
		}
		void suggest_friends(string name)
		{
			node* temp1 = head;
			while(temp1->node_name != name)
			{
				temp1 = temp1->down;
			}
			node* temp2 = temp1->left;
			node* arrt = temp2;
			while(temp2 != NULL)
			{
				arrt->node_name = temp2->frd_name;
				arrt = arrt->left;
				temp2 = temp2 -> left;
			}
			temp2 = temp1;
			while(temp2 != NULL)
			{
				arrt = temp1;
				while(arrt != NULL)
				{
					if(temp2->node_name == arrt->node_name && temp2->node_name != name)
					{
						display_friends(temp2->node_name);
					}
					arrt = arrt->left;
				}
				temp2 = temp2->left;
			}
		}
		
};
		

int main()
{
	string hold,line;
	graph list;
	fstream file5;
	file5.open("jari.csv",ios::in | ios::app);
	if(file5.eof())
	{
	}
	while(getline(file5,line))
	{
		cout<<"enn";
		stringstream info(line);
		getline(info,hold,',');
		cout<<hold<<endl;
	}
	list.insert("A");
	list.insert("B");
	list.insert("C");
	list.insert("D");
	list.insert("E");
	list.insert_link();
//	list.insert_link();
//	list.print_node();	
//	list.display_friends("A");
	list.suggest_friends("B");
	cout<<endl;
//	list.insert_link();
	list.display_graph();
//	list.adjacency_matrix();
//	list.print_link_of_node("A");
	
	
	return 0;
}

