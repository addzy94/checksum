# include <iostream>
using namespace std;

void input(int &n, string &mes)
{
    cout<<"Enter the number of bits in the message.\n";
    cin>>n;
    cout<<"Enter the data to be sent.\n";
    cin>>mes;
}

string cal_sc(char a, char b, char c)
{
    string sc = "00";
    int val = (a + b + c) - (3 * ('0'));

    switch(val)
    {
        case 0: break;
        case 1: sc[0] = '1';
                sc[1] = '0';
                break;
        case 2: sc[0] = '0';
                sc[1] = '1';
                break;
        case 3: sc[0] = '1';
                sc[1] = '1';
    }
    return sc;
}

void wrap_ar(string &res)
{
    string wrap = "0000000000000001", p;
    int ans;
    p = cal_sc('0', '0', '0');

    while(1)
    {
        for(int i=15;i>=0;i--)
        {
            p = cal_sc(res[i], wrap[i], p[1]);
            res[i] = p[0];
        }
        if(p[1] == '0')
            break;
    }
}

void chk_sum(string mes, string &res, int n)
{
    string p;
    p = cal_sc('0', '0', '0');

    for(int i=n-1, j=0; i>=0; i--, j=(j+1)%16)
    {
        p = cal_sc(mes[i], res[15-j], p[1]);
        res[15-j] = p[0];

        if((i % 16 == 0) && (p[1] == '1'))
        {
            p[1] = '0';
            wrap_ar(res);
        }
    }
}

void cment(string &res)
{
    for(int i=0; i<16; i++)
    {
        if(res[i] == '0')
            res[i] = '1';
        else
            res[i] = '0';
    }
}

void intro_err(string &sentmes, int n)
{
    int pos;
    cout<<"Enter the position from 1 to "<<n+16<<" to put the error.\n";
    cin>>pos;
    if(sentmes[pos-1] == '0')
        sentmes[pos-1] = '1';
    else
        sentmes[pos-1] = '0';
}

main()
{
    int n;
    string mes, errchk, res="0000000000000000";
    errchk = res;

    input(n, mes);

    chk_sum(mes, res, n);
    cment(res);

    string sentmes = mes + res;
    cout<<"Data sent:\n"<<sentmes<<"\n\n";

    chk_sum(sentmes, errchk, n + 16);
    cout<<"Error Check returns:\n"<<errchk<<"\n\n";

    intro_err(sentmes, n);
    chk_sum(sentmes, errchk, n + 16);
    cout<<"Error Check after introducing error returns:\n"<<errchk<<"\n\n";
}
