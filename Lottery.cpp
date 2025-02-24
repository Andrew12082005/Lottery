#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void lottery(int n,long long earn);


int main(){
    int n;
    srand(time(NULL));
    cin>>n;
    long long earn = 0;
    lottery(n,earn);
    return 0;
}

void lottery(int n, long long earn){
    
    long long **num = new long long*[n];
    for(int i = 0 ; i < n ; i++){
        num[i] = new long long [8];
    }

    int *lnum = new int[7];
    for(int k = 0 ; k < 6 ; k++){
        lnum[k] = rand() % 38+1;
    }
    lnum[6] = rand() % 8+1;
    cout<<"Lucky Number : ";
    for(int q = 0 ; q < 7 ; q++){
        cout<<lnum[q]<<" ";
    }
    cout<<endl;


    for(int i = 0 ; i < n ; i++){
        
        for(int k = 0 ; k < 6 ; k++){
            num[i][k] = rand() % 38+1;
        }
        num[i][6] = rand() % 8+1;
        num[i][7] = -100;
        
        int ct = 0;
        bool sc = false;
        for(int p = 0 ; p<6 ; p++){
            for(int q = 0 ; q<6 ; q++){
                if(num[i][p] == lnum[q]) ct++;
            }
        }
        if(num[i][6] == lnum[6]) sc=true;
        cout<<i+1<<" : "; 
        
        if(ct ==1 && sc == true) num[i][7] = num[i][7]+100;
        else if(ct ==3 && sc == false) num[i][7] = num[i][7]+100;
        else if(ct ==2 && sc == true) num[i][7] = num[i][7]+200;
        else if(ct ==3 && sc == true) num[i][7] = num[i][7]+400;
        else if(ct ==4 && sc == false) num[i][7] = num[i][7]+800;
        else if(ct ==4 && sc == true) num[i][7] = num[i][7]+4000;
        else if(ct ==5 && sc == false) num[i][7] = num[i][7]+20000;
        else if(ct ==5 && sc == true) num[i][7] = num[i][7]+150000;
        else if(ct ==5 && sc == false) num[i][7] = num[i][7]+25000000;
        else if(ct ==6 && sc == true) num[i][7] = num[i][7]+200000000;
        
        for(int q = 0 ; q < 8 ; q++){
            cout<<num[i][q]<<" ";
        }
        cout<<ct<<" "<<sc<<endl;
        earn = earn+num[i][7];
    }

    for (int i = 0; i < n; i++) {
        delete[] num[i];
    }
    delete[] num;
    cout<<"Total Earn : "<<earn<<endl;
}
