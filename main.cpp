#include <iostream>
#include <string>
using namespace std ; 
int mat1[3][3];
int mat2[3][3];
int mat3[3][3];
bool fail = false;
int y,x;
bool sucsess=true;
bool stroka(int array[3])
    {       
        string str1;
        int a=0;
        if( !getline(cin , str1) || str1.length()==0)
        {
            fail= true;        
        }
        else 
        {
            x=0;
            int len= str1.length();
            for (int i=0 ; i<len;i++)
            {
                int k=1;
                a=a*k;
                if(str1[i]!=' ')
                {
                    a=a+((int)str1[i]-'0');
                    k=k*10;
                    array[x]=a;
                }   
                else
                {
                    x++;
                    a=0;
                    k=0;
                }    
            }   
        }
        if (x!=2) fail=true;    
        return !fail;    
    }
int main()
{
    for(int y=0; y<3 ;y++)
    {
        if( stroka(mat1[y]))
        {}
        else 
        {   
            cout <<  "fail";
            return -1;
        }
    }
    char ch;
    cin >> ch;
    cin.get();
    for(int y=0; y<3 ;y++)
    {
        if( stroka(mat2[y]))
        {}
        else 
        {   
            cout <<  "fail"; 
            return -1 ;
        }
    }    
    if(!fail)
    {
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

}
