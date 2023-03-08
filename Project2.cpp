#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
using namespace std;
template <typename T>  
class node 
{
    public:
        T value;
        T key;
        int height;
        node * left;
        node * right;
        node(T k, T v)
		{
	        height = 1;
	        key = k;
	        value = v;
	        left = NULL;
	        right = NULL;
        }
		string get_key_word()
		{
			return key;
		}
		string get_data()
		{
			return value;
		}
		char get_key_word_initial()
		{
			return key[0];
		}
		void set_left_leave(node<T>* left)
		{
			this->left = left;
		}
		void set_right_leave(node<T>* right)
		{
			this->right = right;
		}
};
template <typename T>       
class AVL
{
    public:
        node<T>* root = NULL;
        AVL(){}
        int n;
		string get_file_name(char letter)
		{
				string file = "";
				
					 if(letter == 'a' || letter == 'A')  		file = "a_data.csv";
				else if(letter == 'b' || letter == 'B')			file = "b_data.csv";
				else if(letter == 'c' || letter == 'C')			file = "c_data.csv";
				else if(letter == 'd' || letter == 'D')			file = "d_data.csv";
				else if(letter == 'e' || letter == 'E')			file = "e_data.csv";
				else if(letter == 'f' || letter == 'F')			file = "f_data.csv";
				else if(letter == 'g' || letter == 'G')			file = "g_data.csv";
				else if(letter == 'h' || letter == 'H')			file = "h_data.csv";
				else if(letter == 'i' || letter == 'I')			file = "i_data.csv";
				else if(letter == 'j' || letter == 'J')			file = "j_data.csv";
				else if(letter == 'k' || letter == 'K')			file = "k_data.csv";
				else if(letter == 'l' || letter == 'L')			file = "l_data.csv";
				else if(letter == 'm' || letter == 'M')			file = "m_data.csv";
				else if(letter == 'n' || letter == 'N')			file = "n_data.csv";	
				else if(letter == 'o' || letter == 'O')			file = "o_data.csv";
				else if(letter == 'p' || letter == 'P')			file = "p_data.csv";
				else if(letter == 'q' || letter == 'Q')			file = "q_data.csv";
				else if(letter == 'r' || letter == 'R')			file = "r_data.csv";
				else if(letter == 's' || letter == 'S')			file = "s_data.csv";
				else if(letter == 't' || letter == 'T')			file = "t_data.csv";
				else if(letter == 'u' || letter == 'U')			file = "u_data.csv";
				else if(letter == 'v' || letter == 'V')			file = "v_data.csv";
				else if(letter == 'w' || letter == 'W')			file = "w_data.csv";
				else if(letter == 'x' || letter == 'X')			file = "x_data.csv";
				else if(letter == 'y' || letter == 'Y')			file = "y_data.csv";
				else if(letter == 'z' || letter == 'Z')			file = "z_data.csv";
				else											file = "missing_data.csv";
				return file;
		}
		fstream file_read;
		node<T>* ssearch(string search_data)
		{
			string file = get_file_name(search_data[0]);		
			create_tree(file);	
			return root;
		}			
		node<T>* get_root()
		{
			return root;
		}
		void insert(string key, string value)
		{
			node<T>* temp = root;
			node<T>* ptr = new node<T>(key,value);
			root = insertion(temp,ptr,key);
		}
		node<T>* create_tree(string file_name)
		{
			string key, value;
			string line = "";		
			file_read.open(file_name.c_str(), ios::in | ios::app);				
			if(file_read.fail())
			{
				cout<<"\nFile failed to opened\n";
				exit(1);
			}
			while(getline(file_read, line))
			{
				stringstream ss(line);
				getline(ss, key, ',');
				getline(ss, value, ',');
				insert(key, value);
			}
		}
		int balanced_factor(node<T>* temp)
		{
			if(temp == NULL)
			{
				return -1;
			}
			return (height(temp->left) - height(temp->right));
		}
		node<T>* insertion(node<T>* temp_root, node<T>* ptr,string key)
		{
			if(temp_root == NULL)
			{
				temp_root = ptr;
				return temp_root;
			}
			else if(temp_root->get_key_word_initial() > ptr->get_key_word_initial())
			{
				temp_root->left = insertion(temp_root->left,ptr,key);
			}
			else
			{
				temp_root->right = insertion(temp_root->right,ptr,key);
			}			
			int bf = balanced_factor(temp_root);
			if(bf > 1 && temp_root->left->get_key_word_initial() > ptr->get_key_word_initial())
			{
				return rightRotation(temp_root);
			}
			else if(bf < -1 && temp_root->right->get_key_word_initial() < ptr->get_key_word_initial())
			{
				return leftRotation(temp_root);
			}
			else if(bf > 1 && temp_root->left->get_key_word_initial() < ptr->get_key_word_initial())
			{
				temp_root->left = leftRotation(temp_root);
				return rightRotation(temp_root);
			}
			else if(bf < -1 && temp_root->right->get_key_word_initial() < ptr->get_key_word_initial())
			{
				temp_root->right = rightRotation(temp_root);
				return leftRotation(temp_root);
			}
			return temp_root;
		}
        void insert(T x)
		{
            root=insertUtil(root, x);
        }
        void remove(T x)
		{
            root=removeUtil(root, x);
        }
        node<T>* search(T x)
		{
            return searchUtil(root,x);
        }
        node<T>* searchstring(T str)
		{
			node<T>* a[7];
            searchstring_(root, str, &a[0]);
            if(a[0] == '\0')
            {
            	cout<<"\t\t\tNO SUCH EXISTS\t"<<endl;
            	return NULL;
			}
			else
			{
				cout<<"Select: ";
				cout<<"\t\t\\tNOT FOUND\t\tPRESS[0]";
	            int select;
	            cin>>select;
	            if(select == 0)
	            {
	            	return NULL;
				}
	            return a[select-1];	
			}
        }
	    void display()
		{
			cout<<"\nInorder traversal:\n";
			inorder_traversal(root);
		}
		void inorder_traversal(node<T>* temp_root)
		{
			if(temp_root == NULL)
			{
				return;
			}
			inorder_traversal(temp_root->left);
			cout<<temp_root->get_key_word_initial()<<" ";
			inorder_traversal(temp_root->right);
		}
		void searchup(string);
    private:
        int height(node<T>* head)
		{
            if(head==NULL) return 0;
            return head->height;
        }
        node<T>* rightRotation(node<T>* head)
		{
            node<T>* newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }
        node<T>* leftRotation(node<T>* head)
		{
            node<T>* newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }
		int i = 1;
        void searchstring_(node<T>* head, T str, node<T>** a)
		{
			int prior = 0;
            if(head==NULL) return ;
            searchstring_(head->left, str, a);
            string temp = head->key;
            if (temp.find(str) != std::string::npos)
            {
            	int index = temp.find(str) + 1 ;  
            	if(index == 1 || temp[index-2] == ' ')
        		{
        				cout<<""<<i<<". "<<head->key<<endl;
        				a[i-1] = head;
        				i++;
				}
			}
            searchstring_(head->right, str, a);
        }
        node<T>* insertUtil(node<T>* head, T x)
		{
            if(head==NULL)
			{
                n+=1;
                node<T>* temp = new node<T>(x);
                return temp;
            }
            if(x < head->key) head->left = insertUtil(head->left, x);
            else if(x > head->key) head->right = insertUtil(head->right, x);
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1)
			{
                if(x < head->left->key)
				{
                    return rightRotation(head);
                
				}
				else
				{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }
			else if(bal<-1)
			{
                if(x > head->right->key)
				{
                    return leftRotation(head);
                }else
				{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }
        node<T>* removeUtil(node<T>* head, T x)
		{
            if(head==NULL) return NULL;
            if(x < head->key)
			{
                head->left = removeUtil(head->left, x);
            }
			else if(x > head->key)
			{
                head->right = removeUtil(head->right, x);
			}
			else
			{
                node<T>* r = head->right;
                if(head->right==NULL)
				{
                    node<T>* l = head->left;
                    delete(head);
                    head = l;
                }
				else if(head->left==NULL)
				{
                    delete(head);
                    head = r;
                }
				else
				{
                    while(r->left!=NULL) r = r->left;
                    head->key = r->key;
                    head->right = removeUtil(head->right, r->key);
                }
            }
            if(head==NULL) return head;
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1)
			{
                if(height(head->left) >= height(head->right))
				{
                    return rightRotation(head);
                }
				else
				{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }
			else if(bal < -1)
			{
                if(height(head->right) >= height(head->left))
				{
                    return leftRotation(head);
                }
				else
				{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }
        node<T>* searchUtil(node<T>* head, T x)
		{
            if(head == NULL) 
			{
				return NULL;
			}
            T k = head->key;
            if(k == x) return head;
            if(k > x) return searchUtil(head->left, x);
            if(k < x) return searchUtil(head->right, x);
        }
};
class graph_mutual_friend_node
{
	public:
		int number_of_mutuals;
		string friend_name;
		string friend_to_friend;
		string names_of_mutuals[3];
		graph_mutual_friend_node *left;
		graph_mutual_friend_node *right;
		graph_mutual_friend_node()
		{
			left = right = NULL;
			this->number_of_mutuals = 0 ;
			for(int i = 0; i < 3;i++)
			{
				names_of_mutuals[i] = '\0';
			}
		}
		graph_mutual_friend_node(string friend_name)
		{
			this->friend_name = friend_name;
		}
};
class AVL_FOR_MUTUAL_FRIENDS
{
	private:
		graph_mutual_friend_node * root;
	public:
		AVL_FOR_MUTUAL_FRIENDS()
		{
			root = NULL;	
		}	
		AVL_FOR_MUTUAL_FRIENDS(string f_name,string ff_name)
		{
			graph_mutual_friend_node* ptr = new graph_mutual_friend_node;
			ptr->friend_name = f_name;
			ptr->friend_to_friend = ff_name;
			ptr->names_of_mutuals[ptr->number_of_mutuals] = f_name;
			ptr->number_of_mutuals = ptr->number_of_mutuals + 1;
			root = ptr;
		}
		void insert(string f_name,string ff_name)
		{
			int i = 0;
			if(root == NULL)
			{
				graph_mutual_friend_node* ptr = new graph_mutual_friend_node;
				ptr->friend_name = f_name;
				ptr->friend_to_friend = ff_name;
				ptr->names_of_mutuals[ptr->number_of_mutuals] = f_name;
				ptr->number_of_mutuals = ptr->number_of_mutuals + 1;
				root = ptr;
				return;
			}
			graph_mutual_friend_node* temp = root;
			root = inserting(temp,f_name,ff_name,0);
		}
		graph_mutual_friend_node* inserting(graph_mutual_friend_node* root,string f_name,string ff_name,int itrator)
		{
			if(root == NULL)
			{
				graph_mutual_friend_node* ptr = new graph_mutual_friend_node;
				ptr->friend_to_friend = ff_name;
				ptr->friend_name = f_name;
				ptr->names_of_mutuals[ptr->number_of_mutuals] = f_name;
				ptr->number_of_mutuals = ptr->number_of_mutuals + 1;
				root = ptr;
				return root;
			}
			if(root->friend_to_friend == ff_name)
			{
				root->names_of_mutuals[root->number_of_mutuals] = f_name;
				root->number_of_mutuals = root->number_of_mutuals + 1;
				return root;
			}
			else if(root->friend_to_friend[itrator] == ff_name[itrator])
			{
				while(root->friend_name[itrator] != ff_name[itrator])
				{
					itrator++;
				}
			}
			if(root->friend_to_friend[itrator] > ff_name[itrator])
			{
				root->left = inserting(root->left,f_name,ff_name,itrator);
			}
			else if(root->friend_to_friend[itrator] < ff_name[itrator])
			{
				root->right = inserting(root->right,f_name,ff_name,itrator);
			}
			else
			{
				int bf = balanced_factor(root);
				if(bf > 1 && root->left->friend_to_friend[itrator] > ff_name[itrator])
				{
				    return rotate_right(root);
				}
				else if(bf < -1 && root->right->friend_to_friend[itrator] < ff_name[itrator])
				{
				    return rotate_left(root);
				}
				else if(bf > 1 && root->left->friend_to_friend[itrator] < ff_name[itrator])
				{
				    root->left = rotate_left(root);
				    return rotate_right(root);
				}
				else if(bf < -1 && root->right->friend_to_friend[itrator] > ff_name[itrator])
				{
				    root->right = rotate_right(root);
				    return rotate_left(root);
				} 
			} 
			return root;
		}
		graph_mutual_friend_node* rotate_right(graph_mutual_friend_node* root)
		{
		    graph_mutual_friend_node* temp = root->left;
		    graph_mutual_friend_node* hold = temp->right;
		    temp->right = root;
		    root->left = hold;
		    return temp;
		}
		graph_mutual_friend_node* rotate_left(graph_mutual_friend_node* root)
		{
		    graph_mutual_friend_node* temp = root->right;
		    graph_mutual_friend_node* hold = temp->left;
		    temp->left = root;
		    root->right = hold;
		    return temp;
		}
		void print()
		{
			graph_mutual_friend_node *temp = root;
			post_order(temp);	
//			cout<<endl<<"HEIGHT : "<<height(root);
		}
		void post_order(graph_mutual_friend_node *root)
		{
			if(root != NULL)
			{
				if(root->number_of_mutuals != 1)
				{
					cout<<"\t"<<root->friend_to_friend<<" MUTUAL : ";
					for(int i = 0; i < root->number_of_mutuals ; i++)
					{
						cout<<root->names_of_mutuals[i];
						cout<<"    ";
					}
					cout<<endl;
				}
				post_order(root->left);
				post_order(root->right);
			}
		}
		
		graph_mutual_friend_node* findmin(graph_mutual_friend_node* temp)
		{
			while(temp->left != NULL) 
			{
        		temp = temp->left;
    		}
    		return	temp;
		}
		int balanced_factor(graph_mutual_friend_node* root)
		{
		    if(root == NULL)
		    {
		        return -1;
		    }
		    return (height(root->left) - height(root->right));
		}
		int height(graph_mutual_friend_node* root)
		{
		    if(root == NULL)
		    {
		        return -1;
		    }
		    else
		    {
		        int lh = height(root->left);
		        int rh = height(root->right);
		        if(lh > rh)
		        {
		            return (lh + 1);
		        }
		        else
		        {
		            return (rh + 1);
		        }
		    }
		}
};
class g_node
{
	public:
		bool frd;
		string g_node_name;
		string frd_name;
		g_node* down;
		g_node* left;	
		g_node()
		{
			down = left = NULL;
			frd = false;
		}
		g_node(bool frd,string g_node_name)
		{
			this->frd = frd;
			this->g_node_name = g_node_name;
			down = left = NULL;
		}
};
class f_graph
{
	private:
		g_node* head;
	public:
		f_graph()
		{
			head = NULL;
		}
		f_graph(string name)
		{
			g_node* ptr = new g_node;
			ptr->g_node_name = name;
			head = ptr;
			ptr->down = NULL;	
		}	
		void insert(string name)
		{
			g_node* ptr = new g_node;
			ptr->g_node_name = name;
			if(head == NULL)
			{
				head = ptr;
				insert_link(ptr);
				ptr->down = NULL;
				return;
			}
			g_node* temp = head;
			while(temp->down != NULL)
			{
				temp = temp->down;
			}
			temp->down = ptr;
			insert_link(ptr);
			ptr->down = NULL;
		}
		void insert_link(g_node* temp)
		{
			string line,hold;
			fstream file;
			file.open(temp->g_node_name.c_str(),ios::in | ios::app);
			int x = 1;
			while(getline(file,line))
			{
				stringstream info(line);
				getline(info,hold,',');
				getline(info,hold,',');
				g_node* ptr = new g_node;
				ptr->frd_name = hold;
				ptr->frd = true;
					while(temp->left != NULL)
					{
						temp = temp->left;
					}
					temp->left = ptr;
					ptr->left = NULL;
			}
		}				
		void print_g_node()
		{
			g_node* temp = head;
			while(temp != NULL)
			{
				cout<<temp->g_node_name<<" ";
				temp = temp->down;
			}
			cout<<endl;
		}
		void suggest_friends()
		{
			g_node* temp = head;
			string hold,hold1,line,line1;
			fstream file,file1;
			AVL_FOR_MUTUAL_FRIENDS list;
			cout<<temp->g_node_name<<endl<<endl;
			while(temp != NULL)
			{
				file.open(temp->g_node_name.c_str(),ios::in | ios::app);
				while(getline(file,line))
				{
					stringstream info(line);
					getline(info,hold,',');
					getline(info,hold,',');
					list.insert(temp->g_node_name,hold);		
				}		
				file.close();
				temp = temp->down;
			}
			list.print();
		}		
};
//global
fstream file,personal_profile;
int x = 1;
class login
{
    private:
   		string email;
        string password;
        string your_email;
        string line;
        string f_name,l_name;
        string get_email_from_server;
        string password_from_server;
    public:
    	login(){}
        login(string start)
        {
        	string your_password;
            file.open("info.csv" ,ios::in | ios::app);
        	cout<<"\t\tENTER YOUR EMAIL ID : ";
        	fflush(stdin);
            getline(cin,your_email);
            int x = -1;
            string new_line = "",user_file_name;
            while(getline(file,new_line))
            {
                stringstream info(new_line);
                stringstream hold(new_line);
				getline(info,f_name,',');
                getline(info,l_name,',');
                getline(info,get_email_from_server,',');
			    getline(info,password_from_server,',');
			    getline(info,user_file_name,',');
            	if(get_email_from_server == your_email)
	            { 
				    while(x != 1)
                	{
						cout<<"\t\tENTER PASSWORD : ";
						fflush(stdin);
						getline(cin,your_password);
				    	if(password_from_server == your_password)
				    	{
							HOME_PAGE(hold);
				    		system("pause");
				    		system("cls");
				    		x = 1;
	                		break;
						}
						if(x == 1)
						{
							break;
						}
						else
						{
							cout<<"\t\t\t-----INVALID PASSWORD-----"<<endl;
							cout<<"\t\tTO EXIT PRESS [1] / FOR RE-WRITE PASSWORD PRESS [0] : ";
							cin>>x;
							system("cls");	
						}
					}
				}
				if(x == 1)
				{
					break;
				}
			}
			if(x == -1)
			{
				cout<<"\t\t\t----USER NOT FOUND----"<<endl;				
			}
			else
			{
				new_window(user_file_name,f_name);
			}
			file.close();
		}
		void new_window(string user_file_name,string f_name)
		{
			fstream file6(user_file_name.c_str(),ios::in | ios::app);
			int option = 1;
			while(option != 0)
			{
				cout<<"\t\tSEARCH \t\t\t\t\tPRESS [1]"<<endl
				<<"\t\tFRIEND \t\t\t\t\tPRESS [2]"<<endl
				<<"\t\tCATCH A MOMENT | CREATE A POST \t\tPRESS [3]"<<endl
				<<"\t\tMY PROFILE\t\t\t\tPRESS [4]"<<endl
				<<"\t\tLOGOUT \t\t\t\t\tPRESS [0]\t";
				cin>>option;
				switch(option)
				{
					case 1:
					{
						search(user_file_name);
						system("cls");
						break;	
					};
					case 2:
					{
						friends(user_file_name);
						system("cls");
						break;	
					}
					case 3:
					{
						write_a_post(f_name);
						system("cls");
						break;
					}
					case 4:
					{
						show_my_post(f_name);
						break;
					}
					case 0:
					{
						system("cls");
						option = 0;
						break;	
					};
					default:
					{
						cout<<"\t\t\t----PLEASE SELECT THE CORRECT OPTION----"<<endl;
						system("pause");
						option = 1;
						system("cls");		
					}
				}
			}
		}
        void notification(stringstream &info)
        {
        	string name1,name2,email;
        	getline(info,name1,',');
        	getline(info,name2,',');
        	getline(info,email,',');
			cout<<"\t\t\tPROFILE : "<<name1<<" "<<name2<<endl<<endl;
			cout<<endl<<"\t\t\tE-mail Id : "<<get_email_from_server<<endl;
			cout<<"_____________________________________________________________________________________________"<<endl;
		}
    	void HOME_PAGE(stringstream &info)
    	{
    		int  x;
    		notification(info);
		}
		void search(string user_file_name)
		{
			
			AVL<string>t;
			t.searchup(user_file_name);
		}
		void friends(string user_file_name)
		{
			x = 1;
			while(x != 0)
			{
				cout<<"\t\t\t\tFRIENDS\t\tPRESS [ 1 ]"<<endl
				<<"\t\t\t\tSUGGESTION\t PRESS [ 2 ]"<<endl
				<<"\t\t\t\tHOME PAGEt\tPRESS [ 0 ]\t\t";
				cin>>x;
				if(x == 0)
				{
					break;
				}
				if( x == 1)
				{
					my_friends(user_file_name,f_name);
				}
				else if(x == 2)
				{
					cout<<endl<<"\t\tMUTUAL FRIENDS";
					friends_suggestions(user_file_name);
				}
				else
				{
					cout<<"\t\t\tPLEASE ENTER CORRECT OPTION"<<endl;
					x = 1;
				}
				cout<<"\t\t\tHOME PAGE\t\tPRESS [ 0 ]"<<endl
					<<"\t\t\tCONTINUE\t\tPRESS [ 1 ]\t\t";
					cin>>x;
			}	
		}
		void friends_suggestions(string user_file_name)
		{
			fstream file;
			string hold,line;
			int  x= 1;
			f_graph list;
			file.open(user_file_name.c_str(),ios::in | ios::app);
			while(getline(file,line))
			{
				stringstream info(line);
				getline(info,hold,',');
				list.insert(hold);
			}
			cout<<"\n\n\n";
			list.suggest_friends();
			
		}
		void my_friends(string user_file_name,string f_name)
		{
			fstream file;
			string hold1,hold,line;
			int  x= 1;
			cout<<"\t\t\tFOLLOWERS"<<endl<<endl;
			file.open(user_file_name.c_str(),ios::in | ios::app);
			while(getline(file,line))
			{
				stringstream info(line);
				getline(info,hold1,',');
				getline(info,hold,',');
				cout<<"\t\t\t"<<hold<<endl;
			}
			cout<<"\t\t\t_______________________________________"<<endl;
		}
		void write_a_post(string user_file_name)
		{
			string post_ext = "post.csv",line,hold;
			cout<<user_file_name<<endl;
			int flag = 0;
			user_file_name = user_file_name + post_ext;
			fstream file(user_file_name.c_str(), ios::in | ios::app);
			while(getline(file,line))
			{
				stringstream info(line);
				getline(info,hold,',');
				getline(info,hold,',');
				flag++;
			}
			cout<<"\t\tWRITE SOMETHING \t\t\n\t\t\t";
			fflush(stdin);
			getline(cin,hold);
			cout<<"\t\t\t\t\tUPLOAD\t\tPRESS [1]\n"<<endl
				<<"\t\t\t\t\tDISCARD\t\tPRESS [2]\t";
				cin>>x;
				if(x == 1)
				{
					fstream file1;
					file1.open(user_file_name.c_str(), ios::in | ios::app);
					file1<<flag<<","<<hold<<"\n";
					file1.close();
				}
				else if( x == 2)
				{
					cout<<"\t\t\tPOST DISCARD"<<endl;
				}
				system("cls");
				file.close();
		}
		void show_my_post(string user_file_name)
		{
			string post_ext = "post.csv",line,hold;
			int flag = 0,scroll;
			user_file_name = user_file_name + post_ext;
			fstream file(user_file_name.c_str(), ios::in | ios::app);
			cout<<"\t\tYOUR PROFILE"<<endl
				<<"________________________________________________________________________________"<<endl;
			while(getline(file,line))
			{
				stringstream info(line);
				fflush(stdin);
				getline(info,hold,',');
				fflush(stdin);
				getline(info,hold,',');
				flag++;
				cout<<"POST : "<<flag<<"\t\t"<<hold<<endl<<endl;
				if(flag%5 == 0)
				{
					cout<<"\n\n\t\t\tSCORLL DOWN \t\tPRESS [5] \t"<<endl
						<<"\t\t\tBACK\t\t\tPRESS [0] \t\n\n";
						cin>>scroll;
				}
				cout<<"________________________________________________________________________________"<<endl;
				if(scroll == 0)
				{
					system("cls");
					break;
				}
			}	
		}
};
class sign_up : public login
{
    private:
        string f_name;
        string l_name;
        string email;
        string password;
        string gender;
    public:
	    sign_up()
	    {
			file.open("info.csv", ios::in | ios::app);	
	        int flag = 0; //count "@" in email
		    int y = 1;
	        fstream file2;
		    file2.open("info.csv", ios::in | ios::app);
		    string hold_string,hold_string1 = "",email_from_file,f_name_from_file;
		    	while( y != -1)
				{
	        		cout<<"\t\tENTER YOUR FIRST NAME : \t";
					fflush(stdin);
					getline(cin,f_name);
					while(getline(file2,hold_string))
			    	{
						stringstream info(hold_string);
						fflush(stdin);
						getline(info,f_name_from_file,',');	      
						fflush(stdin);
						getline(info,hold_string1,',');
						fflush(stdin);
						getline(info,email_from_file,',');
						fflush(stdin);
						getline(info,hold_string1,',');
						if(f_name_from_file == f_name)
						{
							cout<<"\t\tALREADY ACCOUPIED"<<endl
								<<"\t\tPLEASE RE-ENETR YOU FRIST NAME~"<<endl;
								system("pause");
								file2.close();
								file2.open("info.csv", ios::in | ios::app);
								system("cls");
								y = 2;
								break;
						}
						else
						{
							y = -1;
						}  
					}				
				}
			file2.close(); 			
	        cout<<"\t\tENTER YOUR LAST NAME : ";
	        fflush(stdin);
	        getline(cin,l_name);
	        while( x != -1)
	        {
	            cout<<"\t\tENTER YOUR EMAIL ID : ";
	            cin>>email;
	            int size = email.size();
	            for(int i = 0; i < size ; i++)
	            {
	                if(email[i] == '@')
	                {
	                    for(int  j = i ; j < size ; j++)
	                   {
	                        if(email[j] == '.')
	                        {   j++;
	                            if(email[j] == 'c')
	                            {   j++;
	                                if(email[j] == 'o')
	                                {   j++;
	                                    if(email[j] == 'm')
	                                    {
	                                        flag++;
	                                        break;
	                                    }
	                                }
	                            }
	                        }
	                    }
	                }
	            }
	                if(flag == 1)
		            {
		                fstream file1;
		                file1.open("info.csv", ios::in | ios::app);
		                string hold_string,hold_string1,email_from_file;
		                while(getline(file1,hold_string))
		                {
							stringstream info(hold_string);
							getline(info,hold_string1,',');	      
							getline(info,hold_string1,',');
							getline(info,email_from_file,',');
							getline(info,hold_string1,',');
							if(email_from_file == email)
							{
								y = 2;
							}  
						}
						file1.close();
		                if(y == 2)
		                {
		                	cout<<"\t\t\t----ALREADY EXIST----"<<endl;
		                	cout<<"\t\tPLEASE RE-ENTER YOUR EMAIL ID"<<endl;
		                	fflush(stdin);
		                	system("pause");
		                	x = 1;
		                	flag = 0;
						}
						else
						{
							x = -1;
						}
						y = 1;
					}
					else
					{
		                cout<<"\t\t\t----INVALID EMAIL ID----"<<endl;
					}
		            system("cls");
	            }
	            fstream post_file;
	            string user_name;
	            string ext = ".csv",hold_name,post_file_name = "post.csv";
	        	file<<f_name<<","<<l_name<<","<<email<<",";
	            hold_name = user_name = f_name;
	            post_file_name = f_name + post_file_name;
	            f_name  = f_name + ext;
	            personal_profile.open(f_name.c_str(), ios::in | ios::app);
	            post_file.open(post_file_name.c_str(),ios::in | ios::app);
	            x = 1;
	            int count_char = 0;//character counter
	            int count_sp = 0;
	            while(x != -1)
	            {
	                cout<<"\t\tENTER YOUR PASSWORD "
	                <<endl<<"\t\tPASSWORD SHOULD BE MINIMUM 4 CHARACTERS OR MAX MAXIMUM 8 CHARACTERS : "<<endl<<"\t\t";
	                fflush(stdin);
	        		getline(cin,password);
	                int size = password.size();
	                if(size <= 8 && size >= 4)
	                {
	                	system("cls");
	                    string re_pass;
	                    cout<<"\t\tRE-TYPE PASSWORD : ";
	                    cin>>re_pass;
	                    if(password == re_pass)
	                    {
	                        x = -1;
	                    }
	                    else
	                    {
	                    	cout<<"\t\tPASSWORD COULDN'T FOUND"<<endl;
						}
	                }
	            }
	                file << password << "," << f_name << "," << post_file_name << "\n";
	                file.close();
	        	char letter = f_name[0];    
				string file;
				if(letter == 'a' || letter == 'A') 				file = "a_data.csv";		
				else if(letter == 'b' || letter == 'B')				file = "b_data.csv";
				else if(letter == 'c' || letter == 'C')				file = "c_data.csv";
				else if(letter == 'd' || letter == 'D')				file = "d_data.csv";
				else if(letter == 'e' || letter == 'E')				file = "e_data.csv";
				else if(letter == 'f' || letter == 'F')				file = "f_data.csv";
				else if(letter == 'g' || letter == 'G')				file = "g_data.csv";
				else if(letter == 'h' || letter == 'H')				file = "h_data.csv";
				else if(letter == 'i' || letter == 'I')				file = "i_data.csv";
				else if(letter == 'j' || letter == 'J')				file = "j_data.csv";
				else if(letter == 'k' || letter == 'K')				file = "k_data.csv";
				else if(letter == 'l' || letter == 'L')				file = "l_data.csv";
				else if(letter == 'm' || letter == 'M')				file = "m_data.csv";
				else if(letter == 'n' || letter == 'N')				file = "n_data.csv";
				else if(letter == 'o' || letter == 'O')				file = "o_data.csv";
				else if(letter == 'p' || letter == 'P')				file = "p_data.csv";
				else if(letter == 'q' || letter == 'Q')				file = "q_data.csv";
				else if(letter == 'r' || letter == 'R')				file = "r_data.csv";
				else if(letter == 's' || letter == 'S')				file = "s_data.csv";
				else if(letter == 't' || letter == 'T')				file = "t_data.csv";
				else if(letter == 'u' || letter == 'U')				file = "u_data.csv";
				else if(letter == 'v' || letter == 'V')				file = "v_data.csv";
				else if(letter == 'w' || letter == 'W')				file = "w_data.csv";
				else if(letter == 'x' || letter == 'X')				file = "x_data.csv";
				else if(letter == 'y' || letter == 'Y')				file = "y_data.csv";
				else if(letter == 'z' || letter == 'Z')				file = "z_data.csv";
				else												file = "missing_data.csv";
		        fstream file3;
		        file3.open(file.c_str(), ios::in | ios::app);
		        file3<<hold_name<<","<<f_name<<","<<post_file_name<<"\n";
		        file3.close();
	            post_file.close();
	            new_window(f_name,user_name);
	    }  
};

template <typename T>  
void AVL<T> :: searchup(string user_file_name)
{
	int i;
	do
	{
		AVL<string> t;
		int option = 0;
		string line,hold;
		string search;
		cout<<"\t\t\tTYPE... : ";
		cin>>search;
	    t.ssearch(search);
	    node<T>* data = t.searchstring(search);
	    string filename = data->value;
	    string username = data->key;
		fstream file;
		cout<<"\t\t\tFOLLOW\t\t\tPRESS[ 1 ]"<<endl
			<<"\t\t\tDISCARD\t\t\tPRESS [ 0 ]";
			cin>>option;
			if(option == 1)
			{
				file.open(user_file_name.c_str(),ios::in |ios::app);
				file << filename <<","<< username <<"," <<1<<"\n";
				file.close();
				cout<<"\t\t\tNOW YOU FOLLOW "<<username<<endl;
			}
			else if(option == 0)
			{
				cout<<"\t\t\tDISCARD"<<endl;
			}
		cout<<endl<<endl;
		cout<<"\t\t\tSEARCH\t\t\tPRESS [ 1 ]"<<endl
			<<"\t\t\tBACK\t\t\tPRESS [ 0 ]";
		cin>>i;
	}while(i != 0);
}	
		
	
	
	
	
	
int main()
{
	int op;
    	while(x != -1)
    	{
	    	cout << "\t**      **      ";
			cout << "\n\t**      ** ******* **      ****** ******** ****** *** ***********";
			cout << "\n\t**      ** **      **      **     **    ** **  **  ** ***      ";
			cout << "\n\t**  **  ** *****   **      **     **    ** **  **  ** **********    ";
			cout << "\n\t**  **  ** **      **      **     **    ** **  **  ** ***             ";
			cout << "\n\t********** ******* ******* ****** ******** **      ** ************     ";
    		cout<<"\n\t\t\tINSTAGRAM MODEL"<<endl;
    		cout<<"\t\t\tLOGIN\tPRESS [ 1 ] "<<endl
    		<<"\t\t\tSIGN UP\tPRESS [ 0 ] \t";
    		cin>>op;
    		system("cls");
    		switch(op)
    		{
    			case 0 : 
    			{
    				sign_up list;   			
    				break;
				}
				case 1:
				{
					login list("start");
					break;		
				}
			}
			cout<<"PRESS [0] BACK \t PRESS [2] TO EXIT: ";
			cin>>x;
			if(x == 2)
				x = -1;
			system("cls");
		}
}
