#include <iostream>
#include <string>
using namespace std ; 
int mat1[3][3];
int mat2[3][3];
int mat3[3][3];
bool fail = false;
int index_stroki;
int index_marix;
int index_str;
bool stroka(int array[3])
{       
        string str1;
        int numb=0;
        if( !getline(cin , str1) || str1.length()==0)
        {
            fail= true;        
        }
        else 
        {
            index_stroki=0;
            int len= str1.length();
            for (int index_str=0 ; index_str<len;index_str++)
            {
                int k=1;
                numb=numb*k;
                if(str1[index_str]!=' ')
                {
                    numb=numb+((int)str1[index_str]-'0');
                    k=k*10;
                    array[index_stroki]=numb;
                }   
                else
                {
                    index_stroki++;
                    numb=0;
                    k=0;
                }    
            }   
        }
        if (index_stroki!=2) fail=true;    
        return !fail;    
}
int main()
{
    for(int index_marix=0; index_marix<3 ;index_marix++)
    {
        if( !(stroka(mat1[index_marix])))
        {
            cout <<  "fail";
            return -1;
        }
    }
    char ch;
    cin >> ch;
    cin.get();
    for(int index_marix=0; index_marix<3 ;index_marix++)
    {
        if( !(stroka(mat2[index_marix])))
        {
            cout <<  "fail"; 
            return -1 ;
        }
    }    
    
    
    if(ch=='+')
    {
        for( int i = 0; i < 3; ++i ) 
        {
            cout << endl; 
            for( int j = 0; j < 3; ++j ) 
            {
                cout<<mat1[i][j]+mat2[i][j]<<" ";
            }
        }
    }
    else if(ch == '-')
    {
        for( int i = 0; i < 3; ++i ) 
        {
            cout<<endl;
            for( int j = 0; j < 3; ++j ) 
            {
                cout<<mat1[i][j]-mat2[i][j]<<" ";
            }
        }
    }
    else if(ch=='*')
    {
        for( int i = 0; i < 3; ++i ) 
        {
            cout<<endl;
            for( int j = 0; j < 3; ++j ) 
            {
                int result = 0;
                for( int k = 0; k < 3; ++k ) 
                {
                    result += mat1[i][k] * mat2[k][j];                              
                }
                mat3[i][j] = result;
                cout << mat3[i][j]<<" ";                                     
            }
        } 
    }
       

}
