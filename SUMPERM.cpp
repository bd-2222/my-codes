#include <iostream>
using namespace std;
int answerfinder(int *array1,int *array2,int len,int pointer=2,int sum=1){
    //base
    if(len==pointer-1){
        for(int v=0;v<len;v++){
            cout<<*(array1+v)<<" ";
        }
        cout<<endl;
    return 0;
    }

    
    //process
    bool checker=true;
    for(int e=0;e<len;e++){
        if(*(array2+e)>0 && (sum+*(array2+e))%pointer!=0){
            *(array1+pointer-1)=*(array2+e);sum=sum+*(array2+e);
            *(array2+e)=0;
            checker=false;
            break;
        }
    }
    if(checker==true){
        return -1;
    }
    
    //recurse
    
    return answerfinder(array1,array2,len,pointer+1,sum);
}

int main() {
	// your code goes here
	int _BD_;
	cin>>_BD_;
	while(_BD_--){
	    int len;
	    cin>>len;
	    int *array1=new int[len];
	    int *array2=new int[len];
	    for(int d=1;d<=len;d++){
	        *(array2+d-1)=d;
	    }
	    *array2=0;
	    *array1=1;
	    int printnegitive1true=answerfinder(array1,array2,len);
	    if(printnegitive1true==-1){
	        cout<<-1<<endl;}
	    delete []array1;
	    delete []array2;
	}
	return 0;
}
//https://www.codechef.com/problems/SUMPERM
