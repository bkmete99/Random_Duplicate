#include <iostream>
#include <iomanip>

#include <sstream>
#include <string>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

//BURAK KARAMETE
//150170014

int main(int argc,char * argv[]) {

    int count=0;    //for counting how many duplications are there
    srand(time(NULL)); //Make real randomness
    int N=strtol(argv[1], 0, 0);//taking argument from command line

 string output;//for print


            int *A = new int[N + 1]; //for array with argument number

            cout<<"Array"<<endl;

            for (int i = 1; i < N + 1; i++) {
                int r = (rand() % N) + 1; //random numbers 1 to n
                A[i] = r;//assigning this random num to arrays element
                cout<<A[i]<<"\t";//printing elements
                if(i%10==0 ||i==N){cout<<endl;}//for displaying purpose every ten number new line

            }

            for (int i = 1; i < N + 1; i++) {
                for (int j = i + 1; j < N + 1; j++) {
            //Look for all pairs
                    if (A[i] == A[j]) {
                        //if i<j and a[i]==a[j]
                        //this is a duplication
                        count++;
                        output += "(";
                        ostringstream str1, str2;//to make string to int
                        str1 << i;
                        output += str1.str();
                        str2 << j;
                        output += "," + str2.str() + ")";
                        if (count % 10 == 0) { output += '\n'; }//for displaying purpose every ten new line
                    }
                }
            }

            double expect=((N)*(N-1))/(2.0*N);
            cout<<"EXPECTED NUMBER OF DUPLICATIONS = "<<expect<<endl;//how many duplications

            cout << output << endl;
            cout << "ENCOUNTERED NUMBER OF DUPLICATIONS =  " << count<<endl;

    return 0;
}