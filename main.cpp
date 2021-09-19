#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "binarysearchtree.cpp"
using namespace std;
int game()
{
    int coin =0;

                                cout<<"                                        ///// Enter 1,2,3 or 4 to answer \\\\\\\\\\ "<<endl;
    cout<<endl;

    int in;
    TreeType<string> t;
    TreeType<int> t1;
    t.InsertItem("Q4.What_is _the_resolution_of_human_eye_?\n1.325_Megapixels\n2.454_Megapixels\n3.576_Megapixels\n4.625_Megapixels\nANSWER:");
    t.InsertItem("Q1.Can_you_fire_a_gun_in_space?\n1.yes\n2.no\nANSWER:");
    t.InsertItem("Q2.What's_the_speed_of_the_darkness?\n1.No_speed_at_all\n2.3x10^8m/s\n3.0m/s\n4.5m/s\nANSWER:");
    t.InsertItem("Q3.What_if_you_were_born_in_space?\n1.You_will_be_stronger\n2.You_will_be_weaker\nANSWER:");
    t.InsertItem("Q5.Which_river_carries_maximum_quantity_of_water_into_the_sea?\n1.Thames\n2.Hantan\n3.Avon\n4.Amazon\nANSWER:");
    t1.InsertItem(1);
    t1.InsertItem(2);
    t1.InsertItem(3);
    t1.InsertItem(1);
    t1.InsertItem(4);
    t.ResetTree(IN_ORDER);
    t1.ResetTree(IN_ORDER);
    try{

    for(int j=0; j<5; j++)
    {
        bool found;
        int i;
        string s;
        t.GetNextItem(s,IN_ORDER,found);
        cout<<s;
        cin>>in;
        cout<<endl;
        cout<<endl;
        t1.GetNextItem(i,IN_ORDER,found);
        if(i==in)
        {
            cout<<"CORRECT ANSWER!!"<<endl;
            coin+=50;
        }
        else
        {
            cout<<"Game Over!!\n Correct answer is: "<<i<<endl;
            cout<<"you gained "<<coin<<" coins"<<endl;
            break;
        }
        cout<<"YOU GAINED "<<coin<<" COINS!!!"<<endl;
        cout<<endl;
    }
    return coin;
    }

    catch(EmptyQueue e)
    {
        cout<<"Empty tree"<<endl;
    }
}
int main()
{
    cout<<"                         **********<<<<<<<<>>>>>>>> EARN BY KNOWLEDGE <<<<<<<<>>>>>>>>**********"<<endl;
    cout<<"                       A C++ program based project made by Subah ibnat karim & Tanisha kabir kakon   ";
    cout<<endl;
    cout<<endl;
    cout<<"                                      <<<>>>PRESS 1 OR 2 TO SIGN IN OR SIGN UP<<<>>>\n                                          1.Sign In\n                                          2.Sign Up"<<endl;
    int sign;
    string name;
    string pass;
    cin>>sign;

    fstream myfile;
    myfile.open("profile.txt");

    if(sign==2)
    {
     cout<<"Username: ";
     cin>>name;
     cout<<endl;
     cout<<"Password: ";
     cin>>pass;
     cout<<endl;
     int age;
     cout<<"Age: ";
     cin>>age;
     cout<<endl;
     string country;
     cout<<"Country: ";
     cin>>country;
     cout<<endl;

     if(myfile.is_open())
     {
         myfile<<name <<endl;
         myfile<<pass<< endl;
         myfile<<age<<endl;
        myfile<<country<<endl;
         myfile.close();
     }


     cout<<endl;
     cout<<endl;
     cout<<"<<<<>>>>Account successfully created<<<<>>>>"<<endl;
     cout<<endl;
     cout<<endl;
     main();
    }

    else if(sign==1)
    {
       std::string line;
        cout<<"Username: ";
        cin>>name;
        cout<<endl;
        if(myfile.is_open())
        {
            std::getline(myfile,line);
            for(int i=0; i<2; i++)
            {if(i==0){
                    for(int j=0; j<name.length(); j++){
                        if(name[j]==line[j])
                        {
                        }
                        else{
                        cout<<"wrong username"<<endl;
                        cout<<endl;
                        main();
                        }
                    }
                }
            else if(i==1)
                {
                    std::getline(myfile,line);
                                cout<<"Password: ";
                                cin>>pass;
                                cout<<endl;
                    for(int j=0; j<pass.length(); j++)
                    {
                    if(pass[j]==line[j])
                        {
                            std::string msg;
                    cout<<"<<<>>>>PRESS 1 or 2 FOR FURTHER QUERY<<<>>>\n1.Show Info\n2.Play Game"<<endl;
                            cout<<endl;
                            int ant;
                            cin>>ant;
                            switch(ant)
                            {
                            case 1:
                                {
                                    cout<<endl;
                                    if(myfile.is_open()){
                                while(std::getline(myfile,msg)){

                                    cout<<msg<<endl;
                                    }
                                }
                                break;
                                }
                            case 2:
                                {
                                    int coin=game();
                                    if(myfile.is_open()){
                                        myfile<<coin<<endl;
                                        myfile.close();
                                    }
                                   break;
                            }

                            }
                }

                else
                            {
                    cout<<"wrong password"<<endl;
                    cout<<endl;
                    main();
                    }
                    }


        }
            }
    }
        }

    else
        {
        cout<<"WRONG INPUT!!!"<<endl;
        main();
    }

    return 0;
}



