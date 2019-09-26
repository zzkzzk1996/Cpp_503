//Zekun Zhang       Oct.1.2018
//Use Vector to perform matrix operations

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include<iomanip>

using std::setw;

#include <vector>

using std::vector;

//R represents Row and C represents Col, which are used to input Row and Col to the matrix.
//R1 and C1 are for an another matrix
//det is the final result of determinant and firstly initialize it
int R,C;
int R1,C1;
double det=0;

//the menu module for the calculator system
void ShowMenu()
{
    cout<<"Menu"<<endl;
    cout<<" Choice 1: Addition"<<endl;
    cout<<" Choice 2: Subtraction"<<endl;
    cout<<" Choice 3: Multiplication"<<endl;
    cout<<" Choice 4: Transpose"<<endl;
    cout<<" Choice 5: Determinant"<<endl;
    cout<<" Choice 6: Inverse"<<endl;
    cout<<" Choice 7: Quit"<<endl;
    cout<<"Please enter your choice(Use numbers):"<<endl;
}

//the input module for the row and col of the first matrix we used
void InputRandC()
{

    cout << "Please inter the number of the Row and Max is 10" << endl;
    cin >> R;
    //use the while loop to finish error correction for input
    while(R<=0||R>10)
    {
        cout << "Please inter the number of the Row and Max is 10" << endl;
        cin >> R;
    }

    cout << "Please inter the number of the Col and Max is 10" << endl;
    cin >> C;
    //use the while loop to finish error correction for input
    while(C<=0||C>10)
    {
        cout << "Please inter the number of the Col and Max is 10" << endl;
        cin >> C;
    }

}

//the input module for the row and col of the second matrix we used
void InputR1andC1()
{
    cout << "Please inter the number of the Row" << endl;
    cin >> R1;
    //use the while loop to finish error correction for input
    while(R1<=0||R1>10)
    {
        cout << "Please inter the number of the Row" << endl;
        cin >> R1;
    }
    cout << "Please inter the number of the Col" << endl;
    cin >> C1;
    //use the while loop to finish error correction for input
    while(C1<=0||C1>10)
    {
        cout << "Please inter the number of the Col" << endl;
        cin >> C1;
    }

}

//the input module for the values of the matrix
void InputVector(vector< vector<double> >&array,int Row,int Col)
{
    //use a 1D-vector 'line' to contain the data in a row
    vector<double> line;

    cout<<"Please enter the Matrix:"<<endl;

    for (int i = 0;i<Row;i++)
    {
        for (int j = 0; j < Col; j++)
        {
            //use temp to contain a input and then push it to the 'line'
            double temp;
            cin >> temp;
            line.push_back(temp);
        }
        cout << endl;
        //push the data in a row to the 2D-vector 'array'
        array.push_back(line);
        //release the vector 'line'
        line.erase(line.begin(),line.end());
    }
}

//the output module for the matrix
void OutputVector(const vector< vector<double> >&array,int Row,int Col)
{
    cout<<"The Matrix is:"<<endl;
    //use for loop to finish the output of every row and col
    for (int i = 0;i<Row;i++)
    {
        for(int j=0;j<Col;j++)
        {
            cout<<setw(10)<<array[i][j];
        }

        cout<<endl;
    }

}

//the initialize module before the vector is used
void Initialize(vector< vector<double> >&array,int Row,int Col)
{
    //use a 1D-vector 'line' to contain the data in a row
    vector<double> line;

    for (int i = 0;i<Row;i++)
    {
        for (int j = 0; j < Col; j++)
        {
            //push zeros to the row
            line.push_back(0);
        }
        cout << endl;
        //push the data in a row to the 2D-vector 'array'
        array.push_back(line);
        //release the vector 'line'
        line.erase(line.begin(),line.end());
    }
}

//the add operation module
void Add(vector< vector<double> >&array1,vector< vector<double> >&array2,vector< vector<double> >&array3,int Row,int Col)
{
    //use for loop to traverse every data in the matrix
    for(int i=0;i<Row;i++)
    {
        for(int j=0;j<Col;j++)
        {
            //add the very data in array1 and array2 to array3
            array3[i][j]=array1[i][j]+array2[i][j];
        }
    }
}

//the subtract operation module
void Subtraction(vector< vector<double> >&array1,vector< vector<double> >&array2,vector< vector<double> >&array3,int Row,int Col)
{
    //use for loop to traverse every data in the matrix
    for(int i=0;i<Row;i++)
    {
        for(int j=0;j<Col;j++)
        {
            //subtract the very data in array1 and array2 to array3
            array3[i][j]=array1[i][j]-array2[i][j];
        }
    }
}

//the multiply operation module
void Multiply(vector< vector<double> >&array1,vector< vector<double> >&array2,vector< vector<double> >&array3,int Row1,int Col1,int Col2)
{
    //use for loop to traverse every data in the matrix
    for(int i=0;i<Row1;i++)
    {

        for(int j=0;j<Col2;j++)
        {
            for(int k=0;k<Col1;k++)
            {
                //in multiplication operation, sum up the multiplications between array1's row data and array2's col data
                array3[i][j]+=array1[i][k]*array2[k][j];
            }
        }
    }
}

//the transpose operation module
void Transpose(vector< vector<double> >&array1,vector< vector<double> >&array2,int Row,int Col)
{
    //use for loop to traverse every data in the matrix
    for(int i=0;i<Row;i++)
    {

        for(int j=0;j<Col;j++)
        {
            //give the very data of array1 to the transposed position in array2
            array2[j][i]=array1[i][j];

        }

    }
}

//the determinant operation module
double Determinant(vector< vector<double> >&array1,int n)
{
    //if it is a 1D-matrix return the value to determinant answer
    if(n==1)
    {
        return array1[0][0];
    }

    //use variable 'ans' to contain the determinant answer and firstly initialize it
    double ans=0;

    //use a 2D-vector to contain temporary values in the calculation
    vector< vector<double> > temp;
    temp.resize(n);
    for(int i=0;i<n;i++)
    {
        temp[i].resize(n);
    }

    //initialize this vector
    Initialize(temp,n,n);

    //use the triple loop to calculate the cofactor for one value
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<n-1;j++)
        {
            for (int k = 0; k < n-1; k++)
            {
                temp[j][k] = array1[j+1][(k>=i)?k+1:k];
            }
        }

        //use the function again to do the iteration operation
        double t = Determinant(temp, n-1);

        //the characteristics of the sum for cofactors
        if (i%2 == 0)
        {
            ans+= array1[0][i]*t;
        }
        else
        {
            ans-= array1[0][i]*t;
        }
    }

    //finally return the answer
    return ans;
}

//the adjoint matrix operation module, which is used for calculate the inverse operation
void Adjoint(vector< vector<double> >&array1,vector< vector<double> >&array2,int n)
{
    //use a 2D-vector to contain temporary values in the calculation
    vector< vector<double> > temp;

    temp.resize(n);
    for(int i=0;i<n;i++)
    {
        temp[i].resize(n);
    }

    //initialize this vector
    Initialize(temp,n,n);

    int i,j,k,t;


    for(i=0;i<n;i++)
    {
        //use the triple loop to calculate the cofactor for one value
        for(j=0;j<n;j++)
        {
            for(k=0;k<n-1;k++)
            {
                for(t=0;t<n-1;t++)
                {
                    temp[k][t] = array1[k>=i?k+1:k][t>=j?t+1:t];
                }
            }

            //use function to do determinant operation and then transpose the matrix
            array2[j][i]  =  Determinant(temp,n-1);

            //the characteristics of the adjoint matrix
            if((i+j)%2 == 1)
            {
                array2[j][i] = - array2[j][i];
            }
        }
    }
}

//the inverse matrix operation module and in this way we can calculate any dimension matrix
void Inverse(vector< vector<double> >&array1,vector< vector<double> >&array2,int n)
{
    //use variable 'flag' to use the function and then do further calculate
    double flag=Determinant(array1,R);

    //use a 2D-vector to contain temporary values in the calculation
    vector< vector<double> > temp;

    temp.resize(n);
    for(int i=0;i<n;i++)
    {
        temp[i].resize(n);
    }

    //initialize this vector
    Initialize(temp,n,n);

    //use the function to calculate adjoint matrix
    Adjoint(array1,temp,n);

    //use for loop to do inverse operation easily
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            array2[i][j]=temp[i][j]/flag;
        }
    }
}

int main()
{
    //use vectors to contain the matrices we will use in the operations
    vector< vector<double> > arrayA;
    vector< vector<double> > arrayB;
    vector< vector<double> > arrayC;
    vector< vector<double> > arrayD;

    arrayA.resize(R);
    for(int i=0;i<R;i++)
    {
        arrayA[i].resize(C);
    }

    arrayB.resize(R1);
    for(int i=0;i<R1;i++)
    {
        arrayB[i].resize(C1);
    }

    arrayC.resize(R);
    for(int i=0;i<R;i++)
    {
        arrayC[i].resize(C);
    }

    arrayD.resize(R);
    for(int i=0;i<R;i++)
    {
        arrayC[i].resize(C1);
    }


    //show the menu
    ShowMenu();
    //user input choice
    int choice;
    cin>>choice;

    //use the loop to cycle the calculator system unless the user want to quit
    while(choice!=7)
    {
        switch (choice)
        {
            //do the add operation
            case 1:
                //input the row, col and the value to the first matrix and display it
                InputRandC();
                InputVector(arrayA,R,C);
                OutputVector(arrayA,R,C);

                //input the row and col for the second matrix
                InputR1andC1();

                //if they're not in same shape, we can't do the operation and break
                if(R!=R1||C!=C1)
                {
                    cout<<"Can't do this operation"<<endl;
                    break;
                }
                //input the value to the second matrix and display it
                InputVector(arrayB,R1,C1);
                OutputVector(arrayB,R1,C1);

                //initialize this vector to be ready to contain the result
                Initialize(arrayC,R,C);
                //use function do the operation
                Add(arrayA,arrayB,arrayC,R,C);
                //output the result and break
                cout<<"Result:"<<endl;
                OutputVector(arrayC,R,C);
                break;

            //do the subtract operation
            case 2:
                //input the row, col and the value to the first matrix and display it
                InputRandC();
                InputVector(arrayA,R,C);
                OutputVector(arrayA,R,C);

                //input the row and col for the second matrix
                InputR1andC1();
                //if they're not in same shape, we can't do the operation and break
                if(R!=R1||C!=C1)
                {
                    cout<<"Can't do this operation"<<endl;
                    break;
                }
                //input the value to the second matrix and display it
                InputVector(arrayB,R1,C1);
                OutputVector(arrayB,R1,C1);

                //initialize this vector to be ready to contain the result
                Initialize(arrayC,R,C);
                //use function do the operation
                Subtraction(arrayA,arrayB,arrayC,R,C);
                //output the result and break
                cout<<"Result:"<<endl;
                OutputVector(arrayC,R,C);
                break;

            //do the multiply operation
            case 3:
                InputRandC();
                InputVector(arrayA,R,C);
                OutputVector(arrayA,R,C);

                //if the first col do not equal to the second row,we can't do the operation and break
                InputR1andC1();
                if(C!=R1)
                {
                    cout<<"Can't do this operation"<<endl;
                    break;
                }
                InputVector(arrayB,R1,C1);
                OutputVector(arrayB,R1,C1);

                Initialize(arrayD,R,C1);
                Multiply(arrayA,arrayB,arrayD,R,C,C1);
                cout<<"Result:"<<endl;
                OutputVector(arrayD,R,C1);
                break;

            //do the transpose operation
            case 4:
                InputRandC();
                InputVector(arrayA,R,C);
                OutputVector(arrayA,R,C);

                //give the shape parameters to the result matrix
                R1=C;
                C1=R;

                Initialize(arrayB,R1,C1);
                Transpose(arrayA,arrayB,R,C);
                cout<<"Result:"<<endl;
                OutputVector(arrayB,R1,C1);
                break;

            //do the determinant operation
            case 5:
                InputRandC();

                //if it's not a square matrix, we can't do the operation
                if(R!=C)
                {
                    cout<<"It's not a square matrix"<<endl;
                    break;
                }

                InputVector(arrayA,R,C);
                OutputVector(arrayA,R,C);

                //if it's a 1D-matrix just output the result
                if(R==1)
                {
                    cout << "Result:" << endl;
                    cout<<"det="<<arrayA[0][0]<<endl;
                }

                else
                {
                    det=Determinant(arrayA, R);
                    cout << "Result:" << endl;
                    cout<<"det="<<det<<endl;
                }

                break;


            //do the inverse operation
            case 6:
                InputRandC();

                //if it's not a square matrix, we can't do the operation
                if(R!=C)
                {
                    cout << "It's not a square matrix" << endl;
                    break;
                }

                InputVector(arrayA,R,C);
                OutputVector(arrayA,R,C);

                //if the det is equal to 0, we can't do the operation
                det=Determinant(arrayA,R);
                if(det==0)
                {
                    cout<<"There's no Inverse Operation"<<endl;
                    break;
                }

                Initialize(arrayC,R,C);

                //if it's a 1D-matrix just output the result
                if(R==1)
                {
                    cout << "Result:" << endl;
                    cout<<1/arrayA[0][0]<<endl;
                }

                else
                {
                    Inverse(arrayA,arrayC,R);
                    cout << "Result:" << endl;
                    OutputVector(arrayC,R,C);

                }
                break;

            //set the default
            default:
                cout << "Wrong Input" << endl;
        }

        //use another menu function to cycle the system
        ShowMenu();
        cin >> choice;
    }

    cout<<"It's over, bye-bye!"<<endl;

    return 0;
}