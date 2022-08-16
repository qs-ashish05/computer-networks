#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

vector<int> data_stream(7, 0);
int parity;
int count = 0;
int error = 0;
vector<int> check_sum(3, 0);
string label[] = {"D7", "D6", "D5", "P4", "D3", "P2", "P1"};
string parityarr[] = {"Even", "Odd"};
int pos = 0;
int res = 0;

void print()
{

    cout << "\n";
    for (int i = 0; i < 7; i++)
    {

        cout << label[i] << " ";
    }
    cout << "\n";
    for (int i = data_stream.size() - 1; i >= 0; i--)
    {

        cout << data_stream[i] << "  ";
    }
    cout << "\n";
}

int parity_transmission(int a, int b, int c)
{
    int count = 0;

    count = data_stream[a] + data_stream[b] + data_stream[c];

    if (count % 2 == parity)
    {

        return 0;
    }
    else
    {

        return 1;
    }
}

int parity_receiving(int ind, int a, int b, int c)
{

    int count = 0;
    count = data_stream[ind] + data_stream[a] + data_stream[b] + data_stream[c];

    if (count % 2 == parity)
    {

        return 0;
    }
    else
    {

        return 1;
    }
}

int main()
{

x:

    cout << "Choose parity \n0.Even\n1.Odd  \n";

    cin >> parity;

    if (parity == 0)
    {
        cout << "Even parity choosen \n";
    }
    else if (parity == 1)
    {

        cout << "Odd parity Choosen \n";
    }

    else
    {

        cout << "Invalid  choice\n";
        goto x;
    }

    cout << "Hamming code error detection using " << parityarr[parity] << " parity \n";

    cout << "Enter 4 data bits  D7  D6  D5  D3\n";

    for (int i = 6; i >= 0; i--)
    {
        int x;

        if (i == 0 || i == 1 || i == 3)

        {
            continue;
        }
        cout << "Enter the value of D" << i + 1 << " ";
        cin >> x;

        data_stream[i] = x;
    }

    data_stream[0] = parity_transmission(2, 4, 6);
    data_stream[1] = parity_transmission(2, 5, 6);
    data_stream[3] = parity_transmission(4, 5, 6);

    // print();
    cout << "3 parity bits are required for the transmission of data bits.\n";

    cout << "SENDER: \n";

    cout << "The data bits entered are: ";

    for (int i = 6; i >= 0; i--)
    {

        if (i == 0 || i == 1 || i == 3)

        {
            continue;
        }

        cout << data_stream[i] << " ";
    }

    cout << "\n";
    cout << "The parity bits are : ";

    cout << "\n";
    for (int i = 0; i < 7; i++)
    {

        if (i == 3 || i == 5 || i == 6)
        {

            cout << label[i] << " ";
        }
    }
    cout << "\n";
    for (int i = 6; i >= 0; i--)
    {

        if (i == 0 || i == 1 || i == 3)

        {
            cout << data_stream[i] << "  ";
        }
    }
    cout << "\n";
    cout << "The Hamming code is as follows :- \n";
    cout << "\n";
    print();

    cout << "Enter the hamming code with error at any position of your choice \n";
    cout << "\n";
    cout << "NOTE: ENTER 2 SPACES AFFTER EVERY BIT POSITION \n";
    cout << "\n";
    cout << "Error should be present at only one bit position \n";

    for (int i = 0; i < 7; i++)
    {
        cout << label[i] << " ";
    }
    cout << "\n";
    for (int i = 6; i >= 0; i--)
    {

        int x;
        cin >> x;

        data_stream[i] = x;
    }
    cout << "RECEIVER: \n";

    cout << "Received data stream is: \n";

    print();

    cout << "\n";

    check_sum[0] = parity_receiving(0, 2, 4, 6);
    check_sum[1] = parity_receiving(1, 2, 5, 6);
    check_sum[2] = parity_receiving(3, 4, 5, 6);

    cout << "\n";

    for (int i = 2; i >= 0; i--)
    {

        res = check_sum[i] * pow(2, i);

        pos += res;
    }
    cout << "Error is detected at position " << pos << " at the receiving end. \n";
    cout << "Correcting the error..... \n";

    int errorpos = pos - 1;
    if (data_stream[errorpos] == 1)
    {

        data_stream[errorpos] = 0;
    }

    else
    {
        data_stream[errorpos] = 1;
    }

    cout << "\n";

    cout << "The correct code is : \n";
    print();

    cout << "The decoded data is : ";

    for (int i = 6; i >= 0; i--)
    {

        if (i == 0 || i == 1 || i == 3)

        {
            continue;
        }

        cout << data_stream[i] << " ";
    }

    return 0;
}