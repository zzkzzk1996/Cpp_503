//Zekun Zhang   Sept.30.2018
//Use dynamic 2D-array to perform matrix operations

#include <iostream>
#include <iomanip>

using namespace std;

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
    while(R<=0||R>10)
    {
        cout << "Please inter the number of the Row and Max is 10" << endl;
        cin >> R;
    }

    cout << "Please inter the number of the Col and Max is 10" << endl;
    cin >> C;
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
    while(R1<=0||R1>10)
    {
        cout << "Please inter the number of the Row" << endl;
        cin >> R1;
    }
    cout << "Please inter the number of the Col" << endl;
    cin >> C1;
    while(C1<=0||C1>10)
    {
        cout << "Please inter the number of the Col" << endl;
        cin >> C1;
    }

}

//the input module for the values of the matrix
void InputMatrix(double **M,int Row,int Col)
{

    cout<<"Please enter the Matrix:"<<endl;

    for (int i = 0;i<Row;i++)
    {
        for (int j = 0; j < Col; j++) {
            cin >> M[i][j];
        }
        cout << endl;
    }
}

//the output module for the matrix
void PrintMatrix(double **M,int Row,int Col)
{
    cout<<"The Matrix is:"<<endl;
    for (int i = 0;i<Row;i++)
    {
        for(int j=0;j<Col;j++)
        {
            cout<<setw(10)<<M[i][j];
        }

        cout<<endl;
    }

}

//the release module for the dynamic 2D-array
void Release(double **M,int Row)
{
    for (int i = 0; i < Row; i++)
        delete[] M[i];
    delete[] M;
}

//the add operation module
void MatrixAdd(double **M,double **N,double **R,int Row,int Col)
{
    for(int i=0;i<Row;i++)
    {
        for(int j=0;j<Col;j++)
        {
            R[i][j]=M[i][j]+N[i][j];
        }
    }
}

//the subtract operation module
void MatrixSubtract(double **M,double **N,double **R,int Row,int Col)
{
    for(int i=0;i<Row;i++)
    {
        for(int j=0;j<Col;j++)
        {
            R[i][j]=M[i][j]-N[i][j];
        }
    }
}

//the multiply operation module
void MatrixMultiply(double **M,double **N,double **R,int RowM,int ColM,int ColN)
{
    for(int i=0;i<RowM;i++)
    {

        for(int j=0;j<ColN;j++)
        {
            for(int k=0;k<ColM;k++)
            {
                R[i][j]+=M[i][k]*N[k][j];
            }
        }
    }
}

//the transpose operation module
void MatrixTranspose(double **M,double **R,int Row,int Col)
{

    for(int i=0;i<Row;i++)
    {

        for(int j=0;j<Col;j++)
        {
            R[j][i]=M[i][j];

        }

    }
}

//the determinant operation module
double MatrixDeterminant(double **M,int n)
{
    //if it is a 1D-matrix return the value to determinant answer
    if(n==1)
    {
        return M[0][0];
    }
    //use a dynamic 2D-array to contain temporary values in the calculation
    double **T;
    //use variable 'ans' to contain the determinant answer and firstly initialize it
    double ans=0;

    T= new double *[n];
    for (int i = 0; i < n; ++i)
    {
        T[i] = new double[n];
    }
    //initialize this 2D-array
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            T[i][j] = 0;
        }
    }
    //use the triple loop to calculate the cofactor for one value
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<n-1;j++)
        {
            for (int k = 0; k < n-1; k++)
            {
                T[j][k] = M[j+1][(k>=i)?k+1:k];
            }
        }

        //use the function again to do the iteration operation
        double t = MatrixDeterminant(T, n-1);
        //the characteristics of the sum for cofactors
        if (i%2 == 0)
        {
            ans+= M[0][i]*t;
        }
        else
        {
            ans-= M[0][i]*t;
        }
    }
    //finally release 'T' and return the answer
    Release(T,n);
    return ans;
}

//the adjoint matrix operation module, which is used for calculate the inverse operation
void MatrixAdjoint(double **M,double **Res,int n)
{
    //use a dynamic 2D-array to contain temporary values in the calculation
    double **temp;

    temp= new double *[n];
    for (int i = 0; i < n; ++i)
    {
        temp[i] = new double[n];
    }

    //initialize this 2D-array
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = 0;
        }
    }

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
                    temp[k][t] = M[k>=i?k+1:k][t>=j?t+1:t];
                }
            }

            //use function to do determinant operation and then transpose the matrix
            Res[j][i]  =  MatrixDeterminant(temp,n-1);

            //the characteristics of the adjoint matrix
            if((i+j)%2 == 1)
            {
                Res[j][i] = - Res[j][i];
            }
        }
    }
    //release 'temp'
    Release(temp,n);
}

//the inverse matrix operation module and in this way we can calculate any dimension matrix
void MatrixInverse(double **M,double **Res,int n)
{
    //use variable 'flag' to use the function and then do further calculate
    double flag=MatrixDeterminant(M,R);

    //use a dynamic 2D-array to contain temporary values in the calculation
    double **T;

    T= new double *[n];
    for (int i = 0; i < n; ++i)
    {
        T[i] = new double[n];
    }

    //initialize this 2D-array
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            T[i][j] = 0;
        }
    }


    //use the function to calculate adjoint matrix
    MatrixAdjoint(M,T,n);

    //use for loop to do inverse operation easily
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            Res[i][j]=T[i][j]/flag;
        }
    }

    Release(T,n);
}

int main() {
    //use a dynamic 2D-array to contain the matrices we will use in the operations
    double ** MatrixM;
    double ** MatrixN;
    double ** MatrixR;

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
                //define and initialize the 2D-array
                MatrixM= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixM[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixM[i][j] = 0;
                    }
                }

                InputMatrix(MatrixM,R,C);
                PrintMatrix(MatrixM,R,C);

                //input the row and col for the second matrix
                InputR1andC1();

                //if they're not in same shape, we can't do the operation and break
                if(R!=R1||C!=C1)
                {
                    cout<<"Can't do this operation"<<endl;
                    break;
                }

                //define and initialize the 2D-array
                MatrixN= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixN[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixN[i][j] = 0;
                    }
                }

                //input the value to the second matrix and display it
                InputMatrix(MatrixN,R,C);
                PrintMatrix(MatrixN,R,C);

                //define and initialize the 2D-array to be ready to contain the result
                MatrixR= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixR[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixR[i][j] = 0;
                    }
                }

                //use function do the operation
                MatrixAdd(MatrixM,MatrixN,MatrixR,R,C1);

                //output the result, release the arrays and break
                cout<<"Result:"<<endl;
                PrintMatrix(MatrixR,R,C);
                Release(MatrixM,R);
                Release(MatrixN,R);
                Release(MatrixR,R);
                break;


                //do the subtract operation
            case 2:
                InputRandC();

                MatrixM= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixM[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixM[i][j] = 0;
                    }
                }

                InputMatrix(MatrixM,R,C);
                PrintMatrix(MatrixM,R,C);

                InputR1andC1();

                //if they're not in same shape, we can't do the operation and break
                if(R!=R1||C!=C1)
                {
                    cout<<"Can't do this operation"<<endl;
                    break;
                }

                MatrixN= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixN[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixN[i][j] = 0;
                    }
                }

                InputMatrix(MatrixN,R,C);
                PrintMatrix(MatrixN,R,C);

                MatrixR= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixR[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixR[i][j] = 0;
                    }
                }

                MatrixSubtract(MatrixM,MatrixN,MatrixR,R,C);

                cout<<"Result:"<<endl;
                PrintMatrix(MatrixR,R,C);
                Release(MatrixM,R);
                Release(MatrixN,R);
                Release(MatrixR,R);
                break;

                //do the multiply operation
            case 3:
                InputRandC();

                MatrixM= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixM[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixM[i][j] = 0;
                    }
                }

                InputMatrix(MatrixM,R,C);
                PrintMatrix(MatrixM,R,C);

                //if the first col do not equal to the second row,we can't do the operation and break
                InputR1andC1();

                if(C!=R1)
                {
                    cout<<"Can't do this operation"<<endl;
                    break;
                }

                MatrixN= new double *[R1];
                for (int i = 0; i < R1; ++i)
                {
                    MatrixN[i] = new double[C1];
                }
                for (int i = 0; i < R1; ++i)
                {
                    for (int j = 0; j < C1; ++j)
                    {
                        MatrixN[i][j] = 0;
                    }
                }

                InputMatrix(MatrixN,R1,C1);
                PrintMatrix(MatrixN,R1,C1);

                MatrixR= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixR[i] = new double[C1];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C1; ++j)
                    {
                        MatrixR[i][j] = 0;
                    }
                }

                MatrixMultiply(MatrixM,MatrixN,MatrixR,R,C,C1);

                cout<<"Result:"<<endl;
                PrintMatrix(MatrixR,R,C1);
                Release(MatrixM,R);
                Release(MatrixN,R1);
                Release(MatrixR,R);
                break;

                //do the transpose operation
            case 4:
                InputRandC();

                MatrixM= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixM[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixM[i][j] = 0;
                    }
                }

                InputMatrix(MatrixM,R,C);
                PrintMatrix(MatrixM,R,C);

                //give the shape parameters to the result matrix
                R1=C;
                C1=R;

                MatrixR= new double *[R1];
                for (int i = 0; i < R1; ++i)
                {
                    MatrixR[i] = new double[C1];
                }
                for (int i = 0; i < R1; ++i)
                {
                    for (int j = 0; j < C1; ++j)
                    {
                        MatrixR[i][j] = 0;
                    }
                }


                MatrixTranspose(MatrixM,MatrixR,R,C);

                cout<<"Result:"<<endl;
                PrintMatrix(MatrixR,R1,C1);
                Release(MatrixM,R);
                Release(MatrixR,R1);
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

                MatrixM= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixM[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixM[i][j] = 0;
                    }
                }

                InputMatrix(MatrixM,R,C);
                PrintMatrix(MatrixM,R,C);

                //if it's a 1D-matrix just output the result
                if(R==1)
                {
                    cout << "Result:" << endl;
                    cout<<"det="<<MatrixM[0][0]<<endl;
                }

                else
                {
                    det=MatrixDeterminant(MatrixM, R);
                    cout << "Result:" << endl;
                    cout<<"det="<<det<<endl;
                }
                Release(MatrixM,R);
                break;

                //do the inverse operation
            case 6:
                InputRandC();

                //if it's not a square matrix, we can't do the operation
                if(R!=C)
                {
                    cout<<"It's not a square matrix"<<endl;
                    break;
                }


                MatrixM= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixM[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixM[i][j] = 0;
                    }
                }

                InputMatrix(MatrixM,R,C);
                PrintMatrix(MatrixM,R,C);

                //if the det is equal to 0, we can't do the operation
                det=MatrixDeterminant(MatrixM,R);
                if(det==0)
                {
                    cout<<"There's no Inverse Operation"<<endl;
                    Release(MatrixM,R);
                    break;
                }


                MatrixR= new double *[R];
                for (int i = 0; i < R; ++i)
                {
                    MatrixR[i] = new double[C];
                }
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        MatrixR[i][j] = 0;
                    }
                }

                //if it's a 1D-matrix just output the result
                if(R==1)
                {
                    cout << "Result:" << endl;
                    cout<<1/MatrixM[0][0]<<endl;
                }

                else
                {
                    MatrixInverse(MatrixM,MatrixR,R);
                    cout << "Result:" << endl;
                    PrintMatrix(MatrixR,R,C);

                }
                Release(MatrixM,R);
                Release(MatrixR,R);
                break;

                //set the default
            default:cout<<"Wrong Input"<<endl;


        }
        //use another menu function to cycle the system
        ShowMenu();
        cin>>choice;
    }

    cout<<"It's over, bye-bye!"<<endl;

    return 0;
}




