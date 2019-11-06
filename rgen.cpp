#include <iostream>
#include<random>
#include<fstream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<algorithm>
#include <unistd.h>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<utility>
//#include<windows.h>

using namespace std;

int main (int argc, char **argv)
{
    srand(time(0));
    ofstream outfile;
    outfile.open("out.txt");
    static constexpr char alphanum[] = {"abcdefghijklmnopqrstuvwxyz"
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        };

    int sflag,nflag,lflag,cflag = 0;
    string svalue,nvalue,lvalue,cvalue;
    int s = 10;
    int n = 5;
    int c = 20;
    int s2 = 20*(-1);
    int l = 5*(1000);
    int x,y;
    int Arrayx[500];
    int Arrayy[500];
    vector<int> myVector;
    vector<int> myVector2;
    string pass;
    int random_street,random_linesegment,random_coordinates;
    int option;

    while(!cin.eof()){
    while ((option = getopt (argc, argv, "s:n:l:c:")) != -1)
        switch (option)
        {
        case 's':
            if(sflag);
            //cout<<"found s"<<endl;
            svalue = optarg;
            s = atoi(svalue.c_str());
            //cout<<s<<endl;
            break;

        case 'n':
            if(nflag);
            //cout<<"found n"<<endl;
            nvalue = optarg;
            n = atoi(nvalue.c_str());
            //cout<<n<<endl;
            //cout<<"here"<<endl;
            break;

        case 'l':
            if(lflag);
            //cout<<"found l"<<endl;
            lvalue = optarg;
            int l1;
            l1 = atoi(lvalue.c_str());
            l = l1*1000;
            //cout<<l<<endl;
            break;

        case 'c':
            if(cflag);
            //cout<<"found c"<<endl;
            cvalue = optarg;
            c = atoi(cvalue.c_str());
            //cout<<c<<endl;
            s2 = c*(-1);
            break;

        default:
            return 0;


        }

        random_street = (rand()% (s - 2 + 1)) + 2;
        //cout<<"Number of Streets are:"<<random_street<<endl;
        random_linesegment = (rand()% (n - 1 + 1)) + 1;
        //cout<<"Number of Line segments are:"<<random_linesegment<<endl;
        const unsigned int sizeofArray = 500;
        string myArray[sizeofArray];
        for (int i=0;i<random_street;i++)
        {


            myArray[i] =  alphanum[rand()%(sizeof(alphanum)-1)]  ;
            cout<<"a"<<" "<<'"'<<myArray[i]<<'"';
            outfile<<"a"<<" "<<'"'<<myArray[i]<<'"';



            for(int j=0;j<random_linesegment + 1;j++)
            {

                Arrayx[j] = (rand()%(c - s2 +1)) + s2;
                myVector.push_back(Arrayx[j]);
                Arrayy[j] = (rand()%(c - s2 + 1)) + s2;
                myVector.push_back(Arrayy[j]);

                //pair<int,int> pairs = make_pair(Arrayx[j],Arrayy[j]);
                //cout<<" "<<pairs.first<<" "<<pairs.second;
                cout<<" "<<"("<<Arrayx[j]<<","<<Arrayy[j]<<")";
                outfile<<" "<<"("<<Arrayx[j]<<","<<Arrayy[j]<<")";
            }
            cout<<endl;
            outfile<<endl;
        }


        //for(int i=0;i<myVector.size();i++){
            //cout<<myVector[i]<<" ";
        //}
        cout<<"g"<<endl;
        outfile<<"g"<<endl;

nanosleep(l);
for(int i=0;i<random_street;i++){
    cout<<"r"<<" "<<'"'<<myArray[i]<<'"'<<endl;
    outfile<<"r"<<" "<<'"'<<myArray[i]<<'"'<<endl;
}


for(int i=0;i<myVector.size();i++){
    myVector.clear();
}
//outfile.close();


    }


}
