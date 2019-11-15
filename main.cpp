#include <iostream>
#include <iomanip>

#include <sstream>
#include <string>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

//this program initialize array with N (N in loop 1 to 100) and in these arrays;
//lets assume N is 30, randomly choose 30 number in interval 1-30 and in all these numbers
//counting how many duplicated pairs
//In the result we will see a relation between array number and duplicated number
//Since we will execute this code 100 times in every N number;choose is more right randomly and statistically give us a result

int main(int argc,char** argv) {
    int N=30,count=0;
    double oran=0;
    srand(time(NULL)); //Make real randomness
    int maxN=0;
    float* ora=new float[100];
    while(maxN<100) {

        int *Stat = new int[100];
        for (int i = 0; i < 100; i++) {
            Stat[i] = 0;
        }

        int trynumber = 100;//how many times will this execute
        string output;

        while (trynumber != 0) {
            count = 0;
            int *A = new int[maxN + 1];


            for (int i = 1; i < maxN + 1; i++) {
                int r = (rand() % maxN) + 1; //random numbers 1 to n
                A[i] = r;
                //Stat[i] = 0;
            }

            for (int i = 1; i < maxN + 1; i++) {
                for (int j = i + 1; j < maxN + 1; j++) {
                    if (A[i] == A[j]) {
                        count++;
                        output += "(";
                        ostringstream str1, str2;
                        str1 << i;
                        output += str1.str();
                        str2 << j;
                        output += "," + str2.str() + ")";
                        if (i % 10 == 0) { output += '\n'; }
                    }

                }
            }
            //cout << output << endl;
            //cout << "Total duplicated number is " << count;
            Stat[count]++;
            trynumber--;
        }

        //max for this number
        float max = 0,maxnum=0,orannow=0;
        int a=0;
        while (a < 100) {
            if (Stat[a] > max) { maxnum = a;max=Stat[a]; }
            a++;
        }
       

        if(maxN>2){ int expect=((maxN)*(maxN-1))/(2*maxN);
         cout <<"Array size"<<maxN<<":"<<maxnum<<endl;
        cout<<"Expected is "<<expect<<endl;
        cout<<"Error rate :%"<<(abs(expect-maxnum)/expect)*100<<endl<<endl;}
      
        maxN++;
    }
    
    return 0;
}
