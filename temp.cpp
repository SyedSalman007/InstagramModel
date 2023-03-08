class PriorityNode
{	
	public:	
		int priority;
		string data;
		PriorityNode* next;
		PriorityNode(){	}
		PriorityNode(int priority, string data)
		{
			this->priority = priority;
			this->data = data;
			next = NULL;
		}
		int get_priority()
		{
			return priority;
		}
		string get_data()
		{
			return data;
		}	
};
class FriendNode
{
	public:	
		string file;
		FriendNode* next;	
		FriendNode(string file)
		{
			this->file = file;
			next = NULL;
		}
};
class PriorityQueueList
{
	public:	
		PriorityNode* root;
		PriorityNode* searched_user;
		PriorityNode* friend_root;
		FriendNode* node;
		PriorityQueueList()
		{
			root = NULL;
			friend_root = NULL;
			node = NULL;
			searched_user = NULL;
		}
		void make_list(string file_name)
		{
			root = NULL;
			friend_root = NULL;
			node = NULL;
			fstream file;
			string index,line,line1,hold,hold1,hold2,hold3,hold4;
			int flag = 0;
			int length;		
			file.open(file_name.c_str(), ios::in | ios::app);
			if(file.fail())
			{
				cout<<"\nFile failed to opened in priority queue\n";
				exit(1);
			}//       Getting the priority of the post and the content of the post
			while(getline(file,line))
			{
				stringstream info(line);
				getline(info,hold1,',');
				getline(info,hold,',');
				fstream file1;
				hold = hold + "post.csv";
				file1.open(hold.c_str(),ios::in | ios::app);
				while(getline(file1,line1))
				{
					stringstream info1(line1);
					getline(info1,hold3,',');
					getline(info1,hold4,',');
					flag++;
				}
				PriorityNode* ptr = new PriorityNode;
				if(root == NULL)
				{
					ptr->priority = flag;
					ptr->data = hold4;
					root = ptr;
					ptr->next = NULL;
				}
				else
				{
					PriorityNode* temp = new PriorityNode;
					while(temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = ptr;
					ptr->priority = flag;
					ptr->data = hold4;
					ptr->next = NULL;
				}
				
			}		
			file.close();
//			insert_friend();
			display();
		}
	
	void display()
	{
		PriorityNode* temp = root;
		PriorityNode* temp2 = friend_root;
		PriorityNode* to_delete = NULL;
		
		cout<<"**********************************"<<" Welcome To Your News Feed "<<"**********************************\n";
		cout<<"_______________________________________________________________________________________________\n\n";
	    
	    while(temp != NULL)
	    {
	        cout<<"\t\t\t"<<temp->data<<endl;
	        temp = temp->next;
	    }
	}
};


//		void display_graph()
//		{
//			g_node* temp1 = head;
//			g_node* temp2 = head;
//			while(temp1 != NULL)
//			{
//				cout<<temp1->g_node_name;
//				temp2 = temp1;
//				while(temp2 != NULL)
//				{
//					cout<<temp2->frd_name<<"->";
//					temp2 = temp2->left;
//				}
//				temp1 = temp1->down;
//				cout<<endl<<"|"<<endl;
//			}
//		}
//		void display_friends(string name)
//		{
//			g_node* temp1 = head;
//			while(temp1->g_node_name != name)
//			{
//				temp1 = temp1->down;
//			}
//			g_node* temp2 = temp1->left;
//			while(temp2 != NULL)
//			{
//				cout<<" "<<temp2->frd_name;
//				temp2 = temp2->left;
//			}
//		}
//		void mutual(string name)
//		{
//			g_node* temp1 = head;
//			while(temp1->g_node_name != name)
//			{
//				temp1 = temp1->down;
//			}
//			g_node* temp2 = temp1->left;
//			g_node* arrt = temp2;
//			while(temp2 != NULL)
//			{
//				arrt->g_node_name = temp2->frd_name;
//				arrt = arrt->left;
//				temp2 = temp2 -> left;
//			}
//			temp2 = temp1;
//			while(temp2 != NULL)
//			{
//				arrt = temp1;
//				while(arrt != NULL)
//				{
//					if(temp2->g_node_name == arrt->g_node_name && temp2->g_node_name != name)
//					{
//						display_friends(temp2->g_node_name);
//					}
//					arrt = arrt->left;
//				}
//				temp2 = temp2->left;
//			}
//		}
