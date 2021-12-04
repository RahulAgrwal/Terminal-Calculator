//Project Name: Terminal Calculator
//Done by Rahul Agarwal
//Branch : E&TC
//Date: 4th December 2021

#include <bits/stdc++.h>
using namespace std;

void add()
{
    int n;
    cout << "Welcome to Addition!" << endl;
    cout << "Enter Count of Numbers to Add: ";
    cin >> n;
    double sum = 0;
    cout << "Enter Numbers : ";
    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        sum += temp;
    }
    cout << "Additon is " << sum << endl;
}

void subtract()
{
    int n;
    cout << "Welcome to Substraction!" << endl;
    cout << "Enter Count of Numbers to Subtract: ";
    cin >> n;
    double diff = 0;
    cout << "Enter Numbers : ";
    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        diff -= temp;
    }
    cout << "Substraction is " << diff << endl;
}

void multiply()
{
    int n;
    cout << "Welcome to Multiplication!" << endl;
    cout << "Enter Count of Numbers to Multiply: ";
    cin >> n;
    double mul = 1;
    cout << "Enter Numbers : ";
    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        mul *= temp;
    }
    cout << "Multiplication is " << mul << endl;
}

void div()
{
    cout << "Welcome to Division!" << endl;
    double a, b;
    cout << "Enter Two Numbers: ";
    cin >> a >> b;
    if (b == 0)
    {
        cout << "Denominator cannot be Zero" << endl;
        cout << "Re-enter Number: ";
        int temp;
        cin >> temp;
        b = temp;
    }
    double d = a / b;
    cout << d << endl;
}
void areaoftriangle()
{
    int b, h;
    cout << "Enter Height and Breadth of Triangle :";
    cin >> b >> h;
    cout << "Area :" <<b * h / (2 * 1.0) << endl;
}
void areofrectangle()
{
    int l, b;
    cout << "Enter Length and Breadth of Triangle " << endl;
    cin >> l >> b;
    cout<<"Area of rectangle is" << l * b / (1.0)<<endl;
}

void areaofpentagon()
{
    int a;
    cout << "Enter length of Pentagon " << endl;
    cin >> a;
    cout<<"Area of Pentagon is " <<sqrt(5 * (5 + 2 * sqrt(5)) * a * a)<<endl;
}

void factorial()
{
    int n;
    cin >> n;
    vector<int> res;
    res.push_back(1);
    for (int x = 2; x <= n; x++)
    {
        int carry = 0;
        for (int i = 0; i < res.size(); i++)
        {
            int val = res[i] * x + carry;
            res[i] = val % 10;
            carry = val / 10;
        }
        while (carry != 0)
        {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    cout<<"Factorial of "<<n<<" is ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;
}

int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}
int applyOp(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}
int evaluate(string tokens){
	int i;
	stack <int> values;
	stack <char> ops;
	
	for(i = 0; i < tokens.length(); i++){
		if(tokens[i] == ' ')
			continue;
		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}
		else if(isdigit(tokens[i])){
			int val = 0;
			
			while(i < tokens.length() &&
						isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			
			values.push(val);
			i--;
		}
		else if(tokens[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			if(!ops.empty())
			ops.pop();
		}
		else
		{
			while(!ops.empty() && precedence(ops.top())
								>= precedence(tokens[i])){
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			ops.push(tokens[i]);
		}
	}
	while(!ops.empty()){
		int val2 = values.top();
		values.pop();
				
		int val1 = values.top();
		values.pop();
				
		char op = ops.top();
		ops.pop();
				
		values.push(applyOp(val1, val2, op));
	}
	return values.top();
}
void user(){
    string s;
    cout<<"Input Expression :";
    cin>>s;
    cout<<"Result is "<<evaluate(s)<<endl;
}

int main()
{
     cout << "Welcome to Terminal Calculator" << endl;
    do
    {
       
        cout << "Select from below option:" << endl;
        cout << "1.Addition" << endl;
        cout << "2.Substraction" << endl;
        cout << "3.Multiplication" << endl;
        cout << "4.Divison" << endl;
        cout << "5.Factorial" << endl;
        cout << "6.Area of Triangle" << endl;
        cout << "7.Area of Rectangle" << endl;
        cout << "8.Area of Pentagon" << endl;
        cout << "9.User Input Expression" << endl;
        cout << "10.Exit" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            subtract();
            break;
        }
        case 3:
        {
            multiply();
            break;
        }
        case 4:
        {
            div();
            break;
        }
        case 5:
        {
            factorial();
            break;
        }
        case 6:
        {
            areaoftriangle();
            break;
        }
        case 7: { areofrectangle(); break; } 
        case 8:
        {
            areaofpentagon();
            break;
        }
        case 9:
        {
            user();
            break;
        }
        case 10:
        {
            cout << "Thankyou!!";
            return 0;
        }
        default:
        {
            cout << "Select appropiate option from above list" << endl;
            break;
        }
        }
        cout<<"------------------------------"<<endl;
    } while (true);
}