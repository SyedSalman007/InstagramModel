#include<iostream>
#include<fstream>
#include<sstream>
//#include<dos.h>
//#include <cstdlib>
//#include <Windows.h>
using namespace std;
fstream file,personal_profile;
int x = 1;
class sign_up
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
            string ext = ".csv";
        	file<<f_name<<",";
        	file<<l_name<<",";
            file<<email<<",";
            f_name  = f_name + ext;
            personal_profile.open(f_name.c_str(), ios::in | ios::app);
            personal_profile<<email<<",";
            
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
                file<<password<<",";
                file << f_name <<"\n";
                file.close();
        	char letter = f_name[0];    
			string file;
			if(letter == 'a' || letter == 'A')
			{
				file = "a_data.csv";
			}
			else if(letter == 'b' || letter == 'B')
			{
				file = "b_data.csv";
			}
			else if(letter == 'c' || letter == 'C')
			{
				file = "c_data.csv";
			}
			else if(letter == 'd' || letter == 'D')
			{
				file = "d_data.csv";
			}
			else if(letter == 'e' || letter == 'E')
			{
				file = "e_data.csv";
			}
			else if(letter == 'f' || letter == 'F')
			{
				file = "f_data.csv";
			}
			else if(letter == 'g' || letter == 'G')
			{
				file = "g_data.csv";
			}
			else if(letter == 'h' || letter == 'H')
			{
				file = "h_data.csv";
			}
			else if(letter == 'i' || letter == 'I')
			{
				file = "i_data.csv";
			}
			else if(letter == 'j' || letter == 'J')
			{
				file = "j_data.csv";
			}
			else if(letter == 'k' || letter == 'K')
			{
				file = "k_data.csv";
			}
			else if(letter == 'l' || letter == 'L')
			{
				file = "l_data.csv";
			}
			else if(letter == 'm' || letter == 'M')
			{
				file = "m_data.csv";
			}
			else if(letter == 'n' || letter == 'N')
			{
				file = "n_data.csv";
			}
			else if(letter == 'o' || letter == 'O')
			{
				file = "o_data.csv";
			}
			else if(letter == 'p' || letter == 'P')
			{
				file = "p_data.csv";
			}
			else if(letter == 'q' || letter == 'Q')
			{
				file = "q_data.csv";
			}
			else if(letter == 'r' || letter == 'R')
			{
				file = "r_data.csv";
			}
			else if(letter == 's' || letter == 'S')
			{
				file = "s_data.csv";
			}
			else if(letter == 't' || letter == 'T')
			{
				file = "t_data.csv";
			}
			else if(letter == 'u' || letter == 'U')
			{
				file = "u_data.csv";
			}
			else if(letter == 'v' || letter == 'V')
			{
				file = "v_data.csv";
			}
			else if(letter == 'w' || letter == 'W')
			{
				file = "w_data.csv";
			}
			else if(letter == 'x' || letter == 'X')
			{
				file = "x_data.csv";
			}
			else if(letter == 'y' || letter == 'Y')
			{
				file = "y_data.csv";
			}
			else if(letter == 'z' || letter == 'Z')
			{
				file = "z_data.csv";
			}
			else
			{
				file = "missing_data.csv";
			}
	        fstream file3;
	        file3.open(file.c_str(), ios::in | ios::app);
	        file3<<email<<","<<f_name<<"\n";
	        file3.close();
    }  
};
        	
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
        login()
        {
        	string your_password;
            file.open("info.csv" ,ios::in | ios::app);
        	cout<<"\t\tENTER YOUR EMAIL ID : ";
        	fflush(stdin);
            getline(cin,your_email);
            int x = -1;
            string new_line = "";
            while(getline(file,new_line))
            {
                stringstream info(new_line);
                stringstream hold(new_line);
				getline(info,f_name,',');
                getline(info,l_name,',');
                getline(info,get_email_from_server,',');
			    getline(info,password_from_server,',');
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
			}
			if(x == -1)
				cout<<"\t\t\t----USER NOT FOUND----"<<endl;
			file.close();
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
    		cout<<"\t\t\tHOME"<<endl;
    		cout<<"\t\t\tPRESS [1] FOR SEARCH"<<endl
    			<<"\t\t\tPRESS [2] FOR FRIENDS"<<"\t";
    			cin>>x;
    			switch(x)
    			{
    				case 1:
    					{
    						SEARCH();	
    						break;
						}
					case 2:
    					{
    						FRIENDS();
    						break;
						}
					case 3:
    					{
//    						log_out();	
    						break;
						}	
				}
		}
		void SEARCH()
		{
			cout<<"~~~~~~~~~~~~~~~~~~"<<endl;
		}
		void FRIENDS()
		{
			cout<<"@@@@@@@@@@@@@@@@@@@@@@"<<endl;
		}
		void write_a_post()
		{
			
		}
};
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
					login list;
					break;		
				}
			}
			cout<<"PRESS [0] BACK \t PRESS [2] TO EXIT: ";
			cin>>x;
			if(x == 2)
				x = -1;
			system("cls");
		}
    return 0;
}
